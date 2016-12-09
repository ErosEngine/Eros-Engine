#ifndef DEBUGLOGGER_H
#define DEBUGLOGGER_H

#include <QTextBrowser>
#include <QObject>
#include "LoggerMessage.h"


class DebugLogger : public QTextBrowser
{
    Q_OBJECT
    
public:
    explicit DebugLogger(QWidget *parent = 0);
    
    void append(LoggerMessage &message);
};

#endif // DEBUGLOGGER_H
