#pragma once
class DungreedScene : public Scene
{
public:
	DungreedScene();
	virtual ~DungreedScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	virtual void Init() override;

	void NextScene();

private:
	shared_ptr<Player> _player;
	shared_ptr<Monster> _monster;
	shared_ptr<Aim> _aim;

	shared_ptr<Button> _button;
};

