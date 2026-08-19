class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reserved;
        for (auto &seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }
        long long ans = 2LL * n;
        for (auto &[row, seats] : reserved) {
            bool left = true;
            bool middle = true;
            bool right = true;
            for (int s = 2; s <= 5; s++) {
                if (seats.count(s)) {
                    left = false;
                    break;
                }
            }
            for (int s = 4; s <= 7; s++) {
                if (seats.count(s)) {
                    middle = false;
                    break;
                }
            }
            for (int s = 6; s <= 9; s++) {
                if (seats.count(s)) {
                    right = false;
                    break;
                }
            }
            ans -= 2;
            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }
        return ans;
    }
};