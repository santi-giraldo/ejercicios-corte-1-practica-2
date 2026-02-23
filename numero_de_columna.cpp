#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        long result = 0;
        for (char c : columnTitle) {
            int value = c - 'A' + 1;
            result = result * 26 + value;
        }
        return (int)result;
    }
};

int main() {
    Solution sol;
    string columnTitle;
    cout << "Ingrese el titulo de la columna de Excel (ej: A, AB, ZY): ";
    cin >> columnTitle;
    int result = sol.titleToNumber(columnTitle);
    cout << "El numero de columna equivalente es: " << result << endl;
    return 0;
}
