#include "timermainwindow.h"
#include "ui_timermainwindow.h"
#include <QDesktopWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

TimerMainWindow::TimerMainWindow(QWidget *parent) :
    QMainWindow(parent)

{
       resize(360, 250);
       this->setFixedSize(this->geometry().width(),this->geometry().height());


       centralWidget = new QWidget(this);
       groupBox = new QGroupBox(centralWidget);
       groupBox->setGeometry(QRect(5, 5, 220, 100));
       groupBox->setTitle("Time lefting");
       QFont font_box = groupBox->font();
       font_box.setPointSize(12);
       groupBox->setFont(font_box);
     //  groupBox->setStyleSheet("background-color: #FFD700; color: rgb(255, 20, 0)");

       //fields
       txth = new QLineEdit(this);
       txth->setGeometry(QRect(50, 150, 50, 27));
       txtm = new QLineEdit(this);
       txtm->setGeometry(QRect(100, 150, 50, 27));
       txts = new QLineEdit(this);
       txts->setGeometry(QRect(150, 150, 50, 27));
       // signs
       label = new QLabel(this);
       label->setText("Hours");
       label->setGeometry(QRect(50, 105, 50, 45));
       QFont font_label = label->font();
       font_label.setPointSize(8);
       label->setFont(font_label);
       //label->setStyleSheet("background-color: #FFD700; color: rgb(255, 20, 0)");

       label_2 = new QLabel(this);
       label_2->setText("Minutes");
       label_2->setGeometry(QRect(100, 105,50, 45));
       QFont font_label_2 = label_2->font();
       font_label_2.setPointSize(8);
       label_2->setFont(font_label_2);

      // label_2->setStyleSheet("background-color: #FFD700; color: rgb(255, 20, 0)");

       label_3 = new QLabel(this);
       label_3->setText("Seconds");
       label_3->setGeometry(QRect(150, 105, 50, 45));
       QFont font_label_3 = label_3->font();
       font_label_3.setPointSize(8);
       label_3->setFont(font_label_3);

      // label_3->setStyleSheet("background-color: #FFD700; color: rgb(255, 20, 0)");
///////////////////////////////////////////////////////////////////////////////////////////



       lblh = new QLabel(groupBox);
       lblh->setText("00");
       lblh->setGeometry(QRect(10, 30, 55, 55));
       QFont font_h = lblh->font();
       font_h.setPointSize(38);
       lblh->setFont(font_h);
      // lblh->setStyleSheet("background-color: #FFD700; color: rgb(255, 20, 0)");

       lblm = new QLabel(groupBox);
       lblm->setText("00");
       lblm->setGeometry(QRect(80, 30, 55, 55));
       QFont font_m = lblm->font();
       font_m.setPointSize(38);
       lblm->setFont(font_m);
      // lblm->setStyleSheet(font_m);
      // lblm->setStyleSheet("background-color: #FFD700; color: rgb(255, 20, 0)");

       lbls = new QLabel(groupBox);
       lbls->setText("00");
       lbls->setGeometry(QRect(150, 30, 55, 55));
       QFont font_s = lbls->font();
       font_s.setPointSize(38);
       lbls->setFont(font_s);
      // lbls->setStyleSheet(font_s);

       points=new QLabel(groupBox);
       points->setText(":");
       points->setGeometry(QRect(65, 30, 15, 55));
       QFont font_p=points->font();
       font_p.setPointSize(38);
       points->setFont(font_p);

       points1=new QLabel(groupBox);
       points1->setText(":");
       points1->setGeometry(QRect(135, 30, 15, 55));
       QFont font_p1=points1->font();
       font_p1.setPointSize(38);
       points1->setFont(font_p1);
     //  lbls->setStyleSheet("background-color: #FFD700; color: rgb(255, 20, 0)");

////////////////////////////////////////////////////////
       r_on=new QRadioButton(centralWidget);
       r_on->setText("Turn on sounds");
       r_on->setGeometry(QRect(240,85, 100, 20));


       r_off=new QRadioButton(centralWidget);
       r_off->setText("Turn off sounds");
       r_off->setGeometry(QRect(240,115, 100, 25));
 ///////////////////////////////////////////////////////
       //Button for start
       pushButton = new QPushButton(centralWidget);
       pushButton->setText("Start");
       pushButton->setGeometry(QRect(25,200 , 180, 30));

       QFont font_start = pushButton->font();
       font_start.setPointSize(12);
       pushButton->setFont(font_start);

       pushButton->setAutoFillBackground(true);
       pushButton->setStyleSheet("background-color: rgb(14, 20, 228); color: rgb(243,246,40)");
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
 ///////////////////////////////////////////////////////////////////////////////
       setCentralWidget(centralWidget);
       connect(pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
       connect(pushButton_Close,SIGNAL(clicked()),this,SLOT(close()));
       connect(pushButton_Stop,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked_Stop()));
       connect(pushButton_go_on,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked_Go()));
       connect(pushButton_Back,SIGNAL(clicked()),SLOT(on_pushButton_clicked_back()));
       connect(r_off,SIGNAL(clicked()),SLOT(stop_all_music()));
       connect(r_on,SIGNAL(clicked()),SLOT(start_all_music()));
