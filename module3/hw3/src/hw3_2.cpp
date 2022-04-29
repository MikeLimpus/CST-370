/*
 * Title: hw3_2.cpp
 * Abstract: Read input graph data and output a path for travelling salesman
 *           problem
 * ID: 9753
 * Name: Mike Limpus
 * Date: 03/22/2022
 */

#include <iostream>
#include <vector>
using namespace std;

void permute(int input[], int start_index, int size); 
vector<vector<int> > permutations;
vector<int> fastest;
int main(void) {
    int num_vertices = 0, num_edges = 0, starting_vertex = 0;
    cin >> num_vertices;
    cin >> num_edges;
    int cost = 0;
    int lowest_cost = __INT_MAX__;
    int edge_data[num_edges][3];
    int edges[num_vertices];
    

    // Input the source vertex, destination vertex, and cost
    for (int i = 0; i < num_edges; ++i) {
        cin >> edge_data[i][0];
        cin >> edge_data[i][1];
        cin >> edge_data[i][2];
    }

    cin >> starting_vertex;

    for (int i = 0; i < num_edges; ++i) {
        edges[i] = i;
    }
    permute(edges, 0, num_vertices);
    // for (int i = 0; i < permutations.size(); ++i){
    //     for (int j = 0; j < permutations.at(i).size(); ++i) {
    //         cout << permutations[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << permutations.size();
    for (int i = 0; i < permutations.size(); ++i) {
        if(permutations.at(i).at(0) == starting_vertex) {
            permutations.at(i).push_back(starting_vertex); 
            for(int j = 1; j < permutations.at(i).size(); ++j) {
                int source = permutations.at(i).at(j-1), 
                destination = permutations.at(i).at(j); 
                for(int k = 0; k < num_edges; k++) {
                    if (edge_data[k][0] == source && edge_data[k][1] == destination) {
                        cost += edge_data[k][2];
                    }
                }
                if(cost < lowest_cost) {
                    lowest_cost = cost; 
                    fastest = permutations.at(i);
                } 
            }
            //cost = 0;
        }
    }

    if (fastest.size()==0 || cost == 0) {
        cout << "Path:" << endl << "Cost:-1" << endl;
    }
    else {
        cout << "Path:";
        for(int i = 0; i < fastest.size(); ++i) {
            cout << fastest.at(i);
            if (i != fastest.size()-1) {
                cout << "->";
            }
        }
        cout << endl << "Cost:" << lowest_cost << endl;
    }
}

void permute(int input[], int start_index, int size) {
    if (size == start_index + 1) {
        vector<int> temp;
        for (int i = 0; i < size; ++i) {
            temp.push_back(input[i]);
        }
        permutations.push_back(temp);   
    }
    else {
        for (int i = start_index; i < size; ++i) {
            int temp = input[i];
            input[i] = input[start_index];
            input[start_index] = temp;

            permute(input, start_index + 1, size);

            temp = input[i];
            input[i] = input[start_index];
            input[start_index] = temp; 
        }
    }
}
