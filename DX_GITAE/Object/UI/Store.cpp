#include "framework.h"
#include "Store.h"

Store::Store(Vector2 size)
{
	_backGround = make_shared<Quad>(L"Store_BG", Vector2(50.0f, 50.0f),
		L"Shader/TextureVertexShader.hlsl",
		L"Shader/SlotPixelShader.hlsl");

	_backGround->GetTransform()->GetPos() = Vector2(CENTER.x - 300.0f, CENTER.y);

	_icon = make_shared<ItemIcon>();

	_slotOffset.x = 75.0f;
	_slotOffset.y = 100.0f;

	_slotXY = { 3,3 };

	SetItemDataes();

	CreateSlotGroup();

	_bsBuffer = make_shared<BgOrSlotBuffer>();
}

Store::~Store()
{
}

void Store::Update()
{
}

void Store::PostRender()
{
}

void Store::SetItemDataes()
{
	auto unMap = DATA->GetItemManager()->GetItemTable();

	_itemDataes.clear();
	for (auto& pair : unMap)
	{
		_itemDataes.push_back(pair.second);
	}

	_slotCount = _itemDataes.size();
}

void Store::CreateSlotGroup()
{
	for (int i = 0; i < _slotCount; i++)
	{
		shared_ptr<Quad> slot = make_shared<Quad>(L"Inventory_slot", Vector2(50.0f, 50.0f),
			L"Shader/TextureVertexShader.hlsl",
			L"Shader/SlotPixelShader.hlsl");

		_slotGroup.push_back(slot);
	}

}
