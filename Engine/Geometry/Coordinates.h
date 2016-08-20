#ifndef COORDINATES_H
#define COORDINATES_H

#include <SDL_opengl.h>
#include <cmath>
#include <QVector3D>

struct Vector4
{
    GLfloat x,y,z,w;
    Vector4() : x(0), y(0), z(0), w(0){}
    Vector4(const GLfloat &_x,
            const GLfloat &_y,
            const GLfloat &_z,
            const GLfloat &_w) :
        x(_x), y(_y), z(_z), w(_w){}
    GLfloat length()
    {
        GLfloat _x = x;
        GLfloat _y = y;
        GLfloat _z = z;
        GLfloat _w = w;
        return (GLfloat)sqrt(_x * _x * _y * _y * _z * _z * _w * _w);
    }
    Vector4 normalized()
    {
        GLfloat tempLength = length();
        return Vector4
        (
            this->x / tempLength,
            this->y / tempLength,
            this->z / tempLength,
            this->w / tempLength
        );
    }
    void operator *= (Vector4 &right)
    {
        this->x *= right.x;
        this->y *= right.y;
        this->z *= right.z;
        this->w *= right.w;        
    }
};
inline bool operator == (const Vector4 &right, const Vector4 &left)
{
    return (right.x == left.x && right.y == left.y && right.z == left.z && right.w == left.w);
}
inline bool operator != (const Vector4 &right, const Vector4 &left)
{
    return !(right == left);
}
inline Vector4 operator * (Vector4 &left, Vector4 &right)
{
    return Vector4
    (
        right.x * left.x,
        right.y * left.y,
        right.z * left.z,
        right.w * left.w
    );
}
inline void operator *= (Vector4 &left, Vector4 &right)
{
    left = right * left;
}

struct Vector3
{
    GLfloat x,y,z;
    Vector3() : x(0), y(0), z(0) {}
    Vector3(const GLfloat &_x, 
            const GLfloat &_y, 
            const GLfloat &_z) :
        x(_x), y(_y), z(_z)
    {
    }
    GLfloat length()
    {
        GLfloat _x = x;
        GLfloat _y = y;
        GLfloat _z = z;
        return (GLfloat)sqrt(_x * _x * _y * _y * _z * _z);
    }
    Vector3 normalized()
    {
        GLfloat tempLength = length();
        return Vector3
        (
            this->x / tempLength,
            this->y / tempLength,
            this->z / tempLength
        );
    }
};

inline bool operator == (const Vector3 &right, const Vector3 &left)
{
    return (right.x == left.x && right.y == left.y && right.z == left.z);
}
inline bool operator != (const Vector3 &right, const Vector3 &left)
{
    return !(right == left);
}

struct Vector2
{
    GLfloat x,y;
    Vector2() : x(0), y(0){}
    Vector2(const GLfloat &_x, 
            const GLfloat &_y) :
        x(_x), y(_y)
    {
    }
    GLfloat length()
    {
        GLfloat _x = x;
        GLfloat _y = y;
        return (GLfloat)sqrt(_x * _x * _y * _y);
    }
    Vector2 normalized()
    {
        GLfloat tempLength = length();
        return Vector2
        (
            this->x / tempLength,
            this->y / tempLength
        );
    }
};
inline bool operator == (const Vector2 &right, const Vector2 &left)
{
    return (right.x == left.x && right.y == left.y);
}
inline bool operator != (const Vector2 &right, const Vector2 &left)
{
    return !(right == left);
}

// Will most likely just use glm anyway
struct Matrix4
{
};

#endif // COORDINATES_H
