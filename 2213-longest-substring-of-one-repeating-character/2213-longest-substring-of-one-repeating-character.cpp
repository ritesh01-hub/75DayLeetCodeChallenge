class Solution {
    struct Node {
        char leftChar, rightChar;
        int len;
        int pref, suff, best;

        Node() {
            leftChar = rightChar = '#';
            len = pref = suff = best = 0;
        }

        Node(char c) {
            leftChar = rightChar = c;
            len = 1;
            pref = suff = best = 1;
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node &L, Node &R) {
        if (L.len == 0) return R;
        if (R.len == 0) return L;

        Node res;

        res.len = L.len + R.len;

        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        // Prefix
        res.pref = L.pref;

        if (L.pref == L.len && L.rightChar == R.leftChar) {
            res.pref = L.len + R.pref;
        }

        // Suffix
        res.suff = R.suff;

        if (R.suff == R.len && L.rightChar == R.leftChar) {
            res.suff = R.len + L.suff;
        }

        // Best
        res.best = max(L.best, R.best);

        // Join suffix of L with prefix of R
        if (L.rightChar == R.leftChar) {
            res.best = max(res.best, L.suff + R.pref);
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            s[idx] = c;
            tree[node] = Node(c);
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, c);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, c);
        }

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};