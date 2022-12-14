#pragma once
#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
	class PlayerMovementComponent : public GameEngine::Component
	{
	public:
		//PlayerMovementComponent();
		//~PlayerMovementComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;
	private:
		int m_currentFaceIndex = 0;
		bool m_wasFaceSwapButtonPressed = false;
	};
}


