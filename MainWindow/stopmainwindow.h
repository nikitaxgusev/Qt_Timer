#ifndef STOPMAINWINDOW_H
#define STOPMAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QDateTime>
#include <QLayout>
#include <QGridLayout>
#include <QMediaPlayer>
#include <QRadioButton>
#include "mainwindow.h"


class StopMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StopMainWindow(QWidget *parent = 0);
    ~StopMainWindow();
    QTimer *countdown;
    QWidget *centralWidget;
    QGroupBox *groupBox;

    QLabel *lblh;
    QLabel *lblm;
    QLabel *lbls;

    QRadioButton *r_off;
    QRadioButton *r_on;

    QPushButton *pushButton_Start;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_Close;
    QPushButton *pushButton_go_on;
    QPushButton *pushButton_Back;

    QLineEdit *txth;
    QLineEdit *txtm;
    QLineEdit *txts;
    QMediaPlayer *music;
private:
    int startMilliseconds;
    bool        mRunning;
    QDateTime   mStartTime;
    QLabel *    mLabel;
    qint64      mTotalTime;
    qint64      mSessionTime;
protected:
    void timerEvent(QTimerEvent *);
    void MusicFunction(void);
public slots:
    void start(void);
    void pause(void);
    void stop(void);
    void back(void);
    void stop_all_music(void);
    void start_all_music(void);
};

#endif // STOPMAINWINDOW_H*/

