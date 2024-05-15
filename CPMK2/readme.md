# <h1 align="center">Evaluasi CPMK Sub-CPMK 2</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## 1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! 
### 1. Bubble Sort
#### Alur
 Algoritma pengurutan bubble sort berjalan dengan cara membendingkan elemen satu dengan elemen lain disampingnya. Algoritma ini akan menggeser elemen jika berada di urutan yang salah (ururtan disesuaikan, apakah descending atau ascending). Proses ini diulangi untuk setiap elemen yang terdapat pada array.
#### Runtime
  - Best case O(n): terjadi jika array sudah terurut. Hanya perlu satu pass tanpa ada pertukaran.
  - Worst case O(n^2): terjadi jika array tidak terurut atau terurut secara terbalik. Perlu membandingkan dan menukar setiap elemen dalam setiap array.
### 2. Selection Sort
#### Alur
 Algoritma pengurutan selection sort berjalan dengan cara mencari nilai tertinggi / terendah di dalam array kemudian menempatkan nilai tersebut di tempat semestinya. Algorithma ini dapat mengurutkan data dari besar ke kecil (Ascending) dan kecil ke besar (Descending).
#### Runtime
  - Best case O(n): terjadi karena selalu membandingkan setiap elemen dengan elemen lainnya, terlepas dari urutan array.
  - Worst case O(n^2): terjadi karena harus mencari elemen terkecil dari bagian yang belum terurut di setiap iterasi.
### 2. Merge Sort
#### Alur
  Algoritma Merge sort sebenarnya sederhana, bagi larik menjadi dua sama besar, urutkan bagian pertama, urutkan bagian kedua,lalu gabungkan. Merge sort bekerja dengan langkah memilah elemen menjadi dua bagian dan mengulangi pemilihan sehingga satu elemen terdiri maksimal dua nilai (divide). Kemudian, masing-masing elemen diurutkan (conquer). Terakhir, kombinasikan dua bagian tersebut secara rekursif untuk mendapatkan rangkaian data berurutan. Proses rekursi berhenti jika mencapai elemen dasar. Hal ini terjadi bilamana bagian yang akan diurutkan menyisakan tepat satu elemen. Sisa pengurutan satu elemen tersebut menandakan bahwa bagian tersebut telah terurut sesuai rangkaian.
#### Runtime
  - Best case  O(n log n): terjadi karena selalu membagi array menjadi dua dan menggabungkannya kembali.array.
  - Worst case O(n log n): sama seperti best case, karena algoritma ini selalu membagi array menjadi dua dan menggabungkannya kembali, terlepas dari urutan awal array.

## 2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut

```C++
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

 ```


Program ini menggunakan algoritma Bubble Sort untuk kasus mengurutkan nama warga Pak RT. Fungsi "bubble_sort" menerima dua parameter: "arr" (array nama warga) dan "n" (jumlah warga). Fungsi ini menggunakan perulangan "for" untuk mengurutkan nama warga menggunakan algoritma Bubble Sort. Setelah proses sorting selesai, nama warga akan terurut sesuai dengan alfabet.
Kompleksitas waktu kode di atas dapat diklasifikasikan menjadi O(n^2), dimana n merupakan jumlah elemen dalam array. Algoritma Bubble Sort membutuhkan waktu yang lambat ketika jumlah elemen dalam array meningkat. Karena perulangan yang dilakukan dalam algoritma Bubble Sort, kompleksitas waktu akan meningkat seiring dengan jumlah elemen dalam array.


#### Output:

![Screenshot 2024-04-01 120905](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/19e81056-6da2-4d4e-9a1e-a9473ee398db)

#### Full Screenshot

![Screenshot 2024-04-01 120916](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/2ed0a1a7-b169-4630-a775-1f88282f5359)

## 3.	Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram” 

```C++
#include <iostream>
#include <algorithm>
using namespace std;

// Fungsi untuk mengurutkan string
void sortString(string& str) { // Mendefinisikan fungsi sortString untuk mengurutkan string
    sort(str.begin(), str.end()); // Menggunakan fungsi sort untuk mengurutkan string str dari karakter pertama hingga terakhir
}

// Fungsi untuk mengecek apakah dua string adalah anagram
bool cekAnagram(string str1, string str2) { // Mendefinisikan fungsi cekAnagram untuk memeriksa apakah dua string adalah anagram satu sama lain
    // Jika ukuran kedua string tidak sama, pasti bukan anagram
    if (str1.size() != str2.size()) { //Memeriksa apakah panjang (jumlah karakter) dari str1 dan str2 sama. Jika berbeda, maka bukan anagram.
        return false;
    }

    // Mengurutkan kedua string str1 dan str2 menggunakan fungsi sortString yang telah didefinisikan sebelumnya.
    sortString(str1);
    sortString(str2);

    // Membandingkan elemen yang sudah diurutkan
    return str1 == str2;
}

int main() {
    string string1, string2; // Deklarasikan dua variabel string, string1 dan string2, untuk menyimpan input pengguna.

    // Input untuk string1 dan string2
    cout << "Masukkan kata pertama : ";
    cin >> string1;
    cout << "Masukkan kata kedua : ";
    cin >> string2;

    // Mengecek apakah string1 dan string2 adalah anagram
    if (cekAnagram(string1, string2)) {
        cout << "Dua kata tersebut  anagram" << endl;
    } else {
        cout << "Dua kata tersebut tidak anagram" << endl;
    }

    return 0; // Program selesai
}


```

