//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Number of vertices
#define V 8

#define INF 1000000000

/* A utility function to print solution */
void printSolution(int dist[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
              std::cout << "INF" << "   ";
            else
              std::cout << dist[i][j]<<"  ";
        }
        std::cout << std::endl;
    }
}

void Floyd(int graph[][V])
{
    /* dist[][] will be the output matrix hat will finally have the shortest
    distances between every pair of vertices */
    int dist[V][V], i, j, k;

    /* Initialize the solution matrix */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                  dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    /* Print the shortest distance matrix */
    printSolution(dist);
}

int main()
{
  int graph[V][V] = {{0, 48, INF, 8, 20, INF, 20, INF },
                     {INF, 0, 24, INF, 9, INF, 76, 29},
                     {97, INF, 0, INF, INF, INF, 18, 1},
                     {INF, 52, 34, 0, 29, INF, INF, INF},
                     {INF, INF, INF, INF, 0, 10, INF, INF},
                     {INF, 10, 85, 43, INF, 0, 41, 29},
                     {INF, INF, INF, 76, 38, INF, 0, INF},
                     {28, 42, INF, 77, 21, INF, 11, 0},
  };
  Floyd(graph);
  return 0;
}
