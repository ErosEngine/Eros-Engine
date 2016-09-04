#ifndef COORDINATES_H
#define COORDINATES_H

#ifndef __glew_h__
#include <GL/glew.h>
#endif
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

inline Vector4 &operator * (Vector4 &left, Vector4 &right)
{
    return Vector4
    (
        left.x * right.x,
        left.y * right.y,
        left.z * right.z,
        left.w * right.w
    );
}
inline Vector4 &operator * (Vector4 &left, Vector3 &right)
{
    return Vector4
    (
        left.x * right.x,
        left.y * right.y,
        left.z * right.z,
        left.w
    );
}
inline Vector4 &operator * (Vector4 &left, Vector2 &right)
{
    return Vector4
    (
        left.x * right.x,
        left.y * right.y,
        left.z,
        left.w
    );
}
inline Vector4 &operator * (Vector4 &left, float right)
{
    return Vector4
    (
        left.x * right,
        left.y * right,
        left.z * right,
        left.w * right
    );
}

inline Vector3 &operator * (Vector3 &left, Vector4 &right)
{   
    return Vector3
    (
        left.x * right.x,
        left.y * right.y,
        left.z * right.z
    );
}
inline Vector3 &operator * (Vector3 &left, Vector3 &right)
{
    return Vector3
    (
        left.x * right.x,
        left.y * right.y,
        left.z * right.z
    );
}
inline Vector3 &operator * (Vector3 &left, Vector2 &right)
{
    return Vector3
    (
        left.x * right.x,
        left.y * right.y,
        left.z
    );
}
inline Vector3 &operator * (Vector3 &left, float right)
{
    return Vector3
    (
        left.x * right,
        left.y * right,
        left.z * right
    );
}

inline Vector2 &operator * (Vector2 &left, Vector4 &right)
{
    return Vector2(left.x * right.x, left.y * right.y);
}
inline Vector2 &operator * (Vector2 &left, Vector3 &right)
{
    return Vector2(left.x * right.x, left.y * right.y);
}
inline Vector2 &operator * (Vector2 &left, Vector2 &right)
{
    return Vector2(left.x * right.x, left.y * right.y);
}
inline Vector2 &operator * (Vector2 &left, float &right)
{
    return Vector2(left.x * right, left.y * right);
}

inline Vector4 &operator *= (Vector4 &left, Vector4 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    left.z *= right.z;
    left.w *= right.w;
    return left;
}
inline Vector4 &operator *= (Vector4 &left, Vector3 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    left.z *= right.z;
    return left;
}
inline Vector4 &operator *= (Vector4 &left, Vector2 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    return left;
}
inline Vector4 &operator *= (Vector4 &left, float right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    left.w *= right;
    return left;
}

inline Vector3 &operator *= (Vector3 &left, Vector4 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    left.z *= right.z;
    return left;
}
inline Vector3 &operator *= (Vector3 &left, Vector3 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    left.z *= right.z;
    return left;
}
inline Vector3 &operator *= (Vector3 &left, Vector2 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    return left;
}
inline Vector3 &operator *= (Vector3 &left, float right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    return left;
}

inline Vector2 &operator *= (Vector2 &left, Vector4 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    return left;
}
inline Vector2 &operator *= (Vector2 &left, Vector3 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    return left;
}
inline Vector2 &operator *= (Vector2 &left, Vector2 &right)
{
    left.x *= right.x;
    left.y *= right.y;
    return left;
}
inline Vector2 &operator *= (Vector2 &left, float right)
{
    left.x *= right;
    left.y *= right;
    return left;
}

inline Vector4 &operator / (Vector4 &left, Vector4 &right)
{
    return Vector4
    (
        left.x / right.x,
        left.y / right.y,
        left.z / right.z,
        left.w / right.w
    );
}
inline Vector4 &operator / (Vector4 &left, Vector3 &right)
{
    return Vector4
    (
        left.x / right.x,
        left.y / right.y,
        left.z / right.z,
        left.w
    );
}
inline Vector4 &operator / (Vector4 &left, Vector2 &right)
{
    return Vector4
    (
        left.x / right.x,
        left.y / right.y,
        left.z,
        left.w
    );
}
inline Vector4 &operator / (Vector4 &left, float right)
{
    return Vector4
    (
        left.x / right,
        left.y / right,
        left.z / right,
        left.w / right
    );
}

