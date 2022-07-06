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
	// floor ��źȭ : �Ҽ� ������ �Ҽ��� �� �� ����
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

// �ĸ���ۿ� �׸� ����
// 1�����Ӵ� ȣ�� Ƚ�� : 1280 x 720 ��ŭ ȣ��
float4 PS(PixelInput input) : SV_TARGET
{
	[branch]
	if (selected == 0)
		return Mosaic(input.uv);
	else if (selected == 1)
		return Bulr(input.uv);

	return Mosaic(input.uv);
}