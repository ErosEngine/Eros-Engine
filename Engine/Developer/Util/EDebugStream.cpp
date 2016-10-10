#include "EDebugStream.h"
#include <QDebug>

#define SENDDEBUG() MainWindow_Qt::getInstance()->queueDebugStr(this->data)


EDebugStream::EDebugStream() : BTextStream() // Default constructor
{
    m_instance = this;
}

void EDebugStream::onInsert()
{
    SENDDEBUG();
}

EDebugStream *EDebugStream::m_instance = 0;

EDebugStream *EDebugStream::getInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new EDebugStream();
    }
    return m_instance;
}

const char *EDebugStream::onFree()
{
    this->data.clear();
    return "\n";
}
