#ifndef MATH_H
#define MATH_H

#include <math.h>
#include <Core/Common.h>

struct EVector3;
struct EVector2;

struct EVector4
{
    float x, y, z, w;
    EVector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }
    EVector4(float X, float Y, float Z, float W) : x(X), y(Y), z(Z), w(W) { }
	
	inline EVector4 &operator = (const EVector4 &right);
	inline EVector4 &operator = (const EVector3 &right);
	inline EVector4 &operator = (const EVector2 &right);
};

struct EVector3
{
    float x, y, z;
    EVector3() : x(0.0f), y(0.0f), z(0.0f) { }
    EVector3(float X, float Y, float Z) : x(X), y(Y), z(Z) { }
	
	inline EVector3 &operator = (const EVector4 &right);
	inline EVector3 &operator = (const EVector3 &right);
	inline EVector3 &operator = (const EVector2 &right);
};

struct EVector2
{
    float x, y;
    EVector2() : x(0.0f), y(0.0f) { }
    EVector2(float X, float Y) : x(X), y(Y) { }
	
	inline EVector2 &operator = (const EVector4 &right);
	inline EVector2 &operator = (const EVector3 &right);
	inline EVector2 &operator = (const EVector2 &right);
};

EVector4 &EVector4::operator =(const EVector4 &right)
{
	this->x = right.x;
	this->y = right.y;
	this->z = right.z;
	this->w = right.w;
	return *this;
}

EVector4 &EVector4::operator =(const EVector3 &right)
{
	this->x = right.x;
	this->y = right.y;
	this->z = right.z;
	return *this;
}

EVector4 &EVector4::operator =(const EVector2 &right)
{
	this->x = right.x;
	this->y = right.y;
	return *this;
}

EVector3 &EVector3::operator =(const EVector4 &right)
{
	this->x = right.x;
	this->y = right.y;
	this->z = right.z;
	return *this;
}

EVector3 &EVector3::operator =(const EVector3 &right)
{
	this->x = right.x;
	this->y = right.y;
	this->z = right.z;
	return *this;
}

EVector3 &EVector3::operator =(const EVector2 &right)
{
	this->x = right.x;
	this->y = right.y;
	return *this;
}

EVector2 &EVector2::operator =(const EVector4 &right)
{
	this->x = right.x;
	this->y = right.y;
	return *this;
}

EVector2 &EVector2::operator =(const EVector3 &right)
{
	this->x = right.x;
	this->y = right.y;
	return *this;
}

EVector2 &EVector2::operator =(const EVector2 &right)
{
	this->x = right.x;
	this->y = right.y;
	return *this;
}


inline bool operator == (const EVector4 &left, const EVector4 &right)
{
	return (left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w);
}
inline bool operator == (const EVector4 &left, const EVector3 &right)
{
	return (left.x == right.x && left.y == right.y && left.z == right.z);
}
inline bool operator == (const EVector4 &left, const EVector2 &right)
{
	return (left.x == right.x && left.y == right.y);
}
inline bool operator == (const EVector3 &left, const EVector4 &right)
{
	return (left.x == right.x && left.y == right.y && left.z == right.z);
}
inline bool operator == (const EVector3 &left, const EVector3 &right)
{
	return (left.x == right.x && left.y == right.y && left.z == right.z);
}
inline bool operator == (const EVector3 &left, const EVector2 &right)
{
	return (left.x == right.x && left.y == right.y);
}
inline bool operator == (const EVector2 &left, const EVector4 &right)
{
	return (left.x == right.x && left.y == right.y);
}
inline bool operator == (const EVector2 &left, const EVector3 &right)
{
	return (left.x == right.x && left.y == right.y);
}
inline bool operator == (const EVector2 &left, const EVector2 &right)
{
	return (left.x == right.x && left.y == right.y);
}

