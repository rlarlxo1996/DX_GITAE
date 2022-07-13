#include "framework.h"
#include "Zelda.h"

Zelda::Zelda()
{
	_sprite = make_shared<Sprite>(L"Resource/zelda.png", Vector2(10, 8));
	//_pos = { WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f };

	_collider = make_shared<RectCollider>(_sprite->GetFrameHalfSize());
	_collider->SetParent(_sprite->GetTransform());

	CreateActions();

	SetAnimation(_state);
}

Zelda::~Zelda()
{
}

void Zelda::Update()
{
	KeyBoardMove();

	_sprite->Update();
	_collider->Update();
	
	for (auto& action : _actions)
	{
		action->Update();
		if(action->IsPlay())
			_sprite->SetActionToActionBuffer(action->GetCurClip());
	}
}

void Zelda::Render()
{
	_sprite->Render();
}

void Zelda::PostRender()
{
	_collider->Render();
}

void Zelda::CreateActions()
{
	vector<Action::Clip> clips;
	clips.reserve(10);
	float w = 1200.0f / 10.0f;
	float h = 1040.0f / 8.0f;

	// F_IDLE
	{
		clips.emplace_back(1200 * 0			, 0, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w		, 0, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 2	, 0, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "F_IDLE", Action::PINGPONG, 0.3f);
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// L_IDLE
	{
		clips.emplace_back(1200 * 0			, h, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w		, h, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 2	, h, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "L_IDLE", Action::PINGPONG, 0.3f);
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// B_IDLE
	{
		clips.emplace_back(1200 * 0, h * 2, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "B_IDLE" ,Action::LOOP, 0.3f);
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// R_IDLE
	{
		clips.emplace_back(1200 * 0			, h * 3, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w		, h * 3, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 2	, h * 3, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "R_IDLE", Action::PINGPONG, 0.3f);
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// F_RUN
	{
		clips.emplace_back(1200 * 0			, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w		, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 2	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 3	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 4	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));

		clips.emplace_back(1200 * 0 + w * 5	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 6	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 7	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 8	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 9	, h * 4, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "F_RUN");
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// L_RUN
	{
		clips.emplace_back(1200 * 0			, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w		, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 2	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 3	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 4	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));

		clips.emplace_back(1200 * 0 + w * 5	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 6	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 7	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 8	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 9	, h * 5, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "L_RUN");
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// B_RUN
	{
		clips.emplace_back(1200 * 0			, h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w		, h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 2	, h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 3	, h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 4	, h * 6, w, h, Texture::Add(L"Resource/zelda.png"));

		clips.emplace_back(1200 * 0 + w * 5, h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 6, h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 7, h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 8, h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 9, h * 6, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "B_RUN");
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
	// R_RUN
	{
		clips.emplace_back(1200 * 0				, h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w			, h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 2		, h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 3		, h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 4		, h * 7, w, h, Texture::Add(L"Resource/zelda.png"));

		clips.emplace_back(1200 * 0 + w * 5		, h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 6		, h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 7		, h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 8		, h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		clips.emplace_back(1200 * 0 + w * 9		, h * 7, w, h, Texture::Add(L"Resource/zelda.png"));
		shared_ptr<Action> action = make_shared<Action>(clips, "R_RUN");
		action->Pause();
		_actions.push_back(action);
		clips.clear();
	}
}

void Zelda::SetAnimation(Zelda::State state)
{
	if (_actions[state]->IsPlay() &&
		(_actions[state]->GetReapeatTyoe() == Action::LOOP || _actions[state]->GetReapeatTyoe() == Action::PINGPONG))
		return;

	for (auto& action : _actions)
	{
		if (action->IsPlay() && _state == state)
		{
			continue;
		}

		action->Reset();
	}

	_state = state;
	_actions[static_cast<UINT>(state)]->Play();
}

void Zelda::KeyBoardMove()
{
	SetPosition(_pos);

	if (KEY_PRESS('W'))
	{
		_pos.y += 400.0f * DELTA_TIME;
		SetAnimation(Zelda::State::B_RUN);
		return;
	}

	if (KEY_PRESS('S'))
	{
		_pos.y -= 400.0f * DELTA_TIME;
		SetAnimation(Zelda::State::F_RUN);
		return;
	}

	if (KEY_PRESS('A'))
	{
		_pos.x -= 400.0f * DELTA_TIME;
		SetAnimation(Zelda::State::L_RUN);
		return;
	}

	if (KEY_PRESS('D'))
	{
		_pos.x += 400.0f * DELTA_TIME;
		SetAnimation(Zelda::State::R_RUN);
		return;
	}

	SetIDLE();
}

void Zelda::SetIDLE()
{
	switch (_state)
	{
	case Zelda::F_RUN:
		SetAnimation(F_IDLE);
		break;
	case Zelda::L_RUN:
		SetAnimation(L_IDLE);
		break;
	case Zelda::B_RUN:
		SetAnimation(B_IDLE);
		break;
	case Zelda::R_RUN:
		SetAnimation(R_IDLE);
		break;
	default:
		break;
	}
}
