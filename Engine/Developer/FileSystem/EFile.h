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
    NoError                 =  1, // True, no error
    FailedToFindFile        =  0, // false, didn't find file
    InufficientPermissions  = -1, 
    FileCurrupted           = -2
};

class EFile
{
public:
    
   ~EFile();
    
    FileErrorCode openFile(const char *fileName, OpenType type);
    void closeFile();
    const char *getError();
    const char *getDataConst() const; // This is maximum string compatibility
    char *getData() const;
    int size();
    void setSize();
    
private:
    
    struct _FILE_ 
    {
    };
    
    FileErrorCode m_errorState;
    unsigned int m_size;   
    
};

#endif // RESOURCE_H
