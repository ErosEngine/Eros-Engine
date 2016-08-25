#ifndef COORDINATES_H
#define COORDINATES_H

#include <SDL_opengl.h>
#include <glm/glm.hpp>
#include <cmath>
#include <QMatrix4x4>

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
        return (GLfloat)sqrt(x * x * y * y * z * z * w * w);
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
};
inline bool operator == (const Vector4 &right, const Vector4 &left)
{
    return (right.x == left.x && right.y == left.y && right.z == left.z && right.w == left.w);
}
inline bool operator != (const Vector4 &right, const Vector4 &left)
{
    return !(right == left);
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
        return (GLfloat)sqrt(x * x * y * y * z * z);
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
        return (GLfloat)sqrt(x * x * y * y);
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
inline Vector3 operator * (Vector3 &left, Vector3 &right)
{
    return Vector3
    (
        right.x * left.x,
        right.y * left.y,
        right.z * left.z
    );
}
inline Vector2 operator * (Vector2 &left, Vector2 &right)
{
    return Vector2
    (
        right.x * left.x,
        right.y * left.y
    );
}
inline Vector4 operator * (Vector4 &left, Vector3 &right)
{
    return Vector4
    (
        right.x * left.x,
        right.y * left.y,
        right.z * left.z,
        left.w
    );
}
inline Vector4 operator * (Vector4 &left, Vector2 &right)
{
    return Vector4
    (
        left.x * right.x,
        left.y * right.y,
        left.z,
        left.w
    );
}
inline Vector3 operator * (Vector3 &left, Vector4 &right)
{
    return Vector3
    (
        left.x * right.x,
        left.y * right.y,
        left.z * right.z
    );
}
inline Vector3 operator * (Vector3 &left, Vector2 &right)
{
    return Vector3
    (
        left.x * right.x,
        left.y * right.y,
        left.z
    );
}
inline Vector2 operator * (Vector2 &left, Vector4 &right)
{
    return Vector2
    (
        left.x * right.x,
        left.y * right.y
    );
}
inline Vector2 operator * (Vector2 &left, Vector3 &right)
{
    return Vector2
    (
        left.x * right.x,
        left.y * right.y
    );
}
inline bool operator == (Vector2 &left, Vector4 &right)
{
    return (left.x == right.x && left.y == right.y);
}
inline bool operator != (Vector2 &left, Vector4 &right)
{
    return !(left == right);
}
inline bool operator == (Vector2 &left, Vector3 &right)
{
    return (left.x == right.x && left.y == right.y);
}
inline bool operator != (Vector2 &left, Vector3 &right)
{
    return !(left == right);
}
inline bool operator == (Vector3 &left, Vector4 &right)
{
    return (left.x == right.x && left.y == right.y && left.z == right.z);
}
inline bool operator != (Vector3 &left, Vector4 &right)
{
    return !(left == right);
}
inline bool operator == (Vector3 &left, Vector2 &right)
{
    return (left.x == right.x && left.y == right.y);
}
inline bool operator != (Vector3 &left, Vector2 &right)
{
    return !(left == right);
}



#endif // COORDINATES_H
