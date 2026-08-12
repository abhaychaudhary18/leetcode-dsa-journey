class Solution{
    public:
    int minimumPushes(string word){
        vector<int>freq(26,0);
        for(char c: word){
            freq[c - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int ans =0;
        for(int i=0;i<26;i++){
            int pushes= (i/8)+1;
            ans += freq[i]* pushes;
        }
        return ans;
    }
};