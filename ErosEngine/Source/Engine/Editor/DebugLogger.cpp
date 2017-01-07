#include "DebugLogger.h"

DebugLogger::DebugLogger(QWidget *parent) : QTextBrowser(parent)
{
}

void DebugLogger::Append(LoggerMessage &message)
{
    message.GenerateHTML();
    QString current = message.GetString();
    QTextBrowser::append(current);
}
