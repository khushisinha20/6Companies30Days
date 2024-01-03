//leetcode.com/problems/find-consecutive-integers-from-a-data-stream/

#include <bits/stdc++.h>
using namespace std;

class DataStream {
public:
    deque<int> stream;
    unordered_map<int, int> occurence;
    int value;
    int k;
    
    DataStream(int value, int k) {
        this -> value = value;
        this -> k = k;
    }
    
    bool consec(int num) {
        stream.push_back(num);
        ++occurence[num];
        
        if (stream.size() < k)
            return false;
        
        while (stream.size() > k) {
            --occurence[stream.front()];
            if (occurence[stream.front()] <= 0)
                occurence.erase(stream.front());
            stream.pop_front();
        }
        
        return occurence.size() == 1 and occurence[value] == k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
