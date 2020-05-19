/*
 * Title: all_subsets.cpp
 * Abstract: This program displays all subsets of a set by reading n characters from a user and display all subsets of
 * the characters. Characters are always distinct.
 * Author: Yauheniya Nikulyak
 * ID: 2606
 * Date: 01/20/2020
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct node {
    int data;
    struct node *left, *right;
};
int count = 0;
void BSTk(struct node *root, int k)
{
    if (root != NULL && count <= k)
    {
        BSTk(root->right, k);
        count++;
        if (count == k)
            printf("%d ", root->data);
        BSTk(root->left, k);
    }
}

int main() {

    string number;
    string userInput;
    vector<char> array;

    //request the number of characters
    cout << "Number of input characters: ";
    cin >> number;
    //convert string into int
    int size = stoi(number);

    //validate desired number of characters
    if (size < 1 || size > 15) {
        cout << "Invalid number of characters.";
        return 0;
    }

    //request user input - characters
    cout << "Enter " << size << " characters: ";
    cin.ignore();
    //read whole line of user input
    getline(cin, userInput);

    //initialize vector only with chars ignoring whitespaces
    for (int i = 0; i < userInput.length(); i++) {
        if (iswspace(userInput[i])) {
            continue;
        } else {
            array.push_back(userInput[i]);
        }
    }

    //sort user input to create subsets in alphabetical order
    sort(array.begin(), array.end());

    //call recursive function to create all subsets
    allSubsets(array, -1);

    //sort all subsets by size in asc. order
    for(int i = 0; i < result.size()-1; i++){
        for(int j = i+1; j < result.size(); j++) {
            if (result[i].size() > result[j].size()) {
                vector<char> temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }
    //display all subsets of a set
    cout<<"=======All Subsets======"<<endl;
    for(vector<char> v : result){
        if(v.empty()){
            cout<<"empty"<<endl;
        }else{
            cout<<"{";
        }
        for(int i = 0; i < v.size(); i++){
            if(i == v.size()-1){
                cout<<v[i]<<"}"<<endl;
            }else {
                cout << v[i] << ", ";
            }
        }
    }
    return 0;
}
