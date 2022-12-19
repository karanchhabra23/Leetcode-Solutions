//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& a) {
        // Code here
        int n = a.size();
        int m = a[0].size();
        // vector<vector<int>>dp()
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        vector<vector<int>>res(n,vector<int>(m,INT_MAX/2));
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        q.push({0,{0,0}});
        while(!q.empty()){
            int x = q.top().second.first;
            int y = q.top().second.second;
            int d = q.top().first;
            q.pop();
            if(x==n-1 && y==m-1){
                return d;
            }
            for(int i = 0 ;i<4;i++){
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx >=0 && newx<n && newy>=0 && newy<m){
                    int newd = max(d,abs(a[newx][newy]-a[x][y]));
                    if(res[newx][newy]>newd){
                        res[newx][newy] = newd;
                        q.push({newd,{newx,newy}});
                    }
                }
            }
            
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends