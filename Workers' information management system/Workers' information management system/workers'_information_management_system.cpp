#include <iostream>
using namespace std;
#include "workerManager.h"

int main()
{
	// ʵ���������ߵĶ���
	workerManager worker_manager;
	int choice = 0;	//�����û�ѡ��

	while (true)
	{
		//����չʾ�˵��ĳ�Ա����
		worker_manager.show_Menu();
		cout << "������������Ĺ��ܵ���ţ�" << endl;
		cin >> choice;	//�����û�ѡ��
		switch (choice)
		{
		case 0:	// �˳�ϵͳ
			worker_manager.exit_System();
			break;
		case 1:	// ����ְ��
			worker_manager.add_Emp();
			break;
		case 2:	// ��ʾְ��
			worker_manager.show_Emp();
			break;
		case 3:	// ɾ��ְ��
			worker_manager.del_Emp();
			break;
		case 4:	// �޸�ְ��
			worker_manager.mod_Emp();
			break;
		case 5:	// ����ְ��
			worker_manager.find_Emp();
			break;
		case 6:	// ����ְ��
			worker_manager.sort_Emp();
			break;
		case 7:	// ����б�
			worker_manager.clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}