///////////////////////////////////////////////////////////////////////////////
       //Setup the timer object with an interval of one second
           countdown = new QTimer(); //Construct the timer
           countdown->setInterval(1000); //One second interval
           countdown->setSingleShot(false); //Multiple shot. This means that the signal timeout will be signed each second
           connect(countdown,SIGNAL(timeout()),this,SLOT(timeOut())); //Connects the timeout signal to my slot timer

           setWindowTitle("Smart Watch");
        //play playground music
           al=new QMediaPlayer;
           music=new QMediaPlayer(this,  QMediaPlayer::StreamPlayback);
           QMediaPlaylist *playlist = new QMediaPlaylist;
           playlist->addMedia(QUrl("qrc:/sounds/tik.mp3"));
           playlist->setPlaybackMode(QMediaPlaylist::Loop);
           music->setPlaylist(playlist);
           music->setVolume(100);
           r_on->setChecked(true);
}


void  TimerMainWindow::timeOut()
{
    int Hours;
    int Minutes;
    int Seconds;
    if (startMilliseconds - 1000 >= 0) //If not timeout
    {
        startMilliseconds = startMilliseconds - 1000; //Reduce the milliseconds with 1 secod (1000)
        //Convert milliseconds to H:M:S
        Hours = startMilliseconds / (1000*60*60);
        Minutes = (startMilliseconds % (1000*60*60)) / (1000*60);
        Seconds = ((startMilliseconds % (1000*60*60)) % (1000*60)) / 1000;

        //Move the H:M:S to the labels
        lblh->setText(QString::number(Hours));
        lblm->setText(QString::number(Minutes));
        lbls->setText(QString::number(Seconds));
        //play music playground tik


        MusicFunction();

        if (startMilliseconds <=0) //If timeout
        {
            stop_all_music();
            //play music playground for alarm
            al->setMedia(QUrl("qrc:/sounds/al.mp3"));
            al->play();
        }
    }

}

void TimerMainWindow::on_pushButton_clicked()
{
    //Converts the start paramenters into milliseconds
    startMilliseconds = QString(txth->text()).toInt() * 1000 * 60 * 60;
    startMilliseconds = startMilliseconds +  QString(txtm->text()).toInt() * 1000 * 60;
    startMilliseconds = startMilliseconds + QString(txts->text()).toInt() * 1000;
    countdown->start(); //Start the timer
    music->play();
}
void TimerMainWindow::on_pushButton_clicked_Stop()
{
    countdown->stop();
    music->stop();
}
void TimerMainWindow::on_pushButton_clicked_Go()
{
    countdown->start();
}

void TimerMainWindow::on_pushButton_clicked_back()
{
    this->hide();
    MainWindow *s =new MainWindow (this);
    music->stop();
   al->stop();
    s->show();

}
void TimerMainWindow::stop_all_music(void)
{
    music->stop();
}
void TimerMainWindow::start_all_music(void)
{
    music->play();
}
void TimerMainWindow::MusicFunction(void)
{
        connect(r_off,SIGNAL(clicked()),SLOT(stop_all_music()));
       connect(r_on,SIGNAL(clicked()),SLOT(start_all_music()));
}
