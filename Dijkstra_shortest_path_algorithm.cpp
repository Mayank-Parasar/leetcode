//
// Created by Mayank Parasar on 11/7/20.
//

/*
 * Code Dijkstra shortest path findinding algorithm
 * and use it to find the shortest path from all nodes
 * to all other nodes in a graph/topology coded in as
 * a connectivity matrix (adjacency matrix)
 * */

#include <iostream>
#include <vector>
#include <deque>

#define V 9
using namespace  std;

vector<vector<int>> Mesh3x3=   {{0,1,0,1,0,0,0,0,0}, // 1st row
                               {1,0,1,0,1,0,0,0,0}, // 2nd row
                               {0,1,0,0,0,1,0,0,0}, // 3rd row
                               {1,0,0,0,1,0,1,0,0}, // 4th row
                               {0,1,0,1,0,1,0,1,0}, // 5th row
                               {0,0,1,0,1,0,0,0,1}, // 6th row
                               {0,0,0,1,0,0,0,1,0}, // 7th row
                               {0,0,0,0,1,0,1,0,1}, // 8th row
                               {0,0,0,0,0,1,0,1,0}};// 9th row

vector<vector<int>> hop_matrix;

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix/ connectivity matrix
// representation
void dijkstra(vector<vector<int>> graph, int src)
{
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included
    // in shortest path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
//    printSolution(dist);
    vector<int> vect(dist, dist+V);
    hop_matrix.push_back(vect);
}

int main() {

    for (int ii = 0; ii < V; ii ++)
        dijkstra(Mesh3x3, ii);

    for(auto i : hop_matrix) {
        for(auto k : i) {
            cout << k << " ";
        }
        cout << endl;
    }

return 0;
}