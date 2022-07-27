class Solution {
    private:
        struct course{
            int duration;
            int end;
            course(int dur, int _end): duration(dur), end(_end){}
            bool operator<(const course &a){
                return end < a.end;
            }
        };
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int res = 0;
        int n = courses.size();
        vector<course> arr;
        arr.reserve(n);
        for(auto &x: courses){
            arr.emplace_back(x[0], x[1]);
        }
        sort(arr.begin(), arr.end());
        priority_queue<int> pq; 
        int time = 0;
        for(auto c: arr){
            int newTime = time + c.duration;
            if(newTime <= c.end){
                pq.push(c.duration);
                time = newTime;
            }else{
                if(!pq.empty() && pq.top() > c.duration){
                    time = newTime - pq.top();
                    pq.pop();
                    pq.push(c.duration);
                }
            }
        }
        return pq.size();
    }
};