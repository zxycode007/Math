#pragma once

//32λ��64λ�ܹ�
#define SAPPHIRE_ARCHITECTURE_32 1
#define SAPPHIRE_ARCHITECTURE_64 2
/* �жϼܹ�32/64λ */
#if defined(__x86_64__) || defined(_M_X64) || defined(__powerpc64__) || defined(__alpha__) || defined(__ia64__) || defined(__s390__) || defined(__s390x__)
#   define SAPPHIRE_ARCH_TYPE SAPPHIRE_ARCHITECTURE_64
#else
#   define SAPPHIRE_ARCH_TYPE SAPPHIRE_ARCHITECTURE_32
#endif
#define SAPPHIRE_COMPILER_MSVC 1


#if defined(_MSC_VER)
#define SAPPHIRE_COMPILER SAPPHIRE_COMPILER_MSVC
#define SAPPHIRE_COMP_VER _MSC_VER


#define SWAP(a,b,t) {t=a; a=b; b=t;}
//�жϴ�С,ȥ�ϴ���Сֵ
/**
@brief ȡ������Сֵ
@param a ����a
@param b ����b
@return a��b�е���Сֵ
*/
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
/**
@brief ȡ�������ֵ
@param a ����a
@param b ����b
@return a��b�е����ֵ
*/
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

#include <math.h>
#include <random>
#include <time.h>

//���������ټ�����2λ��0-512�������������
unsigned char logbase2ofx[513] =
{
	0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,

	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,

};


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

float Q_rsqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y));
	//	y  = y * ( threehalfs - ( x2 * y * y ) );   

	return y;
}

float Q_fabs(float f) {
	int tmp = *(int *)&f;
	tmp &= 0x7FFFFFFF;
	return *(float *)&tmp;
}

// ����һ�������
float asm_rand()
{

#if  SAPPHIRE_COMPILER == SAPPHIRE_COMPILER_MSVC &&  SAPPHIRE_ARCH_TYPE == SAPPHIRE_ARCHITECTURE_32
#if 1
#if SAPPHIRE_COMP_VER >= 1300

	static unsigned __int64 q = time(NULL);

	_asm {
		movq mm0, q      //��64λint����qֵ�ƶ���mmx�Ĵ���mm0��

						 //������ 0F 70 /r ib
						 //PSHUFW mm1, mm2/m64, imm8
						 //���� imm8 �еı���� mm2/m64 �е���ִ������������洢�� mm1��
						 pshufw mm1, mm0, 0x1E   //ѹ��������  
						 paddd mm0, mm1      //���ƴ��˫�ֽ������ӷ�  ��˫�ֶ���,��ͨ���.��addָ������.

											 // ���ƶ������ڴ��ַ�����ͷ�MMX�Ĵ���
											 movq q, mm0
											 emms   //����Ĵ�����λ
	}

	return float(q);
#endif
#else
	// ��֧��PSHUFW
	return float(rand());
#endif
#else
	// GCC 

	return float(rand());

#endif
}


float Q_crandom(int *seed) {
	return 2.0 * (Q_random(seed) - 0.5);
}

float Q_random(int *seed) {
	return (Q_rand(seed) & 0xffff) / (float)0x10000;
}

int	Q_rand(int *seed) {
	*seed = (69069 * *seed + 1);
	return *seed;
}

float  Fast_Distance_3D(float fx, float fy, float fz)
{


	int temp;
	int x, y, z;


	x = fabs(fx) * 1024;
	y = fabs(fy) * 1024;
	z = fabs(fz) * 1024;


	if (y < x) SWAP(x, y, temp)

		if (z < y) SWAP(y, z, temp)

			if (y < x) SWAP(x, y, temp)

				int dist = (z + 11 * (y >> 5) + (x >> 2));

	return((float)(dist >> 10));

}



int Fast_Distance_2D(int x, int y)
{
	//ȡ����ֵ
	x = abs(x);
	y = abs(y);

	//�����н�Сֵ
	int mn = MIN(x, y);

	return(x + y - (mn >> 1) - (mn >> 2) + (mn >> 4));

}


int FastLog2(int x)
{
	float fx;
	unsigned long ix, exp;

	fx = (float)x;
	//��ȡ�����ȸ����͵�����IEEE�����ʽ
	ix = *(unsigned long*)&fx;
	//����23λȥ��β����23λ��������ָ����8λ
	exp = (ix >> 23) & 0xFF;
	//��ȥ127ƫ��ֵ������ʵָ����
	return exp - 127;
}

#endif