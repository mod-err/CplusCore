/*#include <iostream>
#include <string>
using namespace std;

class Building {
	friend void goodGay(Building& building);//好基友认证
public:
	Building() : mSittingroom("客厅"), mBedroom("卧室") {
		
	}
	string mSittingroom;
private:
	string mBedroom;
};

void goodGay(Building& building) {
	cout << "好基友正在访问：" << building.mSittingroom << endl;
	cout << "好基友正在访问：" << building.mBedroom << endl;
}

int main() {
	Building b;
	goodGay(b);
}*/

/*#include <iostream>
#include <string>
using namespace std;

class Building {
	friend class goodGay;
public:
	Building() : mSittingroom("客厅"), mBedroom("卧室") { }
	string mSittingroom;
private:
	string mBedroom;
};

class goodGay {
public:
	//1.栈上创建
	//void visit() {
	//	cout << "好基友正在访问：" << building.mSittingroom << endl;
	//}
	//Building building;
	//2.堆区创建
	goodGay() {
		building = new Building;
	}
	~goodGay() {
		if(building != NULL) delete building;
	}
	void visit() {
		cout << "好基友正在访问：" << building->mSittingroom << endl;
		cout << "好基友正在访问：" << building->mBedroom << endl;
	}
	Building* building;
};

int main() {
	goodGay g;
	g.visit();
}*/

/*#include <iostream>
#include <string>
using namespace std;

class Building;
class goodGay {
public:
	goodGay();
	~goodGay() {
		if (building != NULL) delete building;
	}
	void visit();
	Building* building;
};
class Building {
	friend void goodGay::visit();
public:
	Building() : mSittingroom("客厅"), mBedroom("卧室") {}
	string mSittingroom;
private:
	string mBedroom;
};

goodGay::goodGay() {
	building = new Building;
}
void goodGay::visit() {
	cout << "好基友正在访问：" << building->mSittingroom << endl;
	cout << "好基友正在访问：" << building->mBedroom << endl;
}
int main() {
	goodGay g;
	g.visit();
}*/

/*#include <iostream>
#include <string>
using namespace std;
class Person {
public:
	//Person operator+(Person& person) {
	//	Person temp;
	//	temp.mA = this->mA + person.mA;
	//	temp.mB = this->mB + person.mB;
	//	return temp;
	//}
	int mA;
	int mB;
};

Person operator+(Person& p1, Person& p2) {
	Person temp;
	temp.mA = p1.mA + p2.mA;
	temp.mB = p1.mB + p2.mB;
	return temp;
}
Person operator+(Person& p1, int num) {
	Person temp;
	temp.mA = p1.mA + num;
	temp.mB = p1.mB + num;
	return temp;
}
int main() {
	Person p1;
	p1.mA = 10;
	p1.mB = 20;
	Person p2;
	p2.mA = 30;
	p2.mB = 40;
	Person p3;

	//p3 = p1 + p2; 
	//p3 = p1.operator+(p2);
	p3 = p1 + 10;
	cout << p3.mA << " " << p3.mB << endl;
}*/

/*#include <iostream>
using namespace std;

class Person {
public:
	void operator<<(ostream& cout) {
		cout << this->mA << " " << this->mB << endl;
	}
	int mA, mB;
};

int main() {
	Person p;
	p.mA = 10;
	p.mB = 20;
	//p.operator<<(cout);
	p << cout;
}*/

/*#include <iostream>
using namespace std;

class Person {
	friend ostream& operator<<(ostream& cout, Person& person);
public:
	Person() : mA(10), mB(20){
	}
private:
	int mA, mB;
};
ostream& operator<<(ostream& cout, Person& person) {
	cout << person.mA << " " << person.mB << endl;
	return cout;
}
int main() {
	Person p;
	//operator<<(cout, p);
	cout << p << endl;
}*/

/*#include <iostream>
using namespace std;

class MyInt {
	friend ostream& operator<<(ostream& cout, const MyInt& myInt);
public:
	MyInt() : mint(0) {}
	//前置自增
	MyInt& operator++() {
		++mint;
		return *this;
	}
	//后置自增
	MyInt operator++(int) {
		MyInt temp = *this;
		mint++;
		return temp;
	}
private:
	int mint;
};
ostream& operator<<(ostream& cout, const MyInt& myInt) {
	cout << myInt.mint;
	return cout;
}
int main() {
	MyInt m;
	//m.operator++();
	cout << ++(++m) << endl;
	cout << m << endl;

	cout << m++ << endl;
	cout << m << endl;
}*/

