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

private:
	shared_ptr<ItemIcon> _icon;

	shared_ptr<Quad> _backGround;
	vector<shared_ptr<Quad>> _slotGroup;

	vector<ItemData> _itemDataes;

	Vector2 _size;
	int _slotCount = 0;

	Vector2 _slotOffset;
	Vector2 _slotXY;

	shared_ptr<BgOrSlotBuffer> _bsBuffer;
};

