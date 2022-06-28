class Solution {
public:
    typedef pair<int,int> pii;
    int orangesRotting(vector<vector<int>>& a) {
        // int count = 0;
        int n = a.size();
        int m = a[0].size();
        int dx[5] = {0,1,0,-1,0};
        queue<pii>q;
        int count  = 0;
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(a[i][j]==2){
                    q.push({i,j});
                }
                else if(a[i][j]==1){
                    count ++;
                }
            }
        }
        int steps = 0;
        while(!q.empty()){
            int sz= q.size();
            if(count==0){
                return steps;
            }
            steps++;
            while(sz--){
                auto [x,y] = q.front();
                q.pop();
                
                for(int t = 0;t<4;t++){
                    int newx = x + dx[t];
                    int newy = y + dx[t+1];
                    
                    if(newx>=0 && newx<n && newy>=0 && newy<m && a[newx][newy]==1){
                        a[newx][newy] = 2;
                        count--;
                        q.push({newx,newy});
                        
                    }
                }
                
            }
            
        }
        if(count==0){
            return steps;
        }
        return -1;
        
    }
};