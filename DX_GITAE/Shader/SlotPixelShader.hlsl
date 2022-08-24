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

// �ĸ���ۿ� �׸� ����
// 1�����Ӵ� ȣ�� Ƚ�� : 1280 x 720 ��ŭ ȣ��
float4 PS(PixelInput input) : SV_TARGET
{
	if(bgOrSlot == 0)
		return float4(0.4f, 0.4f, 0.4f, 0.7f);

	return float4(0.8f, 0.8f, 0.8f, 0.8f);
}