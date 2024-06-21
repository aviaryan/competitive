#include <string>
#include<map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
      map<char,int> romanValues;
      romanValues['I'] = 1;
      romanValues['V'] = 5;
      romanValues['X'] = 10;
      romanValues['L'] = 50;
      romanValues['C'] = 100;
      romanValues['D'] = 500;
      romanValues['M'] = 1000;
      int sum = 0;
      char possibleCarry = '\0';

      for (int i = 0; i < s.length(); i++) {
        // prev possibleCarry --
        if (possibleCarry == 'I') {
          if (s[i] == 'V' || s[i] == 'X') {
            sum -= 2;
          }
        } else if (possibleCarry == 'X') {
          if (s[i] == 'L' || s[i] == 'C') {
            sum -= 20;
          }
        } else if (possibleCarry == 'C') {
          if (s[i] == 'D' || s[i] == 'M') {
            sum -= 200;
          }
        }

        if (s[i] == 'I' || s[i] == 'X' || s[i] == 'C') {
          possibleCarry = s[i];
        } else {
          possibleCarry = '\0';
        }

        // sum up the char for total Number
        sum += romanValues[s[i]];
      }

      return sum;
    }
};

int main() {
  Solution sol;
  int ret = sol.romanToInt("XL");
	printf("hey %d\n", ret);
	return 0;
}
