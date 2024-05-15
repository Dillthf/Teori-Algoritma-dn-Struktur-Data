#include <iostream>
#include <string>
using namespace std;
void bubble_Sort(string arr[], int n) { // Deklarasi variable. Dimana variabel arr berisi nama warga dengan tipe data string, dan n berisi jumlah warga
    for (int i = 0; i < n - 1; ++i) { // Perulangan for ini memulai dari indeks i = 0 dan berhenti ketika indeks i menjadi sama dengan n-1.
        int elemen_terurut = i; // Variabel elemen_terurut berisi indeks elemen yang terurut terkecil hingga saat ini.
        for (int j = i + 1; j < n; ++j) { // Perulangan for ini memulai dari indeks i+1 dan berhenti ketika indeks j menjadi sama dengan n.
            if (arr[j] < arr[elemen_terurut]) { //Jika elemen arr[j] lebih kecil dari elemen arr[elemen_terurut], maka indeks elemen_terurut diubah menjadi j
                elemen_terurut = j;
            } // Akhir dari if
        } // Akhir dari for
        swap(arr[i], arr[elemen_terurut]); // Setelah mencari elemen yang terurut terkecil, elemen arr[i] diganti dengan elemen arr[elemen_terurut]
    } // Akhir dari for
} // Akhir dari bubble_sort

int main() { // Fungsi main merupakan fungsi utama program.
    string arr[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"}; // Deklarasi variabel array yang berisi tipe data string. Elemen dalam array tersebut adalah nama-nama warga
    int n = sizeof(arr) / sizeof(arr[0]); // Menghitung jumlah elemen dalam array arr dengan menggunakan fungsi sizeof


    cout << "Nama warga sebelum diurutkan: "; //Menampilkan teks "Nama warga sebelum diurutkan :" ke layar
    for (int i = 0; i < n; ++i) { // Perulangan for yang berada dalam main mengulang setiap elemen dalam array arr.
        cout << arr[i] << " "; // Menampilkan setiap elemen dalam array arr ke layar.
    } // Akhir prulangan for
    cout << endl;

    bubble_Sort(arr, n); // Berupa fungsi bubble_Sort dengan parameter arr (array yang akan diurutkan) dan n (jumlah elemen dalam array).

    cout << "Nama warga setelah diurutkan: "; //Menampilkan teks "Nama warga setelah diurutkan :" ke layar
    for (int i = 0; i < n; ++i) { // Perulangan for yang berada dalam main mengulang setiap elemen dalam array arr setelah diurutkan.
        cout << arr[i] << " ";
    } // Akhir perulangan for
    cout << endl;

    return 0;
} // Akhir main

