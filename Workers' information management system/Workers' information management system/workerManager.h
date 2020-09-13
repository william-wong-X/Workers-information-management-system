#pragma once	// 防止头文件重复包含
#include <iostream>
using namespace std;
#include <fstream>
#define FILENAME "empFile.txt"
#include "workers.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

class workerManager
{
public:
	// 构造函数
	workerManager();

	// 展示菜单
	void show_Menu();

	// 退出系统
	void exit_System();

	// 记录职工人数
	int m_EmpNum;
	// 职工数组指针
	Worker **m_EmpArray;

	// 添加职工
	void add_Emp();

	// 保存文件
	void save();

	// 判断文件是否为空
	bool m_FileIsEmpty;

	// 统计文件中的人数
	int get_EmpNum();

	// 初始化职工
	void init_Emp();

	// 显示职工
	void show_Emp();

	// 判断职工是否存在，存在返回职工序号，不存在返回-1
	int isExist(int id);

	// 删除职工
	void del_Emp();

	// 修改职工
	void mod_Emp();

	// 查找职工
	void find_Emp();

	// 排序职工
	void sort_Emp();

	// 清空文件数据
	void clean_File();

	// 析构函数
	~workerManager();
	
};
