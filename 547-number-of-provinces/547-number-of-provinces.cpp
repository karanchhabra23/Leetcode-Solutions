class Solution {
public:

    void dfs(int node, int n,vector<vector<int>>&a,vector<int>&vis){
        vis[node] = 1;
        
        for(int i = 0;i<n;i++){
            if(node!=i && a[node][i] == 1 && vis[i]==0){
                dfs(i,n,a,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        
        vector<int>vis(n,0);
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,n,a,vis);
            }
        }
        return ans;
    }
};