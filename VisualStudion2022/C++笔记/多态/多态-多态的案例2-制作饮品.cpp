# include <iostream>
using namespace std;

class MakeDrinking {
public:
	void Boilwater() {   //ÖóË®

		cout << "ÖóË®" << endl;
	}
	virtual void Brewing() = 0;  //³åÅİ

	void PourIn() {  //µ¹Èë±­ÖĞ

		cout << "µ¹Èë±­ÖĞ" << endl;
	}

	virtual void Seasonings() = 0;    //¼Ó¸¨ÁÏ
};

class Coffee : public MakeDrinking {

public:

	void Brewing() {
		
		cout << "³åÅİ¿§·È" << endl;
	}

	void Seasonings() {

		cout << "¼ÓÌÇºÍÅ£ÄÌ" << endl;
	}
};

class Tea : public MakeDrinking {

public:
	void Brewing() {

		cout << "³åÅİ²èÒ¶" << endl;
	}

	void Seasonings() {

		cout << "¼ÓÄûÃÊ" << endl;
	}
};

void Drinking(MakeDrinking * makedrinking) {

	makedrinking->Boilwater();
	makedrinking->Brewing();
	makedrinking->PourIn();
	makedrinking->Seasonings();
}

void test() {

	Drinking(new Tea);

	cout << "___________________" << endl;

	Drinking(new Coffee);

}

int main() {

	test();

	system("pause");

	return 0;
}