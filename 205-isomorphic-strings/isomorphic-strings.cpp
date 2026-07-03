// class Solution{
//     public:
//     boolIsomorphic(String s, string t){
//         unordered_map<char, char>m;
//         for(int i=0;i<s.size();i++){
//             if(m.count(s[i])){
//                 if(m[s[i]] != t[i])
//                 return false;
//             }
//             else{
//                 for(auto x:m){
//                     if(x.second == t[i])
//                     return false;
//                 }
//                 m[s[i]]=t[i];
//             }
//         }
//         return false;
//     }
// }


class Solution{
    public:
    bool isIsomorphic(string s, string t){
        int m1[256] ={0};
        int m2[256] ={0};
        for(int i=0;i<s.size();i++){
            if(m1[s[i]] != m2[t[i]]){
                return false;
            }else{
                m1[s[i]]=i+1;
                m2[t[i]] = i+1;
            }
        }
        return true;
    }
};

