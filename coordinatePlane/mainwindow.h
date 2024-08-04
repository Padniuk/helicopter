#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtMath>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initialDraw();
    void transformTo2D();
    void drawUpdate();
    std::vector<std::vector<double>> rotationMatrix(double phi, char axis);

private slots:
    void on_apply_clicked();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;
    double A = 100;
    std::vector<std::vector<double>> cubeCoordinates = {{A,0,0},{A,A,0},{0,A,0},{0,0,0},
                                                        {A,0,A},{A,A,A},{0,A,A},{0,0,A}};
    std::vector<QLineF> cubeEdges;
};
#endif // MAINWINDOW_H
