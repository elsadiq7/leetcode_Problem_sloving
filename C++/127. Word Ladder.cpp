class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        int V = wordList.size();
        vector<bool> visited(V, false);
        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                string curr = q.front();
                q.pop();
                for (int i = 0; i < V; i++) {
                    if (!visited[i] && differsByOne(curr, wordList[i])) {
                        if (wordList[i] == endWord)
                            return steps + 1;
                        visited[i] = true;
                        q.push(wordList[i]);
                    }
                }
            }
            steps++;
        }
        return 0;
    }

    bool differsByOne(const string& a, const string& b) {
        if (a.size() != b.size())
            return false;
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
                if (diff > 1)
                    return false;
            }
        }
        return diff == 1;
    }
};