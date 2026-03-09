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

/*#include <iostream>
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
}*/

/*#include <iostream>
using namespace std;

//1.引用作为函数重载条件
void func(int& a) {
	cout << "func(int &a)" << endl;
}
void func(const int& a) {
	cout << "func(const int& a)" << endl;
}
//2.函数重载碰到默认参数
void func2(int a) {
	cout << "func(int a)" << endl;
}
void func2(int a, int b = 10) {
	cout << "func2(int a, int b = 10)" << endl;
}

int main() {
	int a = 10;
	func(a);
	func(10); //const int& a = 10;编译器优化：int temp = 10; const int& a = temp;

	func2(a, 20); //func(a)报错，两个重载都可以被调用
}*/

/*#include <iostream>
using namespace std;

#define PI 3.14

class circle {
	//访问权限：公共权限
public:
	//属性：一般为变量
	int r; //半径

	//行为：一般为函数
	double getC() {
		return 2 * PI * r;
	}
};

int main() {
	//通过圆类创建具体的圆（对象）
	//实例化——通过一个类创建一个对象的过程
	circle c1;
	c1.r = 1;
	cout << "圆的周长：" << c1.getC() << endl;
}*/

/*#include <iostream>
#include <string>
using namespace std;

class student {
	//访问权限：公共权限
public:
	//属性：一般为变量
	string name;
	string id;

	//行为：一般为函数
	void setName(string Name) {
		name = Name;
	}
	void setID(string ID) {
		id = ID;
	}
	void get() {
		cout << name << endl;
		cout << id << endl;
	}
};

int main() {
	//通过圆类创建具体的圆（对象）
	//实例化——通过一个类创建一个对象的过程
	student s1;
	s1.setName("张三");
	s1.setID("25021211");
	s1.get();
}*/

/*#include <iostream>
#include <string>
using namespace std;

class family {
	//公共权限
public:
	string name;
	//保护权限
protected:
	string car;
	//私有权限
private:
	string password;
};
int main() {
	family f;
	f.name = "李四";
	f.car = "奔驰";
	f.password = "123";
}*/

/*#include <iostream>
#include <string>
using namespace std;

class student {

public:
	void setname(string Name) {
		name = Name;
	}
	void getname() {
		cout << name << endl;
	}
	void getage() {
		cout << age << endl;
	}
	void setid(string ID) {
		id = ID;
	}
private:
	string name; //可读可写
	int age = 18;	 //只读
	string id;	 //只写
};

int main() {
	student s;
	//s.name = "张三";
	s.setname("张三");
	s.getname();
	//s.age
	s.getage();
	//s.id
	s.setid("2002111");
}*/

/*#include <iostream>
#include <string>
using namespace std;

class Cube {
public:
	//行为：
	void setLWH(int l, int w, int h) {
		L = l;
		W = w;
		H = h;
	}
	//获取面积
	int getS() {
		return 2 * (L * W + L * H + W * H);
	}
	//获取体积
	int getV() {
		return L * W * H;
	}
	//成员函数判断
	bool isSameClass(Cube& c2) {
		if (getS() == c2.getS() && getV() == c2.getV()) {
			return true;
		} else {
			return false;
		}
	}
private:
	//属性：
	int L;
	int W;
	int H;
};
//全局函数判断
bool isSameGlobal(Cube& c1, Cube& c2) {
	if (c1.getS() == c2.getS() && c1.getV() == c2.getV()) {
		return true;
	} else {
		return false;
	}
}
int main() {
	Cube cube1;
	cube1.setLWH(1, 2, 3);
	cout << cube1.getS() << endl;
	cout << cube1.getV() << endl;

	Cube cube2;
	cube2.setLWH(2, 3, 4);

	if (isSameGlobal(cube1, cube2)) {
		cout << "S和V相等" << endl;
	} else {
		cout << "S和V不相等" << endl;
	}

	if(cube2.isSameClass(cube2)) {
		cout << "S和V相等" << endl;
	} else {
		cout << "S和V不相等" << endl;
	}
}*/

/*#include <iostream>
using namespace std;
class Preson {
public:
	//构造函数
	Preson() {
		cout << "构造函数被调用" << endl;
	}
	//析构函数
	~Preson() {
		cout << "析构函数被调用" << endl;
	}
};
int main() {
	Preson preson;
}*/

