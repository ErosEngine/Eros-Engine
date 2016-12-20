#ifndef EDYNAMICARRAY_H
#define EDYNAMICARRAY_H

// Note(kiecker):
// This class will manage memory that you
// give over to it, all memory given to this class
// now belongs to this class and has a manual switch to delete
// the memory with "cleanMemory()" 
template <typename T>
class EDynamicArray
{
    T      * m_pData[];
    int      m_size;
    bool     m_cleanOnDestroy;
    
public:
    
    EDynamicArray();
    EDynamicArray(int size);
    
    void append(const T &&value);
    void prepend(const T &&value);
    void resize(int value);
    void cleanMemory();
    
    inline int size() { return m_size; }
    inline T *data() { return m_pData; }
    
    
};

#endif // EDYNAMICARRAY_H
