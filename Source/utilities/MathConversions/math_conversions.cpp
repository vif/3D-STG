#include "math_conversions.hpp"

glm::mat4 toMat4(const btTransform& t)
{
	glm::mat4 ATTRIBUTE_ALIGNED16(glm_mat);

	t.getOpenGLMatrix(glm::value_ptr(glm_mat));

	return glm_mat;
}

glm::vec3 toVec3(const btVector3& v)
{
	return glm::vec3(v.getX(), v.getY(), v.getZ());
}

btVector3 toVec3(const glm::vec3& v)
{
	return btVector3(v.x, v.y, v.z);
}

glm::vec4 toVec4(const btVector4& v)
{
	return glm::vec4(v.getX(), v.getY(), v.getZ(), v.getW());
}

btVector4 toVec4(const glm::vec4& v)
{
	return btVector4(v.x, v.y, v.z, v.w);
}

glm::quat toQuat(const btQuaternion& q)
{
	return glm::quat(q.getW(), q.getX(), q.getY(), q.getZ());
}

btQuaternion toQuat(const glm::quat& q)
{
	return btQuaternion(q.x, q.y, q.z, q.w);
}

