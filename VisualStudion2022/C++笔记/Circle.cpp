# include <iostream>
using namespace std;

//点
class Spot {

private:
	int X;
	int Y;

public:
	//X
	void  setX(int x) {

		X = x;
	  }
	int gitX() {
		return X;
	}

	//Y
	void setY(int y) {

		Y = y;
	}
	int gitY() {

		return Y;
	}
};

//圆
class Circle {

private:
	int R;
	Spot H;

public:
	void setR(int r) {

		R = r;
	}
	int gitR() {

		return R;
	}
	void setHeat(Spot h) {

		H = h;
	}

	Spot gitHeat() {

		return H;
	}
};

//判断点和圆的关系
void Judgement(Circle C, Spot P) {

	int i =
		(C.gitHeat().gitX() - P.gitX()) * (C.gitHeat().gitX() - P.gitX()) +
		(C.gitHeat().gitY() - P.gitY()) * (C.gitHeat().gitY() - P.gitY());

	int r = C.gitR() * C.gitR();

	if (i = r) {
		cout << "点在圆上" << endl;
	}
	else if (i < r) {

		cout << "点在圆内" << endl;
	}
	else {
		cout << "点在圆外" << endl;
	}
}

int main() {

	Circle C;
	Spot p;
	int a, b, r, x, y;

	cout << "请输入圆的值：" << endl;
	cout << "半径：";
	cin >> r;
	cout << "圆心a:";
	cin >> a;
	cout << "圆心b:";
	cin >> b;

	C.setR(r);
	p.setX(a);
	p.setY(b);
	C.setHeat(p);

	cout << "请输入点的值:" << endl;

		cout << "点X:";
	    cin >> x;
	    cout << "点Y:";
	    cin >> y;

		Spot P;
		P.setX(x);
		P.setY(y);

		Judgement(C, P);

	system("pause");

	return 0;
}