
struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

// �ĸ���ۿ� �׸� ����
// 1�����Ӵ� ȣ�� Ƚ�� : 1280 x 720 ��ŭ ȣ��
float4 PS(PixelInput input) : SV_TARGET
{
	return float4(0.8f, 0.8f, 0.5f, 0.8f);
}