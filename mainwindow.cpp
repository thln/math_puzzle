#include "mainwindow.h"
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QToolBar>
#include <QAction>
#include <QDockWidget>
#include <QWidget>

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
//Radio Buttons
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
//qdw->setWidget(hor


//---------------------------------------------------------------
//Text Boxes

textfields = new formlayout();

lqdw = new QDockWidget();
lqdw->setWidget(textfields);
addDockWidget(Qt::LeftDockWidgetArea, lqdw);
lqdw->setFeatures(QDockWidget::NoDockWidgetFeatures);

//---------------------------------------------------------------

}

MainWindow::~MainWindow()
{
	delete gw;

}

void MainWindow::startGame()
{

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
