#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;

struct Student
{
	string name;
	double ch;
	double ma;
	double en;
};

vector<Student> stuList;

void addStudent()//添加学生
{
	Student s;
	cout << "Please enter student's name:" << endl;
	cin >> s.name;
	cout << "Please enter Chinese score:" << endl;
	cin >> s.ch;
	cout << "Please enter Math score:" << endl;
	cin >> s.ma;
	cout << "Please enter English score:" << endl;
	cin >> s.en;
	stuList.push_back(s);
	cout << "Added successfully!" << endl;
	cout << endl;
}

void modifyStudent()//修改
{
	string name;
	cout << "Pleas enter the name of the student to modify:" << endl;
	cin >> name;
	for (int i = 0;i < stuList.size();i++)
	{
		if (stuList[i].name == name)
		{
			cout << "Please enter new Chinese score:" << endl;
			cin >> stuList[i].ch;
			cout << "Please enter new Math score:" << endl;
			cin >> stuList[i].ma;
			cout << "Please enter new English score:" << endl;
			cin >> stuList[i].en;
			cout << "Modified successfully!" << endl;
			cout << endl;
			return;
		}
	}
	cout << "Student not found" << endl;
}

void deleteStudent()//删除
{
	string name;
	cout << "Enter student name to delete:" << endl;
	cin >> name;
	for (auto it = stuList.begin();it != stuList.end();it++)
	{
		if (it->name == name)
		{
			stuList.erase(it);
			cout << "Deleted successfully." << endl;
			return;
		}
	}
	cout << "Student not found" << endl;
}

void queryStudent()//查询
{
	string name;
	cout << "Enter student name to query:" << endl;
	cin >> name;
	for (auto &s : stuList)
	{
		if (s.name == name)
		{
			cout << "Name: " << s.name << endl;
			cout << "Chinese: " << s.ch << endl;
			cout << "Math: " << s.ma << endl;
			cout << "English: " << s.en << endl;
			return;
		}
	}
	cout << "Student not found" << endl;
}

void showAll()//显示所有学生信息
{
	if (stuList.empty())
	{
		cout << "No student information." << endl;
		return;
	}
	cout << "########## All Student Information ##########" << endl;
	for (auto& s : stuList)
	{
		cout << "Name: " << s.name << endl;
		cout << "Chinese: " << s.ch << endl;
		cout << "Math: " << s.ma << endl;
		cout << "English: " << s.en << endl;
		cout << "#############################################" << endl;
	}
}

void statScore()//显示班级分数信息
{
	if (stuList.empty()) {
		cout << "No data!" << endl;
		return;
	}
	double chMax = stuList[0].ch, chMin = stuList[0].ch, chSum = 0;
	string chMaxName = stuList[0].name, chMinName = stuList[0].name;
	double maMax = stuList[0].ma, maMin = stuList[0].ma, maSum = 0;
	string maMaxName = stuList[0].name, maMinName = stuList[0].name;
	double enMax = stuList[0].en, enMin = stuList[0].en, enSum = 0;
	string enMaxName = stuList[0].name, enMinName = stuList[0].name;
	for (auto& s : stuList) {
		chSum += s.ch;
		if (s.ch > chMax)
		{
			chMax = s.ch;
			chMaxName = s.name;
		}
		if (s.ch < chMin)
		{
			chMin = s.ch;
			chMinName = s.name;
		}
		maSum += s.ma;
		if (s.ma > maMax)
		{
			maMax = s.ma;
			maMaxName = s.name;
		}
		if (s.ma < maMin)
		{
			maMin = s.ma;
			maMinName = s.name;
		}
		enSum += s.en;
		if (s.en > enMax)
		{
			enMax = s.en;
			enMaxName = s.name;
		}
		if (s.en < enMin)
		{
			enMin = s.en;
			enMinName = s.name;
		}
	}
	double chAvg = chSum / stuList.size();
	double maAvg = maSum / stuList.size();
	double enAvg = enSum / stuList.size();
	cout << "==== Class Score Statistics ====" << endl;
	cout << fixed << setprecision(2);
	cout << "Chinese:max" << chMax << "(" << chMaxName << "),min" << chMin << "(" << chMinName << "),Average score:" << chAvg << endl;
	cout << "Math:max   " << maMax << "(" << maMaxName << "),min" << maMin << "(" << maMinName << "),Average score:" << maAvg << endl;
	cout << "English:max" << enMax << "(" << enMaxName << "),min" << enMin << "(" << enMinName << "),Average score:" << enAvg << endl;
	cout << "== == == == == == == == == == ==" << endl;
}

int menu()
{
	int op;
	while (true)
	{
		cout << "== == == == == Students Management System == == == == ==" << endl;
		cout << "==            1.Add Student Information               ==" << endl;
		cout << "==            2.Modify Student Information            ==" << endl;
		cout << "==            3.Delete Student Information            ==" << endl;
		cout << "==            4.Query Student Information             ==" << endl;
		cout << "==            5.List All Students Information         ==" << endl;
		cout << "==            6.Calculate Class Grades                ==" << endl;
		cout << "==            7.Exit System                           ==" << endl;
		cout << "== == == == == == == == == == == == == == == == == == ==" << endl;
		cout << "Please enter an option:" << endl;
		cout << endl;
		cin >> op;
		switch (op)
		{
		case 1:
			addStudent();
			break;
		case 2:
			modifyStudent();
			break;
		case 3:
			deleteStudent();
			break;
		case 4:
			queryStudent();
			break;
		case 5:
			showAll();
			break;
		case 6:
			statScore();
			break;
		case 7:
			cout << "Successfully exited the system.Goodbye! " << endl;
			return 0;
		default:
			cout << "Invalid option ! Please enter a number between 1 and 7." << endl;
			break;
		}
	}
}

int main()
{	
	menu();
	return 0;
}