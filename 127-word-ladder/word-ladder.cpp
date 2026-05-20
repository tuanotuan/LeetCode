class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> ump(wordList.begin(), wordList.end());
        if (ump.find(endWord) == ump.end()) {
            return 0;
        }
        int level = 1;
        queue<string> q;
        q.push(beginWord);
        while (true) {
            vector<string> vs;
            while (!q.empty()) {
                vs.push_back(q.front());
                q.pop();
            }
            if(vs.empty()) return 0;
            for (auto s : vs) {
                for (auto& c : s) {
                    char tmp = c;
                    for (char sc = 'a'; sc <= 'z'; sc++) {
                        c = sc;
                        if (s == endWord)
                            return level + 1;
                        if (ump.find(s) != ump.end()) {
                            q.push(s);
                            ump.erase(s);
                        }
                    }
                    c = tmp;
                }
            }
            level++;
        }
    }
};