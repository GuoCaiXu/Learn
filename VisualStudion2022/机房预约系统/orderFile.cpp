# include "orderFile.h"

//构造函数
OrderFile::OrderFile() {

	ifstream ifs(ORDER_FILE);
	
	string date; //日期
	string interval; //时间段
	string stuId; //学生编号
	string stuName; //学生姓名
	string roomId; //机房编号
	string status; //预约状态

	this->m_Size = 0; //预约记录个数

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {

		string key;
		string value;
		map<string, string>m;

		//date:111
		//截取时间
		int pos = date.find(":"); // 4
		if (pos != -1) {

			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1); // size() = 8   pos = 4  size - pos - 1 = 3

			m.insert(make_pair(key, value));
		}

		//截取时间段
		pos = interval.find(":"); // 4
		if (pos != -1) {

			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		//截取学生编号
		pos = stuId.find(":"); // 4
		if (pos != -1) {

			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		//截取学生姓名
		pos = stuName.find(":"); // 4
		if (pos != -1) {

			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1); 

			m.insert(make_pair(key, value));
		}

		//截取机房编号
		pos = roomId.find(":"); // 4
		if (pos != -1) {

			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1); 

			m.insert(make_pair(key, value));
		}

		//截取审核状态
		pos = status.find(":"); // 4
		if (pos != -1) {

			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1); 

			m.insert(make_pair(key, value));
		}

		//将小map容器放入到大的map容器
		this->m_orderDate.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}

	ifs.close();
}

//更新预约记录
void OrderFile::updateOrder() {

	if (this->m_Size == 0) {

		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++) {

		ofs << "时间:" << this->m_orderDate[i]["时间"] << " ";
		ofs << "时间段:" << this->m_orderDate[i]["时间段"] << " ";
		ofs << "学生编号:" << this->m_orderDate[i]["学生编号"] << " ";
		ofs << "学生姓名:" << this->m_orderDate[i]["学生姓名"] << " ";
		ofs << "机房编号:" << this->m_orderDate[i]["机房编号"] << " ";
		ofs << "审核状态:" << this->m_orderDate[i]["审核状态"] << " ";
	}

	ofs.close();
}