#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <vector>
#include <QFormLayout>
#include <QLineEdit>
#include <QDockWidget>
#include <QLabel>
#include <QGraphicsRectItem>

#include "bouncingrectangle.h"

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 250

using namespace std;

class GraphicsWindow : public QGraphicsView {
    Q_OBJECT
    
public:
    explicit GraphicsWindow();
    ~GraphicsWindow();

    void show();
    
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    QGraphicsRectItem *box1;
    QGraphicsRectItem *box2;
    QGraphicsRectItem *box3;
    QGraphicsRectItem *box4;    
    
    BouncingRectangle *item;
    	QPushButton *buttonclick;
    	vector<BouncingRectangle*> RectangleVector;
    	int counter;

public slots:
    void handleTimer();
	void clicker();

};

#endif
