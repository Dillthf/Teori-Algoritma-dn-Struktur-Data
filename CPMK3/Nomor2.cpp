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
