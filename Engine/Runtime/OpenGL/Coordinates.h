#ifndef COORDINATES_H
#define COORDINATES_H

#include <cmath>

#define EROS_INLINE inline
#define PI 3.1415926535897932384626433832795f

#define RETURN_NOTHING(type) return type()


EROS_INLINE float radians(float value)
{
    return value * (PI / 180.0f);
}
EROS_INLINE float degrees(float value)
{
    return value * (180 / PI);
}
EROS_INLINE float inversesqrt(float value)
{
    return 1.0f / sqrtf(value);
}


struct EVector4
{
    float x,y,z,w;
    EVector4() : x(0), y(0), z(0), w(0){}
    EVector4(const float &_x,
            const float &_y,
            const float &_z,
            const float &_w) :
        x(_x), y(_y), z(_z), w(_w){}
    float length()
    {
        return (float)sqrt(x * x * y * y * z * z * w * w);
    }
    EVector4 normalized()
    {
        float tempLength = length();
        return EVector4
        (
            this->x / tempLength,
            this->y / tempLength,
            this->z / tempLength,
            this->w / tempLength
        );
    }
};

struct EVector3
{
    float x,y,z;
    EVector3() : x(0), y(0), z(0) {}
    EVector3(const float &_x, 
            const float &_y, 
            const float &_z) :
        x(_x), y(_y), z(_z)
    {
    }
    float length()
    {
        return sqrtf(x * x * y * y * z * z);
    }
    EVector3 normalized()
    {
        float tempLength = length();
        return EVector3
        (
            this->x / tempLength,
            this->y / tempLength,
            this->z / tempLength
        );
    }
};

EROS_INLINE bool operator == (const EVector3 &right, const EVector3 &left)
{
    return (right.x == left.x && right.y == left.y && right.z == left.z);
}
EROS_INLINE bool operator != (const EVector3 &right, const EVector3 &left)
{
    return !(right == left);
}

struct EVector2
{
    float x,y;
    EVector2() : x(0), y(0){}
    EVector2(const float &_x, 
            const float &_y) :
        x(_x), y(_y)
    {
    }
    float length()
    {
        return (float)sqrt(x * x * y * y);
    }
    EVector2 normalized()
    {
        float tempLength = length();
        return EVector2
        (
            this->x / tempLength,
            this->y / tempLength
        );
    }
};

EROS_INLINE EVector4 normalize(const EVector4 &arg)
{
    float length = inversesqrt(arg.x * arg.x * arg.y * arg.y * arg.z * arg.z * arg.w * arg.w);
    return EVector4
    (
        arg.x / length,
        arg.y / length,
        arg.z / length,
        arg.w / length
    );
}
EROS_INLINE EVector3 normalize(const EVector3 &arg)
{
    float length = inversesqrt(arg.x * arg.x * arg.y * arg.y * arg.z * arg.z);
    return EVector3
    (
        arg.x / length,
        arg.y / length,
        arg.z / length
    );
}
EROS_INLINE EVector2 normalize(const EVector2 &arg)
{
    float length = inversesqrt(arg.x * arg.x * arg.y * arg.y);
    return EVector2
    (
        arg.x / length,
        arg.y / length
    );
}

EROS_INLINE float dot(EVector4 &x, EVector4 &y)
{
    return (x.x * y.x + x.y * y.y + x.z * y.z + x.w * y.w);
}
EROS_INLINE float dot(EVector3 &x, EVector3 &y)
{
    return (x.x * y.x + x.y * y.y + x.z * y.z);
}

EROS_INLINE float dot(EVector2 &x, EVector2 &y)
{
    return x.x * y.x + x.y * y.y;
}

EROS_INLINE EVector3 cross(EVector3 &left, EVector3 &right)
{
    return EVector3
    (
        left.y * right.z - left.z * right.y,
        left.z * right.x - left.x * right.z,
        left.x * right.y - left.y * right.x
    );
}

