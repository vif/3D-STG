#include "basic.hpp"

#include <attacks/basic_attack.hpp>
#include <utilities/MathConversions/math_conversions.hpp>

BasicEnemy::BasicEnemy(Ship* ship, Model::Model* model, glm::vec3 init_pos, glm::quat init_orientation) :
Killable(100.0)
{
	_ship = ship;
	pose = std::make_unique<btDefaultMotionState>(btTransform(toQuat(init_orientation), toVec3(init_pos)));
	_drawable = std::make_unique<DrawableObject>(pose.get(), model);
	moveable = std::make_unique<MoveableObject>(MoveableObject::ObjectType::SIMULATED, pose.get(), model->GetCollisionShape(), 10);
}

void BasicEnemy::Update(double dt)
{
	if (alive)
	{
		moveable->rigid_body->activate(true);

		btTransform ship_transform;
		_ship->pose->getWorldTransform(ship_transform);
		auto ship_position = ship_transform.getOrigin();

		btTransform transform;
		pose->getWorldTransform(transform);
		auto position = transform.getOrigin();

		auto movementspeed = 1000;
		auto follow_distance = 50;

		auto dir_ship = ship_position - position;

		//VELOCITY

		//get direction to ship, rotate by 90 degrees, make it's length the follow_distance and add it to the ship's position
		auto dest = ship_position + quatRotate(btQuaternion(90.0f, 0.0f, 0.0f), dir_ship).normalize() * follow_distance;

		//head towards the destination
		moveable->rigid_body->setLinearVelocity((dest - position).normalize() * movementspeed * dt);

		//TODO: always face ship
	}
}

void BasicEnemy::Render(glm::vec4 view_light_direction, glm::mat4 view_matrix, glm::mat4 projection_matrix)
{
	_drawable->Render(view_light_direction, view_matrix, projection_matrix);
}

void BasicEnemy::Collision(ICollidable* obj)
{
	auto attack = dynamic_cast<BasicAttack*>(obj);
	if (attack != nullptr && attack->active)
	{
		ReceiveHealthOffset(-attack->damage);
		attack->active = false;
	}
}
