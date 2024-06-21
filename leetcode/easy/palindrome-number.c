#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

bool isPalindrome(int x) {
	int xc = x;
  if (x < 0) return false;
  if (x == 0) return true;
  if (x % 10 == 0) return false;
  // else do reverse
  int s = 0, rem;
  while (x > 0) {
    rem = x % 10;
    s = s * 10 + rem;
    x = x/10;
  }
  return (s == xc);
}

int main() {
	bool ret2 = isPalindrome(121);
	printf("%s\n", ret2 ? "palindrome" : "not");
	return 0;
}
