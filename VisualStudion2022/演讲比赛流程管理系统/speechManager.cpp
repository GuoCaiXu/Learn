# include "speechManager.h"

//构造函数
SpeechManager::SpeechManager() {

	//初始化属性
	this->initSpeech();

	//创建选手
	this->createSpeaker();

	//获取往届记录
	this->loadRecord();
}

//析构函数
SpeechManager::~SpeechManager() {


}

//菜单功能
void SpeechManager::show_Menu() {

	cout << "****************************************************************" << endl;
	cout << "*************************欢迎参加演讲比赛***********************" << endl;
	cout << "*************************1. 开始演讲比赛***********************" << endl;
	cout << "*************************2. 查看往届记录************************" << endl;
	cout << "*************************3. 清空比赛记录************************" << endl;
	cout << "*************************0. 退出比赛程序************************" << endl;
	cout << "****************************************************************" << endl;
}

//退出功能
void SpeechManager::exitsYstem(){

	cout << "欢迎下次使用!" << endl;

	system("pause");
	exit(0);
}

//初始化属性
void SpeechManager::initSpeech() {

	//容器保证为空
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	//初始化比赛轮数
	this->m_Index = 1;

	 //将记录的容器 也清空
	this->m_Record.clear();
}

//创建选手
void SpeechManager::createSpeaker() {

	string nameSpace = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSpace.size(); i++) {

		string name = "选手";
		name += nameSpace[i];

		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++) {
			sp.m_Score[j] = 0;
		}

		//12名选手编号
		this->v1.push_back(i + 1000);

		//选手编号 以及对应选手 存放到map容器中
		this->m_Speaker.insert(make_pair(i + 1000, sp));
	}
}

//开始比赛
void SpeechManager::startSpeech() {

	//第一轮比赛
	//1. 抽签
	this->speechDraw();

	//2. 比赛
	speechContest();

	//3. 显示晋级结果
	showScore();

	//第二轮比赛
	this->m_Index++;

	//1. 抽签
	this->speechDraw();

	//2. 比赛
	speechContest();

	//3. 显示最终结果
	showScore();

	//4. 保存分数
	saverScore();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
	//初始化容器和属性
	this->initSpeech();

	//创建选手
	this->createSpeaker();

	//加载往届记录
	this->loadRecord();
}

//抽签
void SpeechManager::speechDraw() {

	srand((unsigned int)time(NULL));
	cout << "第 <<" << this->m_Index << ">> 轮比赛选手正在抽签" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "抽签后演讲顺序如下:" << endl;
	if (this->m_Index == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++) {

			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++) {

			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------------------------------" << endl;
	system("pause");
}

//比赛
void SpeechManager::speechContest() {

	cout << "--------第" << this->m_Index << "轮比赛正式开始--------" << endl;

	//准备临时容器 存放小组成绩
	multimap<double, int, greater<double>>groupScore;

	int num = 0; //记录人员个数

	vector<int>v_Src; //比赛选手容器
	if (this->m_Index == 1) {

		v_Src = v1;
	}
	else {

		v_Src = v2;
	}

	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {

		num++;

		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++) {

			double score = (rand() % 401 + 600) / 10.f; //600 ~ 1000
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>()); //排序

		d.pop_front(); //去除最高分
		d.pop_back();  //去除最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f); //总分
		double avg = sum / (double)d.size(); //平均分

		//将平均分放到 map容器里面
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//将打分数据 放入到临时小组容器中
		groupScore.insert(make_pair(avg, *it));  //key是得分， value是具体选手编号

		//每6人取前三名
		if (num % 6 == 0) {

			cout << "第" << num / 6 << "小组比赛名次:" << endl;
			for (multimap<double, int, greater<double>>::iterator pos1 = groupScore.begin(); pos1 != groupScore.end(); pos1++) {

				cout << "编号:" << pos1->second << " 姓名:" << this->m_Speaker[pos1->second].m_Name << " 年龄:" << this->m_Speaker[pos1->second].m_Score[this->m_Index - 1] << endl;
			}

			//取走前三名 
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator pos2 = groupScore.begin(); pos2 != groupScore.end() && count < 3; pos2++, count++) {

				if (this->m_Index == 1) {
					v2.push_back((*pos2).second);
				}
				else {
					v3.push_back((*pos2).second);
				}
			}

			groupScore.clear(); //小组容器清空
			cout << endl;
		}
	}

	cout << "--------第" << this->m_Index << "轮比赛完毕--------" << endl;
	system("pause");
}

//显示晋级选手信息
void SpeechManager::showScore() {

	cout << "--------第" << this->m_Index << "轮晋级选手信息如下：--------" << endl;
	vector<int>v;
	if (this->m_Index == 1) {

		v = v2;
	}
	else {
		v = v3;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {

		cout << "选手编号：" << *it << "  姓名：" << this->m_Speaker[*it].m_Name << "  得分：" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	cout << endl;
}

//保存分数
void SpeechManager::saverScore() {

	ofstream ofs(FILENAME, ios::out | ios::app);  //用输出的方式打开文件 -- 写文件

	//将每个数据写入到文件中
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++) {

		ofs << *it << ',' << this->m_Speaker[*it].m_Score[1] << ',';
	}
	ofs << endl;

	//关闭文件
	ofs.close();

	cout << "记录已经保存" << endl;
	this->fileIsEmpty = false;
	cout << endl;
	system("pause");
	system("cls");
}

//读取记录分数
void SpeechManager::loadRecord() {

	ifstream ifs(FILENAME, ios::in);

	{
		if (!ifs.is_open()) {

			this->fileIsEmpty = true;
			ifs.close();
			return;
		}
		
		//文件清空情况
		char ch;
		ifs >> ch;
		if (ifs.eof()) {

			this->fileIsEmpty = true;
			ifs.close();
			return;
		}

		//文件不为空
		this->fileIsEmpty = false;

		ifs.putback(ch);

		string data;
		int index = 0;  //表示第几届

		while (ifs >> data) {


			vector<string>v;  //存放6个string字符串

			int pos = -1; //查到","位置的变量
			int start = 0;

			while (true) {
				pos = data.find(',', start);  //找到"，"的位置

				if (pos == -1) {
					//没有找到情况
					break;
				}
				string temp = data.substr(start, pos - start);

				v.push_back(temp);

				start = pos + 1;
			}

			this->m_Record.insert(make_pair(index, v));
			index++;
		}
	}
	ifs.close();
}

//查看往届记录
void SpeechManager::showRecord() {

	loadRecord();

	if (this->fileIsEmpty) {
		cout << "往届无记录!" << endl;
	}
	else{

	for (int i = 0; i < this->m_Record.size(); i++) {

		cout << "第" << i + 1 << "届" <<
			"冠军编号:" << this->m_Record[i][0] << " 得分:" << this->m_Record[i][1] << "  "
			"亚军编号:" << this->m_Record[i][2] << " 得分:" << this->m_Record[i][3] << "  "
			"季军编号:" << this->m_Record[i][4] << " 得分:" << this->m_Record[i][5] << " "
			<< endl;
	}
	}
	cout << endl;

	system("pause");
	system("cls");
}

//清空记录功能
void SpeechManager::clearRecord() {

	cout << "确认清空？" << endl;
	cout << "1. 确认" << endl;
	cout << "2. 返回" << endl;

	int choise;
	cin >> choise;

	if (choise == 1) {

		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		this->initSpeech();

		this->createSpeaker();

		this->loadRecord();

		this->fileIsEmpty = true;

		cout << "清空成功!" << endl;
		system("pause");
		system("cls");
	}
}