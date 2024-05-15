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
