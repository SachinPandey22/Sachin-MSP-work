//Author: Sachin Pandey
//ihn10
//MSP3
//Purpose: To ask the user name and phone number and display phone number associated with that name.
//Pre condition: Input must be valid for number of entries
//Post condition: Program must output the corresponding phone number to the name entered by user, if the input doesnot exist program must return empty string.
#include <iostream>
using namespace std;
string GetPhoneNumber(string nameArr[], string phoneNumberArr[], int size, string contactName);
int main() {
string nameArr[20];
string phoneNumberArr[20];
int numPairs;
string contactName;
cin >> numPairs;
for (int i = 0; i < numPairs; ++i) {
cin >> nameArr[i] >> phoneNumberArr[i];
}
// Input contact name
cin >> contactName;
// Call the function
string phoneNumber = GetPhoneNumber(nameArr, phoneNumberArr, numPairs, contactName);
if (phoneNumber != "") {
cout << phoneNumber << endl;
} else {
cout << "Name not found" << endl;
}
return 0;
}
string GetPhoneNumber(string nameArr[], string phoneNumberArr[], int size, string contactName) {
for (int i = 0; i < size; ++i) {
if (nameArr[i] == contactName) {
return phoneNumberArr[i];
}
}
return "";
}