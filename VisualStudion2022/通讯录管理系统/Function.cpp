//菜单功能源文件
# include "Function.h"

void Function(int Choose, Person &Data) {

	switch (Choose) {

	case 1: //添加联系人
		Add(Data);
		break;
	case 2: //显示联系人
		Show(Data);
		break;
	case 3: //查找联系人
		Seek(Data);
		break;
	case 4: //删除联系人
		CutOut(Data);
		break;
	case 5: //修改联系人
		Alter(Data);
		break;
	case 6: // 清空联系人
		Empty(Data);
		break;
	default:
		return;
	}
}