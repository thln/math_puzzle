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
	connect(mhChoice, SIGNAL(clicked(bool)), this, SLOT(clickedstate(bool)));
	mhChoice->setAutoExclusive(false);

	ooohChoice = new QRadioButton(tr("&Out Of Order Heuristic"), this);
	connect( ooohChoice, SIGNAL(clicked(bool)), this, SLOT(clickedstate(bool)));
	ooohChoice->setAutoExclusive(false);

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
//Takes inputs from lineedits and store them in respective values
	int size = textfields->getSizeEdit()->text().toInt();
	int randMoves = textfields->getStartMovesEdit()->text().toInt();
	int randSeed = textfields->getRandomSeedEdit()->text().toInt();
	
//Printing out messages
	tempOutput->appendPlainText("Size: "+ QString::number(size));
	tempOutput->appendPlainText("# of random Moves: "+ QString::number(randMoves));	
	tempOutput->appendPlainText("random Seed Number: "+ QString::number(randSeed));

	if(randMoves <= 0)
	{
		tempOutput->appendPlainText("Error: Needs a Start Move value greater than 0.");
	}
	else if(randSeed <= 0)
	{
		tempOutput->appendPlainText("Error: Needs a Random Seed value greater than 0.");
	}
	else if(size != 9 && size != 16)
	{
		tempOutput->appendPlainText("Error: Size can only be of 3x3(9) or 4x4(16).");
	}
	else
	{
		tempOutput->appendPlainText("Game will now begin!");
		int dim = sqrt(size);
		QPen blackPen(Qt::black);
  		QBrush blueBrush(Qt::blue);
  		int index = 0;
//  		tempOutput->appendPlainText("DIM: "+ QString::number(dim));
  		
		for(int i=0; i<dim; i++)
		{
			for(int j=0; j<dim; j++)
			{ //360.0/dim
			tiles[index] = new GUITile(gw, index, 10.0+(j*(360.0/dim)), 10.0+(i*(360.0/dim)), 360.0/dim, 360.0/dim);
			
			if(index != 0)
			{
				tiles[index]->setBrush(blueBrush);
				tiles[index]->setPen(blackPen);
			}
			gw->getScene()->addItem(tiles[index]);
			index++;
//			tempOutput->appendPlainText(QString::number(index));
			}
//		tempOutput->appendPlainText(QString::number(index));

//	srand(randSeed);
//	rand()%size;
		}
	}
	
}

void MainWindow::cheatGame()
{

}

void MainWindow::quitGame()
{
	exit(EXIT_FAILURE);
}

bool MainWindow::clickedstate()
{
	return false;
}
