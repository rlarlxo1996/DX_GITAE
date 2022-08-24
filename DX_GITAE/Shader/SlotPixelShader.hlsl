cbuffer BgOrSlot : register(b0)
{
	int bgOrSlot;
	int padding1;
	int padding2;
	int padding3;
}

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

// 후면버퍼에 그릴 내용
// 1프레임당 호출 횟수 : 1280 x 720 만큼 호출
float4 PS(PixelInput input) : SV_TARGET
{
	if(bgOrSlot == 0)
		return float4(0.4f, 0.4f, 0.4f, 0.7f);

	return float4(0.8f, 0.8f, 0.8f, 0.8f);
}