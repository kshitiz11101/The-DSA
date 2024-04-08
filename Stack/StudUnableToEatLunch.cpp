class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>stud;
        stack<int>sand;
        int n=students.size();
        for(int i=0;i<n;i++){
            stud.push(students[i]);
            sand.push(sandwiches[n-i-1]);
        }
        int ans=0;
        while(!stud.empty() && stud.size()>ans){
            if(sand.top()==stud.front()){
                sand.pop();
                stud.pop();
                ans=0;

            }
            else{
                stud.push(stud.front());
                stud.pop();
                ans++;
            }
        }

    return stud.size();
    }
};
