Texture2D map : register(t0);
SamplerState samp : register(s0);

// SV -> System Value
struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
	float2 maxFrame : MAX_FRAME;
	float2 curFrame : CUR_FRAME;
};

// 후면버퍼에 그릴 내용
// 1프레임당 호출 횟수 : 1280 x 720 만큼 호출
float4 PS(PixelInput input) : SV_TARGET
{
	float2 uv = input.uv + (input.curFrame / input.maxFrame);

	return map.Sample(samp, uv);
}