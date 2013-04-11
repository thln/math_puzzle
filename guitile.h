#ifndef GUITILE_H
#define GUITILE_H

#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsSceneMouseEvent>
#include "graphicswindow.h"

using namespace std;

class GUITile : public QGraphicsRectItem {
//    Q_OBJECT
    
public:
	GUITile(); //graphicswindow & number
	GUITile(GraphicsWindow *p, int val, double nx, double ny, double w, double h);
	~GUITile();
	QGraphicsSimpleTextItem *numbers;
	void mousePressedEvent(QGraphicsSceneMouseEvent* event);

private:
	GraphicsWindow *parent;
	int value;
	double xCord;
	double yCord;
	double width;
	double height;

public slots:

};

#endif
