#include "manager.h"


Manager::Manager(int id, string name, int dID) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}
	// ��λְ����Ϣ����
void Manager::showInfo() {
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDepName()
		<< "\t��λְ������ϰ彻�������񣬲��·��������ͨԱ��" << endl;
}

	// ��ȡ��λ����
string Manager::getDepName() {
	return string("����");
}