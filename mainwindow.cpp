#include "mainwindow.h"
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QToolBar>
#include <QAction>
#include <QDockWidget>
#include <QWidget>
#include <QString>
#include <math.h>
#include "board.h"

using namespace std;

//MainWindow now
MainWindow::MainWindow()
{
	gw = new GraphicsWindow;
	setCentralWidget(gw);

//---------------------------------------------------------------
//Toolbar
	tool = new QToolBar;

//Actions
	QAction *startGameAction = new QAction(tr("&Start Game"), this);
	tool->addAction( startGameAction );
	connect( startGameAction, SIGNAL(triggered() ), this, SLOT(startGame() ));

	QAction *cheatGameAction = new QAction(tr("&Cheat Game"), this);
	tool->addAction( cheatGameAction );
	connect( cheatGameAction, SIGNAL(triggered() ), this, SLOT( cheatGame() ));

	QAction *quitGameAction = new QAction(tr("&Quit Game"), this);
	tool->addAction( quitGameAction );
	connect( quitGameAction, SIGNAL(triggered() ), this, SLOT(quitGame() ));

//tool->show();
//---------------------------------------------------------------
//Radio Buttons between Heuristics
	mhChoice = new QRadioButton(tr("&Manhattan Heuristic"), this);
	connect(mhChoice, SIGNAL(clicked(bool)), this, SLOT(clickedstate()));

	ooohChoice = new QRadioButton(tr("&Out Of Order Heuristic"), this);
	connect( ooohChoice, SIGNAL(clicked(bool)), this, SLOT(clickedstate()));

	mhChoice->setChecked(false);
	ooohChoice->setChecked(false);

	//horlayout = new QHBoxLayout();
	tool->addWidget(mhChoice);
	tool->addWidget(ooohChoice);

	tool->show();

	QDockWidget *tqdw = new QDockWidget();
	tqdw->setWidget(tool);
	addDockWidget(Qt::TopDockWidgetArea, tqdw);
	tqdw->setFeatures(QDockWidget::NoDockWidgetFeatures);


//---------------------------------------------------------------
//Text Boxes to store values for starting game

	textfields = new formlayout();

	lqdw = new QDockWidget();
	lqdw->setWidget(textfields);
	addDockWidget(Qt::LeftDockWidgetArea, lqdw);
	lqdw->setFeatures(QDockWidget::NoDockWidgetFeatures);

//---------------------------------------------------------------
//Temporary Messages to text outputs

	tempOutput = new QPlainTextEdit();
	tempOutput->setReadOnly(true);

	QDockWidget *rqdw = new QDockWidget();
	rqdw->setWidget(tempOutput);
	addDockWidget(Qt::BottomDockWidgetArea, rqdw);
	rqdw->setFeatures(QDockWidget::NoDockWidgetFeatures);

//--------------------------------------------------------------

}

MainWindow::~MainWindow()
{
	delete gw;

}

void MainWindow::startGame()
{

//	delete gw;
//	gw = new GraphicsWindow;
//	setCentralWidget(gw);
	

//Takes inputs from lineedits and store them in respective values
	size = textfields->getSizeEdit()->text().toInt();
	randMoves = textfields->getStartMovesEdit()->text().toInt();
	randSeed = textfields->getRandomSeedEdit()->text().toInt();
	
//Printing out error messages if any
	tempOutput->appendPlainText("Size: "+ QString::number(size));
	tempOutput->appendPlainText("# of random Moves: "+ QString::number(randMoves));	
	tempOutput->appendPlainText("random Seed Number: "+ QString::number(randSeed));

	if(randMoves <= 0)
	{
		tempOutput->appendPlainText("Error: Needs a Start Move value greater than 0.");
	//	return 0;
	}
	else if(randSeed <= 0)
	{
		tempOutput->appendPlainText("Error: Needs a Random Seed value greater than 0.");
	//	return 0;
	}
	else if(size != 9 && size != 16)
	{
		tempOutput->appendPlainText("Error: Size can only be of 3x3(9) or 4x4(16).");
	//	return 0;
	}
	else
	{
		tempOutput->appendPlainText("Game will now begin!");
		gw->setBoard(new Board(size, randMoves, randSeed));
		int dim = sqrt(size);
		QPen blackPen(Qt::black);
  		QBrush blueBrush(Qt::blue);
  		QBrush whiteBrush(Qt::white);
  		QBrush yellowBrush(Qt::yellow);
  		int index = 0;
  			srand(randSeed);
//  		tempOutput->appendPlainText("DIM: "+ QString::number(dim));
 
//making the tiles 		
		for(int i=0; i<dim; i++)
		{
			for(int j=0; j<dim; j++)
			{ 
			gw->setTilesAt(index, new GUITile(gw, gw->getBoard()->getTiles()[index], (j*(100)), (i*(100)), 100, 100));
			
			if(gw->getBoard()->getTiles()[index] != 0)
			{
			//supposed to be -> ?
				gw->getTilesAt(index)->setBrush(blueBrush);
				gw->getTilesAt(index)->setPen(blackPen);
			}
			else
			{
			//	gw->getTilesAt(index)->setBrush(whiteBrush);
				gw->getTilesAt(index)->setBrush(yellowBrush);
				gw->getTilesAt(index)->setPen(blackPen);			
			}
			gw->getScene()->addItem(gw->getTiles()[index]);
//			gw->getScene()->addItem(tiles[index]);
			index++;
//			tempOutput->appendPlainText(QString::number(index));
			}
//		tempOutput->appendPlainText(QString::number(index));
		}

	for(int i=0; i<size; i++)
	{
	tempOutput->appendPlainText(QString::number(gw->getTilesAt(i)->getValue()));
	tempOutput->appendPlainText("X Coordinate: " + QString::number(gw->getTilesAt(i)->getxCord()));
	tempOutput->appendPlainText("Y Coordinate: " + QString::number(gw->getTilesAt(i)->getyCord()));
	}

	}
}

/*
GUITiles* MainWindow::getTiles()
{
	return tiles[];
}

Board* MainWindow::getBoard()
{
	return b;
}

int MainWindow::getSize()
{
	return size;
}
*/

void MainWindow::cheatGame()
{
	if(mhChoice->isChecked())
	{
		tempOutput->appendPlainText("Manhattan Cheat!");
	}
	else if(ooohChoice->isChecked())
	{
		tempOutput->appendPlainText("Out of Order Cheat!");
	}
	else if(size != 9 && size != 16)
	{
		tempOutput->appendPlainText("Please start the game first.");
	}
	else
	{
		tempOutput->appendPlainText("Please choose a cheat first.");
	}


}

void MainWindow::quitGame()
{
	exit(EXIT_FAILURE);
}

bool MainWindow::clickedstate()
{
	return false;
}
