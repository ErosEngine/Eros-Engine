#include "DebugLogger.h"

DebugLogger::DebugLogger(QWidget *parent) : QTextBrowser(parent)
{
}

void DebugLogger::append(LoggerMessage &message)
{
    message.generateHTML();
    QString current = message.getString();
    QTextBrowser::append(current);
}
