#include "PlayerMovementComponent.h"
#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs
#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

using namespace Game;

void PlayerMovementComponent::Update()
{
    Component::Update();

    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();

    //By default the displacement is 0,0
    sf::Vector2f displacement{ 0.0f,0.0f };

    //The amount of speed that we will apply when input is received
    const float inputAmount = 100.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        displacement.x -= inputAmount * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        displacement.x += inputAmount * dt;
    }

    //Update the entity position
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);

    int maxIndex = 4;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        m_wasFaceSwapButtonPressed = true;
    }
    else
    {
        if (m_wasFaceSwapButtonPressed)
        {
            //++m_currentFaceIndex;  // <-- We need to add a new int m_currentFaceIndex attribute member to the class
            //if (m_currentFaceIndex >= maxIndex) m_currentFaceIndex = 0;
            //GameEngine::SpriteRenderComponent* render = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();
            //if (render)
            //{
            //    render->SetTileIndex(sf::Vector2i(m_currentFaceIndex, 0));
            //}
            GameEngine::AnimationComponent* animComponent = GetEntity()->GetComponent<GameEngine::AnimationComponent>();
            if (animComponent)
            {
                animComponent->PlayAnim(GameEngine::EAnimationId::BirdFly);
            }
        }

        m_wasFaceSwapButtonPressed = false;
    }
}

void PlayerMovementComponent::OnAddToWorld() {}