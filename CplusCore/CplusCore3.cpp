/*#include <iostream>
using namespace std;
class Drinking {
public:
	virtual void boil() = 0;
	virtual void brew() = 0;
	virtual void pourincup() = 0;
	virtual void putsomething() = 0;
	void makeDrink() {
		boil();
		brew();
		pourincup();
		putsomething();
	}
};
class Coffee : public Drinking{
public:
	void boil() {
		cout << "煮水" << endl;
	}
	void brew() {
		cout << "冲泡咖啡" << endl;
	}
	void pourincup() {
		cout << "倒入杯子" << endl;
	}
	void putsomething() {
		cout << "加入糖和牛奶" << endl;
	}
};
void doWork(Drinking* drink) {//Drinking* drink = new Coffee;
	drink->makeDrink();
	delete drink;
}
void doWork(Drinking& drink) {
	drink.makeDrink();
}
int main() {
	Coffee c;
	doWork(&c);
	doWork(new Coffee);

	doWork(c);
}*/

/*#include <iostream>
#include <string>
using namespace std;
class Animal {
public:
	virtual void speak() = 0;//纯虚函数
	Animal() {
		cout << "Animal默认构造函数" << endl;
	}
	//虚析构
	virtual ~Animal() {
		cout << "Animal析构函数" << endl;
	}
	//纯虚析构：类内声明，类外初始化
	virtual ~Animal() = 0;
};
Animal::~Animal() {
	cout << "Animal纯析构函数" << endl;
}
class Cat : public Animal {
public:
	Cat(string name) {
		mName = new string(name);
		cout << "Cat有参构造函数" << endl;
	}
	~Cat() {
		if (mName != NULL) {
			delete mName;
			mName = NULL;
		}
		cout << "Cat析构函数" << endl;
	}
	void speak() {
		cout << "小猫在说话" << endl;
	}
	string* mName;
};

int main() {
	//父类指针在析构的时候，不会调用子类中的析构函数，导致子类堆区的数据无法释放
	Animal* animal = new Cat("Tom");
	animal->speak();
	delete animal;
}*/

/*#include <iostream>
using namespace std;
//电脑零件大类
class CPU {
public:
	//计算操作
	virtual void calculate() = 0;//纯虚函数
};
class VideoCard {
public:
	//显示操作
	virtual void display() = 0;//纯虚函数
};
class Memory {
public:
	//存储操作
	virtual void storage() = 0;//纯虚函数
};
//生产厂商大类
//Intel
class IntelCpu : public CPU {
public:
	void calculate() {
		cout << "Inter厂商CPU开始计算！" << endl;
	}
};
class IntelVideoCard : public VideoCard {
public:
	void display() {
		cout << "Inter厂商VideoCard开始显示！" << endl;
	}
};
class IntelMemory : public Memory {
public:
	void storage() {
		cout << "Inter厂商IntelMemory开始存储！" << endl;
	}
};
//Lenovo
class LenovoCpu : public CPU {
public:
	void calculate() {
		cout << "Lenovo厂商CPU开始计算！" << endl;
	}
};
class LenovoVideoCard : public VideoCard {
public:
	void display() {
		cout << "Lenovo厂商VideoCard开始显示！" << endl;
	}
};
class LenovoMemory : public Memory {
public:
	void storage() {
		cout << "Lenovo厂商VideoCard开始存储！" << endl;
	}
};
//电脑类
class Computer {
public:
	Computer(CPU* c, VideoCard* v, Memory* m) : cpu(c), vc(v), mem(m){}
	void dowork() {
		cpu->calculate();
		vc->display();
		mem->storage();
	}
	~Computer() {
		if (cpu != NULL) {
			delete cpu;
			cpu = NULL;
		}
		if (vc != NULL) {
			delete vc;
			vc = NULL;
		}
		if (mem != NULL) {
			delete mem;
			mem = NULL;
		}
	}
private:
	CPU* cpu;
	VideoCard* vc;
	Memory* mem;
};
int main() {
	//生产零件
	CPU* intelCpu = new IntelCpu;
	VideoCard* intelVideoCard = new IntelVideoCard;
	Memory* intelMemory = new IntelMemory;
	//第一台电脑
	Computer* c1 = new Computer(intelCpu, intelVideoCard, intelMemory);
	c1->dowork();
	delete c1;//调用Computer的析构函数，释放三个零件
	//第二台电脑
	Computer* c2 = new Computer(new LenovoCpu, new LenovoVideoCard, new LenovoMemory);
	c2->dowork();
	delete c2;
}*/

/*#include <iostream>
#include <fstream>
using namespace std;
int main() {
	//（1）包含头文件：#include <fstream>
	//（2）创建流对象：ofstream ofs;
	ofstream ofs;
	//（3）打开文件：ofs.open("文件路径", "打开方式");
	ofs.open("text.txt", ios::out);
	//（4）写数据：ofs << "写入的数据";
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;
	//（5）关闭文件：ofs.close();
	ofs.close();
}*/

/*#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	//（1）包含头文件：#include <fstream>
	//（2）创建流对象：ifstream ifs;
	ifstream ifs;
	//（3）打开文件并判断文件是否打开成功：ifs.open("文件路径", "打开方式");
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return 0;
	}
	//（4）读数据：四种方式
	//第一种：
	//char buff[1024] = {0};
	//while (ifs >> buff) {// ifs >> buff 执行后，会返回ifs对象本身，while会判断该流对象的状态：
	//	cout << buff << endl;
	//}
	//第二种：
	//char buff[1024] = { 0 };
	//while (ifs.getline(buff, sizeof(buff))) {
	//	cout << buff << endl;
	//}
	//第三种：
	//string buff;
	//while (getline(ifs, buff)) {
	//	cout << buff << endl;
	//}
	//第四种：
	char c;
	while ( (c = ifs.get()) != EOF ) { //EOF:end of file
		cout << c;
	}
	//（5）关闭文件：ifs.close();
	ifs.close();
}*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
public:
	Person() { }
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

int main() {
	Person p("张三", 18);
	ofstream ofs;
	ofs.open("text1.txt", ios::out | ios::binary);
	ofs.write((const char*)&p, sizeof(p));
	ofs.close();

	Person p1;
	ifstream ifs;
	ifs.open("text1.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return 0;
	}
	ifs.read((char*)&p1, sizeof(p1));
	cout << p1.name << " " << p1.age << endl;
	ifs.close();
}
