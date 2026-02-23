#include <iostream>
#include <vector>
#include <climits> // <-- para INT_MAX
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int price : prices) {
            if (price < minPrice) minPrice = price;
            int profit = price - minPrice;
            if (profit > maxProfit) maxProfit = profit;
        }
        return maxProfit;
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Ingrese el numero de dias: ";
    cin >> n;
    if (n <= 0) {
        cout << "La ganancia maxima es: 0" << endl;
        return 0;
    }
    vector<int> prices(n);
    cout << "Ingrese los precios de cada dia:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    int result = sol.maxProfit(prices);
    cout << "La ganancia maxima es: " << result << endl;
    return 0;
}
