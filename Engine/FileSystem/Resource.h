#ifndef RESOURCE_H
#define RESOURCE_H

#include <GL/glew.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <QDebug>
#include <iostream>

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
    
    std::string m_data;
    std::ifstream m_stream;
    
};

#endif // RESOURCE_H
