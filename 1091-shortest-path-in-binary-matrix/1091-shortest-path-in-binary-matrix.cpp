class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& a) {
        int n = a.size();
        if(a[0][0]==1 || a[n-1][n-1]==1){
            return -1;
        } 
        if(n==1){
            return 1;
        }
        int dx[] = {-1,1,1,-1,-1,0,1,0,-1};
    
        queue<pair<int,int>>q;
        q.push({0,0});
        
        int steps = 1;
        while(!q.empty()){
            int sz = q.size();
            steps++;
            while(sz--){
                auto [x,y] = q.front();
                q.pop();
                
                for(int i = 0;i<8;i++){
                    int newx = x + dx[i];
                    int newy = y + dx[i+1];
                    
                    if(newx==n-1 && newy==n-1){
                        return steps;
                    }
                    if(newx<n && newx>=0 && newy<n && newy>=0 && a[newx][newy]==0){
                        a[newx][newy] = 1;
                        q.push({newx,newy});
                    }
                }
                
            }
        }
        return -1;
    
    }
};