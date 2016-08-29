#include "EDebugStream.h"
#include <QDebug>

#define SENDDEBUG() MainWindow_Qt::getInstance()->sendDebugString(this->m_data)


EDebugStream::EDebugStream(bool isEditor) : BTextStream() // Default constructor
{
    this->m_isEditor = isEditor;
    m_instance = this;
}

void EDebugStream::onInsert()
{
    qDebug() << this->m_data;
    SENDDEBUG();
}

EDebugStream *EDebugStream::m_instance = 0;

EDebugStream *EDebugStream::getInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new EDebugStream(true); // fail if "this" isn't initialized
    }
    return m_instance;
}
