#pragma once
class ItemIcon;

class Store
{
public:
	Store(Vector2 size);
	~Store();

	void Update();
	void PostRender();

	void SetItemDataes();
	void CreateSlotGroup();
	void SetIcon();

	void BuyItem();

	void SetIventory(shared_ptr<Inventory> inventory) { _targetInventory = inventory; }

private:
	shared_ptr<ItemIcon> _icon;

	shared_ptr<Quad> _backGround;
	vector<shared_ptr<Button>> _slotGroup;

	vector<ItemData> _itemDataes;

	Vector2 _size;
	int _slotCount = 0;

	Vector2 _slotOffset;
	Vector2 _slotXY;

	shared_ptr<Button> _buyButton;

	weak_ptr<Inventory> _targetInventory;

	shared_ptr<BgOrSlotBuffer> _bsBuffer;
};

