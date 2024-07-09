#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int score(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int sum = 0;
    
    for (int num : cardPoints) {
        sum += num;
    }
    
    int window_size = n - k;
    int currSum = 0;
 
    for (int i=0; i<window_size; ++i){
        currSum += cardPoints[i];
    }
    
    int minSum = currSum;
    for (int i=window_size; i<n; ++i){
        currSum += cardPoints[i] - cardPoints[i-window_size];
        minSum = min(minSum, currSum);
    }return sum - minSum;
}

void display(vector<int>& cardPoints){
    int n = cardPoints.size();
    for(int i=0; i<n; i++){
        cout << cardPoints[i] << " ";
    }cout << endl;
}

int main() {
    vector<int> cardPoints;
    int k;

    cardPoints = {1, 2, 3, 4, 5, 6, 1};
    k = 3;
    cout << "\nCard Points : ";
    display(cardPoints);
    cout << "k : ";
    cout << k << endl;
    cout << "Maximum score : " << score(cardPoints, k) << endl;
    
    cardPoints = {2, 2, 2};
    k = 2;
    cout << "\nCard Points : ";
    display(cardPoints);
    cout << "k : ";
    cout << k << endl;
    cout << "Maximum score : " << score(cardPoints, k) << endl;
    
    cardPoints = {9, 7, 7, 9, 7, 7, 9};
    k = 7;
    cout << "\nCard Points : ";
    display(cardPoints);
    cout << "k : ";
    cout << k << endl;
    cout << "Maximum score : " << score(cardPoints, k) << endl;
    
    return 0;
}
