#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "board.h"
using namespace std;


// Default constructor
Board::Board()
{
 size_ = 4;
 tiles_ = new int[4];
 for(int i = 0; i< size_; i++)
 {
 	tiles_[i] = i;
 }
}

/** Init a board of given size and scramble it with numInitMoves 
 * by moving the space tile with a randomly chosen direction N, W, S, E
 * some of which may be invalid, in which case we skip that move 
 * 
 *  @param size Number of tiles for the game.  \
 *      Should be a perfect square (4, 16, 25)
 *  @param numInitMoves Number of tile moves to attempt to scramble the board
 *  @param seed Use to seed the random number generator (srand) 
 */
Board::Board(int size, int numInitMoves, int seed )
{
  size_ = size;
  tiles_ = new int[size_];
  int dim = static_cast<int>(sqrt(size_));
  srand(seed);
  for(int i=0; i < size_; i++){
    tiles_[i] = i;
  }
  int blankLoc = 0;
  for(int i=0; i < numInitMoves; i++){
    int r = rand()%4;
    int randNeighbor = -1;
    if(r == 0){
      int n = blankLoc - dim;
      if(n >= 0){
	randNeighbor = n;
      }
    }
    else if(r == 1){
      int w = blankLoc - 1;
      if(blankLoc % dim != 0){
	randNeighbor = w;
      }
    }
    else if(r == 2){
      int s = blankLoc + dim;
      if(s  < size_){
	randNeighbor = s;
      }
    }
    else {
      int e = blankLoc + 1;
      if(blankLoc % dim != dim-1){
	randNeighbor = e;
      }
    }
    if(randNeighbor > -1){
      tiles_[blankLoc] = tiles_[randNeighbor];
      tiles_[randNeighbor] = 0;
      blankLoc = randNeighbor;
    }
  }
}


// Default destructor
Board::~Board()
{
	  delete [] tiles_;
}

//Copy Constructor #1
Board::Board(const Board &b)
{
	tiles_ = new int[b.size_];
	//*tiles_ = *(b.tiles_);
	for(int i=0; i<b.size_; i++)
	{
		tiles_[i] = b.tiles_[i];
	}
}

//Copy Constructor #2
Board::Board(int *tiles, int size)
{
	tiles_ = new int[size];
	for(int i=0; i<size; i++)
	{
		tiles_[i] = tiles[i];
	}
}

//Swaps the blank with the specified tile
void Board::move(int tile)
{
	//checking if tile is in the game or not
	if(tile<0 || tile>(size_-1))
	{
		cout << "Tile does not exist." << endl;
	}
	else{

/* faster way to do shown below
	//finding specified tile
	for(int i=0; i<size_; i++)
	{
	   if(tile == tiles_[i])
	   {
	      //finding the zero or "empty" tile
	      for(int j=0; j<size_; j++)
	      {
		if(tiles[j] == 0)
		{
		//swapping tiles
		  tiles[j] = tile;
		  tiles[i] = 0;
		  break;
		}		
	      }
	   }
	}
*/
	
	//looping through all tiles
	//variables keeping track of tiles to swap
	int a, b;
	for(init i=0; i<size_; i++)
	{
		//finding shown tile
		if(tile == tiles_[i])
		{
		a = i;
		}
		//finding zero tile
		if(0 == tiles_[i])
		{
		b = i;
		}
		
	}
	tiles_[a] = 0;
	tiles_[b] = tile;
	}
}

//Checks if board is solved
bool Board::solved()
{
	for(int i=0; i<size_; i++)
	{
	   if(tiles_[i] != i)
	   {
	     return false;
	   }
	}

  return true;
}

bool Board::operator<(const Board& rhs) const
{
  if(size_ < rhs.size_){
    return true;
  }
  bool val = false;
  for(int i=0; i < size_; i++){
    if(tiles_[i] < rhs.tiles_[i]){
       //val = true;
       //break;
       return true;
     }
     else if(tiles_[i] > rhs.tiles_[i]){
       //break;
       return false;
     }
  }
  return val;
}


