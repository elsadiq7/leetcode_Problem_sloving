#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> graph;   // adjacency list
    vector<int> state;           // 0 = unvisited, 1 = visiting, 2 = visited
    vector<int> order;           // stores topological order

    bool dfs(int course) {
        if (state[course] == 1) return false; // cycle detected
        if (state[course] == 2) return true;  // already processed safely

        state[course] = 1; // mark as visiting
        for (int next : graph[course]) {
            if (!dfs(next)) return false; // cycle in neighbors
        }
        state[course] = 2; // mark as visited (safe)
        order.push_back(course); // add course AFTER processing children
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build graph
        graph.assign(numCourses, {});
        for (auto& pre : prerequisites) {
            int a = pre[0], b = pre[1];
            graph[b].push_back(a); // edge b -> a
        }

        // Step 2: Initialize states
        state.assign(numCourses, 0);
        order.clear();

        // Step 3: Run DFS on all courses
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i)) return {}; // cycle found → return empty
            }
        }

        // Step 4: Reverse order (because DFS adds nodes post-order)
        reverse(order.begin(), order.end());
        return order;
    }
};
