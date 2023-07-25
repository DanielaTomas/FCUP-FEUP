#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(const char s[]) {
  int l = 0;
  int r = strlen(s) - 1;
  while (l < r) {
    if (s[l] != s[r])
      return false;
    l++;
    r--;
  }
  return true;
}

int main(int argc, char** argv) {
  for (int i = 1; i < argc; ++i)
    printf("Is \"%s\" a palindrome? %s\n",
      argv[i],
      is_palindrome(argv[i]) ? "yes" : "no");
   return 0;
}
