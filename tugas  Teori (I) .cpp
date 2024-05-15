#include <iostream>
#include <algorithm>

using namespace std;

bool cekDuplikat(int arrA[], int panjangArr) {
    sort(arrA, arrA + panjangArr); 

    for (int i = 0; i < panjangArr ; ++i) {
        if (arrA[i] == arrA[i + 1]) {
            return true; 
        }
    }
    return false; 
}

int main() {
    int arrA[] = {2, 1, 3, 4};
    int panjangArr = 4;
    cout << boolalpha << cekDuplikat(arrA, panjangArr);
    return 0;
}
