#include <iostream>
#include <fstream>

#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

// 职工管理系统

int main() {
	
	// 测试代码
	//Worker* worker = nullptr;
	//worker = new Employee(1, "张三",1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "李四", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "王五", 3);
	//worker->showInfo();
	//delete worker;

	// 实例化管理者对象
	WorkerManager wm;

	// 选择变量
	int chose = 0;

	while (true) {
		// 调用展示菜单函数
		wm.show_Menu();

		cout << "请输入您的选择：" << endl;
		cin >> chose; // 接收用户的选择

		switch (chose)
		{
		case 0: // 退出系统
			wm.ExitSystem();
			break;
		case 1: // 增加职工
			wm.Add_Emp();
			break;
		case 2: // 显示职工
			wm.showEmp();
			break;
		case 3: // 删除职工
			wm.Del_Emp();
			break;
		case 4: // 修改职工
			wm.Mod_Emp();
			break;
		case 5: // 查找职工
			wm.Find_Emp();
			break;
		case 6: // 排序职工
			break;
		case 7: // 清空文档
			break;

		default:
			system("cls"); // 清屏操作
			break;
		}

	}
	system("pause");
	return 0;
}