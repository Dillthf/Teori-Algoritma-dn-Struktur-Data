#include <iostream>
using namespace std;

// Definisi struktur untuk data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    float nilai;
};

// Definisi konstanta untuk ukuran maksimum stack
const int maksimal = 7;

// Deklarasi stack dan top
Mahasiswa arrayMahasiswa[maksimal];
int top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayMahasiswa(string nama, string nim, float nilai) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayMahasiswa[top] = {nama, nim, nilai};
        top++;
    }
}

void popArrayMahasiswa() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        top--;
        cout << "Data mahasiswa dengan NIM " << arrayMahasiswa[top].nim << " dihapus dari stack\n";
    }
}

void peekArrayMahasiswa(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top - posisi;
        if (index >= 0 && index < top) {
            cout << "Posisi ke " << posisi << " adalah " 
                 << "Nama: " << arrayMahasiswa[index].nama << ", "
                 << "NIM: " << arrayMahasiswa[index].nim << ", "
                 << "Nilai: " << arrayMahasiswa[index].nilai << endl;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    }
}

int countStack() {
    return top;
}

void changeArrayMahasiswa(int posisi, string nama, string nim, float nilai) {
    int index = top - posisi;
    if (index >= 0 && index < top) {
        arrayMahasiswa[index] = {nama, nim, nilai};
    } else {
        cout << "Posisi tidak valid" << endl;
    }
}

void destroyArrayMahasiswa() {
    for (int i = 0; i < top; i++) {
        arrayMahasiswa[i] = {"", "", 0.0};
    }
    top = 0;
}

void cetakArrayMahasiswa() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << "Nama: " << arrayMahasiswa[i].nama << ", "
                 << "NIM: " << arrayMahasiswa[i].nim << ", "
                 << "Nilai: " << arrayMahasiswa[i].nilai << endl;
        }
    }
}

int main() {
    pushArrayMahasiswa("Mahen", "18395764", 85.5);
    pushArrayMahasiswa("Haikal", "18395478", 88.9);
    pushArrayMahasiswa("Jono", "18395381", 82.3);
    pushArrayMahasiswa("Reyhan", "18395182", 97.4);
    pushArrayMahasiswa("Jeman", "18395208", 80.0);
    pushArrayMahasiswa("Cahyo", "18395201", 87.4);
    pushArrayMahasiswa("Icung", "18395117", 90.0);

    cetakArrayMahasiswa();
    cout << "\n";

    cout << "Apakah data stack penuh? " << (isFull() ? "Ya" : "Tidak") << endl;
    cout << "Apakah data stack kosong? " << (isEmpty() ? "Ya" : "Tidak") << endl;

    peekArrayMahasiswa(2);
    popArrayMahasiswa();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayMahasiswa(3, "Juan", "18395012", 88.2);
    cetakArrayMahasiswa();

    cout << "\n";
    destroyArrayMahasiswa();
    cout << "Jumlah data setelah dihapus: " << countStack() << endl;

    cetakArrayMahasiswa();

    return 0;
}
