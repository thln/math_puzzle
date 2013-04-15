#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "puzzle_solver.h"
#include "pmminlist.h"

using namespace std;

/** Constructor
	* Makes a puzzlesolver using the board
	* @param &b The Board you are making a puzzle solver from */
PuzzleSolver::PuzzleSolver(const Board &b)
{
	b_ = b;
	expansions_ = 0;
}

/** Destructor
	* Deletes puzzle solver*/
PuzzleSolver::~PuzzleSolver()
{

}

/** printSolutions function
	* Prints out the solutions in order and the number of expansions */
void PuzzleSolver::printSolutions()
{
	cout << " " << endl;
	cout << "Try this sequence: ";
	for(int i=(Solutions.getSize()-1); i >= 0; i--)
	{
		cout << " " << Solutions[i] << " ";
	}
	cout << " " << endl;
	cout << "(Expansions = " << expansions_ << ")" << endl;
}
 
//Runs the A Star Algorithm
/** Run Function
	* Runs the A Star Algorithm
	* @param *ph the PuzzleHeuristic you are passing through */
int PuzzleSolver::run(PuzzleHeuristic *ph)
{

	PMMinList Open_List;              //stores new, unexplored moves
	BoardSet Closed_Set;              //stores old boards
	vector<PuzzleMove*> Garbage_List; //stores old moves

	PuzzleMove *StartState = new PuzzleMove(b_);
	
//	cout << "Testing StartState board!!!!!!" << endl;
//	cout<<*(StartState->b_) << endl;

	//Adding to open list and closed set
	Open_List.push(StartState);
	Closed_Set.insert(StartState->b_);
	Garbage_List.push_back(StartState);
	map<int, Board*> potentialmap;
	
//	cout<< "LALA2" << endl;

	while(!Open_List.empty())
	{
	
		PuzzleMove *move = Open_List.top();
		Open_List.pop();
		Garbage_List.push_back(move);
	
//		cout<< "LALA3" << endl;
//		cout << "Testing Current Move board!!!!!!" << endl;
//		cout<<*(move->b_) << endl;
		
		if(move->b_->solved())
		{

//		cout <<"Solved!" << endl;
//		cout<< "LALA4" << endl;
			//PuzzleMove *temp = new PuzzleMove(mov
			//trace path backwards
			//** make a temp puzzle with current move.getTile, move, move->prev
			//** add current move.getTile to solutions linked list
			//** temp = temp->prev?
			//** for loop until temp = StartState?
			
//		cout<< "LALA4" << endl;			
		
			//PuzzleMove *temp = move;
		//PuzzleMove *temp = new PuzzleMove(*(move->b_));
		PuzzleMove *temp = new PuzzleMove(move->tileMove_, move->b_, move->prev_);
		
//		cout << "Testing Current Temp board!!!!!!" << endl;
//		cout<<*(temp->b_) << endl;
//		cout << "Temp's tileMove " << temp->tileMove_ << endl;
		if(temp->prev_ == NULL)
		{
//		cout << "temp is NULL" << endl;
		}
//		cout << "Temp's previous " << *(temp->prev_->b_) << endl;


			//std::list<PuzzleMove*>::iterator it = temp;
			//std::list<PuzzleMove*>::iterator it = ;
			//for(it = move; it != StartState; ++it)
			while(temp->prev_ != NULL)
			{
//		cout<< "Adding to Solutions List" << endl;
//		cout << "Temp's tileMove " << temp->tileMove_ << endl;
				Solutions.push_back(temp->tileMove_);
				temp = temp->prev_;
			}
		//cout<< "Adding StartState's tileMove" << endl;
		//necessary?		
		//	Solutions.push_back(StartState->tileMove_);
			break;
		}
		
//		cout<< "Not Solved Yet" << endl;
		
//		cout<<*(move->b_)<<endl;
		
		//makes a map of the current board's potential moves/boards
		potentialmap = move->b_->potentialMoves();
		//travels through the map 
		
//		cout<< "Going into forloop" << endl;
		map<int, Board*>::iterator it;
	//	it = potentialmap.begin();
	
		//Something wrong with forloop, it's not iterating
		for(it = potentialmap.begin(); it != potentialmap.end(); ++it)
		{
//		cout<< "In ForLoop" << endl;
			//if(*(it.second())
			//if the value of the current iterator IS NOT in the Closed_Set it will return Closed_Set.end()
			//therefore if the current move(it) is new and must be explored
			if(Closed_Set.find(it->second) == Closed_Set.end())
			{
			
//			cout<< "New Board" << endl;

			Closed_Set.insert(it->second);
			PuzzleMove *freshMove = new PuzzleMove(it->first, it->second, move);
			freshMove->h_ = ph->compute(it->second->getTiles(), it->second->getSize());
			//freshMove->prev_ = move;
			Open_List.push(freshMove);
			
//			cout << "Expansions Before: " << expansions_ << endl;
			expansions_++;
//			cout << "Expansions After: " << expansions_ << endl;
			}
			else
			{
//			cout << "Old Board, deleting" << endl;
			delete it->second;
			}
		}
		
		/* Generates potentialMoves (in a map, see what you can do next) 
		For every potential move 's'
		 - if 's' does not exist in Closed_Set(i.e. is a new move)
		   - compute f value ( # of moves + heuristic)
		   - add 's' board to Closed_Set (no longer new move)
		   - add 's' to Open_List (will be continued later on)
		   - increment number of expansions (expansions_++ so you know)
		- forloop ends, because there is still a move (not solved) while continues
		
	finishes return solutionSet(??) */
	
		//**Possible algorithm
		//**

	}

//deallocate and delete potentialmoves Map and Closed_List


return Solutions.getSize();	
//return int
//	return;
}

/**getSolutions
	* returns Solutions LinkedList */
MyList<int> PuzzleSolver::getSolutions()
{
	return Solutions;
}

/** getNumExpansions
	* returns number of expansions */
int PuzzleSolver::getNumExpansions()
{
  return expansions_;
}
