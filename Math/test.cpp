#include <stdio.h>
#include "math.h"

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("the greatest common factor of %d and %d is ", a, b);
	printf("%d\n", Gcd(a, b));
	return 0;
}