#include <iostream>
#include <fstream>
#include "../headers/assignment_1.h"
#include "./assignment_1.cpp"

using namespace std;

int main() {
    int max_size = 100;
    int size = 0;
    int numbers[max_size];
    int num;


    // reading the data from the file and outputting a message if the file cannot be read
    ifstream numbers_file;
    numbers_file.open("resources/A1input.txt");

    if (numbers_file.is_open()) {
        while (numbers_file >> num) {
            if (size < max_size) {
                numbers[size] = num;
                size++;
            }
        }
    } else {
        cout << "Could not open file!" << endl;
        return 0;
    }

    numbers_file.close();

    // demonstrating functionality
    int idx = checkIfExists(numbers, size, 50);
    if (idx != -1)  {
        cout << "Value was found at index: " << idx << endl;
    } else {
        cout << "Value could not be found!" << endl;
    }

    // changes the value at index 2 to 30
    pair<int, int> old_to_new = modify(numbers, size, 2, 30);
    cout << "Value: " << old_to_new.first << " changed to Value: " << old_to_new.second << endl;

    // simple demonstration of adding the value 15 to the back !!! MUST INCREASE MAX SIZE OR WILL ONLY GET THROWN RANGE ERROR !!!
    if (push(numbers, size, max_size, 15)) {
        cout << "Value: " << 15 << " added to back of array!" << endl;
    }

    // simple demonstration of removing the value at index 3
    if (remove(numbers, size, 3)) {
        cout << "Value at index: " << 3 << " removed from array!" << endl;
    }

    // simple loop to cout the entire array for demonstrating functionality.
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
