//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            long N = Long.parseLong(read.readLine());
            Solution ob = new Solution();
            int ans=ob.fibonacciDigits(N);
            if(ans/10>0)
             System.out.println(ans);
            else
             System.out.println("0"+ans);
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    int fibonacciDigits(long n){
        //code here
        // n%=300;
        long x = n%300;
        int[] arr = new int[300];
        arr[0] = 0;
        arr[1] = 1;
        for(int i = 2;i<300;i++){
            arr[i] = (arr[i-1] + arr[i-2])%100;
        }
        return arr[(int) x];
    }
}