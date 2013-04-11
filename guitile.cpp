#include "guitile.h"

using namespace std;

GUITile::GUITile()
{


}

GUITile::GUITile(GraphicsWindow *p, int val, double nx, double ny, double w, double h) :  QGraphicsRectItem(nx, ny, w, h)
{
	parent = p;
	value = val;
	xCord = nx;
	yCord = ny;
	width = w;
	height = h;
	
	numbers = new QGraphicsSimpleTextItem(QString::number(value), this);
	numbers->setBrush(Qt::black);
	numbers->setPos(xCord, yCord);
	numbers->update(xCord, yCord, width, height);

}

GUITile::~GUITile()
{

}

int GUITile::getValue()
{
	return value;
}

double GUITile::getxCord()
{
	return xCord;
}

double GUITile::getyCord()
{
	return yCord;
}

double GUITile::getWidth()
{
	return width;
}

double GUITile::getHeight()
{
	return height;
}

void GUITile::mousePressedEvent(QGraphicsSceneMouseEvent* event)
{
	//parent->moveTile(this);
}

