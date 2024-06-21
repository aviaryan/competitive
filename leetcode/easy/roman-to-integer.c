#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int romanToInt(char* s) {
  int length = strlen(s);
  int sum = 0;
  char possibleCarry = NULL;

  for (int i = 0; i < length; i++) {
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
    }

    // sum up the char for total Number

  }
  // printf("%d\n", size);
}

int main() {
	int ret = romanToInt("abcd");
	printf("%d\n", ret);
	return 0;
}
