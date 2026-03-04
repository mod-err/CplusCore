/*#include <iostream>
using namespace std;

int g_a = 10;
int g_b = 10;
const int c_g_a = 10;
const int c_g_b = 10;

int main() {

	//全局区：全局变量，静态变量，字符串常量和const修饰的全局变量
	
	//全局变量
	cout << "全局变量a地址：" << (int)&g_a << endl;
	cout << "全局变量b地址：" << (int)&g_b << endl;
	//静态变量
	static int s_a = 10;
	static int s_b = 10;
	cout << "静态变量a地址：" << (int)&s_a << endl;
	cout << "静态变量b地址：" << (int)&s_b << endl;
	//字符串常量
	cout << "字符串常量地址" << (int)&"HELLO" << endl;
	//const修饰的全局变量
	cout << "const修饰的全局变量a地址：" << (int)&c_g_a << endl;
	cout << "const修饰的全局变量b地址：" << (int)&c_g_b << endl;

	//非全局区：局部变量

	//局部变量
	int l_a = 10;
	int l_b = 10;
	cout << "局部变量a地址：" << (int)&l_a << endl;
	cout << "局部变量b地址：" << (int)&l_b << endl;
	//const修饰的局部变量
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "const修饰的局部变量a地址：" << (int)&c_l_a << endl;
	cout << "const修饰的局部变量b地址：" << (int)&c_l_b << endl;

	system("pause");
	return 0;
}*/

/*#include <iostream>
using namespace std;

int* func() {
	int a = 10;
	return &a;
}

int main() {
	int* p = func();
	cout << *p << endl;
}*/

/*#include <iostream>
using namespace std;

int* func1() {
	int* p = new int(10);
	return p;
}
void func2() {
	int* arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;//等价于*(arr + i) = i + 100;
		cout << arr[i] << endl;
	}
	delete[] arr;
}

int main() {
	int* p = func1();
	cout << *p << endl;
	delete p;

	func2();
}*/

/*#include <iostream>
using namespace std;

int* func1() {
	int* p = new int(10);
	return p;
}
void func2() {
	int* arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;//等价于*(arr + i) = i + 100;
		cout << arr[i] << endl;
	}
	delete[] arr;
}

int main() {
	int* p = func1();
	cout << *p << endl;
	delete p;

	func2();
}*/

/*#include <iostream>
using namespace std;

void func1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
void func2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void func3(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 10;
	int b = 20;
	func1(a, b);
	cout << "原值：" << a << " " << b << endl;
	func2(&a, &b);
	cout << "地址传递：\t" << a << " " << b << endl;
	func2(&a, &b);

	func3(a, b);
	cout << "引用传递：\t" << a << " " << b << endl;
}*/

/*#include <iostream>
using namespace std;

int& func1() {
	int a = 10;
	return a;
}
int& func2(){
	static int a = 10;
	return a;
}

int main() {
	int& ref1 = func1();
	cout << ref1 << endl;
	cout << ref1 << endl;
	
	int& ref2 = func2();
	cout << ref2 << endl;
	cout << ref2 << endl;

	func2() = 1000;
	cout << ref2 << endl;
	cout << ref2 << endl;
}*/


/*int* func3() {
	int a = 10;
	return &a;
}
int main() {
	int* p = func3();
	cout << p << endl;
	//	cout << &p << endl;
	cout << *p << endl;
}*/
