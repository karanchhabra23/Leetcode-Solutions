class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();
        if(n2<n1){
            return findMedianSortedArrays(b,a);
        }
        // if(n1==0){
        //     if(n2%2==0){
        //         return (double)(b[n2/2]+b[(n2-1)/2])/2.0;
        //     }
        //     else{
        //         return (double)b[n2/2];
        //     }
        // }
        // if(n2==0){
        //     if(n1%2==0){
        //         return (double)(a[n1/2]+a[(n1-1)/2])/2.0;
        //     }
        //     else{
        //         return (double)a[n1/2];
        //     }
        // }
        int lo = 0;
        int hi = n1;
        while(lo<=hi){
            int cut1 = (lo+hi)/2;
            int cut2;
            // if((n1+n2)&1){
                cut2 = (n1+n2+1)/2;
            // }
            // else{
                // cut2 = (n1+n2)/2;
            // }
            cut2-=cut1;
            
            int l1,l2,r1,r2;
            
            l1 = (cut1==0)?INT_MIN/2:a[cut1-1];
            l2 = (cut2==0)?INT_MIN/2:b[cut2-1];
            
            r1 = (cut1==n1)?INT_MAX/2:a[cut1];
            r2 = (cut2==n2)?INT_MAX/2:b[cut2];
            
            if(l1<=r2 && l2<=r1){
                if((n1+n2)&1){
                    return max(l1,l2);
                }
                else{
                    return ((double) (max(l1,l2) + min(r1,r2)))/2.0;
                }
            }
            else if(l1>r2){
                hi = cut1 - 1;
            }
            else{
                lo = cut1+1;
            }
        }
        return -1;
    }
};