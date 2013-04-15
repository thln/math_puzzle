#include "graphicswindow.h"
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** Nothing */
void GraphicsWindow::handleTimer() {
}

//clicking will make the timer stop or start
/** Nothing */
void GraphicsWindow::clicker()
{
}

/** Default Constructor*/
GraphicsWindow::GraphicsWindow()  {
    //We need a scene and a view to do graphics in QT
    scene = new QGraphicsScene();
    setScene(scene);
    setWindowTitle( "Programming Assignment #4: Math Puzzles");
    //view = new QGraphicsView( scene );

    //To fill a rectangle use a QBrush. To draw the border of a shape, use a QPen
    QBrush redBrush(Qt::red);
    QPen blackPen(Qt::black);
    QBrush blueBrush(Qt::blue);
    QBrush yellowBrush(Qt::yellow);
    QBrush greenBrush(Qt::green);

  	
}

/** Show
	* Displays the graphicsWindow */
void GraphicsWindow::show() {
    //This is only called once by main. Timers don't start working until
    //we call start
	//timer->start();

    //This is how we get our view displayed.
    this->show();
}

/** getScene
	* Scene Accessor */
QGraphicsScene *GraphicsWindow::getScene()
{
	return scene;
}

/** moveTile
	* @param piece1 The GUITile being moved */
void GraphicsWindow::moveTile(GUITile* piece1)
{
if(!b->solved())
{
	int zeroX = 0;
	int zeroY = 0;
	int tempX = piece1->getxCord();
	int tempY = piece1->getyCord();
	int zero_index = 0;

   int value_ = piece1->getValue();
   b->move(value_);

	for(int j=0; j< b->getSize(); j++)
	{
		if(tiles[j]->getValue() == 0)
		{
			zeroX = tiles[j]->getxCord();
			zeroY = tiles[j]->getyCord();
			zero_index = j;
		}
	}	
	
	if(tempX == zeroX || tempY == zeroY)
	{
		if((tempX+100) == zeroX || (tempX-100) == zeroX)
		{


//			piece1->setPos(zeroX, zeroY);	
//			piece1->setxCord(zeroX);
//			piece1->setyCord(zeroY);


			piece1->setDestinationX(zeroX);
			piece1->setDestinationY(zeroY);
			piece1->setVelocityX((zeroX-tempX)/100);
			piece1->setVelocityY(0);
			piece1->timer->start();
//			piece1->moveTilesAnimate();

			piece1->setxCord(zeroX);
			piece1->setyCord(zeroY);

			tiles[zero_index]->setPos(tempX, tempY);
			tiles[zero_index]->setxCord(tempX);
			tiles[zero_index]->setyCord(tempY);

//			QPointF p(zeroX, zeroY);
//			QRectF r(piece1);
//			r.moveTo(p);
//			setRect( r );
		}
		
		else if((tempY+100) == zeroY || (tempY-100) == zeroY)
		{
			
//			piece1->setPos(zeroX, zeroY);	
//			piece1->setxCord(zeroX);
//			piece1->setyCord(zeroY);

			piece1->setDestinationX(zeroX);
			piece1->setDestinationY(zeroY);
			piece1->setVelocityY((zeroY-tempY)/100);
			piece1->setVelocityX(0);
			piece1->timer->start();
//			piece1->moveTilesAnimate();

			piece1->setxCord(zeroX);
			piece1->setyCord(zeroY);

			tiles[zero_index]->setPos(tempX, tempY);
			tiles[zero_index]->setxCord(tempX);
			tiles[zero_index]->setyCord(tempY);

		}
	
	}
		

	zeroX = 0;
	zeroY = 0;
	tempX = 0;
	tempY = 0;
	zero_index = 0;
}

if (b->solved())
{
	QMessageBox messagebox;
	messagebox.about(0, "Congratulations!", "You have won the game.");
	messagebox.setFixedSize(500,200);
}

}

/** getTiles
	* @return tiles Returns Array of tiles */
GUITile** GraphicsWindow::getTiles()
{
	return tiles;
}

/** getTilesAt
	* @param index The index of the array being accessed
	* @return tiles[index] The tile you want to access */
GUITile* GraphicsWindow::getTilesAt(int index)
{
	return tiles[index];
}

/** getBoard
	* @return b Returns your gameboard */
Board* GraphicsWindow::getBoard()
{
	return b;
}

/** setBoard
	* @param *b_ The Board you want to set your game to*/
void GraphicsWindow::setBoard(Board *b_)
{
	b = b_;
}

/** setTilesAt
	* @param index The index of the GUITile in the array
	* @param *piece The GUITile being set to in the array */
void GraphicsWindow::setTilesAt(int index, GUITile *piece)
{
	tiles[index] = piece;
}

/** Destructor */
GraphicsWindow::~GraphicsWindow()
{
    timer->stop();
    delete timer;
    delete scene;
}

