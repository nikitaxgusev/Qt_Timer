#include "stopmainwindow.h"
#include "ui_stopmainwindow.h"
#include <QGridLayout>
#include <QLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "mainwindow.h"
StopMainWindow::StopMainWindow(QWidget *parent) :
    QMainWindow(parent),

      mRunning(false)
    , mStartTime()
    , mTotalTime(0)
{
    resize(360, 250);
    this->setFixedSize(this->geometry().width(),this->geometry().height());

    centralWidget = new QWidget(this);

    mLabel = new QLabel(centralWidget);
    mLabel->setText("00:00:00,000");
    mLabel->setGeometry(QRect(20, 70, 285, 80));
    QFont font_s = mLabel->font();
    font_s.setPointSize(36);
    mLabel->setFont(font_s);
   // mLabel->setStyleSheet("background-color: #FFD700; color: rgb(255, 20, 0)");


    /////////////////////////////////////////////////////////////////////////
    r_on=new QRadioButton(centralWidget);
    r_on->setText("Turn on sounds");
    r_on->setGeometry(QRect(20,1, 100, 20));


    r_off=new QRadioButton(centralWidget);
    r_off->setText("Turn off sounds");
    r_off->setGeometry(QRect(20,18, 100, 25));


    //Button for start
    pushButton_Start = new QPushButton(centralWidget);
    pushButton_Start->setText("Start");
    pushButton_Start->setGeometry(QRect(25,200 , 180, 30));


    QFont font_start = pushButton_Start->font();
    font_start.setPointSize(12);
    pushButton_Start->setFont(font_start);

    pushButton_Start->setAutoFillBackground(true);
    pushButton_Start->setStyleSheet("background-color: rgb(14, 20, 228); color: rgb(243,246,40)");
    // Button for stop
    pushButton_Stop = new QPushButton(centralWidget);
    pushButton_Stop->setText("Stop");
    pushButton_Stop->setGeometry(QRect(260, 200, 80, 30));


    QFont font_stop = pushButton_Stop->font();
    font_stop.setPointSize(12);
    pushButton_Stop->setFont(font_stop);

    pushButton_Stop->setAutoFillBackground(true);
    pushButton_Stop->setStyleSheet("background-color: rgb(255, 20, 0); color: rgb(243,246,40)");
    //Button for Go on
    pushButton_go_on=new QPushButton(centralWidget);
    pushButton_go_on->setText("Countinue");
    pushButton_go_on->setGeometry(QRect(260,165, 80, 30));

    QFont font_go = pushButton_go_on->font();
    font_go.setPointSize(12);
    pushButton_go_on->setFont(font_go);

    pushButton_go_on->setAutoFillBackground(true);
    pushButton_go_on->setStyleSheet("background-color:rgb(14, 20, 228); color: rgb(243,246,40)");

    //Button for close
    pushButton_Close = new QPushButton(centralWidget);
    pushButton_Close->setText("close");
    pushButton_Close->setGeometry(QRect(260, 5, 80, 30));

    QFont font_close = pushButton_Close->font();
    font_close.setPointSize(12);
    pushButton_Close->setFont(font_close);

    pushButton_Close->setAutoFillBackground(true);
    pushButton_Close->setStyleSheet("background-color: rgb(14, 20, 228); color: rgb(243,246,40)");
    //Button cancel

    pushButton_Back = new QPushButton(centralWidget);
    pushButton_Back->setText("Back");
    pushButton_Back->setGeometry(QRect(260, 40, 80, 30));

    QFont font_back = pushButton_Back->font();
    font_back.setPointSize(12);
    pushButton_Back->setFont(font_back);

   pushButton_Back->setAutoFillBackground(true);
   pushButton_Back->setStyleSheet("background-color: rgb(14, 20, 228); color: rgb(243,246,40)");
/////////////////////////////////////////////////////////////////////////////////////
    connect(pushButton_Start, SIGNAL(clicked()), SLOT(start()));
    connect(pushButton_go_on, SIGNAL(clicked()), SLOT(pause()));
    connect(pushButton_Stop, SIGNAL(clicked()), SLOT(stop()));
    connect(pushButton_Close, SIGNAL(clicked()), SLOT(close()));
    connect(pushButton_Back,SIGNAL(clicked()),SLOT(back()));
    connect(r_off,SIGNAL(clicked()),SLOT(stop_all_music()));
    connect(r_on,SIGNAL(clicked()),SLOT(start_all_music()));
///////////////////////////////////////////////////////////////////////////////
    setCentralWidget(centralWidget);
///////////////////////////////////////////////////////////////////////////////////////////////
        pushButton_Start->setEnabled(true);
        pushButton_go_on->setEnabled(false);
        pushButton_Stop->setEnabled(false);
/////////////////////////////////////////////////////////////////////////////////////////
          music=new QMediaPlayer(this,  QMediaPlayer::StreamPlayback);
          QMediaPlaylist *playlist = new QMediaPlaylist;
          playlist->addMedia(QUrl("qrc:/sounds/tik.mp3"));
          playlist->setPlaybackMode(QMediaPlaylist::Loop);
          music->setPlaylist(playlist);
          music->setVolume(100);


        r_on->setChecked(true);
        mRunning = false;
        startTimer(0);
}

