#include <iostream>
#include <climits>
#include <vector>

std::vector<unsigned int> indeksy;
std::vector<unsigned int> vtemp;

void umiesc(unsigned int** tab2, unsigned int row, unsigned int col, unsigned int n) {
    vtemp.push_back(col);
    for (int i = row, j = 0; i < n; i++, j++) {
        tab2[i][col]++;
        if (col >= j) {
            tab2[i][col - j]++;
        }
        if (col+j < n) {
            tab2[i][col + j]++;
        }
    }
}

void usun(unsigned int** tab2, unsigned int row, unsigned int col, unsigned int n) {
    vtemp.pop_back();
    for (int i = row, j = 0; i < n; i++, j++) {
        tab2[i][col]--;
        if (col >= j) {
            tab2[i][col - j]--;
        }
        if (col + j < n) {
            tab2[i][col + j]--;
        }
    }

}
unsigned int min = INT_MAX;
void function(unsigned int n, unsigned int** tab1, unsigned int** tab2, unsigned int row, unsigned int temp) {
 
    if (row == n) {
        if (temp < min) {
            indeksy = vtemp;
            min = temp;
        }
        return;
    }

    for (int i = 0; i < n; i++ ) {
        if (tab2[row][i] == 0 && temp+tab1[row][i]<min) {
            umiesc(tab2, row, i, n);
            function(n, tab1, tab2, row + 1, temp+tab1[row][i]);
            usun(tab2, row, i, n);
        }
        
    }
}

int main()
{
    unsigned int n, koszt;
    unsigned int k;
    std::cin >> n;

    unsigned int** koszty = new unsigned int* [n];
    unsigned int** szach = new unsigned int* [n];

  

    for (int i = 0; i < n; i++) {
        koszty[i] = new unsigned int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> koszt;
            koszty[i][j] = koszt;
        }
    }

    for (int i = 0; i < n; i++) {
        szach[i] = new unsigned int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            szach[i][j] = 0;
        }
    }

    //umiesc(szach, 0, 0, 5);
    //umiesc(szach, 1, 2, 5);
    //usun(szach, 0, 0, 5);
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << szach[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */
    function(n, koszty, szach, 0, 0);
    for (int i = 0; i < n; i++) {
        std::cout << indeksy[i] << ' ';
    }

    for (int i = 0; i < n; i++) {
        delete[] koszty[i];
        delete[] szach[i];
    }
    delete[] koszty;
    delete[] szach;

    return 0;
}