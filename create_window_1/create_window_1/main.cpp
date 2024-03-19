#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main()
{
	/* initialize GLFW */
	glfwInit();
	/* configure GLFW */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	/*  create a window object */
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	/*  make the context of our window the main context on the current thread */
	glfwMakeContextCurrent(window);

	/* initialize GLAD before calling any OpenGL function */
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	/* tell OpenGL the size of the rendering window */
	glViewport(0, 0, 800, 600);

	/* call on every window resize */
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/* render loop */
	while (!glfwWindowShouldClose(window))
	{
		/* will swap the color buffer (a large 2D buffer that contains color 
		values for each pixel in GLFW�s window)*/
		glfwSwapBuffers(window);

		/* checks if any events are triggered */
		glfwPollEvents();
	}

	/*  clean/delete all of GLFW�s resources that were allocated */
	glfwTerminate();

	return 0;
}