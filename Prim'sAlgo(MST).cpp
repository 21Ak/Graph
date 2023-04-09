// 1. Make a minimum heap of (weight, node, parent node) and push (0,0,-1) in it 
// 2. make a visited array 
// 3. make a mst array to store minimum spanning tree 
// 4. stand at 0 and look at the adjacent node ie 1, if unvisited, store it in the min heap as (edgeweight from 0 to 1, 1, parent(0))
// 5. Do it for all the adjacent nodes of 0 and store them in the min heap, but do not mark the adjacent nodes visited
// 6. Mark them visited only when taking them out of the min heap, smallest comes out first
// 7. Now store the nodes in the mst array and add the edge weights to the sum
// 8. Repeat for all the nodes 


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(V,0);
        // (weight, node) since we only need sum, so no need to store parent
        pq.push({0,0});
        
        int sum=0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            
            if(vis[node]==1) continue;
            vis[node]=1;
            sum+=wt;
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edW = it[1];
                if(!vis[adjNode]){
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
