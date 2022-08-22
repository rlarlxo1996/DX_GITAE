#include "framework.h"
#include "XMLScene.h"

XMLScene::XMLScene()
{
	_itemManager = make_shared<ItemManager>();

	int DaesungBookAttck = _itemManager->GetItemData("Daesung's Book")->attackInfo;
}

XMLScene::~XMLScene()
{
}

void XMLScene::Update()
{
}

void XMLScene::Render()
{
}
