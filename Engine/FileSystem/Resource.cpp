#include "Resource.h"


Resource::Resource()
{
    // Nothing for default constructor
}

Resource::Resource(const char *fileName)
{
    openFile(fileName);
}

Resource::~Resource()
{
    // Close checking already implemented
    this->closeFile();
}

void Resource::openFile(const char *fileName, const fileType &file_type)
{
    m_stream.open(fileName, std::ios::in);
    
    if (m_stream.is_open())
    {
        while (m_stream.good())
        {        
            std::string temp;
            std::getline(m_stream, temp);
            this->m_data.append(temp + "\n");
        }
    }
    else
    {
        qDebug() << "FAILED TO OPEN SPECIFIED FILE";
    }
}

void Resource::closeFile()
{
    if (m_stream.is_open())
    {
        m_stream.close();
    }
}

const char *Resource::getData() const
{
    return m_data.c_str();
}


