#include "OpeningDialog.h"
#include "ui_OpeningDialog.h"
#include "ErosLib/ErosDefines.h"

OpeningDialog::OpeningDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpeningDialog)
{
    ui->setupUi(this);
    
    ui->comboBox->addItem("GAME");
    ui->comboBox->addItem("EDITOR");
    ui->comboBox->setCurrentIndex(1);
	
	ui->renderingApi->addItem("OpenGL 4.5");
#ifdef EROS_WINDOWS
	ui->renderingApi->addItem("DirectX 11");
#endif
    this->setWindowTitle("Choose editor mode");
}

void OpeningDialog::SyncData()
{
    this->clearFocus();
    if (ui->comboBox->currentText() == "EDITOR")
        returnedType = WindowType::WINDOW_QT;
    else if (ui->comboBox->currentText() == "GAME")
        returnedType = WindowType::WINDOW_SDL;
	
	if (ui->renderingApi->currentData() == "OpenGL 4.5")
		apiType = RenderingType::RENDERING_OPENGL;
	else if (ui->renderingApi->currentData() == "DirectX 11")
		apiType = RenderingType::RENDERING_DIRECTX;
}

OpeningDialog::~OpeningDialog()
{
    SyncData();
    delete ui;
}

void OpeningDialog::on_buttonBox_accepted()
{
    SyncData();
}
