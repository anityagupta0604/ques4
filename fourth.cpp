#include <iostream>
#include <string>
#include <stack>
using namespace std;
string removeKDigits(string ticketPrice, int k) {
    int n = ticketPrice.size();
    stack<char> stk;
    for (int i = 0; i < n; i++) {

        while (!stk.empty() && k > 0 && stk.top() > ticketPrice[i]) {
            stk.pop();
            k--;
        }
        stk.push(ticketPrice[i]);
    }
    while (k > 0 && !stk.empty()) {
        stk.pop();
        k--;
    }
    string result = "";
    while (!stk.empty()) {
        result = stk.top() + result;
        stk.pop();
    }
    int start = 0;
    while (start < result.size() && result[start] == '0') {
        start++;
    }
    result = result.substr(start);
    return result.empty() ? "0" : result;
}
int main() {
    string ticketPrice;
    int k;
    cout << "Enter ticket price: ";
    cin >> ticketPrice;
    cout << "Enter number of digits to remove (K): ";
    cin >> k;
    string result = removeKDigits(ticketPrice, k);
    cout << "The smallest possible ticket price is: " << result << endl;
    return 0;
}
