#include "workerManager.h"

WorkerManager::WorkerManager() {
	
	// 1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in); // ���ļ�
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		// ��ʼ������
		// ��ʼ����¼����
		this->m_EmpNum = 0;
		// ��ʼ������ָ��
		this->m_EmpArray = nullptr;
		// ��ʼ���ļ��Ƿ�Ϊ�ձ�־λ
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	// 2���ļ�����������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		// �����ļ�Ϊ��
		//cout << "�ļ�Ϊ��" << endl;
		// ��ʼ������
		// ��ʼ����¼����
		this->m_EmpNum = 0;
		// ��ʼ������ָ��
		this->m_EmpArray = nullptr;
		// ��ʼ���ļ��Ƿ�Ϊ�ձ�־λ
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	// 3���ļ����ڣ����Ҽ�¼������
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	// ���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// ���ļ��е����ݴ浽������
	this->init_Emp();

	// ���Դ���
	//for (int i = 0; i < this->m_EmpNum; i++) {
	//	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_ID
	//		<< " ������" << this->m_EmpArray[i]->m_Name
	//		<< " ���ţ�" << this->m_EmpArray[i]->m_DeptID << endl;
	//}
}

WorkerManager::~WorkerManager() {
	// Ĭ����������
}

// չʾ�˵�����
void WorkerManager::show_Menu() {

	cout << "****************************************" << endl;
	cout << "********* ��ӭʹ��ְ������ϵͳ *********" << endl;
	cout << "************ 0.�˳�����ϵͳ ************" << endl;
	cout << "************ 1.����ְ����Ϣ ************" << endl;
	cout << "************ 2.��ʾְ����Ϣ ************" << endl;
	cout << "************ 3.ɾ����ְְ�� ************" << endl;
	cout << "************ 4.�޸�ְ����Ϣ ************" << endl;
	cout << "************ 5.����ְ����Ϣ ************" << endl;
	cout << "************ 6.���ձ������ ************" << endl;
	cout << "************ 7.��������ĵ� ************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}
// �˳�ϵͳ����
void WorkerManager::ExitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);  // �˳�����
}

// ���ְ������
void WorkerManager::Add_Emp() {
	cout << "���������ְ����������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		// ���
		// ��������¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum; // �¿ռ�Ĵ�С = ԭ�������� + ����������

		// �����¿ռ�
		Worker** newSpace = new Worker* [newSize];

		// ��ԭ���ռ��е����ݿ������¿ռ���
		if (this->m_EmpArray != nullptr) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// ���������
		for (int i = 0; i < addNum; i++) {
			int id; // ְ�����
			string name; // ְ������
			int dSelect; // ����ѡ��

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = nullptr;
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
			// ��������ְ�����浽������
			newSpace[this->m_EmpNum + i] = worker;
		}

		// �ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;

		// �����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		// �����µ�ְ������
		this->m_EmpNum = newSize;

		// ����ְ����Ϊ�ձ�־λ
		this->m_FileIsEmpty = false;

		// ��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ����" << endl;

		// �������ݵ��ļ���
		this->save();
	}
	else
		cout << "������������" << endl;

	// ����������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");

}

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out); // ������ķ�ʽ���ļ� -- д���ļ�

	// ��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}

	ofs.close();
}

// ��ȡְ������
int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); // ���ļ� ��ȡ����

	// ���ձ���
	int id;
	string name;
	int dID;

	int num = 0;
	// ���ж�ȡ�ļ�����
	while (ifs >> id && ifs >> name && ifs >> dID) {
		// ͳ������
		num++;
	}
	return num;
}

void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// ��������
	int index = 0;

	int id;
	string name;
	int dID;

	while (ifs >> id && ifs >> name && ifs >> dID) {
		Worker* worker = nullptr;

		// ��ְͨ��
		if (dID == 1) {
			worker = new Employee(id, name, dID);
		}
		// ����
		else if (dID == 2) {
			worker = new Manager(id, name, dID);
		}
		else if (dID == 3) {
			worker = new Boss(id, name, dID);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}

	// �ر��ļ�
	ifs.close();
}

// ��ʾְ��
void WorkerManager::showEmp() {
	// �ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			// ���ö�̬���ýӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
// ɾ��ְ��
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		// ����ְ����Ž���ɾ������
		cout << "������Ҫɾ��ְ���ı�ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		// �ҵ��˸�ְ��
		if (index != -1) {
			for (int i = index; i < this->m_EmpNum; i++) {
				// ����ǰ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			this->m_EmpNum--; // ���������м�¼��Ա�ĸ���
			// ͬ�����µ��ļ���
			this->save();

			cout << "ɾ���ɹ���" << endl;
		}
		else {
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
		// �����������
		system("pause");
		system("cls");
	}
}

// �ж�ְ���Ƿ���� ������ڷ���ְ�����������е�λ�ã������ڷ���-1
int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_ID == id) {
			// �ҵ��˸�ְ��
			index = i;
		}
	}
	return index;
}

// �޸�ְ��
void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		int id;
		cout << "������Ҫɾ����ְ����ţ�" << endl;
		cin >> id;
		int ret = this->IsExist(id);
		// �ҵ���ְ����
		if (ret != -1) {
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽�� " << id << "��ְ�����������µ�ְ���ţ�" << endl;
			cin >> newId;

			cout << "��������������" << endl;
			cin >> newName;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = nullptr;

			switch (dSelect) {
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			// �������ݵ�������
			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ���" << endl;

			// ���浽�ļ���
			this->save();
			
		}
		else {
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

// ����ְ��
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1����ְ����Ų��� " << endl;
		cout << "2����ְ���������� " << endl;
	}
	int select = 0;
	cin >> select;
	if (select == 1) {
		// ���ձ�Ų���
		int id;
		cout << "��������ҵı�ţ�" << endl;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1) {
			// �ҵ�ְ��
			cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
			this->m_EmpArray[ret]->showInfo();
		}
		else {
			cout << "����ʧ�ܣ����޴���" << endl;
		}
	}
	else if (select == 2) {
		string name;
		cout << "��������ҵ�������" << endl;
		cin >> name;
		// �����ж��Ƿ�鵽�ı�־
		bool flag = false; // Ĭ��δ�ҵ���ְ��

		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->m_Name == name) {
				cout << "���ҳɹ���ְ�����Ϊ��"
					<< this->m_EmpArray[i]->m_ID
					<< "��ְ����Ϣ���£�" << endl;

				flag = true;
				// ������ʾ��Ϣ�Ľӿ�
				this->m_EmpArray[i]->showInfo();
			}
		}
		if (flag == false) {
			cout << "����ʧ�ܣ����޴���" << endl;
		}
	}
	else {
		cout << "����ѡ������" << endl;
	}
	system("pause");
	system("cls");
}


