#include "boss.h"

// ���캯��
Boss::Boss(int id, string name, int depid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = depid;
}
// ��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ�𣺹���˾����������" << endl;
}
// ��ȡ��λ��Ϣ
string Boss::getDeptName()
{
	return string("�ϰ�");
}