#pragma once

class ItemManager
{
public:
	ItemManager();
	~ItemManager();

	void Init();
	ItemData* GetItemData(string item);

	const unordered_map<string, ItemData>& GetItemTable() { return _dataTable; }

private:
	unordered_map<string, ItemData> _dataTable;
};

