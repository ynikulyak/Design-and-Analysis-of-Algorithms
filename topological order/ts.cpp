/*
 * Title: ts.cpp
 * Abstract: This program reads an input file name and displays the topological ordering.
 * Author: Yauheniya Nikulyak
 * ID: 2606
 * Date: 02/07/2020
 */

#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <fstream>

using namespace std;

//list of adjacent lists for each vertex
list<int> *adj;

void topologicalSort(int size) {
    //create array for number of incoming edges for each node
    int *incomingEdges = new int[size];

    //initialize array with 0 incoming edges at the beginning
    for (int k = 0; k < size; k++) {
        incomingEdges[k] = 0;
    }

    //run through each node's adjacent list to count incoming edges for each node
    for (int i = 0; i < size; i++) {
        int j = 0;
        for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
            if (*it == 1) {
                incomingEdges[j]++;
            }
            j++;
        }
    }

    cout << "Topological sort: ";

    for (int index = 0; index < size; index++) {
        //variable to store smallest node with 0 incoming edges
        int min = size;

        //create a vector in case there are more than one node with 0 incoming edges
        vector<int> zeroDegree;
        //find all node with 0 incoming edges and put them in vector
        for (int i = 0; i < size; i++) {
            if (incomingEdges[i] == 0) {
                zeroDegree.push_back(i);
            }
        }

        //to follow the asc. order convention - find the smallest node with 0 incoming edges
        for (int i = 0; i < zeroDegree.size(); i++) {
            int number = zeroDegree.at(i);
            if (number < min) {
                min = number;
            }
        }

        //display node in topological ordering
        if (index == size - 1) {
            cout << min;
        } else {
            cout << min << " -> ";
        }

        int j = 0;
        //decrement number of incoming edges for each adjacent nodes of a currently displayed node
        for (auto it = adj[min].begin(); it != adj[min].end(); it++) {
            if (*it == 1) {
                incomingEdges[j]--;
            }
            j++;
        }
        //"delete" currently displayed node
        incomingEdges[min] = -1;
    }

    delete[]incomingEdges;
    incomingEdges = nullptr;
}

int main() {
    string fileName;
    ifstream file;
    string line;

    //request user for file name
    cout << "Enter filename: ";
    cin >> fileName;

    file.open(fileName);
    //if something wrong when opening file, print error and stop the program
    if (file.fail()) {
        cout << "Error: " << strerror(errno);
        return 0;
    }

    int size;
    if (file.is_open()) {
        //read first line of a file to get the number of vertexes
        getline(file, line);
        size = atoi(line.c_str());

        //create adjacent lists of this size
        adj = new list<int>[size];

        int j = 0;
        while (!file.eof()) {
            //read whole line
            getline(file, line);

            int num = 0;
            //push elements in adjacent list escaping whitespaces
            for (int i = 0; i < line.length(); i++) {
                if (iswspace(line[i])) {
                    continue;
                } else {
                    int n = line[i] - '0';
                    adj[j].push_back(n);
                }
            }
            j++;
        }

        topologicalSort(size);
        delete[] adj;
    }
    return 0;
}

