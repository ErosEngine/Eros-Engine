#include "EditorWindow.h"
#include "ui_EditorWindow.h"
#include "Engine/Runtime/Window/Window.h"


EditorWindow::EditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);
}

EditorWindow::~EditorWindow()
{
    delete ui;
}

EditorWindow *EditorWindow::m_singleton = 0;

EditorWindow *EditorWindow::GetInstance()
{
    if (!m_singleton)
    {
        m_singleton = new EditorWindow();
    }
	return m_singleton;
}

void EditorWindow::SetRenderer(IRenderBase *pRenderer)
{
	ui->viewport->SetRenderer(pRenderer);
}

void EditorWindow::on_pushButton_released()
{
}
