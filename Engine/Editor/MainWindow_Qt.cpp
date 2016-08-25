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

void MainWindow_Qt::sendDebugString(QString &string)
{
    ui->debugOutput->append(string);
}

void MainWindow_Qt::sendDebugString(const char *string)
{
    sendDebugString(QString(string));
}

void MainWindow_Qt::sendDebugString(GLenum &errorCode)
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
    
    sendDebugString(errorMessage);
}

MainWindow_Qt *MainWindow_Qt::m_singleton = 0;

MainWindow_Qt *MainWindow_Qt::getInstance()
{
    return m_singleton;
}
