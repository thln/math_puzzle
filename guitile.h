#ifndef GUITILE_H
#define GUITILE_H

#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsSceneMouseEvent>
#include "graphicswindow.h"
#include <QFont>
#include <QObject>


using namespace std;

class GraphicsWindow;

/**
	* This class is used to keep track of one graphic tile. Inherits from QGraphicsRectItem.
	* @author Tam Henry Le Nguyen */


class GUITile : public QGraphicsRectItem {
//    Q_OBJECT
    
public:
	GUITile(); /** Default Constructor */
	GUITile(GraphicsWindow *p, int val, qreal nx, qreal ny, qreal w, qreal h); /** Constructor with parameters */
	~GUITile(); /** Destructor */
	void mousePressEvent(QGraphicsSceneMouseEvent* event); /** when tile is clicked on*/
	int getValue(); /** Value accessor */
	int getxCord(); /** X Coordinate Accessor */
	int getyCord(); /** Y Coordinate Accessor */
	int getWidth(); /** Width Accessor*/
	int getHeight(); /** Height Accessor */
	void setxCord(double x); /** X Coordinate Resetter */
	void setyCord(double y); /** Y Coordinate Resetter */	
	QTimer *timer; /** Timer */

private:
	GraphicsWindow *parent; /** Pointer to the window the element is in*/
	QGraphicsSimpleTextItem* numbers; /** The Graphical display of the number */
	int value; /** what number is the guitile*/
	int xCord; /** the upper left x coordinate of the tile*/
	int yCord; /** the upper left y coordinate of the tile*/
	int width; /** the width of the tile*/
	int height; /** the height of the tile*/
	QGraphicsSceneMouseEvent* event;

public slots:
	void moveTilesAnimate(); /** Used to animate tiles */

};

#endif