EROS_INLINE EVector4 operator * (EVector4 &left, EVector4 &right)
{
    return EVector4
    (
        left.x * right.x,
        left.y * right.y,
        left.z * right.z,
        left.w * right.w
    );
}
EROS_INLINE EVector4 operator * (EVector4 &left, EVector3 &right)
{
    return EVector4
    (
        left.x * right.x,
        left.y * right.y,
        left.z * right.z,
        left.w
    );
}
EROS_INLINE EVector4 operator * (EVector4 &left, EVector2 &right)
{
    return EVector4
    (
        left.x * right.x,
        left.y * right.y,
        left.z,
        left.w
    );
}
EROS_INLINE EVector4 operator * (EVector4 &left, float right)
{
    return EVector4
    (
        left.x * right,
        left.y * right,
        left.z * right,
        left.w * right
    );
}

EROS_INLINE EVector3 operator * (EVector3 &left, EVector4 &right)
{   
    return EVector3
    (
        left.x * right.x,
        left.y * right.y,
        left.z * right.z
    );
}
EROS_INLINE EVector3 operator * (EVector3 &left, EVector3 &right)
{
    return EVector3
    (
        left.x * right.x,
        left.y * right.y,
        left.z * right.z
    );
}
EROS_INLINE EVector3 operator * (EVector3 &left, EVector2 &right)
{
    return EVector3
    (
        left.x * right.x,
        left.y * right.y,
        left.z
    );
}
EROS_INLINE EVector3 operator * (EVector3 &left, float right)
{
    return EVector3
    (
        left.x * right,
        left.y * right,
        left.z * right
    );
}

EROS_INLINE EVector2 operator * (EVector2 &left, EVector4 &right)
{
    return EVector2(left.x * right.x, left.y * right.y);
}
EROS_INLINE EVector2 operator * (EVector2 &left, EVector3 &right)
{
    return EVector2(left.x * right.x, left.y * right.y);
}
EROS_INLINE EVector2 operator * (EVector2 &left, EVector2 &right)
{
    return EVector2(left.x * right.x, left.y * right.y);
}
EROS_INLINE EVector2 operator * (EVector2 &left, float &right)
{
    return EVector2(left.x * right, left.y * right);
}

EROS_INLINE EVector4 &operator *= (EVector4 &left, EVector4 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    left.z *= right.z;
    left.w *= right.w;
    return left;
}
EROS_INLINE EVector4 &operator *= (EVector4 &left, EVector3 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    left.z *= right.z;
    return left;
}
EROS_INLINE EVector4 &operator *= (EVector4 &left, EVector2 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    return left;
}
EROS_INLINE EVector4 &operator *= (EVector4 &left, float right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    left.w *= right;
    return left;
}

EROS_INLINE EVector3 &operator *= (EVector3 &left, EVector4 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    left.z *= right.z;
    return left;
}
EROS_INLINE EVector3 &operator *= (EVector3 &left, EVector3 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    left.z *= right.z;
    return left;
}
EROS_INLINE EVector3 &operator *= (EVector3 &left, EVector2 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    return left;
}
EROS_INLINE EVector3 &operator *= (EVector3 &left, float right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    return left;
}

EROS_INLINE EVector2 &operator *= (EVector2 &left, EVector4 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    return left;
}
EROS_INLINE EVector2 &operator *= (EVector2 &left, EVector3 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    return left;
}
EROS_INLINE EVector2 &operator *= (EVector2 &left, EVector2 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    return left;
}
EROS_INLINE EVector2 &operator *= (EVector2 &left, float right)
{
    left.x *= right;
    left.y *= right;
    return left;
}

EROS_INLINE EVector4 operator / (EVector4 &left, EVector4 &right)
{
    return EVector4
    (
        left.x / right.x,
        left.y / right.y,
        left.z / right.z,
        left.w / right.w
    );
}
EROS_INLINE EVector4 operator / (EVector4 &left, EVector3 &right)
{
    return EVector4
    (
        left.x / right.x,
        left.y / right.y,
        left.z / right.z,
        left.w
    );
}
EROS_INLINE EVector4 operator / (EVector4 &left, EVector2 &right)
{
    return EVector4
    (
        left.x / right.x,
        left.y / right.y,
        left.z,
        left.w
    );
}
EROS_INLINE EVector4 operator / (EVector4 &left, float right)
{
    return EVector4
    (
        left.x / right,
        left.y / right,
        left.z / right,
        left.w / right
    );
}

