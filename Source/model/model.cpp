#include <typedefs.hpp>

Model::Model(std::string filename)
{
	Assimp::Importer imp;
	auto scene = imp.ReadFile(filename,
		aiProcess_JoinIdenticalVertices |
		aiProcess_Triangulate |
		aiProcess_RemoveComponent |
		aiProcess_GenSmoothNormals |
		aiProcess_FlipUVs |
		aiProcess_OptimizeMeshes |
		aiProcess_OptimizeGraph |
		aiProcess_FindDegenerates |
		aiProcess_SortByPType);

	assert(scene->mFlags); //assert no errors loading the file
	assert(scene->mRootNode != nullptr); //assert that we actually loaded something
	assert(scene->mRootNode->mNumChildren == 0); //we can't handle multiple inheritance data yet.. (TODO maybe)

	for (unsigned int meshIndex = 0; meshIndex < scene->mNumMeshes; ++meshIndex)
	{
		auto mesh = scene->mMeshes[meshIndex];
		if (mesh->mPrimitiveTypes != aiPrimitiveType_TRIANGLE) continue; //we are only dealing with triangles
		assert(mesh->HasPositions());
		assert(mesh->HasNormals());

		//since we are concatenating multiple meshes, we need offsets for our members
		auto verticesIndexOffset = _vertices.size();
		auto indecesIndexOffset = _indices.size();

		//VERTICES
		//reserve the space for an additional mesh->mNumVertices vertices.
		_vertices.resize(_vertices.size() + mesh->mNumVertices);
		for (unsigned int vertexIndex = 0; vertexIndex < mesh->mNumVertices; ++vertexIndex)
		{
			MeshVertex mv;
			auto position = mesh->mVertices[vertexIndex];
			mv.position = { position.x, position.y, position.z };
			auto normal = mesh->mNormals[vertexIndex];
			mv.normal = { normal.x, normal.y, normal.z };

			if (mesh->HasVertexColors(vertexIndex))
			{
				auto colour = mesh->mColors[vertexIndex];
				mv.colour = { colour->r, colour->g, colour->b, colour->a };
			}

			if (mesh->HasTextureCoords(vertexIndex))
			{
				auto UV = mesh->mTextureCoords[vertexIndex];
				mv.UV = { UV->x, UV->y, UV->z };
			}

			_vertices[verticesIndexOffset + vertexIndex] = mv;
		}

		//FACES
		//reserve the space for an additional mesh->mNumFaces faces
		_indices.resize(_indices.size() + mesh->mNumFaces * 3);
		for (unsigned int faceIndex = 0; faceIndex < mesh->mNumFaces; ++faceIndex)
		{
			auto face = mesh->mFaces[faceIndex];
			assert(face.mNumIndices == 3);

			//since we have multiple meshes, the indices need to be offset by the number of vertices we already processed
			_indices[indecesIndexOffset + faceIndex + 0] = face.mIndices[0] + verticesIndexOffset;
			_indices[indecesIndexOffset + faceIndex + 1] = face.mIndices[1] + verticesIndexOffset;
			_indices[indecesIndexOffset + faceIndex + 2] = face.mIndices[2] + verticesIndexOffset;
		}
	}

	//UPLOAD the data onto the GPU
	_vao.Bind();

	_vertexBuffer.Bind(oglplus::BufferOps::Target::Array);
	_vertexBuffer.Data(oglplus::BufferOps::Target::Array, _vertices);
	_vertexBuffer.Unbind(oglplus::BufferOps::Target::Array);

	_faceBuffer.Bind(oglplus::BufferOps::Target::ElementArray);
	_faceBuffer.Data(oglplus::BufferOps::Target::ElementArray, _indices);
	_faceBuffer.Unbind(oglplus::BufferOps::Target::ElementArray);

	_vao.Unbind();
}

void Model::draw(oglplus::Program* program)
{
#define make_vaa(name) \
	oglplus::VertexAttribArray name(*program, #name); \
	name.Format(sizeof(((MeshVertex *)0)->name) / sizeof(GLfloat), oglplus::DataType::Float, false, offsetof(MeshVertex, name)); \
	name.Enable();

	make_vaa(position);
	make_vaa(normal);
	make_vaa(colour);
	make_vaa(UV);
#undef make_vaa

	_vao.Bind();
	oglplus::Context::DrawElements(oglplus::PrimitiveType::Triangles, _indices.size(), &_indices[0]);
	_vao.Unbind();
}