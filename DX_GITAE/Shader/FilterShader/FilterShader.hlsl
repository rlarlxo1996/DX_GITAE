cbuffer Filter :register(b0)
{
	int selected;
	int value1;
	int value2;
	int value3;
}

Texture2D map : register(t0);
SamplerState samp : register(s0);

// SV -> System Value
struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

float4 Mosaic(float2 uv)
{
	// floor 평탄화 : 소수 들어오면 소수점 뒤 다 날림
	float x = floor(uv.x * value1);
	float y = floor(uv.y * value1);

	float2 temp;
	temp.x = x / value1;
	temp.y = y / value1;
	
	return map.Sample(samp, temp);
}

float4 Bulr(float2 uv)
{
	float4 result = 0;

	for (int i = 0; i < value1; i++)
	{
		float divX = (i + 1) / 416;
		float divY = (i + 1) / 416;

		result += map.Sample(samp, float2(uv.x + divX, uv.y));
		result += map.Sample(samp, float2(uv.x - divX, uv.y));
		result += map.Sample(samp, float2(uv.x, uv.y + divY));
		result += map.Sample(samp, float2(uv.x, uv.y - divY));
	}

	result /= 4 * value1;
	return result;
}

// 후면버퍼에 그릴 내용
// 1프레임당 호출 횟수 : 1280 x 720 만큼 호출
float4 PS(PixelInput input) : SV_TARGET
{
	[branch]
	if (selected == 0)
		return Mosaic(input.uv);
	else if (selected == 1)
		return Bulr(input.uv);

	return Mosaic(input.uv);
}