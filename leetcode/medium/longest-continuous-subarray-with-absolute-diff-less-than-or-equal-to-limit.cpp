// #include <string>
// #include<map>
// #include<vector>
// #include <algorithm>
// #include <cmath>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int longestSubarray(vector<int>& nums, int limit) {
    //   int tempDiff, ans = 1, j, minInSeq, maxInSeq;

    //   for (int i = 0; i < nums.size(); i++) {
    //     minInSeq = nums[i];
    //     maxInSeq = minInSeq;
    //     // if max ans than what comes next already made, break it
    //     if (ans >= (nums.size() - i)) {
    //       break;
    //     }
    //     for (j = i+1; j < nums.size(); j++) {
    //       tempDiff = max(abs(nums[j] - minInSeq), abs(maxInSeq - nums[j]));
    //       if (tempDiff > limit) {
    //         ans = max(j - i, ans);
    //         break;
    //       }
    //       if (nums[j] < minInSeq) {
    //         minInSeq = nums[j];
    //       }
    //       if (nums[j] > maxInSeq) {
    //         maxInSeq = nums[j];
    //       }
    //     }
    //     if (j == nums.size()) {
    //       ans = max(j - i, ans);
    //     }
    //   }

    //   return ans;
    // }

    int longestSubarray(vector<int>& nums, int limit) {
      int tempDiff, ans = 1, j = 1;
      int minInSeq, maxInSeq, prevEqualMinPos, prevEqualMaxPos;
      stack<pair<int,int>> minStack;
      stack<pair<int,int>> maxStack;

      for (int i = 0; i < nums.size(); i++) {
        if (minStack.empty() || (minStack.top().first > nums[i])) {
          minStack.push(make_pair(nums[i], i));
        }
        if (maxStack.empty() || (maxStack.top().first < nums[i])) {
          maxStack.push(make_pair(nums[i], i));
        }

        for (; j < nums.size(); j++) {
          minInSeq = minStack.top().first;
          maxInSeq = maxStack.top().first;
          // check if nums[j] can't work, then break
          tempDiff = max(abs(nums[j] - minInSeq), abs(maxInSeq - nums[j]));
          // save ans and clean up stack
          if (tempDiff > limit) {
            ans = max(j - i, ans);
            printf("%d %d..%d %d..%d\n", j - i, nums[i], nums[j], i, j);
            // clean up stack
            while (true) {
              if (!minStack.empty() && (minStack.top().second <= i)) {
                minStack.pop();
              } else if (!maxStack.empty() && (maxStack.top().second <= i)) {
                maxStack.pop();
              } else {
                break;
              }
            }
            break;
          }
          if (i == 25) {
            printf("stack %d %d\n", minStack.top().first, maxStack.top().first);
          }
          // if nums[j] works, update values
          if (nums[j] < minInSeq) {
            minStack.push(make_pair(nums[j], j));
          } else if (nums[j] == minInSeq) {
            prevEqualMinPos = minStack.top().second;
            if (prevEqualMinPos < j) {
              minStack.top().second = j;
              minStack.push(make_pair(nums[j], prevEqualMinPos));
            }
          }
          if (nums[j] > maxInSeq) {
            maxStack.push(make_pair(nums[j], j));
          } else if (nums[j] == maxInSeq) {
            prevEqualMaxPos = maxStack.top().second;
            if (prevEqualMaxPos < j) {
              maxStack.top().second = j;
              maxStack.push(make_pair(nums[j], prevEqualMaxPos));
            }
          }
        }
        if (j == nums.size()) {
          ans = max(j - i, ans);
          // can't get better than this as we reached till end now, so future solutions will be worse
          break;
        }
      }

      return ans;
    }
};

int main() {
  Solution sol;
  // vector<int> nums = {8,2,4,7};
  vector<int> nums = {7,40,10,10,40,39,96,21,54,73,33,17,2,72,5,76,28,73,59,22,100,91,80,66,5,49,26,45,13,27,74,87,56,76,25,64,14,86,50,38,65,64,3,42,79,52,37,3,21,26,42,73,18,44,55,28,35,87};
  int ret = sol.longestSubarray(nums, 63);
	printf("hey %d\n", ret);
	return 0;
}

// [10,1,2,4,7,2,6]
// 5
// Ans - 4

// [7,40,10,10,40,39,96,21,54,73,33,17,2,72,5,76,28,73,59,22,100,91,80,66,5,49,26,45,13,27,74,87,56,76,25,64,14,86,50,38,65,64,3,42,79,52,37,3,21,26,42,73,18,44,55,28,35,87]
