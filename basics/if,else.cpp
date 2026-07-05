#include<iostream>
using namespace std;
/*
int main() {
  int age;
  cin >> age;

  if (age >= 18) {
    cout << "the person is an adult";
  }
  else {
    cout << "the person is not an adult.";
  }

  return 0;
}
*/

/*
A school has following rules or grading system:
1. Below 25 - F
2. 25 to 44 - E
3. 45 to 49 - D
4. 50 to 59 - C
5. 60 to 79 - B
6. 80 to 100 - A
*/

int main () {
  int marks;
  cin >> marks;

  if (marks < 25 ) {
    cout<< "grade F.";
  }
  else if (marks >=25 && marks <=44) {
    cout << "grade E.";
  }
  else if (marks >=45 && marks <=49) {
    cout << "grade D.";
  }
  else if (marks >=50 && marks <=59) {
    cout << "grade C.";
  }
  else if (marks >=60 && marks <=79) {
    cout << "grade B.";
  }
  else if (marks >=80 && marks <=100) {
    cout << "grade A.";
  }

  return 0;
  
}