inline bool operator != (const EVector4 &left, const EVector4 &right)
{
	return !(left == right);
}
inline bool operator != (const EVector4 &left, const EVector3 &right)
{
	return !(left == right);
}
inline bool operator != (const EVector4 &left, const EVector2 &right)
{
	return !(left == right);
}
inline bool operator != (const EVector3 &left, const EVector4 &right)
{
	return !(left == right);
}
inline bool operator != (const EVector3 &left, const EVector3 &right)
{
	return !(left == right);
}
inline bool operator != (const EVector3 &left, const EVector2 &right)
{
	return !(left == right);
}
inline bool operator != (const EVector2 &left, const EVector4 &right)
{
	return !(left == right);
}
inline bool operator != (const EVector2 &left, const EVector3 &right)
{
	return !(left == right);
}
inline bool operator != (const EVector2 &left, const EVector2 &right)
{
	return !(left == right);
}


inline EVector4 operator * (const EVector4 &left, const EVector4 &right)
{
	return EVector4(left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w);
}
inline EVector4 operator * (const EVector4 &left, const EVector3 &right)
{
	return EVector4(left.x * right.x, left.y * right.y, left.z * right.z, left.w);
}
inline EVector4 operator * (const EVector4 &left, const EVector2 &right)
{
	return EVector4(left.x * right.x, left.y * right.y, left.z, left.w);
}
inline EVector4 operator * (const EVector4 &left, float right)
{
	return EVector4(left.x * right, left.y * right, left.z * right, left.w * right);
}
inline EVector3 operator * (const EVector3 &left, const EVector4 &right)
{
	return EVector3(left.x * right.x, left.y * right.y, left.z * right.z);
}
inline EVector3 operator * (const EVector3 &left, const EVector3 &right)
{
	return EVector3(left.x * right.x, left.y * right.y, left.z * right.z);
}
inline EVector3 operator * (const EVector3 &left, const EVector2 &right)
{
	return EVector3(left.x * right.x, left.y * right.y, left.z);
}
inline EVector3 operator * (const EVector3 &left, float right)
{
	return EVector3(left.x * right, left.y * right, left.z * right);
}
inline EVector2 operator * (const EVector2 &left, const EVector4 &right)
{
	return EVector2(left.x * right.x, left.y * right.y);
}
inline EVector2 operator * (const EVector2 &left, const EVector3 &right)
{
	return EVector2(left.x * right.x, left.y * right.y);
}
inline EVector2 operator * (const EVector2 &left, const EVector2 &right)
{
	return EVector2(left.x * right.x, left.y * right.y);
}
inline EVector2 operator * (const EVector2 &left, float right)
{
	return EVector2(left.x * right, left.y * right);
}

inline EVector4 operator / (const EVector4 &left, const EVector4 &right)
{
	return EVector4(left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.w);
}
inline EVector4 operator / (const EVector4 &left, const EVector3 &right)
{
	return EVector4(left.x / right.x, left.y / right.y, left.z / right.z, left.w);
}
inline EVector4 operator / (const EVector4 &left, const EVector2 &right)
{
	return EVector4(left.x / right.x, left.y / right.y, left.z, left.w);
}
inline EVector4 operator / (const EVector4 &left, float right)
{
	return EVector4(left.x / right, left.y / right, left.z / right, left.w / right);
}
inline EVector3 operator / (const EVector3 &left, const EVector4 &right)
{
	return EVector3(left.x / right.x, left.y / right.y, left.z / right.z);
}
inline EVector3 operator / (const EVector3 &left, const EVector3 &right)
{
	return EVector3(left.x / right.x, left.y / right.y, left.z / right.z);
}
inline EVector3 operator / (const EVector3 &left, const EVector2 &right)
{
	return EVector3(left.x / right.x, left.y / right.y, left.z);
}
inline EVector3 operator / (const EVector3 &left, float right)
{
	return EVector3(left.x / right, left.y / right, left.z / right);
}
inline EVector2 operator / (const EVector2 &left, const EVector4 &right)
{
	return EVector2(left.x / right.x, left.y / right.y);
}
inline EVector2 operator / (const EVector2 &left, const EVector3 &right)
{
	return EVector2(left.x / right.x, left.y / right.y);
}
inline EVector2 operator / (const EVector2 &left, const EVector2 &right)
{
	return EVector2(left.x / right.x, left.y / right.y);
}
inline EVector2 operator / (const EVector2 &left, float right)
{
	return EVector2(left.x / right, left.y / right);
}

