#include <iostream>
#include <string>
using namespace std;

string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string multiple[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string tens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};

string convertNumberstoWords(int num) {
    if (num==1000){
        return "one thousand";
    } else if (num>=100){
        if (num%100==0){
            return ones[num/100] + " hundred";
        } else{
            return ones[num/100] + " hundred and " + convertNumberstoWords(num%100);
        }
    } else if (num >= 20) {
        return multiple[num/10] + " " + ones[num%10];
    } else if (num>=10) {
        return tens[num - 10];
    } else {
        return ones[num];
    }
}

int count(string s) {
    int count = 0;
    for (char c : s){
        if (c != ' '){
            count++;
        }
    }return count;
}

int main() {
    int total = 0;
    for (int i = 1; i <= 1000; ++i) {
        string words = convertNumberstoWords(i);
        total += count(words);
    }
    cout << total << endl;
    return 0;
}
