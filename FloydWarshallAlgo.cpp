// It is different from Dijkstra and Bellman Ford because former two are single source shortest path algos
// Whereas Floyd Warshall tells shortest path from every node to every other node
// It is a multisource shortest path algorithm
// It also detects negative cycles
// It states to go via every node
// If the graph does not contain negative cycles, then we can apply dijkstra for every individual node

// Algorithm : 
// 1. Make an adjacency matrix to store the graph
// 2. Now store the distance from each node to every other node
// 3. first go via 0 then via 1 then via 2 .... then via n-1 nodes and keep on updating the distance to the minimum
// 4. If the distance of any node to itself becomes less than 0, that means the graph has negative cycle

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    
	    int n = matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e9;
	            }
	           // if(i==j) matrix[i][j]=0; Already given in question
	        }
	    }
	    
	    for(int via=0; via<n; via++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][via]+matrix[via][j]);
	            }
	        }
	    }
		
		// Negative cycle detection
		for (int i = 0; i < n; i++)
		{
			if(matrix[i][i]<0){
				// it implies negative cycle
			}
		}
		
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends