// 何老师.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<time.h>
#include<armadillo>
using namespace std;
using namespace arma;
mat enframe(mat x, mat win, int inc) {
	int len;
	mat x1 = x;
	int nx = x1.n_elem;
	int nwin = win.n_elem;
	if (nwin == 1) {
		len = win(0);
	}
	else {
		len = nwin;
	}

	if (inc == -1) {
		inc = len;
	}

	int nf = floor((nx - len + inc) / inc);
	mat frameout(1, nf*len + 1);
	mat a(nf, 1);
	for (int i = 0; i < nf; i++) {
		a(i) = i;
	}
	mat indf = inc*a;
	mat inds(1, len);
	for (int i = 1; i <= len; i++) {
		inds(i - 1) = i;
	}

	int k = 0;
	inds = repmat(inds, nf, 1);
	indf = repmat(indf, 1, len);
	a = inds + indf;
	for (int i = 0; i < a.n_elem; i++) {
		frameout(k++) = x(a(i) - 1);
	}
	frameout.reshape(nf, len);

	if (nwin > 1) {
		a = win.t();
		frameout = frameout%repmat(a, nf, 1);
	}
	return frameout;
}
int main()
{
	mat A(2, 2), B(2, 2);
		for (int i = 0; i < 4; i++)
		{
		A(i) = i + 1;//i：以列为排列顺序，矩阵的第i个元素
		B(i) = i + 5;
		}
		A.print("矩阵A为：");
		B.print("矩阵B为：");
		//2、矩阵A与矩阵B相加
		mat AAddB = A + B;
		AAddB.print("A + B =");
		//3、矩阵A与矩阵B相减
		mat AMinusB = A - B;
		AMinusB.print("A - B =");
		//4、矩阵A与矩阵B相乘
		//mat AMulB = A * B;
		//AMulB.print("A * B =");
		//5、矩阵A与矩阵B点除
		mat ADiviB = A / B;
		ADiviB.print("A / B =");
		//6、矩阵A与矩阵B点乘
		mat ADotMulB = A % B;
		ADotMulB.print("A % B =");

		B.col(1) = A.col(1) * 2;
		cout << endl << B << endl;

		B.reshape(1,2);
		cout << B << endl;


		//cout << repmat(B, 5, 1) << endl;

		mat c;
		c << 0.165300 << 0.454037 << 0.995795 << 0.124098 << 0.047084 << endr
		<< 0.688782 << 0.036549 << 0.552848 << 0.937664 << 0.866401 << endr
		<< 0.348740 << 0.479388 << 0.506228 << 0.145673 << 0.491547 << endr
		<< 0.148678 << 0.682258 << 0.571154 << 0.874724 << 0.444632 << endr
		<< 0.245726 << 0.595218 << 0.409327 << 0.367827 << 0.385736 << endr;
		cout << c << endl;
		getchar();

    return 0;
}

