// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <memory>
#include <tchar.h>
#include <time.h>

#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <functional>

#include <wrl/client.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib, "dxguid.lib")

using namespace DirectX;
using namespace std;

// DirectXTeX
#include "../DirectXTex/DirectXTex.h"

// ImGui
#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_dx11.h"
#include "../ImGui/imgui_impl_win32.h"

// Device
#include "Framework/Device/Device.h"


// TypeDef
#include "TypeDef.h"

// Math
#include "Framework/Math/Vector2.h"
#include "Framework/Math/Transform.h"

// Render
#include "Framework/Render/VertexLayOuts.h"
#include "Framework/Render/ConstantBuffer.h"
#include "Framework/Render/GlobalBuffer.h"
#include "Framework/Render/IndexBuffer.h"
#include "Framework/Render/Shader.h"
#include "Framework/Render/VertexShader.h"
#include "Framework/Render/PixelShader.h"
#include "Framework/Render/ShaderManager.h"
#include "Framework/Render/VertexBuffer.h"
#include "Framework/Render/SRV.h"
#include "Framework/Render/Texture.h"

// Camera
#include "Framework/Camera/Camera.h"

// State
#include "Framework/State/SamplerState.h"
#include "Framework/State/BlendState.h"
#include "Framework/State/StateManager.h"

// Utility
#include "Framework/Utility/Timer.h"
#include "Framework/Utility/InputManager.h"
#include "Framework/Utility/Utility.h"
#include "Framework/Utility/MathUtility.h"

// Collider
#include "Framework/Collider/Collider.h"
#include "Framework/Collider/CircleCollider.h"
#include "Framework/Collider/RectCollider.h"

// Animation
#include "Framework/Animation/Action.h"

// Object
// Basic Object
#include "Object/BasicObject/Quad.h"
#include "Object/BasicObject/Sprite.h"
#include "Object/BasicObject/Effect.h"
#include "Object/BasicObject/EffectManager.h"
#include "Object/Zelda/Zelda.h"
#include "Object/Aim.h"

// Dungreed
#include "Object/Dungreed/Player.h"
#include "Object/Dungreed/Gun.h"
#include "Object/Dungreed/Bullet.h"
#include "Object/Dungreed/Monster.h"

// PlaneShoot
#include "Object/PlaneShoot/PlaneShoot.h"

// Scene
#include "Scene/Scene.h"

// Program
#include "Program/Program.h"