#ifndef COORDINATES_H
#define COORDINATES_H

#include <cmath>

#define EROS_INLINE inline
#define PI 3.1415926535897932384626433832795f



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

/*
struct Vector4
{
    float x,y,z,w;
    Vector4() : x(0), y(0), z(0), w(0){}
    Vector4(const float &_x,
            const float &_y,
            const float &_z,
            const float &_w) :
        x(_x), y(_y), z(_z), w(_w){}
    float length()
    {
        return (float)sqrt(x * x * y * y * z * z * w * w);
    }
    Vector4 normalized()
    {
        float tempLength = length();
        return Vector4
        (
            this->x / tempLength,
            this->y / tempLength,
            this->z / tempLength,
            this->w / tempLength
        );
    }
};

struct Vector3
{
    float x,y,z;
    Vector3() : x(0), y(0), z(0) {}
    Vector3(const float &_x, 
            const float &_y, 
            const float &_z) :
        x(_x), y(_y), z(_z)
    {
    }
    float length()
    {
        return sqrtf(x * x * y * y * z * z);
    }
    Vector3 normalized()
    {
        float tempLength = length();
        return Vector3
        (
            this->x / tempLength,
            this->y / tempLength,
            this->z / tempLength
        );
    }
};

EROS_INLINE bool operator == (const Vector3 &right, const Vector3 &left)
{
    return (right.x == left.x && right.y == left.y && right.z == left.z);
}
EROS_INLINE bool operator != (const Vector3 &right, const Vector3 &left)
{
    return !(right == left);
}

struct Vector2
{
    float x,y;
    Vector2() : x(0), y(0){}
    Vector2(const float &_x, 
            const float &_y) :
        x(_x), y(_y)
    {
    }
    float length()
    {
        return (float)sqrt(x * x * y * y);
    }
    Vector2 normalized()
    {
        float tempLength = length();
        return Vector2
        (
            this->x / tempLength,
            this->y / tempLength
        );
    }
};

EROS_INLINE Vector4 normalize(const Vector4 &arg)
{
    float length = inversesqrt(arg.x * arg.x * arg.y * arg.y * arg.z * arg.z * arg.w * arg.w);
    return Vector4
    (
        arg.x / length,
        arg.y / length,
        arg.z / length,
        arg.w / length
    );
}
EROS_INLINE Vector3 normalize(const Vector3 &arg)
{
    float length = inversesqrt(arg.x * arg.x * arg.y * arg.y * arg.z * arg.z);
    return Vector3
    (
        arg.x / length,
        arg.y / length,
        arg.z / length
    );
}
EROS_INLINE Vector2 normalize(const Vector2 &arg)
{
    float length = inversesqrt(arg.x * arg.x * arg.y * arg.y);
    return Vector2
    (
        arg.x / length,
        arg.y / length
    );
}

EROS_INLINE float dot(Vector4 &x, Vector4 &y)
{
    return (x.x * y.x + x.y * y.y + x.z * y.z + x.w * y.w);
}
EROS_INLINE float dot(Vector3 &x, Vector3 &y)
{
    return (x.x * y.x + x.y * y.y + x.z * y.z);
}

EROS_INLINE float dot(Vector2 &x, Vector2 &y)
{
    return x.x * y.x + x.y * y.y;
}

EROS_INLINE Vector3 cross(Vector3 &left, Vector3 &right)
{
    return Vector3
    (
        left.y * right.z - left.z * right.y,
        left.z * right.x - left.x * right.z,
        left.x * right.y - left.y * right.x
    );
}

EROS_INLINE Vector4 operator * (Vector4 &left, Vector4 &right)
{
    return Vector4
    (
        left.x * right.x,
        left.y * right.y,
        left.z * right.z,
        left.w * right.w
    );
}
EROS_INLINE Vector4 operator * (Vector4 &left, Vector3 &right)
{
    return Vector4
    (
        left.x * right.x,
        left.y * right.y,
        left.z * right.z,
        left.w
    );
}
EROS_INLINE Vector4 operator * (Vector4 &left, Vector2 &right)
{
    return Vector4
    (
        left.x * right.x,
        left.y * right.y,
        left.z,
        left.w
    );
}
EROS_INLINE Vector4 operator * (Vector4 &left, float right)
{
    return Vector4
    (
        left.x * right,
        left.y * right,
        left.z * right,
        left.w * right
    );
}

EROS_INLINE Vector3 operator * (Vector3 &left, Vector4 &right)
{   
    return Vector3
    (
        left.x * right.x,
        left.y * right.y,
        left.z * right.z
    );
}
EROS_INLINE Vector3 operator * (Vector3 &left, Vector3 &right)
{
    return Vector3
    (
        left.x * right.x,
        left.y * right.y,
        left.z * right.z
    );
}
EROS_INLINE Vector3 operator * (Vector3 &left, Vector2 &right)
{
    return Vector3
    (
        left.x * right.x,
        left.y * right.y,
        left.z
    );
}
EROS_INLINE Vector3 operator * (Vector3 &left, float right)
{
    return Vector3
    (
        left.x * right,
        left.y * right,
        left.z * right
    );
}

EROS_INLINE Vector2 operator * (Vector2 &left, Vector4 &right)
{
    return Vector2(left.x * right.x, left.y * right.y);
}
EROS_INLINE Vector2 operator * (Vector2 &left, Vector3 &right)
{
    return Vector2(left.x * right.x, left.y * right.y);
}
EROS_INLINE Vector2 operator * (Vector2 &left, Vector2 &right)
{
    return Vector2(left.x * right.x, left.y * right.y);
}
EROS_INLINE Vector2 operator * (Vector2 &left, float &right)
{
    return Vector2(left.x * right, left.y * right);
}

EROS_INLINE Vector4 &operator *= (Vector4 &left, Vector4 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    left.z *= right.z;
    left.w *= right.w;
    return left;
}
EROS_INLINE Vector4 &operator *= (Vector4 &left, Vector3 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    left.z *= right.z;
    return left;
}
EROS_INLINE Vector4 &operator *= (Vector4 &left, Vector2 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    return left;
}
EROS_INLINE Vector4 &operator *= (Vector4 &left, float right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    left.w *= right;
    return left;
}

EROS_INLINE Vector3 &operator *= (Vector3 &left, Vector4 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    left.z *= right.z;
    return left;
}
EROS_INLINE Vector3 &operator *= (Vector3 &left, Vector3 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    left.z *= right.z;
    return left;
}
EROS_INLINE Vector3 &operator *= (Vector3 &left, Vector2 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    return left;
}
EROS_INLINE Vector3 &operator *= (Vector3 &left, float right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    return left;
}

EROS_INLINE Vector2 &operator *= (Vector2 &left, Vector4 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    return left;
}
EROS_INLINE Vector2 &operator *= (Vector2 &left, Vector3 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    return left;
}
EROS_INLINE Vector2 &operator *= (Vector2 &left, Vector2 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    return left;
}
EROS_INLINE Vector2 &operator *= (Vector2 &left, float right)
{
    left.x *= right;
    left.y *= right;
    return left;
}

EROS_INLINE Vector4 operator / (Vector4 &left, Vector4 &right)
{
    return Vector4
    (
        left.x / right.x,
        left.y / right.y,
        left.z / right.z,
        left.w / right.w
    );
}
EROS_INLINE Vector4 operator / (Vector4 &left, Vector3 &right)
{
    return Vector4
    (
        left.x / right.x,
        left.y / right.y,
        left.z / right.z,
        left.w
    );
}
EROS_INLINE Vector4 operator / (Vector4 &left, Vector2 &right)
{
    return Vector4
    (
        left.x / right.x,
        left.y / right.y,
        left.z,
        left.w
    );
}
EROS_INLINE Vector4 operator / (Vector4 &left, float right)
{
    return Vector4
    (
        left.x / right,
        left.y / right,
        left.z / right,
        left.w / right
    );
}

EROS_INLINE Vector3 operator / (Vector3 &left, Vector4 &right)
{   
    return Vector3
    (
        left.x / right.x,
        left.y / right.y,
        left.z / right.z
    );
}
EROS_INLINE Vector3 operator / (Vector3 &left, Vector3 &right)
{
    return Vector3
    (
        left.x / right.x,
        left.y / right.y,
        left.z / right.z
    );
}
EROS_INLINE Vector3 operator / (Vector3 &left, Vector2 &right)
{
    return Vector3
    (
        left.x / right.x,
        left.y / right.y,
        left.z
    );
}
EROS_INLINE Vector3 operator / (Vector3 &left, float right)
{
    return Vector3
    (
        left.x / right,
        left.y / right,
        left.z / right
    );
}

EROS_INLINE Vector2 operator / (Vector2 &left, Vector4 &right)
{
    return Vector2(left.x / right.x, left.y / right.y);
}
EROS_INLINE Vector2 operator / (Vector2 &left, Vector3 &right)
{
    return Vector2(left.x / right.x, left.y / right.y);
}
EROS_INLINE Vector2 operator / (Vector2 &left, Vector2 &right)
{
    return Vector2(left.x / right.x, left.y / right.y);
}
EROS_INLINE Vector2 operator / (Vector2 &left, float &right)
{
    return Vector2(left.x / right, left.y / right);
}

EROS_INLINE Vector4 &operator /= (Vector4 &left, Vector4 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    left.z /= right.z;
    left.w /= right.w;
    return left;
}
EROS_INLINE Vector4 &operator /= (Vector4 &left, Vector3 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    left.z /= right.z;
    return left;
}
EROS_INLINE Vector4 &operator /= (Vector4 &left, Vector2 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    return left;
}
EROS_INLINE Vector4 &operator /= (Vector4 &left, float right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;
    left.w /= right;
    return left;
}

EROS_INLINE Vector3 &operator /= (Vector3 &left, Vector4 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    left.z /= right.z;
    return left;
}
EROS_INLINE Vector3 &operator /= (Vector3 &left, Vector3 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    left.z /= right.z;
    return left;
}
EROS_INLINE Vector3 &operator /= (Vector3 &left, Vector2 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    return left;
}
EROS_INLINE Vector3 &operator /= (Vector3 &left, float right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;
    return left;
}

EROS_INLINE Vector2 &operator /= (Vector2 &left, Vector4 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    return left;
}
EROS_INLINE Vector2 &operator /= (Vector2 &left, Vector3 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    return left;
}
EROS_INLINE Vector2 &operator /= (Vector2 &left, Vector2 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    return left;
}
EROS_INLINE Vector2 &operator /= (Vector2 &left, float right)
{
    left.x /= right;
    left.y /= right;
    return left;
}

EROS_INLINE Vector4 operator + (Vector4 &left, Vector4 &right)
{
    return Vector4
    (
        left.x + right.x,
        left.y + right.y,
        left.z + right.z,
        left.w + right.w
    );
}
EROS_INLINE Vector4 operator + (Vector4 &left, Vector3 &right)
{
    return Vector4
    (
        left.x + right.x,
        left.y + right.y,
        left.z + right.z,
        left.w
    );
}
EROS_INLINE Vector4 operator + (Vector4 &left, Vector2 &right)
{
    return Vector4
    (
        left.x + right.x,
        left.y + right.y,
        left.z,
        left.w
    );
}
EROS_INLINE Vector4 operator + (Vector4 &left, float right)
{
    return Vector4
    (
        left.x + right,
        left.y + right,
        left.z + right,
        left.w + right
    );
}

EROS_INLINE Vector3 operator + (Vector3 &left, Vector4 &right)
{   
    return Vector3
    (
        left.x + right.x,
        left.y + right.y,
        left.z + right.z
    );
}
EROS_INLINE Vector3 operator + (Vector3 &left, Vector3 &right)
{
    return Vector3
    (
        left.x + right.x,
        left.y + right.y,
        left.z + right.z
    );
}
EROS_INLINE Vector3 operator + (Vector3 &left, Vector2 &right)
{
    return Vector3
    (
        left.x + right.x,
        left.y + right.y,
        left.z
    );
}
EROS_INLINE Vector3 operator + (Vector3 &left, float right)
{
    return Vector3
    (
        left.x + right,
        left.y + right,
        left.z + right
    );
}

EROS_INLINE Vector2 operator + (Vector2 &left, Vector4 &right)
{
    return Vector2(left.x + right.x, left.y + right.y);
}
EROS_INLINE Vector2 operator + (Vector2 &left, Vector3 &right)
{
    return Vector2(left.x + right.x, left.y + right.y);
}
EROS_INLINE Vector2 operator + (Vector2 &left, Vector2 &right)
{
    return Vector2(left.x + right.x, left.y + right.y);
}
EROS_INLINE Vector2 operator + (Vector2 &left, float &right)
{
    return Vector2(left.x + right, left.y + right);
}

EROS_INLINE Vector4 &operator += (Vector4 &left, Vector4 &right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    left.w += right.w;
    return left;
}
EROS_INLINE Vector4 &operator += (Vector4 &left, Vector3 &right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}
EROS_INLINE Vector4 &operator += (Vector4 &left, Vector2 &right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}
EROS_INLINE Vector4 &operator += (Vector4 &left, float right)
{
    left.x += right;
    left.y += right;
    left.z += right;
    left.w += right;
    return left;
}

EROS_INLINE Vector3 &operator += (Vector3 &left, Vector4 &right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}
EROS_INLINE Vector3 &operator += (Vector3 &left, Vector3 &right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}
EROS_INLINE Vector3 &operator += (Vector3 &left, Vector2 &right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}
EROS_INLINE Vector3 &operator += (Vector3 &left, float right)
{
    left.x += right;
    left.y += right;
    left.z += right;
    return left;
}

EROS_INLINE Vector2 &operator += (Vector2 &left, Vector4 &right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}
EROS_INLINE Vector2 &operator += (Vector2 &left, Vector3 &right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}
EROS_INLINE Vector2 &operator += (Vector2 &left, Vector2 &right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}
EROS_INLINE Vector2 &operator += (Vector2 &left, float right)
{
    left.x += right;
    left.y += right;
    return left;
}

EROS_INLINE Vector4 operator - (Vector4 &left, Vector4 &right)
{
    return Vector4
    (
        left.x - right.x,
        left.y - right.y,
        left.z - right.z,
        left.w - right.w
    );
}
EROS_INLINE Vector4 operator - (Vector4 &left, Vector3 &right)
{
    return Vector4
    (
        left.x - right.x,
        left.y - right.y,
        left.z - right.z,
        left.w
    );
}
EROS_INLINE Vector4 operator - (Vector4 &left, Vector2 &right)
{
    return Vector4
    (
        left.x - right.x,
        left.y - right.y,
        left.z,
        left.w
    );
}
EROS_INLINE Vector4 operator - (Vector4 &left, float right)
{
    return Vector4
    (
        left.x - right,
        left.y - right,
        left.z - right,
        left.w - right
    );
}

EROS_INLINE Vector3 operator - (Vector3 &left, Vector4 &right)
{   
    return Vector3
    (
        left.x - right.x,
        left.y - right.y,
        left.z - right.z
    );
}
EROS_INLINE Vector3 operator - (Vector3 &left, Vector3 &right)
{
    return Vector3
    (
        left.x - right.x,
        left.y - right.y,
        left.z - right.z
    );
}
EROS_INLINE Vector3 operator - (Vector3 &left, Vector2 &right)
{
    return Vector3
    (
        left.x - right.x,
        left.y - right.y,
        left.z
    );
}
EROS_INLINE Vector3 operator - (Vector3 &left, float right)
{
    return Vector3
    (
        left.x - right,
        left.y - right,
        left.z - right
    );
}

EROS_INLINE Vector2 operator - (Vector2 &left, Vector4 &right)
{
    return Vector2(left.x - right.x, left.y - right.y);
}
EROS_INLINE Vector2 operator - (Vector2 &left, Vector3 &right)
{
    return Vector2(left.x - right.x, left.y - right.y);
}
EROS_INLINE Vector2 operator - (Vector2 &left, Vector2 &right)
{
    return Vector2(left.x - right.x, left.y - right.y);
}
EROS_INLINE Vector2 operator - (Vector2 &left, float &right)
{
    return Vector2(left.x - right, left.y - right);
}

EROS_INLINE Vector4 &operator -= (Vector4 &left, Vector4 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    left.w -= right.w;
    return left;
}
EROS_INLINE Vector4 &operator -= (Vector4 &left, Vector3 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}
EROS_INLINE Vector4 &operator -= (Vector4 &left, Vector2 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}
EROS_INLINE Vector4 &operator -= (Vector4 &left, float right)
{
    left.x -= right;
    left.y -= right;
    left.z -= right;
    left.w -= right;
    return left;
}

EROS_INLINE Vector3 &operator -= (Vector3 &left, Vector4 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}
EROS_INLINE Vector3 &operator -= (Vector3 &left, Vector3 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}
EROS_INLINE Vector3 &operator -= (Vector3 &left, Vector2 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}
EROS_INLINE Vector3 &operator -= (Vector3 &left, float right)
{
    left.x -= right;
    left.y -= right;
    left.z -= right;
    return left;
}

EROS_INLINE Vector2 &operator -= (Vector2 &left, Vector4 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}
EROS_INLINE Vector2 &operator -= (Vector2 &left, Vector3 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}
EROS_INLINE Vector2 &operator -= (Vector2 &left, Vector2 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}
EROS_INLINE Vector2 &operator -= (Vector2 &left, float right)
{
    left.x -= right;
    left.y -= right;
    return left;
}

EROS_INLINE bool operator == (Vector4 &left, Vector4 &right)
{
    return (left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w);
}
EROS_INLINE bool operator != (Vector4 &left, Vector4 &right)
{
    return !(right == left);
}
EROS_INLINE bool operator == (Vector4 &left, Vector3 &right)
{
    return (left.x == right.x && left.y == right.y && left.z == right.z);
}
EROS_INLINE bool operator != (Vector4 &left, Vector3 &right)
{
    return !(left == right);
}
EROS_INLINE bool operator == (Vector4 &left, Vector2 &right)
{
    return (left.x == right.x && left.y == right.y);
}
EROS_INLINE bool operator != (Vector4 &left, Vector2 &right)
{
    return !(left == right);
}

EROS_INLINE bool operator == (Vector3 &left, Vector4 &right)
{
    return (left.x == right.x && left.y == right.y && left.z == right.z);
}
EROS_INLINE bool operator != (Vector3 &left, Vector4 &right)
{
    return !(left == right);
}
EROS_INLINE bool operator == (Vector3 &left, Vector3 &right)
{
    return (left.x == right.x && left.y == right.y && left.z == right.z);
}
EROS_INLINE bool operator != (Vector3 &left, Vector3 &right)
{
    return !(left == right);
}
EROS_INLINE bool operator == (Vector3 &left, Vector2 &right)
{
    return (left.x == right.x && left.y == right.y);
}
EROS_INLINE bool operator != (Vector3 &left, Vector2 &right)
{
    return !(left == right);
}

EROS_INLINE bool operator == (Vector2 &left, Vector4 &right)
{
    return (left.x == right.x && left.y == right.y);
}
EROS_INLINE bool operator != (Vector2 &left, Vector4 &right)
{
    return !(left == right);
}
EROS_INLINE bool operator == (Vector2 &left, Vector3 &right)
{
    return (left.x == right.x && left.y == right.y);
}
EROS_INLINE bool operator != (Vector2 &left, Vector3 &right)
{
    return !(left == right);
}
EROS_INLINE bool operator == (Vector2 &left, Vector2 &right)
{
    return (left.x == right.x && left.y == right.y);
}
EROS_INLINE bool operator != (Vector2 &left, Vector2 &right)
{
    return !(left == right);
}

*/
// -------- MATRICES ---------- //

