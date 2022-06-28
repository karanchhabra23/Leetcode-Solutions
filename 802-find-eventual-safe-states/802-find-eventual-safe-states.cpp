class Solution {
public:
    vector<int>vis;
    bool dfs(int node,vector<vector<int>>& edge){
        vis[node] = 1;
        // mask|=(1<<node);
        for(int &child:edge[node]){
            if(vis[child]==0){
                if(dfs(child,edge)==false){
                    return false;
                }
            }
            else{
                if(vis[child]==1){
                    return false;
                }
            }
        }
        
        vis[node] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& edge) {
        int n = edge.size();
        vis.resize(n,0);
        vector<int>res;
        for(int i = 0;i<n;i++){
            if(vis[i]==2 || (vis[i]==0 && dfs(i,edge))){
                res.push_back(i);
            }
        }
        return res;
        
    }
};