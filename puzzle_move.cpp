#include "puzzle_move.h"

//Constructor for starting Board of an A* search
PuzzleMove::PuzzleMove(Board &b)
{
	tileMove_ = 0;
	g_ = 0;
	h_ = 0;
	b_ = NULL;
	prev_ = NULL;

}

//Constructor for subsequent search boards
// (i.e) like those returned by Board::potentialMoves()
PuzzleMove::PuzzleMove(int tile, Board *b, PuzzleMove *Parent)
{
	tileMove_ = tile;
	prev_ = Parent;
	b_ = b;
	g_++;
	h_ = 0;
}

//Destructor
PuzzleMove::~PuzzleMove()
{
	delete b_;
	delete prev_;
}




// Compare to PuzzleMoves based on f distance (needed for priority queue
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

