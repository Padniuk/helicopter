#include "mainwindow.h"
#include "./ui_mainwindow.h"

#define N 10
#define px 35
#define py 35

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->scale(1, -1);

    ui->Xx->setMaximum(px*N);
    ui->Xy->setMaximum(px*N);
    ui->Yx->setMaximum(py*N);
    ui->Yy->setMaximum(py*N);
    ui->wX->setMaximum(N/2);
    ui->wY->setMaximum(N/2);
    ui->w0->setMaximum(N/2);
    ui->Ox->setMaximum(px*N/2);
    ui->Oy->setMaximum(py*N/2);

    scene = new QGraphicsScene(this);
    scene->clear();
    ui->graphicsView->setScene(scene);
    initialDraw();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialDraw()
{
    QLineF line;
    for(int i=0; i<=10;i++)
    {
        if(i==0)
        {
            line.setLine(0,0,N*px,0);
            scene->addLine(line,QPen(Qt::red, 2));
            linesX.append(line);
            line.setLine(0,0,0,N*py);
            scene->addLine(line,QPen(Qt::green, 2));
            linesY.append(line);
        }
        else
        {
            line.setLine(0,i*py,N*px,i*py);
            scene->addLine(line,QPen(Qt::gray, 0.5, Qt::DashLine));
            linesX.append(line);
            line.setLine(i*px,0,i*px,N*py);
            scene->addLine(line,QPen(Qt::gray, 0.5, Qt::DashLine));
            linesY.append(line);
        }
    }
}

void MainWindow::drawUpdate(std::vector<std::vector<double>> T)
{
    scene->clear();

    double Xbegin, Xend, Ybegin, Yend;

    for(int i=0; i<=10;i++)
    {
        Xbegin = linesX.at(i).x1()/px;
        Ybegin = linesX.at(i).y1()/py;
        Xend = linesX.at(i).x2()/px;
        Yend = linesX.at(i).y2()/py;

        linesX[i].setLine((Xbegin*T[0][0]+Ybegin*T[1][0]+T[2][0])/(T[0][2]*Xbegin+T[1][2]*Ybegin+T[2][2]),
                          (Xbegin*T[0][1]+Ybegin*T[1][1]+T[2][1])/(T[0][2]*Xbegin+T[1][2]*Ybegin+T[2][2]),
                          (Xend*T[0][0]+Yend*T[1][0]+T[2][0])/(T[0][2]*Xend+T[1][2]*Yend+T[2][2]),
                          (Xend*T[0][1]+Yend*T[1][1]+T[2][1])/(T[0][2]*Xend+T[1][2]*Yend+T[2][2]));

        Xbegin = linesY.at(i).x1()/px;
        Ybegin = linesY.at(i).y1()/py;
        Xend = linesY.at(i).x2()/px;
        Yend = linesY.at(i).y2()/py;

        linesY[i].setLine((Xbegin*T[0][0]+Ybegin*T[1][0]+T[2][0])/(T[0][2]*Xbegin+T[1][2]*Ybegin+T[2][2]),
                          (Xbegin*T[0][1]+Ybegin*T[1][1]+T[2][1])/(T[0][2]*Xbegin+T[1][2]*Ybegin+T[2][2]),
                          (Xend*T[0][0]+Yend*T[1][0]+T[2][0])/(T[0][2]*Xend+T[1][2]*Yend+T[2][2]),
                          (Xend*T[0][1]+Yend*T[1][1]+T[2][1])/(T[0][2]*Xend+T[1][2]*Yend+T[2][2]));
        QLineF line;
        if(i==0)
        {
            line = linesX[i];
            scene->addLine(line,QPen(Qt::red, 2));
            line = linesY[i];
            scene->addLine(line,QPen(Qt::green, 2));
        }
        else
        {
            line = linesX[i];
            scene->addLine(line,QPen(Qt::gray, 0.5, Qt::DashLine));
            line = linesY[i];
            scene->addLine(line,QPen(Qt::gray, 0.5, Qt::DashLine));
        }
    }
}

void MainWindow::on_apply_clicked()
{
    std::vector<std::vector<double>> T = {{1,0,0},{0,1,0},{0,0,1}};

    T[0][0] = ui->Xx->value()*ui->wX->value();
    T[0][1] = ui->Xy->value()*ui->wX->value();
    T[0][2] = ui->wX->value();
    T[1][0] = ui->Yx->value()*ui->wY->value();
    T[1][1] = ui->Yy->value()*ui->wY->value();
    T[1][2] = ui->wY->value();
    T[2][0] = ui->Ox->value()*ui->w0->value();
    T[2][1] = ui->Oy->value()*ui->w0->value();
    T[2][2] = ui->w0->value();
    drawUpdate(T);
}

