// �ϰ���ļ�
#pragma once
#include <iostream>
using namespace std;
#include "workers.h"

class Boss :public Worker
{
public:

	// ���캯��
	Boss(int id, string name, int depid);
	// ��ʾ������Ϣ
	virtual void showInfo();
	// ��ȡ��λ��Ϣ
	virtual string getDeptName();
};
