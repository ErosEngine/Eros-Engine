#ifndef BTEXTSTREAM_H
#define BTEXTSTREAM_H

#include <string>
#include <QString>


class BTextStream
{    
public:
    
    BTextStream();
    
    const char *constData() const;
    std::string stdStringData() const;
    QString QStringData() const;
    
    void insert(const char *str);
    void insert(char *str);
    void insert(int i);
    void insert(float f);
    void insert(char c);
    void insert(double d);
    void insert(unsigned char c);
    void insert(short s);
    void insert(std::string &str);
    void insert(QString &str);
    void insert(const unsigned char *str);
    void insert(unsigned short s);
    
    const char *freeData();
    
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
