#include <typedefs.hpp>


void load_model(std::string filename, std::vector<Model::MeshVertex>& vertices, std::vector<GLuint>& indices, Model::Material& material)
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


	//Material
	{
		assert(scene->mNumMaterials == 1); //handle only one material per model thus far
		auto mat = scene->mMaterials[0];

		aiColor4D colour;
		
		mat->Get(AI_MATKEY_COLOR_DIFFUSE, colour);
		material.diffuse = { colour.r, colour.g, colour.b, colour.a };

		mat->Get(AI_MATKEY_COLOR_SPECULAR, colour);
		material.specular = { colour.r, colour.g, colour.b, colour.a };

		mat->Get(AI_MATKEY_SHININESS, material.shininess);
	}


	//for each mesh
	for (unsigned int meshIndex = 0; meshIndex < scene->mNumMeshes; ++meshIndex)
	{
		auto mesh = scene->mMeshes[meshIndex];
		if (mesh->mPrimitiveTypes != aiPrimitiveType_TRIANGLE) continue; //we are only dealing with triangles, skip points and lines
		assert(mesh->HasPositions());
		assert(mesh->HasNormals());

		//since we are concatenating multiple meshes, we need offsets for our members
		auto verticesIndexOffset = vertices.size();
		auto indecesIndexOffset = indices.size();

		//VERTICES
		//reserve the space for an additional mesh->mNumVertices vertices.
		vertices.resize(vertices.size() + mesh->mNumVertices);
		for (unsigned int vertexIndex = 0; vertexIndex < mesh->mNumVertices; ++vertexIndex)
		{
			Model::MeshVertex mv;

			//position
			auto position = mesh->mVertices[vertexIndex];
			mv.position = { position.x, position.y, position.z };

			//normal
			auto normal = mesh->mNormals[vertexIndex];
			mv.normal = { normal.x, normal.y, normal.z };

			//colour
			if (mesh->HasVertexColors(vertexIndex))
			{
				auto colour = mesh->mColors[vertexIndex];
				mv.colour = { colour->r, colour->g, colour->b, colour->a };
			}
			else
			{
				mv.colour = { 0.9, 0.9, 0.9, 1 }; //set grey as default colour
			}

			vertices[verticesIndexOffset + vertexIndex] = mv;
		}

		//FACES
		//reserve the space for an additional mesh->mNumFaces faces
		indices.resize(indices.size() + mesh->mNumFaces * 3);
		for (unsigned int faceIndex = 0; faceIndex < mesh->mNumFaces; ++faceIndex)
		{
			auto face = mesh->mFaces[faceIndex];
			assert(face.mNumIndices == 3); //we only deal with triangles

			//since we have multiple meshes, the indices need to be offset by the number of vertices we already processed
			indices[indecesIndexOffset + faceIndex * 3 + 0] = face.mIndices[0] + verticesIndexOffset;
			indices[indecesIndexOffset + faceIndex * 3 + 1] = face.mIndices[1] + verticesIndexOffset;
			indices[indecesIndexOffset + faceIndex * 3 + 2] = face.mIndices[2] + verticesIndexOffset;
		}
	}
}

Model::Model(std::string filename, oglplus::Program* program) : _program(program)
{
	load_model(filename, _vertices, _indices, material);

	//UPLOAD the data onto the GPU
	_vao.Bind();

	_vertexBuffer.Bind(oglplus::BufferOps::Target::Array);
	_vertexBuffer.Data(oglplus::BufferOps::Target::Array, _vertices);

	_faceBuffer.Bind(oglplus::BufferOps::Target::ElementArray);
	_faceBuffer.Data(oglplus::BufferOps::Target::ElementArray, _indices);

	//SETUP attributes
#define make_vaa(name) \
	oglplus::VertexAttribArray name(*program, #name); \
	name.Pointer(sizeof(((MeshVertex *)0)->name) / sizeof(GLfloat), oglplus::DataType::Float, false, sizeof(MeshVertex), (const void *) offsetof(MeshVertex, name)); \
	name.Enable();

	make_vaa(position);
	make_vaa(normal);
	make_vaa(colour);
#undef make_vaa

	oglplus::VertexArray::Unbind();

	oglplus::Buffer::Unbind(oglplus::BufferOps::Target::Array);
	oglplus::Buffer::Unbind(oglplus::BufferOps::Target::ElementArray);
}

void Model::draw()
{
	_program->Use();
	_vao.Bind();

	oglplus::Context::DrawElements(oglplus::PrimitiveType::Triangles, _indices.size(), oglplus::DataType::UnsignedInt);

	oglplus::VertexArray::Unbind(); //unbind the VAOs
	oglplus::Program::UseNone();
}