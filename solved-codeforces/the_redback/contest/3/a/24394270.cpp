#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <string>
#include <cstdio>
#include <vector>
#include <stack>
#include <bitset>
using namespace std;

int main()
{
	int b, d;
	char a, c;

	scanf("%c%d", &a, &b);
	getchar();
	scanf("%c%d", &c, &d);
	getchar();

	printf("%d\n", max(abs(a-c), abs(b-d)));


	while(a != c || b != d) {
		if(a > c) {
			printf("L");
			a--;
		}
		else if(a < c) {
			printf("R");
			a++;
		}

		if(b > d) {
			printf("D");
			b--;
		}
		else if(b < d) {
			printf("U");
			b++;
		}

		printf("\n");
	}


	return 0;
}