#include <bits/stdc++.h>

using namespace std;

class Graph{

    int V;
    vector<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v, bool *visited);
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

void Graph::DFS(int v, bool *visited){

    visited[v] = true;
    cout << v << " ";

    for(int i=0; i<adj[v].size(); i++){
        if(visited[adj[v][i]]==false){
            DFS(adj[v][i], visited);
        }
    }
}

bool Graph :: DetectCycle(int v, bool *visited, bool *recStack){
    if(visited[v] == false){
        visited[v] = true;
        recStack[v] = true;
        for(int i=0; i<adj[v].size(); i++){
            if(!visited[adj[v][i]] && DetectCycle(adj[v][i], visited, recStack)){
                return true;
            }
            else if(recStack[adj[v][i]]){
                return true;
            }
            
        }
    }
    recStack[v] = false;
    return false;
}

bool Graph :: isCyclic(){
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i=0; i<V; i++){
        visited[i] = false;
        recStack[i] = false;
    }
    //DFS(0, visited);
    for(int i=0; i<V; i++){
        
        if(DetectCycle(i, visited, recStack)){
            return true;
        }
        // for(int i=0; i<V; i++){
        //     visited[i] = false;
        //     recStack[i] = false;
        // }
        //DFS(i, visited);
    }

    return false;
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

bool Graph::isCyclicIterative(){
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for(int i=0; i<V; i++){
        stack<int> s;
        s.push(i);

        while(!stack.empty()){
            int cur = stack.top();
            stack.pop();
            
            if(!visited[cur]){
                visited[cur] = true;
                recStack[cur] = true;

                for(int i<adj[cur].size(); i++){
                    if(!visited[adj[cur][i]]){
                        stack.push(adj[cur][i]);
                    }

                }
            }
        }

    }
}


int main(){
    
    int T;
    cin >> T;
    while(T--){
        int V, M;
        cin >> V >> M;
        Graph g(V);
        int v, w;
        for(int i=0; i<M; i++){
           cin >> v >> w;
           g.addEdge(v,w);
        }
        if(g.isCyclicIterative()){
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
    }

    return 0;
}