EROS_INLINE EVector3 operator / (EVector3 &left, EVector4 &right)
{   
    return EVector3
    (
        left.x / right.x,
        left.y / right.y,
        left.z / right.z
    );
}
EROS_INLINE EVector3 operator / (EVector3 &left, EVector3 &right)
{
    return EVector3
    (
        left.x / right.x,
        left.y / right.y,
        left.z / right.z
    );
}
EROS_INLINE EVector3 operator / (EVector3 &left, EVector2 &right)
{
    return EVector3
    (
        left.x / right.x,
        left.y / right.y,
        left.z
    );
}
EROS_INLINE EVector3 operator / (EVector3 &left, float right)
{
    return EVector3
    (
        left.x / right,
        left.y / right,
        left.z / right
    );
}

EROS_INLINE EVector2 operator / (EVector2 &left, EVector4 &right)
{
    return EVector2(left.x / right.x, left.y / right.y);
}
EROS_INLINE EVector2 operator / (EVector2 &left, EVector3 &right)
{
    return EVector2(left.x / right.x, left.y / right.y);
}
EROS_INLINE EVector2 operator / (EVector2 &left, EVector2 &right)
{
    return EVector2(left.x / right.x, left.y / right.y);
}
EROS_INLINE EVector2 operator / (EVector2 &left, float &right)
{
    return EVector2(left.x / right, left.y / right);
}

EROS_INLINE EVector4 &operator /= (EVector4 &left, EVector4 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    left.z /= right.z;
    left.w /= right.w;
    return left;
}
EROS_INLINE EVector4 &operator /= (EVector4 &left, EVector3 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    left.z /= right.z;
    return left;
}
EROS_INLINE EVector4 &operator /= (EVector4 &left, EVector2 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    return left;
}
EROS_INLINE EVector4 &operator /= (EVector4 &left, float right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;
    left.w /= right;
    return left;
}

EROS_INLINE EVector3 &operator /= (EVector3 &left, EVector4 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    left.z /= right.z;
    return left;
}
EROS_INLINE EVector3 &operator /= (EVector3 &left, EVector3 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    left.z /= right.z;
    return left;
}
EROS_INLINE EVector3 &operator /= (EVector3 &left, EVector2 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    return left;
}
EROS_INLINE EVector3 &operator /= (EVector3 &left, float right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;
    return left;
}

EROS_INLINE EVector2 &operator /= (EVector2 &left, EVector4 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    return left;
}
EROS_INLINE EVector2 &operator /= (EVector2 &left, EVector3 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    return left;
}
EROS_INLINE EVector2 &operator /= (EVector2 &left, EVector2 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    return left;
}
EROS_INLINE EVector2 &operator /= (EVector2 &left, float right)
{
    left.x /= right;
    left.y /= right;
    return left;
}

EROS_INLINE EVector4 operator + (EVector4 &left, EVector4 &right)
{
    return EVector4
    (
        left.x + right.x,
        left.y + right.y,
        left.z + right.z,
        left.w + right.w
    );
}
EROS_INLINE EVector4 operator + (EVector4 &left, EVector3 &right)
{
    return EVector4
    (
        left.x + right.x,
        left.y + right.y,
        left.z + right.z,
        left.w
    );
}
EROS_INLINE EVector4 operator + (EVector4 &left, EVector2 &right)
{
    return EVector4
    (
        left.x + right.x,
        left.y + right.y,
        left.z,
        left.w
    );
}
EROS_INLINE EVector4 operator + (EVector4 &left, float right)
{
    return EVector4
    (
        left.x + right,
        left.y + right,
        left.z + right,
        left.w + right
    );
}

EROS_INLINE EVector3 operator + (EVector3 &left, EVector4 &right)
{   
    return EVector3
    (
        left.x + right.x,
        left.y + right.y,
        left.z + right.z
    );
}
EROS_INLINE EVector3 operator + (EVector3 &left, EVector3 &right)
{
    return EVector3
    (
        left.x + right.x,
        left.y + right.y,
        left.z + right.z
    );
}
EROS_INLINE EVector3 operator + (EVector3 &left, EVector2 &right)
{
    return EVector3
    (
        left.x + right.x,
        left.y + right.y,
        left.z
    );
}
EROS_INLINE EVector3 operator + (EVector3 &left, float right)
{
    return EVector3
    (
        left.x + right,
        left.y + right,
        left.z + right
    );
}

