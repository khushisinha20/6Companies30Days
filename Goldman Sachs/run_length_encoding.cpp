// www.geeksforgeeks.org/problems/run-length-encoding/1

#include <bits/stdc++.h>
using namespace std;

string encode(string src) {
    string result = "";
    
    int count = 1;
    for (int i = 1; i <= src.length(); i++) {
        if (i == src.length() || src[i] != src[i - 1]) {
            result += src[i - 1] + to_string(count);
            count = 1;
        } else {
            count++;
        }
    }
    
    return result;
}    
