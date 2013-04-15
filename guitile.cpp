#include "guitile.h"

using namespace std;


/** Default constructor */
GUITile::GUITile()
{


}

/** Init a GUITile with given elements
 * 
 *  @param *p The GraphicsWindow the GUITile is located in  
 *  @param val The Value of the time
 *  @param nx The Upper Left X Coordinate of the Tile
 *  @param ny The Upper Left Y Coordinate of the Tile
 *  @param w The width of the tile
 *  @param h The height of the tile 
 */
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
	//update(xCord, yCord, width, height);


	timer = new QTimer(this);
	timer->setInterval(1);
	connect(timer, SIGNAL(timeout()), this, SLOT(moveTilesAnimate()));	
}

/** Default destructor
	* stops the timer. */
GUITile::~GUITile()
{
	timer->stop();
}

/** value Accessor
	* @return value returns the value of the guitile */
int GUITile::getValue()
{
	return value;
}

/** XCord Accessor
	* @return xCord returns the upper left x Coordinate of the guitile */
int GUITile::getxCord()
{
	return xCord;
}

/** yCord Accessor
	* @return yCord returns the upper left y Coordinate of the guitile */
int GUITile::getyCord()
{
	return yCord;
}

/** Width Accessor
	* @return width returns the width of the guitile */
int GUITile::getWidth()
{
	return width;
}

/** Height Accessor
	* @return height returns the height of the guitile */
int GUITile::getHeight()
{
	return height;
}

/** XCord Resetter
	* @param x The New x Coordinate you want to set */
void GUITile::setxCord(double x)
{
	xCord = x;
}

/** YCord Resetter
	* @param y The New y Coordinate you want to set */
void GUITile::setyCord(double y)
{
	yCord = y;
}

/** Velocity X Resetter
	* @param vx The New x velocity you want to set */
void GUITile::setVelocityX(double vx)
{
	velocityX = vx;
}

/** Velocity Y Resetter
	* @param vy The New y velocity you want to set */
void GUITile::setVelocityY(double vy)
{
	velocityY = vy;
}

/** Destination X Resetter
	* @param dx The New x coordinate Destination you want to set */
void GUITile::setDestinationX( int dx)
{
	destinationX = dx;
}

/** Destination Y Resetter
	* @param dy The New x coordinate Destination you want to set */
void GUITile::setDestinationY( int dy)
{
	destinationY = dy;
}

/** mousePressEvent
	* @param event Does Nothing
	* Registers the tile as click, passes the tile to graphicswindow to move */
void GUITile::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	parent->moveTile(this);
	event = event;
//	QGraphicsScene::mousePressedEvent(event);
}

/** moveTilesAnimate
	*Animates the tile */
void GUITile::moveTilesAnimate()
{
	setPos(xCord+velocityX, yCord+velocityY);
	
	if(xCord == destinationX && yCord==destinationY)
	{
	timer->stop();
	}
}
