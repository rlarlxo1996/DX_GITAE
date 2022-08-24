#include "framework.h"
#include "Inventory.h"
#include "Object/Dungreed/ItemIcon.h" // Data의 정보를 이용해서 그릴 것

Inventory::Inventory(Vector2 size)
: _size(size)
{
	_rtv = make_shared<RenderTarget>(size.x, size.y);

	_backGround = make_shared<Quad>(L"Inventory_Pannel", size);
	shared_ptr<Texture> texture = Texture::Add(L"Inventory_texture", _rtv->GetSRV());
	_backGround->SetTexture(texture);
	_backGround->GetTransform()->GetPos() = Vector2(CENTER.x + 300.0f, CENTER.y);

	_icon = make_shared<ItemIcon>();

	_slotOffset.x = 75.0f;
	_slotOffset.y = 100.0f;

	_slotXY = { 3,3 };

	CreateSlotGroup();

	_itemDataes.resize(_slotCount);

	for (int i = 0; i < _slotCount; i++)
	{
		_icon->SetIcon(_itemDataes[i].name, _slotGroup[i]->GetTransform()->GetPos());
	}

	_bsBuffer = make_shared<BgOrSlotBuffer>();
}

Inventory::~Inventory()
{
}

void Inventory::Update()
{
	_backGround->Update();
	_icon->Update();
}

void Inventory::SetRTV()
{
	_rtv->Set();
}

void Inventory::PostRender()
{
	_backGround->Render();

	_bsBuffer->_data.bgOrSlot = 1;
	_bsBuffer->SetPSBuffer(0);

	for (auto& slot : _slotGroup)
	{
		slot->Render();
	}

	_icon->Render();
}

void Inventory::CreateSlotGroup()
{
	for (int i = 0; i < _slotCount; i++)
	{
		shared_ptr<Quad> slot = make_shared<Quad>(L"Inventory_slot", Vector2(50.0f, 50.0f),
			L"Shader/TextureVertexShader.hlsl",
			L"Shader/SlotPixelShader.hlsl");

		slot->GetTransform()->GetPos() = CENTER;
		slot->Update();
		_slotGroup.push_back(slot);
	}

	for (int y = 0; y < (int)_slotXY.y; y++)
	{
		for (int x = 0; x < (int)_slotXY.x; x++)
		{
			_slotGroup[x + y * _slotXY.y]->GetTransform()->GetPos().x = _backGround->LeftBottom().x + _slotOffset.x + _slotOffset.x * x;
			_slotGroup[x + y * _slotXY.y]->GetTransform()->GetPos().y = _backGround->RightTop().y - _slotOffset.y - _slotOffset.y * y;
			_slotGroup[x + y * _slotXY.y]->GetTransform()->UpdateWorld();
		}
	}
}

void Inventory::AddItem(const ItemData& data)
{
	int slotIndex = 0;

	for (auto& item : _itemDataes)
	{
		if (item.name == "NONE")
		{
			item = data;
			break;
		}

		slotIndex++;
	}

	if (slotIndex >= _slotCount)
		return;
	
	_icon->SetIcon(data.name, _slotGroup[slotIndex]->GetTransform()->GetPos());
}
