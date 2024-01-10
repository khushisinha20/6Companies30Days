//leetcode.com/problems/minimum-cost-to-convert-string-i/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, vector<pair<char, long long>>> getGraph(vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, long long>>> graph;
        for (int i = 0; i < original.size(); ++i)
            graph[original[i]].push_back({changed[i], (long long)cost[i]});
        return graph;
    }

    long long dijkstra(char source, char target, unordered_map<char, vector<pair<char, long long>>>& graph,
                       unordered_map<char, unordered_map<char, long long>>& memo) {
        if (memo.find(source) != memo.end() && memo[source].find(target) != memo[source].end()) {
            return memo[source][target];
        }

        unordered_map<char, long long> minCost;
        priority_queue<pair<long long, char>, vector<pair<long long, char>>, greater<pair<long long, char>>> minHeap;
        minCost[source] = 0ll;
        minHeap.push({0ll, source});

        while (!minHeap.empty()) {
            char current = minHeap.top().second;
            long long currentCost = minHeap.top().first;
            minHeap.pop();

            if (current == target) {
                memo[source][target] = currentCost;
                return currentCost;
            }

            for (auto& neighbor : graph[current]) {
                char next = neighbor.first;
                long long edgeCost = neighbor.second;

                if (minCost.find(next) == minCost.end() or minCost[current] + edgeCost < minCost[next]) {
                    minCost[next] = minCost[current] + edgeCost;
                    minHeap.push({minCost[next], next});
                }
            }
        }

        memo[source][target] = -1;
        return -1;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, long long>>> graph = getGraph(original, changed, cost);
        unordered_map<char, unordered_map<char, long long>> memo;
        long long result = 0;

        for (int i = 0; i < source.size(); ++i) {
            long long currentCost = dijkstra(source[i], target[i], graph, memo);

            if (currentCost == -1) {
                return -1;
            }

            result += currentCost;
        }

        return result;
    }
};
