#include "Game/Components/LinkedEntityComponent.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

void LinkedEntityComponent::Update()
{
	__super::Update();

	if (m_followedEntity)
	{
		GetEntity()->SetPos(m_followedEntity->GetPos() + m_offset);
	}
}

void LinkedEntityComponent::SetFollowedEntity(GameEngine::Entity* entity)
{
	m_followedEntity = entity;
}