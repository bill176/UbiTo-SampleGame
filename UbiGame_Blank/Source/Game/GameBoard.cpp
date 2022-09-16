#include "GameBoard.h"
#include "Components/PlayerMovementComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem//Components/SpriteRenderComponent.h"
#include <GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h>
#include "Components/LinkedEntityComponent.h"
#include "Components/PlayerCameraComponent.h"

using namespace Game;

GameBoard::GameBoard()
	: m_player(nullptr)
{
	CreatePlayer();
	CreateObstacle();
	CreateBackground();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	

}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(100.f, 100.f));
	m_player->SetSize(sf::Vector2f(50.f, 50.f));

	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>(m_player->AddComponent<GameEngine::SpriteRenderComponent>());
	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Player);

	m_player->AddComponent<Game::PlayerMovementComponent>();
	m_player->AddComponent<GameEngine::AnimationComponent>();
	m_player->AddComponent<GameEngine::CollidablePhysicsComponent>();
	m_player->AddComponent<Game::PlayerCameraComponent>();

}

void GameBoard::CreateObstacle()
{
	GameEngine::Entity* obstacle = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);

	obstacle->SetPos(sf::Vector2f(350.f, 150.f));
	obstacle->SetSize(sf::Vector2f(150.f, 150.f));

	auto spriteRender = static_cast<GameEngine::SpriteRenderComponent*>(obstacle->AddComponent<GameEngine::SpriteRenderComponent>());
	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Obstacle);

	obstacle->AddComponent<GameEngine::CollidableComponent>();
}

void GameBoard::CreateBackground()
{
	GameEngine::Entity* bg = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bg);

	bg->SetPos(sf::Vector2f(200.f, 200.f));
	bg->SetSize(sf::Vector2f(200.f, 200.f));

	auto render = static_cast<GameEngine::SpriteRenderComponent*>(bg->AddComponent<GameEngine::SpriteRenderComponent>());
	render->SetTexture(GameEngine::eTexture::BG);
	render->SetFillColor(sf::Color::Transparent);
	render->SetZLevel(-1);

	auto linkedCmp = static_cast<LinkedEntityComponent*>(bg->AddComponent<LinkedEntityComponent>());
	linkedCmp->SetFollowedEntity(m_player);
	//linkedCmp->SetFollowedOffset(sf::Vector2f(0.f, 0.f));
}