#pragma once
class PlaneShootScene : public Scene
{
public:
	PlaneShootScene();
	virtual ~PlaneShootScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

private:
	shared_ptr<PlaneShoot> _planeShoot;
	shared_ptr<Transform> _planeFollow;
	shared_ptr<Quad> _worldMap;

	shared_ptr<Aim> _aim;
};

