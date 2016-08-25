#include "BTextStream.h"
#include <iostream>


BTextStream::BTextStream()
{
    
}

const char *BTextStream::getConstData() const
{
    return m_data.c_str();
}

std::string BTextStream::getStringData() const
{
    return m_data;
}

QString BTextStream::getQStringData() const
{
    return QString::fromStdString(m_data);
}

void BTextStream::insert(const char *str)
{
    m_data.append(str);
    onInsert();
}

void BTextStream::insert(char *str)
{
    m_data.append(str);
    onInsert();
}

void BTextStream::insert(int i)
{
    m_data.append(std::to_string(i));
    onInsert();
}

void BTextStream::insert(float f)
{
    m_data.append(std::to_string(f));
    onInsert();
}

void BTextStream::insert(char c)
{
    m_data.append((const char *)&c);
    onInsert();
}

void BTextStream::insert(double d)
{
    m_data.append(std::to_string(d));
    onInsert();
}

void BTextStream::insert(unsigned char c)
{
    m_data.append((const char *)&c);
    onInsert();
}

void BTextStream::insert(short s)
{
    m_data.append(std::to_string(s));    
    onInsert();
}

void BTextStream::insert(std::string &str)
{
    m_data.append(str);
    onInsert();
}

void BTextStream::insert(QString &str)
{
    m_data.append(str.toStdString());
    onInsert();
}

void BTextStream::insert(const unsigned char *str)
{
    m_data.append((const char *)str);
    onInsert();
}

void BTextStream::insert(unsigned short s)
{
    m_data.append(std::to_string(s));
    onInsert();
}

void BTextStream::onInsert()
{
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
