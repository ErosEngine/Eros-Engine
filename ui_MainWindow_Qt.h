/********************************************************************************
** Form generated from reading UI file 'MainWindow_Qt.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "Engine/Editor/DebugLogger.h"
#include "Engine/Editor/OpenGLViewPort.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow_Qt
{
public:
    QWidget *centralwidget;
    OpenGLViewPort *openGLWidget;
    DebugLogger *debugOutput;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow_Qt)
    {
        if (MainWindow_Qt->objectName().isEmpty())
            MainWindow_Qt->setObjectName(QStringLiteral("MainWindow_Qt"));
        MainWindow_Qt->resize(1257, 689);
        MainWindow_Qt->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	color: black;\n"
"	background-color: orange;\n"
"}"));
        centralwidget = new QWidget(MainWindow_Qt);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        openGLWidget = new OpenGLViewPort(centralwidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(90, 0, 741, 451));
        debugOutput = new DebugLogger(centralwidget);
        debugOutput->setObjectName(QStringLiteral("debugOutput"));
        debugOutput->setGeometry(QRect(90, 450, 751, 171));
        debugOutput->setStyleSheet(QLatin1String("#debugOutput {\n"
"	font: 12pt \"Arial\";\n"
"}"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 10, 91, 21));
        pushButton->setStyleSheet(QLatin1String("QPushButton#pushButton\n"
"{\n"
"	\n"
"}"));
        MainWindow_Qt->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow_Qt);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1257, 20));
        MainWindow_Qt->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow_Qt);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow_Qt->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow_Qt);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow_Qt->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow_Qt);

        QMetaObject::connectSlotsByName(MainWindow_Qt);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_Qt)
    {
        MainWindow_Qt->setWindowTitle(QApplication::translate("MainWindow_Qt", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow_Qt", "PushButton", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow_Qt", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_Qt: public Ui_MainWindow_Qt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_QT_H
