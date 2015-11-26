#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int W = 600;
    int H = 400;

    QImage image = QImage(W, H, QImage::Format_RGB32);
    QGraphicsScene * graphic = new QGraphicsScene(this);

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            int r = i % 256;
            int g = j % 256;
            int b = (int)sqrt((double)i*i+(double)j*j)%256;

            image.setPixel(i, j, qRgb(r, g, b));

        }
    }

    graphic->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView->setScene(graphic);
}

MainWindow::~MainWindow()
{
    delete ui;
}
