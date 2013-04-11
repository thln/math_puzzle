#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphicswindow.h"
#include <QToolBar>
#include <QAction>

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 250

using namespace std;

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
	MainWindow();
	GraphicsWindow *gw;
	~MainWindow();
	
private:

public slots:
	void startGame();
	void aStarAlg();
	void quitGame();

};

#endif // MAINWINDOW_H
