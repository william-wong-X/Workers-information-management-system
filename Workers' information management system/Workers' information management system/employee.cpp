#include "employee.h"

// ���캯��
Employee::Employee(int id, string name, int depid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = depid;
}

// ��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϼ�����������" << endl;
}

// ��ȡ��λ��Ϣ
string Employee::getDeptName()
{
	return string("ְ��");
}
