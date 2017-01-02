#include "LoggerMessage.h"


const QString errorTag   = "<font color=\"Red\">";
const QString warningTag = "<font color=\"Yellow\">";

LoggerMessage::LoggerMessage()
{
}

LoggerMessage::LoggerMessage(const QString &message, MessageType messageType)
{
    m_message = message;
    m_type = messageType;
}

QString LoggerMessage::GetString()
{
    return m_string;
}

void LoggerMessage::SetMessage(const QString &message)
{
    m_message = message;
}

const MessageType LoggerMessage::GetType() const
{
    return m_type;
}

void LoggerMessage::SetType(const MessageType &type)
{
    m_type = type;
}

void LoggerMessage::GenerateHTML()
{
    switch (m_type)
    {
        case ERROR_STRING:
        {
            m_string.prepend(errorTag);
            m_string.append(m_message);
        } break;
        case WARNING_STRING:
        {
            m_string.prepend(warningTag);
            m_string.append(m_message);
        } break;
        case NORMAL_STRING:
        {
            m_string.append(m_message);
        } break;
        default:
        {
            m_string.append(m_message);
        } break;
    }
}