inline EVector4 operator + (const EVector4 &left, const EVector4 &right)
{
	return EVector4(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
}
inline EVector4 operator + (const EVector4 &left, const EVector3 &right)
{
	return EVector4(left.x + right.x, left.y + right.y, left.z + right.z, left.w);
}
inline EVector4 operator + (const EVector4 &left, const EVector2 &right)
{
	return EVector4(left.x + right.x, left.y + right.y, left.z, left.w);
}
inline EVector4 operator + (const EVector4 &left, float right)
{
	return EVector4(left.x + right, left.y + right, left.z + right, left.w + right);
}
inline EVector3 operator + (const EVector3 &left, const EVector4 &right)
{
	return EVector3(left.x + right.x, left.y + right.y, left.z + right.z);
}
inline EVector3 operator + (const EVector3 &left, const EVector3 &right)
{
	return EVector3(left.x + right.x, left.y + right.y, left.z + right.z);
}
inline EVector3 operator + (const EVector3 &left, const EVector2 &right)
{
	return EVector3(left.x + right.x, left.y + right.y, left.z);
}
inline EVector3 operator + (const EVector3 &left, float right)
{
	return EVector3(left.x + right, left.y + right, left.z + right);
}
inline EVector2 operator + (const EVector2 &left, const EVector4 &right)
{
	return EVector2(left.x + right.x, left.y + right.y);
}
inline EVector2 operator + (const EVector2 &left, const EVector3 &right)
{
	return EVector2(left.x + right.x, left.y + right.y);
}
inline EVector2 operator + (const EVector2 &left, const EVector2 &right)
{
	return EVector2(left.x + right.x, left.y + right.y);
}
inline EVector2 operator + (const EVector2 &left, float right)
{
	return EVector2(left.x + right, left.y + right);
}

inline EVector4 operator - (const EVector4 &left, const EVector4 &right)
{
	return EVector4(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
}
inline EVector4 operator - (const EVector4 &left, const EVector3 &right)
{
	return EVector4(left.x - right.x, left.y - right.y, left.z - right.z, left.w);
}
inline EVector4 operator - (const EVector4 &left, const EVector2 &right)
{
	return EVector4(left.x - right.x, left.y - right.y, left.z, left.w);
}
inline EVector4 operator - (const EVector4 &left, float right)
{
	return EVector4(left.x - right, left.y - right, left.z - right, left.w - right);
}
inline EVector3 operator - (const EVector3 &left, const EVector4 &right)
{
	return EVector3(left.x - right.x, left.y - right.y, left.z - right.z);
}
inline EVector3 operator - (const EVector3 &left, const EVector3 &right)
{
	return EVector3(left.x - right.x, left.y - right.y, left.z - right.z);
}
inline EVector3 operator - (const EVector3 &left, const EVector2 &right)
{
	return EVector3(left.x - right.x, left.y - right.y, left.z);
}
inline EVector3 operator - (const EVector3 &left, float right)
{
	return EVector3(left.x - right, left.y - right, left.z - right);
}
inline EVector2 operator - (const EVector2 &left, const EVector4 &right)
{
	return EVector2(left.x - right.x, left.y - right.y);
}
inline EVector2 operator - (const EVector2 &left, const EVector3 &right)
{
	return EVector2(left.x - right.x, left.y - right.y);
}
inline EVector2 operator - (const EVector2 &left, const EVector2 &right)
{
	return EVector2(left.x - right.x, left.y - right.y);
}
inline EVector2 operator - (const EVector2 &left, float right)
{
	return EVector2(left.x - right, left.y - right);
}

inline EVector4 &operator *= (EVector4 &left, const EVector4 &right)
{
	left.x *= right.x;
	left.y *= right.y;
	left.z *= right.z;
	left.w *= right.w;
	return left;
}
inline EVector4 &operator *= (EVector4 &left, const EVector3 &right)
{
	left.x *= right.x;
	left.y *= right.y;
	left.z *= right.z;
	return left;
}
inline EVector4 &operator *= (EVector4 &left, const EVector2 &right)
{
	left.x *= right.x;
	left.y *= right.y;
	return left;
}
inline EVector4 &operator *= (EVector4 &left, float right)
{
	left.x *= right;
	left.y *= right;
	left.z *= right;
	left.w *= right;
	return left;
}
inline EVector3 &operator *= (EVector3 &left, const EVector4 &right)
{
	left.x *= right.x;
	left.y *= right.y;
	left.z *= right.z;
	return left;
}
inline EVector3 &operator *= (EVector3 &left, const EVector3 &right)
{
	left.x *= right.x;
	left.y *= right.y;
	left.z *= right.z;
	return left;
}
inline EVector3 &operator *= (EVector3 &left, const EVector2 &right)
{
	left.x *= right.x;
	left.y *= right.y;
	return left;
}
inline EVector3 &operator *= (EVector3 &left, float right)
{
	left.x *= right;
	left.y *= right;
	left.z *= right;
	return left;
}
inline EVector2 &operator *= (EVector2 &left, const EVector4 &right)
{
	left.x *= right.x;
	left.y *= right.y;
	return left;
}
inline EVector2 &operator *= (EVector2 &left, const EVector3 &right)
{
	left.x *= right.x;
	left.y *= right.y;
	return left;
}
inline EVector2 &operator *= (EVector2 &left, const EVector2 &right)
{
	left.x *= right.x;
	left.y *= right.y;
	return left;
}
inline EVector2 &operator *= (EVector2 &left, float right)
{
	left.x *= right;
	left.y *= right;
	return left;
}

inline EVector4 &operator /= (EVector4 &left, const EVector4 &right)
{
	left.x /= right.x;
	left.y /= right.y;
	left.z /= right.z;
	left.w /= right.w;
	return left;
}
inline EVector4 &operator /= (EVector4 &left, const EVector3 &right)
{
	left.x /= right.x;
	left.y /= right.y;
	left.z /= right.z;
	return left;
}
inline EVector4 &operator /= (EVector4 &left, const EVector2 &right)
{
	left.x /= right.x;
	left.y /= right.y;
	return left;
}
inline EVector4 &operator /= (EVector4 &left, float right)
{
	left.x /= right;
	left.y /= right;
	left.z /= right;
	left.w /= right;
	return left;
}
inline EVector3 &operator /= (EVector3 &left, const EVector4 &right)
{
	left.x /= right.x;
	left.y /= right.y;
	left.z /= right.z;
	return left;
}
inline EVector3 &operator /= (EVector3 &left, const EVector3 &right)
{
	left.x /= right.x;
	left.y /= right.y;
	left.z /= right.z;
	return left;
}
inline EVector3 &operator /= (EVector3 &left, const EVector2 &right)
{
	left.x /= right.x;
	left.y /= right.y;
	return left;
}
inline EVector3 &operator /= (EVector3 &left, float right)
{
	left.x /= right;
	left.y /= right;
	left.z /= right;
	return left;
}
inline EVector2 &operator /= (EVector2 &left, const EVector4 &right)
{
	left.x /= right.x;
	left.y /= right.y;
	return left;
}
inline EVector2 &operator /= (EVector2 &left, const EVector3 &right)
{
	left.x /= right.x;
	left.y /= right.y;
	return left;
}
inline EVector2 &operator /= (EVector2 &left, const EVector2 &right)
{
	left.x /= right.x;
	left.y /= right.y;
	return left;
}
inline EVector2 &operator /= (EVector2 &left, float right)
{
	left.x /= right;
	left.y /= right;
	return left;
}

inline EVector4 &operator -= (EVector4 &left, const EVector4 &right)
{
	left.x -= right.x;
	left.y -= right.y;
	left.z -= right.z;
	left.w -= right.w;
	return left;
}
inline EVector4 &operator -= (EVector4 &left, const EVector3 &right)
{
	left.x -= right.x;
	left.y -= right.y;
	left.z -= right.z;
	return left;
}
inline EVector4 &operator -= (EVector4 &left, const EVector2 &right)
{
	left.x -= right.x;
	left.y -= right.y;
	return left;
}
inline EVector4 &operator -= (EVector4 &left, float right)
{
	left.x -= right;
	left.y -= right;
	left.z -= right;
	left.w -= right;
	return left;
}
inline EVector3 &operator -= (EVector3 &left, const EVector4 &right)
{
	left.x -= right.x;
	left.y -= right.y;
	left.z -= right.z;
	return left;
}
inline EVector3 &operator -= (EVector3 &left, const EVector3 &right)
{
	left.x -= right.x;
	left.y -= right.y;
	left.z -= right.z;
	return left;
}
inline EVector3 &operator -= (EVector3 &left, const EVector2 &right)
{
	left.x -= right.x;
	left.y -= right.y;
	return left;
}
inline EVector3 &operator -= (EVector3 &left, float right)
{
	left.x -= right;
	left.y -= right;
	left.z -= right;
	return left;
}
inline EVector2 &operator -= (EVector2 &left, const EVector4 &right)
{
	left.x -= right.x;
	left.y -= right.y;
	return left;
}
inline EVector2 &operator -= (EVector2 &left, const EVector3 &right)
{
	left.x -= right.x;
	left.y -= right.y;
	return left;
}
inline EVector2 &operator -= (EVector2 &left, const EVector2 &right)
{
	left.x -= right.x;
	left.y -= right.y;
	return left;
}
inline EVector2 &operator -= (EVector2 &left, float right)
{
	left.x -= right;
	left.y -= right;
	return left;
}

inline EVector4 &operator += (EVector4 &left, const EVector4 &right)
{
	left.x += right.x;
	left.y += right.y;
	left.z += right.z;
	left.w += right.w;
	return left;
}
inline EVector4 &operator += (EVector4 &left, const EVector3 &right)
{
	left.x += right.x;
	left.y += right.y;
	left.z += right.z;
	return left;
}
inline EVector4 &operator += (EVector4 &left, const EVector2 &right)
{
	left.x += right.x;
	left.y += right.y;
	return left;
}
inline EVector4 &operator += (EVector4 &left, float right)
{
	left.x += right;
	left.y += right;
	left.z += right;
	left.w += right;
	return left;
}
inline EVector3 &operator += (EVector3 &left, const EVector4 &right)
{
	left.x += right.x;
	left.y += right.y;
	left.z += right.z;
	return left;
}
inline EVector3 &operator += (EVector3 &left, const EVector3 &right)
{
	left.x += right.x;
	left.y += right.y;
	left.z += right.z;
	return left;
}
inline EVector3 &operator += (EVector3 &left, const EVector2 &right)
{
	left.x += right.x;
	left.y += right.y;
	return left;
}
inline EVector3 &operator += (EVector3 &left, float right)
{
	left.x += right;
	left.y += right;
	left.z += right;
	return left;
}
inline EVector2 &operator += (EVector2 &left, const EVector4 &right)
{
	left.x += right.x;
	left.y += right.y;
	return left;
}
inline EVector2 &operator += (EVector2 &left, const EVector3 &right)
{
	left.x += right.x;
	left.y += right.y;
	return left;
}
inline EVector2 &operator += (EVector2 &left, const EVector2 &right)
{
	left.x += right.x;
	left.y += right.y;
	return left;
}
inline EVector2 &operator += (EVector2 &left, float right)
{
	left.x += right;
	left.y += right;
	return left;
}



inline float inverseSqrt(float value)
{
    return 1.0f / sqrtf(value);
}

inline float dot(const EVector4 &right, const EVector4 &left)
{
    return right.x * left.x + right.y * left.y + right.z * left.z + right.w * left.w;
}

inline float dot(const EVector3 &right, const EVector3 &left)
{
    return right.x * left.x + right.y * left.y + right.z * left.z;
}

inline float dot(const EVector2 &right, const EVector2 &left)
{
    return right.x * left.x + right.y * left.y;
}

inline EVector3 cross(const EVector3 &right, const EVector3 &left)
{
    return EVector3
    (
        right.y * left.z - left.y * right.z,
        right.z * left.x - left.z * right.x,
        right.x * left.y - left.x * right.y
    );
}

inline float length(const EVector4 &vec)
{
    float len = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w;
    return sqrtf(len);
}

inline float length(const EVector3 &vec)
{
    float len = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
    return sqrtf(len);
}

inline float length(const EVector2 &vec)
{
    float len = vec.x * vec.x + vec.y * vec.y;
    return sqrtf(len);
}

inline float distance(const EVector4 &right, const EVector4 &left)
{
    return length(right - left);
}

inline float distance(const EVector3 &right, const EVector3 &left)
{
    return length(right - left);
}

inline float distance(const EVector2 &right, const EVector2 &left)
{
    return length(right - left);
}

struct ERect
{
	Sint32 x, y, width, height;
	ERect() : x(0), y(0), width(0), height(0) { }
	ERect(Sint32 X, Sint32 Y, Sint32 Width, Sint32 Height) : x(X), y(Y), width(Width), height(Height) { }
	inline ERect &operator = (const ERect &right)
	{
		this->x = right.x;
		this->y = right.y;
		this->width = right.width;
		this->height = right.height;
		return *this;
	}
};

inline bool operator == (const ERect &left, const ERect &right)
{
	return (left.x == right.x && left.y == right.y && left.width == right.width && left.height == right.height);
}
inline bool operator != (const ERect &left, const ERect &right)
{
	return !(left == right);
}


/* ******* MATRICES ******* */

struct EMatrix4x4
{
    float m[4][4];
    
    EMatrix4x4()
    {
        m[0][0] = 0.0f; m[1][0] = 0.0f; m[2][0] = 0.0f; m[3][0] = 0.0f;
        m[0][1] = 0.0f; m[1][1] = 0.0f; m[2][1] = 0.0f; m[3][1] = 0.0f;
        m[0][2] = 0.0f; m[1][2] = 0.0f; m[2][2] = 0.0f; m[3][2] = 0.0f;
        m[0][3] = 0.0f; m[1][3] = 0.0f; m[2][3] = 0.0f; m[3][3] = 0.0f;
    }
    EMatrix4x4(
            float m00, float m10, float m20, float m30,
            float m01, float m11, float m21, float m31,
            float m02, float m12, float m22, float m32,
            float m03, float m13, float m23, float m33)
    {
        m[0][0] = m00; m[1][0] = m10; m[2][0] = m20; m[3][0] = m30;
        m[0][1] = m01; m[1][1] = m11; m[2][1] = m21; m[3][1] = m31;
        m[0][2] = m02; m[1][2] = m12; m[2][2] = m22; m[3][2] = m32;
        m[0][3] = m03; m[1][3] = m13; m[2][3] = m23; m[3][3] = m33;
    }
};

//glm::perspective()
//inline EMatrix4x4 perspective(float fovY, float aspect, float zNear, float zFar)
//{
//    return EMatrix4x4();
//}

struct EMatrix3x3
{
    
};

struct EMatrix2x2
{
    
};

#endif // MATH_H

