// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    vector<int>topo;
	void top(int node, vector<int>&vis, vector<int>adj[]){
	    vis[node] =1;
	    for(auto &child:adj[node]){
	        if(!vis[child]){
	            top(child,vis,adj);
	        }
	    }
	    topo.push_back(node);
	    
	}
	void dfs(int node, vector<int>&vis,vector<vector<int>>&edge){
	    vis[node] = 1;
	    for(auto &child:edge[node]){
	        if(!vis[child]){
	            dfs(child,vis,edge);
            }
	    }
	} 
    int kosaraju(int v, vector<int> adj[])
    {
        //code here
        topo.clear();
        vector<int>vis(v,0);
        for(int i = 0;i<v;i++){
            if(!vis[i]){
                top(i,vis,adj);
            }
        }
        vector<vector<int>>edge(v);
        reverse(topo.begin(),topo.end());
        for(int i = 0;i<v;i++){
            vis[i] = 0;
            for(auto &it:adj[i]){
                edge[it].push_back(i);
            }
        }
        int ans =0;
        for(auto &it:topo){
            if(!vis[it]){
                ans++;
                dfs(it,vis,edge);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

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