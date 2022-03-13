#pragma once
#include <iostream>
#include <string>

using namespace std;

// 职工抽象类
class Worker {
public:
	// 成员函数：
	// 岗位职责信息描述 纯虚函数 不做任何实现
	virtual void showInfo() = 0;

	// 获取岗位名称 纯虚函数 不做任何实现
	virtual string getDepName() = 0;

	// 成员属性：
	int m_ID; // 职工编号
	string m_Name; // 职工姓名
	int m_DeptID; // 岗位名称
};