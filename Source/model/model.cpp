#include <typedefs.hpp>

namespace Model
{

	Mesh::Mesh(oglplus::Program* program, const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices, Material* material) :
		_program(program),
		_vertices(vertices),
		_indices(indices),
		_material(material)
	{
		//UPLOAD the data onto the GPU
		_vao.Bind();

		_vertexBuffer.Bind(oglplus::BufferOps::Target::Array);
		_vertexBuffer.Data(oglplus::BufferOps::Target::Array, _vertices);

		_faceBuffer.Bind(oglplus::BufferOps::Target::ElementArray);
		_faceBuffer.Data(oglplus::BufferOps::Target::ElementArray, _indices);
		_material->texture.Bind(oglplus::TextureOps::Target::_2D);

		//SETUP attributes
#define make_vaa(name) \
	oglplus::VertexAttribArray name(*program, #name); \
	name.Pointer(sizeof(((Vertex *)0)->name) / sizeof(GLfloat), oglplus::DataType::Float, false, sizeof(Vertex), (const void *) offsetof(Vertex, name)); \
	name.Enable();

		make_vaa(position);
		make_vaa(normal);
		make_vaa(colour);
#undef make_vaa

		oglplus::VertexArray::Unbind();

		oglplus::Buffer::Unbind(oglplus::BufferOps::Target::Array);
		oglplus::Buffer::Unbind(oglplus::BufferOps::Target::ElementArray);
		oglplus::Texture::Unbind(oglplus::TextureOps::Target::_2D);
	}

	void Mesh::draw()
	{
		_program->Use();
		_vao.Bind();

		oglplus::Context::DrawElements(oglplus::PrimitiveType::Triangles, _indices.size(), oglplus::DataType::UnsignedInt);

		oglplus::VertexArray::Unbind(); //unbind the VAOs
		oglplus::Program::UseNone();
	}

	Model::Model(std::string filename, oglplus::Program* program) : _program(program)
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

		_materials.resize(scene->mNumMaterials);
		//for each material
		for (unsigned int matIndex = 0; matIndex < scene->mNumMaterials; ++matIndex)
		{
			auto material = scene->mMaterials[matIndex];

			auto mat = new Material();
			aiColor3D colour;
			material->Get(AI_MATKEY_COLOR_DIFFUSE, colour);
			mat->diffuse_colour = { colour.r, colour.g, colour.b };
			material->Get(AI_MATKEY_COLOR_AMBIENT, colour);
			mat->ambient_colour = { colour.r, colour.g, colour.b };
			material->Get(AI_MATKEY_COLOR_SPECULAR, colour);
			mat->specular_colour = { colour.r, colour.g, colour.b };
			material->Get(AI_MATKEY_SHININESS, mat->shininess);

			//we are going to assume one texture per mesh
			aiString texture_path;
			auto texture_found = material->GetTexture(aiTextureType_DIFFUSE, 0, &texture_path);
			if (texture_found == AI_SUCCESS)
			{
				_materials[matIndex]->texture.Image2D(oglplus::TextureOps::Target::_2D, oglplus::images::LoadTexture(texture_path.C_Str()));
			}

			_materials[matIndex] = mat;
		}

		//for each mesh
		for (unsigned int meshIndex = 0; meshIndex < scene->mNumMeshes; ++meshIndex)
		{
			auto mesh = scene->mMeshes[meshIndex];
			if (mesh->mPrimitiveTypes != aiPrimitiveType_TRIANGLE) continue; //we are only dealing with triangles, skip points and lines
			assert(mesh->HasPositions());
			assert(mesh->HasNormals());

			std::vector<Vertex> vertices;
			std::vector<GLuint> indices;

			//VERTICES
			//reserve the space for an additional mesh->mNumVertices vertices.
			vertices.resize(vertices.size() + mesh->mNumVertices);
			for (unsigned int vertexIndex = 0; vertexIndex < mesh->mNumVertices; ++vertexIndex)
			{
				Vertex mv;

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

				vertices[vertexIndex] = mv;
			}

			//FACES
			//reserve the space for an additional mesh->mNumFaces faces
			indices.resize(indices.size() + mesh->mNumFaces * 3);
			for (unsigned int faceIndex = 0; faceIndex < mesh->mNumFaces; ++faceIndex)
			{
				auto face = mesh->mFaces[faceIndex];
				assert(face.mNumIndices == 3); //we only deal with triangles

				indices[faceIndex * 3 + 0] = face.mIndices[0];
				indices[faceIndex * 3 + 1] = face.mIndices[1];
				indices[faceIndex * 3 + 2] = face.mIndices[2];
			}

			_meshes.push_back(new Mesh(program, vertices, indices, _materials[mesh->mMaterialIndex]));
		}
	}

	Model::~Model()
	{
		//delete the materials
		for (auto m : _materials)
		{
			delete m;
		}

		//delete the meshes
		for (auto m : _meshes)
		{
			delete m;
		}
	}

	void Model::draw()
	{
		for (auto& mesh : _meshes)
		{
			mesh->draw();
		}
	}
}