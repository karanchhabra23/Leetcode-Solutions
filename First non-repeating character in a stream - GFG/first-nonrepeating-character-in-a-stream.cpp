// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    vector<int>freq(26,0);
		    string res;
		    queue<char>q;
		    for(auto &it:s)
		    {
		        freq[it-'a']++;
		        if(freq[it-'a']==1){
		            q.push(it);
		        }
		        
		        while(!q.empty() && freq[q.front()-'a']>1)
		            q.pop();
		            
                if(q.empty()){
                    res+='#';
                }
                else{
                    res+=q.front();
                }
		        
		    }
		    return res;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends