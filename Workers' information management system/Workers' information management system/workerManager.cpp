#include "workerManager.h"

workerManager::workerManager()
{
	// 1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		// ��ʼ������
		// ��ʼ����¼����
		this->m_EmpNum = 0;
		// ��ʼ������ָ��
		this->m_EmpArray = NULL;
		// ��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	// 2���ļ����ڵ�����Ϊ��
	char ch;
	ifs >> ch;	// ��ȡһ���ַ�
	if (ifs.eof())	// ʹ��eof�����ж��Ƿ��ļ�Ϊ��
	{
		cout << "�ļ�Ϊ��" << endl;
		// ��ʼ������
		// ��ʼ����¼����
		this->m_EmpNum = 0;
		// ��ʼ������ָ��
		this->m_EmpArray = NULL;
		// ��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	// 3���ļ����ڶ���������
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	// ���ٿռ�
	this->m_EmpArray = new Worker *[this->m_EmpNum];
	// ���ļ��е����ݶ�ȡ��������
	this->init_Emp();

}

// չʾ�µ�
void workerManager::show_Menu()
{
	cout << "********************************************************" << endl;
	cout << "********************************************************" << endl;
	cout << "********          ��ӭʹ��ְ������ϵͳ          ********" << endl;
	cout << "********          0���˳�ְ������ϵͳ           ********" << endl;
	cout << "********            1������ְ����Ϣ             ********" << endl;
	cout << "********            2����ʾְ����Ϣ             ********" << endl;
	cout << "********            3��ɾ����ְְ��             ********" << endl;
	cout << "********            4���޸�ְ����Ϣ             ********" << endl;
	cout << "********            5������ְ����Ϣ             ********" << endl;
	cout << "********            6�����ձ������             ********" << endl;
	cout << "********            7����������б�             ********" << endl;
	cout << "********************************************************" << endl;
	cout << "********************************************************" << endl;
	cout << endl;
}

// �˳�ϵͳ
void workerManager::exit_System()
{
	cout << "**********��ӭ�´�ʹ��**********" << endl;
	system("pause");
	exit(0);	//�˳�����
}

// ���ְ��
void workerManager::add_Emp()
{
	int addNum = 0;	// �����û����������
	cout << "���������ְ����������" << endl;
	cin >> addNum;

	if (addNum > 0)
	{
		// ���
		// ������Ӻ��¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum;

		// �����¿ռ�
		Worker **newSpace = new Worker *[newSize];
		// ��ԭ���ռ��µ����ݿ������¿ռ�
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		// �������������
		for (int i = 0; i < addNum; i++)
		{
			int id;	//ְ�����
			string name;	// ְ������
			int dSelect;	// ����ѡ��

			cout << "�������" << i + 1 << "����ְ���ı�ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ����������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			// �������õ�ְ��ָ��worker���浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		// �ͷ�ԭ���Ŀռ�
		delete[] this->m_EmpArray;

		// �����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		// ����ְ��������
		this->m_EmpNum = newSize;

		// �ɹ���Ӻ󣬱��浽�ļ���
		this->save();

		// �����ļ��Ƿ�Ϊ�յı�־
		this->m_FileIsEmpty = false;

		// ��ʾ��ӳɹ�
		cout << "�ɹ������" << addNum << "����ְ��" << endl;
	}
	else
	{
		cout << "�����������󣡣���" << endl;
	}

	// �������������
	system("pause");
	system("cls");
}

// �����ļ�
void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	// ������ķ�ʽ���ļ���д�ļ���

	// ��ÿ���˵�����д���ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
}

// ͳ���ļ��е�����
int workerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	// ���ļ������ļ���

	int id;
	string name;
	int dId;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;	// ͳ�������ı���
	}
	return num;
}

// ��ʼ��ְ��
void workerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;	// Ĭ������λ��
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

// ��ʾְ��
void workerManager::show_Emp()
{
	// �ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			// ���ö�̬���ú����ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	// �������������
	system("pause");
	system("cls");
}

// �ж�ְ���Ƿ���ڣ����ڷ���ְ����ţ������ڷ���-1
int workerManager::isExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			// �ҵ�ְ��
			index = i;
			break;
		}
	}
	return index;

}

// ɾ��ְ��
void workerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�������Ϊ��" << endl;
	}
	else
	{
		// ����ְ�����ɾ��ְ��
		cout << "����������ɾ����ְ����ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			// ���������м�¼����Ա����
			this->m_EmpNum--;
			// ����ͬ�����µ��ļ���
			this->save();

			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	// �������������
	system("pause");
	system("cls");
}

// �޸�ְ��
void workerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�������Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ�ְ�����" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			// �ҵ���ְ��
			delete this->m_EmpArray[ret];
			int newID = 0;
			string newName = "";
			int newSelect = 0;

			cout << "���ҵ�" << id << "�ŵ�ְ�����������µ�ְ���ţ�" << endl;
			cin >> newID;
			cout << "�������µ�����" << endl;
			cin >> newName;
			cout << "�������µ�ְλ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			// ���µ�������
			this->m_EmpArray[ret] = worker;

			// ���µ��ļ���
			this->save();
			cout << "���޸����" << endl;

		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	// �������������
	system("pause");
	system("cls");
}

// ����ְ��
void workerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�������Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ����ҵķ�ʽ��" << endl;
		cout << "1������ְ����Ų���" << endl;
		cout << "2������ְ����������" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			// ���ձ�Ų�
			int id = 0;
			cout << "������Ҫ���ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = this->isExist(id);
			if (ret != -1)
			{
				// �ҵ�ְ��
				cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2)
		{
			// ��������
			string name = "";
			cout << "������Ҫ���ҵ�ְ������" << endl;
			cin >> name;

			// �ж��Ƿ���ҵı�־
			bool flag = false;

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��" << this->m_EmpArray[i]->m_ID << "��ְ����Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "�����ѡ������" << endl;
		}
	}
	// �������������
	system("pause");
	system("cls");
}

// ����ְ��
void workerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�������Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ������ķ�ʽ��" << endl;
		cout << "1�����������������" << endl;
		cout << "2�����ս����������" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			// �������ֵ��Сֵ���±�
			int minOrMax = i;
			for (int j = 0; j < this->m_EmpNum; j++)
			{
				if (select == 1)	// ����
				{
					if (this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
				else  // ����
				{
					if (this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
			}
			// �ж�һ��ʼ��ֵ�ǲ���������Сֵ���粻�Ǿͽ���
			if (i != minOrMax)
			{
				Worker *temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
			
		}
	}
	cout << "����ɹ��������Ľ��Ϊ��" << endl;
	this->save();	// ͬ�����ļ���
	this->show_Emp();
}

// ����ļ�����
void workerManager::clean_File()
{
	cout << "�Ƿ�����б���y/n����" << endl;
	char select = 'n';
	cin >> select;
	if (select == 'y')
	{
		// ����ļ�
		ofstream ofs(FILENAME, ios::trunc);	// trunc��ɾ���ļ������´�����������գ�
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
		cout << "��ճɹ���" << endl;
	}
	// �������������
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