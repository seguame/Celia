#include <iostream>
#include "src\graphics\window.h"
#include "src\input\input.h"

int main(void) 
{
	using namespace celia;
	using namespace graphics;
	using namespace input;

	Window window("Celia!", 400, 400);
	glClearColor(0.2f, 0.1f, 0.3f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;

	Mouse& mouse = Mouse::GetInstance();
	Keyboard& keyboard = Keyboard::GetInstance();

	while ( !window.closed() )
	{
		std::cout << "X: " << mouse.getX() << " Y: " << mouse.getY() << std::endl;
		if (mouse.is_pressed(GLFW_MOUSE_BUTTON_1))
		{
			std::cout << "Mouse pressed " << std::endl;
		}

		if (keyboard.is_pressed(GLFW_KEY_A))
		{
			std::cout << "KB pressed " << std::endl;
		}

		window.clear();

		glBegin(GL_QUADS);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(-0.5f, 0.5f);
			glVertex2f(0.5f, 0.5f);
			glVertex2f(0.5f, -0.5f);
		glEnd();

		window.update();
	}

	return 0;
}