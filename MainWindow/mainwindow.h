#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QRadioButton>
#include <QMediaPlayer>
#include "timermainwindow.h"
#include "stopmainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QLabel *label_pic;

    QRadioButton *yellow;
    QRadioButton *black;
    QRadioButton *blue;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

    void yellow_clicked();
    void blue_clicked();
    void black_clicked();
private:
    Ui::MainWindow *ui;
   // TimerMainWindow *t;
   // StopMainWindow *s;
};

#endif // MAINWINDOW_H