inline Vector3 &operator / (Vector3 &left, Vector4 &right)
{   
    return Vector3
    (
        left.x / right.x,
        left.y / right.y,
        left.z / right.z
    );
}
inline Vector3 &operator / (Vector3 &left, Vector3 &right)
{
    return Vector3
    (
        left.x / right.x,
        left.y / right.y,
        left.z / right.z
    );
}
inline Vector3 &operator / (Vector3 &left, Vector2 &right)
{
    return Vector3
    (
        left.x / right.x,
        left.y / right.y,
        left.z
    );
}
inline Vector3 &operator / (Vector3 &left, float right)
{
    return Vector3
    (
        left.x / right,
        left.y / right,
        left.z / right
    );
}

inline Vector2 &operator / (Vector2 &left, Vector4 &right)
{
    return Vector2(left.x / right.x, left.y / right.y);
}
inline Vector2 &operator / (Vector2 &left, Vector3 &right)
{
    return Vector2(left.x / right.x, left.y / right.y);
}
inline Vector2 &operator / (Vector2 &left, Vector2 &right)
{
    return Vector2(left.x / right.x, left.y / right.y);
}
inline Vector2 &operator / (Vector2 &left, float &right)
{
    return Vector2(left.x / right, left.y / right);
}

inline Vector4 &operator /= (Vector4 &left, Vector4 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    left.z /= right.z;
    left.w /= right.w;
    return left;
}
inline Vector4 &operator /= (Vector4 &left, Vector3 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    left.z /= right.z;
    return left;
}
inline Vector4 &operator /= (Vector4 &left, Vector2 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    return left;
}
inline Vector4 &operator /= (Vector4 &left, float right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;
    left.w /= right;
    return left;
}

inline Vector3 &operator /= (Vector3 &left, Vector4 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    left.z /= right.z;
    return left;
}
inline Vector3 &operator /= (Vector3 &left, Vector3 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    left.z /= right.z;
    return left;
}
inline Vector3 &operator /= (Vector3 &left, Vector2 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    return left;
}
inline Vector3 &operator /= (Vector3 &left, float right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;
    return left;
}

inline Vector2 &operator /= (Vector2 &left, Vector4 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    return left;
}
inline Vector2 &operator /= (Vector2 &left, Vector3 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    return left;
}
inline Vector2 &operator /= (Vector2 &left, Vector2 &right)
{
    left.x /= right.x;
    left.y /= right.y;
    return left;
}
inline Vector2 &operator /= (Vector2 &left, float right)
{
    left.x /= right;
    left.y /= right;
    return left;
}

inline Vector4 &operator + (Vector4 &left, Vector4 &right)
{
    return Vector4
    (
        left.x + right.x,
        left.y + right.y,
        left.z + right.z,
        left.w + right.w
    );
}
inline Vector4 &operator + (Vector4 &left, Vector3 &right)
{
    return Vector4
    (
        left.x + right.x,
        left.y + right.y,
        left.z + right.z,
        left.w
    );
}
inline Vector4 &operator + (Vector4 &left, Vector2 &right)
{
    return Vector4
    (
        left.x + right.x,
        left.y + right.y,
        left.z,
        left.w
    );
}
inline Vector4 &operator + (Vector4 &left, float right)
{
    return Vector4
    (
        left.x + right,
        left.y + right,
        left.z + right,
        left.w + right
    );
}

inline Vector3 &operator + (Vector3 &left, Vector4 &right)
{   
    return Vector3
    (
        left.x + right.x,
        left.y + right.y,
        left.z + right.z
    );
}
inline Vector3 &operator + (Vector3 &left, Vector3 &right)
{
    return Vector3
    (
        left.x + right.x,
        left.y + right.y,
        left.z + right.z
    );
}
inline Vector3 &operator + (Vector3 &left, Vector2 &right)
{
    return Vector3
    (
        left.x + right.x,
        left.y + right.y,
        left.z
    );
}
inline Vector3 &operator + (Vector3 &left, float right)
{
    return Vector3
    (
        left.x + right,
        left.y + right,
        left.z + right
    );
}

