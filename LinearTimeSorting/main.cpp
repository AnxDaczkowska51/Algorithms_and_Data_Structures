#include<iostream>
#include<string>

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    int k_i, p_i;
    std::string name;
    std::cin >> n;

    std::string arr[100][9];

    for (int i = 0; i < n; i++) {
        std::cin >> name >> k_i >> p_i;
        arr[k_i][p_i-1] += name + ' ';
    }

    for (int i = 99; i >= 0; i--) {
        for (int j = 0; j < 9; j++) {
            std::cout << arr[i][j];
        }
    }

    return 0;
}