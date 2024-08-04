#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QVector3D>

#define L 250
#define l 10
#define alpha 210.
#define scaleX 0.5

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->scale(1, -1);

    ui->angle->setText("0");
    ui->oxTrans->setText("0");
    ui->oyTrans->setText("0");
    ui->ozTrans->setText("0");

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
    std::vector<QLineF> axes;
    axes.push_back(QLineF(0,0,L*scaleX*1.75*qCos(qDegreesToRadians(alpha)),L*scaleX*1.75*qSin(qDegreesToRadians(alpha))));
    axes.push_back(QLineF(0,0,0,L));
    axes.push_back(QLineF(0,0,L,0));

    for(auto a : axes) 
    {
        scene->addLine(a,QPen(Qt::red, 2));
    }
    transformTo2D();           
    for(auto c : cubeEdges) 
    {
        scene->addLine(c,QPen(Qt::blue, 2));
    }

}

void MainWindow::drawUpdate()
{
    scene->clear();
    std::vector<QLineF> axes;
    axes.push_back(QLineF(0,0,L*scaleX*1.75*qCos(qDegreesToRadians(alpha)),L*scaleX*1.75*qSin(qDegreesToRadians(alpha))));
    
    axes.push_back(QLineF(0,0,0,L));
    
    axes.push_back(QLineF(0,0,L,0));
    
    for(auto a : axes) 
    {
        scene->addLine(a,QPen(Qt::red, 2));
    }    
    for(auto c : cubeEdges) 
    {
        scene->addLine(c,QPen(Qt::blue, 2));
    }
    axes.clear();
}

void MainWindow::transformTo2D() {
    cubeEdges.clear();
    cubeEdges.push_back(QLineF(cubeCoordinates[0][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[0][1],
                               cubeCoordinates[0][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[0][2],
                               cubeCoordinates[1][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[1][1],
                               cubeCoordinates[1][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[1][2]));
    cubeEdges.push_back(QLineF(cubeCoordinates[0][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[0][1],
                               cubeCoordinates[0][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[0][2],
                               cubeCoordinates[4][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[4][1],
                               cubeCoordinates[4][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[4][2]));
    cubeEdges.push_back(QLineF(cubeCoordinates[1][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[1][1],
                               cubeCoordinates[1][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[1][2],
                               cubeCoordinates[2][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[2][1],
                               cubeCoordinates[2][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[2][2]));
    cubeEdges.push_back(QLineF(cubeCoordinates[1][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[1][1],
                               cubeCoordinates[1][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[1][2],
                               cubeCoordinates[5][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[5][1],
                               cubeCoordinates[5][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[5][2]));
    cubeEdges.push_back(QLineF(cubeCoordinates[2][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[2][1],
                               cubeCoordinates[2][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[2][2],
                               cubeCoordinates[3][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[3][1],
                               cubeCoordinates[3][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[3][2]));
    cubeEdges.push_back(QLineF(cubeCoordinates[2][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[2][1],
                               cubeCoordinates[2][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[2][2],
                               cubeCoordinates[6][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[6][1],
                               cubeCoordinates[6][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[6][2]));
    cubeEdges.push_back(QLineF(cubeCoordinates[3][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[3][1],
                               cubeCoordinates[3][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[3][2],
                               cubeCoordinates[0][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[0][1],
                               cubeCoordinates[0][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[0][2]));
    cubeEdges.push_back(QLineF(cubeCoordinates[3][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[3][1],
                               cubeCoordinates[3][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[3][2],
                               cubeCoordinates[7][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[7][1],
                               cubeCoordinates[7][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[7][2]));
    cubeEdges.push_back(QLineF(cubeCoordinates[4][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[4][1],
                               cubeCoordinates[4][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[4][2],
                               cubeCoordinates[5][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[5][1],
                               cubeCoordinates[5][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[5][2]));                           
    cubeEdges.push_back(QLineF(cubeCoordinates[5][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[5][1],
                               cubeCoordinates[5][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[5][2],
                               cubeCoordinates[6][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[6][1],
                               cubeCoordinates[6][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[6][2]));
    cubeEdges.push_back(QLineF(cubeCoordinates[6][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[6][1],
                               cubeCoordinates[6][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[6][2],
                               cubeCoordinates[7][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[7][1],
                               cubeCoordinates[7][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[7][2]));
    cubeEdges.push_back(QLineF(cubeCoordinates[7][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[7][1],
                               cubeCoordinates[7][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[7][2],
                               cubeCoordinates[4][0]*scaleX*qCos(qDegreesToRadians(alpha))+cubeCoordinates[4][1],
                               cubeCoordinates[4][0]*scaleX*qSin(qDegreesToRadians(alpha))+cubeCoordinates[4][2]));   
}

std::vector<std::vector<double>> MainWindow::rotationMatrix(double phi, char axis) {
    if (axis == 'X') {
        return {{1,0,0},{0,qCos(qDegreesToRadians(phi)),-1*qSin(qDegreesToRadians(phi))},{0,qSin(qDegreesToRadians(phi)),qCos(qDegreesToRadians(phi))}};
    }
    else if (axis == 'Y') {
        return {{qCos(qDegreesToRadians(phi)),0,qSin(qDegreesToRadians(phi))},{0,1,0},{-1*qSin(qDegreesToRadians(phi)),0,qCos(qDegreesToRadians(phi))}};
    }
    else if (axis == 'Z') {
        return {{qCos(qDegreesToRadians(phi)),-1*qSin(qDegreesToRadians(phi)),0},{qSin(qDegreesToRadians(phi)),qCos(qDegreesToRadians(phi)),0},{0,0,1}};
    }
    else {
        return {{1,0,0},{0,1,0},{0,0,1}};
    }
}

void MainWindow::on_apply_clicked()
{
    std::vector<std::vector<double>> oldCoordinates = cubeCoordinates;
    std::vector<std::vector<double>> rotMat;
    if (ui->oxRot->isChecked()) {
        rotMat = rotationMatrix(ui->angle->text().toDouble(),'X');
    }
    else if (ui->oyRot->isChecked()) {
        rotMat = rotationMatrix(ui->angle->text().toDouble(),'Y');
    } 
    else if (ui->ozRot->isChecked()) {
        rotMat = rotationMatrix(ui->angle->text().toDouble(),'Z');
    }
    else {
        rotMat = {{1,0,0},{0,1,0},{0,0,1}};
    }
    for(int i=0; i<cubeCoordinates.size();i++) {
        cubeCoordinates[i] = {rotMat[0][0]*oldCoordinates[i][0]+rotMat[0][1]*oldCoordinates[i][1]+rotMat[0][2]*oldCoordinates[i][2]+ui->oxTrans->text().toDouble(),
                              rotMat[1][0]*oldCoordinates[i][0]+rotMat[1][1]*oldCoordinates[i][1]+rotMat[1][2]*oldCoordinates[i][2]+ui->oyTrans->text().toDouble(),
                              rotMat[2][0]*oldCoordinates[i][0]+rotMat[2][1]*oldCoordinates[i][1]+rotMat[2][2]*oldCoordinates[i][2]+ui->ozTrans->text().toDouble()};
    }
    
    transformTo2D();
    drawUpdate();
}