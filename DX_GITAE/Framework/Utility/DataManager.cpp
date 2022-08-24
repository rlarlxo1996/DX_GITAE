#include "framework.h"
#include "DataManager.h"
#include "Object/Dataes/ItemManager.h"

DataManager* DataManager::_instance = nullptr;

DataManager::DataManager()
{
	_itemManager = make_shared<ItemManager>();
}

DataManager::~DataManager()
{
}
