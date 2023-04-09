// Strongly Connected Components(SCC)
// SCC are only valid for directed graphs
// A scc is that part of a graph where every pair of vertices are reachable to each other

// If we reverse all the edges in the graph then with dfs we will only be able to traverse in one scc, other scc will be unreachable

// Algorithm :

// Sort all the edges according to finishing time
// Finishing time: the node that finishes the dfs first is in the last scc and correspondingly other nodes
// Reverse the graph
// Do the dfs

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    private:
    void dfs(int node, vector<int> &vis, vector<vector<int>>& adj, stack<int> &st){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        
        st.push(node);
    }
    void dfs3(int node, vector<int> &vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        // Reversing the graph
        vector<int> adjT[V];
        for(int i=0; i<V; i++){
            vis[i]=0; // marking it unvisited to reuse it again later
            for(auto it: adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        int scc=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                scc++; // storing only the unique dfs in the scc
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends