#pragma once

#include <btBulletDynamicsCommon.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>



glm::mat4 toMat4(const btTransform& t);
glm::vec3 toVec3(const btVector3& v);
btVector3 toVec3(const glm::vec3& v);
glm::vec4 toVec4(const btVector4& v);
btVector4 toVec4(const glm::vec4& v);
glm::quat toQuat(const btQuaternion& q);
btQuaternion toQuat(const glm::quat& q);