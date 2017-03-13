# C++_A2
Implementing Vector class with iterators

First define a new type DynamicArray. The type should be templated, so that it can work with all types.
Your new type should have the following methods defined on it:
• add(T item) : adds an element to the end of the DynamicArray. T is the type used in the template above. It should return void.
• size: returns how many elements are in the DynamicArray. (Note: this is di↵erent than the capacity. See below for further discussion.)
• remove(int i): removes the element at position i of the DynamicArray. All elements at positions greater than i should be shifted down by one at this point. It should return the removed element.
• DynamicArray() : This should initialize the backend array (see below) to have a size of 10 and set the capacity to be 10 and current position to be 0.
• ⇠ DynamicArray() : This destructor should handle any memory that has not been freed yet.
• Overload the [] operator so that you can access any arbitrary spot of the dynamic array. Hint: Re- member to return a reference to allow for setting values this way.
• begin() : This method returns a DynamicArrayIterator object with a state that is at the beginning of a DynamicArray set up to iterator forward.
• end() : This method returns a DynamicArrayIterator (see the next question) object with a state that is one past the end of a DynamicArray set up to iterator forward.
• r begin() : This method returns a DynamicArrayIterator object with a state that is at the beginning of a DynamicArray set up to iterator forward.
• r end() : This method returns a DynamicArrayIterator object with a state that is one past the end of a DynamicArray set up to iterator forward.

Second, you should define a new type DynamicArrayIterator which can be used to traverse an array either forwards and backwards based on the value of the private properties. This type will also need to be templated to work fully with the other one.
You should have the following private properties:
• int currentPosition
• DynamicArray* array
• int direction - This is used to store how to move each time. A value of 1 indicates it is moving forward and a value of -1 indicates it is moving backwards. This value never changes after its initialization.

Then, write the following methods/overloaded operators
1. A constructor that takes as input a pointer to the DynamicArray, the initial current position, and the direction it is moving.
2. Overload the * operator so that values can be set and fetched.
3. Overload the increment operator. For simplicity, make this a void function so that it does not matter if you do pre or post fix –though you will need to ensure you call it properly from your main method. Depending on the direction of the iterator, this should either increase or decrease the current position.
4. Overload the == operator to allow a comparison with another DynamicArrayIterator.
5. Overload the != operator to allow a comparison with another DynamicArrayIterator.
