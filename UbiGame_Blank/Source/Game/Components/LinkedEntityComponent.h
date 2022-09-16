#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include "SFML/System/Vector2.hpp"

class GameEngine::Entity;

namespace Game
{
	class LinkedEntityComponent : public GameEngine::Component
	{
	public:
		virtual void Update() override;
		void SetFollowedEntity(GameEngine::Entity* entity);
		//void SetFollowedOffset();
	private:
		GameEngine::Entity* m_followedEntity = nullptr;
		sf::Vector2f m_offset = sf::Vector2f(0.f, 0.f);
	};
}