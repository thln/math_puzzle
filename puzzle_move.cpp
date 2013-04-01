#include "puzzle_move.h"

/** Constructor
	* Constructor for starting Board of an A* search
	* @param &b References the board you want to use */
PuzzleMove::PuzzleMove(Board &b)
{
	tileMove_ = 0;
	g_ = 0;
	h_ = 0;
	b_ = &b;
	prev_ = NULL;

}

/** Constructor
	* Constructor for subsequent search boards
	* (i.e) like those returned by Board::potentialMoves()
	* @param tile The tile that is being moved
	* *b The current board
	* *Parent the previous puzzlemove */
PuzzleMove::PuzzleMove(int tile, Board *b, PuzzleMove *Parent)
{
	tileMove_ = tile;
	prev_ = Parent;
	b_ = b;
	g_ = Parent->g_ + 1;
	h_ = 0;
}

/** Desructor
	* Deletes dynamically allocated items, b_ and prev_ */
PuzzleMove::~PuzzleMove()
{
	delete b_;
	delete prev_;
}




/** == Operator
	* Compare to PuzzleMoves based on f distance (needed for priority queue)
	* @param p the Puzzlemove you are comparing to */
bool PuzzleMove::operator==(const PuzzleMove& p) const
{
	if((g_ + h_) == (p.g_ + p.h_))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/** < Operator
	* Compare to PuzzleMoves based on f distance (needed for priority queue)
	* @param p the Puzzlemove you are comparing to */
bool PuzzleMove::operator<(const PuzzleMove& p) const
{
  if((g_ + h_) < (p.g_ + p.h_)){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ > p.g_)){
    return true;
  }
  else {
    return false;
  }
}

/** > Operator
	* Compare to PuzzleMoves based on f distance (needed for priority queue)
	* @param p the Puzzlemove you are comparing to */
bool PuzzleMove::operator>(const PuzzleMove& p) const
{
  if( (g_ + h_) > (p.g_ + p.h_) ){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ < p.g_) ){
    return true;
  }
  else {
     return false;
  }
  
}

