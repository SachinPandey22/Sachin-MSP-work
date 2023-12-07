//Name: Sachin Pandey
//net id: ihn10
//Date: 12/5/2023
//MSP 4
//Purpose: To write a program that will read the grades and process them, giving a le\er grade as per
//University guidelines (F->A).
#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Data {
    string name;
    double msp[4];
    double labCourse;
    double midterm;
    double finalExam;
    double quiz[4];
    double bonus[5];
};

const int WORK_TOTAL = 100; // Total points for Work component
const int RECALL_TOTAL = 100; // Total points for Recall component

void process(Data student);

int main() {
    int no_of_students;

    cout << "Enter Number of Students: ";
    cin >> no_of_students;

    Data students[no_of_students];

    for (int i = 0; i < no_of_students; i++) {
        cout << "Enter student " << i + 1 << "'s name: ";
        cin >> students[i].name;

        // Input scores for Work Component
        cout << "Score in MSP 1: ";
        cin >> students[i].msp[0];
        cout << "Score in MSP 2: ";
        cin >> students[i].msp[1];
        cout << "Score in MSP 3: ";
        cin >> students[i].msp[2];
        cout << "Score in MSP 4: ";
        cin >> students[i].msp[3];
        cout << "Score in Lab course: ";
        cin >> students[i].labCourse;

        // Input scores for Recall Component
        cout << "Score in Midterm Exam: ";
        cin >> students[i].midterm;
        cout << "Score in Final Exam: ";
        cin >> students[i].finalExam;

        for (int j = 0; j < 4; ++j) {
            cout << "Score in Quiz " << j + 1 << ": ";
            cin >> students[i].quiz[j];
        }

        // Input bonus points for Work Component
        cout << "Intro Survey: ";
        cin >> students[i].bonus[0];
        cout << "Algorithm Design Basics Assignment: ";
        cin >> students[i].bonus[1];
        cout << "Github Account Creation & Population: ";
        cin >> students[i].bonus[2];
        cout << "Struct Problem Set: ";
        cin >> students[i].bonus[3];
        cout << "PAs/CAs: ";
        cin >> students[i].bonus[4];
    }

    for (int i = 0; i < no_of_students; i++) {
        cout << "The overall grade of " << students[i].name << " is ";
        process(students[i]);
    }

    return 0;
}

void process(Data student) {
    // Drop the lowest MSP and Quiz
    double msp_sum = 0;
    double lowest_msp = numeric_limits<double>::max();
    double quiz_sum = student.midterm + student.finalExam;
    double lowest_quiz = numeric_limits<double>::max();
    double score;

    for (int i = 0; i < 4; ++i) {
        msp_sum += student.msp[i];
        if (student.msp[i] < lowest_msp) {
            lowest_msp = student.msp[i];
        }

        quiz_sum += student.quiz[i];
        if (student.quiz[i] < lowest_quiz) {
            lowest_quiz = student.quiz[i];
        }
    }

    msp_sum -= lowest_msp;
    quiz_sum -= lowest_quiz;

    // Determine the component with higher points and calculate the final score
    double work_percentage = ((msp_sum + student.labCourse + student.bonus[0] + student.bonus[1] + student.bonus[2] + student.bonus[3] + student.bonus[4]) / WORK_TOTAL) * 100;
    double recall_percentage = (quiz_sum / RECALL_TOTAL) * 100;

    if (work_percentage >= recall_percentage) {
        score = (work_percentage * 0.6) + (recall_percentage * 0.4);
    } else {
        score = (recall_percentage * 0.6) + (work_percentage * 0.4);
    }

    // Convert the numeric grade into a letter grade
    if (score >= 90) {
        cout << "A" << endl;
    } else if (score >= 80) {
        cout << "B" << endl;
    } else if (score >= 70) {
        cout << "C" << endl;
    } else if (score >= 60) {
        cout << "D" << endl;
    } else if (score >= 50) {
        cout << "E" << endl;
    } else {
        cout << "F" << endl;
    }
}
