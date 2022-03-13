#include "boss.h"


Boss::Boss(int id, string name, int dID) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}
// 岗位职责信息描述
void Boss::showInfo() {
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDepName()
		<< "\t岗位职责：管理公司所有事务" << endl;
}

// 获取岗位名称
string Boss::getDepName() {
	return string("老板");
}