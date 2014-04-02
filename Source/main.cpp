#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stl.hpp>
#include <glm.hpp>
#include <oglplus.hpp>
#include <world/world.hpp>
#include <utilities/ShaderManager/shadermanager.hpp>

std::unique_ptr<World> world;  //world can't be initialized here, must be initialized after glew
std::unique_ptr<ShaderManager> Global::shader_manager; //again, must be initialized after glew

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_W && action == GLFW_PRESS)
		world->ship.position += glm::vec3(1, 0, 0);
	if (key == GLFW_KEY_S && action == GLFW_PRESS)
		world->ship.position -= glm::vec3(1, 0, 0);
	if (key == GLFW_KEY_A && action == GLFW_PRESS)
		world->ship.position += glm::vec3(0, 0, 1);
	if (key == GLFW_KEY_D && action == GLFW_PRESS)
		world->ship.position -= glm::vec3(0, 0, 1);
	if (key == GLFW_KEY_R && action == GLFW_PRESS)
		world->ship.position += glm::vec3(0, 1, 0);
	if (key == GLFW_KEY_F && action == GLFW_PRESS)
		world->ship.position -= glm::vec3(0, 1, 0);
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
	glfwSetWindowSizeCallback(window, window_size_callback);


	Global::shader_manager = std::make_unique<ShaderManager>();
	world = std::make_unique<World>();

	{   //do the window resize callback for the initial size
		int height;
		int width;
		glfwGetWindowSize(window, &width, &height);
		window_size_callback(window, width, height);
	}

	oglplus::Context::Enable(oglplus::Capability::DepthTest);
	oglplus::Context::Enable(oglplus::Capability::CullFace);

	while (!glfwWindowShouldClose(window))
	{
		oglplus::Context::ClearColor(1, 1, 1, 1);
		oglplus::Context::Clear().ColorBuffer().DepthBuffer();
		world->integrate(0, 0);
		world->render(0, 0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//WORKAROUND for oglplus not cleaning up properly if context destroyed
	delete world.release();
	delete Global::shader_manager.release();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
