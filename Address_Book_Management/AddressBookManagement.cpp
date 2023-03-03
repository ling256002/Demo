#include <iostream>
#include <string>
using namespace std;

#define MAX 1000  //�������


struct contact
{
	string name;		//����
	short gender;		//�Ա�
	short age;			//����
	string tel_number;	//�绰����
	string address;		//��ͥ��ַ
};

struct address_books
{
	struct contact book[MAX];	//������ϵ�˵Ľṹ������
	int m_size;			//ͨѶ¼��Ա����
};


void ShowMenu();		//�˵���ʾ
void AddContacts(address_books *ads);		//�����ϵ��
void ShowContacts(address_books *ads);	//��ʾ��ϵ��
void DeleteContacts(address_books *ads);	//ɾ����ϵ��
void FindContacts(address_books *ads);	//������ϵ��
void EditContacts(address_books *ads);	//�޸���ϵ��
void ClearContacts(address_books *ads);	//�����ϵ��

//�����ϵ���Ƿ���ڣ����ڷ�����ϵ����ͨѶ¼��λ�ã������ڷ���-1��
int isExist(address_books * ads, string name)
{
	for (int i = 0; i < ads->m_size; i++)
	{
		if (ads->book[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	address_books ads;	//����һ��ͨѶ¼�ṹ��
	ads.m_size = 0;		//��ʼ��ͨѶ¼����Ϊ0

	while (true)
	{	
		ShowMenu();		//�˵���ʾ
		int menu = 0;	//�˵�ѡ��
		cin >> menu;
		switch (menu)
		{
		case 1:		//�����ϵ��
			AddContacts(&ads);
			break;
		case 2:		//��ʾ��ϵ��
			ShowContacts(&ads);
			break;
		case 3:		//ɾ����ϵ��
			DeleteContacts(&ads);
			break;
		case 4:		//������ϵ��
			FindContacts(&ads);
			break;
		case 5:		//�޸���ϵ��
			EditContacts(&ads);
			break;
		case 6:		//�����ϵ��
			ClearContacts(&ads);
			break;
		case 0:		//�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");		//����
		}
	}

	system("pause");
	return 0;
}

void ShowMenu()		//�˵���ʾ
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

void AddContacts(address_books *ads)		//�����ϵ��
{
	cout << "������������" << endl;
	cin >> ads->book[ads->m_size].name;

	cout << "�������Ա�" << endl;
	cout << "1---��    2---Ů" << endl;
	int sex = 0;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			ads->book[ads->m_size].gender = sex;
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "���������䣺" << endl;
	cin >> ads->book[ads->m_size].age;

	cout << "������绰���룺" << endl;
	cin >> ads->book[ads->m_size].tel_number;

	cout << "�������ͥסַ��" << endl;
	cin >> ads->book[ads->m_size].address;

	ads->m_size++;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");		//����
}


//��ʾ��ϵ��
void ShowContacts(address_books *ads)	
{
	if (ads->m_size <= 0)
		cout << "��ǰͨѶ¼��¼Ϊ��" << endl;
	else
	{
		for (int i = 0; i < ads->m_size; i++)
			cout << "������" << ads->book[i].name
				<< "\t�Ա�" << (ads->book[i].gender==1?"��":"Ů")
				<< "\t���䣺" << ads->book[i].age
				<< "\t�绰���룺" << ads->book[i].tel_number
			<< " ��ͥסַ��" << ads->book[i].address << endl;
	}
	system("pause");
	system("cls");		//����
}

//ɾ����ϵ��
void DeleteContacts(address_books *ads)
{
	cout << "������Ҫɾ������ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExist(ads, name);
	if (ret != -1)
	{
		for (int i = 0; i < ret; i++)
			ads->book[i] = ads->book[i + 1];

		ads->m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
		cout << "��ϵ�˲�����" << endl;

	system("pause");
	system("cls");		//����
}

//������ϵ��
void FindContacts(address_books *ads)	
{
	cout << "������Ҫ���ҵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExist(ads, name);
	if (ret != -1)
	{
		cout << "������" << ads->book[ret].name
			<< "\t�Ա�" << (ads->book[ret].gender == 1 ? "��" : "Ů")
			<< "\t���䣺" << ads->book[ret].age
			<< "\t�绰���룺" << ads->book[ret].tel_number
			<< " ��ͥסַ��" << ads->book[ret].address << endl;
	}
	else
		cout << "��ϵ�˲�����" << endl;

	system("pause");
	system("cls");		//����
}

//�޸���ϵ��
void EditContacts(address_books *ads)	
{
	cout << "������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExist(ads, name);
	if (ret != -1)
	{
		cout << "������������" << endl;
		cin >> ads->book[ret].name;

		cout << "�������Ա�" << endl;
		cout << "1---��    2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ads->book[ret].gender = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		cout << "���������䣺" << endl;
		cin >> ads->book[ret].age;

		cout << "������绰���룺" << endl;
		cin >> ads->book[ret].tel_number;

		cout << "�������ͥסַ��" << endl;
		cin >> ads->book[ret].address;
		cout << "�޸ĳɹ�" << endl;
	}
	else
		cout << "��ϵ�˲�����" << endl;

	system("pause");
	system("cls");		//����
}

//�����ϵ��
void ClearContacts(address_books *ads)	
{
	ads->m_size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");		//����
}