/*#include <iostream>
using namespace std;
class Person {
public:
	Person(int age) {
		mage = new int(age);
	}
	~Person() {
		if (mage != NULL) { delete mage; mage = NULL; }
	}
	Person& operator=(Person& person) {
		if (mage != NULL) { delete mage; mage = NULL; }
		mage = new int(*person.mage);
		return *this;
	}
	int* mage;
};
int main() {
	Person p1(10);
	Person p2(20);
	Person p3(30);
	//p2.operator=(p1);
	p3 = p2 = p1;
	cout << *p1.mage << endl;
	cout << *p2.mage << endl;
	cout << *p3.mage << endl;
}*/

/*#include <iostream>
#include <string>
using namespace std;
class Person {
public:
	Person(string name, int age) :mName(name), mAge(age) {}
	bool operator==(Person& person) {
		if (this->mAge == person.mAge && this->mName == person.mName)
			return true;
	}
	bool operator!=(Person& person) {
		if (this->mAge != person.mAge && this->mName != person.mName)
			return false;
	}
	string mName;
	int mAge;
};
int main() {
	Person p1("张三", 19);
	Person p2("张三", 19);
	//if(p2.operator==(p1)) cout << "相同" << endl;
	if(p1 == p2) cout << "相同" << endl;
	else if (p1 != p2) cout << "不相同" << endl;

}*/

/*#include <iostream>
#include <string>
using namespace std;
class MyClass {
public:
	void operator()(string a) {
		cout << a << endl;
	}
	int operator()(int a, int b) {
		return a + b;
	}
};
int main() {
	MyClass m;
	m("你好");//m.operator()("你好");
	cout << m(10, 20) <<endl;//m.operator()(10, 20);
	MyClass()("我不好");//MyClass().operator()("我不好");
	cout << MyClass()(10, 40) << endl;
}*/

/*#include <iostream>
using namespace std;
class BasePage {
public:
	void header() {
		cout << "公共头部：首页、登录注册" << endl;
	}
	void footer() {
		cout << "公共底部：帮助中心、交流合作" << endl;
	}
	void left() {
		cout << "公共左侧：java、python、c++" << endl;
	}
};
class Java : public BasePage {
public:
	void contenet()
	{
		cout << "java学科视频" << endl;
	}
};
class CPP : public BasePage {
public:
	void contenet()
	{
		cout << "C++学科视频" << endl;
	}
};

int main() {
	Java j;
	j.contenet();
	j.header();
	j.footer();
	j.left();

	CPP c;
	c.contenet();
	c.header();
	c.footer();
	c.left();
}*/

/*#include <iostream>
using namespace std;
class Base {
public:
	int mA;
protected:
	int mB;
private:
	int mC;
};
class son1 : public Base {
public:
	son1(){
		mA = 10;//父类：公共权限成员，子类：公共权限
		mB = 20;//父类：保护权限成员，子类：保护权限
		//mC = 30;父类：私有权限成员，子类访问不到
	}
};
class son2 : protected Base {
public:
	son2() {
		mA = 10;//父类：公共权限成员，子类：保护权限
		mB = 20;//父类：保护权限成员，子类：保护权限
		//mC = 30;父类：私有权限成员，子类访问不到
	}
};
class son3 : private Base {
	son3() {
		mA = 10;//父类：公共权限成员，子类：私有权限
		mB = 20;//父类：保护权限成员，子类：私有权限
		//mC = 30;父类：私有权限成员，子类访问不到
	}
};
int main() {
	son1 s1;
	cout << s1.mA << endl;//s1.mB

	son2 s2;
	//cout << s2.mA << endl;
	//cout << s2.mB << endl;
	son3 s3;
	cout << s3.mA << endl;
}*/

/*#include <iostream>
using namespace std;
class Base {
public:
	Base() {
		cout << "Base的构造函数被调用" << endl;
	}
	~Base() {
		cout << "Base的析构函数被调用" << endl;
	}
};
class Son : public Base {
public:
	Son() {
		cout << "Son的构造函数被调用" << endl;
	}
	~Son() {
		cout << "Son的析构函数被调用" << endl;
	}
};
int main() {
	//Base b;
	Son s;
}*/

