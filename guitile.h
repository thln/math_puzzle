#ifndef GUITILE_H
#define GUITILE_H

#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsSceneMouseEvent>
#include "graphicswindow.h"
#include <QFont>


using namespace std;

class GraphicsWindow;


class GUITile : public QGraphicsRectItem {
//    Q_OBJECT
    
public:
	GUITile(); //graphicswindow & number
	GUITile(GraphicsWindow *p, int val, qreal nx, qreal ny, qreal w, qreal h);
	~GUITile();
//	QGraphicsSimpleTextItem *numbers;
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	int getValue();
	int getxCord();
	int getyCord();
	int getWidth();
	int getHeight();
	void setxCord(double x);
	void setyCord(double y);	

private:
	GraphicsWindow *parent;
	QGraphicsSimpleTextItem* numbers;
	int value;
	int xCord;
	int yCord;
	int width;
	int height;

public slots:

};

#endif
