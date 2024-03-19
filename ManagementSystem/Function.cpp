#include "Function.h"
using namespace std;


void createNewClasses(Class *&NewClasses, int &numOfClass)
{
	cout << "Please input the number of new Classes";
	cin >> numOfClass;
	NewClasses = new Class[numOfClass];
	cout << "Please input the file name: ";
	string filename;
	getline(cin,filename);
	for (int i = 0; i < numOfClass; ++i) {
		cin >> NewClasses[i].Name;
		//readStudentsList(NewClasses[i].stHead, filename);
	}
}

void createSchoolYear(SchoolYear &sy)
{
	getline(cin, sy.Name);
	getline(cin, sy.start_date);
	getline(cin, sy.end_date);
	int numOfNewClasses;
	Class *NewClasses;
	createNewClasses(NewClasses, numOfNewClasses);
	Class *tmp = new Class[sy.NumOfClasses + numOfNewClasses];
	for (int i = 0; i < sy.NumOfClasses; ++i) {
		tmp[i] = sy.ClassesList[i];
	}
	for (int i = 0; i < numOfNewClasses; ++i) {
		tmp[i + sy.NumOfClasses] = NewClasses[i];
	}
	delete[] sy.ClassesList;
	sy.ClassesList = tmp;
	sy.NumOfClasses += numOfNewClasses;
	
}
void AddCourse(Semester& semester, const Course& course)
{
	Node<Course>* new_course_node = new Node<Course>{ course };

	if (semester.CoursesList == nullptr) {
		semester.CoursesList = new_course_node;
	}
	else {
		Node<Course>* current = semester.CoursesList;
		while (current->next != nullptr) 
		{
			current = current->next;
		}
		current->next = new_course_node;
	}
}
	void AddStudentToCourse(string student_id, string name, Student & st, Course & co);
	{

		Student* new_student = new Student(student_id, name);
		if (student_head == nullptr) {
			student_head = new_student;
		}
		else
		{
			Student* current_student = student_head;
			while (current_student->next) {
				current_student = current_student->next;
			}
			current_student->next = new_student;
		}


		cout << "Sinh vien " << name << " (" << student_id << ") da duoc them vao khoa hoc" << endl;
	}
}