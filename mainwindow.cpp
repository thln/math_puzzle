#include "mainwindow.h"
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QToolBar>
#include <QAction>

using namespace std;

//MainWindow now
MainWindow::MainWindow()
{
	gw = new GraphicsWindow;
	setCentralWidget(gw);

//---------------------------------------------------------------
//Toolbar
QToolBar *tool = new QToolBar;

//Actions
QAction *startGameAction = new QAction(tr("&Start Game"), this);
tool->addAction( startGameAction );
connect( startGameAction, SIGNAL(triggered() ), this, SLOT(startGame() ));

QAction *aStarAlgAction = new QAction( tr("&A Star Algorithm"), this );
tool->addAction( aStarAlgAction );
connect( aStarAlgAction, SIGNAL(triggered() ), this, SLOT( aStarAlg() ));

QAction *quitGameAction = new QAction( tr("&Quit Game"), this );
tool->addAction( quitGameAction );
connect( quitGameAction, SIGNAL(triggered() ), this, SLOT(quitGame() ));

tool->show();
//---------------------------------------------------------------
}

MainWindow::~MainWindow()
{
	delete gw;

}

void MainWindow::startGame()
{

}

void MainWindow::aStarAlg()
{

}

void MainWindow::quitGame()
{
	exit(EXIT_FAILURE);
}
