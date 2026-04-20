class Solution {
    public int maxDistance(int[] c) {
        int n = c.length;
        int res= 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(c[i] != c[j]){
                    res=Math.max(res,j-i);
                }
            }
        }
        return res;
        
    }
}