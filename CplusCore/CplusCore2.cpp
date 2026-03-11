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

#include <iostream>
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

}