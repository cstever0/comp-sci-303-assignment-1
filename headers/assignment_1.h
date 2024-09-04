#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include <iostream>

using namespace std;
// Header file to declare all my functions that will be used for this assignment.


// simple function to check if a given value exists and return the index of the value or -1 if it does not exist
int checkIfExists(int arr[], int size, int value);

// simple function to change a single value to a new value then return the old value and the new value as a pair
pair<int, int> modify(int array[], int size, int idx, int new_value);

// simple function to add a value to the end of the array
bool push(int array[], int& size, int max_size, int new_value);

// simple function to remove a value from the array (some complexity attempted due to shifting)
bool remove(int array[], int& size, int idx);

#endif
