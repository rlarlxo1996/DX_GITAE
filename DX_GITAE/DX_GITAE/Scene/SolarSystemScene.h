#pragma once
class SolarSystemScene : public Scene
{
public:
	SolarSystemScene();
	virtual ~SolarSystemScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Texture> _sun;
	shared_ptr<Texture> _earth;
	shared_ptr<Texture> _moon;

	shared_ptr<Transform> _sunOrbit;
	shared_ptr<Transform> _earthOrbit;
};

