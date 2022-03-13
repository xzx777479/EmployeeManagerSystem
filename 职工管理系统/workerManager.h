#pragma once  // ��ֹͷ�ļ��ظ�����
#include <iostream>  // �������������ͷ�ļ�

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
using namespace std;  // ʹ�ñ�׼�����ռ�

#define FILENAME "empFile.txt"



class WorkerManager {
public:
	// ���캯��
	WorkerManager();

	// չʾ�˵�����
	void show_Menu();

	// �˳�ϵͳ����
	void ExitSystem();

	// ��¼ְ������
	int m_EmpNum;

	// ְ������ָ�� ����ָ��
	Worker** m_EmpArray;

	// ���ְ��
	void Add_Emp();

	// �����ļ�
	void save();

	// �ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	// ͳ������
	int get_EmpNum();

	// ��ʼ������
	void init_Emp();
	
	// ��ʾְ��
	void showEmp();

	// ɾ��ְ��
	void Del_Emp();

	// �ж�ְ���Ƿ���� ������ڷ���ְ�����������е�λ�ã������ڷ���-1
	int IsExist(int id);

	// �޸�ְ����Ϣ
	void Mod_Emp();

	// ����ְ��
	void Find_Emp();

	// ��������
	~WorkerManager();
};