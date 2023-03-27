// 1. Dijkstra's Algorithm is used to find the shortest path in the graph
// 2. It can be implemented using Queue, Priority Queue and Set.
// 4. Dijkstra doesn't work in negative weight graphs or negative cycle graphs
//    because on every traversal distance reduces and the program doesn't stop.

// Using Priority queue

// 1. Create a minimum heap to store pair of distance of node and node
// 2. create a distance array and store 0 for source node and rest store infinity
// 3. take out the node from min-heap and go to its adjacent node and store min(current distance, distance already stored)
// 4. store the pair of the distance of adjacent node and the adjacent node in the min-heap
// 5. Repeat until the min-heap is empty
// Time Complexity : O( E + logV ) : E=total edges, V=number of nodes

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Min-Heap of pair
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        
        // Distance Array
        vector<int> dist(V);
        for(int i=0;i<V;i++){
            dist[i]=1e9;
        }
        
        dist[S]=0; // distance from source to source is 0
        pq.push({0,S}); // pushing pair of {source distance, source node} in pq
        
        // iterating till pq is empty
        while(!pq.empty()){
            int dis=pq.top().first; //distance
            int node=pq.top().second; //node
            pq.pop(); //erasing top element from pq
            
            for(auto it: adj[node]){
                // "it" is vector containing two elements
                // at index 1 : edgeWeight
                // at index 2 : adjNode
                int edgeWeight=it[1];
                int adjNode=it[0];
                
                if(dis+edgeWeight < dist[adjNode]){
                    //if new distance is shorter than the previously stored distance
                    // replace it with new distance
                    dist[adjNode] = dis+edgeWeight;
                    // Also store the new, better distance in the pq, along with its node
                    pq.push({dist[adjNode], adjNode});
                }
            }
            
        }
        
        return dist;
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
