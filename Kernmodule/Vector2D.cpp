#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D()
{
    this->x = 0;
    this->y = 0;
}

Vector2D::Vector2D(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2D::~Vector2D()
{

}

Vector2D Vector2D::operator+(const float& f) const
{
    Vector2D result(*this);
    result.x += f;
    result.y += f;
    return result;
}

Vector2D Vector2D::operator-(const float& f) const
{
    Vector2D result(*this);
    result.x -= f;
    result.y -= f;
    return result;
}

Vector2D Vector2D::operator*(const float& f) const
{
    Vector2D result(*this);
    result.x *= f;
    result.y *= f;
    return result;
}

Vector2D Vector2D::operator/(const float& f) const
{
    Vector2D result(*this);
    result.x /= f;
    result.y /= f;
    return result;
}

Vector2D Vector2D::operator+(const Vector2D& vector) const
{
    Vector2D result(*this);
    result.x += vector.x;
    result.y += vector.y;
    return result;
}

Vector2D Vector2D::operator-(const Vector2D& vector) const
{
    Vector2D result(*this);
    result.x -= vector.x;
    result.y -= vector.y;
    return result;
}

Vector2D Vector2D::operator*(const Vector2D& vector) const
{
    Vector2D result(*this);
    result.x *= vector.x;
    result.y *= vector.y;
    return result;
}

Vector2D Vector2D::operator/(const Vector2D& vector) const
{
    Vector2D result(*this);
    result.x /= vector.x;
    result.y /= vector.y;
    return result;
}



Vector2D& Vector2D::operator+=(const float& f)
{
    x += f;
    y += f;
    return *this;
}

Vector2D& Vector2D::operator-=(const float& f)
{
    x -= f;
    y -= f;
    return *this;
}

Vector2D& Vector2D::operator*=(const float& f)
{
    x *= f;
    y *= f;
    return *this;
}

Vector2D& Vector2D::operator/=(const float& f)
{
    x /= f;
    y /= f;
    return *this;
}

Vector2D& Vector2D::operator+=(const Vector2D& vector)
{
    x += vector.x;
    y += vector.y;
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& vector)
{
    x -= vector.x;
    y -= vector.y;
    return *this;
}

Vector2D& Vector2D::operator*=(const Vector2D& vector)
{
    x *= vector.x;
    y *= vector.y;
    return *this;
}

Vector2D& Vector2D::operator/=(const Vector2D& vector)
{
    x /= vector.x;
    y /= vector.y;
    return *this;
}

Vector2D& Vector2D::operator=(const Vector2D& vector)
{
    x = vector.x;
    y = vector.y;
    return *this;
}

Vector2D& Vector2D::operator=(const float& f)
{
    x = f;
    y = f;
    return *this;
}

Vector2D Vector2D::Add(const float& f)
{
    return(*this + f);
}

Vector2D Vector2D::Subtract(const float& f)
{
    return(*this - f);
}

Vector2D Vector2D::Multiply(const float& f)
{
    return(*this * f);
}

Vector2D Vector2D::Divide(const float& f)
{
    return(*this / f);
}

Vector2D Vector2D::Sqrt()
{
    Vector2D result(*this);
    result.x = sqrtf(result.x);
    result.y = sqrtf(result.y);
    return result;
}

Vector2D Vector2D::Add(const Vector2D& vector)
{
    x += vector.x;
    y += vector.y;
    return *this;
}

Vector2D Vector2D::Subtract(const Vector2D& vector)
{
    x -= vector.x;
    y -= vector.y;
    return *this;
}

Vector2D Vector2D::Multiply(const Vector2D& vector)
{
    x *= vector.x;
    y *= vector.y;
    return *this;
}

Vector2D Vector2D::Divide(const Vector2D& vector)
{
    x /= vector.x;
    y /= vector.y;
    return *this;
}


std::ostream& operator<<(std::ostream& stream, const Vector2D& vector)
{
	stream << "(" << vector.x << ", " << vector.y << ")";
	return stream;
}
