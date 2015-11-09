#include <iostream>
#include "window.h"

namespace celia { namespace graphics {

	void windowResize(GLFWwindow *window, int width, int height);

	Window::Window(const char *name, int width, int height) 
	{
		m_title		= name;
		m_width		= width;
		m_height	= height;

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

		m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
		
		if ( !m_window ) 
		{
			glfwTerminate();
			std::cout << "Failed to create new Window" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_window);
		glfwSetWindowSizeCallback(m_window, windowResize);

		if ( glewInit() != GLEW_OK )
		{
			std::cerr << "Could not initialize GLEW!" << std::endl;
			return false;
		}

		return true;
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_window) == 1;
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	int Window::getWidth() const 
	{
		return m_width; 
	}

	int Window::getHeight() const 
	{ 
		return m_height; 
	}


	//CALLBACKS
	void windowResize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}}