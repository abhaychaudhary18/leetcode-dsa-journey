class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>v;
        for(string op : operations){
            if(op=="C"){
                v.pop_back();
            }
            else if(op=="D"){
                v.push_back(2*v.back());
            }
            else if(op=="+"){
                v.push_back(v[v.size()-1]+v[v.size()-2]);
            }
            else{
                v.push_back(stoi(op));
            }
        }
        int sum =0;
        for(int i = 0; i < v.size(); i++) {
        sum += v[i];
}
        return sum;
    }
};