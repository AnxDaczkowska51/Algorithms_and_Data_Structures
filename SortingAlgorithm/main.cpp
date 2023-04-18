#include <iostream>

struct mountain {
    std::string s;
    unsigned int w;
};
struct island {
    unsigned int n;
    mountain* ptr;
    mountain* power_of_two;
    mountain* rest;
};
void insertionSort (mountain* tab, unsigned int n);

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    unsigned int t;
    unsigned int num_of_powers = 0, num_of_rest = 0;
    //std::cout << "number of islands: \n";
    std::cin >> t;
    island* tab = new island[t];
    for (int i = 0; i < t; i++){
        unsigned int number = 1;
        //std::cout << "number of mountains: \n";
        std::cin >> tab[i].n;
        tab[i].ptr = new mountain[tab[i].n];
        //std::cout << "name and height of each mountain: \n";

        for (int j = 0; j < tab[i].n; j++){
            std::cin >> tab[i].ptr[j].s >> tab[i].ptr[j].w;
        }
        for (int j = 0; j < tab[i].n; j++){
            for (int k = 0; k < 32; k++, number <<= 1)
                if (tab[i].ptr[j].w == number) {
                    num_of_powers++;
                    break;
                }
        number = 1;
        }
        num_of_rest = tab[i].n - num_of_powers;
        //std::cout << num_of_powers << " " << num_of_rest << std::endl;
        tab[i].power_of_two = new mountain[num_of_powers];
        tab[i].rest = new mountain[num_of_rest];
        for (int j = 0, l1 = 0, l2 = 0; j < tab[i].n; j++){
            for (int k = 0; k <= 32; k++, number <<= 1){
                if (tab[i].ptr[j].w == number){
                    tab[i].power_of_two[l1].s = tab[i].ptr[j].s;
                    tab[i].power_of_two[l1].w = tab[i].ptr[j].w;
                    l1++;
                    break;
                }
                else{
                    if (k == 32){
                        tab[i].rest[l2].s = tab[i].ptr[j].s;
                        tab[i].rest[l2].w = tab[i].ptr[j].w;
                        l2++;
                        break;
                    }
                }
            }
         number = 1;
        }
        insertionSort((&(tab[i].power_of_two[0]), num_of_powers);
        insertionSort((&(tab[i].rest[0]), num_of_rest);
        //std::cout << num_of_powers << " " << num_of_rest << std::endl;

        for (int j = 0; j < num_of_powers; j++){
            std::cout << tab[i].power_of_two[j].s << "-" << tab[i].power_of_two[j].w << " ";
        }
        //std::cout << "\n rest:\n";
        for (int j = 0; j < num_of_rest; j++){
            std::cout << tab[i].rest[j].s << "-" << tab[i].rest[j].w << " ";
        }
        std::cout << std::endl;
        delete[]  tab[i].power_of_two;
        delete[]  tab[i].rest;
        num_of_powers = 0;
        num_of_rest = 0;
    }
    delete[] tab;
}

void insertionSort (mountain* tab, unsigned int n){
    for (int i = 1; i < n; i++){
        int key1 = tab[i].w;
        std::string key2 = tab[i].s;
        int j = i - 1;
        while (key1 < tab[j].w && j >= 0) {
            tab[j + 1].w = tab[j].w;
            tab[j + 1].s = tab[j].s;
            j--;
        }
        tab[j + 1].w = key1;
        tab[j + 1].s = key2;
    }
}