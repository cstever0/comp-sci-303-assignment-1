#include <iostream>
#include "../headers/assignment_1.h"

using namespace std;

// simple function to check if a given value exists and return the index of the value or -1 if it does not exist
int checkIfExists(int array[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }

    return -1;
}

// simple function to change a single value to a new value then return the old value and the new value as a pair
pair<int, int> modify(int array[], int size, int idx, int new_value) {
    try {
        if (idx < 0 || idx >= size) {
            throw range_error("Index is out of bounds");
        }
    } catch(range_error err) {
        cerr << err.what() << endl;
    }

    int old_value = array[idx];
    array[idx] = new_value;

    return { old_value, new_value };
}

// simple function to add a value to the end of the array
bool push(int array[], int& size, int max_size, int value) {
    try {
        if (size == max_size) {
            throw range_error("The array is full. Resize to add new values.");
        }
    } catch (range_error err) {
        // cout << size << endl; // <-- debugging cout
        cerr << err.what() << endl;
        return false;
    }

    array[size] = value;
    size++;
    return true;
}

// simple function to remove a value from the array (some complexity attempted due to shifting)
bool remove(int array[], int& size, int idx) {
    try {
        if (idx < 0 || idx >= size) {
            throw range_error("Index is out of bounds");
        }
    } catch(range_error err) {
        cerr << err.what() << endl;
        return false;
    }

    for (int i = idx; i < size; i++) {
        array[i] = array[i + 1];
    }

    size--;
    return true;
}
