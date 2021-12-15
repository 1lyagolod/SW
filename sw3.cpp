#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct student
{
	string surname;
    int group_number;
    double certificate_mark; 
    int position_in_rating;
} *students_info;

int main()
{
	string file_path = "studentInfo.txt";
	int counter_1 = 0;
	ifstream file(file_path, ios::in);
	string check;
	while (!file.eof())
	{
		getline(file, check);
		counter_1++;
	}
	cout<<counter_1<<"\n";
	file.close();
	students_info = new student[counter_1];
	ifstream file_1(file_path, ios::in);
	for (int i = 0; i < counter_1; i++)
	{
		file_1>>students_info[i].surname
		      >>students_info[i].group_number
			  >>students_info[i].certificate_mark
			  >>students_info[i].position_in_rating;

		cout<<students_info[i].surname<<" "
		    <<students_info[i].group_number<<" "
			<<students_info[i].certificate_mark<<" "
			<<students_info[i].position_in_rating<<endl;
	}
	file_1.close();
	ofstream file_2(file_path, ios::trunc);
	for (int i = counter_1 - 1; i >= 0; i--)
	{
		file_2<<students_info[i].surname<<" "
		      <<students_info[i].group_number<<" "
			  <<students_info[i].certificate_mark<<" "
			  <<students_info[i].position_in_rating<<endl;
	}
	file_2.close();
	ifstream count_size(file_path, ios::in);
	int size_of_file;
	char a;
	int counter_2 = 0;
	while (!count_size.eof())
	{
		counter_2++;
		count_size.get(a);
	}
	cout<<endl;
	cout<<"Размер : "<<counter_1 - 1  + counter_2<<endl;
	cout<<endl;
	cout<<"Сортировка : "<<endl;
	cout<<endl;
	ofstream file_3(file_path, ios::app);
	string sort;
	for (int i = 0; i < counter_1 - 1; i++)
	{
		for (int j = 0; j < counter_1 - 1; j++)
		{
			if (students_info[j].surname.at(0) > students_info[j + 1].surname.at(0))
			{
				swap(students_info[j + 1], students_info[j]);
			}
		}
	}
	for (int i = 0; i < counter_1; i++)
	{
		cout<<students_info[i].surname<<" "
		    <<students_info[i].group_number<<" "
			<<students_info[i].certificate_mark<<" "
			<<students_info[i].position_in_rating<<endl;
	}
}
