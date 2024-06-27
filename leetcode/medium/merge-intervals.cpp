#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int arrLen = 10000 + 2;
    int arr[10000 + 2] = { -1 };
    memset(arr, -1, arrLen * sizeof(int)); // init with -1 properly
    int maxVal = -1;
    for (int i = 0; i < intervals.size(); i++) {
      if (arr[intervals[i][0]] == -1) {
        arr[intervals[i][0]] = intervals[i][1];
      } else {
        arr[intervals[i][0]] = max(intervals[i][1], arr[intervals[i][0]]);
      }
      maxVal = max(maxVal, intervals[i][1]);
    }
    // solve
    bool started = false;
    int checkTill = -1, startedFrom = -1;
    vector<vector<int>> sol;
    for (int i = 0; i <= (maxVal + 1); i++) {
      if ((i > checkTill) && started) {
        started = false;
        sol.push_back({startedFrom, checkTill});
      }
      if (arr[i] == -1) {
        continue;
      }
      if (!started) {
        started = true;
        startedFrom = i;
        checkTill = arr[i];
      } else {
        checkTill = max(checkTill, arr[i]);
      }
    }
    return sol;
  }
};

int main() {
  Solution sol;
  // vector<vector<int>> nums = {8,2,4,7};
  // int ret = sol.longestSubarray(nums, 63);
	printf("hey %d\n", ret);
	return 0;
}
