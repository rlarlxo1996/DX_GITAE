#include "framework.h"
#include "Vector2.h"

Vector2::Vector2()
: _x(0.0f)
, _y(0.0f)
{
}

Vector2::Vector2(float x, float y)
: _x(x)
, _y(y)
{
}

Vector2::Vector2(int x, int y)
: _x((float)x)
, _y((float)y)
{
}

Vector2::~Vector2()
{
}

Vector2 Vector2::operator+(const Vector2& value) const
{
    return Vector2(_x + value._x, _y+value._y);
}

Vector2 Vector2::operator-(const Vector2& value) const
{
    return Vector2(_x - value._x, _y - value._y);
}

Vector2 Vector2::operator*(const float& value) const
{
    return Vector2(_x * value, _y * value);
}

Vector2& Vector2::operator+=(const Vector2& value)
{
    _x += value._x;
    _y += value._y;

    return *this;
}

bool Vector2::operator==(const Vector2& value) const
{
    if (_x == value._x && _y == value._y)
        return true;

    return false;
}

bool Vector2::operator!=(const Vector2& value) const
{
    return !(*this == value);
}

bool Vector2::operator<(const Vector2& value) const
{
    if (_y != value._y)
        return _y < value._y;

    return _x < value._x;
}

Vector2& Vector2::operator=(const Vector2& value)
{
    _x = value._x;
    _y = value._y;

    return *this;
}

void Vector2::Normalize()
{
    float length = Length();
    _x = _x / length;
    _y = _y / length;
}

float Vector2::Distance(const Vector2& value) const
{
    float x = value._x - _x;
    float y = value._y - _y;
    return sqrtf(x * x + y * y);
}

float Vector2::Length() const
{
    return sqrtf(_x * _x + _y * _y);
}

float Vector2::Dot(const Vector2& value)
{
    return _x* value._x + _y*value._y;
}

float Vector2::Cross(const Vector2& value)
{
    return _x * value._y - _y*value._x;
}

bool Vector2::IsBetween(const Vector2& value1, const Vector2& value2)
{
    Vector2 temp1 = value1;
    Vector2 temp2 = value2;

    Vector2 line1ToEnd = temp1 - *this;
    Vector2 line1ToStart = temp2 - *this;

    float between = line1ToEnd.Cross(*this) * line1ToStart.Cross(*this);

    return between < 0.0f;
}

int Vector2::Manhattan(const Vector2 value) const
{
    return (value._x - _x) + (value._y - _y);
}

float Vector2::Angle(const Vector2& value)
{
    float dot = this->Dot(value);
    float aDis = abs(this->Length());
    float bDis = abs(value.Length());

    float cos = dot / (aDis * bDis);

    return acos(cos);
}
