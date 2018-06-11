/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    map<int,Employee*> mp;
    int getImportance(vector<Employee*> employees, int id) {
        for(int i=0; i<employees.size(); i++){
            int idx=employees[i]->id;
            mp[idx]=employees[i];
        }
        int ans=dfs(id);
        return ans;
    }
    int dfs(int id){
        Employee* e=mp[id];
        int ans=e->importance;
        for(int i=0; i<e->subordinates.size(); i++){
            ans += dfs(e->subordinates[i]);
        }
        return ans;
    }
};