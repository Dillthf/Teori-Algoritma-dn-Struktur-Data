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
