#ifndef RESOURCE_H
#define RESOURCE_H

#include <stdio.h>
#include <string>
#include <QDebug>
#include "Engine/Developer/Util/ErosDefines.h"

enum OpenType
{
    /*
    READWRITE = "rw",
    READONLY = "r",
    WRITEONLY = "w",
    READBINARY = "rb",
    WRITEBINARY = "wb"
    */
};

enum FileErrorCode
{
    NoError = 1, // True, no error
    FailedToFindFile = 0 // false, didn't find file
};

class EFile
{
public:
    
   ~EFile();
    
    FileErrorCode OpenFile(const char *fileName, OpenType type);
    void CloseFile();
    const char *GetError();
    const char *GetDataConst() const; // This is maximum string compatibility
    char *GetData() const;
    int Size();
    
private:
    
    FileErrorCode m_errorState;
    char *m_str;
    FILE *m_file;
    unsigned int m_size;   
    
};

#endif // RESOURCE_H
