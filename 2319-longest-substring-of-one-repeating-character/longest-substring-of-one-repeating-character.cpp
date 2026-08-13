class Solution {
public:
    struct Node {
        char left, right;
        int pref, suff, best, len;
        Node() {
            left = right = '#';
            pref = suff = best = len = 0;
        }
        Node(char c) {
            left = right = c;
            pref = suff = best = len = 1;
        }
    };
    vector<Node> tree;
    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;
        Node res;
        res.len = a.len + b.len;
        res.left = a.left;
        res.right = b.right;
        res.pref = a.pref;
        res.suff = b.suff;
        res.best = max(a.best, b.best);
        if (a.right == b.left) {
            res.best = max(res.best,a.suff + b.pref);
            if (a.pref == a.len) {
                res.pref = a.len + b.pref;
            }
            if (b.suff == b.len) {
                res.suff = b.len + a.suff;
            }
        }
        return res;
    }
    void build(int node, int l, int r, string &s) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);
        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }
        void update(int node, int l, int r,
                int idx, char c) {

        if (l == r) {
            tree[node] = Node(c);
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) {
            update(node * 2, l, mid, idx, c);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, c);
        }

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices) {
        int n = s.size();
        tree.resize(4 * n + 5);
        build(1, 0, n - 1, s);
        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); i++) {
            int index = queryIndices[i];
            char c = queryCharacters[i];
            s[index] = c;
            update(1, 0, n - 1, index, c);
            ans.push_back(tree[1].best);
        }

        return ans;
    }
};