#pragma once

namespace celia { namespace input {

#define MAX_KEYS    1024
#define MAX_BUTTONS 32

	class Mouse
	{
	public:
		static Mouse& GetInstance();

		inline double getX() const { return m_mx; }
		inline double getY() const { return m_my; };
		inline void setX(double x) { m_mx = x; };
		inline void setY(double y) { m_my = y; };
		inline void setButtonState(unsigned int button, bool state) { m_buttons[button] = state; };
		inline bool is_pressed(unsigned int button) const { return m_buttons[button]; };

	private:
		Mouse();

	private:
		static Mouse m_instance;

		bool   m_buttons[MAX_BUTTONS];
		double m_mx;
		double m_my;
	};

	class Keyboard
	{
	public:
		static Keyboard& GetInstance();

		inline void setKeyState(unsigned int key, bool state) { m_keys[key] = state;}
		inline bool is_pressed(unsigned int key) const { return m_keys[key]; }

	private:
		Keyboard();

	private:
		static Keyboard m_instance;

		bool m_keys[MAX_KEYS];
	};

} }