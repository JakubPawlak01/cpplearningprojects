#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>


struct edge{
    int s;
    int t;
};

class Graph{
    private:
        int** adjMatrix;
        int n;
        bool directed;

    public:
        Graph(int n, int m, edge edges[], bool directed){
            this->n = n;
            this->directed = directed;
            adjMatrix = new int*[n];
            for (int i = 0; i < n; i++)
            {
                adjMatrix[i] = new int[n];
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                   adjMatrix[i][j] = 0;
                }
            }
            for (int i = 0; i < m; i++)
            {
                int s = edges[i].s;
                int t = edges[i].t;
                adjMatrix[s][t] = 1;
                if (!directed)
                {
                    adjMatrix[t][s] = 1;
                }
            }   
        }

        ~Graph(){
            for (int i = 0; i < n; i++)
            {
            delete[] adjMatrix[i];
            }
        delete[] adjMatrix;
        }

        friend std::ostream& operator<<(std::ostream& out, Graph& g){
            for (int i = 0; i < g.n; i++)
            {
                for (int j = 0; j < g.n; j++)
                {
                 out << g.adjMatrix[i][j] << " ";
                }
            out << std::endl;
            }
            return out;
        }
};

int main(){
    int n = 6, m = 15;
    edge directedConnectedGraph[]={{0,4},{0,5},{1,0},{1,2},{1,4},{2,1},{2,3},{2,4},{3,2},{3,5},{4,0},{4,1},{4,3},{5,3},{5,4}}; //przykładowy graf
    Graph g(n,m,directedConnectedGraph,true);
    std::cout<<g<<std::endl;


    return 0;
}