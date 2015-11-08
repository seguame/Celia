#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace celia { namespace graphics {

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
		const char *m_Title;
		int m_Width, m_Height;
		GLFWwindow *m_Window;
		bool m_Closed;
	};
} }