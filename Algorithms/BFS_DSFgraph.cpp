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

        void dfs(int s, int* visited, int* parent){
            visited[s] = 1;
            std::cout << s << " ";
            for (int i = 0; i < n; i++)
            {
                if (adjMatrix[s][i] && !visited[i])
                {
                parent[i] = s;
                dfs(i, visited, parent);
                }
            }
        }

        void bfs(int s, int* visited, int* parent){
            visited[s] = 1;
            std::queue<int> kolejka;
            kolejka.push(s);
            while(!kolejka.empty())
            {
                s = kolejka.front();
                kolejka.pop();
                std::cout << s << " ";
                for(int i = 0; i<n; i++)
                {
                    if(adjMatrix[s][i] && !visited[i])
                    {
                        visited[i] = 1;
                        parent[i] = s;
                        kolejka.push(i);

                    }
                }
            }
        }

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

        void dfs(int s)
        {
            int* visited = new int[n];
            for (int i = 0; i < n; i++)
            {
                visited[i] = 0;
            }
            int* parent = new int[n];
            for (int i = 0; i < n; i++)
            {
                parent[i] = 0;
            }
            dfs(s, visited, parent);
/*
            std::cout<<std::endl;
            std::cout<<std::endl;
            for (int i = 0; i < n; i++)
            {
                std::cout<<parent[i]<<" ";
            }
*/
        }

        void bfs(int s){
            int* visited = new int[n];
            for (int i = 0; i < n; i++)
            {
                visited[i] = 0;
            }
            int* parent = new int[n];
            for (int i = 0; i < n; i++)
            {
                parent[i] = 0;
            }
            bfs(s, visited, parent);
            std::cout<<std::endl;
            std::cout<<std::endl;
            for (int i = 0; i < n; i++)
            {
                std::cout<<parent[i]<<" ";
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
    g.bfs(0);

    return 0;
}