Program tersebut dibuat untuk mengecek apakah kedua kata yang diinput pengguna merupakan anagram. Dua kata yang diinput, teridentifikasi sebagai string. Kemudian, program memeriksan dengan cara yang pertama yaitu kesamaan kedua string. Jika sama, kedua string akan diurutkan dan dibandingkan. Setelah diurutkan dan dibandingkan, kedua string tetap sama, maka program akan menampilkan bahwa kedua kata tersebut adalah anagram. 

![Screenshot 2024-03-25 104628](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/1da6da1f-e9da-4230-ab4d-39379d3e1bc4)
![Screenshot 2024-03-25 104712](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/f1a81068-d7df-4440-b4ed-c81a4f8afe5b)
![Screenshot 2024-03-25 104720](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/7960d35e-647e-4544-b068-98c106939801)

#### Full Screenshot

![Screenshot 2024-03-25 104745](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/00b15a05-3857-4ff4-b661-487969c97c42)


## 4.	Tulislah sebuah fungsi program dengan asumsi sebagai berikut: Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut! 


```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Fungsi untuk menggabungkan dua array terurut
void mergeSorting(string A[], int x, string B[], int z) {
    // Indeks akhir dari A dan B
    int akhirA = x - 1;   // Indeks terakhir dari elemen valid dalam array A
    int akhirB = z - 1;   // Indeks terakhir dari elemen dalam array B
    // Indeks akhir dari array A setelah penggabungan
    int gabunganAkhir = x + z - 1; // Indeks terakhir dari array A setelah digabung dengan B

    // Menggabungkan A dan B dari belakang ke depan
    while (akhirA >= 0 && akhirB >= 0) { // Perulangan berjalan selama masih ada elemen di kedua array
        if (A[akhirA] > B[akhirB]) { // Jika elemen terakhir di A lebih besar dari elemen terakhir di B
            A[gabunganAkhir] = A[akhirA]; // Tempatkan elemen A di posisi terakhir dari hasil gabungan
            akhirA--; // Kurangi indeks A
        } else {
            A[gabunganAkhir] = B[akhirB]; // Jika elemen terakhir di B lebih besar atau sama dengan elemen di A, tempatkan elemen B di posisi terakhir dari hasil gabungan
            akhirB--; // Kurangi indeks B
        }
        gabunganAkhir--; // Kurangi indeks gabungan
    }

    // Jika ada elemen yang tersisa di B, salin ke A
    while (akhirB >= 0) { // Jika masih ada elemen tersisa di B (A sudah habis)
        A[gabunganAkhir] = B[akhirB]; // Elemen B ke posisi terakhir gabungan
        akhirB--; // Kurangi indeks B
        gabunganAkhir--; // Kurangi indeks gabungan
    }
}

int main() {
    // Contoh penggunaan fungsi
    string A[16] = {"S-Coups", "Jeonghan", "Joshua", "Jun", "Hoshi", "Wonwoo", "Woozi"}; // Array A dengan kapasitas lebih untuk menampung B
    string B[6] = {"DK", "Mingyu", "The8", "Seungkwan", "Vernon", "Dino"}; // Array B

    int x = 7; // Jumlah elemen valid dalam A (mengubah jumlah elemen yang benar dalam A)
    int z = 6; // Jumlah elemen dalam B

    // Mengurutkan array A dan B terlebih dahulu
    sort(A, A + x);
    sort(B, B + z);

    mergeSorting(A, x, B, z); // Panggil fungsi untuk menggabungkan A dan B

    // Menampilkan hasil array A setelah penggabungan
    for (int i = 0; i < x + z; i++) { // Perulangan melalui seluruh elemen dalam array gabungan
        cout << A[i] << " "; // Cetak elemen A
    }

    return 0; // Program selesai
}

```
 Kode diatas dimaksudkan untuk membuat suatu program yang akan menggabungkan dua array berbeda. Array utama (A), mempunyai ruang lebih yang akan digunakan untuk menampung elemen yang ada pada array B. Pada contoh penggunaan program, array A mempunyai kapasitas sebesar 16 elemen, namun diisi sebanyak 7 elemen saja. Kapasitas di array A yang tersisa 9, akan diisi oleh elemen B sebanyak 6 eleme. Program dibuat untuk menampung array bertipe data string, sehingga array yang telah digabungkan akan diurutkan sesuai abjad.
#### Output:

![Screenshot 2024-03-25 111102](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/e3799a98-fcd4-4169-ac6c-2d4eb8ba0414)

#### Full Screenshot
![Screenshot 2024-03-25 111125](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/1eb7f2b2-b92d-46b9-a5ca-c0e17f2c5f14)


