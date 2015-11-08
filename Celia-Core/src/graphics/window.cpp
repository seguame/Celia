#include <iostream>
#include "window.h"

namespace celia { namespace graphics {

	void windowResize(GLFWwindow *window, int width, int height);

	Window::Window(const char *name, int width, int height) 
	{
		m_Title		= name;
		m_Width		= width;
		m_Height	= height;

		if ( !init() )
		{
			glfwTerminate();
		}
	}

	Window::~Window() 
	{
		glfwTerminate();
	}

	bool Window::init() 
	{
		if ( !glfwInit() )
		{
			std::cout << "Unable to start GLFW!" << std::endl;
			return false;
		} 

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		
		if ( !m_Window ) 
		{
			glfwTerminate();
			std::cout << "Failed to create new Window" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowSizeCallback(m_Window, windowResize);

		return true;
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window) == 1;
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	int Window::getWidth() const 
	{
		return m_Width; 
	}

	int Window::getHeight() const 
	{ 
		return m_Height; 
	}


	//CALLBACKS
	void windowResize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}}