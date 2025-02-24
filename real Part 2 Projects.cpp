#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * This program reads student data from a file, dynamically allocates memory for student records,
 * calculates their average test scores, assigns a course grade, and displays the results.
 * The program ensures proper memory deallocation before termination.
 */

 // Structure to store student information
struct Student {
    string name;
    int idNum;
    int* tests;
    double average;
    char grade;
};

/**
 * Reads student data from a file and dynamically allocates memory for students and test scores.
 * @param file Input file stream containing student data.
 * @param studentCnt Reference to store number of students.
 * @param testsCnt Reference to store number of test scores per student.
 * @return Pointer to dynamically allocated array of Student structures.
 */
Student* getData(ifstream& file, int& studentCnt, int& testsCnt) {
    file >> studentCnt >> testsCnt;
    Student* students = new Student[studentCnt];

    for (int i = 0; i < studentCnt; i++) {
        file >> students[i].name >> students[i].idNum;
        students[i].tests = new int[testsCnt];
        for (int j = 0; j < testsCnt; j++) {
            file >> students[i].tests[j];
        }
    }
    return students;
}

/**
 * Calculates the average score and assigns a letter grade based on a grading scale.
 * @param students Array of Student structures.
 * @param studentCnt Number of students.
 * @param testsCnt Number of test scores per student.
 */
void calcAverage(Student students[], int studentCnt, int testsCnt) {
    for (int i = 0; i < studentCnt; i++) {
        int sum = 0;
        for (int j = 0; j < testsCnt; j++) {
            sum += students[i].tests[j];
        }
        students[i].average = static_cast<double>(sum) / testsCnt;

        if (students[i].average >= 91) students[i].grade = 'A';
        else if (students[i].average >= 81) students[i].grade = 'B';
        else if (students[i].average >= 71) students[i].grade = 'C';
        else if (students[i].average >= 61) students[i].grade = 'D';
        else students[i].grade = 'F';
    }
}

/**
 * Displays student data in a formatted report.
 * @param students Array of Student structures.
 * @param studentCnt Number of students.
 */
void printReport(const Student students[], int studentCnt) {
    cout << "Student ID   Name    Average Score   Grade\n";
    for (int i = 0; i < studentCnt; i++) {
        cout << students[i].idNum << " " << students[i].name << " "
            << students[i].average << " " << students[i].grade << endl;
    }
}

/**
 * Frees dynamically allocated memory for student records.
 * @param students Array of Student structures.
 * @param studentCnt Number of students.
 */
void freeMemory(Student students[], int studentCnt) {
    for (int i = 0; i < studentCnt; i++) {
        delete[] students[i].tests;
    }
    delete[] students;
}

int main() {
    ifstream file("grades.txt");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int studentCnt, testsCnt;
    Student* students = getData(file, studentCnt, testsCnt);
    file.close();

    calcAverage(students, studentCnt, testsCnt);
    printReport(students, studentCnt);
    freeMemory(students, studentCnt);

    return 0;
}