/*#include <iostream>
using namespace std;
class Preson {
public:
	//构造函数
	Preson() {
		cout << "无参构造函数被调用" << endl;
	}
	Preson(int a) {
		cout << "有参构造函数被调用" << endl;
		age = 10;
	}
	Preson(const Preson& preson) {
		cout << "拷贝构造函数被调用" << endl;
		age = preson.age;
	}
	//析构函数
	~Preson() {
		cout << "析构函数被调用" << endl;
	}
	int age;
};
int main() {
	//括号法
	//Preson p1;
	//Preson p2(10);
	//Preson p3(p2);
	//cout << p2.age << endl;
	//cout << p3.age << endl;

	//显式法
	//Preson p1;
	//Preson p2 = Preson(10);
	//Preson p3 = Preson(p2);

	//隐式法
	//Preson p1;
	//Preson p2 = 10;
	//Preson p3 = p2;
}*/

/*#include <iostream>
using namespace std;

class Preson {
public:
	Preson() {
		cout << "无参构造函数被调用" << endl;
	}
	Preson(int a) {
		cout << "有参构造函数被调用" << endl;
		age = a;
	}
	Preson(const Preson& preson) {
		cout << "拷贝构造函数被调用" << endl;
		age = preson.age;
	}
	~Preson() {
		cout << "析构函数被调用" << endl;
	}
	//属性
	int age;
};

void test1() {
	Preson p1(10);
	Preson p2(p1);
}
void test2(Preson preson) {
	
}
Preson test3() {
	Preson p4;
	p4.age = 100;
	cout << &p4 << endl;
	cout << p4.age << endl;
	return p4;
}
int main() {
	//使用一个已经创建完毕的对象来初始化新的对象
	//test1();
	//值传递的方式给函数参数传值
	//Preson p3;
	//test2(p3); //实参p3被拷贝给形参preson
	//以值的方式返回局部对象
	Preson p5 = test3();
	p5.age = 10;
	cout << &p5 << endl;
	cout << p5.age << endl;
}*/

/*#include <iostream>
using namespace std;
class Preson {
public:
	//Preson() {
	//	cout << "无参构造函数被调用" << endl;
	//}
	//Preson(int a) {
	//	cout << "有参构造函数被调用" << endl;
	//	age = a;
	//}
	Preson(const Preson& preson) {
		cout << "拷贝构造函数被调用" << endl;
		age = preson.age;
	}
	~Preson() {
		cout << "析构函数被调用" << endl;
	}
	//属性
	int age;
};
int main() {
	Preson p1;
	Preson p2(10);
	Preson p3(p2);
	cout << p3.age << endl;
}*/

/*#include <iostream>
using namespace std;

class Preson {
public:
	Preson() {
		cout << "无参构造函数被调用" << endl;
	}
	Preson(int a, int h) {
		age = a;
		height = new int(h); //堆区开辟内存，手动释放
		cout << "有参构造函数被调用" << endl;
	}
	Preson(const Preson& preson) {
		age = preson.age;
		//浅拷贝：编译器默认实现
		//height = preson.height;
		//深拷贝
		height = new int(*preson.height);
		cout << "拷贝构造函数被调用" << endl;
	}
	~Preson() {
		if (height != NULL) {//检查指针是否为空
			delete height;   //释放指针指向的堆内存
			height = NULL;	 //将指针设为空
		}
		cout << "析构函数被调用" << endl;
	}
	int age;
	int* height;
};

int main() {
	Preson p1(18, 160);
	cout << p1.age << " " << *p1.height << endl;
	cout << &p1.age << endl;
	cout << p1.height << endl;
	Preson p2(p1);
	cout << p2.age << " " << *p2.height << endl;
	cout << &p2.age << endl;
	cout << p2.height << endl;
}*/

#include <iostream>
using namespace std;
class Preson {	
public:
	Preson(int A, int B, int C) {
		a = A;
		b = B;
		c = C;
	}
	int a, b, c;
};
int main() {
	Preson p(1, 2, 3);
	cout << p.a << " " << p.b << " " << p.c << endl;
}