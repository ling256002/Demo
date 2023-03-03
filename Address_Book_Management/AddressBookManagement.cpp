#include <iostream>
#include <string>
using namespace std;

#define MAX 1000  //最大人数


struct contact
{
	string name;		//姓名
	short gender;		//性别
	short age;			//年龄
	string tel_number;	//电话号码
	string address;		//家庭地址
};

struct address_books
{
	struct contact book[MAX];	//保存联系人的结构体数组
	int m_size;			//通讯录人员个数
};


void ShowMenu();		//菜单显示
void AddContacts(address_books *ads);		//添加联系人
void ShowContacts(address_books *ads);	//显示联系人
void DeleteContacts(address_books *ads);	//删除联系人
void FindContacts(address_books *ads);	//查找联系人
void EditContacts(address_books *ads);	//修改联系人
void ClearContacts(address_books *ads);	//清空联系人

//检测联系人是否存在；存在返回联系人在通讯录的位置，不存在返回-1；
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
	address_books ads;	//创建一个通讯录结构体
	ads.m_size = 0;		//初始化通讯录人数为0

	while (true)
	{	
		ShowMenu();		//菜单显示
		int menu = 0;	//菜单选择
		cin >> menu;
		switch (menu)
		{
		case 1:		//添加联系人
			AddContacts(&ads);
			break;
		case 2:		//显示联系人
			ShowContacts(&ads);
			break;
		case 3:		//删除联系人
			DeleteContacts(&ads);
			break;
		case 4:		//查找联系人
			FindContacts(&ads);
			break;
		case 5:		//修改联系人
			EditContacts(&ads);
			break;
		case 6:		//清空联系人
			ClearContacts(&ads);
			break;
		case 0:		//退出通讯录
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");		//清屏
		}
	}

	system("pause");
	return 0;
}

void ShowMenu()		//菜单显示
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

void AddContacts(address_books *ads)		//添加联系人
{
	cout << "请输入姓名：" << endl;
	cin >> ads->book[ads->m_size].name;

	cout << "请输入性别：" << endl;
	cout << "1---男    2---女" << endl;
	int sex = 0;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			ads->book[ads->m_size].gender = sex;
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请输入年龄：" << endl;
	cin >> ads->book[ads->m_size].age;

	cout << "请输入电话号码：" << endl;
	cin >> ads->book[ads->m_size].tel_number;

	cout << "请输入家庭住址：" << endl;
	cin >> ads->book[ads->m_size].address;

	ads->m_size++;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");		//清屏
}


//显示联系人
void ShowContacts(address_books *ads)	
{
	if (ads->m_size <= 0)
		cout << "当前通讯录记录为空" << endl;
	else
	{
		for (int i = 0; i < ads->m_size; i++)
			cout << "姓名：" << ads->book[i].name
				<< "\t性别：" << (ads->book[i].gender==1?"男":"女")
				<< "\t年龄：" << ads->book[i].age
				<< "\t电话号码：" << ads->book[i].tel_number
			<< " 家庭住址：" << ads->book[i].address << endl;
	}
	system("pause");
	system("cls");		//清屏
}

//删除联系人
void DeleteContacts(address_books *ads)
{
	cout << "请输入要删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(ads, name);
	if (ret != -1)
	{
		for (int i = 0; i < ret; i++)
			ads->book[i] = ads->book[i + 1];

		ads->m_size--;
		cout << "删除成功" << endl;
	}
	else
		cout << "联系人不存在" << endl;

	system("pause");
	system("cls");		//清屏
}

//查找联系人
void FindContacts(address_books *ads)	
{
	cout << "请输入要查找的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(ads, name);
	if (ret != -1)
	{
		cout << "姓名：" << ads->book[ret].name
			<< "\t性别：" << (ads->book[ret].gender == 1 ? "男" : "女")
			<< "\t年龄：" << ads->book[ret].age
			<< "\t电话号码：" << ads->book[ret].tel_number
			<< " 家庭住址：" << ads->book[ret].address << endl;
	}
	else
		cout << "联系人不存在" << endl;

	system("pause");
	system("cls");		//清屏
}

//修改联系人
void EditContacts(address_books *ads)	
{
	cout << "请输入要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(ads, name);
	if (ret != -1)
	{
		cout << "请输入姓名：" << endl;
		cin >> ads->book[ret].name;

		cout << "请输入性别：" << endl;
		cout << "1---男    2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ads->book[ret].gender = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		cout << "请输入年龄：" << endl;
		cin >> ads->book[ret].age;

		cout << "请输入电话号码：" << endl;
		cin >> ads->book[ret].tel_number;

		cout << "请输入家庭住址：" << endl;
		cin >> ads->book[ret].address;
		cout << "修改成功" << endl;
	}
	else
		cout << "联系人不存在" << endl;

	system("pause");
	system("cls");		//清屏
}

//清空联系人
void ClearContacts(address_books *ads)	
{
	ads->m_size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");		//清屏
}