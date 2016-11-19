#ifndef BTEXTSTREAM_H
#define BTEXTSTREAM_H

#include <string>
#include <QString>


class BTextStream
{    
public:
    
    BTextStream();
    
    const char *ConstData() const;
    std::string StdStringData() const;
    QString QStringData() const;
    
    void Insert(const char *str);
    void Insert(char *str);
    void Insert(int i);
    void Insert(float f);
    void Insert(char c);
    void Insert(double d);
    void Insert(unsigned char c);
    void Insert(short s);
    void Insert(std::string &str);
    void Insert(QString &str);
    void Insert(const unsigned char *str);
    void Insert(unsigned short s);
    
    const char *FreeData();
    
    QString data;
    
protected:
    
    virtual void onInsert();
    virtual const char *onFree();
    
};

BTextStream &operator << (BTextStream &bs, const char *str);
BTextStream &operator << (BTextStream &bs, char *str);
BTextStream &operator << (BTextStream &bs, int i);
BTextStream &operator << (BTextStream &bs, float f);
BTextStream &operator << (BTextStream &bs, char c);
BTextStream &operator << (BTextStream &bs, double d);
BTextStream &operator << (BTextStream &bs, unsigned char c);
BTextStream &operator << (BTextStream &bs, short s);
BTextStream &operator << (BTextStream &bs, std::string &str);
BTextStream &operator << (BTextStream &bs, QString &str);
BTextStream &operator << (BTextStream &bs, const unsigned char *str);
BTextStream &operator << (BTextStream &bs, unsigned short s);
BTextStream &operator << (BTextStream &bs, BTextStream &other);


#endif // BTEXTSTREAM_H
