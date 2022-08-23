#include "framework.h"
#include "Inventory.h"
#include "Object/Dungreed/Item.h" // Data
#include "Object/Dungreed/ItemIcon.h" // Data의 정보를 이용해서 그릴 것

Inventory::Inventory()
{
	_icon = make_shared<ItemIcon>();
	_icon->SetIcon("Potion", CENTER);
}

Inventory::~Inventory()
{
}

void Inventory::Update()
{
	_icon->Update();
}

void Inventory::Render()
{
	_icon->Render();
}
