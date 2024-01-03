//www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        long long missing = 0;
        long long repeating = 0;
        long long totalSum = ((long long)n * ((long long)n + 1)) / 2;
        long long sumOfSquares = ((long long)n * ((long long)n + 1) * (2 * (long long)n + 1)) / 6;
        long long currentSum = accumulate(arr.begin(), arr.end(), 0ll);
        long long repeatingMinusMissing = currentSum - totalSum;

        long long currentSumOfSquares = 0;
        for (int i = 0; i < arr.size(); ++i)
            currentSumOfSquares += ((long long)arr[i] * (long long)arr[i]);

        long long squaresDifference = currentSumOfSquares - sumOfSquares;
        long long repeatingPlusMissing = squaresDifference / repeatingMinusMissing;
        repeating = (repeatingPlusMissing + repeatingMinusMissing) / 2;
        missing = repeatingPlusMissing - repeating;
        return {repeating, missing};
    }
};
