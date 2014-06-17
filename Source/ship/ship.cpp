#include "ship.hpp"
#include <utilities/ShaderManager/shadermanager.hpp>
#include <utilities/MathConversions/math_conversions.hpp>
#include <glm/common.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <world/world.hpp>

Ship::Ship(btDynamicsWorld* physics_world) :
Model("Resources/models/player/ship.dae", &Global::shader_manager->phong3d),
ScriptableObject(ScriptableObject::ObjectType::SIMULATED, glm::vec3(10, 0, 0), glm::quat(), static_cast<Model*>(this), 100),
Killable(1000.0)
{
	rigid_body->setUserPointer(static_cast<ICollidable*>(this));
	rigid_body->setCollisionFlags(rigid_body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	
	_physics_world = physics_world;

	_physics_world->addRigidBody(rigid_body.get());
}


Ship::~Ship()
{
	_physics_world->removeRigidBody(rigid_body.get());
	for (auto& a : _basic_attacks)
	{
		_physics_world->removeRigidBody(a->rigid_body.get());
	}
}


void Ship::Update(double dt)
{
	if (alive)
	{
		rigid_body->activate(true);

		auto transform = rigid_body->getWorldTransform();
		auto position = transform.getOrigin();
		auto rotation = transform.getRotation();

		const float max_speed = 100;

		if (input.propel_forward)
		{
			rigid_body->applyCentralImpulse(quatRotate(rotation, btVector3(max_speed, 0, 0) * dt));
		}
		if (input.propel_backward)
		{
			rigid_body->applyCentralImpulse(quatRotate(rotation, btVector3(-max_speed, 0, 0) * dt));
		}

		const float max_rotation_speed = 20 * glm::pi<float>();

		if (input.roll_right)
		{
			rigid_body->applyTorqueImpulse(quatRotate(rotation, btVector3(max_rotation_speed, 0, 0)) * dt);
		}
		if (input.roll_left)
		{
			rigid_body->applyTorqueImpulse(quatRotate(rotation, btVector3(-max_rotation_speed, 0, 0)) * dt);
		}

		if (input.pitch_up)
		{
			rigid_body->applyTorqueImpulse(quatRotate(rotation, btVector3(0, 0, max_rotation_speed)) * dt);
		}

		if (input.pitch_down)
		{
			rigid_body->applyTorqueImpulse(quatRotate(rotation, btVector3(0, 0, -max_rotation_speed)) * dt);
		}

		if (input.shoot)
		{
			_basic_attacks.emplace_back(std::make_unique<BasicAttack>(
				50.0,
				1, 
				toVec3(position + quatRotate(rotation, btVector3(15, 0, 0))),
				toQuat(rotation), 
				toVec3(quatRotate(rotation, btVector3(100, 0, 0)))));
			_physics_world->addRigidBody(_basic_attacks.back()->rigid_body.get());

			input.shoot = false;
		}

		//process basic attacks
		auto a = _basic_attacks.begin();
		while (a != _basic_attacks.end())
		{
			if ((*a)->active)
			{
				(*a)->Update(dt);
				++a;
			}
			else
			{
				_physics_world->removeRigidBody((*a)->rigid_body.get());
				a = _basic_attacks.erase(a);
			}
		}
	}
}

void Ship::Collision(ICollidable* obj)
{
	//do nothing
}

void Ship::Render(glm::vec4 view_light_direction, glm::mat4 view_matrix, glm::mat4 projection_matrix)
{
	if (alive)
	{
		ScriptableObject::Render(view_light_direction, view_matrix, projection_matrix);

		for (auto& a : _basic_attacks)
		{
			a->Render(view_light_direction, view_matrix, projection_matrix);
		}
	}
}