#include "input_manager.hpp"
#include <world/world.hpp>

//needed for the key names
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void InputManager::keyboard(int key, int action, int mods)
{
	//manage_held_key does a one to one mapping between whether key is pressed and the mapped boolean is true
#define manage_held_key(keyname, mapname) \
	if (key == keyname && action == GLFW_PRESS && mods == NULL) mapname = true; \
	if (key == keyname && action == GLFW_RELEASE) mapname = false;

	//manage_toggle_key toggles the mapped boolean whenever the key is pressed
#define manage_toggle_key(keyname, mapname) \
	if(key == keyname && action == GLFW_PRESS && mods == NULL) mapname = !mapname;

	//SHIP Inputs
	manage_held_key(GLFW_KEY_W, _world->ship.input.propel_forward);
	manage_held_key(GLFW_KEY_S, _world->ship.input.propel_backward);
	manage_held_key(GLFW_KEY_RIGHT, _world->ship.input.roll_right);
	manage_held_key(GLFW_KEY_LEFT, _world->ship.input.roll_left);
	manage_held_key(GLFW_KEY_UP, _world->ship.input.pitch_up);
	manage_held_key(GLFW_KEY_DOWN, _world->ship.input.pitch_down);

	//CAMERA Inputs
	manage_held_key(GLFW_KEY_I, _world->camera->input.move_forward);
	manage_held_key(GLFW_KEY_K, _world->camera->input.move_backward);
	manage_held_key(GLFW_KEY_J, _world->camera->input.strafe_left);
	manage_held_key(GLFW_KEY_L, _world->camera->input.strafe_right);
	if (key == GLFW_KEY_C && action == GLFW_PRESS && mods == NULL)
	{
		if (_world->camera->input.follow_ship == true)
		{
			//sets cameras pose & position to current one
			_world->camera->free_move_orientation = _world->camera->orientation;
			_world->camera->free_move_position = _world->camera->position;
		}
		else //_world->camera->input.follow_ship == false
		{
			//sets cameras own rotation to nothing
			_world->camera->camera_follow_orientation = glm::quat();
		}

		//toggle whether we follow or not
		_world->camera->input.follow_ship = !_world->camera->input.follow_ship;
	}

	//WORLD Inputs
	manage_toggle_key(GLFW_KEY_F11, _world->input.draw_physics_debug);

#undef manage_held_key
#undef manage_toggle_key
}

void InputManager::mouse(double dx, double dy)
{
	_world->camera->input.mouse_delta_x += dx;
	_world->camera->input.mouse_delta_y += dy;
}