/*#include <iostream>
using namespace std;
class Base {
public:
	int mA = 100;
	void func() {
		cout << "Base" << endl;
	}
	void func(int a) {
		cout << "Base_a" << endl;
	}
};
class Son : public Base {
public:
	int mA = 200;
	void func() {
		cout << "Son" << endl;
	}
};
int main() {
	Son s;
	cout << s.mA << endl;
	cout << s.Base::mA << endl;
	s.func();
	s.Base::func();
	s.Base::func(100);
}*/

/*#include <iostream>
using namespace std;
class Base {
public:
	static int mA;
	static void func() {
		cout << "Base" << endl;
	}
	static void func(int a) {
		cout << "Base a" << endl;
	}
};
int Base::mA = 100;

class Son : public Base {
public:
	static int mA;
	static void func() {
		cout << "Son" << endl;
	}
};
int Son::mA = 200;

int main() {
	//静态成员变量
	//1.通过对象访问
	Son s;
	cout << s.mA << endl;
	cout << s.Base::mA << endl;
	//2.通过类名访问
	cout << Son::mA << endl;
	cout << Son::Base::mA << endl;

	//静态成员函数
    //1.通过对象访问
	s.func();
	s.Base::func();
	//2.通过类名访问
	Son::func();
	Son::Base::func();
	Son::Base::func(100);
}*/

/*#include <iostream>
using namespace std;
class Base1 {
public:
	int mA = 100;
};
class Base2 {
public:
	int mA = 200;
	int mB = 300;
};
class Son : public Base1, public Base2{
public:
	int mC = 400;
};
int main() {
	Son s;
	cout << sizeof(s) << endl;//12字节
	cout << s.Base1::mA << endl;
}*/

/*#include <iostream>
using namespace std;
class Animal {
public:
	int mAge;
};
//利用虚继承，解决数据有两份，资源浪费问题
//继承之前加关键字virtual
//Animal为虚基类
class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};
int main() {
	SheepTuo cnm;
	//菱形继承，两个父类有相同的数据，需要加作用域区分
	cnm.Sheep::mAge = 18;
	cnm.Tuo::mAge = 28;
	cout << cnm.Sheep::mAge << endl;//28
	cout << cnm.Tuo::mAge << endl;//28
	cout << cnm.mAge << endl;//28
}*/

/*#include <iostream>
using namespace std;
class Animal {
public:
	virtual void speak() {
		cout << "动物在说话" << endl;
	}
};
class Cat : public Animal {
public:
	//void speak() {
	//	cout << "小猫在说话" << endl;
	//}
};
class Dog : public Animal {
public:
	void speak() {
		cout << "小狗在说话" << endl;
	}
};
void doSpeak(Animal& animal) {
	animal.speak();
}
int main() {
	Cat cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);
}*/

/*#include <iostream>
using namespace std;
class Calculator {
public:
	virtual int getResult() {
		return 0;
	}
	int mA, mB;
};
class Add : public Calculator {
public:
	int getResult() {
		return mA + mB;
	}
};
class Sub : public Calculator {
public:
	int getResult() {
		return mA - mB;
	}
};
class Mul : public Calculator {
public:
	int getResult() {
		return mA * mB;
	}
};
void test1() {
	Calculator* cal;

	cal = new Add;
	cal->mA = 10;
	cal->mB = 10;
	cout << cal->getResult() << endl;
	delete cal;

	cal = new Sub;
	cal->mA = 10;
	cal->mB = 10;
	cout << cal->getResult() << endl;
	delete cal;

	cal = new Mul;
	cal->mA = 10;
	cal->mB = 10;
	cout << cal->getResult() << endl;
	delete cal;
}
void result(Calculator& cal) {
	cal.getResult();
}
void test2() {
	Calculator cal;
	cal.mA = 10;
	cal.mB = 10;

	Add add;
	result(add);
	cout << add.getResult() << endl;
}
int main() {
}*/

/*#include <iostream>
using namespace std;
class Base {
public:
	virtual void func() = 0;//类存在纯虚函数，此类成为抽象类
};
class Son : public Base 
{
public:
	void func() {
		cout << "func函数调用" << endl;
	}
};
int main() {
	//Base base;//抽象类无法实例化对象
	//Base* b = new Son;
	//b->func();

	Son s;//子类重写父类的虚函数，否则无法实例化对象
	Base& base = s;
	base.func();
}*/

