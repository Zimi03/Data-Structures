#include "Dynamic array.h"
#include "optional"

//basic constructor
DynamicArray::DynamicArray(){
    capacity = 5;
    array = new int [capacity];
    size = 0;
}
DynamicArray::DynamicArray(DynamicArray *to_copy): size(0), capacity(5) {
    std::optional<int> value;
    int _size = to_copy->getSize();
    array = new int [_size];
    if(_size != 0){
        for (int i = 0; i < _size; i++){
            value = to_copy->get(i);
            if(value != std::nullopt){
                insertBack(value.value());
            }
        }
    }
}
//destructor
DynamicArray::~DynamicArray(){
    delete[] array;
}
int DynamicArray::getSize() {return size; } //size getter

int DynamicArray::isEmpty() {
    if (size == 0) return 1;
    else return 0;
}

int DynamicArray::find(int value){
    for (int i = 0; i < size; i++){
        if(array[i] == value){ //checking if value exists at current index
            return i; // returning index of wanted value
        }
    }
    return -1; // returning -1 if value doesn't exist in array
}

std::optional<int> DynamicArray::get(int index) {
    if(index >= 0 && index < size) {
        return array[index];
    }else return std::nullopt;
}

/**
 * Init DynamicArray with insertBack - it is necessary for fast initzialization of data structure
 */
void DynamicArray::init(int data){
    insertBack(data);
}

void DynamicArray::insertFront(int data){
    if (size == capacity) {
        grow(); // growing array if needed
    }
   for (int i = size - 1; i >= 0; i--) {
        array[i + 1] = array[i]; //copying values to next index
   }

    array[0] = data; // inserting new value at given index
    size ++; // growing size of array
}

int DynamicArray::insert(int index, int data) {
    if (index == 0 ) {
        insertFront(data);
        return 0;
    }else if(size == index){
        insertBack(data);
        return 0;
    }
    if (index>=0 && index <=size) {
        if (size == capacity) {
            grow(); // growing array if needed
        }
        for (int i = size - 1; i >= index; i--) {
            array[i + 1] = array[i]; //copying values to next index
        }

        array[index] = data; // inserting new value at given index
        size++; // growing size of array
        return 0;
    }
    return 1;
}

void DynamicArray::insertBack(int data){
    if(size == capacity) grow(); // growing array if needed
    array[size] = data; //inserting value at end
    size++; // growing size of array
}

std::optional<int> DynamicArray::removeFront() {
    if(size != 0) {
        int data = array[0];
        for (int i = 0; i < size; i++) {
            array[i] = array[i + 1]; // pushing elements back to fill the gap
        }
        size--; // decreasing size of array
        if(size < (capacity/2)) shrink(); // shrinking array if needed
        return data;
    }else
        return std::nullopt;
}



std::optional<int> DynamicArray::remove(int index){

    if(index < 0 && index >= size) return std::nullopt;
    if(index == 0) return removeFront();
    int data = array[index];
        for (int i = index; i < size; i++) {
            array[i] = array[i + 1]; // pushing elements back to fill the gap
        }

        size--; // decreasing size of array
        if(size < (capacity/2)) shrink(); // shrinking array if needed
        return data;
}

std::optional<int> DynamicArray::removeBack(){
    if(size == 0) return std::nullopt;
    return remove(size-1);
}

void DynamicArray::grow() {
    capacity *= 2; // doubling capacity of array
    int *temp = new int[capacity]; // creating temp array
    for( int i =0; i< size; i++){
        temp[i] = array[i]; //copying values to temp array
    }
    delete[] array; // dellocating memory of old array
    array = temp; //copying temp array to new array
}

void DynamicArray::shrink() {
    capacity = size;
    int *temp = new int[capacity];
    for (int i = 0; i < size; i++){
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}
