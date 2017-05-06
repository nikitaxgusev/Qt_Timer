#ifndef TIMERMAINWINDOW_H
#define TIMERMAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QGroupBox>
#include <QTimer>
#include <QPushButton>
#include <QMessageBox>
#include <QRadioButton>
#include <QMediaPlayer>
#include "mainwindow.h"
#include "stopmainwindow.h"
#include "timermainwindow.h"


class TimerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TimerMainWindow(QWidget *parent = 0);
    ~TimerMainWindow(){}
       QTimer *countdown;

       QWidget *centralWidget;

       QGroupBox *groupBox;

       QLineEdit *txth;
       QLineEdit *txtm;
       QLineEdit *txts;

       QLabel *label;
       QLabel *label_2;
       QLabel *label_3;

       QLabel *lblh;
       QLabel *lblm;
       QLabel *lbls;
       QLabel *points;
       QLabel *points1;

       QRadioButton *r_off;
       QRadioButton *r_on;

       QPushButton *pushButton;
       QPushButton *pushButton_Stop;
       QPushButton *pushButton_Close;
       QPushButton *pushButton_go_on;
       QPushButton *pushButton_Back;

       QMediaPlayer *music;
       QMediaPlayer *al;

private:
    int startMilliseconds;
    void MusicFunction(void);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_clicked_Stop();
    void on_pushButton_clicked_Go();
    void on_pushButton_clicked_back();
public slots:
    void stop_all_music(void);
    void start_all_music(void);
protected slots:
    void timeOut();
};

#endif // TIMERMAINWINDOW_H