EROS_INLINE EVector2 operator + (EVector2 &left, EVector4 &right)
{
    return EVector2(left.x + right.x, left.y + right.y);
}
EROS_INLINE EVector2 operator + (EVector2 &left, EVector3 &right)
{
    return EVector2(left.x + right.x, left.y + right.y);
}
EROS_INLINE EVector2 operator + (EVector2 &left, EVector2 &right)
{
    return EVector2(left.x + right.x, left.y + right.y);
}
EROS_INLINE EVector2 operator + (EVector2 &left, float &right)
{
    return EVector2(left.x + right, left.y + right);
}

EROS_INLINE EVector4 &operator += (EVector4 &left, EVector4 &right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    left.w += right.w;
    return left;
}
EROS_INLINE EVector4 &operator += (EVector4 &left, EVector3 &right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}
EROS_INLINE EVector4 &operator += (EVector4 &left, EVector2 &right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}
EROS_INLINE EVector4 &operator += (EVector4 &left, float right)
{
    left.x += right;
    left.y += right;
    left.z += right;
    left.w += right;
    return left;
}

EROS_INLINE EVector3 &operator += (EVector3 &left, EVector4 &right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}
EROS_INLINE EVector3 &operator += (EVector3 &left, EVector3 &right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}
EROS_INLINE EVector3 &operator += (EVector3 &left, EVector2 &right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}
EROS_INLINE EVector3 &operator += (EVector3 &left, float right)
{
    left.x += right;
    left.y += right;
    left.z += right;
    return left;
}

EROS_INLINE EVector2 &operator += (EVector2 &left, EVector4 &right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}
EROS_INLINE EVector2 &operator += (EVector2 &left, EVector3 &right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}
EROS_INLINE EVector2 &operator += (EVector2 &left, EVector2 &right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}
EROS_INLINE EVector2 &operator += (EVector2 &left, float right)
{
    left.x += right;
    left.y += right;
    return left;
}

EROS_INLINE EVector4 operator - (EVector4 &left, EVector4 &right)
{
    return EVector4
    (
        left.x - right.x,
        left.y - right.y,
        left.z - right.z,
        left.w - right.w
    );
}
EROS_INLINE EVector4 operator - (EVector4 &left, EVector3 &right)
{
    return EVector4
    (
        left.x - right.x,
        left.y - right.y,
        left.z - right.z,
        left.w
    );
}
EROS_INLINE EVector4 operator - (EVector4 &left, EVector2 &right)
{
    return EVector4
    (
        left.x - right.x,
        left.y - right.y,
        left.z,
        left.w
    );
}
EROS_INLINE EVector4 operator - (EVector4 &left, float right)
{
    return EVector4
    (
        left.x - right,
        left.y - right,
        left.z - right,
        left.w - right
    );
}

EROS_INLINE EVector3 operator - (EVector3 &left, EVector4 &right)
{   
    return EVector3
    (
        left.x - right.x,
        left.y - right.y,
        left.z - right.z
    );
}
EROS_INLINE EVector3 operator - (EVector3 &left, EVector3 &right)
{
    return EVector3
    (
        left.x - right.x,
        left.y - right.y,
        left.z - right.z
    );
}
EROS_INLINE EVector3 operator - (EVector3 &left, EVector2 &right)
{
    return EVector3
    (
        left.x - right.x,
        left.y - right.y,
        left.z
    );
}
EROS_INLINE EVector3 operator - (EVector3 &left, float right)
{
    return EVector3
    (
        left.x - right,
        left.y - right,
        left.z - right
    );
}

EROS_INLINE EVector2 operator - (EVector2 &left, EVector4 &right)
{
    return EVector2(left.x - right.x, left.y - right.y);
}
EROS_INLINE EVector2 operator - (EVector2 &left, EVector3 &right)
{
    return EVector2(left.x - right.x, left.y - right.y);
}
EROS_INLINE EVector2 operator - (EVector2 &left, EVector2 &right)
{
    return EVector2(left.x - right.x, left.y - right.y);
}
EROS_INLINE EVector2 operator - (EVector2 &left, float &right)
{
    return EVector2(left.x - right, left.y - right);
}

