#pragma once
class XMLScene : public Scene
{
public:
	XMLScene();
	virtual ~XMLScene();

	virtual void Update() override;
	virtual void Render() override;
private:
	shared_ptr<ItemManager> _itemManager;
};

