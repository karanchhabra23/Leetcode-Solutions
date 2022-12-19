//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

  public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            inputLine = br.readLine().trim().split(" ");
            int k = Integer.parseInt(inputLine[0]);
            inputLine = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            int ans = new Solution().getMinDiff(arr, n, k);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    int getMinDiff(int[] a, int n, int k) {
        // code here
        Arrays.sort(a);
        int max = a[n-1];
        int min = a[0];
        int ans = max-min;
    
        for(int i = 0 ;i<n-1;i++){
            if(a[i+1]-k<0){
                continue;
            }
            max = Math.max(a[n-1]-k,a[i]+k);
            min = Math.min(a[0]+k, a[i+1]-k);
            if(max-min<ans){
                ans = max-min;
            }
        }
        return ans;
    }
}
