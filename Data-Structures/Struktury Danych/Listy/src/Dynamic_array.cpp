#include "Dynamic array.h"
//basic constructor
DynamicArray::DynamicArray(){
    capacity = 1;
    size = 0;
    array = new int[capacity];
}
//user constructor
DynamicArray::DynamicArray(int capacity) {
    this->capacity = capacity;
    array = new int[capacity];
    size = 0;
}
//destructor
DynamicArray::~DynamicArray(){
    delete[] array;
}
int DynamicArray::get_size() {return size; } //size getter

int DynamicArray::get_capcity() {return capacity;} // capacity getter

int DynamicArray::find(int value){
    for (int i = 0; i < size; ++i){
        if(array[i] == value){ //checking if value exists at current index
            return i; // returning index of wanted value
        }
    }
    return -1; // returning -1 if value doesn't exist in array
}

void DynamicArray::insert_at_given(int value, int index) {
    if(index >= 0 && index <= size) {
        if (size == capacity) {
            grow(); // growing array if needed
        }
        for (int i = size - 1; i >= index; i--) {
            array[i + 1] = array[i]; //copying values to next index
        }
    }
    array[index] = value; // inserting new value at given index
    size ++; // growing size of array
}

void DynamicArray::insert_at_end(int value) {
    if(size == capacity) grow(); // growing array if needed
    array[size] = value; //inserting value at end
    size++; // growing size of array
}

void DynamicArray::delete_at_given(int index) {
    if(index >= 0 && index <= size) {
        for (int i = index; i < size; i--) {
            array[i] = array[i + 1]; // pushing elements back to fill the gap
        }
    }
    size--; // decreasing size of array
    if(size < (capacity/2)) shrink(); // shrinking array if needed

}

void DynamicArray::delete_at_end() {
    array[size] = 0;
    size --;
    if(size < (capacity/2)) shrink();
}

void DynamicArray::grow() {
    capacity *= 2; // doubling capacity of array
    int *temp = new int[capacity]; // creating temp array
    for( int i =0; i< size; ++i){
        temp[i] = array[i]; //copying values to temp array
    }
    delete[] array; // dellocating memory of old array
    array = temp; //copying temp array to new array
}

void DynamicArray::shrink() {
    capacity = size;
    int *temp = new int[capacity];
    for (int i = 0; i < size; ++i){
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}