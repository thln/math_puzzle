#include "graphicswindow.h"
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GraphicsWindow::handleTimer() {
//  item->move(WINDOW_MAX_X, WINDOW_MAX_Y);
//    counter++;
}

//clicking will make the timer stop or start
void GraphicsWindow::clicker()
{
//	if(timer->isActive())
//	{
//		timer->stop();
//	}
//	else if(!timer->isActive())
//	{
//		timer->start();
//	}
}

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


void GraphicsWindow::show() {
    //This is only called once by main. Timers don't start working until
    //we call start
//    timer->start();

    //This is how we get our view displayed.
    this->show();
}

QGraphicsScene *GraphicsWindow::getScene()
{
	return scene;
}

void GraphicsWindow::moveTile(GUITile* piece1)
{
	int zeroX = 0;
	int zeroY = 0;
	int tempX = piece1->getxCord();
	int tempY = piece1->getyCord();
	int zero_index = 0;
	int piece_index = 0;

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
	
	for(int j=0; j< b->getSize(); j++)
	{
		if(tiles[j]->getValue() == value_)
		{
			piece_index = j;
		}
	}
/*	
	int xDiff = tempX-zeroX;
	int yDiff = tempY-zeroY;
	if( (xDiff==0 && yDiff==100) || (xDiff==0 && yDiff==-100) || (xDiff==100 && yDiff==0) || (xDiff==-100 && yDiff==0))
	{
			tiles[zero_index]->setPos(tempX, tempY);
			tiles[zero_index]->setxCord(tempX);
			tiles[zero_index]->setyCord(tempY);
			//tiles[zero_index]->update(tempX, tempY, 100, 100);
			piece1->setPos(zeroX, zeroY);	
			//piece1->update(tempX, tempY, 100, 100);
			piece1->setxCord(tempX);
			piece1->setyCord(tempY);
			
			GUITile *temp;
			temp = tiles[zero_index];
			tiles[zero_index] = tiles[piece_index];
			tiles[piece_index] = temp;
			
//			scene->addItem(piece1);
//			scene->addItem(tiles[zero_index]);
	} 
*/	
	
	
	
	if(tempX == zeroX || tempY == zeroY)
	{
		if((tempX+100) == zeroX || (tempX-100) == zeroX)
		{
			tiles[zero_index]->setPos(tempX, tempY);
			tiles[zero_index]->setxCord(tempX);
			tiles[zero_index]->setyCord(tempY);
			piece1->setPos(zeroX, zeroY);	
			piece1->setxCord(tempX);
			piece1->setyCord(tempY);
			
			GUITile *temp;
			temp = tiles[zero_index];
			tiles[zero_index] = tiles[piece_index];
			tiles[piece_index] = temp;
		}
		else if((tempY+100) == zeroY || (tempY-100) == zeroY)
		{
		QBrush redBrush(Qt::red);
		QBrush greenBrush(Qt::green);
			tiles[zero_index]->setPos(tempX, tempY);
			tiles[zero_index]->setxCord(tempX);
			tiles[zero_index]->setyCord(tempY);
			tiles[zero_index]->setBrush(redBrush);
			
			piece1->setPos(zeroX, zeroY);	
			piece1->setxCord(tempX);
			piece1->setyCord(tempY);
			piece1->setBrush(greenBrush);
			
			GUITile *temp;
			temp = tiles[zero_index];
			tiles[zero_index] = tiles[piece_index];
			tiles[piece_index] = temp;	
		}
	
	}
		

	zeroX = 0;
	zeroY = 0;
	tempX = 0;
	tempY = 0;
	zero_index = 0;
	piece_index = 0;

}

GUITile** GraphicsWindow::getTiles()
{
	return tiles;
}

GUITile* GraphicsWindow::getTilesAt(int index)
{
	return tiles[index];
}

Board* GraphicsWindow::getBoard()
{
	return b;
}

void GraphicsWindow::setBoard(Board *b_)
{
	b = b_;
}

void GraphicsWindow::setTilesAt(int index, GUITile *piece)
{
	tiles[index] = piece;
}

/*
int GraphicsWindow::getSize()
{
	return size;
}

int GraphicsWindow::getRandMoves()
{
	return randMoves;
}

int GraphicsWindow::getRandSeed()
{
	return randSeed;
}
*/

GraphicsWindow::~GraphicsWindow()
{
    timer->stop();
    delete timer;
//    delete item;
    delete scene;
}

