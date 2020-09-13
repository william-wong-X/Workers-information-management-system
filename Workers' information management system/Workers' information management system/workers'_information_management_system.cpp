#include <iostream>
using namespace std;
#include "workerManager.h"

int main()
{
	// 实例化管理者的对象
	workerManager worker_manager;
	int choice = 0;	//储存用户选项

	while (true)
	{
		//调用展示菜单的成员函数
		worker_manager.show_Menu();
		cout << "请输入您所需的功能的序号：" << endl;
		cin >> choice;	//接搜用户选择
		switch (choice)
		{
		case 0:	// 退出系统
			worker_manager.exit_System();
			break;
		case 1:	// 增加职工
			worker_manager.add_Emp();
			break;
		case 2:	// 显示职工
			worker_manager.show_Emp();
			break;
		case 3:	// 删除职工
			worker_manager.del_Emp();
			break;
		case 4:	// 修改职工
			worker_manager.mod_Emp();
			break;
		case 5:	// 查找职工
			worker_manager.find_Emp();
			break;
		case 6:	// 排序职工
			worker_manager.sort_Emp();
			break;
		case 7:	// 清空列表
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