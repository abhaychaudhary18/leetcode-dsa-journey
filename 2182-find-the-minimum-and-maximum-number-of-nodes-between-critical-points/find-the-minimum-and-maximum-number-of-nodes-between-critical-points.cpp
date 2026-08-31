class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return ans;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int first = -1;       
        int last = -1;        
        int minDist = INT_MAX;
        int pos = 1;
        while (curr->next != nullptr) {
            bool critical =
                (curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val);
            if (critical) {
                if (first == -1) {
                    first = pos;
                }
                                if (last != -1) {
                    minDist = min(minDist, pos - last);
                }
                last = pos;
            }
            prev = curr;
            curr = curr->next;
            pos++;
        }
        if (first == -1 || first == last)
            return ans;

        int maxDist = last - first;

        return {minDist, maxDist};
    }
};