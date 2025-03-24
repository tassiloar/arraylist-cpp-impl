/*
 *  CharArrayList.h
 *  YOUR NAME HERE
 *  DATE CREATED
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  FILE PURPOSE HERE
 *
 */

#include <string>
#include <stdexcept>
using namespace std;

class CharArrayList {

    public:
        CharArrayList();
        CharArrayList(char c);
        CharArrayList(char arr[], int size);
        CharArrayList(const CharArrayList &other);
        ~CharArrayList();
        CharArrayList &operator=(const CharArrayList &other);
        bool isEmpty() const;
        void clear();
        int size() const;
        char first() const;
        char last() const;
        char elementAt(int index) const;
        string toString() const;
        string toReverseString() const;
        void pushAtBack(char c);
        void pushAtFront(char c);
        void insertAt(char c, int index);
        void insertInOrder(char c);
        void popFromFront();
        void popFromBack();
        void removeAt(int index);
        void replaceAt(char c, int index);
        void concatenate(CharArrayList *other);


    private:
        char* arraypointer;
        int size_array;
        void increaseSize();
        int getActiveIndex() const;

};


