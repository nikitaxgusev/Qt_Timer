#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>
#include<QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    resize(400, 350);
    this->setFixedSize(this->geometry().width(),this->geometry().height());

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showClock()));
    timer->start();
    showClock();
  ///////////////////////////////////////////////////////////////



  /////////////////////////////////////////////////////////////
    yellow=new QRadioButton(this);
    yellow->setText("Yellow");
    yellow->setGeometry(QRect(120,270, 100, 20));


    blue=new QRadioButton(this);
    blue->setText("Blue");
    blue->setGeometry(QRect(180,270, 100, 20));

    black=new QRadioButton(this);
    black->setText("Gray");
    black->setGeometry(QRect(230,270, 100, 20));

    ///////////////////////////////////////////////////////////////
   // blue->setChecked(true);
    connect(yellow,SIGNAL(clicked()),SLOT(yellow_clicked()));
    connect(blue,SIGNAL(clicked()),SLOT(blue_clicked()));
    connect(black,SIGNAL(clicked()),SLOT(black_clicked()));
    ///////////////////////////////////////////////////////////
    //button Timer
    QFont font = ui->pushButton->font();
    font.setPointSize(12);
    ui->pushButton->setFont(font);
    ui->pushButton->setAutoFillBackground(true);
    ui->pushButton->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(244, 208, 63)");

    //Button Close
    QFont font1 = ui->pushButton_2->font();
    font1.setPointSize(12);
    ui->pushButton_2->setFont(font1);
    ui->pushButton_2->setAutoFillBackground(true);
    ui->pushButton_2->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(244, 208, 63)");

    //Button StopWatch
    QFont font2 = ui->pushButton_3->font();
    font2.setPointSize(12);
    ui->pushButton_3->setFont(font2);
    ui->pushButton_3->setAutoFillBackground(true);
    ui->pushButton_3->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(244, 208, 63)");

    setWindowTitle("Smart Watch");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
   TimerMainWindow *t =new TimerMainWindow(this);
    t->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}

void MainWindow::on_pushButton_2_clicked()
{
   this->hide();
   StopMainWindow *s=new StopMainWindow (this);
   s->show();
}
void MainWindow::yellow_clicked()
{
    this->setStyleSheet("background-color: #FFD700");
    this->setFixedSize(this->geometry().width(),this->geometry().height());
}
void MainWindow::blue_clicked()
{
    this->setStyleSheet("background-color: #1E90FF");
    this->setFixedSize(this->geometry().width(),this->geometry().height());
}
void MainWindow::black_clicked()
{
  this->setStyleSheet("background-color: #808080");
  this->setFixedSize(this->geometry().width(),this->geometry().height());
}
void MainWindow::showClock()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    if((time.second()%2)==0)
    {
        time_text[3]=' ';
    }
    if((time.second()%2)!=0)
    {
        time_text[8]=' ';
    }

    ui->Digital_work->setText(time_text);
}

