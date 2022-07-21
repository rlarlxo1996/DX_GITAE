#include "framework.h"
#include "ItemManager.h"

ItemManager::ItemManager()
{
	Init();
}

ItemManager::~ItemManager()
{
}

void ItemManager::Init()
{
	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	string path = "Resource/XML/ItemData.xml";
	document->LoadFile(path.c_str());

	tinyxml2::XMLElement* workBook = document->FirstChildElement();
	tinyxml2::XMLElement* workSheet = workBook->FirstChildElement("Worksheet");
	tinyxml2::XMLElement* table = workSheet->FirstChildElement();
	tinyxml2::XMLElement* row = table->FirstChildElement();
	row = row->NextSiblingElement();

	while (true)
	{
		if (row == nullptr)
			break;
		// 1000 : 값을 넣어주는 코드
		tinyxml2::XMLElement* cell = row->FirstChildElement();
		tinyxml2::XMLElement* data = cell->FirstChildElement();

		string key;
		ItemData itemData;

		{ // 아이템 명
			key = data->GetText();
			itemData.name = key;
			cell = cell->NextSiblingElement();
		}
		{ // 정보 세팅
			//data = cell->FirstChildElement();
			//itemData.price = data->IntText();
			//cell = cell->NextSiblingElement();

			//data = cell->FirstChildElement();
			//itemData.value = data->IntText();
			//cell = cell->NextSiblingElement();

			//data = cell->FirstChildElement();
			//itemData.type = data->IntText();
			//cell = cell->NextSiblingElement();
			//
			//data = cell->FirstChildElement();
			//itemData.attackInfo = data->IntText();
			//cell = cell->NextSiblingElement();

			// 다른 방법
			vector<int> temp;
			temp.reserve(4);
			for (; cell != nullptr; cell = cell->NextSiblingElement())
			{
				tinyxml2::XMLElement* data = cell->FirstChildElement();
				temp.push_back(data->IntText());
			}

			itemData.price		= temp[0];
			itemData.value		= temp[1];
			itemData.type		= temp[2];
			itemData.attackInfo = temp[3];
		}

		_dataTable[key] = itemData;
		row = row->NextSiblingElement();
	}

}

ItemData* ItemManager::GetItemData(string item)
{
	if (_dataTable.count(item) == 0)
		return nullptr;

	return &_dataTable[item];
}
