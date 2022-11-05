#include <iostream>
#include <conio.h>
#include "string-final.h"
#include "vec-final.h"


using namespace std;
int testVec();
int testStr();
int test();

int main()
{
	int a = 1;
	while (a)
	{
		cout << "\n1 --- testing Vector"
			<< "\n2 --- testing String"
			<< "\n3 --- testing Vector & String"
			<< "\n0 --- exit"
			<< endl;

		cin >> a;
		switch (a)
		{
		case 1:testVec();	break;
		//case '2':testStr();	break;
		//case '3':test();			break;
		case '0':a = 0;		break;
		}
	}
	return 0;

}

/*int test()
{
	Vector<int> v;
	String str;
	int n;

	cout << "请输入一个整数向量。" << endl;
	cin >> v;
	cout << v << endl;
	cin.sync();			// 刷新输入流缓冲区（目的是读取并丢弃向量后的换行符）
	cout << "请输入一个字符串。" << endl;
	cin >> str;						// 并非读取整行
	cout << str << endl;

	cout << "请输入修改后Vector和String的大小" << endl;
	cin >> n;
	cout << "\n调整对象维数为"<<n<<"，实现多态性" << endl;
	try
	{
		v.resize(n);
		str.resize(n);
	}
	catch (double d)
	{
		cout << "Failed to resize" << endl;
	}
	catch (int a)
	{
		cout << "Failed to resize" << endl;
	}
	cout << "向量：" << v << endl
		<< "字符串：\"" << str << "\"" << endl;



	cout << "向量：" << v << endl
		<< "字符串：\"" << str << "\"" << endl;
	return 0;
}
*/
int testVec()
{
	int a[10], b[10], x = 0, c = 1, length;	//this->l是向vec中添加的数据，length是修改size
	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
		b[i] = 2 * i;
	}
	Vector<int> vec1(10, a);
	Vector<int> vec2(10, b);
	cout << vec1<<endl;
	//vec1.pop_back();
	//cout << vec1 << endl;
	vec1.reverse(0, 3);
	cout << vec1 << endl;;
	while (c) {
		cout << endl << "当前vector为:vec1=" << vec1 << ", vec2=" << vec2 << endl << "请选择测试操作:";
		cout << endl << "1. 测试关系运算符==";
		cout << endl << "2. 获取vec1和vec2的维数";
		cout << endl << "3. 向vec1中添加数据";
		cout << endl << "4. 向vec2中添加数据";
		cout << endl << "5. 测试赋值运算符，将vec2赋值给vec1";
		cout << endl << "6. 修改vec1维数";
		cout << endl << "7. 修改vec2维数";
		cout << endl << "8. 测试越界";
		cout << endl << "0. 退出";
		cout << endl << "选择功能 (0~8):";
		cin >> c;
		switch (c) {
		case 1:
			cout << "vec1为：";
			cout << vec1 << endl;
			cout << "vec2为：";
			cout << vec2 << endl;
			if (vec1 == vec2)
				cout << "vec1和vec2相等。" << endl;
			else
				cout << "vec1和vec2不相等。" << endl;
			break;
		case 2:
			cout << "vec1容量为：";
			cout << vec1.getsize() << endl;
			cout << "vec2容量为：";
			cout << vec2.getsize() << endl;
			break;
		case 3:
			cout << "请输入您想要添加的数据";
			cin >> x;
			vec1.push_back(x);
			break;
		case 4:
			cout << "请输入您想要添加的数据";
			cin >> x;
			vec2.push_back(x);
			break;
		case 5:
			vec1 = vec2;
			break;
		case 6:
			cout << "请输入vec1修改后的大小:";
			cin >> length;
			vec1.resize(length);
			break;
		case 7:
			cout << "请输入vec2修改后的大小:";
			cin >> length;
			vec2.resize(length);
			break;
		case 8:
			cout << "调用a[length+1]";
			cout << vec1[11];
			break;
		default:
			break;
		}
	}
	system("pause");

	return 0;
}
/*
int testStr()
{
	String s1("SHU");
	String s2("OOP");
	String s3;

	int c = 1;
	int x, l;

	while (c) {
		cout << "当前默认字符串为:s1=" << s1 << ", s2=" << s2 << endl << "请选择测试操作:";
		cout << endl << "1. 测试关系运算符==";
		cout << endl << "2. 测试下标运算符";
		cout << endl << "3. 测试连接运算符+与+=";
		cout << endl << "4. 输入字符串1";
		cout << endl << "5. 输入字符串2";
		cout << endl << "0. 退出";
		cout << endl << "选择功能 (0~5):";
		cin >> c;
		switch (c) {
		case 1:
			cout << "字符串s1为：";
			cout << s1 << endl;
			cout << "字符串s2为：";
			cout << s2 << endl;
			if (s1 == s2)
				cout << "s1和s2相等。" << endl;
			else
				cout << "s1和s2不相等。" << endl;
			break;
		case 2:
			cout << "字符串s1为：";
			cout << s1 << endl;
			cout << endl << "输入字符下标：";
			cin >> x;
			cout << endl << "测试下标运算符结果为：" << endl;
			try {
				cout << s1[x] << endl;
			}
			catch (out_of_range& e)
			{
				cerr << e.what() << endl;
			}
			break;
		case 3:
			cout << "字符串s1为：";
			cout << s1 << endl;
			cout << "字符串s2为：";
			cout << s2 << endl;
			s3 = s1 + s2;
			cout << endl << "字符串连接结果（使用+）为：";
			cout << s3 << endl;
			s1 += s2;
			cout << endl << "字符串连接结果（使用+=）为：";
			cout << s1 << endl;
			break;
		case 4:
			cout << endl << "输入字符串1：";
			cin >> s1;
			break;
		case 5:
			cout << endl << "输入字符串2：";
			cin >> s2;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}*/