#include "employee.h"

// 构造函数
Employee::Employee(int id, string name, int depid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = depid;
}

// 显示个人信息
void Employee::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成上级交代的任务" << endl;
}

// 获取岗位信息
string Employee::getDeptName()
{
	return string("职工");
}
