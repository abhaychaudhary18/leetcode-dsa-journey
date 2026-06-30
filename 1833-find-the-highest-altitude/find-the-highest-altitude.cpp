class Solution{
    public:
    int largestAltitude(vector<int>& gain){
        int curAltitude =0;
        int highestPoint = curAltitude;
        for(int altitudeGain : gain){
            curAltitude += altitudeGain;
            highestPoint = max(highestPoint, curAltitude);
        }
        return highestPoint;
    }
};