#pragma once
#include "Event.h"

namespace DawnView {

	class DV_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
		// GetCatogoryFlags
		EVENT_CLASS_CATEGORY( EventCategoryKeyboard | EventCategoryInput )

	protected:
		KeyEvent(int keyCode)
			: m_KeyCode(keyCode) {}

		int m_KeyCode;
	};

	class DV_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent (int keyCode, int repeatCount)
			: KeyEvent(keyCode), m_RepeatCount(repeatCount) {}
		inline int GetRepeatCount() const { return m_RepeatCount; }
		std::string ToString() const override 
		{ 
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " ( " << m_RepeatCount << " repeats).";
			return ss.str(); 
		}

		// GetStaticType, GetEventType, GetName
		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_RepeatCount;
	};

	class DV_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode << ".";
			return ss.str();
		}

		// GetStaticType, GetEventType, GetName
		EVENT_CLASS_TYPE(KeyReleased)

	};
}

