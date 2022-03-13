#pragma once
// 普通职工头文件
#include <iostream>
#include <string>

#include "worker.h"
using namespace std;

class Employee :public Worker {
public:
	// 构造函数
	Employee(int id, string name, int dID);
	// 显示个人信息
	virtual void showInfo();
	// 获取部门ID
	virtual string getDepName();
};

