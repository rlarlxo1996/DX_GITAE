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
};

