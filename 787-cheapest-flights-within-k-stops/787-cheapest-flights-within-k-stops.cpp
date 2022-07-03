class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>dis(k+2,vector<int>(n+1,INT_MAX));
        for(int i = 0;i<=k+1;i++){
            dis[i][src]=0;
        }
        
        for(int i = 1;i<=k+1;i++){
            for(auto &it:flights){
                int u = it[0];
                int v = it[1];
                int w = it[2];
                if(dis[i-1][u]!=INT_MAX){
                    if(dis[i][v]>dis[i-1][u]+w){
                        dis[i][v] = dis[i-1][u] + w;
                    }
                }
            }
        }
        if(dis[k+1][dst]==INT_MAX)return -1;
        return dis[k+1][dst];
    }
};