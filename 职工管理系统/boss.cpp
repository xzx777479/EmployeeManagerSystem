#include "boss.h"


Boss::Boss(int id, string name, int dID) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}
// ��λְ����Ϣ����
void Boss::showInfo() {
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDepName()
		<< "\t��λְ�𣺹���˾��������" << endl;
}

// ��ȡ��λ����
string Boss::getDepName() {
	return string("�ϰ�");
}