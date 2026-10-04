#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


// 4070 -- 4070. Minimum Rotations to Dial a Number I
class Solution {
public:
    int minRotations(string s) {
        int n = s.size();
        int minSteps = 0;

        int firstptr = s[0] - '0';
        int secondptr = 0;
        
        int choice1 = abs(firstptr - secondptr);
        int choice2 = 10 - abs(firstptr - secondptr);
        minSteps+= min(choice1, choice2);

        firstptr = 0;
        for (secondptr = 1; secondptr < n; secondptr++) {
            int num1 = s[firstptr] - '0';
            int num2 = s[secondptr] - '0';

            int firstWay = abs(num1 - num2);
            int secondWay = 10 - abs(num1 - num2);
            minSteps+= min(firstWay, secondWay);
            
            firstptr++;
        }
        return minSteps;
    }
};