#include "graphicswindow.h"
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GraphicsWindow::handleTimer() {
//  item->move(WINDOW_MAX_X, WINDOW_MAX_Y);
    counter++;


	QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QBrush yellowBrush(Qt::yellow);
    QBrush greenBrush(Qt::green);

	enum Colors
	{
		COLOR_RED,
		COLOR_BLUE,
		COLOR_YELLOW,
		COLOR_GREEN,
	};
	
	for(int i=0; i<RectangleVector.size(); i++)
	{
		RectangleVector[i]->move(WINDOW_MAX_X, WINDOW_MAX_Y);
	}

	Colors eColors = Colors(rand()%4);

	//Generate random squares
	srand(time(NULL));
	
	if(counter%50 == 0)
	{
		item = new BouncingRectangle(rand()%200, rand()%200, rand()%200, rand()%200, rand()%5, rand()%5);
		switch(eColors)
		{
			case COLOR_RED:
				item->setBrush(redBrush);
				scene->addItem(item);
				break;
			case COLOR_BLUE:
				item->setBrush(blueBrush);
				scene->addItem(item);
				break;
			case COLOR_YELLOW:
				item->setBrush(yellowBrush);
				scene->addItem(item);
				break;
			case COLOR_GREEN:
				item->setBrush(greenBrush);
				scene->addItem(item);
				break;
		}
		RectangleVector.push_back(item);
	}

}

//clicking will make the timer stop or start
void GraphicsWindow::clicker()
{
	if(timer->isActive())
	{
		timer->stop();
	}
	else if(!timer->isActive())
	{
		timer->start();
	}
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

    //First 2 arguments are the x, y, of the upper left of the rectangle.
    //The second 2 arguments are the width and height
    //The last 2 arguments are the velocity in the x, and y, directions
   // Inserting boxes into a 360x360 pixel area
    box1 = new QGraphicsRectItem( 10.0, 10.0, 180.0, 180.0);
    box1->setBrush(redBrush);
    box1->setPen(blackPen);
    scene->addItem(box1);
    box2 = new QGraphicsRectItem( 190.0, 10.0, 180.0, 180.0);
    box2->setBrush(redBrush);
    box2->setPen(blackPen);
    scene->addItem(box2);
    box3 = new QGraphicsRectItem( 10.0, 190.0, 180.0, 180.0);
    box3->setBrush(redBrush);
    box3->setPen(blackPen);
    scene->addItem(box3);
    box4 = new QGraphicsRectItem( 190.0, 190.0, 180.0, 180.0);
    box4->setBrush(redBrush);
    box4->setPen(blackPen);
    scene->addItem(box4);

    //This sets the size of the window and gives it a title.
    setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );

    //This is how we do animation. We use a timer with an interval of 5 milliseconds
    //We connect the signal from the timer - the timeout() function to a function
    //of our own - called handleTimer - which is in this same MainWindow class
//    timer = new QTimer(this);
//    timer->setInterval(5);
    
    //making a new button and giving it characteristics
//    buttonclick = new QPushButton(this);
//    buttonclick->setText("Start or Stop");
//    buttonclick->setGeometry(0, 0, 180, 60);
//    connecting timer to handletimer and buttonclick to a clicker via clicked
//    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
//    connect(buttonclick, SIGNAL(clicked()), this, SLOT(clicker()));


	
}


void GraphicsWindow::show() {
    //This is only called once by main. Timers don't start working until
    //we call start
    timer->start();

    //This is how we get our view displayed.
    this->show();
}

QGraphicsScene *GraphicsWindow::getScene()
{
	return scene;
}

void GraphicsWindow::move(int tile)
{
/*
  int dim = static_cast<int>(sqrt(size_));

	//checking if tile is in the game or not
	if(tile<-1 || tile>(size_))
	{
		cout << "Tile does not exist." << endl;
	}
	else{
	
	//looping through all tiles
	//variables keeping track of tiles to swap
	int a, b;
	for(int i=0; i<size_; i++)
	{
		//finding shown tile
		if(tile == tiles_[i])
		{
		a = i;
		}
		//finding zero tile
		if(0 == tiles_[i])
		{
		b = i;
		}
		
	}
	//Checks if two tiles are next to each other
	if( a == b+sqrt(size_) || a == b-sqrt(size_) || a == b+1 || a == b-1)
	{
	//Checks if numbers are on the "edge"
		//Special 2 square case
		if(size_ == 4)
		{
			if( (a==0 && b==3) || (b==0 && a==3) || (a==1 && b==2) || (b==1 && a==2) )
			{
			cout << "Incorrect tile movement." << endl;
			}
			else
			{
			tiles_[a] = 0;
	 		tiles_[b] = tile;
			}
		}
		else if((a%dim == 0 && b%dim == dim-1) || (b%dim == 0 && a%dim == dim-1))
		{
			cout << "Incorrect tile movement." << endl;
		}
		else{
	 		tiles_[a] = 0;
	 		tiles_[b] = tile;
	 	}
	}
	}
*/
}

GraphicsWindow::~GraphicsWindow()
{
    timer->stop();
    delete timer;
    delete item;
    delete scene;
}

