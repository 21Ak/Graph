// Edges have weights
// So we need to find out the shortest path to go from one node to other taking edge weights into consideration

// Algorithm :
// Store the graph as aan array of vector of pairs, pair containing adjacent node and edge weight
// Now do a topo sort on this graph (let say using DFS)
// Now take the nodes out of stack and relax the edges, to relax the edges declare a distance array of elements value to infinity
// Mark the source node in distance as 0
// Now go to the adjacent nodes and update the distance of that node to the min(dist+edgeweight, dist already stored in the array)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    void topoSort(int node, vector<pair<int,int>> adj[], int vis[], stack<int> &st){
        vis[node]=1;
        for(auto it: adj[node]){
            int v=it.first;
            if(!vis[v]){
                topoSort(v,adj, vis, st);
            }
        }
        
        st.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // Creating a weighted graph
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0]; //Current Node
            int v=edges[i][1]; //Adjacent Node
            int wt=edges[i][2]; //Edge Weight
            adj[u].push_back({v,wt});
        }
        
        //Step 1 find the topo sort
        // O(N + M)
        int vis[N]={0};
        stack<int> st;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                topoSort(i, adj, vis, st);
            }
        }
        
        // Step 2 Do the distance thing
        vector<int> dist(N);
        for(int i=0;i<N;i++) dist[i]=1e9;
        dist[0]=0;
        // O(N+M)
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            // Going to all the adjacent nodes
            for(auto it: adj[node]){
                int v=it.first;
                int wt=it.second;
                
                dist[v] = min(dist[v], dist[node]+wt);
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends