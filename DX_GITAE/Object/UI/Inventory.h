#pragma once
class ItemIcon;

class Inventory
{
public:
	Inventory(Vector2 size);
	~Inventory();

	void Update();
	void SetRTV();
	void PostRender();

	void CreateSlotGroup();

	void AddItem(const ItemData& data);

private:
	shared_ptr<ItemIcon> _icon;

	shared_ptr<RenderTarget> _rtv;
	shared_ptr<Quad> _backGround;
	vector<shared_ptr<Quad>> _slotGroup;

	vector<ItemData> _itemDataes;

	Vector2 _size;
	int _slotCount = 9;

	Vector2 _slotOffset;
	Vector2 _slotXY;
	
	shared_ptr<BgOrSlotBuffer> _bsBuffer;
};


