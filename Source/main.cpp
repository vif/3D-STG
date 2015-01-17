#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <oglplus.hpp>
#include <world/world.hpp>
#include <utilities/ShaderManager/shadermanager.hpp>

World* world;  //world can't be initialized here, must be initialized after glew
ShaderManager* Global::shader_manager; //again, must be initialized after glew

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

static void mouse_callback(GLFWwindow* window, double x, double y)
{
	world->input_manager.mouse(x, -y);
	glfwSetCursorPos(window, 0, 0); //we are only handling delta offsets so reset to (0,0) after we done
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE) glfwSetWindowShouldClose(window, true);
	world->input_manager.keyboard(key, action, mods);
}

static void window_size_callback(GLFWwindow* window, int width, int height)
{
	world->display_info.SetScreenSize(width, height);
}

int main(void)
{
	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	window = glfwCreateWindow(1280, 720, "3D-STG", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}
	glGetError(); //clears the errors that glewInit() might have accumulated

	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);

	//disable the mouse and set it initially to 0,0
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(window, 0, 0);

	Global::shader_manager = new ShaderManager();
	world = new World();

	{   //do the window resize callback for the initial size
		int height;
		int width;
		glfwGetWindowSize(window, &width, &height);
		window_size_callback(window, width, height);
	}

	oglplus::Context::Enable(oglplus::Capability::DepthTest);
	oglplus::Context::Enable(oglplus::Capability::CullFace);

	double current_time, previous_time = glfwGetTime();

	while (!glfwWindowShouldClose(window))
	{
		oglplus::Context::ClearColor(1, 1, 1, 1);
		oglplus::Context::Clear().ColorBuffer().DepthBuffer();

		current_time = glfwGetTime();
		int times = world->physics_world.world->stepSimulation(current_time - previous_time, 10);
		previous_time = current_time;

		world->Render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//CLEANUP

	delete world;
	delete Global::shader_manager;

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