enum RotDir
{
    XAxis,
    YAxis,
    ZAxis
};

struct Matrix4x4
{
    float matrix[4][4];
    
    EROS_INLINE float *getValuePtr()
    {
        return &matrix[0][0];
    }
    
    explicit EROS_INLINE Matrix4x4(
    float m11 = 0.0f, float m12 = 0.0f, float m13 = 0.0f, float m14 = 0.0f,
    float m21 = 0.0f, float m22 = 0.0f, float m23 = 0.0f, float m24 = 0.0f,
    float m31 = 0.0f, float m32 = 0.0f, float m33 = 0.0f, float m34 = 0.0f,
    float m41 = 0.0f, float m42 = 0.0f, float m43 = 0.0f, float m44 = 0.0f)
    {
        matrix[0][0] = m11; matrix[0][1] = m12; matrix[0][2] = m13; matrix[0][3] = m14;
        matrix[1][0] = m21; matrix[1][1] = m22; matrix[1][2] = m23; matrix[1][3] = m24;
        matrix[2][0] = m31; matrix[2][1] = m32; matrix[2][2] = m33; matrix[2][3] = m34; 
        matrix[3][0] = m41; matrix[3][1] = m42; matrix[3][2] = m43; matrix[3][3] = m44;
    }
    /*
    EROS_INLINE Matrix4x4(Vector4 &row1, Vector4 &row2, Vector4 &row3, Vector4 &row4)
    {
        matrix[0][0] = row1.x; matrix[0][1] = row1.y; matrix[0][2] = row1.z; matrix[0][3] = row1.w;
        matrix[1][0] = row2.x; matrix[1][1] = row2.y; matrix[1][2] = row2.z; matrix[1][3] = row2.w;
        matrix[2][0] = row3.x; matrix[2][1] = row3.y; matrix[2][2] = row3.z; matrix[2][3] = row3.w; 
        matrix[3][0] = row4.x; matrix[3][1] = row4.y; matrix[3][2] = row4.z; matrix[3][3] = row4.w;
    }
    */
    EROS_INLINE Matrix4x4 &operator = (const Matrix4x4 &right)
    {
        this->matrix[0][0] = right.matrix[0][0];
        this->matrix[0][1] = right.matrix[0][1];
        this->matrix[0][2] = right.matrix[0][2];
        this->matrix[0][3] = right.matrix[0][3];
        this->matrix[1][0] = right.matrix[1][0];
        this->matrix[1][1] = right.matrix[1][1];
        this->matrix[1][2] = right.matrix[1][2];
        this->matrix[1][3] = right.matrix[1][3];
        this->matrix[2][0] = right.matrix[2][0];
        this->matrix[2][1] = right.matrix[2][1];
        this->matrix[2][2] = right.matrix[2][2];
        this->matrix[2][3] = right.matrix[2][3];
        this->matrix[3][0] = right.matrix[3][0];
        this->matrix[3][1] = right.matrix[3][1];
        this->matrix[3][2] = right.matrix[3][2];
        this->matrix[3][3] = right.matrix[3][3];
        return *this;
    }

