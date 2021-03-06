// algorithmtest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int parent(int i) //叫爸爸
{
	return i / 2;
}
int left(int i) //左儿子
{
	return i * 2 + 1;
}
int right(int i) //右儿子
{
	return i * 2 + 2;
}
void Max_Heapify(vector<int> &a, int i) //让爸爸最大
{
	int l = left(i);
	int r = right(i);
	int largest = 0;
	if (l <= a.size()-1 && a[l] > a[i])
		largest = l;
	else
		largest = i;
	if (r <= a.size()-1 && a[r] > a[largest])
		largest = r;
	if (largest != i)
	{
		//cout << a[i] << " " << a[largest] << endl;
		swap(a[i], a[largest]);
		Max_Heapify(a, largest);
	}
}

void Build_Max_Heap(vector<int> &a) //使数组成为最大堆
{
	for (int i = a.size() / 2; i >= 0; i--) {
		Max_Heapify(a, i);
	}
}

void HeapSort(vector<int> &a) 
{
	Build_Max_Heap(a);
	for (int i = a.size() - 1; i >= 0; i--) {
		swap(a[0], a[i]);
		cout << a[i] << " ";
		a.pop_back();
		if (a.size() == 0)
			break;
		Max_Heapify(a, 0);
	}
}

int main()
{
	int n = 0;
	int num_buf = 0;
	cin >> n;
	printf("heap size: %d\n", n);
	vector<int> A;
	for (int i = 1; i <= n; i++) {
		cin >> num_buf;
		A.push_back(num_buf);
	}
	HeapSort(A);
	return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
