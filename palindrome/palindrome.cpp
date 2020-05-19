/*
 * Title: palindrome.cpp
 * Abstract: This program reads a string of characters from user and determines if the string is a palindrome or not.
 * Author: Yauheniya Nikulyak
 * ID: 2606
 * Date: 01/11/2020
 */

#include <iostream>
using namespace std;

int main() {
    string word;
    //request user input
    cout<<"Input string: ";
    cin>>word;

    //determine the size of array of characters
    int size = word.length();
    //create dynamic array of characters
    char *p = new char[size];
    //initialize array
    for(int i = 0; i < size; i++){
        p[i] = word[i];
    }

    //loop till middle of the array using 2 pointers
    for(int i = 0, j = size -1; i<j; i++, j--){
        //if found characters that are not equal, stop the loop
        if(p[i] != p[j]){
            cout<<"NO, it's not a palindrome";
            return 0;
        }
    }
    cout<<"YES, it's a palindrome";

    delete []p;
    p = nullptr;
    return 0;
}
