/*
 * Title: prim.cpp
 * Abstract: This program implements the Prim’s algorithm to calculate the minimum spanning tree (MST) from an input
 * graph. The program asks a user for an input file name that includes the input graph information. Then, presents the
 * edges to be added one-by-one to construct the MST.
 * Author: Yauheniya Nikulyak
 * ID: 2606
 * Date: 02/21/2020
 */

#include <iostream>
#include <fstream>
#include <set>
#include <sstream>

using namespace std;

int **matrix;

void prim(int start, int size, int vertices) {

    //initialize min edge as infity at the beginning
    int min = INT_MAX;
    //vertex on edge'd end
    int end = -1;
    //beginning of edge
    int begin = start;
    //set for visited vertices
    set<int> included;

    //add starting vertex to the set
    included.insert(start);
    //varialbe to keep track of number of included vertices in set
    int setSize = 1;
    //run till set includes all vertices
    while (setSize < vertices) {
        //find the smallest distance to the next not included vertex
        for (auto it = included.begin(); it != included.end(); ++it) {
            for (int i = 0; i < size; i++) {
                if (matrix[*it][i] < min) {
                    min = matrix[*it][i];
                    end = i;
                    begin = *it;
                }
            }
        }
        //check if you need to include found vertex with the smallest edge weight in to set
        if (included.count(end) == 0) {
            included.insert(end);
            setSize++;
            matrix[begin][end] = INT_MAX;
            matrix[end][begin] = INT_MAX;
        }else { //don't include if vertex has been already visited
            matrix[begin][end] = INT_MAX;
            matrix[end][begin] = INT_MAX;
            min = INT_MAX;
            continue;
        }

        cout << "New edge: " << begin << ", " << end << " - cost " << min << endl;
        min = INT_MAX;
    }
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

    int vertices;
    int edges;
    int row, col, weight;

    if (file.is_open()) {
        //read first line of a file to get the number of vertexes
        getline(file, line);
        vertices = atoi(line.c_str());

        getline(file, line);
        edges = atoi(line.c_str());

        matrix = new int *[vertices + 1];
        for (int i = 0; i <= vertices; ++i) {
            matrix[i] = new int[vertices + 1];
        }

        //read each line and initialize 2D matrix
        while (!file.eof()) {
            getline(file, line);
            istringstream iss(line);
            iss >> row >> col >> weight;

            matrix[row][col] = weight;
            matrix[col][row] = weight;
        }

        //initialize all values to infinity that are less than 1
        for (int i = 0; i <= vertices; i++) {
            for (int j = 0; j <= vertices; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][j] = INT_MAX;
                }
            }
        }

        int start;
        //request user for starting vertex
        cout << "Enter the first vertex to start: ";
        cin >> start;

        prim(start, vertices + 1, vertices);

        for (int i = 0; i < vertices; ++i) {
            delete[] matrix[i];
            matrix[i] = nullptr;
        }
        delete[] matrix;
        matrix = nullptr;
        file.close();
    }


    return 0;
}
