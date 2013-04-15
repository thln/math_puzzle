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

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
	MainWindow();
	~MainWindow();
//	Board* getBoard();
//	GUITile* getTiles();
	int getSize();
	
private:
	QDockWidget *lqdw;
	formlayout *textfields;
	QToolBar *tool;
	GraphicsWindow *gw;
	QRadioButton *mhChoice;
	QRadioButton *ooohChoice;
	QHBoxLayout *horlayout;
	QPlainTextEdit *tempOutput;
//	GUITile *tiles[16];
//	Board *b;
	int size;
	int randMoves;
	int randSeed;


public slots:
	void startGame();
	void cheatGame();
	void quitGame();
	bool clickedstate();

};

#endif // MAINWINDOW_H