inline Vector2 &operator + (Vector2 &left, Vector4 &right)
{
    return Vector2(left.x + right.x, left.y + right.y);
}
inline Vector2 &operator + (Vector2 &left, Vector3 &right)
{
    return Vector2(left.x + right.x, left.y + right.y);
}
inline Vector2 &operator + (Vector2 &left, Vector2 &right)
{
    return Vector2(left.x + right.x, left.y + right.y);
}
inline Vector2 &operator + (Vector2 &left, float &right)
{
    return Vector2(left.x + right, left.y + right);
}

inline Vector4 &operator += (Vector4 &left, Vector4 &right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    left.w += right.w;
    return left;
}
inline Vector4 &operator += (Vector4 &left, Vector3 &right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}
inline Vector4 &operator += (Vector4 &left, Vector2 &right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}
inline Vector4 &operator += (Vector4 &left, float right)
{
    left.x += right;
    left.y += right;
    left.z += right;
    left.w += right;
    return left;
}

inline Vector3 &operator += (Vector3 &left, Vector4 &right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}
inline Vector3 &operator += (Vector3 &left, Vector3 &right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}
inline Vector3 &operator += (Vector3 &left, Vector2 &right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}
inline Vector3 &operator += (Vector3 &left, float right)
{
    left.x += right;
    left.y += right;
    left.z += right;
    return left;
}

inline Vector2 &operator += (Vector2 &left, Vector4 &right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}
inline Vector2 &operator += (Vector2 &left, Vector3 &right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}
inline Vector2 &operator += (Vector2 &left, Vector2 &right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}
inline Vector2 &operator += (Vector2 &left, float right)
{
    left.x += right;
    left.y += right;
    return left;
}

inline Vector4 &operator - (Vector4 &left, Vector4 &right)
{
    return Vector4
    (
        left.x - right.x,
        left.y - right.y,
        left.z - right.z,
        left.w - right.w
    );
}
inline Vector4 &operator - (Vector4 &left, Vector3 &right)
{
    return Vector4
    (
        left.x - right.x,
        left.y - right.y,
        left.z - right.z,
        left.w
    );
}
inline Vector4 &operator - (Vector4 &left, Vector2 &right)
{
    return Vector4
    (
        left.x - right.x,
        left.y - right.y,
        left.z,
        left.w
    );
}
inline Vector4 &operator - (Vector4 &left, float right)
{
    return Vector4
    (
        left.x - right,
        left.y - right,
        left.z - right,
        left.w - right
    );
}

inline Vector3 &operator - (Vector3 &left, Vector4 &right)
{   
    return Vector3
    (
        left.x - right.x,
        left.y - right.y,
        left.z - right.z
    );
}
inline Vector3 &operator - (Vector3 &left, Vector3 &right)
{
    return Vector3
    (
        left.x - right.x,
        left.y - right.y,
        left.z - right.z
    );
}
inline Vector3 &operator - (Vector3 &left, Vector2 &right)
{
    return Vector3
    (
        left.x - right.x,
        left.y - right.y,
        left.z
    );
}
inline Vector3 &operator - (Vector3 &left, float right)
{
    return Vector3
    (
        left.x - right,
        left.y - right,
        left.z - right
    );
}

inline Vector2 &operator - (Vector2 &left, Vector4 &right)
{
    return Vector2(left.x - right.x, left.y - right.y);
}
inline Vector2 &operator - (Vector2 &left, Vector3 &right)
{
    return Vector2(left.x - right.x, left.y - right.y);
}
inline Vector2 &operator - (Vector2 &left, Vector2 &right)
{
    return Vector2(left.x - right.x, left.y - right.y);
}
inline Vector2 &operator - (Vector2 &left, float &right)
{
    return Vector2(left.x - right, left.y - right);
}

