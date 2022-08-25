#include "framework.h"
#include "Store.h"

Store::Store(Vector2 size)
{
	_backGround = make_shared<Quad>(L"Resource/UI/InventoryPanel.png");

	_backGround->GetTransform()->GetPos() = Vector2(CENTER.x - 300.0f, CENTER.y);

	_icon = make_shared<ItemIcon>();

	_slotOffset.x = 135.0f;
	_slotOffset.y = 120.0f;

	_slotXY = { 3,3 };

	SetItemDataes();
	CreateSlotGroup();
	SetIcon();

	_buyButton = make_shared<Button>(L"Resource/UI/BuyBtn.png");
	Vector2 buyPos = Vector2(_backGround->GetTransform()->GetPos().x - 70.0f, _backGround->LeftBottom().y + 70.0f);
	_buyButton->SetText("BUY");
	_buyButton->SetPosition(buyPos);
	_buyButton->SetScale(Vector2(1.0f, 0.4f));
	_buyButton->SetEvent(std::bind(&Store::BuyItem, this));

	_bsBuffer = make_shared<BgOrSlotBuffer>();
}

Store::~Store()
{
}

void Store::Update()
{
	_backGround->Update();

	_icon->Update();

	_buyButton->Update();

	for (auto& slot : _slotGroup)
	{
		slot->Update();
	}
}

void Store::PostRender()
{
	_backGround->Render();

	_bsBuffer->_data.bgOrSlot = 1;
	_bsBuffer->SetPSBuffer(0);

	for (auto& slot : _slotGroup)
	{
		slot->PostRender();
	}

	_icon->Render();
	_buyButton->PostRender();
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
		shared_ptr<Button> slot = make_shared<Button>(L"Resource/UI/SlotBtn.png");

		_slotGroup.push_back(slot);
	}

	for (int y = 0; y < (int)_slotXY.y; y++)
	{
		for (int x = 0; x < (int)_slotXY.x; x++)
		{
			if (x + y * _slotXY.y >= _slotCount)
				return;

			Vector2 pos = { _backGround->LeftBottom().x + _slotOffset.x + _slotOffset.x * x,
							_backGround->RightTop().y - _slotOffset.y + _slotOffset.y * y };
			_slotGroup[x + y * _slotXY.y]->GetTransform()->UpdateWorld();
		}
	}
}

void Store::SetIcon()
{
	for (int i = 0; i < _slotCount; i++)
	{
		_icon->SetIcon(_itemDataes[i].name, _slotGroup[i]->GetTransform()->GetPos());
	}
}

void Store::BuyItem()
{
	if (_targetInventory.expired() == true)
		return;

	if (DATA->GetMoney() - _itemDataes[0].price < 0)
		return;

	if (_targetInventory.lock()->AddItem(_itemDataes[0]))
		DATA->AddMoney(-_itemDataes[0].price);
}
