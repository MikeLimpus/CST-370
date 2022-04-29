/*
 * Title: hw4_3.cpp
 * Abstract: Implement Kahn Algorithm for topological sorting 
 * ID: 9753
 * Name: Mike Limpus
 * Date: 04/05/2022
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void kahn(vector<vector<int> > input, int vertices, int edges);
void calc_in_degree(vector<int> in_degree, vector<vector<int> > input, int vertices, int edges);

int main(void) {
    int vertices, edges; 
    cin >> vertices;
    cin >> edges; 
    vector<vector<int> > input;
    for (int i = 0; i < edges; ++i) {
        int foo, bar;
        cin >> foo;
        cin >> bar; 
        cout << "HELLO";
        input[i].push_back(foo);
        input[i].push_back(bar);
        cout << "HELLO";
    }
    kahn(input, vertices, edges);

    return 0;
}

void kahn(vector<vector<int> > input, int vertices, int edges) {
    int visited = 0;
    queue<int> zero_in;
    vector<int> in_degree;
    calc_in_degree(in_degree, input, vertices, edges);
    for (int i = 0; i < vertices - 1; ++i) {
        if(in_degree[i] == 0) {
            zero_in.push(i);
        }
    }
    while(zero_in.size() > 0) {
        zero_in.pop();
        // Increment count of visited nodes by 1.
        visited++;
        int popped = zero_in.front();
        // Decrease in-degree by 1 for all its neighbouring nodes.
        // If in-degree of a neighbouring nodes is reduced to zero, then add it to the queue.
        in_degree[popped-1]--;
        if (in_degree[popped-1] == 0) 
            zero_in.push(popped-1);
        in_degree[popped+1]--;
        if (in_degree[popped+1] == 0)
            zero_in.push(popped+1);
    }
    // if(visited != vertices) {
    //     cout << "Impossible";
    //     return;
    // }
    for (int i = 0; i < vertices; ++i) {
        cout << "In-degree[" << i << "]:" << in_degree[i] << endl;
    }
}

void calc_in_degree(vector<int> in_degree, vector<vector<int> > input, int vertices, int edges) {
    for (int i = 0; i < vertices; ++i) {
        in_degree[i] = 0;
    }
    for (int i = 0; i < edges; ++i) {
        in_degree[input[i][1]]++; 
    }
}