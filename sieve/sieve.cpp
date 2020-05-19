/*
 * Title: sieve.cpp
 * Abstract: This program implements the sieve of Eratosthenes algorithm for generating consecutive primes not exceeding
 * any given integer n > 1.
 * Author: Yauheniya Nikulyak
 * ID: 2606
 * Date: 01/12/2020
 */
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int number;
    //request user input
    cout<<"Input number: ";
    cin>>number;
    //validate user input
    if(number <=1){
        cout<<"Invalid number. Your number has to be greater then 1.";
        return 0;
    }

    //create dynamic array for all numbers from 2 till number inclusive
    int *A = new int[number+1];
    //initialize first two elements of array as 0 as we start from index 2
    A[0] = 0;
    A[1] = 0;
    //initialize array from 2 till user input inclusive
    for(int p = 2, i = 0; p <= number; p++){
        A[p] = p;
    }

    //loop till square root of user input number
    for(int p = 2; p <= sqrt(number); p++){
        //if element in aaray is not 0, initialize every pth element of array as 0
        if(A[p] != 0){
            int j = p*p;
            while(j <= number){
                A[j] = 0;
                j = j + p;
            }
        }
    }

    int count = 0;
    //check how many prime numbers in array A
    for(int i = 0; i <= number; i++){
        if(A[i] != 0){
            count++;
        }
    }

    int j = 0;
    //create dynamic array to copy all prime numbers from array A into array L
    int *L = new int[count];
    for(int p = 2; p <= number; p++){
        if(A[p] != 0){
            L[j] = A[p];
            j++;
        }
    }

    //print out all prime numbers
    for(int i = 0; i < count; i++){
        if(i == count-1){
            cout<<L[i];
        }else {
            cout << L[i] << ", ";
        }
    }

    delete []A;
    A = nullptr;
    delete []L;
    L = nullptr;
    return 0;
}