    EROS_INLINE void setIdentity()
    {
        matrix[0][0] = 1.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f; matrix[0][3] = 0.0f;
        matrix[1][0] = 0.0f; matrix[1][1] = 1.0f; matrix[1][2] = 0.0f; matrix[1][3] = 0.0f;
        matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 1.0f; matrix[2][3] = 0.0f;
        matrix[3][0] = 0.0f; matrix[3][1] = 0.0f; matrix[3][2] = 0.0f; matrix[3][3] = 1.0f;
    }
    
};
/*
EROS_INLINE Vector4 operator * (Vector4 &left, Matrix4x4 &right)
{
    return Vector4
    (
        ((right.matrix[0][0] * left.x) + (right.matrix[0][1] * left.y) + (right.matrix[0][2] * left.z) + (right.matrix[0][3] * left.w)),
        ((right.matrix[1][0] * left.x) + (right.matrix[1][1] * left.y) + (right.matrix[1][2] * left.z) + (right.matrix[1][3] * left.w)),
        ((right.matrix[2][0] * left.x) + (right.matrix[2][1] * left.y) + (right.matrix[2][2] * left.z) + (right.matrix[2][3] * left.w)),
        ((right.matrix[3][0] * left.x) + (right.matrix[3][1] * left.y) + (right.matrix[3][2] * left.z) + (right.matrix[3][3] * left.w))
    );
}
*/
EROS_INLINE Matrix4x4 operator * (Matrix4x4 &left, Matrix4x4 &right)
{
    return Matrix4x4(
    ((left.matrix[0][0] * right.matrix[0][0]) + (left.matrix[0][1] * right.matrix[1][0]) + (left.matrix[0][2] * right.matrix[2][0]) + (left.matrix[0][3] * right.matrix[3][0])),
    ((left.matrix[0][0] * right.matrix[0][1]) + (left.matrix[0][1] * right.matrix[1][1]) + (left.matrix[0][2] * right.matrix[2][1]) + (left.matrix[0][3] * right.matrix[3][1])),
    ((left.matrix[0][0] * right.matrix[0][2]) + (left.matrix[0][1] * right.matrix[1][2]) + (left.matrix[0][2] * right.matrix[2][2]) + (left.matrix[0][3] * right.matrix[3][2])),
    ((left.matrix[0][0] * right.matrix[0][3]) + (left.matrix[0][1] * right.matrix[1][3]) + (left.matrix[0][2] * right.matrix[2][3]) + (left.matrix[0][3] * right.matrix[3][3])),
    ((left.matrix[1][0] * right.matrix[1][0]) + (left.matrix[1][1] * right.matrix[1][0]) + (left.matrix[1][2] * right.matrix[2][0]) + (left.matrix[1][3] * right.matrix[3][0])),
    ((left.matrix[1][0] * right.matrix[1][1]) + (left.matrix[1][1] * right.matrix[1][1]) + (left.matrix[1][2] * right.matrix[2][1]) + (left.matrix[1][3] * right.matrix[3][1])),
    ((left.matrix[1][0] * right.matrix[1][2]) + (left.matrix[1][1] * right.matrix[1][2]) + (left.matrix[1][2] * right.matrix[2][2]) + (left.matrix[1][3] * right.matrix[3][2])),
    ((left.matrix[1][0] * right.matrix[1][3]) + (left.matrix[1][1] * right.matrix[1][3]) + (left.matrix[1][2] * right.matrix[2][3]) + (left.matrix[1][3] * right.matrix[3][3])),
    ((left.matrix[2][0] * right.matrix[2][0]) + (left.matrix[2][1] * right.matrix[1][0]) + (left.matrix[2][2] * right.matrix[2][0]) + (left.matrix[2][3] * right.matrix[3][0])),
    ((left.matrix[2][0] * right.matrix[2][1]) + (left.matrix[2][1] * right.matrix[1][1]) + (left.matrix[2][2] * right.matrix[2][1]) + (left.matrix[2][3] * right.matrix[3][1])),
    ((left.matrix[2][0] * right.matrix[2][2]) + (left.matrix[2][1] * right.matrix[1][2]) + (left.matrix[2][2] * right.matrix[2][2]) + (left.matrix[2][3] * right.matrix[3][2])),
    ((left.matrix[2][0] * right.matrix[2][3]) + (left.matrix[2][1] * right.matrix[1][3]) + (left.matrix[2][2] * right.matrix[2][3]) + (left.matrix[2][3] * right.matrix[3][3])),
    ((left.matrix[3][0] * right.matrix[3][0]) + (left.matrix[3][1] * right.matrix[1][0]) + (left.matrix[3][2] * right.matrix[2][0]) + (left.matrix[3][3] * right.matrix[3][0])),
    ((left.matrix[3][0] * right.matrix[3][1]) + (left.matrix[3][1] * right.matrix[1][1]) + (left.matrix[3][2] * right.matrix[2][1]) + (left.matrix[3][3] * right.matrix[3][1])),
    ((left.matrix[3][0] * right.matrix[3][2]) + (left.matrix[3][1] * right.matrix[1][2]) + (left.matrix[3][2] * right.matrix[2][2]) + (left.matrix[3][3] * right.matrix[3][2])),
    ((left.matrix[3][0] * right.matrix[3][3]) + (left.matrix[3][1] * right.matrix[1][3]) + (left.matrix[3][2] * right.matrix[2][3]) + (left.matrix[3][3] * right.matrix[3][3])));
}
/*
EROS_INLINE Vector4 &operator *= (Vector4 &left, Matrix4x4 &right)
{
    left.x = ((right.matrix[0][0] * left.x) + (right.matrix[0][1] * left.y) + (right.matrix[0][2] * left.z) + (right.matrix[0][3] * left.w));
    left.y = ((right.matrix[1][0] * left.x) + (right.matrix[1][1] * left.y) + (right.matrix[1][2] * left.z) + (right.matrix[1][3] * left.w));
    left.z = ((right.matrix[2][0] * left.x) + (right.matrix[2][1] * left.y) + (right.matrix[2][2] * left.z) + (right.matrix[2][3] * left.w));
    left.w = ((right.matrix[3][0] * left.x) + (right.matrix[3][1] * left.y) + (right.matrix[3][2] * left.z) + (right.matrix[3][3] * left.w));
    return left;
}
*/
EROS_INLINE Matrix4x4 &operator *= (Matrix4x4 &left, Matrix4x4 &right)
{
    left.matrix[0][0] = ((left.matrix[0][0] * right.matrix[0][0]) + (left.matrix[0][1] * right.matrix[1][0]) + (left.matrix[0][2] * right.matrix[2][0]) + (left.matrix[0][3] * right.matrix[3][0]));
    left.matrix[0][1] = ((left.matrix[0][0] * right.matrix[0][1]) + (left.matrix[0][1] * right.matrix[1][1]) + (left.matrix[0][2] * right.matrix[2][1]) + (left.matrix[0][3] * right.matrix[3][1]));
    left.matrix[0][2] = ((left.matrix[0][0] * right.matrix[0][2]) + (left.matrix[0][1] * right.matrix[1][2]) + (left.matrix[0][2] * right.matrix[2][2]) + (left.matrix[0][3] * right.matrix[3][2]));
    left.matrix[0][3] = ((left.matrix[0][0] * right.matrix[0][3]) + (left.matrix[0][1] * right.matrix[1][3]) + (left.matrix[0][2] * right.matrix[2][3]) + (left.matrix[0][3] * right.matrix[3][3]));
    left.matrix[1][0] = ((left.matrix[1][0] * right.matrix[1][0]) + (left.matrix[1][1] * right.matrix[1][0]) + (left.matrix[1][2] * right.matrix[2][0]) + (left.matrix[1][3] * right.matrix[3][0]));
    left.matrix[1][1] = ((left.matrix[1][0] * right.matrix[1][1]) + (left.matrix[1][1] * right.matrix[1][1]) + (left.matrix[1][2] * right.matrix[2][1]) + (left.matrix[1][3] * right.matrix[3][1]));
    left.matrix[1][2] = ((left.matrix[1][0] * right.matrix[1][2]) + (left.matrix[1][1] * right.matrix[1][2]) + (left.matrix[1][2] * right.matrix[2][2]) + (left.matrix[1][3] * right.matrix[3][2]));
    left.matrix[1][3] = ((left.matrix[1][0] * right.matrix[1][3]) + (left.matrix[1][1] * right.matrix[1][3]) + (left.matrix[1][2] * right.matrix[2][3]) + (left.matrix[1][3] * right.matrix[3][3]));
    left.matrix[2][0] = ((left.matrix[2][0] * right.matrix[2][0]) + (left.matrix[2][1] * right.matrix[1][0]) + (left.matrix[2][2] * right.matrix[2][0]) + (left.matrix[2][3] * right.matrix[3][0]));
    left.matrix[2][1] = ((left.matrix[2][0] * right.matrix[2][1]) + (left.matrix[2][1] * right.matrix[1][1]) + (left.matrix[2][2] * right.matrix[2][1]) + (left.matrix[2][3] * right.matrix[3][1]));
    left.matrix[2][2] = ((left.matrix[2][0] * right.matrix[2][2]) + (left.matrix[2][1] * right.matrix[1][2]) + (left.matrix[2][2] * right.matrix[2][2]) + (left.matrix[2][3] * right.matrix[3][2]));
    left.matrix[2][3] = ((left.matrix[2][0] * right.matrix[2][3]) + (left.matrix[2][1] * right.matrix[1][3]) + (left.matrix[2][2] * right.matrix[2][3]) + (left.matrix[2][3] * right.matrix[3][3]));
    left.matrix[3][0] = ((left.matrix[3][0] * right.matrix[3][0]) + (left.matrix[3][1] * right.matrix[1][0]) + (left.matrix[3][2] * right.matrix[2][0]) + (left.matrix[3][3] * right.matrix[3][0]));
    left.matrix[3][1] = ((left.matrix[3][0] * right.matrix[3][1]) + (left.matrix[3][1] * right.matrix[1][1]) + (left.matrix[3][2] * right.matrix[2][1]) + (left.matrix[3][3] * right.matrix[3][1]));
    left.matrix[3][2] = ((left.matrix[3][0] * right.matrix[3][2]) + (left.matrix[3][1] * right.matrix[1][2]) + (left.matrix[3][2] * right.matrix[2][2]) + (left.matrix[3][3] * right.matrix[3][2]));
    left.matrix[3][3] = ((left.matrix[3][0] * right.matrix[3][3]) + (left.matrix[3][1] * right.matrix[1][3]) + (left.matrix[3][2] * right.matrix[2][3]) + (left.matrix[3][3] * right.matrix[3][3]));
    return left;
}

