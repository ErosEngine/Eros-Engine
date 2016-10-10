#include "OpeningDialog.h"
#include "ui_OpeningDialog.h"

OpeningDialog::OpeningDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpeningDialog)
{
    ui->setupUi(this);
    
    ui->comboBox->addItem("GAME");
    ui->comboBox->addItem("EDITOR");
    ui->comboBox->setCurrentIndex(1);
    this->setWindowTitle("Choose editor mode");
}

void OpeningDialog::SyncData()
{
    this->clearFocus();
    if (ui->comboBox->currentText() == "EDITOR")
        returnedType = WindowType::WINDOW_QT;
    if (ui->comboBox->currentText() == "GAME")
        returnedType = WindowType::WINDOW_SDL;
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
