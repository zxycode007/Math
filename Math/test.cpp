/*
欧几里德算法：辗转求余
原理： gcd(a,b)=gcd(b,a mod b)
当b为0时，两数的最大公约数即为a
getchar()会接受前一个scanf的回车符
*/
#include<stdio.h>
unsigned int Gcd(unsigned int M, unsigned int N)
{
	unsigned int Rem;
	while (N > 0)
	{
		Rem = M % N;
		M = N;
		N = Rem;
	}
	return M;
}
int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("the greatest common factor of %d and %d is ", a, b);
	printf("%d\n", Gcd(a, b));
	return 0;
}