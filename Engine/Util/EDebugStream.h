#ifndef EDEBUGSTREAM_H
#define EDEBUGSTREAM_H

#include "Engine/Util/BTextStream.h"
#include "Engine/Editor/MainWindow_Qt.h"


class EDebugStream : public BTextStream
{
    friend class BTextStream;
    
public:
    
    explicit EDebugStream(bool isEditor);
    
    void onInsert() override;
    
private:
    
    bool m_isEditor;

};

#endif // EDEBUGSTREAM_H
