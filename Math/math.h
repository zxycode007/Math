#pragma once
/*
欧几里德算法：辗转求余
原理： gcd(a,b)=gcd(b,a mod b)
当b为0时，两数的最大公约数即为a
getchar()会接受前一个scanf的回车符
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
对于不完全为 0 的非负整数 a，b，gcd（a，b）表示 a，b 的最大公约数，必然
存在整数对 x，y ，使得 gcd（a，b）=ax+by。
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