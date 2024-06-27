#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter2(vector<vector<int>>& edges) {
      set<int> s;
      int soln = -1;
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          if (s.contains(edges[i][j])) {
            soln = edges[i][j];
            break;
          }
          s.insert(edges[i][j]);
        }
        if (soln != -1) break;
      }
      return soln;
    }

    int findCenter(vector<vector<int>>& edges) {
      if ( (edges[0][0] == edges[1][0]) || (edges[0][1] == edges[1][0]) ) {
        return edges[1][0];
      } else if ( (edges[0][0] == edges[1][1]) || (edges[0][1] == edges[1][1]) ) {
        return edges[1][1];
      }
      return -1;
    }
};


int main() {
  Solution sol;
  int ret = sol.findCenter();
	printf("hey %d\n", ret);
	return 0;
}
