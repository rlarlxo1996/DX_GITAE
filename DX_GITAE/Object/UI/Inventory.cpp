#include "framework.h"
#include "Inventory.h"
#include "Object/Dungreed/Item.h" // Data
#include "Object/Dungreed/ItemIcon.h" // Data의 정보를 이용해서 그릴 것

Inventory::Inventory(Vector2 size)
: _size(size)
{
	_rtv = make_shared<RenderTarget>(size.x, size.y);

	_backGround = make_shared<Quad>(L"Inventory_Pannel", size);
	shared_ptr<Texture> texture = Texture::Add(L"Inventory_texture", _rtv->GetSRV());
	_backGround->SetTexture(texture);
	_backGround->GetTransform()->GetPos() = CENTER;

	_icon = make_shared<ItemIcon>();
	_icon->SetIcon("Potion", CENTER);
	_icon->SetIcon("Sword", { CENTER.x + 75, CENTER.y });

	_slotOffset.x = 75.0f;
	_slotOffset.y = 100.0f;

	_slotXY = { 3,3 };

	CreateSlotGroup();
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
