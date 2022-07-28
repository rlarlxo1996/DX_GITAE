#pragma once
class CameraScene : public Scene
{
public:
	CameraScene();
	virtual ~CameraScene();

	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void Save();

	void Load();

private:
	shared_ptr<Quad> _backGround;
	shared_ptr<Zelda> _zelda;
	shared_ptr<Transform> _zeladFollow;
	shared_ptr<Button> _button;

	shared_ptr<MiniMap> _miniMap;
};
