#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <vector>
#include <QFormLayout>
#include <QLineEdit>
#include <QDockWidget>
#include <QLabel>
#include <QGraphicsRectItem>
#include "guitile.h"
#include "board.h"

using namespace std;

class GUITile;

class GraphicsWindow : public QGraphicsView {
    Q_OBJECT
    
public:
    explicit GraphicsWindow();
    ~GraphicsWindow();
	QGraphicsScene *getScene();
  	void show();
    	void moveTile(GUITile *piece1);
	Board* getBoard();
	GUITile** getTiles();
	void setBoard(Board *b_);
	GUITile* getTilesAt(int index);
	void setTilesAt(int index, GUITile *piece);
//	int getSize();
//	int getRandMoves();
//	int getRandSeed();
    
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    
    GUITile *tiles[16];
	Board *b;
//	int size;
//	int randMoves;
//	int randSeed;
	
//    QGraphicsRectItem *box1;
//    QGraphicsRectItem *box2;
//    QGraphicsRectItem *box3;
//    QGraphicsRectItem *box4;    
    
    	QPushButton *buttonclick;
    	int counter;

public slots:
    void handleTimer();
	void clicker();

};

#endif
