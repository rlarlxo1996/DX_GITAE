#include "framework.h"
#include "InventoryScene.h"

InventoryScene::InventoryScene()
{
	_inventory = make_shared<Inventory>();
}

InventoryScene::~InventoryScene()
{
}

void InventoryScene::Update()
{
	_inventory->Update();
}

void InventoryScene::Render()
{

}

void InventoryScene::PreRender()
{
}

void InventoryScene::PostRender()
{
	_inventory->Render();
}

void InventoryScene::Init()
{
}