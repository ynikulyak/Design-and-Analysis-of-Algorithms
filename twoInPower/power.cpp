/*
 * Title: power.cpp
 * Abstract: This program computes 2^n for a nonnegative integer n.
 * Author: Yauheniya Nikulyak
 * ID: 2606
 * Date: 01/18/2020
 */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//recursive function to calculate 2^n
long powerOfTwo(int n){
    //validation check
    if(n < 0){
        cout<<"Invalid power. Has to be nonnegative.";
        return -1;
    }
    //base case
    if(n == 0){
        return 1;
    }
    return 2*powerOfTwo(n-1);
}

int main() {
    string number;
    //request user input number
    cout<<"Enter a number: ";
    cin>>number;

    //convert string into int
    int power = stoi(number);
    //call recursive function
    long result = powerOfTwo(power);
    cout<<"Result: "<<result;

    return 0;
}


