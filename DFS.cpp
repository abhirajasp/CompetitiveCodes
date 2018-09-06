#include <bits/stdc++.h>

using namespace std;

class Graph{

    int V;
    vector<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v, bool *visited, int I, int **a, int count);



};

Graph::Graph(int V){
    this->V = V;
    this->adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w){
    this->adj[v].push_back(w);
}

void Graph::DFS(int v, bool *visited, int I, int **a, int count){

    visited[v] = true;
    a[I][v] = count;
    cout << v << " ";

    for(int i=0; i<adj[v].size(); i++){
        if(visited[adj[v][i]]==false){
            DFS(adj[v][i], visited, I, a, count+1);
        }
    }
}

int main(){
    Graph g(4);
    
    int T;
    cin >> T;
    while(T--){
        int V;
        cin >> V;
        Graph g(V);
        int v, w;
        for(int i=0; i<V-1; i++){
            cin >> v >> w;
            v--;    w--;
            g.addEdge(v,w);
        }
        int ans = 0;
        int **a;
        a = new int *[V];
        for(int i = 0; i <V; i++)
            a[i] = new int[V];

        for(int i=0; i<V; i++){
            bool visited[V];
            for(int i=0; i<4; i++)
                visited[i] = false;
            g.DFS(i, visited, i, a, 0);
            
            for(int j=0; j<V; j++){
                if(a[i][j] != 0 && a[i][j]%2 == 0){
                    ans++;
                }
            }
        }
        cout << ans << endl;
        
    }

    return 0;
}