class Solution 
{
    public List<List<Integer>> threeSum(int[] arr) 
    {
        Arrays.sort(arr);
        List<List<Integer>> ans = new ArrayList();
        int n = arr.length;
        int i  = 0;
        // for(int i=0;i<n-2;i++)
        while(i<n-2)
        {
             int k = arr.length-1;
             int j = i+1;
            int z = arr[i];
             while(k>j) // -4 -1 -1 0 1 2    t = 0
             {
                 int x = arr[j];
                 int y = arr[k];
                 if(arr[i]+arr[j]+arr[k]==0)
                 {
                     List<Integer> A = new ArrayList();
                     A.add(arr[i]);
                     A.add(arr[j]);
                     A.add(arr[k]);
                     ans.add(A);
                     while(j<k && arr[j]==x){
                         j++;
                     }
                     while(j<k && arr[k]==y){
                         k--;
                     }
                    
                 }
                 else if(arr[i]+arr[j]+arr[k]>0)
                 {
                      while(j<k && arr[k]==y){
                         k--;
                     }
                 }
                 else
                 {
                      while(j<k && arr[j]==x){
                         j++;
                     }
                 }
             }
            while(i<n && arr[i]==z){
                i++;
            }
        }
        return ans;
    }
}