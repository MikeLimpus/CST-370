/*
 * Title: main_hw1_3.cpp
 * Abstract: Convert directed graph data into adjacency list format
 * ID: 9753
 * Name: Mike Limpus
 * Date: 03/08/2022
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int vertices, edges;
    cin >> vertices; 
    cin >> edges;
    vector< vector<int> > adjacency_matrix(edges);

    // if there are no edges, then just show the vertices and exit
    if (edges == 0) {
        for(int i = 0; i < vertices; ++i) {
            cout << i << endl;
        }
        return 0;
    }

    for(int i = 0; i < edges; ++i) {
        int m, n;
        cin >> m;
        cin >> n;

        adjacency_matrix[m].push_back(n);
    }

    for (int i = 0; i < edges; ++i) {
        sort(adjacency_matrix[i].begin(), adjacency_matrix[i].end());
    }
    
    for(int i = 0; i < vertices; ++i) {
        cout << i;
        for(int j = 0; j < adjacency_matrix[i].size(); ++j) {
            cout << "->" << adjacency_matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}

