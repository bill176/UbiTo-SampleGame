#include "PlayerCameraComponent.h"
#include "GameEngine/Util/CameraManager.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

void PlayerCameraComponent::Update()
{
	__super::Update();
	GameEngine::CameraManager::GetInstance()->GetCameraView().setCenter(GetEntity()->GetPos());
}