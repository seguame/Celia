#include "input.h"

namespace celia { namespace input {

	// Setup the mouse singleton.
	Mouse Mouse::m_instance;

	Mouse& Mouse::GetInstance( void )
	{
		return Mouse::m_instance;
	}

	Mouse::Mouse( void )
	{
		for (int i = 0; i < MAX_BUTTONS; ++i)
		{
			m_buttons[i] = false;
		}
	}


	// Setup the keyboard singleton.
	Keyboard Keyboard::m_instance;

	Keyboard& Keyboard::GetInstance( void )
	{
		return Keyboard::m_instance;
	}

	Keyboard::Keyboard( void )
	{
		for (int i = 0; i < MAX_KEYS; ++i)
		{
			m_keys[i] = false;
		}
	}

} }