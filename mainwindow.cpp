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

/** Default Constructor */
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

//---------------------------------------------------------------
//Radio Buttons between Heuristics
	mhChoice = new QRadioButton(tr("&Manhattan Heuristic"), this);
	connect(mhChoice, SIGNAL(clicked(bool)), this, SLOT(clickedstate()));

	ooohChoice = new QRadioButton(tr("&Out Of Order Heuristic"), this);
	connect( ooohChoice, SIGNAL(clicked(bool)), this, SLOT(clickedstate()));

	mhChoice->setChecked(false);
	ooohChoice->setChecked(false);

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
	addDockWidget(Qt::RightDockWidgetArea, rqdw);
	rqdw->setFeatures(QDockWidget::NoDockWidgetFeatures);

//--------------------------------------------------------------

}

/** Default Destructor */
MainWindow::~MainWindow()
{
	delete gw;

}

/** Slot to start game */
void MainWindow::startGame()
{


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
		gw->setBoard(new Board(size, randMoves, randSeed));
		int dim = sqrt(size);
		QPen blackPen(Qt::black);
  		QBrush blueBrush(Qt::blue);
  		QBrush whiteBrush(Qt::white);
  		QBrush yellowBrush(Qt::yellow);
  		int index = 0;
  			srand(randSeed);
 
//making the tiles 		
		for(int i=0; i<dim; i++)
		{
			for(int j=0; j<dim; j++)
			{ 
			gw->setTilesAt(index, new GUITile(gw, gw->getBoard()->getTiles()[index], (j*(100)), (i*(100)), 100, 100));
			
			if(gw->getBoard()->getTiles()[index] != 0)
			{
				gw->getTilesAt(index)->setBrush(blueBrush);
				gw->getTilesAt(index)->setPen(blackPen);
			}
			else
			{
				gw->getTilesAt(index)->setBrush(yellowBrush);
				gw->getTilesAt(index)->setPen(blackPen);			
			}
			gw->getScene()->addItem(gw->getTiles()[index]);
			index++;
			}
		}

	}
}

/** Slot to start cheating on game */
void MainWindow::cheatGame()
{
	if(mhChoice->isChecked())
	{
		tempOutput->appendPlainText("Manhattan Cheat!");
		ManhattanHeuristic *MH = new ManhattanHeuristic;
		PuzzleSolver* Answer = new PuzzleSolver(*(gw->getBoard()));
		Answer->run(MH);
		tempOutput->appendPlainText("Try this: ");
		for(int i=( Answer->getSolutions().getSize()-1 ); i>=0; i--)
		{
		tempOutput->appendPlainText(QString::number(Answer->getSolutions()[i]));
		}
	}
	else if(ooohChoice->isChecked())
	{
		tempOutput->appendPlainText("Out of Order Cheat!");
		OutOfPlaceHeuristic *OOPH = new OutOfPlaceHeuristic;
		PuzzleSolver* Answer = new PuzzleSolver(*(gw->getBoard()));
		Answer->run(OOPH);
		tempOutput->appendPlainText("Try this: ");
		for(int i=( Answer->getSolutions().getSize()-1 ); i>=0; i--)
		{
		tempOutput->appendPlainText(QString::number(Answer->getSolutions()[i]));
		}
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

/** Slot to quit game */
void MainWindow::quitGame()
{
	exit(EXIT_FAILURE);
}

/** Slot to check if clicked */
bool MainWindow::clickedstate()
{
	return false;
}
