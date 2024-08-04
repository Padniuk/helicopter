#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
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
    void drawUpdate(std::vector<std::vector<double>> T);

private slots:
    void on_apply_clicked();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;
    QList<QLineF> linesY;
    QList<QLineF> linesX;
};
#endif // MAINWINDOW_H
