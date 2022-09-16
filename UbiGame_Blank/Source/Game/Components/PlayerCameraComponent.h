#pragma once
#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
	class PlayerCameraComponent : public GameEngine::Component
	{
	public:
		virtual void Update() override;
	};
}


