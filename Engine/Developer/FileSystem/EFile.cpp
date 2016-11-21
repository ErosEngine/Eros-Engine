#include "EFile.h"



EFile::~EFile()
{
    
}

FileErrorCode EFile::openFile(const char *fileName, OpenType type)
{
    return NoError;
}

const char *EFile::getError()
{
    if (m_errorState == FailedToFindFile)
    {
        return "Failed to find the file";
    }
    // Default return
    return "There was no error";
}

const char *EFile::getDataConst() const
{
    return NULL;
}

char *EFile::getData() const
{
    return NULL;
}

int EFile::size()
{
    return m_size;
}
