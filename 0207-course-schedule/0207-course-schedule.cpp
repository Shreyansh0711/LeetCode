class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ig(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto& it : prerequisites) {
            int course = it[0];
            int prereq = it[1];

            adj[prereq].push_back(course);
            ig[course]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (ig[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[node]) {
                ig[it]--;
                if (ig[it] == 0) {
                    q.push(it);
                }
            }
        }
        return cnt == numCourses;
    };
};