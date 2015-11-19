#include <iostream>
#include "window.h"

namespace celia { namespace graphics {

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

	bool Window::init( void ) 
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
		glfwSetWindowUserPointer(m_window, this);

		glfwSetWindowSizeCallback(m_window, cbWindowResize);
		glfwSetKeyCallback(m_window, cbKeyboard);
		glfwSetMouseButtonCallback(m_window, cbMouseClicks);
		glfwSetCursorPosCallback(m_window, cbMouseMovement);

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
	void cbWindowResize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void cbKeyboard(GLFWwindow *window, int key, int scancode, int action, int mods)
	{
		input::Keyboard::GetInstance().setKeyState(key, action != GLFW_RELEASE);
	}

	void cbMouseClicks(GLFWwindow *window, int button, int action, int mods)
	{
		input::Mouse::GetInstance().setButtonState(button, action != GLFW_RELEASE);
	}

	void cbMouseMovement(GLFWwindow *window, double xpos, double ypos)
	{
		input::Mouse& mouse = input::Mouse::GetInstance();

		mouse.setX(xpos);
		mouse.setY(ypos);
	}
}}