#pragma once
class Item;
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

private:
	shared_ptr<ItemIcon> _icon;

	shared_ptr<RenderTarget> _rtv;
	shared_ptr<Quad> _backGround;
	vector<shared_ptr<Quad>> _slotGroup;

	Vector2 _size;
	int _slotCount = 9;

	Vector2 _slotOffset;
	Vector2 _slotXY;
};


