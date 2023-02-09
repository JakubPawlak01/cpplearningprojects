#include <iostream>
#include <climits>


struct weightedEdge{
    int s;
    int t;
    double w;
};

class WeightedGraph{
    private:
        double** adjWeightMatrix;
        double** w;
        int n;
        bool directed;

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
                    if(i == j)   
                    adjWeightMatrix[i][j] = 0;
                    else
                    adjWeightMatrix[i][j] = 999;
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

        void FloydW(){
            w = new double*[n];
            for (int i = 0; i < n; i++)
            {
                w[i] = new double[n];
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    w[i][j] = adjWeightMatrix[i][j];
                }
            }

            for (int k = 0; k < n; k++)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (w[i][j] > w[i][k] + w[k][j])
                        {
                            w[i][j] = w[i][k] + w[k][j];
                        }
                    }
                }
            }
        }

        void displayW(){
            std::cout << "Shortest path distances:" << std::endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    std::cout << w[i][j] << " ";
                }
                std::cout << std::endl;
            }
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
};
int main(){
    int n = 6, m =15;
    weightedEdge directedWeightedGraph[]={{0,4,2},{0,5,3},{1,0,4},{1,2,5},{1,4,4},{2,1,1},{2,3,9},{2,4,4},{3,2,1},{3,5,5},{4,0,7},{4,1,9},{4,3,2},{5,3,8},{5,4,9}};
    WeightedGraph h(n,m,directedWeightedGraph,true);
   std::cout<<h<<std::endl;
   //h.Dijkstra(1); 
   h.FloydW();
   h.displayW();

}