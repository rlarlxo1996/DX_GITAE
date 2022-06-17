#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	Vector2(int x, int y);
	~Vector2();

	Vector2 operator+(const Vector2& value);
	Vector2 operator-(const Vector2& value);
	Vector2 operator*(const float& value);

	Vector2& operator+=(const Vector2& value);

	bool operator==(const Vector2& value);
	bool operator!=(const Vector2& value);
	bool operator<(const Vector2& value) const;

	Vector2& operator=(const Vector2& value);

	void Normalize();

	float Distance(const Vector2& value);
	float Length();

	// ³»Àû
	float Dot(const Vector2& value);
	float Cross(const Vector2& value);

	bool IsBetween(const Vector2& value1, const Vector2& value2);
	int Manhattan(const Vector2 value) const;

public:
	float _x;
	float _y;
};

