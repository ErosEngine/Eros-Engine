#ifndef RESOURCE_H
#define RESOURCE_H

#include <fstream>
#include <string>
#include <QDebug>


enum fileType
{
    TEXT,
    BINARY
};

// This will be improved upon later 
// but for now this is all I need
class Resource
{
public:
    
    Resource();
    Resource(const char *fileName);
   ~Resource();
    
    void openFile(const char *fileName, const fileType &file_type = fileType::TEXT);
    void closeFile();
    const char *getDataConst() const;
    char *getData() const;

private:

    std::ifstream m_stream;
    std::string m_data;
    
};

#endif // RESOURCE_H
