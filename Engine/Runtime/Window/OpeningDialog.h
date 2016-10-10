#ifndef OPENINGDIALOG_H
#define OPENINGDIALOG_H

#include <QDialog>
#include <QThread>

enum WindowType
{
    WINDOW_SDL,
    WINDOW_QT
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
    
    WindowType returnedType;
    
private slots:
    void on_buttonBox_accepted();
    
private:
    void SyncData();
    
    Ui::OpeningDialog *ui;
};

#endif // OPENINGDIALOG_H
