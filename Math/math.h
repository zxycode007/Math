#pragma once

//32位和64位架构
#define SAPPHIRE_ARCHITECTURE_32 1
#define SAPPHIRE_ARCHITECTURE_64 2
/* 判断架构32/64位 */
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
//判断大小,去较大或较小值
/**
@brief 取两者最小值
@param a 参数a
@param b 参数b
@return a，b中的最小值
*/
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
/**
@brief 取两者最大值
@param a 参数a
@param b 参数b
@return a，b中的最大值
*/
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

#include <math.h>
#include <random>
#include <time.h>

//这个数组快速计算以2位底0-512对数最近的整数
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

// 返回一个随机数
float asm_rand()
{

#if  SAPPHIRE_COMPILER == SAPPHIRE_COMPILER_MSVC &&  SAPPHIRE_ARCH_TYPE == SAPPHIRE_ARCHITECTURE_32
#if 1
#if SAPPHIRE_COMP_VER >= 1300

	static unsigned __int64 q = time(NULL);

	_asm {
		movq mm0, q      //将64位int变量q值移动到mmx寄存器mm0中

						 //操作码 0F 70 /r ib
						 //PSHUFW mm1, mm2/m64, imm8
						 //按照 imm8 中的编码对 mm2/m64 中的字执行乱序处理，结果存储到 mm1。
						 pshufw mm1, mm0, 0x1E   //压缩字乱序  
						 paddd mm0, mm1      //环绕打包双字节整数加法  按双字对齐,普通相加.与add指令类似.

											 // 在移动整形内存地址并且释放MMX寄存器
											 movq q, mm0
											 emms   //浮点寄存器复位
	}

	return float(q);
#endif
#else
	// 不支持PSHUFW
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
	//取绝对值
	x = abs(x);
	y = abs(y);

	//求其中较小值
	int mn = MIN(x, y);

	return(x + y - (mn >> 1) - (mn >> 2) + (mn >> 4));

}


int FastLog2(int x)
{
	float fx;
	unsigned long ix, exp;

	fx = (float)x;
	//提取单精度浮点型的完整IEEE浮点格式
	ix = *(unsigned long*)&fx;
	//右移23位去掉尾数域（23位），留下指数域8位
	exp = (ix >> 23) & 0xFF;
	//减去127偏差值，得真实指数域
	return exp - 127;
}

#endif