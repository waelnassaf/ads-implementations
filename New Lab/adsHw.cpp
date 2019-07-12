/*
|--------------------------------------------------------------------------
| Exercise 3 | University
|--------------------------------------------------------------------------
| Write a class Student which consist of the following data members:
| * Id, Name, Credits, credit price fields, array of marks.
| * Each mark has (quiz, midterm, final).
| * A constructor that takes name and credits as inputs and generates automatic id.
| * GetSemesterPaymentAmount() function member that returns the amount which should be —
| * paid by the student.
|
| In the main function:
| * Create dynamic array of students.
| * Read their data from the console.
| * Print the amount which should be paid by each student.
|
*/

#include <iostream>
#include <string>
using namespace std;


class Mark {
public:
    double quiz;
    double mid;
    double final;
    Mark() {    }
    Mark(double quiz, double mid, double final) {
        this->quiz = quiz;
        this->mid = mid;
        this->final = final;
    }
};

class Student {
public:
    static int idCounter;
    static double creditPrice;
    int id;
    string name;
    int credits;
    Mark* marks;
    int marksNum;
    Student() {     }
    Student(string name, int credits) {
        id = ++idCounter;
        this->name = name;
        this->credits = credits;
    }
    double GetSemesterPaymentAmount() {
        return creditPrice * credits;
    }
};

int Student::idCounter = 0;
double Student::creditPrice = 18000;

int main() {

    int size;
    cout << "Enter the number of students: \t";
    cin >> size;


    Student* students = new Student[size];

    string name;
    int credits;
    double q, m, f;
    for (int i = 0; i < size; i++) {

        cout << "Enter student's name: \t";
        cin >> name;
        cout << "Enter student's credit hours: \t";
        cin >> credits;
        students[i] = Student(name, credits);


        cout << "How many marks does this student have?\t";
        cin >> students[i].marksNum;
        students[i].marks = new Mark[students[i].marksNum];

        for (int j = 0; j < students[i].marksNum; j++) {
            cout << "Enter the quiz mark: \t";
            cin >> q;
            cout << "Enter the midterm mark: \t";
            cin >> m;
            cout << "Enter the final mark: \t";
            cin >> f;
            students[i].marks[j] = Mark(q, m, f);
        }
    }



    cout << "+-+-+-+-+-+-+-+-+-+-+-+-\n";
    for (int i = 0; i < size; i++) {
        cout << "Student Name:\t " << students[i].name << "\n";
        cout << "Student ID:\t " << students[i].id << "\n";
        cout << "Payment Amount:\t $" << students[i].GetSemesterPaymentAmount() << "\n";
        cout << "Student Marks\n";
        for (int j = 0; j < students[i].marksNum; j++) {
            cout << "\tQuiz Mark: ";
            cout << students[i].marks[j].quiz << "\n";
            cout << "\tMidterm Mark: ";
            cout << students[i].marks[j].mid << "\n";
            cout << "\tFinal Mark: ";
            cout << students[i].marks[j].final << "\n";
            cout << "\t-------------\n";
        }
        cout << "+-+-+-+-+-+-+-+-+-+-+-+-\n";
    }

    // Dump Free-store..... .. .
    delete[] students;
    students = NULL;
	
	system("pause");
}
