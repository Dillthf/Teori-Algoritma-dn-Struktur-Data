# <h1 align="center">Evaluasi CPMK Sub-CPMK 6</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## 1.	Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)! 

```C++
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


```
Program ini mengimplementasikan konsep stack untuk menyimpan data mahasiswa yang terdiri dari nama, NIM, dan nilai. Program membuat struct bernama Mahasiswa  yang berisi informasi nama, nim, dan nilai. Program menddklarasikan maksimal kapasitas stack adalah 7. Kemudian untuk menyimpan elemen stack, digunakan array yang diberi nama arrayMahasiswa. Fungsi pertama adalah fungsi isFull, untuk mengecek apakah stack sudah penuh. Stack dianggap penuh jika top sama dengan maksimal. Fungsi berikuntya adalah ismpty, untuk mengecek apakah stack kosong. Stack dianggap kosong jika top sama dengan 0. Fungsi ketiga yang digunakan adalah pushArrayMahasiswa, untuk menambahkan elemen baru ke stack. Jika stack penuh, fungsi akan mencetak pesan bahwa data telah penuh. Jika tidak, elemen baru ditambahkan ke array di posisi top, dan top akan bertambah satu. Fungsi berikutnya adalah popArrayMahasiswa, untuk menghapus elemen teratas dari stack. Jika stack kosong, fungsi akan mencetak pesan "Tidak ada data yang dihapus". Jika tidak, top akan berkurang satu dan menghapus data teratas. Fungsi berikutnya adalah countSatck, untuk mengembalikan jumlah elemen dalam stack, yaitu nilai dari top. Selanjutnya fungsi destroyArrayMahasiswa, untuk menghapus semua elemen dalam stack dengan mengatur ulang nilai-nilai dalam array dan mengatur top menjadi 0. Kemudian, fugsi cetakArrayMahasiswa, untuk  mencetak semua elemen dalam stack. Jika stack kosong, fungsi akan mencetak pesan "Tidak ada data yang dicetak". Jika tidak, fungsi akan mencetak setiap elemen dari atas ke bawah.
Fungsi utama program sendiri menambahkan beberapa data mahasiswa ke stack menggunakan pushArrayMahasiswa, mencetak stack, mengecek status penuh atau kosong dari stack, melihat data di posisi tertentu dengan peekArrayMahasiswa, menghapus elemen teratas dengan popArrayMahasiswa, mengganti data di posisi tertentu dengan changeArrayMahasiswa, dan akhirnya menghapus semua data dalam stack menggunakan destroyArrayMahasiswa. Program mencetak informasi setelah setiap operasi untuk menunjukkan status stack.

#### Output

![Screenshot 2024-05-15 074921](https://github.com/Dillthf/Teori-Algoritma-dn-Struktur-Data/assets/161497877/08cc2eac-7839-43bb-a275-525505e9fb85)

#### Full Screenshot

![Screenshot 2024-05-15 074941](https://github.com/Dillthf/Teori-Algoritma-dn-Struktur-Data/assets/161497877/c6b803dc-ec1b-4231-8c8c-17df260e7b5e)

## 2.	Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array.  Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty. 

```C++
#include <iostream>
#include <stack>

using namespace std;

// Fungsi untuk menambah elemen ke stack dalam urutan yang tepat
void sortedInsert(stack<float>& s, float x) {
    // Jika stack kosong atau elemen teratas lebih besar dari x, masukkan x
    if (s.empty() || x < s.top()) {
        s.push(x);
    } else {
        // Jika elemen teratas lebih kecil dari x, pindahkan elemen ke stack sementara
        float temp = s.top();
        s.pop();
        sortedInsert(s, x);
        s.push(temp);
    }
}

// Fungsi untuk mensortir stack
void sortStack(stack<float>& s) {
    // Jika stack tidak kosong
    if (!s.empty()) {
        // Ambil elemen teratas
        float x = s.top();
        s.pop();
        // Sortir stack yang tersisa secara rekursif
        sortStack(s);
        // Masukkan elemen yang diambil kembali ke stack dengan urutan yang tepat
        sortedInsert(s, x);
    }
}

// Fungsi untuk mencetak stack
void printStack(stack<float>& s) {
    stack<float> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() {
    stack<float> s;
    s.push(0.34);
    s.push(3.90);
    s.push(42.78);
    s.push(56.22);
    s.push(100.67);
    s.push(15.64);

    cout << "Stack sebelum diurutkan: ";
    printStack(s);

    sortStack(s);

    cout << "Stack setelah diurutkan: ";
    printStack(s);

    return 0;
}
 ```

Program ini mengurutkan elemen-elemen dalam sebuah stack sehingga elemen terkecil selalu berada di posisi teratas. Program menggunakan konsep rekursi dan sebuah stack sementara untuk mencapai tujuan ini tanpa menggunakan struktur data lain seperti array.
Pada baris awal program, dibuat fungsi untuk memasukkan elemen x ke dalam stack s dalam urutan yang tepat. Jika stack s kosong atau elemen x lebih kecil dari elemen teratas stack, langsung masukkan x ke dalam stack.Jika elemen x lebih besar dari elemen teratas stack, keluarkan elemen teratas dan panggil sortedInsert secara rekursif untuk menemukan posisi yang tepat bagi x. Masukkan kembali elemen yang dikeluarkan tadi ke dalam stack.
Fungsi berikutnya adalah sortStack, yang berfungsi mengurutkan seluruh elemen dalam stack s. Jika stack s tidak kosong, ambil elemen teratas dan panggil sortStack secara rekursif untuk mengurutkan sisa elemen dalam stack. Setelah stack diurutkan, masukkan kembali elemen yang diambil tadi ke dalam stack menggunakan sortedInsert.
Fungsi berikutnya adalah printStack untuk mencetak elemen-elemen dalam stack dari yang teratas hingga terbawah. Menggunakan stack sementara temp untuk mencetak elemen-elemen dari stack asli tanpa mengubahnya.
Fungsi utama program adalah inisialisasi stack s dan tambahkan beberapa elemen float ke dalamnya.  Cetak stack s sebelum diurutkan untuk menampilkan keadaan awal stack. Panggil fungsi sortStack(s) untuk mengurutkan stack s. Cetak stack s setelah diurutkan untuk menampilkan hasil akhir dari pengurutan.

#### Output

![Screenshot 2024-05-15 074952](https://github.com/Dillthf/Teori-Algoritma-dn-Struktur-Data/assets/161497877/b289c285-2317-4f40-b2b2-6865c7bc35a9)

#### Full Screenshot

![Screenshot 2024-05-15 075029](https://github.com/Dillthf/Teori-Algoritma-dn-Struktur-Data/assets/161497877/cec8d566-1b07-4020-ab76-6551b0413c3c)
