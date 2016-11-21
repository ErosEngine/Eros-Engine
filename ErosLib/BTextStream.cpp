#include "BTextStream.h"
#include <iostream>

BTextStream::BTextStream()
{
    data = QString(); // Default constructor
}

const char *BTextStream::constData() const
{
    return data.toLatin1().constData();
}

std::string BTextStream::stdStringData() const
{
    return std::string(data.toLatin1().constData());
}

QString BTextStream::QStringData() const
{
    return data;
}

void BTextStream::insert(const char *str)
{
    data += (str);
    onInsert();
}

void BTextStream::insert(char *str)
{
    data += (str);
    onInsert();
}

void BTextStream::insert(int i)
{
    data += (QString::fromStdString(std::to_string(i)));
    onInsert();
}

void BTextStream::insert(float f)
{
    data += (QString::fromStdString(std::to_string(f)));
    onInsert();
}

void BTextStream::insert(char c)
{
    data += (c);
    onInsert();
}

void BTextStream::insert(double d)
{
    data += (QString::fromStdString(std::to_string(d)));
    onInsert();
}


void BTextStream::insert(unsigned char c)
{
    data += ((const char *)&c);
    onInsert();
}

void BTextStream::insert(short s)
{
    data += (QString::fromStdString(std::to_string(s)));    
    onInsert();
}

void BTextStream::insert(std::string &str)
{
    data += (QString::fromStdString(str));
    onInsert();
}

void BTextStream::insert(QString &str)
{
    data += (str);
    onInsert();
}

void BTextStream::insert(const unsigned char *str)
{
    data += ((const char *)str);
    onInsert();
}

void BTextStream::insert(unsigned short s)
{
    data += (QString::fromStdString(std::to_string(s)));
    onInsert();
}

void BTextStream::onInsert()        { /* .... */ }
const char *BTextStream::onFree()   { return ""; }

const char *BTextStream::freeData()
{
    return onFree();
}

BTextStream &operator <<(BTextStream &bs, const char *str)
{
    bs.insert(str);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, char *str)
{
    bs.insert(str);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, int i)
{
    bs.insert(i);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, float f)
{
    bs.insert(f);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, char c)
{
    bs.insert(c);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, unsigned char c)
{
    bs.insert(c);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, short s)
{
    bs.insert(s);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, std::string &str)
{
    bs.insert(str);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, QString &str)
{
    bs.insert(str);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, const unsigned char *str)
{
    bs.insert(str);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, double d)
{
    bs.insert(d);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, unsigned short s)
{
    bs.insert(s);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, BTextStream &other)
{
    bs.insert(other.data);
    return bs;
}
