// Indegree - number of incoming edges to a node.
// TopoSort only valid for Directed Acyclic Graph
// We can place those nodes at the start of the sorted array that have an indegree of 0
// 1. In queue insert all those nodes with indegree 0.
// 2. Take the nodes out and decrease the indegree of the adjacent nodes by 1, ie, removing the edges
// 3. If indegree of any node becomes 0, insert it into the queue otherwise take out the nex node and do the same
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{

        // TC = O(V+E)

	    int indegree[V]={0}; 
	    for(int i=0;i<V;i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
                // inserting nodes in queue that have indegree 0
	        }
	    }
	    
	    vector<int> topo;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        
	        topo.push_back(node);
	        
	        for(auto it: adj[node]){
                // decreasing indegree of adjacent nodes by 1
	            indegree[it]--;
	            if(indegree[it] == 0){
                    // if indegree of any adjacent node becomes 0, pushing it into queue
	                q.push(it);
	            }
	        }
	    }
	    return topo;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends