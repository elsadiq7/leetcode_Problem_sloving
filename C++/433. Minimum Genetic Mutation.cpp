class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int V = bank.size();
        vector<bool> visited(V, false);
        queue<string> q;
        q.push(startGene);
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                string curr = q.front();
                q.pop();
                for (int i = 0; i < V; i++) {
                    if (!visited[i] && differsByOne(curr, bank[i])) {
                        if (bank[i] == endGene) return steps + 1;
                        visited[i] = true;
                        q.push(bank[i]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }

    bool differsByOne(const string& a, const string& b) {
        if (a.size() != b.size()) return false;
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
                if (diff > 1) return false;
            }
        }
        return diff == 1;
    }
};
