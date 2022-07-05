#pragma once
class SpriteScene : public Scene
{
public:
	SpriteScene();
	virtual ~SpriteScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void Test() { _hello = "Hello CallBack!"; }

private:
	shared_ptr<Sprite> _sprite;
	shared_ptr<Action> _action;

	string _hello = "";

	int _curFrameX = 0;
	int _curFrameY = 0;
};

