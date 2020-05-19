/*
 * Title: assignment.cpp
 * Abstract: This program reads the assignment costs of each person from a user and determines the best assignment.
 * Author: Yauheniya Nikulyak
 * ID: 2606
 * Date: 01/31/2020
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//for user input costs for jobs
int **matrix;
//to store minimum cost of all permutations
int minim = INT_MAX;
//to store combination with minimum cost
int *p;
//keep track of permutations
int k = 1;

void calculateReesult(int arr[], int size) {

    int cost = 0;
    cout << "Permutation " << k << ": <";

    //computer cost of permutation
    for (int i = 0; i < size; i++) {
        int col = arr[i];
        cost += matrix[i][col];
    }

    //check if new cost less then previous ones
    if(cost < minim){
        minim = cost;
        //store combination with minimum cost
        p = new int[size];
        for(int i = 0; i < size; i++){
            p[i] = arr[i];
        }
    }

    //display the result of permutation
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            cout << arr[i] + 1 << "> => total cost: " << cost;
        } else {
            cout << arr[i] + 1 << ", ";
        }
    }
    cout << endl;
    k++;
}

//create all combinations using recursion
void permutation(int arr[], int start, int end) {
    //base case, when start reaches end of array
    if (start == end) {
        calculateReesult(arr, end + 1);
        return;
    }

    for (int i = start; i <= end; i++) {
        //swapping numbers
        int temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        //fixing one first digit and calling permutation on the rest of the digits
        permutation(arr, start + 1, end);
        //swapping numbers
        int temp1 = arr[start];
        arr[start] = arr[i];
        arr[i] = temp1;
    }
}

int main() {

    string input;
    int jobs;

    //request user for number of jobs
    cout << "Enter number of jobs: ";
    cin >> input;
    //convert user input into integer
    jobs = stoi(input);

    //create 2D matrix that represent each person and costs for each job for each person
    matrix = new int *[jobs];
    for (int i = 0; i < jobs; ++i) {
        matrix[i] = new int[jobs];
    }

    cout << "Enter assignment costs of " << jobs << " persons.";
    cout << endl;

    cin.ignore();

    //request user input for costs of each job for each person
    for (int m = 0; m < jobs; m++) {
        //store costs
        vector<int> array;
        string cost;

        cout << "Person " << m + 1 << ": ";
        getline(cin, cost);

        //initialize vector only with numbers ignoring whitespaces
        for (int i = 0; i < cost.length(); i++) {
            if (iswspace(cost[i])) {
                continue;
            } else {
                array.push_back(cost[i] - '0');
            }
        }

        //initialize matrix with costs for each person
        for (int j = 0; j < jobs; j++) {
            matrix[m][j] = array[j];
        }
    }

    //create array of length "jobs" and initialize it from 0 to jobs-1 to use it in permutation to get indexes and use
    //those indexes to get matrix element
    int arrPermutation[jobs];

    for (int i = 0; i < jobs; i++) {
        arrPermutation[i] = i;
    }
    permutation(arrPermutation, 0, jobs - 1);

    //print the low cost and combination
    cout<<endl<<"Solution: <";
    for(int i = 0; i < jobs; i++){
        if(i == jobs-1) {
            cout << p[i] + 1 << "> => total cost: "<<minim;
        }else{
            cout << p[i] + 1 << ", ";
        }
    }

    for (int i = 0; i < jobs; ++i) {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;

    delete[] p;
    p = nullptr;
    return 0;
}
