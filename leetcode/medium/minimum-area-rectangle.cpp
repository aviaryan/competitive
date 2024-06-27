#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
      sort(points.begin(), points.end());
      set<pair<int, int>> pointsHash; // just use set instead of unordered_set
      multimap<int, int> pointsMap; // saved in [y, x] form

      for (int i = 0; i < points.size(); i++) {
        pointsHash.insert(make_pair(points[i][0], points[i][1])); // for 4th point of rect
        pointsMap.insert(pair<int, int>(points[i][1], points[i][0])); // for 3rd point of rect [y, x]
      }

      int ans = INT_MAX, tempArea;
      vector<int> firstPoint, secondPoint;
      // solve
      for (int i = 0; i < (points.size() - 1); i++) {
        firstPoint = points[i];
        for (int j = i+1; j < points.size(); j++) {
          secondPoint = points[j];
          if (secondPoint[0] != firstPoint[0]) {
            // if x not equal, can't be second point
            // and no future point should have same x, so break
            break;
          }
          // find 3rd point
          auto it = pointsMap.equal_range(firstPoint[1]);
          for (auto itr = it.first; itr != it.second; ++itr) {
            // https://www.geeksforgeeks.org/multimap-equal_range-in-c-stl/
            if (itr->second <= firstPoint[0]) {
              // this is the point we have as firstPoint, ignore
              // or point is on left side, which we should have already checked, don't check again
              continue;
            }
            // got 3rd point in form of [itr->second, firstPoint[1]] x, y
            // find 4th point
            if (pointsHash.find(make_pair(itr->second, secondPoint[1])) != pointsHash.end()) {
              tempArea = (secondPoint[1] - firstPoint[1]) * (itr->second - firstPoint[0]);
              ans = min(ans, tempArea);
            }
          }
        }
      }
      return (ans == INT_MAX) ? 0 : ans;
    }
};


int main() {
  Solution sol;
  vector<vector<int>> points = {{1,1},{3,1},{3,3},{1,3},{4,3},{4,1}};
  int ret = sol.minAreaRect(points);
	printf("hey %d\n", ret);
	return 0;
}
