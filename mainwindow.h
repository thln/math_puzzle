#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphicswindow.h"
#include <QToolBar>
#include <QAction>
#include "formlayout.h"
#include <QDockWidget>
#include <QWidget>
//#include "guitile.h"
#include <QRadioButton>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QGraphicsRectItem>
#include "puzzle_solver.h"
#include "puzzle_heur.h"

using namespace std;

/**
	* This class is used to keep track of all widgets and graphicswindow.
	* Inherits from QMainWindow.
	* @author Tam Henry Le Nguyen */

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
	MainWindow(); /** Default Constructor */
	~MainWindow(); /** Default Destructor */
	int getSize(); /** Size Accessor */
	
private:
	QDockWidget *lqdw; /** Left Doct Widget */
	formlayout *textfields; /** A formlayout to take text from */
	QToolBar *tool; /** A toolbar */
	GraphicsWindow *gw; /** Your graphics Window */
	QRadioButton *mhChoice; /** Radio button choice for manhattan heuristic */
	QRadioButton *ooohChoice; /** Radio button choice for out of order heuristic */
	QPlainTextEdit *tempOutput; /** Text Outputter */
//	GUITile *tiles[16];
//	Board *b;
	int size; /** size of board */
	int randMoves; /** number of random moves */
	int randSeed; /** random seed generator */


public slots:
	void startGame(); /** slot for starting the game */
	void cheatGame(); /** slot for starting A* Algorithm */
	void quitGame(); /** slot for quitting the game */
	bool clickedstate(); /** slot to check if it was clicked or not */

};

#endif // MAINWINDOW_H
