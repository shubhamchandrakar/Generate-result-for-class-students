#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int n;
class Student
{
    int r_no;
    char name[30], grade;
    int marks[5], total_marks;
public:
    Student()
    {
        r_no =0;
        // name[30]= {};
        // grade ={};
        for (int i = 0; i < 5; i++) {
            marks[i] =0;
        }
        total_marks=0;
    }
public:
    friend ostream& operator<<(ostream& out, const Student& st_data);
    friend istream & operator>>(istream &in,Student s[]);
    friend void generate_result(Student s[], int n);
    friend ostream& operator<<(ostream& out,Student s[]);
};

void generate_result(Student s[], int n){
  for (int j = 0; j < n; j++) {

    for (int i = 0; i < 5; i++) {
      s[j].total_marks = s[j].total_marks + s[j].marks[i];
    }
    float res = 0;
	res = s[j].total_marks/5;
    if(res>=80){
      s[j].grade='A';
    } else if(65<=res&&res<80) {
      s[j].grade='B';
    } else if(55<=res&&res<65) {
      s[j].grade='C';
    } else if(50<=res&&res<55) {
      s[j].grade='D';
    }else{
      s[j].grade='F';
    }
    for (int i = 0; i < 5; i++) {
      if (s[j].marks[i]<33) {
        s[j].grade='F';
      }
    }
  }
}
istream& operator>>(istream &in, Student s[])
{
  for (int j = 0; j < n; j++) {
    cout<<"Enter the Detail of Student : "<< j+1;
    cout<<"\nEnter Name: ";
    in >> s[j].name;
    cout<<"Enter Roll no:";
    in >> s[j].r_no;
    for (int i = 0; i < 5; i++) {
      cout<<"Enter the mark of module "<<i+1<<" : ";
      in >> s[j].marks[i];
    }
  }
    return in;

}
ostream& operator<<(ostream& out, const Student& st_data)
{
    out << "\n Name of Student :"<<st_data.name;
    out << "\n R_no :"<<st_data.r_no;
    for (int i = 0; i < 5; i++) {
      out<<"\n Marks of module "<<i+1<<" : "<<st_data.marks[i];
    }
    out << '\n';
    return out;
}
ostream& operator<<(ostream& out, Student s[])
{

  ofstream my_file;
	my_file.open ("output.txt");
  // my_file << "n = "<<n << '\n';
  for (int j = 0; j < n; j++) {
    my_file << "****************************************************************" << '\n';

    my_file << "\n Name of Student :"<<s[j].name;
    my_file << "\n R_no :"<<s[j].r_no;
    my_file << "\n====================" << '\n';
    for (int i = 0; i < 5; i++) {
      if (s[j].marks[i]<33) {
          my_file<<"\n Marks of module "<<i+1<<" : "<<s[j].marks[i]<<"\tF";
          // s[j].grade = 'F';
      }else{
        my_file<<"\n Marks of module "<<i+1<<" : "<<s[j].marks[i];
      }  
    }
    my_file<<"\n Total marks is "<< s[j].total_marks<<" out of 500";
    my_file << "\n============";
    my_file<<"\n Grade : "<<s[j].grade;
    my_file << "\n============";
    my_file<< '\n';
}
    return out;
}


void print(){
	ifstream myfile ("output.txt");
	if (myfile.is_open())
	{
		  char c = myfile.get();
	    while ( myfile.good() )
	    {
      		cout<< c;
      		c = myfile.get();
	    }
	    myfile.close();
	}
	else
	{
	    cout << "Unable to open file";
	}

}



int main()
{
    cout<<"Enter No of Students in DESD Class ";
    cin>>n;
    Student s1[n];
    cin >> s1;
    // cout << s1[0];
    generate_result(s1,n);
    cout<<s1;
    print();

}
