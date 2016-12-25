#ifndef OPENINGDIALOG_H
#define OPENINGDIALOG_H

#include <QDialog>
#include <QThread>

enum WindowType
{
    WINDOW_SDL,
    WINDOW_QT
};

enum ApiType
{
	RENDERING_OPENGL_4_5 = 1,
	RENDERING_DIRECTX_11 = 2,
	RENDERING_VULKAN	 = 3,
	RENDERING_DIRECTX_12 = 4
};

namespace Ui {
class OpeningDialog;
}

class OpeningDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit OpeningDialog(QWidget *parent = 0);
    ~OpeningDialog();
    
    WindowType		returnedType;
	ApiType			apiType;
    
private slots:
    void on_buttonBox_accepted();
    
private:
    void SyncData();
    
    Ui::OpeningDialog *ui;
};

#endif // OPENINGDIALOG_H
