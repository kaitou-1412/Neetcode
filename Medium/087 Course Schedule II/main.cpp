class Solution {

private: 
    unordered_map<int,vector<int>> graph;
    unordered_set<int> alreadyVisited;
    unordered_set<int> cycle;
    
    
public:
    bool dfs(int course, vector<int> &res) {
        if(cycle.find(course) != cycle.end()) return false;
        if(alreadyVisited.find(course) != alreadyVisited.end()) return true;
        
        cycle.insert(course);
        for(int i=0; i<graph[course].size(); i++) {
            if(dfs(graph[course][i], res) == false) {
                return false;
            }
        }
        cycle.erase(cycle.find(course));
        
        alreadyVisited.insert(course);
        res.push_back(course);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        for(int i=0; i<prerequisites.size(); i++)
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        for(int i=0; i<numCourses; i++) {
            if(dfs(i, res) == false) {
                return {};
            }
        }
        return res;
    }
};