inline Vector4 &operator -= (Vector4 &left, Vector4 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    left.w -= right.w;
    return left;
}
inline Vector4 &operator -= (Vector4 &left, Vector3 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}
inline Vector4 &operator -= (Vector4 &left, Vector2 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}
inline Vector4 &operator -= (Vector4 &left, float right)
{
    left.x -= right;
    left.y -= right;
    left.z -= right;
    left.w -= right;
    return left;
}

inline Vector3 &operator -= (Vector3 &left, Vector4 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}
inline Vector3 &operator -= (Vector3 &left, Vector3 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}
inline Vector3 &operator -= (Vector3 &left, Vector2 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}
inline Vector3 &operator -= (Vector3 &left, float right)
{
    left.x -= right;
    left.y -= right;
    left.z -= right;
    return left;
}

inline Vector2 &operator -= (Vector2 &left, Vector4 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}
inline Vector2 &operator -= (Vector2 &left, Vector3 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}
inline Vector2 &operator -= (Vector2 &left, Vector2 &right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}
inline Vector2 &operator -= (Vector2 &left, float right)
{
    left.x -= right;
    left.y -= right;
    return left;
}

inline bool operator == (Vector4 &left, Vector4 &right)
{
    return (left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w);
}
inline bool operator != (Vector4 &left, Vector4 &right)
{
    return !(right == left);
}
inline bool operator == (Vector4 &left, Vector3 &right)
{
    return (left.x == right.x && left.y == right.y && left.z == right.z);
}
inline bool operator != (Vector4 &left, Vector3 &right)
{
    return !(left == right);
}
inline bool operator == (Vector4 &left, Vector2 &right)
{
    return (left.x == right.x && left.y == right.y);
}
inline bool operator != (Vector4 &left, Vector2 &right)
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
inline bool operator == (Vector3 &left, Vector3 &right)
{
    return (left.x == right.x && left.y == right.y && left.z == right.z);
}
inline bool operator != (Vector3 &left, Vector3 &right)
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
inline bool operator == (Vector2 &left, Vector2 &right)
{
    return (left.x == right.x && left.y == right.y);
}
inline bool operator != (Vector2 &left, Vector2 &right)
{
    return !(left == right);
}


// -------- MATRICES ---------- //

struct Matrix4x4
{
    GLfloat matrix[4][4];
    
    enum RotDir
    {
        XAxis,
        YAxis,
        ZAxis
    };
    
    inline GLfloat *getValuePtr()
    {
        GLfloat arr[16];
        arr[0] = matrix[0][0]; arr[1] = matrix[0][1]; arr[2] = matrix[0][2]; arr[3] = matrix[0][3];
        arr[4] = matrix[1][0]; arr[5] = matrix[1][1]; arr[6] = matrix[1][2]; arr[7] = matrix[1][3];
        arr[8] = matrix[2][0]; arr[9] = matrix[2][1]; arr[10] = matrix[2][2]; arr[11] = matrix[2][3];
        arr[12] = matrix[3][0]; arr[13] = matrix[3][1]; arr[14] = matrix[3][2]; arr[15] = matrix[3][3];
        return arr;
    }
    
    explicit inline Matrix4x4(
    GLfloat m11 = 0.0f, GLfloat m12 = 0.0f, GLfloat m13 = 0.0f, GLfloat m14 = 0.0f,
    GLfloat m21 = 0.0f, GLfloat m22 = 0.0f, GLfloat m23 = 0.0f, GLfloat m24 = 0.0f,
    GLfloat m31 = 0.0f, GLfloat m32 = 0.0f, GLfloat m33 = 0.0f, GLfloat m34 = 0.0f,
    GLfloat m41 = 0.0f, GLfloat m42 = 0.0f, GLfloat m43 = 0.0f, GLfloat m44 = 0.0f)
    {
        matrix[0][0] = m11; matrix[0][1] = m12; matrix[0][2] = m13; matrix[0][3] = m14;
        matrix[1][0] = m21; matrix[1][1] = m22; matrix[1][2] = m23; matrix[1][3] = m24;
        matrix[2][0] = m31; matrix[2][1] = m32; matrix[2][2] = m33; matrix[2][3] = m34; 
        matrix[3][0] = m41; matrix[3][1] = m42; matrix[3][2] = m43; matrix[3][3] = m44;
    }
    
