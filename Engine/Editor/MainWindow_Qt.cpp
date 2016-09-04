#include "MainWindow_Qt.h"
#include "ui_MainWindow_Qt.h"


MainWindow_Qt::MainWindow_Qt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Qt)
{
    ui->setupUi(this);
    
    // allocate the singleton to this
    m_singleton = this;
}

MainWindow_Qt::~MainWindow_Qt()
{
    delete ui;
}

void MainWindow_Qt::queueDebugStr(QString &string)
{
    ui->debugOutput->append(string);
}

void MainWindow_Qt::queueDebugStr(const char *string)
{
    queueDebugStr(QString(string));
}

void MainWindow_Qt::queueDebugStr(GLenum &errorCode)
{
    QString errorMessage = "OPENGL ERROR: ";
    switch (errorCode)
    {
        case(GL_INVALID_ENUM):
            errorMessage += "invalid enum";
        break;
        case(GL_INVALID_FRAMEBUFFER_OPERATION):
            errorMessage += "invalid framebuffer operation";
        break;
        case(GL_INVALID_OPERATION):
            errorMessage += "invalid operation";
        break;
        case(GL_INVALID_INDEX):
            errorMessage += "invalid index";
        break;
        case(GL_INVALID_VALUE):
            errorMessage += "invalid value";
        break;
        case(GL_STACK_OVERFLOW):
            errorMessage += "stack overflow";
        break;
        case(GL_STACK_UNDERFLOW):
            errorMessage += "stack underflow";
        break;
        case(GL_OUT_OF_MEMORY):
            errorMessage += "out of memory";
        break;
        case(GL_NO_ERROR):
            errorMessage += "no error";
        break;
        default:
            errorMessage += "Unknown error, error code: " + 
                    QString::fromStdString(std::to_string((int)errorCode));
        break;
    }
    
    queueDebugStr(errorMessage);
}

void MainWindow_Qt::freeQueue()
{
}

MainWindow_Qt *MainWindow_Qt::m_singleton = 0;

MainWindow_Qt *MainWindow_Qt::getInstance()
{
    if (!m_singleton)
    {
        m_singleton = new MainWindow_Qt();
    }
    return m_singleton;
}
