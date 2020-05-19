/*
 * Title: heap.cpp
 * Abstract: This program conducts heap operations delete, insert, heapsort. Program reads a set of numbers from a user
 * and store them in an array and displays if the array representation is a heap or not. If it’s not a heap, the program
 * constructs a heap (heapify) using the bottom-up algorithm.
 * Author: Yauheniya Nikulyak
 * ID: 2606
 * Date: 01/22/2020
 */

#include <iostream>

using namespace std;

//function to check if the array is heap
bool isHeap(int arr[], int size) {
    if (size < 1) {
        cout << "Invalid size of array";
        return false;
    }

    if (size == 1) {
        cout << "This is a heap.";
        return true;
    }

    //check if left and right children less than parent
    for (int i = 1; i <= size / 2; i++) {
        if (2 * i + 1 <= size) {
            if (arr[i] >= arr[2 * i] && arr[i] >= arr[2 * i + 1]) {
                continue;
            } else {
                cout << "This is NOT a heap.\n";
                return false;
            }
        } else if (arr[i] >= arr[2 * i]) {
            continue;
        }
    }
    cout << "This is a heap.";
    return true;
}

//helper function to create max heap
void heapify(int arr[], int size, int parent) {

    int max = parent;
    int leftChild = 2 * parent;
    int rightChild = 2 * parent + 1;

    //check if left child is greater than parent
    if (leftChild <= size && arr[leftChild] > arr[max]) {
        max = leftChild;
    }
    //check if right child greater than parent and left child
    if (rightChild <= size && arr[rightChild] > arr[max]) {
        max = rightChild;
    }

    //swap elements if found greater element than parent
    if (max != parent) {
        int temp = arr[parent];
        arr[parent] = arr[max];
        arr[max] = temp;
        //check part of array with new parent if it needs to be adjacent to become max heap
        heapify(arr, size, max);
    }
}

//function to create min heap
void minHeap(int arr[], int size, int parent) {

    int smallest = parent;
    int leftChild = 2 * parent;
    int rightChild = 2 * parent + 1;

    //check if left child is less than parent
    if (leftChild <= size && arr[leftChild] < arr[smallest]) {
        smallest = leftChild;
    }
    //check if right child is less than parent and left child
    if (rightChild <= size && arr[rightChild] < arr[smallest]) {
        smallest = rightChild;
    }

    //swap elements if found smaller element than parent
    if (smallest != parent) {
        int temp = arr[parent];
        arr[parent] = arr[smallest];
        arr[smallest] = temp;
        //check part of array with new parent if it needs to be adjacent to become min heap
        minHeap(arr, size, smallest);
    }
}

void heapSort(int arr[], int size) {
    //create min heap from given array
    for (int i = size / 2; i >= 1; i--) {
        minHeap(arr, size, i);
    }

    //place all small elements at the end one by one
    for (int i = size; i >= 1; i--) {
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        //create min heap from array with updated size
        minHeap(arr, i - 1, 1);
    }
}

void addElement(int arr[], int element, int &size) {
    //increase array size
    size = size + 1;
    //place element at the end of heap
    arr[size] = element;
    //check if adjacent needed to satisfy max heap property
    for (int i = size / 2; i >= 1; i--) {
        heapify(arr, size, i);
    }
}

void deleteMax(int arr[], int &size) {
    //delete first element by placing last element of array to position 1
    arr[1] = arr[size];
    //reduce size of heap
    size = size - 1;
    //check if adjacent needed to satisfy max heap property
    for (int i = size / 2; i >= 1; i--) {
        heapify(arr, size, i);
    }
}

int main() {
    string userInput;
    int size;
    //request use heap size
    cout << "Input size: ";
    //read use input
    cin >> userInput;

    //convert string into int
    size = stoi(userInput);
    //create array for use input
    int arr[100];

    //request user for numbers for heap
    cout << "Enter numbers: ";
    cin.ignore();
    //place numbers in array
    for(int i = 1; i <= size; i++){
        cin >>arr[i];
    }

    bool heap = isHeap(arr, size);

    //check if array is heap
    if (heap == 0) {
        //if array is not a heap, update array to create max heap
        heapify(arr, size, 1);
        cout << "Heap constructed: ";
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
    }

    int operation;
    //request user for operation
    while (true) {
        cout << endl << "Select an operation\n"
                        "    1. Insert a number\n"
                        "    2. Delete the max\n"
                        "    3. Heapsort & Quit\n";

        cin >> userInput;
        operation = stoi(userInput);
        //insert element
        if (operation == 1) {
            cout << "Enter a number: ";
            cin >> userInput;
            int element = stoi(userInput);
            addElement(arr, element, size);
            cout << "Updated heap: ";
            for (int i = 1; i <= size; i++) {
                cout << arr[i] << " ";
            }
        } else if (operation == 2) { //delete element
            deleteMax(arr, size);
            cout << "Updated heap: ";
            for (int i = 1; i <= size; i++) {
                cout << arr[i] << " ";
            }
        } else if (operation == 3) { //provide heap sort and quit the program
            heapSort(arr, size);
            cout << endl << "Heapsort: ";
            for (int i = 1; i <= size; i++) {
                cout << arr[i] << " ";
            }
            cout << "\nBye!";
            break;
        }
    }

    return 0;
}
