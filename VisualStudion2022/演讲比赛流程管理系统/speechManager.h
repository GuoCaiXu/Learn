#pragma once
# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
# include <ctime>
# include <deque>
# include <functional>
# include <numeric>
# include <string>
# include <fstream>
# define FILENAME "speech.csv"
# include "speaker.h"
using namespace std;

class SpeechManager {

public:
	//构造函数
	SpeechManager();

	//析构函数
	~SpeechManager();

	//展示菜单
	void show_Menu();

	//退出功能
	void exitsYstem();

	//初始化属性
	void initSpeech();

	//创建选手
	void createSpeaker();

	//比赛选手容器  12人
	vector<int>v1;

	//第一轮晋级容器  6人
	vector<int>v2;

	//胜利前三名容器  3人
	vector<int>v3;

	//存放编号 以及对应的 具体选手 容器
	map<int, Speaker>m_Speaker;

	//记录比赛轮数
	int m_Index;

	//开始比赛
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示晋级选手信息
	void showScore();

	//保存分数
	void saverScore();

	//读取记录分数
	void loadRecord();

	//文件为空标志
	bool fileIsEmpty;

	//存放往届记录的容器
	map<int, vector<string>>m_Record;

	//查看往届记录
	void showRecord();

	//清空记录功能
	void clearRecord();
};