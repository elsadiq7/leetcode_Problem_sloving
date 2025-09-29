class Solution {
public:
    unordered_map<string, vector<pair<string,double>>> graph;
    
    double dfs(string src, string dst, unordered_set<string>& visited, double product) {
        if (src == dst) return product;
        visited.insert(src);
        for (auto& [neighbor, weight] : graph[src]) {
            if (!visited.count(neighbor)) {
                double result = dfs(neighbor, dst, visited, product * weight);
                if (result != -1.0) return result;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Step 1: Build the graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        // Step 2: Answer queries
        vector<double> results;
        for (auto& q : queries) {
            string src = q[0], dst = q[1];
            if (!graph.count(src) || !graph.count(dst)) {
                results.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            double result = dfs(src, dst, visited, 1.0);
            results.push_back(result);
        }
        return results;
    }
};
