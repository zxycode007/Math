/*
ŷ������㷨��շת����
ԭ�� gcd(a,b)=gcd(b,a mod b)
��bΪ0ʱ�����������Լ����Ϊa
getchar()�����ǰһ��scanf�Ļس���
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