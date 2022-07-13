#pragma once
class CameraScene : public Scene
{
public:
	CameraScene();
	virtual ~CameraScene();

	virtual void Update() override;
	virtual void Render() override;
private:
	shared_ptr<Quad> _backGround;
	shared_ptr<Zelda> _zelda;
	shared_ptr<Transform> _zeldaFollow;
};

