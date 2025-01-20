#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

struct node {
    unordered_map<char, node*> nxt;
    int cnt = 0;
};

class trie {
    node* root;

public:
    trie() {
        root = new node();
    }

    void add(const string& s) {
        node* cur = root;
        for (char c : s) {
            if (!cur->nxt[c]) {
                cur->nxt[c] = new node();
            }
            cur = cur->nxt[c];
            cur->cnt++;
        }
    }

    void remove(const string& s) {
        node* cur = root;
        vector<node*> path;
        for (char c : s) {
            if (!cur->nxt[c]) return;
            path.push_back(cur);
            cur = cur->nxt[c];
        }

        for (int i = path.size() - 1; i >= 0; --i) {
            path[i]->nxt[s[i]]->cnt--;
            if (path[i]->nxt[s[i]]->cnt == 0) {
                delete path[i]->nxt[s[i]];
                path[i]->nxt.erase(s[i]);
            }
        }
    }

    int count(const string& s) {
        node* cur = root;
        for (char c : s) {
            if (!cur->nxt[c]) return 0;
            cur = cur->nxt[c];
        }
        return cur->cnt;
    }

    ~trie() {
        clear(root);
    }

private:
    void clear(node* cur) {
        if (!cur) return;
        for (auto& p : cur->nxt) {
            clear(p.second);
        }
        delete cur;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    trie t;

    while (q--) {
        int op;
        string s;
        cin >> op >> s;

        if (op == 1) {
            t.add(s);
        } else if (op == 2) {
            t.remove(s);
        } else if (op == 3) {
            cout << t.count(s) << "\n";
        }
    }

    return 0;
}
