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
    map<int, Employee*> mp;
    int getImportance(vector<Employee*> employees, int id) {
        for(int i=0; i<employees.size(); i++){
            int idx=employees[i]->id;
            mp[idx]=employees[i];
        }
        int ans=0;
        stack<int> sk;
        sk.push(id);
        while(!sk.empty()){
            int eid=sk.top();
            sk.pop();
            Employee* e=mp[eid];
            ans += e->importance;
            for(int i=0; i<e->subordinates.size(); i++){
                sk.push(e->subordinates[i]);
            }
        }
        return ans;
    }
};