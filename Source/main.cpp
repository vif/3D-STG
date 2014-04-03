#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
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
	int width;
	int height;
	glfwGetWindowSize(window, &width, &height);
	//calculate such that (0, 0) is the screen center, left is positive x, and up is positive y
	world->input_manager.x_mouse = x - (double) width / 2.0;
	world->input_manager.y_mouse = -1*(y - (double) height / 2.0);
}


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
#define handle_key(__key) \
	if(key == GLFW_KEY_##__key && action == GLFW_PRESS) world->input_manager.__key##_key = true; \
	if(key == GLFW_KEY_##__key && action == GLFW_RELEASE) world->input_manager.__key##_key = false;

	handle_key(W);
	handle_key(A);
	handle_key(S);
	handle_key(D);
	handle_key(Q);
	handle_key(E);
	handle_key(C);
	handle_key(UP);
	handle_key(DOWN);
	handle_key(LEFT);
	handle_key(RIGHT);
	handle_key(SPACE)
#undef handle_key
}

static void window_size_callback(GLFWwindow* window, int width, int height)
{
	auto aspect_ratio = glm::golden_ratio<double>();
	world->projectionMatrix = glm::infinitePerspective<double>(glm::radians(60.0f), aspect_ratio, 0.1);
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
	window = glfwCreateWindow(800, 640, "3D-STG", NULL, NULL);
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

	double previous_time = glfwGetTime();

	while (!glfwWindowShouldClose(window))
	{
		oglplus::Context::ClearColor(1, 1, 1, 1);
		oglplus::Context::Clear().ColorBuffer().DepthBuffer();

		auto current_time = glfwGetTime();
		world->physics_world.world->stepSimulation(current_time - previous_time, 10);
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
