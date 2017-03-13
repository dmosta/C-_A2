// DynamicArray.cpp
//  DynamicArray
//  Created by Diaa Mostafa on 2017-03-11.
//  ID: 260371546
//  Copyright © 2017 Diaa Mostafa. All rights reserved.
//

#include <iostream>
#include <cstdlib>

template <class T> class DynamicArrayIterator;

template<class T>
class DynamicArray
    {
    private:
        T *array;     //pointer for memory of the array
        int current;  //number of elemets in the array
        int Asize;     //size of array's allocated memory
        int DynamicArray_init = 10; //initial size of array's allocated memory
        int DynamicArray_mult = 2; // multiplier to increase array's allocated memory
        
    public:
        DynamicArray(){               // constructor initialize the backend array to have a size of 10
            Asize = DynamicArray_init; // allocatition step
            current= 0;               // 0 elements in the array
            array = (T *)malloc(Asize*sizeof(T));
        }
        
        ~DynamicArray(){               // destructor handles any memory that has not been freed yet
            if (array)
            {
                free(array);           // free the memory
                array = NULL;
            } 
        }
        
        void add(const T &item)        // adds an element to the end of the DynamicArray
        {
            current++;                 // increment current number of elements by 1

            if (current > Asize)        // check if the number of elements is bigger than the array size
            {
                Asize *= DynamicArray_mult;       //create a bigger array
                array = (T *)realloc(array, sizeof(T)* Asize);
            } 
            
            array[current-1] = item;             // insert the element at the end of the array
        }
        
        int size(){                              // returns how many elements are in the DynamicArray
            return current;
        }
       
        void clear() {                           //  Auxillary function: clears the array
         current = 0;
         array = (T *)realloc(array, sizeof(T)*DynamicArray_init);
         Asize = DynamicArray_init;               // reset initial memory size
       }
        
        T remove( int i)             // removes the element at position i of the DynamicArray
        {
            if (i >=current || i < 0){
                std:: cout << "Error: position does not exist." << std::endl;
                return -1;
            }
            else if (current ==1 ) {             // If array has only one element
                T  item = array[i];
                clear();                         //clear it, since it will be deleted
                return item;                               // return array element
            }
            else
            {
                 T  item = array[i];
                //All elements at positions greater than i should be shifted down by one at this point
                for( int j=i; j<current-1; j++){
                    array[j] = array[j+1];
                }
                current--; // decrease array's elements number by 1
                return item; // return array element
            }
        }
        
        T& operator[](int i) // get array item
        {
            if ((i-1)>Asize){
                Asize += (i+1);       //create a bigger array
                array = (T *)realloc(array, sizeof(T)* Asize);
            }
                return array[i]; // return array element
        }
        
        //This method returns a DynamicArrayIterator object with a state that is at
        //the beginning of a DynamicArray set up to iterator forward.
        
        DynamicArrayIterator<T> begin(){
            //create Dynamic Array Iterator out of this and set at position 0
            return DynamicArrayIterator<T>(this,0,1 );
        }
        
        //This method returns a DynamicArrayIterator object with a state that is
        // one past the end of a DynamicArray set up to iterator forward.
        
        DynamicArrayIterator<T> end(){
            //create Dynamic Array Iterator out of this and set at position at one past the last value
            return DynamicArrayIterator<T>(this,current,1);
            
        }
        
        // should return a DynamicArrayIterator whose state is pointing at the
        // last value in the array and direction is moving backwards.
        
        DynamicArrayIterator<T> r_begin(){
            //create Dynamic Array Iterator out of this and set at at the last value
            return DynamicArrayIterator<T>(this,current-1,-1);
        }
        
        // should return a DynamicArrayIterator whose state is pointing one before the
        // first value in the array and the direction is moving backwards.
        
        DynamicArrayIterator<T> r_end(){
            //create Dynamic Array Iterator out of this and set at position at one before the first value
            return DynamicArrayIterator<T>(this,-1,-1);
        }
        
    };

