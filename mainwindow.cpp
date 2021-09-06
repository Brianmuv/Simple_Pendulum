#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    scene = new QGraphicsScene(this);
    scene-> setSceneRect(-300,-200,700,600);
    //ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/fondo")));


    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width()+100,ui->graphicsView->height()+100);


    ui->graphicsView->setScene(scene);

    QBrush brush(Qt::green);
    pen.setColor(Qt::blue);  //Pinceles para  Bordo de la bola final y cuerda
    pen.setWidth(5);

    Px =250.0;
    Py = 50.0;
    r = 25.0;


    ellipsis1 = scene->addEllipse(Px,Py,r,r,pen,brush);

    line = scene->addLine(0,0,Px + (r/2),Py + (r/2));

    line->setPos(50,50);


    //Definición de Cuerda
    cuerda = sqrt(pow(Px, 2.0)+ pow(Py, 2.0));

    connect(timer,SIGNAL(timeout()),this,SLOT(mover()));
    timer->start(15);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ellipsis1;
    delete line;
    delete scene;
}

void MainWindow::mover(){
    double angle = asin((Px) / cuerda);
    double a_x = -GRAV * sin(angle);
    static double vx = 0;
    vx += a_x * TIME;
    static double w = 0;
    w = vx / cuerda;
    double ace_angle = w / TIME;
    angle = angle + w * TIME  + (ace_angle / 2 ) * TIME * TIME;

    Px = cuerda * sin(angle);
    Py = cuerda * cos(angle);

    //¿¿¿Why should I substract -200????
    ellipsis1->setPos(Px - 200, Py);
   // para que funcione el movimiento
   line->setLine(0,0, Px+(r/2), Py+(r/2));
}


