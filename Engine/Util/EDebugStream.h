#ifndef EDEBUGSTREAM_H
#define EDEBUGSTREAM_H

#include "Engine/Util/BTextStream.h"
#include "Engine/Editor/MainWindow_Qt.h"


class EDebugStream : public BTextStream
{    
public:
    
    explicit EDebugStream(bool isEditor);
    
    void onInsert() override;
    
    static EDebugStream *getInstance();
    
private:
    
    static EDebugStream *m_instance;
    
    bool m_isEditor;

};

#endif // EDEBUGSTREAM_H
