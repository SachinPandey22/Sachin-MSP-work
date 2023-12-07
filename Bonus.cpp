#include <iostream>
#include <fstream>
#include <sstream>
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
    string inputFileName, outputFileName;

    cout << "Enter input CSV file name: ";
    cin >> inputFileName;

    cout << "Enter output CSV file name: ";
    cin >> outputFileName;

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files. Make sure the file names are correct." << endl;
        return 1;
    }

    int no_of_students;

    inputFile >> no_of_students;

    Data students[no_of_students];

    // Reading data from CSV file
    for (int i = 0; i < no_of_students; i++) {
        inputFile >> students[i].name;

        for (int j = 0; j < 4; ++j) {
            inputFile >> students[i].msp[j];
        }

        inputFile >> students[i].labCourse >> students[i].midterm >> students[i].finalExam;

        for (int j = 0; j < 4; ++j) {
            inputFile >> students[i].quiz[j];
        }

        for (int j = 0; j < 5; ++j) {
            inputFile >> students[i].bonus[j];
        }
    }

    // Writing headers to output CSV file
    outputFile << "Name,Grade" << endl;

    // Processing and writing grades to output CSV file
    for (int i = 0; i < no_of_students; i++) {
        process(students[i]);
        outputFile << students[i].name << ","; // Writing student name to CSV file
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

void process(Data student) {
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

    double work_percentage = (msp_sum / WORK_TOTAL) * 100 + (student.labCourse + student.bonus[0] + student.bonus[1] + student.bonus[2] + student.bonus[3] + student.bonus[4]);
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

