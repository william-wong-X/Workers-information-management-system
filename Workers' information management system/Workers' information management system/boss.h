// 老板的文件
#pragma once
#include <iostream>
using namespace std;
#include "workers.h"

class Boss :public Worker
{
public:

	// 构造函数
	Boss(int id, string name, int depid);
	// 显示个人信息
	virtual void showInfo();
	// 获取岗位信息
	virtual string getDeptName();
};
