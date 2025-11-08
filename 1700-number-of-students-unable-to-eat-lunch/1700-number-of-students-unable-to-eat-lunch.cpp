class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n =students.size();
        queue<int> q;
        for(int i = 0 ; i < n ; i++){
            q.push(students[i]);
        }
        int count =0;
        int i=0;
        while(q.size()){
            
            if(sandwiches[i]==q.front()){q.pop();
                i++; 
                count=0;
            }
            else{
                int x= q.front();
                q.pop();
                q.push(x);
                count++;
                if(count>=q.size()){
                    return q.size();
                }
            }
        }
        return q.size();
    }
};