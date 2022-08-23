#include "framework.h"
#include "SceneManager.h"

#include "../Scene/Basic_Scene/TextureScene.h"
#include "../Scene/Basic_Scene/WVPScene.h"
#include "../Scene/Basic_Scene/SolarSystemScene.h"
#include "../Scene/Basic_Scene/DungreedScene.h"
#include "../Scene/Basic_Scene/CollisionScene.h"
#include "../Scene/Basic_Scene/SpriteScene.h"
#include "../Scene/Basic_Scene/FilterScene.h"
#include "../Scene/Basic_Scene/EffectScene.h"
#include "../Scene/Basic_Scene/CameraScene.h"
#include "../Scene/Basic_Scene/XMLScene.h"
#include "../Scene/Basic_Scene/PlaneShootScene.h"
#include "../Scene/Basic_Scene/InstancingScene.h"
#include "../Scene/Basic_Scene/InventoryScene.h"

SceneManager* SceneManager::_instance = nullptr;

SceneManager::SceneManager()
{
	_sceneTable["Dungreed"] = make_shared<DungreedScene>();
	_sceneTable["Zelda"] = make_shared<SpriteScene>();
	_sceneTable["Instancing"] = make_shared<InstancingScene>();
	_sceneTable["Inventory"] = make_shared<InventoryScene>();

	SetCurSence("Inventory");
}

SceneManager::~SceneManager()
{
}

void SceneManager::Update()
{
	if (_curScene.expired())
		return;

	_curScene.lock()->Update();
}

void SceneManager::Render()
{
	if (_curScene.expired())
		return;

	_curScene.lock()->Render();
}

void SceneManager::PreRender()
{
	if (_curScene.expired())
		return;

	_curScene.lock()->PreRender();
}

void SceneManager::PostRender()
{
	if (_curScene.expired())
		return;

	_curScene.lock()->PostRender();
}

void SceneManager::SetCurSence(string name)
{
	if (_sceneTable.count(name) == 0)
		return;

	_curScene = _sceneTable[name];
	_curScene.lock()->Init();
}


