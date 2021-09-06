#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define GRAV 9.8
#define TIME 0.1

#include <QMainWindow>
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include <math.h>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void mover();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QPen pen;
    QTimer *timer;
    QGraphicsEllipseItem *ellipsis1;
    QGraphicsLineItem *line;
    double Px;
    double Py;
    double r;
    double cuerda;
};

#endif // MAINWINDOW_H
