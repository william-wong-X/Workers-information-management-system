#include "manager.h"

// ���캯��
Manager::Manager(int id, string name, int depid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = depid;
}
// ��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ岼�õ����񣬰������������ְ��" << endl;
}
// ��ȡ��λ��Ϣ
string Manager::getDeptName()
{
	return string("����");
}