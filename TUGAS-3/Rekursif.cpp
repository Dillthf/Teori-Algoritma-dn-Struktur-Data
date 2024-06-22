#include <iostream>
using namespace std;

// Deklarasi fungsi-fungsi yang saling memanggil
int faktorialB(int n);

int faktorialA(int n) {
    if (n <= 1) {
        return 1; // Basis rekursi
    } else {
        return n * faktorialB(n - 1); // Panggilan rekursi ke fungsi B
    }
}

int faktorialB(int n) {
    return faktorialA(n); // Panggilan rekursi ke fungsi A
}

int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;
    
    if (num < 0) {
        cout << "Bilangan harus positif." << endl;
    } else {
        int hasil = faktorialA(num); // Memulai rekursi dari fungsi A
        cout << "Faktorial dari " << num << " adalah: " << hasil << endl;
    }

    return 0;
}