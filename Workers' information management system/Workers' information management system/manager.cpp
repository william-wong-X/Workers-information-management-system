#include "manager.h"

// 构造函数
Manager::Manager(int id, string name, int depid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = depid;
}
// 显示个人信息
void Manager::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成老板布置的任务，把任务合理分配给职工" << endl;
}
// 获取岗位信息
string Manager::getDeptName()
{
	return string("经理");
}