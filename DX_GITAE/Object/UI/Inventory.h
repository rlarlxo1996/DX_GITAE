#pragma once
class Item;
class ItemIcon;

class Inventory
{
public:
	Inventory();
	~Inventory();

	void Update();
	void Render();

private:
	shared_ptr<ItemIcon> _icon;
};


