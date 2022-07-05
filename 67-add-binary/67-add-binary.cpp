class Solution {
public:
    string addBinary(string a, string b) {
        string res;
    
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        int sum = 0;
        while(i>=0 ||  j>=0){
            sum=carry;
            if(i>=0){
                sum+= a[i] - '0';
                i--;
            }
            if(j>=0){
                sum+= b[j] - '0';
                j--;
            }

            int x = sum%2;
            res+=x+'0';
            carry = sum/2;

        }
        if(carry){
            res+=carry+'0';
        }
        reverse(res.begin(),res.end());
        return res;
    }
};