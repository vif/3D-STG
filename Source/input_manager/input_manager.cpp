#include "input_manager.hpp"
#include <world/world.hpp>

//needed for the key names
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//manage_pressed_key sets mapped boolean to true when key is pressed
#define manage_pressed_key(keyname, mapname) \
if (key == keyname && action == GLFW_PRESS && mods == NULL) mapname = true;

//manage_released_key sets mapped boolean to false when key is released
#define manage_released_key(keyname, mapname) \
if (key == keyname && action == GLFW_RELEASE) mapname = false;


//manage_held_key sets mapped boolean to true when key is held, and false when it is released
#define manage_held_key(keyname, mapname) \
	manage_pressed_key(keyname, mapname); \
	manage_released_key(keyname, mapname);

//manage_toggle_key toggles the mapped boolean whenever the key is pressed
#define manage_toggle_key(keyname, mapname) \
	if(key == keyname && action == GLFW_PRESS && mods == NULL) mapname = !mapname;

void InputManager::keyboard(int key, int action, int mods)
{
	//SHIP Inputs
	manage_held_key(GLFW_KEY_W, _world->ship->input.propel_forward);
	manage_held_key(GLFW_KEY_S, _world->ship->input.propel_backward);
	manage_held_key(GLFW_KEY_RIGHT, _world->ship->input.roll_right);
	manage_held_key(GLFW_KEY_LEFT, _world->ship->input.roll_left);
	manage_held_key(GLFW_KEY_UP, _world->ship->input.pitch_up);
	manage_held_key(GLFW_KEY_DOWN, _world->ship->input.pitch_down);
	manage_pressed_key(GLFW_KEY_SPACE, _world->ship->input.shoot);

	//CAMERA Inputs
	manage_held_key(GLFW_KEY_I, _world->camera->input.move_forward);
	manage_held_key(GLFW_KEY_K, _world->camera->input.move_backward);
	manage_held_key(GLFW_KEY_J, _world->camera->input.strafe_left);
	manage_held_key(GLFW_KEY_L, _world->camera->input.strafe_right);
	manage_held_key(GLFW_KEY_O, _world->camera->input.move_up);
	manage_held_key(GLFW_KEY_U, _world->camera->input.move_down);
	manage_pressed_key(GLFW_KEY_C, _world->camera->input.toggle_ship_follow);

	//WORLD Inputs
	manage_toggle_key(GLFW_KEY_F11, _world->input.draw_physics_debug);
}

void InputManager::mouse(double dx, double dy)
{
	_world->camera->input.mouse_delta_x += dx;
	_world->camera->input.mouse_delta_y += dy;
}

#undef manage_pressed_key
#undef manage_released_key
#undef manage_held_key
#undef manage_toggle_key