#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <climits>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    unsigned int n, m;
    std::cin >> n >> m;

    std::string wioska;
    std::string sasiad;
    std::string start;
    unsigned int start_id;
    std::string docelowa;
    int* docelowe_wioski = new int[m];
    std::map<std::string, int> mapa;
    std::vector<std::vector<int>> sasiedzi(n);
    unsigned int* dystans = new unsigned int[n];


    for (unsigned int i = 0; i < n; i++) {
        std::cin >> wioska;
        mapa.insert(std::pair<std::string,int> (wioska, i));
    }

    unsigned int i = 0;
    while (i < n) {
        std::cin >> sasiad;
        if (sasiad == "X") {
            i++;
        }
        else {
            sasiedzi[i].push_back(mapa[sasiad]);
        }
    }
    std::cin >> start;
    start_id = mapa[start];
    for (unsigned int i = 0; i < m; i++) {
        std::cin >> docelowa;
        docelowe_wioski[i] = mapa[docelowa];
    }

    for (unsigned int i = 0; i < n; i++) {
        dystans[i] = INT_MAX;
    }
    dystans[start_id] = 0;

    std::queue<int> q;
    q.push(start_id);

    int element;

    while (!q.empty()) {
        element = q.front();
        for (int i = 0; i < sasiedzi[element].size(); i++) {
            if (dystans[sasiedzi[element][i]] == INT_MAX) {
                dystans[sasiedzi[element][i]] = dystans[element] + 1;

                q.push(sasiedzi[element][i]);
            }
        }
        q.pop();
    }
    int longest = 0;
    for (int i = 0; i < m; i++) {
        if (dystans[docelowe_wioski[i]] > longest) {
            longest = dystans[docelowe_wioski[i]];
        }
    }
    std::cout << longest;
}