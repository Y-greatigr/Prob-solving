#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct TrieNode {
    bool valid;
    map<string, int> child;
    TrieNode() {
        valid = false;
    }
};

struct Trie {
    vector<TrieNode> trie;
    int newNode() {
        TrieNode temp;
        trie.push_back(temp);
        return trie.size() - 1;
    }
    void add(vector<string>& v, int node = 0, int idx = 0) {
        if (idx == v.size()) {
            trie[node].valid = true;
            return;
        }
        string s = v[idx];
        if (!trie[node].child.count(s)) {
            int nxt = newNode();
            trie[node].child.insert({ s, nxt });
        }
        add(v, trie[node].child[s], idx + 1);
    }
    void sol(int node = 0, int depth = 0) {
        for (auto [s, idx] : trie[node].child) {
            cout << string(2 * depth, '-') << s << '\n';
            sol(idx, depth + 1);
        }
    }
    Trie() {
        newNode();
    }
};

int main() {
    fastio;
    Trie T;
    int n; cin >> n;
    while (n--) {
        int t; cin >> t;
        vector<string> v;
        while (t--) { string s; cin >> s; v.push_back(s); }
        T.add(v);
    }
    T.sol();
}