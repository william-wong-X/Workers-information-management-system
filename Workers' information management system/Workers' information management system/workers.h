#pragma once
#include <iostream>
using namespace std;
#include <string>

// ְ��������
class Worker
{
public:

	// ��ʾ������Ϣ
	virtual void showInfo() = 0;
	// ��ȡ��λ��Ϣ
	virtual string getDeptName() = 0;

	// ְ�����
	int m_ID;
	// ְ������
	string m_Name;
	// ���ű��
	int m_DeptID;
};