#include "guitile.h"

using namespace std;

GUITile::GUITile()
{


}

GUITile::GUITile(GraphicsWindow *p, int val, qreal nx, qreal ny, qreal w, qreal h) :  QGraphicsRectItem(0, 0, w, h)
{
	parent = p;
	value = val;
	xCord = nx;
	yCord = ny;
	width = w;
	height = h;
	
	QFont font ("Arial", 60);
	QBrush blackBrush(Qt::black);
	QBrush whiteBrush(Qt::white);
	
	numbers = new QGraphicsSimpleTextItem(QString::number(value), this);
	numbers->setFont(font);
	numbers->setBrush(blackBrush);
	if(value == 0)
	{
	numbers->setBrush(whiteBrush);	
	}
	setPos(xCord, yCord);
	update(xCord, yCord, width, height);
	//numbers->setPos(xCord, yCord);
	//numbers->update(xCord, yCord, width, height);

	
}

GUITile::~GUITile()
{

}

int GUITile::getValue()
{
	return value;
}

int GUITile::getxCord()
{
	return xCord;
}

int GUITile::getyCord()
{
	return yCord;
}

int GUITile::getWidth()
{
	return width;
}

int GUITile::getHeight()
{
	return height;
}

void GUITile::setxCord(double x)
{
	xCord = x;
}

void GUITile::setyCord(double y)
{
	yCord = y;
}

void GUITile::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	parent->moveTile(this);
//	QGraphicsScene::mousePressedEvent(event);
}

