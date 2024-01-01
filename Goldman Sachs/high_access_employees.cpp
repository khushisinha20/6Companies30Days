//leetcode.com/problems/high-access-employees/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> mapEmployeeToAccessTime(vector<vector<string>>& access_times) {
        unordered_map<string, vector<string>> employeeToAccessTime;
        for (auto& access_time : access_times)
            employeeToAccessTime[access_time[0]].push_back(access_time[1]);
        return employeeToAccessTime;
    }

    int toMinutes(string& time) {
        int hour = (time[0] - '0') * 10 + (time[1] - '0');
        int minutes = (time[2] - '0') * 10 + (time[3] - '0');
        return hour * 60 + minutes;
    }

    bool isHighAccessEmployee(vector<int>& accessTimeInMins) {
        if (accessTimeInMins.size() < 3)
            return false;
        for (int i = 2; i < accessTimeInMins.size(); ++i)
            if (accessTimeInMins[i] - accessTimeInMins[i - 2] < 60)
                return true;
        return false;
    }

    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<string>> employeeToAccessTime = mapEmployeeToAccessTime(access_times);
        vector<string> highAccessEmployees;

        for (auto& [employee, accessTime] : employeeToAccessTime) {
            vector<int> accessTimeInMins;
            for (auto& time : accessTime)
                accessTimeInMins.push_back(toMinutes(time));
            sort(accessTimeInMins.begin(), accessTimeInMins.end());
            if (isHighAccessEmployee(accessTimeInMins))
                highAccessEmployees.push_back(employee);
        }

        return highAccessEmployees;
    }
};

