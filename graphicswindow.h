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
#include <QMessageBox>
#include "guitile.h"
#include "board.h"

using namespace std;

/**
	* This class is used to keep track of all graphic tiles in the central widget.
	* Inherits from QGraphicsView.
	* @author Tam Henry Le Nguyen */

class GUITile;

class GraphicsWindow : public QGraphicsView {
    Q_OBJECT
    
public:
    explicit GraphicsWindow(); /** Constructor */
    ~GraphicsWindow(); /** Destructor */
	QGraphicsScene *getScene(); /** Scene Accessor*/
  	void show(); /** shows the scene*/
    	void moveTile(GUITile *piece1); /** Moves the guitile in the graphicswindow */
	Board* getBoard(); /** Board Accessor */
	GUITile** getTiles(); /** Tiles Accessor */
	void setBoard(Board *b_); /** Board Resetter */
	GUITile* getTilesAt(int index); /** Returns a tile at a certain index */
	void setTilesAt(int index, GUITile *piece); /** Sets a tile at a certain index*/
    
private:
    QGraphicsScene *scene; /** What is being displayed */
    QGraphicsView *view; /** What is being displayed */
    QTimer *timer; /** A Timer */
    
    GUITile *tiles[16]; /** Array of GUITiles pointers */
	Board *b; /** A board */
   	QPushButton *buttonclick; /** Nothing */
   	int counter; /** Nothing */

public slots:
    void handleTimer(); /** Nothing */
	void clicker(); /** Nothing */

};

#endif
