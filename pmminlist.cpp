#include "puzzle_move.h"
#include "pmminlist.h"

/**
 * Default Constructor
 */
PMMinList::PMMinList() : slist_()
{

}

/**
 * Destructor
 */
PMMinList::~PMMinList()
{

}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest (if 
 * @param val Value to add to the sorted PuzzleMove list
 * @return nothing
 */
void PMMinList::push(PuzzleMove* pm)
{
  std::list<PuzzleMove*>::iterator it = slist_.begin();
 
  //---- Add your implementation to iterate through the list
  //---- to find the correct location to insert pm and then
  //---- use the insert() method of std::List to insert it
  //---- See http://www.cplusplus.com/reference/list/list/insert/

//if it's not empty
	if(!slist_.empty())
	{
		//if the value is the biggest one, just add to the end
		if(*pm>*(*(slist_.end())))
		{
			slist_.push_back(pm);
		}
		//if value is somewhere inbetween
		else
		{
			//traversing list
			for(it = slist_.begin(); it != slist_.end(); ++it)
			{
				//if next value is larger than current value pm, insert right before
				if(*(*it)>*pm)
				{
					slist_.insert(it, pm);
					break;
				}
			}
		}
	}
	//if empty, just push_back
	else
	{
		slist_.push_back(pm);
	}


}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest
 * @param val Value to add to the sorted PuzzleMove list
 * @return nothing
 */
void PMMinList::pop()
{
  slist_.pop_front();
}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest
 * @param val Value to add to the sorted PuzzleMove list
 * @return reference to the minimum-scored PuzzleMove*
 */
PuzzleMove* PMMinList::top()
{
  return slist_.front();
}

