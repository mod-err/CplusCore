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

#include <iostream>
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
}