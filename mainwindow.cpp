#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Camera.h"
#include "Ray.h"
#include "Window.h"
#include "Scene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    int W = 600;
    int H = 400;

    Point eye = Point(5, 5, 5);
    Point lookAt = Point(0, 0, 0);
    Point up = Point(-5, 10, -5);
    Camera camera = Camera(eye, lookAt, up);
    Window frame = Window(600, 600, 600, 600, 1.7320);
    Scene scene = Scene(camera);

    Point p1 = Point(1, 0, 0);
    Point p2 = Point(0, 1, 0);
    Point p3 = Point(0, 0, 1);

    Triangle tri = Triangle(p1, p2, p3);

    std::cout << tri.get_plane_distance();

    QImage image = QImage(W, H, QImage::Format_RGB32);
    QGraphicsScene * graphic = new QGraphicsScene(this);

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            int r = i % 256;
            int g = j % 256;
            int b = (int)sqrt((double)i*i+(double)j*j)%256;

            Ray ray = camera.createRay(frame.calculateXYZ(i, j));
            Hit hit = scene.touch(ray);
            Color color = hit.getColor();
            QRgb qtRGB = qRgb(color.r, color.g, color.b);

            image.setPixel(i, j, qtRGB);

        }
    }

    graphic->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView->setScene(graphic);
}

MainWindow::~MainWindow()
{
    delete ui;
}
