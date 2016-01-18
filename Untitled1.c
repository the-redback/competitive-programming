#include <stdio.h>

int main () {

  int kase, cnt = 0;
  scanf ( "%d", &kase );
  while ( kase-- ) {
    long long a, b;
    char c;
    scanf ( "%lld %lld %c", &a, &b, &c );

    long long res = 0;
    if ( c == '+' ) res = a + b;
    if ( c == '-' ) res = a - b;
    if ( c == '*' ) res = a * b;
    if ( c == '/' ) res = a / b;
    if ( c == '%' ) res = a % b;

    printf ( "Case %d: %lld\n", ++cnt, res );
  }

  return 0;
}
