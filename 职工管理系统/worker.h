#pragma once
#include <iostream>
#include <string>

using namespace std;

// ְ��������
class Worker {
public:
	// ��Ա������
	// ��λְ����Ϣ���� ���麯�� �����κ�ʵ��
	virtual void showInfo() = 0;

	// ��ȡ��λ���� ���麯�� �����κ�ʵ��
	virtual string getDepName() = 0;

	// ��Ա���ԣ�
	int m_ID; // ְ�����
	string m_Name; // ְ������
	int m_DeptID; // ��λ����
};