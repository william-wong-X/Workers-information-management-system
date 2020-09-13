#pragma once	// ��ֹͷ�ļ��ظ�����
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
	// ���캯��
	workerManager();

	// չʾ�˵�
	void show_Menu();

	// �˳�ϵͳ
	void exit_System();

	// ��¼ְ������
	int m_EmpNum;
	// ְ������ָ��
	Worker **m_EmpArray;

	// ���ְ��
	void add_Emp();

	// �����ļ�
	void save();

	// �ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	// ͳ���ļ��е�����
	int get_EmpNum();

	// ��ʼ��ְ��
	void init_Emp();

	// ��ʾְ��
	void show_Emp();

	// �ж�ְ���Ƿ���ڣ����ڷ���ְ����ţ������ڷ���-1
	int isExist(int id);

	// ɾ��ְ��
	void del_Emp();

	// �޸�ְ��
	void mod_Emp();

	// ����ְ��
	void find_Emp();

	// ����ְ��
	void sort_Emp();

	// ����ļ�����
	void clean_File();

	// ��������
	~workerManager();
	
};
