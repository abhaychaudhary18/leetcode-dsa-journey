class Solution{
    public:
    bool sumGame(string num){
        const int n = num.size(), n2 =n>>1;
        int diff=0;
        for(int i=0;i<n;i++){
            const char c = num[i];
            bool abh = c=='?', half=i<n2;
            int ayc = (half<<1)-1;
            int d =(-abh &9) +(-!abh&(c-'0')<<1);
            diff+=ayc*d;
        }
        return diff !=0;
    }
};

