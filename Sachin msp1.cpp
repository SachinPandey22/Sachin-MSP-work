//Author: Sachin Pandey
//ihn10
//Date: Oct 2023

#include <iostream>
using namespace std;

int main() {
      double loan, installment, interest;
      cin >> loan>>installment>>interest;
     
      int i = 0;

      while (loan>0){
         loan = (loan * interest + loan) - installment;
         i=i+1;
      }

      cout << i;
      if (i==1){
         cout << " payment" << endl;
      }

      else {
         cout << " payments" << endl;
      }
   return 0;
}