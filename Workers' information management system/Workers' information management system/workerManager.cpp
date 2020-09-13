#include "workerManager.h"

workerManager::workerManager()
{
	// 1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		// 初始化属性
		// 初始化记录人数
		this->m_EmpNum = 0;
		// 初始化数组指针
		this->m_EmpArray = NULL;
		// 初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	// 2、文件存在但数据为空
	char ch;
	ifs >> ch;	// 读取一个字符
	if (ifs.eof())	// 使用eof函数判断是否文件为空
	{
		cout << "文件为空" << endl;
		// 初始化属性
		// 初始化记录人数
		this->m_EmpNum = 0;
		// 初始化数组指针
		this->m_EmpArray = NULL;
		// 初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	// 3、文件存在而且有数据
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	// 开辟空间
	this->m_EmpArray = new Worker *[this->m_EmpNum];
	// 将文件中的数据读取到数组中
	this->init_Emp();

}

// 展示下单
void workerManager::show_Menu()
{
	cout << "********************************************************" << endl;
	cout << "********************************************************" << endl;
	cout << "********          欢迎使用职工管理系统          ********" << endl;
	cout << "********          0、退出职工管理系统           ********" << endl;
	cout << "********            1、增加职工信息             ********" << endl;
	cout << "********            2、显示职工信息             ********" << endl;
	cout << "********            3、删除离职职工             ********" << endl;
	cout << "********            4、修改职工信息             ********" << endl;
	cout << "********            5、查找职工信息             ********" << endl;
	cout << "********            6、按照编号排序             ********" << endl;
	cout << "********            7、清空所有列表             ********" << endl;
	cout << "********************************************************" << endl;
	cout << "********************************************************" << endl;
	cout << endl;
}

// 退出系统
void workerManager::exit_System()
{
	cout << "**********欢迎下次使用**********" << endl;
	system("pause");
	exit(0);	//退出程序
}

// 添加职工
void workerManager::add_Emp()
{
	int addNum = 0;	// 保存用户输入的数量
	cout << "请输入添加职工的数量：" << endl;
	cin >> addNum;

	if (addNum > 0)
	{
		// 添加
		// 计算添加后新空间的大小
		int newSize = this->m_EmpNum + addNum;

		// 开辟新空间
		Worker **newSpace = new Worker *[newSize];
		// 将原来空间下的数据拷贝至新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		// 批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;	//职工编号
			string name;	// 职工姓名
			int dSelect;	// 部门选择

			cout << "请输入第" << i + 1 << "个新职工的编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker *worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			// 将创建好的职工指针worker保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		// 释放原来的空间
		delete[] this->m_EmpArray;

		// 更改新空间的指向
		this->m_EmpArray = newSpace;

		// 更新职工的人数
		this->m_EmpNum = newSize;

		// 成功添加后，保存到文件中
		this->save();

		// 跟新文件是否为空的标志
		this->m_FileIsEmpty = false;

		// 提示添加成功
		cout << "成功添加了" << addNum << "名新职工" << endl;
	}
	else
	{
		cout << "输入数据有误！！！" << endl;
	}

	// 按任意键后清屏
	system("pause");
	system("cls");
}

// 保存文件
void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	// 用输出的方式打开文件（写文件）

	// 将每个人的数据写入文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
}

// 统计文件中的人数
int workerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	// 打开文件（读文件）

	int id;
	string name;
	int dId;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;	// 统计人数的变量
	}
	return num;
}

// 初始化职工
void workerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;	// 默认索引位置
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker *worker = NULL;

		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

// 显示职工
void workerManager::show_Emp()
{
	// 判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			// 利用多态调用函数接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	// 按任意键后清屏
	system("pause");
	system("cls");
}

// 判断职工是否存在，存在返回职工序号，不存在返回-1
int workerManager::isExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			// 找到职工
			index = i;
			break;
		}
	}
	return index;

}

// 删除职工
void workerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者数据为空" << endl;
	}
	else
	{
		// 按照职工编号删除职工
		cout << "请输入你想删除的职工编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			// 更新数组中记录的人员个数
			this->m_EmpNum--;
			// 数据同步更新到文件中
			this->save();

			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	// 按任意键后清屏
	system("pause");
	system("cls");
}

// 修改职工
void workerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者数据为空" << endl;
	}
	else
	{
		cout << "请输入需要修改的职工编号" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			// 找到该职工
			delete this->m_EmpArray[ret];
			int newID = 0;
			string newName = "";
			int newSelect = 0;

			cout << "查找到" << id << "号的职工，请输入新的职工号：" << endl;
			cin >> newID;
			cout << "请输入新的姓名" << endl;
			cin >> newName;
			cout << "请输入新的职位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> newSelect;

			Worker *worker = NULL;
			switch (newSelect)
			{
			case 1:
				worker = new Employee(newID, newName, newSelect);
				break;
			case 2:
				worker = new Manager(newID, newName, newSelect);
				break;
			case 3:
				worker = new Boss(newID, newName, newSelect);
				break;
			default:
				break;
			}
			// 更新到数组中
			this->m_EmpArray[ret] = worker;

			// 更新到文件中
			this->save();
			cout << "已修改完成" << endl;

		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	// 按任意键后清屏
	system("pause");
	system("cls");
}

// 查找职工
void workerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者数据为空" << endl;
	}
	else
	{
		cout << "请选择查找的方式：" << endl;
		cout << "1、按照职工编号查找" << endl;
		cout << "2、按照职工姓名查找" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			// 按照编号查
			int id = 0;
			cout << "请输入要查找的职工编号：" << endl;
			cin >> id;

			int ret = this->isExist(id);
			if (ret != -1)
			{
				// 找到职工
				cout << "查找成功！该职工的信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if (select == 2)
		{
			// 按姓名查
			string name = "";
			cout << "请输入要查找的职工姓名" << endl;
			cin >> name;

			// 判断是否查找的标志
			bool flag = false;

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为：" << this->m_EmpArray[i]->m_ID << "号职工信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else
		{
			cout << "输入的选项有误" << endl;
		}
	}
	// 按任意键后清屏
	system("pause");
	system("cls");
}

// 排序职工
void workerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者数据为空" << endl;
	}
	else
	{
		cout << "请选择排序的方式：" << endl;
		cout << "1、按照升序进行排序" << endl;
		cout << "2、按照降序进行排序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			// 声明最大值最小值的下标
			int minOrMax = i;
			for (int j = 0; j < this->m_EmpNum; j++)
			{
				if (select == 1)	// 升序
				{
					if (this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
				else  // 降序
				{
					if (this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
			}
			// 判断一开始的值是不是最大或最小值，如不是就交换
			if (i != minOrMax)
			{
				Worker *temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
			
		}
	}
	cout << "排序成功！排序后的结果为：" << endl;
	this->save();	// 同步到文件中
	this->show_Emp();
}

// 清空文件数据
void workerManager::clean_File()
{
	cout << "是否清空列表？（y/n）：" << endl;
	char select = 'n';
	cin >> select;
	if (select == 'y')
	{
		// 清空文件
		ofstream ofs(FILENAME, ios::trunc);	// trunc是删除文件后重新创建（等于清空）
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] == NULL;
				}
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	// 按任意键后清屏
	system("pause");
	system("cls");
}

workerManager::~workerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] == NULL;
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}