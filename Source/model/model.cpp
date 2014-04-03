#include "model.hpp"

#include <assimp/importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace Model
{

	Model::Model(std::string filename, oglplus::Program* program) :
		_program(program),
		camera_position_uniform(*program, "camera_position"),
		normalMatrix_uniform(*program, "NormalMatrix"),
		modelViewProjectionMatrix_uniform(*program, "ModelViewProjectionMatrix")
	{
		Assimp::Importer imp;

		//importer destruction should clean up the scene
		auto scene = imp.ReadFile(filename,
			aiProcess_JoinIdenticalVertices |
			aiProcess_Triangulate |
			aiProcess_RemoveComponent |
			aiProcess_PreTransformVertices |
			aiProcess_FlipUVs |
			aiProcess_OptimizeMeshes |
			aiProcess_OptimizeGraph |
			aiProcess_FindDegenerates |
			aiProcess_SortByPType);

		assert((scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE) == 0); //assert no errors loading the file

		_materials.resize(scene->mNumMaterials);
		//for each material
		for (unsigned int matIndex = 0; matIndex < scene->mNumMaterials; ++matIndex)
		{
			auto material = scene->mMaterials[matIndex];

			_materials[matIndex] = std::make_unique<Material>();

			aiColor3D colour;

			if (material->Get(AI_MATKEY_COLOR_DIFFUSE, colour) == AI_SUCCESS)
			{
				_materials[matIndex]->diffuse_colour = { colour.r, colour.g, colour.b };
			}
			//if (material->Get(AI_MATKEY_COLOR_AMBIENT, colour) == AI_SUCCESS)
			//{
			//	_materials[matIndex]->ambient_colour = { colour.r, colour.g, colour.b };
			//}
			if (material->Get(AI_MATKEY_COLOR_SPECULAR, colour) == AI_SUCCESS)
			{
				_materials[matIndex]->specular_colour = { colour.r, colour.g, colour.b };
			}

			float shininess;
			if (material->Get(AI_MATKEY_SHININESS, shininess) == AI_SUCCESS)
			{
				_materials[matIndex]->specular_shininess = shininess;
			}

		}

		//for each mesh
		for (unsigned int meshIndex = 0; meshIndex < scene->mNumMeshes; ++meshIndex)
		{
			auto mesh = scene->mMeshes[meshIndex];
			if (mesh->mPrimitiveTypes != aiPrimitiveType_TRIANGLE) continue; //we are only dealing with triangles, skip points and lines
			assert(mesh->HasPositions());
			assert(mesh->HasNormals());

			std::vector<Vertex> vertices;
			std::vector<GLint> indices;

			//VERTICES
			//reserve the space for an additional mesh->mNumVertices vertices.
			vertices.resize(vertices.size() + mesh->mNumVertices);
			for (unsigned int vertexIndex = 0; vertexIndex < mesh->mNumVertices; ++vertexIndex)
			{
				Vertex mv;

				//position
				auto position = mesh->mVertices[vertexIndex];
				mv.position = { position.x, position.y, position.z, 1.0 };

				//normal
				auto normal = mesh->mNormals[vertexIndex];
				mv.normal = { normal.x, normal.y, normal.z, 1.0 };

				if (mesh->HasVertexColors(vertexIndex))
				{
					auto colour = mesh->mColors[vertexIndex];
					mv.colour = { colour->r, colour->g, colour->b, colour->a };
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

			_meshes.emplace_back(std::make_unique<Mesh>(program, vertices, indices, _materials[mesh->mMaterialIndex].get()));
		}
	}

	void Model::draw(glm::vec3 camera_position, glm::mat4 modelMatrix, glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
	{
		_program->Use();

		auto modelViewMatrix = viewMatrix * modelMatrix;
		auto normalMatrix = glm::transpose(glm::inverse(modelViewMatrix));
		auto modelViewProjectionMatrix = projectionMatrix * modelViewMatrix;

		camera_position_uniform.Set(camera_position);
		normalMatrix_uniform.Set(normalMatrix);
		modelViewProjectionMatrix_uniform.Set(modelViewProjectionMatrix);

		for (auto& mesh : _meshes)
		{
			mesh->draw();
		}

		oglplus::Program::UseNone();
	}

	btCollisionShape* Model::GetCollisionShape()
	{
		if(!_shape) //if shape has not been previously generated, generate it
		{
			_shape_indexed_vertex_array = std::make_unique<btTriangleIndexVertexArray>();

			for (auto& mesh : _meshes)
			{
				btIndexedMesh indexed_mesh;

				indexed_mesh.m_numTriangles = mesh->indices.size() / 3;
				indexed_mesh.m_triangleIndexBase = (const unsigned char *) &mesh->indices[0];
				indexed_mesh.m_triangleIndexStride = 3 * sizeof(GLint);
				indexed_mesh.m_indexType = PHY_INTEGER;

				indexed_mesh.m_numVertices = mesh->vertices.size();
				indexed_mesh.m_vertexBase = (const unsigned char *) (&mesh->vertices[0] + offsetof(Vertex, position));
				indexed_mesh.m_vertexStride = sizeof(Vertex);
				indexed_mesh.m_vertexType = PHY_FLOAT; //set that we are dealing with floats

				_shape_indexed_vertex_array->addIndexedMesh(indexed_mesh);
			}
			//TODO Convex Decompositions.
			_shape = std::make_unique<btConvexTriangleMeshShape>(_shape_indexed_vertex_array.get());
		}

		return _shape.get();
	}
}