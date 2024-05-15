# <h1 align="center">Evaluasi CPMK Sub-CPMK 3</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## 1. Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma 
### 1. Binary Search
#### Alur
 Algoritma pencarian binary search berjalan pada array yang sudah terurut. Pada algoritma ini, langlah berikutnya setelah array diurutkan adalah mencari elemen dengan menjumlahkan indeks indeks pertama dan terakhir array kemudian dibagi dua. Hasilnya akan menjadi indeks nilai tengah. Elemen yang terdapat pada indeks nilai tengah tersebut dibandingkan dengan nilai yang ingin dicari. Jika elemen yang dicari lebih kecil dari elemen tengah, cari di setengah kiri array. Sedangkan, jika elemen yang dicari lebih besar dari elemen tengah, cari di setengah kanan array. Langkah tersebut diulangi hingga nilai ditemukan atau semua elemen array telah diperiksa.
#### Runtime
  - Best case O(1): terjadi jika elemen yang dicari tepat berada di tengah array.
  - Worst case O(log n): terjadi jika elemen yang dicari tidak ada dalam array atau berada di ujung array. Setiap iterasi membagi jumlah elemen yang harus diperiksa menjadi dua.
### 2. Linear Search
#### Alur
 Linear search bekerja dengan mencari satu persatu dari awal array hingga akhir. Algoritma ini akan bekerja dimulai pada elemen pertama di array, setiap elemen akan dibandingkan dengan elemen yang dicari. Jika bernilai sama, pencarian selesai. Namun jika tidak, pencarian akan terus dilakukan hingga elemen terakhir array.  
#### Runtime
  - Best case O(1): terjadi ketika elemen yang dicari berada di posisi pertama array.
  - Worst case O(n): terjadi ketika elemen yang dicari tidak ada dalam array atau berada di posisi terakhir array. Harus memeriksa setiap elemen dalam array.

## 2. Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut 

```C++
#include <iostream>
#include <string>
#include <algorithm> // Untuk fungsi transform()
using namespace std;

// Fungsi untuk mencari rasa eskrim menggunakan linear search
bool linearSearch(string ragamRasa[], int size, string dicari) {
    // Mengubah target menjadi huruf kecil
    transform(dicari.begin(), dicari.end(), dicari.begin(), ::tolower);
    
    for (int i = 0; i < size; ++i) {
        // Mengubah rasa eskrim ke huruf kecil sebelum membandingkan
        string rasa = ragamRasa[i];
        transform(rasa.begin(), rasa.end(), rasa.begin(), ::tolower);
        
        if (rasa == dicari) {
            return true; // Jika rasa eskrim ditemukan
        }
    }
    return false; // Jika rasa eskrim tidak ditemukan
}

int main() {
    const int MAX_FLAVORS = 7; // Jumlah maksimum rasa eskrim
    string rasaEskrim[MAX_FLAVORS] = {"Mangga", "Melon", "Stroberi", "Susu Kurma", "Jagung", "Pisang", "Jeruk"};
    string rasaDicari;

    // Input rasa eskrim yang ingin dicari
    cout << "Silahkan masukkan rasa eskrim yang ingin dicari : ";
    getline(cin, rasaDicari);

    // Mencari rasa eskrim menggunakan linear search
    if (linearSearch(rasaEskrim, MAX_FLAVORS, rasaDicari)) {
        cout << "Rasa eskrim \"" << rasaDicari << "\" tersedia" << endl;
    } else {
        cout << "Maaf, rasa eskrim yang dimaksud \"" << rasaDicari << "\" tidak tersedia." << endl;
    }

    return 0; // Program selesai
}
 ```

Program tersebut menggunakan salah satu algoritma searching untuk mencari rasa es krim yang diinginkan pengguna. Program mendeklarasikan array bernama rasaEskrim dengan kapasitas 7 yang berisi daftar rasa eskrim bertipe data string. Algoritma yang digunakan adalah linear searching, yang diterapkan pada fungsi linearSearch. Main program akan meminta pengguna menginput rasa yang ingin dicari. Program memanggil fungsi linearSearch untuk mencari rasa eskrim yang dimasukkan oleh pengguna. Program juga menggunakan fungsi tolower sehingga setiap perbandingan yang dilakukan, kedua elemen akan dikonversikan melalui fungsi transform(). Ini bertujuan agar penggunaan kapital atau tidak tetap bisa terbaca sebagai satu elemen yang sama. Jika rasa eskrim ditemukan, program mencetak pesan bahwa rasa eskrim tersebut tersedia. Jika tidak, program mencetak pesan bahwa rasa eskrim tersebut tidak tersedia.

#### Output:

![Screenshot 2024-04-01 120905](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/19e81056-6da2-4d4e-9a1e-a9473ee398db)

#### Full Screenshot

![Screenshot 2024-04-01 120916](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/2ed0a1a7-b169-4630-a775-1f88282f5359)

## 3.Tulislah sebuah fungsi program dengan kondisi sebagai berikut: Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari! 

```C++
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


```

Program tersebut dibuat untuk mencari kata. Program menggunakan algoritma binary searching di dalam fungsi searchString. Fungsi ini mencari indeks dari kata yang dicari (target) dalam array terurut yang terdapat string kosong. Jika elemen tengah adalah string kosong, fungsi mencari elemen non-kosong terdekat di kedua arah (kiri dan kanan). Setelah menemukan elemen non-kosong, fungsi membandingkan kata yang dicari dengan elemen ini dan menyesuaikan batas pencarian (low dan high) sesuai dengan hasil perbandingan. Fungsi memanggil dirinya sendiri secara rekursif hingga menemukan kata yang dicari atau hingga pencarian tidak dapat dilakukan lagi (low melebihi high).
Pada fungsi main, array diinisialisasi terurut. kemudia meminta pengguna memasukkan kata yang ingin dicari. Kemudian memanggil fungsi searchString untuk mencari kata dalam array dan menampilkan hasil pencarian. Karena menggunaan array, maka indeks akan dimulai dari 0.

![Screenshot 2024-03-25 104628](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/1da6da1f-e9da-4230-ab4d-39379d3e1bc4)
![Screenshot 2024-03-25 104712](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/f1a81068-d7df-4440-b4ed-c81a4f8afe5b)
![Screenshot 2024-03-25 104720](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/7960d35e-647e-4544-b068-98c106939801)

#### Full Screenshot

![Screenshot 2024-03-25 104745](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/00b15a05-3857-4ff4-b661-487969c97c42)


