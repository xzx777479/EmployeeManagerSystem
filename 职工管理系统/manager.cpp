#include "manager.h"


Manager::Manager(int id, string name, int dID) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}
	// 岗位职责信息描述
void Manager::showInfo() {
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDepName()
		<< "\t岗位职责：完成老板交给的任务，并下发任务给普通员工" << endl;
}

	// 获取岗位名称
string Manager::getDepName() {
	return string("经理");
}