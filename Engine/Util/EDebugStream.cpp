#include "EDebugStream.h"
#include <QDebug>


EDebugStream::EDebugStream(bool isEditor)
{
    this->m_isEditor = isEditor;
}

void EDebugStream::onInsert()
{
    MainWindow_Qt::getInstance()->sendDebugString(QString::fromStdString(this->m_data));
    qDebug() << "Sent string " << QString::fromStdString(this->m_data);
}
