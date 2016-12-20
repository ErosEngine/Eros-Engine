#include "EDynamicArray.h"




EDynamicArray::EDynamicArray()
{
    m_pData = nullptr;
}

EDynamicArray::EDynamicArray(int size)
{
}

void EDynamicArray::append(const T &&value)
{
    resize(m_size + 1);
    m_pData[m_size] = &value;
}

void EDynamicArray::prepend(const T &&value)
{
    
}

void EDynamicArray::resize(int value)
{
}

