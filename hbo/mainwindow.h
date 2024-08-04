#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include "QMediaPlayer"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mouseMoveEvent(QMouseEvent *event);
    double distance(QPoint a, QPoint b);

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player = new QMediaPlayer();
    int count =0;
    bool finish = false;
};
#endif // MAINWINDOW_H