EROS_INLINE Matrix4x4 Rotate(float angle, RotDir dir)
{
    Matrix4x4 m;
    m.setIdentity();
    switch (dir)
    {
        case (RotDir::XAxis):
        {
            m.matrix[1][1] = cosf(angle);
            m.matrix[1][2] = sinf(angle) * -1.0f;
            m.matrix[2][1] = sinf(angle);
            m.matrix[2][2] = cosf(angle);
        }
        break;
        case (RotDir::YAxis):
        {
            m.matrix[0][0] = cosf(angle);
            m.matrix[0][3] = sinf(angle);
            m.matrix[2][0] = sinf(angle) * -1.0f;
            m.matrix[2][2] = cosf(angle);
        }
        break;
        case (RotDir::ZAxis):
        {
            m.matrix[0][0] = cosf(angle);
            m.matrix[0][1] = sinf(angle) * -1.0f;
            m.matrix[1][0] = sinf(angle);
            m.matrix[1][1] = cosf(angle);
        }
        break;
    }
    
    return m;
}

EROS_INLINE Matrix4x4 Translate(float offsetX = 0.0f, float offsetY = 0.0f, float offsetZ = 0.0f)
{
    Matrix4x4 m;
    m.setIdentity();
    m.matrix[0][3] = offsetX;
    m.matrix[1][3] = offsetY;
    m.matrix[2][3] = offsetZ;
    return m;
}
/*
EROS_INLINE Matrix4x4 Translate(Vector3 &offset)
{
    return Translate(offset.x, offset.y, offset.z);
}
*/
EROS_INLINE Matrix4x4 Scale(float scaleX, float scaleY, float scaleZ)
{
    Matrix4x4 m;
    m.matrix[0][0] = scaleX; 
    m.matrix[1][1] = scaleY;
    m.matrix[2][2] = scaleZ;
    m.matrix[3][3] = 0.0f;
    return m;
}

