#include "framework.h"
#include "InventoryScene.h"

InventoryScene::InventoryScene()
{
	DATA->AddMoney(30000);

	_inventory = make_shared<Inventory>(Vector2(300,400));

	_inventory->AddItem(*DATA->GetItemManager()->GetItemData("Sword_1"));
	_inventory->AddItem(*DATA->GetItemManager()->GetItemData("Potion_1"));
	_inventory->AddItem(*DATA->GetItemManager()->GetItemData("Potion_1"));
	_inventory->AddItem(*DATA->GetItemManager()->GetItemData("Potion_1"));

	_store = make_shared<Store>(Vector2(300.0f, 400.0f));
	_store->SetIventory(_inventory);
}

InventoryScene::~InventoryScene()
{
}

void InventoryScene::Update()
{
	_inventory->Update();
	_store->Update();
}

void InventoryScene::Render()
{

}

void InventoryScene::PreRender()
{
}

void InventoryScene::PostRender()
{
	_inventory->PostRender();
	_store->PostRender();
}

void InventoryScene::Init()
{
}