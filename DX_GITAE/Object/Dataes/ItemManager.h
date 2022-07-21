#pragma once

class ItemManager
{
public:
	ItemManager();
	~ItemManager();

	void Init();
	ItemData* GetItemData(string item);

private:
	unordered_map<string, ItemData> _dataTable;
};

