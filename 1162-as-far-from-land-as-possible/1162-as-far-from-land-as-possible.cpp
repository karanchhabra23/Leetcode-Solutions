class Solution {
public:
    typedef pair<int,int> pii;
    int maxDistance(vector<vector<int>>& a) {
        int n = a.size();
        queue<pii>q;
        for(int i = 0;i<n;i++){
            for(int j = 0 ;j<n;j++){
                if(a[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if(q.size()==n*n || q.size()==0){
            return -1;
        }
        int ans = -1;
        int dx[] = {0,1,0,-1,0};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x,y] = q.front();
                q.pop();
                for(int i = 0;i<4;i++){
                    int newx = x+dx[i];
                    int newy = y+dx[i+1];
                    if(newx>=0 && newx<n && newy>=0 && newy<n && a[newx][newy]==0){
                        a[newx][newy] = 1;
                        q.push({newx,newy});
                    }
                }
            }
            ans++;
            
        }
        return ans;
    }
};