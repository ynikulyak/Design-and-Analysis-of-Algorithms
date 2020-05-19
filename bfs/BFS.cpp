/*
 * Title: BFS.cpp
 * Abstract: This program implements the Breadth-First Search algorithm. It reads an input file name and a starting node
 * from a user and displays the list of vertices visited..
 * Author: Yauheniya Nikulyak
 * ID: 2606
 * Date: 01/30/2020
 */

#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <list>
using namespace std;
//list of adjacent lists for each vertex
list<int> *adj;

void bfs(int start, int size){
    //mark-array for visited vertexes
    bool *visited = new bool[size];
    for(int i = 0; i < size; i++){
        visited[i] = false;
    }

    queue<int> myqueue;

    //push starting vertex for bfs
    myqueue.push(start);
    //mark this vertex as visited
    visited[start] = true;

    //while queue is not empty, take first in order vertex
    while(!myqueue.empty()){

        //take the first vertex in a queue
        start = myqueue.front();
        if(start != 0){
            cout<<" -> ";
        }
        cout<<start;
        //delete this vertex
        myqueue.pop();

        int i = 0;
        //traverse adjacent list of this popped vertex
        for(auto it = adj[start].begin(); it != adj[start].end(); ++it){
            //check if vertex from adjacent list was visited or not and whether it has an edge with popped vertex
            if(!(visited[i]) && *it == 1){
                //if not visited, mark as visited
                visited[i] = true;
                //push to the queue new visited vertex
                myqueue.push(i);
            }
            i++;
        }
    }

    delete []visited;
    visited = nullptr;
}

int main() {
    string fileName;
    ifstream file;
    string line;

    string input;
    int number;

    //request user for file name
    cout<<"Enter filename: ";
    cin>>fileName;

    file.open(fileName);
    //if something wrong when opening file, print error and stop the program
    if (file.fail()) {
        cout << "Error: " << strerror(errno);
        return 0;
    }

    int size;
    if(file.is_open()){
        //read first line of a file to get the number of vertexes
        getline(file, line);
        size = atoi(line.c_str());

        //create adjacent lists of this size
         adj = new list<int>[size];

         int j = 0;
         while(!file.eof()) {
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
    }
    //request user for start vertex
    cout<<"Enter a start vertex: ";
    cin>>input;
    number = stoi(input);

    bfs(number, size);

    return 0;
}
