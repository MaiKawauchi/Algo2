#include<iostream>
/* Number of vertices */
#define V 8

/* A function to print the solution matrix */
void printSolution(int reach[][V])
{
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
        std::cout << reach[i][j] << " ";
      std::cout << std::endl;
    }
}

/* Prints transitive closure of graph[][] using Warshall algorithm */
void Warshall(int graph[][V])
{
    /* reach[][] will be the output matrix that will finally have the
       shortest distances between every pair of vertices */
    int reach[V][V], i, j, k;

    /* Initialize the solution matrix */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            reach[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
    {
      /* Pick all vertices as source one by one */
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
    printSolution(reach);
}

int main()
{
  int graph[V][V] = {{0, 1, 0, 0, 1, 1, 0, 1},
                     {0, 0, 1, 0, 0, 0, 1, 0},
                     {0, 0, 0, 1, 0, 0, 1, 0},
                     {0, 0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 1, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 0, 1, 0},
                     {0, 0, 0, 0, 0, 0, 0, 1},
                     {0, 0, 0, 0, 0, 1, 1, 0},
                      };

    Warshall(graph);
    return 0;
}
