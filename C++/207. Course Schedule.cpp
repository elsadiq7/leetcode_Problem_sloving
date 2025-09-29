class Solution {
public:
    bool dfs(int course, vector<vector<int>>& graph, vector<int>& state) {
        if (state[course] == 1) return false; // cycle found
        if (state[course] == 2) return true;  // already processed
        
        state[course] = 1; // visiting
        
        for (int next : graph[course]) {
            if (!dfs(next, graph, state)) return false;
        }
        
        state[course] = 2; // visited
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]); // edge b → a
        }
        
        vector<int> state(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i, graph, state)) return false;
            }
        }
        
        return true;
    }
};
