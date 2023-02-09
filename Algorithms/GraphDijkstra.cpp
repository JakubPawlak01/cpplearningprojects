#include <iostream>
#include <climits>



struct weightedEdge{
    int s;
    int t;
    double w;        //waga krawędzi
};

class WeightedGraph{
    private:
        double** adjWeightMatrix;
        int n;                //liczba węzłów
        bool directed;

        void Dijkstra(int s, int* d, bool* So, int* parent){
            d[s] = 0;
            for (int i = 0; i < n; i++) 
            {
                int v = find(s, d, So, n);
                if (v == -1) return;
                So[v] = true;
                for (int u = 0; u < n; u++) 
                {
                    if (adjWeightMatrix[v][u] > 0) 
                    {
                        int alt = d[v] + adjWeightMatrix[v][u];
                        if (alt < d[u])
                        {
                            d[u] = alt;
                            parent[u] = v;
                        }
                    }
                }

            }
            std::cout<<"weight: ";
            for(int i = 0 ; i< n; i++)
                {
                    std::cout<<d[i]<<" ";
                }
                std::cout<<std::endl<<"parent: ";
                for(int i = 0 ; i< n; i++)
                {
                    std::cout<<parent[i]<<" ";
                }
                std::cout<<std::endl;
        }

    public:
        WeightedGraph(int n, int m, weightedEdge edges[], bool directed){
            this->n = n;
            this->directed = directed;
            adjWeightMatrix = new double*[n];
            for (int i = 0; i < n; i++)
            {
                adjWeightMatrix[i] = new double[n];
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                   adjWeightMatrix[i][j] = 0;
                }
            }

            for (int i = 0; i < m; i++)
            {
                int s = edges[i].s;
                int t = edges[i].t;
                double w = edges[i].w;
                adjWeightMatrix[s][t] = w;
                if (!directed)
                {
                    adjWeightMatrix[t][s] = w;
                }
            }   
        }

        void Dijkstra(int s){
            int* d = new int[n];
            for(int i = 0; i<n; i++)
            {
                d[i] = INT_MAX;
            }
            bool* So = new bool[n];
            for(int i = 0; i<n; i++)
            {
                So[i] = false;
            }
            int* parent = new int[n];
            for(int i = 0; i<n; i++)
            {
                parent[i] = -1;
            }
            Dijkstra(s, d, So, parent);
        }    

        void printPath(int s, int t){
            int* d = new int[n];
            for(int i = 0; i<n; i++)
            {
                d[i] = INT_MAX;
            }
            bool* So = new bool[n];
            for(int i = 0; i<n; i++)
            {
                So[i] = false;
            }
            int* parent = new int[n];
            for(int i = 0; i<n; i++)
            {
                parent[i] = -1;
            }
            Dijkstra(s, d, So, parent);

            if (d[t] == INT_MAX)
            {
                std::cout << "There is no path from " << s << " to " << t << std::endl;
                return;
            }

            int path[n];
            int current = t;
            int pathLength = 0;
            while (current != -1)
            {
                path[pathLength] = current;
                current = parent[current];
                pathLength++;
            }

            std::cout << "Shortest path from " << s << " to " << t << ": ";
            for (int i = pathLength-1; i >= 0; i--)
            {
                std::cout << path[i] << " ";
            }
            std::cout << std::endl;
        }

        friend std::ostream& operator<<(std::ostream& out, WeightedGraph& g){
            for (int i = 0; i < g.n; i++)
            {
                for (int j = 0; j < g.n; j++)
                {
                 out << g.adjWeightMatrix[i][j] << " ";
                }
            out << std::endl;
            }
            return out;
        }

        int find(int s, int* d, bool* So, int n){
            int minDist = INT_MAX;
            int minIndex = -1;
            for (int i = 0; i < n; i++)
            {
                if (!So[i] && d[i] < minDist) 
                {
                    minDist = d[i];
                    minIndex = i;
                }
            }
            return minIndex;
        }
};

int main(){
    int n = 6, m =15;
    weightedEdge directedWeightedGraph[]={{0,4,2},{0,5,3},{1,0,4},{1,2,5},{1,4,4},{2,1,1},{2,3,9},{2,4,4},{3,2,1},{3,5,5},{4,0,7},{4,1,9},{4,3,2},{5,3,8},{5,4,9}};
    WeightedGraph h(n,m,directedWeightedGraph,true);
    std::cout<<h<<std::endl;
    h.Dijkstra(1); 
    h.printPath(0,4);
    return 0;
}
