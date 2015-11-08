#include "src\graphics\window.h"

int main(void) 
{
	using namespace celia;
	using namespace graphics;

	Window window("Celia!", 400, 400);
	glClearColor(0.2f, 0.1f, 0.3f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;

	while (!window.closed())
	{
		//std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;

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
