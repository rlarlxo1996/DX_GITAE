#pragma once
class CollisionScene : public Scene
{
public:
	CollisionScene();
	virtual ~CollisionScene();

	virtual void Update() override;
	virtual void Render() override;

	virtual void PostRender() override;

private:
	shared_ptr<RectCollider> _rectCollider1;
	//shared_ptr<RectCollider> _rectCollider2;

	shared_ptr<CircleCollider> _circleCollider1;
	//shared_ptr<CircleCollider> _circleCollider2;
};