EROS_INLINE Matrix4x4 Perspective(float fovy, float aspect, float zNear, float zFar)
{
    float range = tanf(radians(fovy / (2.0f))) * zNear;	
    float left = -range * aspect;
    float right = range * aspect;
    float bottom = -range;
    float top = range;
    
    Matrix4x4 m;
    m.matrix[0][0] = ((2.0f) * zNear) / (right - left);
    m.matrix[1][1] = ((2.0f) * zNear) / (top - bottom);
    m.matrix[2][2] = - (zFar + zNear) / (zFar - zNear);
    m.matrix[3][2] = - (1.0f);
    m.matrix[2][3] = - ((2.0f) * zFar * zNear) / (zFar - zNear);
    m.matrix[3][3] = 1.0f;
    return m;
}
/*
EROS_INLINE Matrix4x4 LookAt(Vector3 eye, Vector3 center, Vector3 up)
{
    Matrix4x4 m;
    Vector3 f = normalize(center - eye);
    Vector3 u = normalize(up);
    Vector3 s = normalize(cross(f, u));
    u = cross(s, f);
    
    m.matrix[0][0] = s.x;
    m.matrix[1][0] = s.y;
    m.matrix[2][0] = s.z;
    m.matrix[0][1] = u.x;
    m.matrix[1][1] = u.y;
    m.matrix[2][1] = u.z;
    m.matrix[0][2] =-f.x;
    m.matrix[1][2] =-f.y;
    m.matrix[2][2] =-f.z;
    m.matrix[3][0] =-dot(s, eye);
    m.matrix[3][1] =-dot(u, eye);
    m.matrix[3][2] = dot(f, eye);
    
    return m;
}
*/


#endif // COORDINATES_H
