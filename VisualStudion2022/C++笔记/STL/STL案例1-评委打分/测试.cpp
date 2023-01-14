# include <iostream>
using namespace std;
# include <ctime>

int main() {

	srand((int)time(0));
	cout << rand() % 100 << endl;

	system("Pause");

	return 0;
}