StopMainWindow::~StopMainWindow()
{

}
void StopMainWindow::start(void)
{
     pushButton_Start->setEnabled(false);
     pushButton_go_on->setEnabled(true);
     pushButton_Stop->setEnabled(true);
     mStartTime = QDateTime::currentDateTime();
     mRunning = true;
     r_on->setChecked(true);
     MusicFunction();
     mStartTime = QDateTime::currentDateTime();
     startTimer(1);
}



void StopMainWindow::stop(void)
{
    pushButton_Start->setEnabled(true);
    pushButton_go_on->setEnabled(true);
    pushButton_Stop->setEnabled(false);
    mTotalTime = 0;
    mRunning = false;
    music->stop();
}
void StopMainWindow::pause(void)
{
    pushButton_Start->setEnabled(true);
    pushButton_go_on->setEnabled(false);
    pushButton_Stop->setEnabled(true);
    timerEvent(new QTimerEvent(0));
    mTotalTime += mSessionTime;
    mRunning = false;
    //music->stop();
}
void StopMainWindow::timerEvent(QTimerEvent *)
{

    if(mRunning)
      {

        mSessionTime = mStartTime.msecsTo(QDateTime::currentDateTime());
          qint64 time = mTotalTime + mSessionTime;
          time *= 60;

          unsigned int h = time / 1000 / 60 / 60;
          unsigned int m = (time / 1000 / 60) - (h * 60);
          unsigned int s = (time / 1000) - ((m + (h * 60))* 60);
          unsigned int ms = time - (s + ((m + (h * 60))* 60)) * 1000;

          const QString diff = QString("%1:%2:%3,%4")
                  .arg(h,  2, 10, QChar('0'))
                  .arg(m,  2, 10, QChar('0'))
                  .arg(s,  2, 10, QChar('0'))
                  .arg(ms, 3, 10, QChar('0'));
          mLabel->setText(diff);
      }
}

void StopMainWindow::back(void)
{
    this->hide();
    MainWindow *s =new MainWindow (this);
    music->stop();
    s->show();
}
void StopMainWindow::stop_all_music(void)
{
    music->stop();
}
void StopMainWindow::start_all_music(void)
{
    music->play();
}
void StopMainWindow::MusicFunction(void)
{
    if(r_on)
    {
     music->play();
    }
     else
    {
        connect(r_off,SIGNAL(clicked()),SLOT(stop_all_music()));
        connect(r_on,SIGNAL(clicked()),SLOT(start_all_music()));
    }
}
