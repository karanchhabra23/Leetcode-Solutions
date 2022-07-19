class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& a, int target) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>>pre(n+1,vector<int>(m+1,0));
        
        for(int i = 0 ;i<n;i++){
            for(int j = 0 ;j<m;j++){
                if(j==0){
                    pre[i][j] = a[i][j]; 
                }
                else{
                    pre[i][j] = a[i][j]+pre[i][j-1];
                }
            }
        }
        
        int count = 0 ;
        unordered_map<int,int>mp;
        // m[0]++;
        

        for(int col1 = 0 ;col1<m;col1++){
                
                
            
            for(int col2=0 ;col2<=col1;col2++){
                int sum = 0;
                // int sum = 0;
                mp.clear();
                mp[0]++;
                
                for(int row = 0;row<n;row++){
                    sum+=pre[row][col1];
                    if(col2!=0){
                        sum-=pre[row][col2-1];
                    }

                    count+= mp[sum-target];
                    // count+=mp[sum+target];
                    mp[sum]++;
                }
            }
        }
        return count;
        
        
    }
};