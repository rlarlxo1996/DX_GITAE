#pragma once
class Zelda
{
public:
	enum State
	{
		F_IDLE,
		L_IDLE,
		B_IDLE,
		R_IDLE,

		F_RUN,
		L_RUN,
		B_RUN,
		R_RUN
	};

	Zelda();
	~Zelda();

	void Update();
	void Render();
	void PostRender();

	void CreateActions();

	shared_ptr<Transform> GetTransform() { return _sprite->GetTransform(); }

	void SetPosition(Vector2 pos) { _sprite->GetTransform()->GetPos() = pos; }
	void SetAnimation(Zelda::State state);

	void KeyBoardMove();
	void SetIDLE();

private:
	shared_ptr<Sprite> _sprite;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<Collider> _collider;

	Vector2 _pos = Vector2();
	State _state = State::F_IDLE;
};

