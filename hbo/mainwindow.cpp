#include "mainwindow.h"
#include <QMouseEvent>
#include <QtMath>
#include <QMediaPlaylist>
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000,670);

    QPixmap pix(":/img/background.png");
    ui->label->setPixmap(pix);
    ui->label->setScaledContents(true);
    ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    setMouseTracking(true);
    ui->centralwidget->setMouseTracking(true);

    player->setMedia(QUrl("qrc:///audio/start.ogg"));
    player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::distance(QPoint a, QPoint b)
{
    return qSqrt((a.x()-b.x())*(a.x()-b.x())+(a.y()-b.y())*(a.y()-b.y()));
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(!finish)
    {
        if(count < 50)
        {
            if(distance(event->pos(),QPoint(53,100))<60)
            {
                player->setMedia(QUrl("qrc:///audio/o1.ogg"));
                player->play();
            }
            else if(distance(event->pos(),QPoint(360,250))<60)
            {
                player->setMedia(QUrl("qrc:///audio/o2.ogg"));
                player->play();
            }
            else if(distance(event->pos(),QPoint(525,84))<45)
            {
                player->setMedia(QUrl("qrc:///audio/o3.ogg"));
                player->play();
            }
            else if(distance(event->pos(),QPoint(638,55))<60)
            {
                player->setMedia(QUrl("qrc:///audio/o4.ogg"));
                player->play();
            }
            else if(distance(event->pos(),QPoint(850,200))<45)
            {
                player->setMedia(QUrl("qrc:///audio/o5.ogg"));
                player->play();
            }
            else if(distance(event->pos(),QPoint(955,190))<45)
            {
                player->setMedia(QUrl("qrc:///audio/o6.ogg"));
                player->play();
            }
            else if(distance(event->pos(),QPoint(770,350))<50)
            {
                player->setMedia(QUrl("qrc:///audio/o7.mp3"));
                player->play();
            }
            else if(distance(event->pos(),QPoint(655,445))<45)
            {
                player->setMedia(QUrl("qrc:///audio/o8.ogg"));
                player->play();
            }
            else if(distance(event->pos(),QPoint(450,450))<45)
            {
                player->setMedia(QUrl("qrc:///audio/o9.ogg"));
                player->play();
            }
            else if(distance(event->pos(),QPoint(560,290))<50)
            {
                player->setMedia(QUrl("qrc:///audio/b.ogg"));
                player->play();
            }
            else if(distance(event->pos(),QPoint(160,300))<50)
            {
                player->setMedia(QUrl("qrc:///audio/g.ogg"));
                player->play();
            }
            count++;
        }
        else
        {
            QMediaPlaylist* playlist = new QMediaPlaylist;
            playlist->addMedia(QUrl("qrc:///audio/final.ogg"));
            playlist->addMedia(QUrl("qrc:///audio/song.mp3"));
            playlist->setCurrentIndex(1);

            player->setPlaylist(playlist);
            player->play();
            QPixmap final(":/img/final.jpg");
            ui->label->setPixmap(final);
            finish= true;
        }

    }
}


