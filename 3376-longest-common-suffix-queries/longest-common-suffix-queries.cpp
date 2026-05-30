struct Trie {
    int child[26];
    int pos;
    Trie() {
        memset(child, -1, sizeof(child));
        pos = -1;
    }
};

class Solution {
    vector<Trie> trie;
    vector<string>* words;
public:
    bool better(int x, int y) {
        if (y == -1) return true;
        if ((*words)[x].size() != (*words)[y].size()) {
            return (*words)[x].size() < (*words)[y].size();
        }
        return x < y;
    }

    void insert(const string& s, int id) {
        int u = 0;
        if (better(id, trie[u].pos)) trie[u].pos = id;

        for (char ch : s) {
            int c = ch - 'a';
            if (trie[u].child[c] == -1) {
                trie[u].child[c] = trie.size();
                trie.push_back(Trie());
            }
            u = trie[u].child[c];

            if (better(id, trie[u].pos))
                trie[u].pos = id;
        }
    }

    int findLongestCommonSuffix(const string& s) {
        int u = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[u].child[c] == -1) return trie[u].pos;
            u = trie[u].child[c];
        }
        return trie[u].pos;
    }


    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.push_back(Trie());
        words = &wordsContainer;

        for (int i = 0; i < wordsContainer.size(); i++) {
            string s = wordsContainer[i];
            reverse(s.begin(), s.end());
            insert(s, i);
        }

        vector<int> ans;
        for (string& q : wordsQuery) {
            reverse(q.begin(), q.end());
            ans.push_back(findLongestCommonSuffix(q));
        }
        return ans;
    }
};