EROS_INLINE EVector4 &operator -= (EVector4 &left, EVector4 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    left.w -= right.w;
    return left;
}
EROS_INLINE EVector4 &operator -= (EVector4 &left, EVector3 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}
EROS_INLINE EVector4 &operator -= (EVector4 &left, EVector2 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}
EROS_INLINE EVector4 &operator -= (EVector4 &left, float right)
{
    left.x -= right;
    left.y -= right;
    left.z -= right;
    left.w -= right;
    return left;
}

EROS_INLINE EVector3 &operator -= (EVector3 &left, EVector4 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}
EROS_INLINE EVector3 &operator -= (EVector3 &left, EVector3 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}
EROS_INLINE EVector3 &operator -= (EVector3 &left, EVector2 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}
EROS_INLINE EVector3 &operator -= (EVector3 &left, float right)
{
    left.x -= right;
    left.y -= right;
    left.z -= right;
    return left;
}

EROS_INLINE EVector2 &operator -= (EVector2 &left, EVector4 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}
EROS_INLINE EVector2 &operator -= (EVector2 &left, EVector3 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}
EROS_INLINE EVector2 &operator -= (EVector2 &left, EVector2 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}
EROS_INLINE EVector2 &operator -= (EVector2 &left, float right)
{
    left.x -= right;
    left.y -= right;
    return left;
}

EROS_INLINE bool operator == (EVector4 &left, EVector4 &right)
{
    return (left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w);
}
EROS_INLINE bool operator != (EVector4 &left, EVector4 &right)
{
    return !(right == left);
}
EROS_INLINE bool operator == (EVector4 &left, EVector3 &right)
{
    return (left.x == right.x && left.y == right.y && left.z == right.z);
}
EROS_INLINE bool operator != (EVector4 &left, EVector3 &right)
{
    return !(left == right);
}
EROS_INLINE bool operator == (EVector4 &left, EVector2 &right)
{
    return (left.x == right.x && left.y == right.y);
}
EROS_INLINE bool operator != (EVector4 &left, EVector2 &right)
{
    return !(left == right);
}

EROS_INLINE bool operator == (EVector3 &left, EVector4 &right)
{
    return (left.x == right.x && left.y == right.y && left.z == right.z);
}
EROS_INLINE bool operator != (EVector3 &left, EVector4 &right)
{
    return !(left == right);
}
EROS_INLINE bool operator == (EVector3 &left, EVector3 &right)
{
    return (left.x == right.x && left.y == right.y && left.z == right.z);
}
EROS_INLINE bool operator != (EVector3 &left, EVector3 &right)
{
    return !(left == right);
}
EROS_INLINE bool operator == (EVector3 &left, EVector2 &right)
{
    return (left.x == right.x && left.y == right.y);
}
EROS_INLINE bool operator != (EVector3 &left, EVector2 &right)
{
    return !(left == right);
}

EROS_INLINE bool operator == (EVector2 &left, EVector4 &right)
{
    return (left.x == right.x && left.y == right.y);
}
EROS_INLINE bool operator != (EVector2 &left, EVector4 &right)
{
    return !(left == right);
}
EROS_INLINE bool operator == (EVector2 &left, EVector3 &right)
{
    return (left.x == right.x && left.y == right.y);
}
EROS_INLINE bool operator != (EVector2 &left, EVector3 &right)
{
    return !(left == right);
}
EROS_INLINE bool operator == (EVector2 &left, EVector2 &right)
{
    return (left.x == right.x && left.y == right.y);
}
EROS_INLINE bool operator != (EVector2 &left, EVector2 &right)
{
    return !(left == right);
}


// -------- MATRICES ---------- //


struct Column4
{
private:
    
    float m[4];
    
public:
    
    EROS_INLINE float &operator[](int pos)
    {
        return m[pos];
    }
    
    EROS_INLINE const float &operator [](int pos) const 
    {
        return m[pos];
    }
    
};

struct Column3
{
private:
    
    float m[3];
    
public:
    
    EROS_INLINE float &operator[](int pos)
    {
        return m[pos];
    }
    
    EROS_INLINE const float &operator[](int pos) const
    {
        return m[pos];
    }
};

struct Column2
{
private:
    
    float m[2];
    
public:
    
    EROS_INLINE float &operator[](int pos)
    {
        return m[pos];
    }
    
