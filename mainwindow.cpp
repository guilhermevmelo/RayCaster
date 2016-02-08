#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Camera.h"
#include "Ray.h"
#include "Window.h"
#include "Scene.h"
#include "Cube.h"
#include "Matrix.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    int W = 600;
    int H = 400;

    Point eye = Point(0.0, 0.0, 100.0);
    Point lookAt = Point(0.0, 0.0, 0.0);
    Point up = Point(0.0, 1.0, 0.0);
    Camera camera = Camera(eye, lookAt, up);

    Matrix WtoC = Matrix::world_camera(camera);
    Matrix CtoW = Matrix::camera_world(camera);

    Window frame = Window(600, 600, 100, 100, 30);
    Scene scene = Scene(camera, Color(255, 255, 255));

    Light ambient = Light(Point(100, 100, 100), Color(0, 0, 255));
    scene.addLight(ambient);

    Point p1 = Point(10, 0, 0);
    Point p2 = Point(0, 10, 0);
    Point p3 = Point(0, 0, 10);
    Point p4 = Point(5, 5, 5);

    Material material1 = Material(0.9, 0.5, 0.8);
    Triangle f1 = Triangle(p1, p2, p3);
    Triangle f2 = Triangle(p2, p4, p3);
    Triangle f3 = Triangle(p1, p4, p2);
    Triangle f4 = Triangle(p1, p3, p4);

    Object obj1 = Object(material1);
    obj1.addTriangle(f1);
    obj1.addTriangle(f2);
    obj1.addTriangle(f3);
    obj1.addTriangle(f4);

    obj1.applyTransformation(WtoC);

    scene.addObject(obj1);

//    Material m2 = Material(0.9, 0.9, 0.9);
//    Cube c1 = Cube(Point(5, 0, 0), 13, 15, 20, m2);
//    scene.addObject(c1);

    //std::cout << f1.get_plane_distance() << std::endl;

    QImage image = QImage(W, H, QImage::Format_RGB32);
    QGraphicsScene * graphic = new QGraphicsScene(this);

    //std::cout << "About to enter main loop" << std::endl;

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            int r = i % 256;
            int g = j % 256;
            int b = (int)sqrt((double)i*i+(double)j*j)%256;

            //std::cout << "\nWe are now evaluating the colour of pixel: i = " << i << ", j = " << j << std::endl;

            Ray ray = camera.createRay(frame.calculateXYZ(i, j));
            //std::cout << "We have the ray, let's see if it hits" << std::endl;
            Color color = scene.touch(ray);
            //std::cout << "Now let's colour that pixel" << std::endl;

            QRgb qtRGB = qRgb(color.r, color.g, color.b);

            //QRgb qtRGB = qRgb(r, g, b);
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
