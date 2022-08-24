#pragma once
class ItemManager;

class DataManager
{
public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new DataManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static DataManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;
	}

	int GetMoney() { return money; }
	void AddMoney(int amount) { money += amount; }
	shared_ptr<ItemManager> GetItemManager() { return _itemManager; }


private:
	DataManager();
	~DataManager();

	static DataManager* _instance;

	shared_ptr<ItemManager> _itemManager;

	int money;

};

