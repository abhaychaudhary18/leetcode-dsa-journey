class Solution{
    public:
    bool validPalindrome(string s){
        int left =0;
        int right = s.length()-1;
        while(left<right){
            if(s[left] != s[right]){
                string s1= s.substr(left+1, right-left);
                string s2=s.substr(left,right-left);
                string r1=s1,r2=s2;
                reverse(r1.begin(),r1.end());
                reverse(r2.begin(),r2.end());
                return (s1==r1 || s2==r2);
            }
            left++;
            right--;
        }
        return true;
    }
};