template<class T>
class DynamicArrayIterator{
    
private:
    int currentPosition;
    DynamicArray<T> * array; // pointer to dynamic array
    int direction; // store how to move each time
    
public:
    // A constructor that takes as input a pointer to the DynamicArray,
    // the initial current position, and the direction it is moving

    DynamicArrayIterator <T>(DynamicArray<T>* arr, int pos, int dir)
    {
        array = arr;
        currentPosition = pos;
        direction = dir;
    }
    
    // Overload the * operator so that values can be set and fetched
    T& operator*()
    {
        return (*array)[currentPosition];
    }
  
    
    // Overload the increment operator. Depending on the direction of
    //the iterator, this should either increase or decrease the current position.
    void operator++()
    {
      this->currentPosition += this->direction;
    
    }
    
    // Overload the == operator to allow a comparison with another DynamicArrayIterator
    bool operator==( DynamicArrayIterator<T>& other)
    {
        return ( this-> array == other.array && this->currentPosition == other.currentPosition &&
                this->direction == other.direction );
    }
    
    // Overload the != operator to allow a comparison with another DynamicArrayIterator
    
    bool operator !=(DynamicArrayIterator<T> other)  {
        return !(*this == other);
    }
};

int main(void)
{
    
    std::cout << "***********************"  << std::endl;
    
    DynamicArray<int> foo;
    foo.add(3);
    foo.add(2);
    std::cout << foo[1] << std::endl;
    foo[1] = 10;
    std::cout << foo[1] << std::endl;
    
    
    for(DynamicArrayIterator<int> a = foo.begin(); a != foo.end(); ++a) {
        std::cout << *a << std::endl;
    }
    for(DynamicArrayIterator<int> a = foo.r_begin(); a != foo.r_end(); ++a) {
        std::cout << *a << std::endl;
    }
    std::cout << "***********************"  << std::endl;
    std::cout << "Additional Testing "  << std::endl;
    std::cout << "***********************"  << std::endl;
    DynamicArray<int> array;
    
    // lets add some values using Add()
    array.add(7);
    array.add(94);
    array.add(1);
    
    std::cout << "element at posistion 0: " <<array[0] << std::endl;
    std::cout << "element at posistion 1: " << array[1] << std::endl;
    std::cout << "element at posistion 2: " << array[2] << std::endl;
    std::cout << "array size " << array.size() << std::endl;
    // delete 1-st  and last items
    std::cout << "element removed at posistion 0: " <<array.remove(0) << std::endl;
    std::cout << "array size " << array.size() << std::endl;
    std::cout << "element removed at posistion 1: " <<array.remove(1) << std::endl;
    std::cout << "array size " << array.size() << std::endl;
    std::cout << "element at posistion 0: " << array[0] << std::endl;
    
    std::cout << "***********************"  << std::endl;
    
    DynamicArray<int> soo;
    soo.add(1);
    soo.add(2);
    soo.add(3);
    soo.add(4);
    soo.add(5);
    soo.add(6);
    
    for(DynamicArrayIterator<int> a = soo.begin(); a != soo.end(); ++a) {
        std::cout << *a << std::endl;
    }

    std::cout << "***********************"  << std::endl;
    
    for(DynamicArrayIterator<int> a = soo.r_begin(); a != soo.r_end(); ++a) {
        std::cout << *a << std::endl;
    }
    std::cout << "***********************"  << std::endl;
    soo[20] =20;
    soo[30]=30;
     std::cout << soo.size() << std::endl;
     std::cout << soo[20] << std::endl;
    std::cout << soo[30] << std::endl;
    std::cout << soo.size() << std::endl;
     std::cout << "***********************"  << std::endl;
    DynamicArray<int> loo;
    loo[0]=0;
    loo[2]=2;
    loo[11]=11;
    std::cout << loo[0] << std::endl;
    std::cout << loo[2] <<  std::endl;
    std::cout << loo[11] << std::endl;
    std::cout << "***********************"  << std::endl;
    
    
    return 0;
}
