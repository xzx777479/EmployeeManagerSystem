#include "workerManager.h"

WorkerManager::WorkerManager() {
	
	// 1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in); // 读文件
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		// 初始化属性
		// 初始化记录人数
		this->m_EmpNum = 0;
		// 初始化数组指针
		this->m_EmpArray = nullptr;
		// 初始化文件是否为空标志位
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	// 2、文件存在且数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		// 代表文件为空
		//cout << "文件为空" << endl;
		// 初始化属性
		// 初始化记录人数
		this->m_EmpNum = 0;
		// 初始化数组指针
		this->m_EmpArray = nullptr;
		// 初始化文件是否为空标志位
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	// 3、文件存在，并且记录了数据
	int num = this->get_EmpNum();
	//cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	// 开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// 将文件中的数据存到数组中
	this->init_Emp();

	// 测试代码
	//for (int i = 0; i < this->m_EmpNum; i++) {
	//	cout << "职工编号：" << this->m_EmpArray[i]->m_ID
	//		<< " 姓名：" << this->m_EmpArray[i]->m_Name
	//		<< " 部门：" << this->m_EmpArray[i]->m_DeptID << endl;
	//}
}

WorkerManager::~WorkerManager() {
	// 默认析构函数
}

// 展示菜单函数
void WorkerManager::show_Menu() {

	cout << "****************************************" << endl;
	cout << "********* 欢迎使用职工管理系统 *********" << endl;
	cout << "************ 0.退出管理系统 ************" << endl;
	cout << "************ 1.增加职工信息 ************" << endl;
	cout << "************ 2.显示职工信息 ************" << endl;
	cout << "************ 3.删除离职职工 ************" << endl;
	cout << "************ 4.修改职工信息 ************" << endl;
	cout << "************ 5.查找职工信息 ************" << endl;
	cout << "************ 6.按照编号排序 ************" << endl;
	cout << "************ 7.清空所有文档 ************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}
// 退出系统函数
void WorkerManager::ExitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);  // 退出程序
}

// 添加职工函数
void WorkerManager::Add_Emp() {
	cout << "请输入添加职工的数量：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		// 添加
		// 计算添加新空间的大小
		int newSize = this->m_EmpNum + addNum; // 新空间的大小 = 原来的人数 + 新增的人数

		// 开辟新空间
		Worker** newSpace = new Worker* [newSize];

		// 将原来空间中的数据拷贝到新空间中
		if (this->m_EmpArray != nullptr) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// 添加新数据
		for (int i = 0; i < addNum; i++) {
			int id; // 职工编号
			string name; // 职工姓名
			int dSelect; // 部门选择

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			// 将创建的职工保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		// 释放原有的空间
		delete[] this->m_EmpArray;

		// 更改新空间的指向
		this->m_EmpArray = newSpace;

		// 更新新的职工人数
		this->m_EmpNum = newSize;

		// 更新职工不为空标志位
		this->m_FileIsEmpty = false;

		// 提示添加成功
		cout << "成功添加" << addNum << "名新职工！" << endl;

		// 保存数据到文件中
		this->save();
	}
	else
		cout << "数据输入有误" << endl;

	// 按任意键后清屏，回到上级目录
	system("pause");
	system("cls");

}

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out); // 以输出的方式打开文件 -- 写入文件

	// 将每个人的数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}

	ofs.close();
}

// 获取职工人数
int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); // 打开文件 读取数据

	// 接收变量
	int id;
	string name;
	int dID;

	int num = 0;
	// 逐行读取文件内容
	while (ifs >> id && ifs >> name && ifs >> dID) {
		// 统计人数
		num++;
	}
	return num;
}

void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// 数组索引
	int index = 0;

	int id;
	string name;
	int dID;

	while (ifs >> id && ifs >> name && ifs >> dID) {
		Worker* worker = nullptr;

		// 普通职工
		if (dID == 1) {
			worker = new Employee(id, name, dID);
		}
		// 经理
		else if (dID == 2) {
			worker = new Manager(id, name, dID);
		}
		else if (dID == 3) {
			worker = new Boss(id, name, dID);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}

	// 关闭文件
	ifs.close();
}

// 显示职工
void WorkerManager::showEmp() {
	// 判断文件是否为空
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			// 利用多态调用接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
// 删除职工
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		// 按照职工编号进行删除操作
		cout << "请输入要删除职工的编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		// 找到了该职工
		if (index != -1) {
			for (int i = index; i < this->m_EmpNum; i++) {
				// 数据前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			this->m_EmpNum--; // 更新数组中记录人员的个数
			// 同步更新到文件中
			this->save();

			cout << "删除成功！" << endl;
		}
		else {
			cout << "删除失败，未找到该职工" << endl;
		}
		// 按任意键清屏
		system("pause");
		system("cls");
	}
}

// 判断职工是否存在 如果存在返回职工所在数组中的位置，不存在返回-1
int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_ID == id) {
			// 找到了该职工
			index = i;
		}
	}
	return index;
}

// 修改职工
void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		int id;
		cout << "请输入要删除的职工编号：" << endl;
		cin >> id;
		int ret = this->IsExist(id);
		// 找到该职工了
		if (ret != -1) {
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到： " << id << "号职工，请输入新的职工号：" << endl;
			cin >> newId;

			cout << "请输入新姓名：" << endl;
			cin >> newName;
			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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

			// 更新数据到数组中
			this->m_EmpArray[ret] = worker;

			cout << "修改成功！" << endl;

			// 保存到文件中
			this->save();
			
		}
		else {
			cout << "修改失败，查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

// 查找职工
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入查找方式：" << endl;
		cout << "1、按职工编号查找 " << endl;
		cout << "2、按职工姓名查找 " << endl;
	}
	int select = 0;
	cin >> select;
	if (select == 1) {
		// 按照编号查找
		int id;
		cout << "请输入查找的编号：" << endl;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1) {
			// 找到职工
			cout << "查找成功！该职工信息如下：" << endl;
			this->m_EmpArray[ret]->showInfo();
		}
		else {
			cout << "查找失败，查无此人" << endl;
		}
	}
	else if (select == 2) {
		string name;
		cout << "请输入查找的姓名：" << endl;
		cin >> name;
		// 加入判断是否查到的标志
		bool flag = false; // 默认未找到该职工

		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->m_Name == name) {
				cout << "查找成功，职工编号为："
					<< this->m_EmpArray[i]->m_ID
					<< "号职工信息如下：" << endl;

				flag = true;
				// 调用显示信息的接口
				this->m_EmpArray[i]->showInfo();
			}
		}
		if (flag == false) {
			cout << "查找失败，查无此人" << endl;
		}
	}
	else {
		cout << "输入选项有误！" << endl;
	}
	system("pause");
	system("cls");
}


