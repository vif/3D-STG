#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <typedefs.hpp>
#include <game/gameintegrator.hpp>
#include <game/gameintegrator.hpp>
#include <game/gamerenderer.hpp>

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
		exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	window = glfwCreateWindow(640, 480, "3D-STG", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}
	glGetError(); //clears the errors that glewInit() might have accumulated

	glfwSetKeyCallback(window, key_callback);

	double t = 0.0;
	const double dt = 0.01;

	double currentTime = glfwGetTime();
	double accumulator = 0.0;

	Game::State previousState;
	Game::State currentState;

	while (!glfwWindowShouldClose(window))
	{
		double newTime = glfwGetTime();
		double frameTime = newTime - currentTime;
		if (frameTime > 0.25)
			frameTime = 0.25;	  // note: max frame time to avoid spiral of death
		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= dt)
		{
			previousState = currentState;
			Game::Integrate(currentState, t, dt);
			t += dt;
			accumulator -= dt;
		}

		const double alpha = accumulator / dt;

		Game::State state = currentState*alpha + previousState * (1.0 - alpha);

		Game::Render(state);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
