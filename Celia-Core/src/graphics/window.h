#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace celia { namespace graphics {

#define MAX_KEYS 1024

	class Window
	{
	public:
		Window(const char *name, int width, int height);
		~Window();
		bool closed() const;
		void update();
		void clear() const;
		int getWidth() const;
		int getHeight() const;

	private:
		//Functions
		bool init();

		//Variables
		const char *m_title;
		int m_width, m_height;
		GLFWwindow *m_window;
		bool m_closed;
	};
} }