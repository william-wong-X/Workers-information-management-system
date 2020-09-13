#include "boss.h"

// 构造函数
Boss::Boss(int id, string name, int depid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = depid;
}
// 显示个人信息
void Boss::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：管理公司的所有事物" << endl;
}
// 获取岗位信息
string Boss::getDeptName()
{
	return string("老板");
}