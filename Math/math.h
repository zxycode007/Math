#pragma once
/*
ŷ������㷨��շת����
ԭ�� gcd(a,b)=gcd(b,a mod b)
��bΪ0ʱ�����������Լ����Ϊa
getchar()�����ǰһ��scanf�Ļس���
*/
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


/*
���ڲ���ȫΪ 0 �ķǸ����� a��b��gcd��a��b����ʾ a��b �����Լ������Ȼ
���������� x��y ��ʹ�� gcd��a��b��=ax+by��
*/
int gcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int q = gcd(b, a%b, y, x);
	y -= a / b*x;
	return q;
}