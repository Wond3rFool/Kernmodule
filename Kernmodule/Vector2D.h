#pragma once
#include <iostream>

class Vector2D
{
public:
    Vector2D();
    Vector2D(float x, float y);
    ~Vector2D();

    //variables
    float x, y;

    //operators
    Vector2D operator+(const float& f) const;                     
    Vector2D operator-(const float& f) const;                     
    Vector2D operator*(const float& f) const;
    Vector2D operator/(const float& f) const;
    Vector2D operator+(const Vector2D& vector) const;
    Vector2D operator-(const Vector2D& vector) const;
    Vector2D operator*(const Vector2D& vector) const;             
    Vector2D operator/(const Vector2D& vector) const;             
    Vector2D& operator+=(const float& f);                         
    Vector2D& operator-=(const float& f);                         
    Vector2D& operator*=(const float& f);
    Vector2D& operator/=(const float& f);
    Vector2D& operator+=(const Vector2D& vector);
    Vector2D& operator-=(const Vector2D& vector);
    Vector2D& operator*=(const Vector2D& vector);                 
    Vector2D& operator/=(const Vector2D& vector);                 
    Vector2D& operator=(const Vector2D& vector);                 
    Vector2D& operator=(const float& f);                         

    //Basic Math Operators
    //Float Calculations
    Vector2D Add(const float& f);                                     
    Vector2D Subtract(const float& f);                                 
    Vector2D Multiply(const float& f);
    Vector2D Divide(const float& f);
    Vector2D Sqrt();

    //Vector2D Calculations
    Vector2D Add(const Vector2D& vector);
    Vector2D Subtract(const Vector2D& vector);
    Vector2D Multiply(const Vector2D& vector);                        
    Vector2D Divide(const Vector2D& vector);                         
    

	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vector);
};

