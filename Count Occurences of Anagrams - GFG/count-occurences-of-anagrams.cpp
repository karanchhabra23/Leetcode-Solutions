// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int freq1[26] = {0};
	    for(auto&it:pat){
	        freq1[it-'a']++;
	    }
	    int n = txt.size();
	    int freq[26] = {0};
	    int j = 0;
	    int i = 0;
	    int ans = 0;
	    while(i<n){
	        freq[txt[i]-'a']++;
	        if(i-j+1<pat.size()){
	            i++;
	        }
	        else{
	            bool flag = true;
	            for(int k = 0;k<26;k++){
	                if(freq1[k]!=freq[k]){
	                    flag = false;
	                    break;
	                }
	            }
	            if(flag)ans++;
	            freq[txt[j]-'a']--;
	            j++;
	            i++;
	        }
	        
	        
	    }
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends