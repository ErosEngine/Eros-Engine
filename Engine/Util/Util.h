#ifndef UTIL_H
#define UTIL_H

#define endl "\n"

template<typename T>
inline int eros_arraySize(T *arr)
{
    return (sizeof(arr) / sizeof(T));
}

#endif // UTIL_H
