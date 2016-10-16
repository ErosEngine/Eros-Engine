#ifndef EDEBUGSTREAM_H
#define EDEBUGSTREAM_H

#include "../Util/BTextStream.h"
#include "Engine/Editor/MainWindow_Qt.h"


class EDebugStream : public BTextStream
{    
public:
    
    EDebugStream();
    
    void onInsert() override;
    
    static EDebugStream *getInstance();
    
protected:
    
    const char *onFree() override;
    
private:
    
    static EDebugStream *m_instance;

};

#endif // EDEBUGSTREAM_H
