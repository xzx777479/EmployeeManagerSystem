#pragma once
#include <iostream>
using namespace std;

#include "worker.h"

// 老板类
class Boss :public Worker {
public:
	// 构造函数
	Boss(int id, string name, int dID);
	// 岗位职责信息描述
	virtual void showInfo();

	// 获取岗位名称
	virtual string getDepName();
};