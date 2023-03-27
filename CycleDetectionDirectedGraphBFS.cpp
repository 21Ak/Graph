// Using Kahn's Algorithm
// Since topo sort is only applicable to DAG
// We will try to apply topo sort here
// If topo sort has elements equal to V it means it is DAG
// Otherwise it means there is a cycle in the graph

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // TC = O(V+E)

        int indegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                // inserting nodes in queue that have indegree 0
            }
        }

        // vector<int> topo;
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // topo.push_back(node);
            cnt++; // counting elements in the topo sort array

            for (auto it : adj[node])
            {
                // decreasing indegree of adjacent nodes by 1
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    // if indegree of any adjacent node becomes 0, pushing it into queue
                    q.push(it);
                }
            }
        }

        if (cnt == V)
        {
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends