class Solution {
public:
    int numEnclaves(vector<vector<int>>& a) {
        int  n = a.size();
        int m = a[0].size();
        queue<pair<int,int>>q;
        for(int i = 0;i<n;i++){
            if(a[i][0]==1){
                a[i][0] = 0;
                q.push({i,0});
            }
            if(a[i][m-1]==1){
                a[i][m-1]= 0;
                q.push({i,m-1});
            }
        }     
        for(int j = 0;j<m;j++){
            if(a[0][j]==1){
                a[0][j] = 0;
                q.push({0,j});
            }
            if(a[n-1][j]==1){
                a[n-1][j]=0;
                q.push({n-1,j});
            }
        }
        int dx[5] = {0,-1,0,1,0};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int t= 0;t<4;t++){
                int newx = x+dx[t];
                int newy = y+dx[t+1];
                if(newx>=0 && newx<n && newy>=0 && newy<m && a[newx][newy]==1){
                    a[newx][newy]=0;
                    q.push({newx,newy});
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                ans+=a[i][j];
            }        
        }
        return ans;
    }
};