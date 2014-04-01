#pragma once

//STL
#include <list>
#include <vector>
#include <memory>
#include <string>

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>

//OGLPLUS
#include <oglplus.hpp>

//BULLET PHYSICS
#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

//ASSIMP
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

//INTERFACES
#include <interfaces.hpp>

//UTILITIES
#include <utilities/ShaderManager/shaders.hpp>

//GAME
#include <model/mesh.hpp>
#include <model/model.hpp>
#include <world/world.hpp>
#include <player/ship.hpp>