    EROS_INLINE const float &operator[](int pos) const
    {
        return m[pos];
    }
};

struct EMatrix4x4
{
private:
    
    Column4 mat[4];
    
public:
    
    explicit EROS_INLINE EMatrix4x4(
    float m11 = 0.0f, float m21 = 0.0f, float m31 = 0.0f, float m41 = 0.0f,
    float m12 = 0.0f, float m22 = 0.0f, float m32 = 0.0f, float m42 = 0.0f,
    float m13 = 0.0f, float m23 = 0.0f, float m33 = 0.0f, float m43 = 0.0f,
    float m14 = 0.0f, float m24 = 0.0f, float m34 = 0.0f, float m44 = 0.0f)
    {
        mat[0][0] = m11; mat[1][0] = m21; mat[2][0] = m31; mat[3][0] = m41;
        mat[0][1] = m12; mat[1][1] = m22; mat[2][1] = m32; mat[3][1] = m42;
        mat[0][2] = m13; mat[1][2] = m23; mat[2][2] = m33; mat[3][2] = m43;
        mat[0][3] = m14; mat[1][3] = m24; mat[2][3] = m34; mat[3][3] = m44;        
    }
    
    EROS_INLINE EMatrix4x4(const EVector4 &column1, const EVector4 &column2, 
                           const EVector4 &column3, const EVector4 &column4)
    {
        mat[0][0] = column1.x; mat[1][0] = column2.x; mat[2][0] = column3.x; mat[3][0] = column4.x;
        mat[0][1] = column1.y; mat[1][1] = column2.y; mat[2][1] = column3.y; mat[3][1] = column4.y;
        mat[0][2] = column1.z; mat[1][2] = column2.z; mat[2][2] = column3.z; mat[3][2] = column4.z;
        mat[0][3] = column1.w; mat[1][3] = column2.w; mat[2][3] = column3.w; mat[3][3] = column4.w;        
    }
    
    EROS_INLINE EMatrix4x4 &operator = (const EMatrix4x4 &right)
    {
       mat[0][0] = right[0][0];
       mat[0][0] = right[0][0];
       mat[0][0] = right[0][0];
       mat[0][0] = right[0][0];
       mat[0][0] = right[0][0];
       mat[0][0] = right[0][0];
       mat[0][0] = right[0][0];
       mat[0][0] = right[0][0];
       return *this;
    }
    
    EROS_INLINE Column4 &operator[] (int pos)
    {
        return mat[pos];
    }
    
    EROS_INLINE const Column4 &operator[] (int pos) const
    {
        return mat[pos];
    }
    
};

EROS_INLINE EVector4 operator * (EVector4 &left, EMatrix4x4 &right)
{
    RETURN_NOTHING(EVector4);
}

EROS_INLINE EMatrix4x4 operator * (EMatrix4x4 &left, EMatrix4x4 &right)
{
    RETURN_NOTHING(EMatrix4x4);
}

EROS_INLINE EVector4 operator *= (EVector4 &left, EMatrix4x4 &right)
{
    RETURN_NOTHING(EVector4);
}

EROS_INLINE EMatrix4x4 operator *= (EMatrix4x4 &left, EMatrix4x4 &right)
{
    RETURN_NOTHING(EMatrix4x4);
}

EROS_INLINE EMatrix4x4 Rotate(float angle)
{
    RETURN_NOTHING(EMatrix4x4);
}

EROS_INLINE EMatrix4x4 Translate(float offsetX = 0.0f, float offsetY = 0.0f, float offsetZ = 0.0f)
{
    RETURN_NOTHING(EMatrix4x4);
}

EROS_INLINE EMatrix4x4 Translate(EVector3 &offset)
{
    return Translate(offset.x, offset.y, offset.z);
}

EROS_INLINE EMatrix4x4 Scale(float scaleX, float scaleY, float scaleZ)
{
    return EMatrix4x4();
}

EROS_INLINE EMatrix4x4 Perspective(float fovy, float aspect, float zNear, float zFar)
{
    return EMatrix4x4();
}

EROS_INLINE EMatrix4x4 LookAt(EVector3 eye, EVector3 center, EVector3 up)
{
    return EMatrix4x4();
}



#endif // COORDINATES_H
