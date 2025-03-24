/*
 *  CharArrayList.cpp
 *  YOUR NAME HERE
 *  DATE CREATED
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  FILE PURPOSE HERE
 *
 */

#include "CharArrayList.h"


CharArrayList::CharArrayList(){
    arraypointer = new char[0]();
    size_array = 0;
}

CharArrayList::CharArrayList(char c){
    arraypointer = new char[1]();
    arraypointer[0] = c;
    size_array = 1;
}

CharArrayList::CharArrayList(char arr[], int size){
    arraypointer = new char[size]();
    size_array = size;
    for(int i = 0; i < size; i++) {
        arraypointer[i] = arr[i];
    }
}

CharArrayList::CharArrayList(const CharArrayList &other){
    int size_other = other.size();
    arraypointer = new char[size_other];

    size_array = size_other;

    for(int i = 0; i < size_other; i++) {
        arraypointer[i] = other.elementAt(i);
    }
}

CharArrayList::~CharArrayList() {
    delete[] arraypointer;
}


CharArrayList& CharArrayList::operator=(const CharArrayList &other) {

    char* temp = new char[other.size()]();

    for(int i = 0; i < other.size(); i++) {
        temp[i] = other.elementAt(i);
    }

    arraypointer = temp;
    size_array = other.size();

    return *this;

}

bool CharArrayList::isEmpty() const {

    for(int i = 0; i < size_array; i++) {
        if(arraypointer[i] != '\0') {
            return false;
        }
    }

    return true;

}

void CharArrayList::clear() {

    for(int i = 0; i < size_array; i++) {
        arraypointer[i] == '\0';
        
    }
}

int CharArrayList::size() const{
    int i = 0;

    if (size_array == 0) {
        return 0;
    }

    for(i = 0; arraypointer[i] != '\0'; i++) {      
    }

    return i;
}

char CharArrayList::first() const{

    if(size_array == 0 or arraypointer[0] =='\0' ) {
        throw runtime_error("cannot get first of empty ArrayList");
    } 

    return arraypointer[0];
    
}

char CharArrayList::last() const{

    if(size_array == 0 or arraypointer[0] =='\0' ) {
        throw runtime_error("cannot get last of empty ArrayList");
    }

    return arraypointer[size_array-1];
}

int CharArrayList::getActiveIndex() const{

    for (int i = 0; i < size_array; i++) {
        if(arraypointer[i] == '\0') {
            return i;
        }
    }

    return size_array-1;
}

char CharArrayList::elementAt(int index) const{
    int len = getActiveIndex();
    if (index > len) {
        throw range_error("index "+to_string(index)+" not in range [0.."+to_string(len)+")");
    }

    return arraypointer[index];
}

string CharArrayList::toString() const{

    string string_array = "";

    for(int i = 0; i < size_array; i++) {
        string_array +=arraypointer[i];
    }

    return string_array;
}

string CharArrayList::toReverseString() const{

    string string_array = "";

    for(int i = size_array-1; i >=0; i--) {
        string_array +=arraypointer[i];
    }

    return string_array;
}

void CharArrayList::increaseSize() {
   char *temp = new char[(size_array*2) +2]();

    for(int i = 0; i < size_array; i++) {
        temp[i] = arraypointer[i];
    }

    delete[] arraypointer;

    size_array = (size_array*2) +2;

    arraypointer = temp;
}

void CharArrayList::pushAtBack(char c){

    if (last() != '\0' or size_array == 0) {
        increaseSize();
    }

    for(int i = 0; i < size(); i++) {
        if (arraypointer[i] == '\0') {
            arraypointer[i] = c;
        }
    }
}

void CharArrayList::pushAtFront(char c){

    if (last() != '\0' or size_array == 0) {
        increaseSize();
    }

    for(int i = size(); i > 0; i--) {
        arraypointer[i] = arraypointer[i-1];
    }
    arraypointer[0] = c;
}

void CharArrayList::insertAt(char c, int index){

    int len = getActiveIndex();
    if (index > len) {
        throw range_error("index "+to_string(index)+" not in range [0.."+to_string(len)+")");
    }

    if (last() != '\0' or size_array == 0) {
        increaseSize();
    }


    for(int i = size(); i > index; i--) {
        arraypointer[i] = arraypointer[i-1];
    }
    arraypointer[index] = c;
}

void CharArrayList::insertInOrder(char c){

    if (last() != '\0' or size_array == 0) {
        increaseSize();
    }

    for(int i = size(); i > 0; i--) {
        arraypointer[i] = arraypointer[i-1];
        if(arraypointer[i] <= c) {
            arraypointer[i] = c;
            break;
        }
    }
}

void CharArrayList::popFromFront(){

    if(size_array == 0 or arraypointer[0] =='\0' ) {
        throw runtime_error("cannot pop from empty ArrayList");
    }

    for(int i = 0; i < size_array-1; i++) {
        arraypointer[i] = arraypointer[i+1];
    }
    arraypointer[size_array-1] = '\0';
}

void CharArrayList::popFromBack(){

    if(size_array == 0 or arraypointer[0] =='\0' ) {
        throw runtime_error("cannot pop from empty ArrayList");
    }

    for(int i = size()-1; i > 0; i--) {
        if(arraypointer[i] != '\0') {
            arraypointer[i] == '\0';
        }
    }
}

void CharArrayList::removeAt(int index){

    for(int i = index; i < size_array; i++) {
        arraypointer[i] = arraypointer[i+1];
    }
}

void CharArrayList::replaceAt(char c, int index){

    arraypointer[index] = c;

}

void CharArrayList::concatenate(CharArrayList *other){

    if (other == nullptr || other->size_array == 0) {
            return; 
        }

    while(size_array < other->size() + size_array) {
        increaseSize();
    }

    for (int i = 0; i < other->size_array; i++) {
            arraypointer[size_array + i] = other->arraypointer[i];
        }
}

