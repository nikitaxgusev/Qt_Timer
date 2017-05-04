/********************************************************************************
** Form generated from reading UI file 'stopmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOPMAINWINDOW_H
#define UI_STOPMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StopMainWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StopMainWindow)
    {
        if (StopMainWindow->objectName().isEmpty())
            StopMainWindow->setObjectName(QStringLiteral("StopMainWindow"));
        StopMainWindow->resize(800, 600);
        menubar = new QMenuBar(StopMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        StopMainWindow->setMenuBar(menubar);
        centralwidget = new QWidget(StopMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        StopMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(StopMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        StopMainWindow->setStatusBar(statusbar);

        retranslateUi(StopMainWindow);

        QMetaObject::connectSlotsByName(StopMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StopMainWindow)
    {
        StopMainWindow->setWindowTitle(QApplication::translate("StopMainWindow", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StopMainWindow: public Ui_StopMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOPMAINWINDOW_H
