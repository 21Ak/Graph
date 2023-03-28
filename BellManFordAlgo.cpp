// 1. Dijkstra fails for negative graph edges as it keeps on running in an infinite loop
// 2. Bellman Ford algoirthm works for negative graph edges
// 3. It can tell shortest distance to all the nodes from the source
// 4. Bellman Ford also helps to detect negative cycle
// 5. It is applicable only in directed graph
// 6. To implement it in undirected graph, we need to represented bidriectional edges into two directed edges

// Algorithm :

// Relax all the edges N-1 times (N - number of nodes)
// that is
// for(i = 0; i<N-1; i++){
//     if(dist[u] + wt < dist[v]){
//         dist[v] = dist[u] + wt
//     }
// }
// This algorithm gives us the shortest distance to every node

// To detect a negative cycle
// Perform Nth relaxation, 
// if distance of any node changes => it means graph has a negative cycle
// otherwise => no negative cycle

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int> dist(V, 1e8);
        dist[S]=0;
        
        for(int i=0; i<V-1; i++){
            for(auto it: edges){
                int node = it[0];
                int adjNode = it[1];
                int edW = it[2];
                
                if(dist[node] + edW < dist[adjNode] && dist[node]!=1e8){
                    dist[adjNode] = dist[node] + edW;
                }
            }
        }
        
        
        for(auto it: edges){
            int node = it[0];
            int adjNode = it[1];
            int edW = it[2];
            
            if(dist[node]!=1e8 && dist[node]+edW < dist[adjNode]){
                return {-1};
            }
        }
        
        
        return dist;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
