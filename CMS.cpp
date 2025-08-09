#include<iostream> 
#include<string> 
using namespace std;
struct course
{
	int course_id;
	string course_title;
	int credit_hrs;
};
void add_students(course[], int&);
void update_students(course[], int);
void delete_students(course[], int&);
void displayAll_students(course[], int);
void searchAnddisplay_students(course[], int);
int main()
{
	course cou[5];
	int cou_count = 0;
	char op;
	do
	{
		cout << "_____________Menu_____________" << endl;
		cout << "Press 1 to add a course" << endl;
		cout << "Press 2 to update a course" << endl;
		cout << "Press 3 to delete a course" << endl;
		cout << "Press 4 to search and display a course" << endl;
		cout << "Press 5 to display all courses" << endl;
		cout << "Press e to exit the program" << endl;
		cout << "Enter your choice:";
		cin >> op;
		if (op == '1')
		{
			add_students(cou, cou_count);
		}
		else if (op == '2')
		{
			update_students(cou, cou_count);
		}
		else if (op == '3')
		{
			delete_students(cou, cou_count);
		}
		else if (op == '4')
		{
			searchAnddisplay_students(cou, cou_count);
		}
		else if (op == '5')
		{
			displayAll_students(cou, cou_count);
		}
		else if (op == 'e')
		{
			cout << "Program exit!" << endl;
		}
		else
		{
			cout << "Invalid choice!" << endl;
		}

	} while (op != 'e');
}
void add_students(course cou[], int& cou_count)
{
	if (cou_count < 5)
	{
		cout << "Enter course Id:";
		cin >> cou[cou_count].course_id;
		cout << "Enter course Title:";
		cin >> cou[cou_count].course_title;
		cout << "Enter course credit hours:";
		cin >> cou[cou_count].credit_hrs;
		cou_count++;
		cout << "Course added successfully" << endl;
	}
	else
	{
		cout << "Cannot add more then five records." << endl;
	}
}
void update_students(course cou[], int cou_count)
{
	int id;
	bool flag = false;
	cout << "Enter course id you want to update:";
	cin >> id;
	for (int i = 0; i < cou_count; i++)
	{
		if (cou[i].course_id == id)
		{
			flag = true;
			cout << "Enter new course Id:";
			cin >> cou[i].course_id;
			cout << "Enter new course Title:";
			cin >> cou[i].course_title;
			cout << "Enter  new course credit hours:";
			cin >> cou[i].credit_hrs;
			cout << "Course updated successfully" << endl;
		}
	}
	if (!flag)
	{
		cout << "Course not found!!" << endl;
	}
}
void delete_students(course cou[], int& cou_count)
{
	int id;
	bool flag = false;
	cout << "Enter course id you want to delete:";
	cin >> id;
	int ind = -2;
	for (int i = 0; i < cou_count; i++)
	{
		if (cou[i].course_id == id)
		{
			flag = true;
			ind = i;

		}
	}
	if (flag)
	{
		for (int i = ind; i < cou_count - 1; i++)
		{
			cou[i] = cou[i + 1];
		}
		cou_count--;
		cout << "Course deleted successfully" << endl;
	}
	if (!flag)
	{
		cout << "course not found" << endl;
	}
}
void displayAll_students(course cou[], int cou_count)
{
	if (cou_count == 0)
	{
		cout << "No course found" << endl;
	}
	else
	{
		for (int i = 0; i < cou_count; i++)
		{
			cout << "Course " << i << " id is:" << cou[i].course_id <<
				endl;;
			cout << "Course " << i << " title is:" <<
				cou[i].course_title << endl;
			cout << "Course " << i << " credit hours is:" <<
				cou[i].credit_hrs << endl;
		}
	}
}
void searchAnddisplay_students(course cou[], int cou_count)
{
	int id;
	bool flag = false;
	cout << "Enter id you want to search:";
	cin >> id;
	for (int i = 0; i < cou_count; i++)
	{
		if (cou[i].course_id == id)
		{
			flag = true;
			cout << "Course id is:" << cou[i].course_id << endl;
			cout << "Course title is:" << cou[i].course_title << endl;
			cout << "Course credit hour is:" << cou[i].credit_hrs << endl;
		}
	}
	if (!flag)
	{
		cout << "Course not found" << endl;
	}
}