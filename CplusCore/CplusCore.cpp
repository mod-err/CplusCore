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

/*#include <iostream>
using namespace std;

int* func3() {
	int a = 10;
	return &a;
}
int* func2() {
	int* a = new int(10);
	return a;
}

int main() {
	int* p = func3();  // ① 指针p接收func3返回的地址（即原a的栈区地址）
	cout << p << endl; // ② 打印p中存储的地址值（就是原a的地址）
	cout << &p << endl;// ③ 打印指针变量p自己的内存地址（p本身也是个变量，存在栈区）
	cout << *p << endl;// ④ 解引用p：试图访问p指向的地址（原a的地址）中的值

	int* q = func2();
	cout << q << endl;
	cout << &q << endl;
	cout << *q << endl;
	delete q;
}*/

/*#include <iostream>
using namespace std;

void func(int& ref) { 
	ref = 100;  //ref是引用，自动转换为*ref
}

int main() {
	int a = 10;
	//内部自动转换为：int* const ref = &a
	int& ref = a;
	ref = 20; //ref是引用，自动转换为*ref = 20；
	cout << a << endl;   //20
	cout << ref << endl; //20

	func(a);
	cout << a << endl;   //100
}*/

/*#include <iostream>
using namespace std;

//const防止误修改实参
void func(const int& ref) {
	cout << ref << endl;
}

int main() {
	int a = 10;
	func(a);
	//编译器自动改为int temp = 100; int& ref = temp;
	const int& ref = 100;
}*/

/*#include <iostream>
using namespace std;

int func(int a, int b = 10, int c = 30) {
	return a + b + c;
}

int main() {
	int a = 10;
	cout << func(a) << endl;

	int b = 20, c = 40;
	cout << func(a, b, c) << endl; //b,c赋值传入
}*/

#include <iostream>
using namespace std;

void func() {
	cout << "func()被调用" << endl;
}
void func(int a) {
	cout << "func(int a)被调用" << endl;
}
void func(double a) {
	cout << "func(double a)被调用" << endl;
}
void func(int a, double b) {
	cout << "func(int a, int b)被调用" << endl;
}
void func(double a, int b) {
	cout << "func(double a, int b)被调用" << endl;
}

int main() {
	func();
	func(10);
	func(3.14);
	func(3.14, 10);
	func(10, 3.14);
}