    inline Matrix4x4(Vector4 &row1, Vector4 &row2, Vector4 &row3, Vector4 &row4)
    {
        matrix[0][0] = row1.x; matrix[0][1] = row1.y; matrix[0][2] = row1.z; matrix[0][3] = row1.w;
        matrix[1][0] = row2.x; matrix[1][1] = row2.y; matrix[1][2] = row2.z; matrix[1][3] = row2.w;
        matrix[2][0] = row3.x; matrix[2][1] = row3.y; matrix[2][2] = row3.z; matrix[2][3] = row3.w; 
        matrix[3][0] = row4.x; matrix[3][1] = row4.y; matrix[3][2] = row4.z; matrix[3][3] = row4.w;
    }
    
    inline void setIdentity()
    {
        matrix[0][0] = 1.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f; matrix[0][3] = 0.0f;
        matrix[1][0] = 0.0f; matrix[1][1] = 1.0f; matrix[1][2] = 0.0f; matrix[1][3] = 0.0f;
        matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 1.0f; matrix[2][3] = 0.0f;
        matrix[3][0] = 0.0f; matrix[3][1] = 0.0f; matrix[3][2] = 0.0f; matrix[3][3] = 1.0f;
    }
    
    inline void translate(GLfloat offsetX = 0.0f, GLfloat offsetY = 0.0f, GLfloat offsetZ = 0.0f)
    {
        matrix[0][3] = offsetX;
        matrix[1][3] = offsetY;
        matrix[2][3] = offsetZ;
    }
    
    inline void rotate(GLfloat angle, RotDir dir)
    {
        switch (dir)
        {
            case (RotDir::XAxis):
            {
                matrix[1][1] = cosf(angle);
                matrix[1][2] = sinf(angle) * -1.0f;
                matrix[2][1] = sinf(angle);
                matrix[2][2] = cosf(angle);
            }
            break;
            case (RotDir::YAxis):
            {
                matrix[0][0] = cosf(angle);
                matrix[0][3] = sinf(angle);
                matrix[2][0] = sinf(angle) * -1.0f;
                matrix[2][2] = cosf(angle);
            }
            break;
            case (RotDir::ZAxis):
            {
                matrix[0][0] = cosf(angle);
                matrix[0][1] = sinf(angle) * -1.0f;
                matrix[1][0] = sinf(angle);
                matrix[1][1] = cosf(angle);
            }
            break;
        }
    }
};

inline Vector4 &operator * (Vector4 &left, Matrix4x4 &right)
{
    return Vector4
    (
        ((right.matrix[0][0] * left.x) + (right.matrix[0][1] * left.y) + (right.matrix[0][2] * left.z) + (right.matrix[0][3] * left.w)),
        ((right.matrix[1][0] * left.x) + (right.matrix[1][1] * left.y) + (right.matrix[1][2] * left.z) + (right.matrix[1][3] * left.w)),
        ((right.matrix[2][0] * left.x) + (right.matrix[2][1] * left.y) + (right.matrix[2][2] * left.z) + (right.matrix[2][3] * left.w)),
        ((right.matrix[3][0] * left.x) + (right.matrix[3][1] * left.y) + (right.matrix[3][2] * left.z) + (right.matrix[3][3] * left.w))
    );
}
/*
inline Matrix4x4 &operator * (Matrix4x4 &left, Matrix4x4 &right)
{
    return Matrix4x4
    (
    ((left.matrix[0][0] * right.matrix[0][0]) + (left.matrix[0][1] * right.matrix[1][0]) + (left.matrix[0][2] * right.matrix[2][0]) + (left.matrix[0][3] * right.matrix[3][0])),
    ()
    );
}
*/

#endif // COORDINATES_H
