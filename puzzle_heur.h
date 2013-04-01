#ifndef PUZZLE_HEUR_H
#define PUZZLE_HEUR_H

/**
	* This is a skeleton class for other classes to inherit from.
	* @author Tam Henry Le Nguyen */
class PuzzleHeuristic
{
 public:
  virtual int compute(int *tiles, int size) = 0; /** Computes the heuristic score */
};


// Define actual Heuristic Classes here
/** Manhattan Heuristic Class
	* This is a Heuristic Class that will compute the value Manhattan style.
	* @author Tam Henry Le Nguyen */
class ManhattanHeuristic : public PuzzleHeuristic
{
	public:
	int compute(int *tiles, int size); /** Computes the heuristic score */

	private:
	
};

/** Out of Place Heuristic Class
	* This is a Heuristic Class that will compute the value OutOfPlace style.
	* @author Tam Henry Le Nguyen */
class OutOfPlaceHeuristic : public PuzzleHeuristic
{
	public:
	int compute(int *tiles, int size); /** Computes the heuristic score */
	
	private:

};
#endif
