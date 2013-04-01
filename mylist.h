#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
#include <stdexcept>

/**
	* This templated class is used to keep track of a dynamic array along with useful member functions.
	* @author Tam Henry Le Nguyen */

template <typename T> 
class MyList
{
	private:
		T *info_; /** a pointer to the information */
		int size_; /** number of variables in dynamic array */
		int capacity_; /** size of dynamic array*/

	public:
		MyList(); /** default constructor */
		~MyList(); /** destructor */
		int getSize(); /** returns Size */
		T& at(int loc); /** gives the item at given location */
		T& operator[] (int n); /** operator overload [] same as at */
		void push_back(T name); /** pushes an item to end of array */
		bool remove(T val); /** deletes an item in array */
		T pop(int loc); /** pop the first item in array */
		void refresh(); /** clears array */

};


/** Constructor
	* Makes an array with no variables with a capacity to hold one variable*/
template <typename T> 
MyList<T>::MyList(){
	capacity_=1;
	info_=new T[capacity_];
	size_=0;
}

/** Destructor
	* Deletes the array */
template <typename T>
MyList<T>::~MyList(){
//	delete [] info_;
//	size_=0; 
}

/** getSize Function 
	* Returns the current size(number of items) of array */
template <typename T>
int MyList<T>::getSize(){
	return size_;
}

/** Refresh Function 
	* Clear everything in the list */
template <class T>
void MyList<T>::refresh(){
	size_ = 0;
}

/** Push_back function
	* Adds the item to the end of the ist
	* @param name Item you wish you add */
template <typename T>
void MyList<T>::push_back(T name){
	if(size_==capacity_){
		T *newinfo = new T[size_*2];
		capacity_=capacity_*2;
		for(int i=0; i <=size_; i++){
			newinfo[i] = info_[i];
		}
	delete [] info_;
	info_ = newinfo;
	}
	info_[size_] = name;
	size_++;
}


/** at Function 
	* Return name at specified location in the array
	* @param loc The location of the item you want */
template <typename T>
T& MyList<T>::at(int loc){
	return info_[loc];
}


/** Remove Function 
	* Removes the value
	* @param val The value you want to remove*/
template <typename T>
bool MyList<T>::remove(T val){

for(int i=0; i < size_; i++){
	if(info_[i] == val){
		for(int j=i; j < size_-1; j++){
		info_[j] = info_[j+1];
		}
		size_--;
		return true;
	}
}
	return false;
}

/*
//Popping a location
template <typename T>
T MyList<T>::pop(int loc){


do {
  cin.exceptions(ios::failbit);
  try {  
    cin >> loc;
  }
catch(ios::failure& ex) {
    cerr << "Error" << endl;
    cin.clear();
cin.ignore(1000,'\n');
    continue;
  }
break;
} while(1)


T temp = info_[loc];
	for(int j=loc; j < size_-1; j++){
		info_[j] = info_[j+1];
	}
	size_--;
	return temp;
}
*/

/** Operator Overload 
	* Overloads the [] to return the item at the location
	* @param n The location of the item */
template <typename T>
T& MyList<T>::operator[] (int n){
	return info_[n];
}

#endif
