#include <bits/stdc++.h>

using namespace std;

class Graph{

    int V;
    vector<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v, bool *visited);
    void DFS(int s);
    bool isCyclic();
    bool DetectCycle(int v, bool *visited, bool *recStack);


};

Graph::Graph(int V){
    this->V = V;
    this->adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w){
    this->adj[v].push_back(w);
}

void Graph::DFS(int s){

    vector<bool> visited(V, false);

    stack<int> stck;

    stck.push(s);
    
    while(!stck.empty()){
        int current = stck.top();
        stck.pop();

        if(visited[current]==false){
            visited[current] = true;
            cout << current << " ";
        }
        
        for(int i=0; i<adj[current].size(); i++){
            if(!visited[adj[current][i]]){
                stck.push(adj[current][i]);
            }
        }
    }
}

int main()
{
    Graph g(5); // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);

    cout << "Following is Depth First Traversal\n";
    g.DFS(0);

    return 0;
}
