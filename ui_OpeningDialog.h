/********************************************************************************
** Form generated from reading UI file 'OpeningDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENINGDIALOG_H
#define UI_OPENINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_OpeningDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;

    void setupUi(QDialog *OpeningDialog)
    {
        if (OpeningDialog->objectName().isEmpty())
            OpeningDialog->setObjectName(QStringLiteral("OpeningDialog"));
        OpeningDialog->resize(294, 131);
        buttonBox = new QDialogButtonBox(OpeningDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-110, 70, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(OpeningDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 30, 261, 22));
        comboBox->setStyleSheet(QStringLiteral(""));

        retranslateUi(OpeningDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OpeningDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OpeningDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OpeningDialog);
    } // setupUi

    void retranslateUi(QDialog *OpeningDialog)
    {
        OpeningDialog->setWindowTitle(QApplication::translate("OpeningDialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OpeningDialog: public Ui_OpeningDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENINGDIALOG_H
