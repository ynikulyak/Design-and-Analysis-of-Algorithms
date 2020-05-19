/*
 * Title: select-sort-k.cpp
 * Abstract: This program modifies the selection sort algorithm to sort the first k smallest elements of the array
 * with n elements.
 * Author: Yauheniya Nikulyak
 * ID: 2606
 * Date: 01/30/2020
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void selectionSort(int arr[], int k, int size) {

    for (int i = 0; i < k; i++) {
        //assign index of min element
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        //swap min element to put it on the next asc. order position
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main() {
    string fileName;
    ifstream file;

    string input;
    int k;

    //request user a file name
    cout << "Enter a file name: ";
    cin >> fileName;

    //request user a number of elements to sort
    cout << "Enter the value k: ";
    cin >> input;
    //convert string into int
    k = stoi(input);

    file.open(fileName);
    if (file.fail()) {
        cout << "Error" << strerror(errno);
        return 0;
    }

    string line;
    int size;
    int *p;
    int i = 0;

    if (file.is_open()) {
        //read the first line to get the amount of numbers
        getline(file, line);
        //convert string into int
        size = stoi(line);

        //check if size is valid
        if (size < 1) {
            cout << "Your file is empty";
            return 0;
        }

        //check if user input of number of elements is valid
        if (k > size) {
            cout << "Amount of numbers in your file less then your k value.";
            return 0;
        }

        //create dynamic array
        p = new int[size];
        //read file till end
        while (!file.eof()) {
            getline(file, line);
            //convert each line into int
            int number = atoi(line.c_str());
            //initialize dymanic array
            p[i] = number;
            i++;
        }
    }
    file.close();

    //sort first k elements
    selectionSort(p, k, size);

    //display first k sorted elements
    for (int i = 0; i < k; i++) {
        if (i == k - 1) {
            cout << p[i];
        } else {
            cout << p[i] << ", ";
        }
    }

    delete []p;
    p = nullptr;

    return 0;
}
