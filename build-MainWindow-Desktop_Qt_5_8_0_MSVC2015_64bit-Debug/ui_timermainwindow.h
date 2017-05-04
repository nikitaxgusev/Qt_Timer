/********************************************************************************
** Form generated from reading UI file 'timermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMERMAINWINDOW_H
#define UI_TIMERMAINWINDOW_H

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

class Ui_TimerMainWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TimerMainWindow)
    {
        if (TimerMainWindow->objectName().isEmpty())
            TimerMainWindow->setObjectName(QStringLiteral("TimerMainWindow"));
        TimerMainWindow->resize(394, 359);
        centralwidget = new QWidget(TimerMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        TimerMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TimerMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 394, 21));
        TimerMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TimerMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TimerMainWindow->setStatusBar(statusbar);

        retranslateUi(TimerMainWindow);

        QMetaObject::connectSlotsByName(TimerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TimerMainWindow)
    {
        TimerMainWindow->setWindowTitle(QApplication::translate("TimerMainWindow", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TimerMainWindow: public Ui_TimerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERMAINWINDOW_H
