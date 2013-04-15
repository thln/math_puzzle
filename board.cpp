#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "board.h"
using namespace std;

/** Default constructor 
	*makes a basic board of size 4 with tiles already solved.
*/
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
 *  @param size Number of tiles for the game.  
 *      Should be a perfect square (4, 16, 25)
 *  @param numInitMoves Number of tile moves to attempt to scramble the board
 *  @param seed Use to seed the random number generator (srand) 
 */
Board::Board(int size, int numInitMoves, int seed)
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


/** Default destructor
	* deletes the dynamically allocated tiles. */
Board::~Board()
{
	  delete [] tiles_;
}

/** Copy Constructor #1 
	* copys a current board and makes a new one
	* @param &b References a board to make a copy of. */
Board::Board(const Board &b)
{
	tiles_ = new int[b.size_];
	size_ = b.size_;
	//*tiles_ = *(b.tiles_);
	for(int i=0; i<b.size_; i++)
	{
		tiles_[i] = b.tiles_[i];
	}
}

/** Copy Constructor #2
	* makes a board with given parameters
	* @param *tiles Copies the given tiles to a board
	* @param size Makes a board of given size  */
Board::Board(int *tiles, int size)
{
	tiles_ = new int[size];
	for(int i=0; i<size; i++)
	{
		tiles_[i] = tiles[i];
	}
}

/** Move Function 
	* Swaps the blank tile with the specified tile
	* @param tile The tile that you specified to move */
void Board::move(int tile)
{
  int dim = static_cast<int>(sqrt(size_));

	//checking if tile is in the game or not
	if(tile<-1 || tile>(size_))
	{
		cout << "Tile does not exist." << endl;
	}
	else{
	
	//looping through all tiles
	//variables keeping track of tiles to swap
	int a = 0;
	int b = 0;
	for(int i=0; i<size_; i++)
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
	//Checks if two tiles are next to each other
	if( a == b+sqrt(size_) || a == b-sqrt(size_) || a == b+1 || a == b-1)
	{
	//Checks if numbers are on the "edge"
		//Special 2 square case
		if(size_ == 4)
		{
			if( (a==0 && b==3) || (b==0 && a==3) || (a==1 && b==2) || (b==1 && a==2) )
			{
			cout << "Incorrect tile movement." << endl;
			}
			else
			{
			tiles_[a] = 0;
	 		tiles_[b] = tile;
			}
		}
		else if((a%dim == 0 && b%dim == dim-1) || (b%dim == 0 && a%dim == dim-1))
		{
			cout << "Incorrect tile movement." << endl;
		}
		else{
	 		tiles_[a] = 0;
	 		tiles_[b] = tile;
	 	}
	}
	}
}

/** Solve Function
	* Checks if the board is solved or not */
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

/** potenialMoves function 
	* Generates potential moves and returns a map of every possible board
	* Key=tile, Value=Ptr to corresponding Board
	* @return mymap A map of the possible boards*/
std::map<int, Board*> Board::potentialMoves()
{
 std::map<int, Board*> mymap;
 int dim = (sqrt(this->size_));

//index where zero is
int zeroIndex = 0;
//finds where the zeroIndex is
 for(int i=0; i<this->size_; i++)
 {
 	if(this->tiles_[i] == 0)
 	{
 		zeroIndex = i;
 //		cout << "ZeroIndex is at: " << i << endl;
 		break;
 	}
 }
 if (dim != 0)
 {
 //checking if 0 is on the left edge
 if(zeroIndex%dim == 0)
 {
 
 }
 else
 {

//   	cout << "     Board1" << endl;
 	Board *Board1 = new Board(*this);
 	int temp = zeroIndex-1;
// 	cout << "Tile is: " << this->tiles_[temp] << endl;
 	Board1->move(this->tiles_[temp]);
 	mymap[(this->tiles_[zeroIndex-1])] = Board1;
 }
 
 //checking if 0 is on the right edge
 if(zeroIndex%dim == (dim-1))
 {
 
 }
 else
 {
//  	cout << "     Board2" << endl;
 	Board *Board2 = new Board(*this);
 	int temp = zeroIndex+1;
// 	cout << "Tile is: " << this->tiles_[temp] << endl;
 	Board2->move(this->tiles_[temp]);
 	mymap[(this->tiles_[zeroIndex+1])] = Board2;
 } 
 
 //checking if 0 is on the top row
 if(zeroIndex < dim)
 {
 
 }
 else
 {
//  	cout << "     Board3" << endl;
 	Board *Board3 = new Board(*this);
 	int temp = zeroIndex-dim;
// 	cout << "Tile is: " << this->tiles_[temp] << endl;
 	Board3->move(this->tiles_[temp]);
 	mymap[(this->tiles_[zeroIndex-dim])] = Board3;
 } 
 //checking if 0 is on the bottom row
 if(zeroIndex >= dim*(dim-1))
 {
 
 }
 else
 {
//  	cout << "     Board4" << endl;
 	Board *Board4 = new Board(*this);
 	int temp = zeroIndex+dim;
// 	cout << "Tile is: " << this->tiles_[temp] << endl;
 	Board4->move(this->tiles_[temp]);
 	mymap[(this->tiles_[zeroIndex+dim])] = Board4;
 } 
}
	return mymap;
}

/** Tile Accessor 
	* @return tiles_ returns the array of tiles*/
int* Board::getTiles()
{
	return tiles_;
}

/** Size Accessor
	* @return size_ returns the size variable */
int Board::getSize()
{
	return size_;
}

/** < Operators
	* Checks if one board is less than another board
	* @param rhs the board you comparing this to */
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


/** << Operators
	* Prints out board
	* @param &b Board to print */
std::ostream& operator<<(std::ostream &os, const Board &b)
{
  int dim = static_cast<int>(sqrt(b.size_));
  
	for(int i=0; i<b.size_; i++)
	{
	   if(i%dim == 0)
	   {
	    os << " " << endl;
	   }
	   if(b.tiles_[i] == 0)
	   {
	    os << " " << setw(2);
	   }
	   else
	   {
	    os << b.tiles_[i] << setw(2);
	   }
	}
 return os;
}

/** == Operators
	* Compares two boards to see if they are equal
	* @param rhs Board to compare */
bool Board::operator==(const Board& rhs) const
{
	if(size_ < rhs.size_){
    	return false;
    }
    for(int i=0; i<size_; i++)
    {
    	if(tiles_[i] != rhs.tiles_[i])
    	{
    		return false;
    	}
    }
    return true;
}

/** != Operators
	* Compares two boards to see if they are not equal
	* @param rhs Board to compare */
bool Board::operator!=(const Board& rhs) const
{
	if(size_ < rhs.size_){
      return true;
    }
    for(int i=0; i<size_; i++)
    {
    	if(tiles_[i] != rhs.tiles_[i])
    	{
    		return true;
    	}
    }
    return false;
}
