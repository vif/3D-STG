#include "ship.hpp"
#include <utilities/ShaderManager/shadermanager.hpp>
#include <utilities/MathConversions/math_conversions.hpp>
#include <glm/common.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <world/world.hpp>

Ship::Ship(btDynamicsWorld* physics_world) :
_model("Resources/models/player/ship.dae", &Global::shader_manager->phong3d),
_basic_attack_model("Resources/models/projectile/basic_attack.dae", &Global::shader_manager->phong3d),
Killable(1000.0)
{
	pose = std::make_unique<btDefaultMotionState>(btTransform(toQuat(_init_orientation), toVec3(_init_pos)));
	_drawable = std::make_unique<DrawableObject>(pose.get(), &_model);
	_moveable = std::make_unique<MoveableObject>(MoveableObject::ObjectType::SIMULATED, pose.get(), _model.GetCollisionShape(), _init_weight);


	_moveable->rigid_body->setUserPointer(static_cast<ICollidable*>(this));
	_moveable->rigid_body->setCollisionFlags(_moveable->rigid_body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	_moveable->rigid_body->setDamping(0.5, 0.5);
	
	_physics_world = physics_world;

	_physics_world->addRigidBody(_moveable->rigid_body.get());
}


Ship::~Ship()
{
	_physics_world->removeRigidBody(_moveable->rigid_body.get());
	for (auto& a : _basic_attacks)
	{
		_physics_world->removeRigidBody(a->moveable->rigid_body.get());
	}
}


void Ship::Update(double dt)
{
	if (alive)
	{
		auto rigid_body = _moveable->rigid_body.get();

		rigid_body->activate(true);

		auto transform = rigid_body->getWorldTransform();
		auto position = transform.getOrigin();
		auto rotation = transform.getRotation();

		const float max_speed = 100;

		if (input.propel_forward)
		{
			rigid_body->applyCentralImpulse(quatRotate(rotation, btVector3(max_speed, 0, 0)));
		}
		if (input.propel_backward)
		{
			rigid_body->applyCentralImpulse(quatRotate(rotation, btVector3(-max_speed, 0, 0)));
		}

		const float max_rotation_speed = 20 * glm::pi<float>();

		if (input.roll_right)
		{
			rigid_body->applyTorqueImpulse(quatRotate(rotation, btVector3(max_rotation_speed, 0, 0)));
		}
		if (input.roll_left)
		{
			rigid_body->applyTorqueImpulse(quatRotate(rotation, btVector3(-max_rotation_speed, 0, 0)));
		}

		if (input.pitch_up)
		{
			rigid_body->applyTorqueImpulse(quatRotate(rotation, btVector3(0, 0, max_rotation_speed)));
		}
		if (input.pitch_down)
		{
			rigid_body->applyTorqueImpulse(quatRotate(rotation, btVector3(0, 0, -max_rotation_speed)));
		}

		if (input.shoot)
		{
			_basic_attacks.emplace_back(std::make_unique<BasicAttack>(
				50.0,
				1, 
				toVec3(position + quatRotate(rotation, btVector3(15, 0, 0))),
				toQuat(rotation), 
				toVec3(rigid_body->getLinearVelocity() + quatRotate(rotation, btVector3(100, 0, 0))),
				&_basic_attack_model));
			_physics_world->addRigidBody(_basic_attacks.back()->moveable->rigid_body.get());

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
				_physics_world->removeRigidBody((*a)->moveable->rigid_body.get());
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
		_drawable->Render(view_light_direction, view_matrix, projection_matrix);

		for (auto& a : _basic_attacks)
		{
			a->Render(view_light_direction, view_matrix, projection_matrix);
		}
	}
}