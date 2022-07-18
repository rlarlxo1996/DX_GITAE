#pragma once
class Button
{
public:
	Button();
	~Button();

	void Update();
	void PostRender();

	void SetPosition(Vector2 pos);
	void SetScale(Vector2 scale);
	void SetText(string text);

private:
	shared_ptr<Quad> _quad;
	shared_ptr<RectCollider> _collider;
	string _text;

	Vector2 _buttonPos;
};