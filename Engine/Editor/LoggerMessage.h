#ifndef LOGGERMESSAGE_H
#define LOGGERMESSAGE_H

#ifndef QSTRING_H
#include <QString>
#endif

enum MessageType
{
    ERROR_STRING    = 1,
    WARNING_STRING  = 2,
    NORMAL_STRING   = 3
};

class LoggerMessage
{
public:
    
    LoggerMessage();
    LoggerMessage(const QString &message, MessageType messageType);

    QString GetString();
    void SetMessage(const QString &message);
    
    const MessageType GetType() const;
    void SetType(const MessageType &GetType);
    
    void GenerateHTML();
    
private:
    
    MessageType m_type;
    QString m_string;
    QString m_message;
};

#endif // LOGGERMESSAGE_H
