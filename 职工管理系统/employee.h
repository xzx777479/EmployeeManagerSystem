#pragma once
// ��ְͨ��ͷ�ļ�
#include <iostream>
#include <string>

#include "worker.h"
using namespace std;

class Employee :public Worker {
public:
	// ���캯��
	Employee(int id, string name, int dID);
	// ��ʾ������Ϣ
	virtual void showInfo();
	// ��ȡ����ID
	virtual string getDepName();
};

