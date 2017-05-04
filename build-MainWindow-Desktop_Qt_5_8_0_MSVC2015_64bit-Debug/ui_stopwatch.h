/********************************************************************************
** Form generated from reading UI file 'stopwatch.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOPWATCH_H
#define UI_STOPWATCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StopWatch
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *StopWatch)
    {
        if (StopWatch->objectName().isEmpty())
            StopWatch->setObjectName(QStringLiteral("StopWatch"));
        StopWatch->resize(400, 300);
        pushButton = new QPushButton(StopWatch);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(64, 82, 121, 61));

        retranslateUi(StopWatch);

        QMetaObject::connectSlotsByName(StopWatch);
    } // setupUi

    void retranslateUi(QWidget *StopWatch)
    {
        StopWatch->setWindowTitle(QApplication::translate("StopWatch", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("StopWatch", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StopWatch: public Ui_StopWatch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOPWATCH_H
