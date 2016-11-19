#include "EFile.h"



EFile::~EFile()
{
    
}

FileErrorCode EFile::OpenFile(const char *fileName, OpenType type)
{
    m_file = fopen(fileName, type);
    
    
    
    return NoError;
}

const char *EFile::GetError()
{
    if (m_errorState == FailedToFindFile)
    {
        return "Failed to find the file";
    }
    // Default return
    return "There was no error";
}

const char *EFile::GetDataConst() const
{
    return reinterpret_cast<const char *>(m_str);
}

char *EFile::GetData() const
{
    return m_str;
}

int EFile::Size()
{
    return m_size;
}
