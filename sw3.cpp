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

void showInformationOfFile(int counter);
void calculateSizeOfFile(string file_path);
void readInformationFromFile(int counter, string file_path, student* students_info);
void writeInformationInFile(int counter, string file_path, student* students_info);
void sortInfromation(int counter, student* students_info);

int main()
{
	string file_path = "studentInfo.txt";
	int counter = 0;
	ifstream file(file_path, ios::in);
	string check;
	while (!file.eof())
	{
		getline(file, check);
		counter++;
	}
	cout<<counter<<"\n";
	file.close();
	students_info = new student[counter];
	readInformationFromFile(counter, "studentInfo.txt", students_info);
	showInformationOfFile(counter);
	writeInformationInFile(counter, "studentInfo.txt", students_info);
	calculateSizeOfFile("studentInfo.txt");
	sortInfromation(counter, students_info);
	showInformationOfFile(counter);
}

void showInformationOfFile(int counter)
{
	for	(int i = 0; i < counter; i++)
	{
		cout<<students_info[i].surname<<" "
		    <<students_info[i].group_number<<" "
			<<students_info[i].certificate_mark<<" "
			<<students_info[i].position_in_rating<<endl;
	}
}

void calculateSizeOfFile(string file_path)
{
	ifstream file_size(file_path, ios::binary | ios::ate);
	int size = file_size.tellg();
	file_size.close();
	cout<<endl;
	cout<<"Размер : "<<size<<endl;
}

void readInformationFromFile(int counter, string file_path, student* students_info)
{
	ifstream file(file_path, ios::in);
	for (int i = 0; i < counter; i++)
	{
		file>>students_info[i].surname
		      >>students_info[i].group_number
			  >>students_info[i].certificate_mark
			  >>students_info[i].position_in_rating;
	}
	file.close();
}

void writeInformationInFile(int counter, string file_path, student* students_info)
{
	ofstream file(file_path, ios::trunc);
	for (int i = counter - 1; i >= 0; i--)
	{
		file<<students_info[i].surname<<" "
		      <<students_info[i].group_number<<" "
			  <<students_info[i].certificate_mark<<" "
			  <<students_info[i].position_in_rating<<endl;
	}
	file.close();
}

void sortInfromation(int counter, student* students_info)
{
	cout<<endl;
	cout<<"Сортировка : "<<endl;
	for (int i = 0; i < counter - 1; i++)
	{
		for (int j = 0; j < counter - 1; j++)
		{
			if (students_info[j].surname.at(0) > students_info[j + 1].surname.at(0))
			{
				swap(students_info[j + 1], students_info[j]);
			}
		}
	}
}