class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
        int i,j=1;
        for( i=0; i < nums1.length && j< nums2.length; j++)
        if(nums1[i]>nums2[j])
           i++;
        return j-i-1;
        
    }
}