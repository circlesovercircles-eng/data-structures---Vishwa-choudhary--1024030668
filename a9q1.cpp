#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adj; // {vertex, weight}
    
public:
    Graph(int v) : V(v), adj(v) {}
    
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected
    }
    
    // 1. BFS using queue
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        
        visited[start] = true;
        q.push(start);
        
        cout << "BFS from " << start << ": ";
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            cout << curr << " ";
            
            for (auto& neighbor : adj[curr]) {
                int v = neighbor.first;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
    
    // 2. DFS using stack (iterative)
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;
        
        visited[start] = true;
        s.push(start);
        
        cout << "DFS from " << start << ": ";
        while (!s.empty()) {
            int curr = s.top(); s.pop();
            cout << curr << " ";
            
            for (auto& neighbor : adj[curr]) {
                int v = neighbor.first;
                if (!visited[v]) {
                    visited[v] = true;
                    s.push(v);
                }
            }
        }
        cout << endl;
    }
    
    // 3a. Kruskal MST
    void KruskalMST() {
        vector<Edge> edges;
        for (int u = 0; u < V; u++)
            for (auto& p : adj[u])
                if (u < p.first) // Avoid duplicates
                    edges.push_back(Edge(u, p.first, p.second));
        
        // Sort edges by weight
        sort(edges.begin(), edges.end(), 
             [](const Edge& a, const Edge& b) { return a.w < b.w; });
        
        vector<int> parent(V);
        for (int i = 0; i < V; i++) parent[i] = i;
        
        auto find = [&](auto& self, int x) -> int {
            return parent[x] == x ? x : parent[x] = self(self, parent[x]);
        };
        
        int mstCost = 0;
        cout << "Kruskal MST edges:\n";
        for (auto& e : edges) {
            int px = find(find, e.u), py = find(find, e.v);
            if (px != py) {
                parent[px] = py;
                mstCost += e.w;
                cout << e.u << "-" << e.v << "(" << e.w << ") ";
            }
        }
        cout << "\nMST Cost: " << mstCost << endl;
    }
    
    // 3b. Prim MST
    void PrimMST(int start) {
        vector<int> key(V, INT_MAX), parent(V, -1);
        vector<bool> inMST(V, false);
        key[start] = 0;
        
        cout << "Prim MST (from " << start << "):\n";
        for (int count = 0; count < V; count++) {
            int u = -1, minKey = INT_MAX;
            for (int v = 0; v < V; v++) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }
            
            if (u == -1) break;
            inMST[u] = true;
            cout << "Added " << u << "(key=" << minKey << ") ";
            
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;
                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }
        cout << endl;
    }
    
    // 4. Dijkstra
    void Dijkstra(int start) {
        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);
        dist[start] = 0;
        
        for (int count = 0; count < V; count++) {
            int u = -1, minDist = INT_MAX;
            for (int v = 0; v < V; v++) {
                if (!visited[v] && dist[v] < minDist) {
                    minDist = dist[v];
                    u = v;
                }
            }
            
            if (u == -1) break;
            visited[u] = true;
            
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;
                if (!visited[v] && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
        
        cout << "Dijkstra distances from " << start << ":\n";
        for (int i = 0; i < V; i++)
            cout << start << "->" << i << ": " << dist[i] << endl;
    }
};

int main() {
    Graph g(5);
    
    // Graph edges: 0-1(10), 0-3(5), 1-2(1), 1-3(2), 2-3(6), 2-4(4), 3-4(2)
    g.addEdge(0, 1, 10);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 6);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 4, 2);
    
    cout << "=== Vector-Based Graph Algorithms ===\n\n";
    
    cout << "1. BFS:\n"; g.BFS(0);
    cout << "\n2. DFS:\n"; g.DFS(0);
    
    cout << "\n3a. Kruskal:\n"; g.KruskalMST();
    
    cout << "\n3b. Prim:\n"; g.PrimMST(0);
    
    cout << "\n4. Dijkstra:\n"; g.Dijkstra(0);
    
    return 0;
}
