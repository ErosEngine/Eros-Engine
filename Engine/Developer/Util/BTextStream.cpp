#include "BTextStream.h"
#include <iostream>

BTextStream::BTextStream()
{
    data = QString(); // Default constructor
}

const char *BTextStream::ConstData() const
{
    return data.toLatin1().constData();
}

std::string BTextStream::StdStringData() const
{
    return std::string(data.toLatin1().constData());
}

QString BTextStream::QStringData() const
{
    return data;
}

void BTextStream::Insert(const char *str)
{
    data += (str);
    onInsert();
}

void BTextStream::Insert(char *str)
{
    data += (str);
    onInsert();
}

void BTextStream::Insert(int i)
{
    data += (QString::fromStdString(std::to_string(i)));
    onInsert();
}

void BTextStream::Insert(float f)
{
    data += (QString::fromStdString(std::to_string(f)));
    onInsert();
}

void BTextStream::Insert(char c)
{
    data += (c);
    onInsert();
}

void BTextStream::Insert(double d)
{
    data += (QString::fromStdString(std::to_string(d)));
    onInsert();
}


void BTextStream::Insert(unsigned char c)
{
    data += ((const char *)&c);
    onInsert();
}

void BTextStream::Insert(short s)
{
    data += (QString::fromStdString(std::to_string(s)));    
    onInsert();
}

void BTextStream::Insert(std::string &str)
{
    data += (QString::fromStdString(str));
    onInsert();
}

void BTextStream::Insert(QString &str)
{
    data += (str);
    onInsert();
}

void BTextStream::Insert(const unsigned char *str)
{
    data += ((const char *)str);
    onInsert();
}

void BTextStream::Insert(unsigned short s)
{
    data += (QString::fromStdString(std::to_string(s)));
    onInsert();
}

void BTextStream::onInsert()        { /* .... */ }
const char *BTextStream::onFree()   { return ""; }

const char *BTextStream::FreeData()
{
    return onFree();
}

BTextStream &operator <<(BTextStream &bs, const char *str)
{
    bs.Insert(str);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, char *str)
{
    bs.Insert(str);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, int i)
{
    bs.Insert(i);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, float f)
{
    bs.Insert(f);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, char c)
{
    bs.Insert(c);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, unsigned char c)
{
    bs.Insert(c);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, short s)
{
    bs.Insert(s);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, std::string &str)
{
    bs.Insert(str);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, QString &str)
{
    bs.Insert(str);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, const unsigned char *str)
{
    bs.Insert(str);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, double d)
{
    bs.Insert(d);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, unsigned short s)
{
    bs.Insert(s);
    return bs;
}

BTextStream &operator <<(BTextStream &bs, BTextStream &other)
{
    bs.Insert(other.data);
    return bs;
}
