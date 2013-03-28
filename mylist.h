#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
#include <stdexcept>


template <typename T> 
class MyList
{
	private:
		T *info_;
		int size_;
		int capacity_;

	public:
		MyList();
		~MyList();
		int getSize();
		T& at(int loc);
		T& operator[] (int n);
		void push_back(T name);
		bool remove(T val);
		T pop(int loc);
		void refresh();

};


//class MyList methods
//constructor
template <typename T> 
MyList<T>::MyList(){
	capacity_=1;
	info_=new T[capacity_];
	size_=0;
}

//destructor
template <typename T>
MyList<T>::~MyList(){
//	delete [] info_;
//	size_=0; 
}

//returning size of list
template <typename T>
int MyList<T>::getSize(){
	return size_;
}

//Clear everything in the list
template <class T>
void MyList<T>::refresh(){
	size_ = 0;
}

//adding name to end of the list
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

//returning name at specified location on the array
template <typename T>
T& MyList<T>::at(int loc){
	return info_[loc];
}


//Removing a Value
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

//Operator Overload
template <typename T>
T& MyList<T>::operator[] (int n){
	return info_[n];
}

#endif
