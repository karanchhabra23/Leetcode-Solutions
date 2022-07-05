class Solution {
public:
    int strStr(string b, string a) {
            int n = b.size();
        int m = a.size();

        for(int i = 0 ;i<n-m+1;i++){
            if(b[i]==a[0]){
                bool flag = true;
                for(int j = 0;j<m;j++){
                    if(b[i+j]!=a[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    return i;
                }

            }
        }
        return -1;
    }
};