// ��ְͨ���ļ�
#pragma once
#include <iostream>
using namespace std;
#include "workers.h"

class Employee :public Worker
{
public:

	// ���캯��
	Employee(int id, string name, int depid);
	// ��ʾ������Ϣ
	virtual void showInfo();
	// ��ȡ��λ��Ϣ
	virtual string getDeptName();

};
