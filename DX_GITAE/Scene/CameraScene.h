#pragma once
class CameraScene : public Scene
{
public:
	CameraScene();
	virtual ~CameraScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void Save();
	void Test(int t);


	void Load();

private:
	shared_ptr<Quad> _backGround;
	shared_ptr<Zelda> _zelda;
	shared_ptr<Transform> _zeldaFollow;
	shared_ptr<Button> _button;

	int test = 0;
};

