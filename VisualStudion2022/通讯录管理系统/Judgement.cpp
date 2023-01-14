//判断函数源文件
# include "Judgement.h"

int Judgement(Person& Data, string name) {

	int i;

	for(i = 0; i < Data.Quantity; i++) {

		if (name == Data.Data[i].name) {

			return i;
		}
	}
	return -1;
}
