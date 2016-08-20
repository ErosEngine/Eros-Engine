/********************************************************************************
** Form generated from reading UI file 'MainWindow_Qt.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_QT_H
#define UI_MAINWINDOW_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "Engine/Editor/OpenGLViewPort.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow_Qt
{
public:
    QWidget *centralwidget;
    OpenGLViewPort *openGLWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_Qt)
    {
        if (MainWindow_Qt->objectName().isEmpty())
            MainWindow_Qt->setObjectName(QStringLiteral("MainWindow_Qt"));
        MainWindow_Qt->resize(1257, 689);
        centralwidget = new QWidget(MainWindow_Qt);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        openGLWidget = new OpenGLViewPort(centralwidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(110, 0, 751, 441));
        MainWindow_Qt->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow_Qt);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1257, 20));
        MainWindow_Qt->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow_Qt);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow_Qt->setStatusBar(statusbar);

        retranslateUi(MainWindow_Qt);

        QMetaObject::connectSlotsByName(MainWindow_Qt);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_Qt)
    {
        MainWindow_Qt->setWindowTitle(QApplication::translate("MainWindow_Qt", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_Qt: public Ui_MainWindow_Qt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_QT_H
