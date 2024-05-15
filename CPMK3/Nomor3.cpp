#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk mencari indeks dari kata yang dicari dalam array terurut yang mengandung string kosong
int searchString(string arr[], int low, int high, const string& target) {
    if (low > high) {
        return -1; // Jika low melebihi high, kata tidak ditemukan
    }

    int mid = (low + high) / 2;

    // Jika elemen tengah adalah string kosong, kita harus mencari elemen non-kosong terdekat
    if (arr[mid].empty()) {
        int kiri = mid - 1;
        int kanan = mid + 1;
        while (true) {
            if (kiri < low && kanan > high) {
                return -1; // Tidak ada elemen non-kosong yang ditemukan
            } else if (kanan <= high && !arr[kanan].empty()) {
                mid = kanan;
                break;
            } else if (kiri >= low && !arr[kiri].empty()) {
                mid = kiri;
                break;
            }
            kanan++;
            kiri--;
        }
    }

    // Lakukan perbandingan string dan sesuaikan batas pencarian
    if (arr[mid] == target) {
        return mid; // Kata ditemukan
    } else if (arr[mid] < target) {
        return searchString(arr, mid + 1, high, target);
    } else {
        return searchString(arr, low, mid - 1, target);
    }
}

int main() {
    const int SIZE = 9;
    string sortedArray[SIZE] = {"Adi", "", "", "bermain", "", "bola", "", "", "sedang"};
    string target;

    // Input kata yang ingin dicari
    cout << "Masukkan kata yang ingin dicari: ";
    cin >> target;

    // Mencari kata menggunakan fungsi searchString
    int indeks = searchString(sortedArray, 0, SIZE - 1, target);

    if (indeks != -1) {
        cout << "Kata \"" << target << "\" ditemukan pada indeks " << indeks << "." << endl;
    } else {
        cout << "Kata \"" << target << "\" tidak ditemukan." << endl;
    }

    return 0; // Program selesai
}
