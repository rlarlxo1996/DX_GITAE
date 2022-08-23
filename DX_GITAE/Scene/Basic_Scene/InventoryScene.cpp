#include "framework.h"
#include "InventoryScene.h"

InventoryScene::InventoryScene()
{
	_inventory = make_shared<Inventory>(Vector2(300,400));
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
	_inventory->SetRTV();
}

void InventoryScene::PostRender()
{
	_inventory->PostRender();
}

void InventoryScene::Init()
{
}