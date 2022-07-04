// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    typedef pair<int,int> pii;
    int d[5] = {0,1,0,-1,0};
	vector<vector<int>>nearest(vector<vector<int>>a)
	{
	    // Code here
        int n = a.size();
        int m = a[0].size();        
        queue<pii>q;
        // vector<vector<int>>dis(n,vector<int>(m,0));
        for(int i=0;i<a.size();i++){
            for(int j = 0;j<a[0].size();j++){
                if(a[i][j]==0){
                    a[i][j] = -1;
                }
                else{
                    a[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++){
                int newx = x + d[i];
                int newy = y + d[i+1];
                if(newx>=0 && newx<n && newy>=0 && newy<m && a[newx][newy]==-1){
                    a[newx][newy] = a[x][y]+1;
                    q.push({newx,newy});
                }
            }
        }
        return a;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends