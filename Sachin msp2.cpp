//Author: Sachin Pandey
//inh10
//Date:Nov 2, 2023


#include <iostream>
#include <iomanip>

using namespace std;

 

  double averages(int num1, int num2, int num3, double& best_avg) {
  double avg;
  int highest = 0;
  int highest2 = 0;
  if (num1 >= num2 && num1 >= num3) {
    highest = num1;
    if (num2>= num3) {
      highest2 = num2;
    }
    else {
      highest2 = num3;
    }
  } else if (num2 >= num3 && num2 >= num1) {
    highest = num2;
    if (num1 >= num3) {
      highest2 = num1;
    } else {
      highest2 = num3;
    }
  } else if (num3 >= num1 && num3 >= num2) {
    highest = num3;
    if (num1 >= num2) {
      highest2 = num1;
    } else {
      highest2 = num2;
    }
  }

  best_avg = (highest + highest2) / 2.0;

  avg = (num1 + num2 + num3) / 3.0;
  return avg;
}

int main() {
  int a, b, c;
  double avg, best_avg;
  cin >> a >> b >> c;
  avg = averages(a, b, c, best_avg);

 
 cout << setprecision(2) << fixed << avg << " " << setprecision(2) << fixed << best_avg << endl;
  return 0;
}
