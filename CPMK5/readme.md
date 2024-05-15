# <h1 align="center">Evaluasi CPMK Sub-CPMK 5</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## 1.	Buatlah sebuah fungsi program untuk menghilangkan duplikasi data pada unsorted linked list (single atau double atau circular) 

```C++
#include <iostream>
#include <unordered_set>

using namespace std;

// Definisi struktur untuk node pada singly linked list
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Fungsi untuk menambahkan node baru di akhir linked list
void append(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new Node(data);
}

// Fungsi untuk menghilangkan duplikasi data pada unsorted linked list
void hapusDuplikat(Node* head) {
    if (!head) return;

    unordered_set<int> seen;
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (seen.find(current->data) != seen.end()) {
            // Jika data sudah ada di set, hapus node saat ini
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            // Jika data belum ada di set, tambahkan ke set
            seen.insert(current->data);
            prev = current;
            current = current->next;
        }
    }
}

// Fungsi untuk mencetak linked list
void cetakList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Fungsi utama untuk pengujian
int main() {
    Node* head = nullptr;

    append(head, 60);
    append(head, 45);
    append(head, 78);
    append(head, 90);
    append(head, 60);
    append(head, 56);
    append(head, 78);

    cout << "Linked List awal : " << endl;
    cetakList(head);

    hapusDuplikat(head);

    cout << "Linked List setelah dihapus duplikat : " << endl;
    cetakList(head);

    return 0;
}

```
Prgoram ini menggunakan single linked list. Awalnya, program mendefinisikan struktur node dengan dua elemen, yaitu data untuk menyimpan nilai, dan next untuk pointer ke node berikutnya. Fungsi pertama adalah fungsi append, untuk menambahkan node baru di akhir linked list. Jika linked list kosong (head adalah nullptr), buat node baru dan set head ke node tersebut. Jika linked list tidak kosong, iterasi hingga akhir list dan tambahkan node baru di akhir. 
Fungsi selanjutnya adalah fungsi hapusDuplikat. Fungsi ini menghilangkan node dengan data duplikat. Jika linked list kosong, keluar dari fungsi. Buat unordered_set untuk menyimpan data yang sudah ditemukan. Iterasi melalui linked list dengan dua pointer (current dan prev). Jika data node saat ini (current) sudah ada dalam set, hapus node tersebut dengan mengubah next pointer dari prev. Jika data node saat ini belum ada dalam set, tambahkan data tersebut ke set dan lanjutkan ke node berikutnya.
Untuk menampilkan isi linked list sebelum dan sesudah duplikat dihapus, program menggunakan fungsi cetakList. Fungsi utamanya adalah membuat linked list dan tambahkan beberapa node (beberapa dengan nilai duplikat). Mencetak linked list sebelum penghapusan duplikat. Memanggil fungsi hapusDuplikat untuk menghapus node duplikat.
Mencetak kembali linked list setelah penghapusan duplikat.


## 2. Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list! 

```C++
#include <iostream>

using namespace std;

// Definisi struktur untuk node pada single linked list
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Fungsi untuk menambahkan node baru di akhir linked list
void append(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new Node(data);
}

// Fungsi untuk menghapus node di tengah linked list
void deleteMiddle(Node*& head) {
    if (!head) return;
    if (!head->next) {
        // Hanya ada satu node, hapus node tersebut
        delete head;
        head = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    while (fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // 'slow' sekarang menunjuk ke node tengah
    // 'prev' adalah node sebelum node tengah
    if (prev) {
        prev->next = slow->next;
        delete slow;
    }
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Fungsi utama untuk pengujian
int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "Linked List sebelum menghapus node tengah: " << endl;
    printList(head);

    deleteMiddle(head);

    cout << "Linked List setelah menghapus node tengah: " << endl;
    printList(head);

    return 0;
}
 ```


Secara sederhana, algoritma program ini berupa menginisialisasi dua pointer yaitu slow dan fast. Mulai keduanya dari head. Slow digeser satu langkah setiap iterasi dan fast dua langkah setiap iterasi. Ketika fast mencapai akhir, slow akan berada di node tengah. Jika linked list hanya memiliki satu node, langsung hapus node tersebut, jika lebih dari satu node, temukan node sebelum slow untuk mengubah pointer next dari node tersebut ke node setelah slow.
Hapus node slow.
Program akan menampilkan linked list sebelum dan setelah menghapus node tengah, menunjukkan bagaimana linked list berubah setelah operasi penghapusan. Untuk pengecekan awal, jika linked list kosong (head adalah nullptr), fungsi langsung keluar. Jika linked list hanya memiliki satu node, node tersebut dihapus dan head diset ke nullptr. Untuk menemukan node tengah, digunakan dua pointer, slow dan fast. fast bergerak dua kali lebih cepat dari slow, sehingga ketika fast mencapai akhir, slow berada di node tengah. Dan untuk menghapus, prev adalah node sebelum slow. Setelah menemukan node tengah (slow), node sebelum slow (prev) diatur ulang agar menunjuk ke node setelah slow. Node slow dihapus menggunakan delete.


#### Output:

![Screenshot 2024-04-01 120905](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/19e81056-6da2-4d4e-9a1e-a9473ee398db)

#### Full Screenshot

![Screenshot 2024-04-01 120916](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/2ed0a1a7-b169-4630-a775-1f88282f5359)

## 3.	Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! 

```C++
#include <iostream>
using namespace std;

// Definisi struktur untuk node pada singly linked list
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Fungsi untuk menambahkan node baru di akhir linked list
void append(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new Node(data);
}

// Fungsi untuk membalik linked list
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Fungsi untuk memeriksa apakah linked list adalah palindrom
bool isPalindrome(Node* head) {
    if (!head || !head->next) {
        return true;
    }

    // Temukan titik tengah linked list
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Balikkan separuh kedua linked list
    Node* secondHalf = reverse(slow);
    Node* firstHalf = head;

    // Bandingkan dua setengah linked list
    Node* secondHalfCopy = secondHalf; // Simpan untuk membalik kembali nanti
    while (secondHalf) {
        if (firstHalf->data != secondHalf->data) {
            reverse(secondHalfCopy); // Balikkan kembali sebelum return false
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Kembalikan separuh kedua ke bentuk asli
    reverse(secondHalfCopy);
    return true;
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Fungsi utama untuk pengujian
int main() {
    Node* head = nullptr;

    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 3);
    append(head, 2);
    append(head, 1);

    cout << "Linked List: " << endl;
    printList(head);

    if (isPalindrome(head)) {
        cout << "Linked list adalah palindrom" << endl;
    } else {
        cout << "Linked list bukan palindrom" << endl;
    }

    return 0;
}
```

Program bekerja dengan alur pertama yatu menemukan titik tengah linked list. Digunakan dua pointer (slow dan fast). slow bergerak satu langkah setiap iterasi, sedangkan fast bergerak dua langkah setiap iterasi. Ketika fast mencapai akhir, slow berada di titik tengah. Kemudian, membalikkan setengah linked list dari titik tengah. Mulai dari slow, balikkan linked list dari titik tengah ke akhir. Setelah itu, elemen-elemen dari awal linked list hingga titik tengah dengan elemen-elemen dari akhir hingga tengah yang telah dibalik dibandingan. Terakhir, balikkan kembali separuh kedua ke bentuk aslinya untuk mengembalikan linked list ke keadaan semula (opsional). Jika kedua setengah sama, linked list adalah palindrom; jika tidak, bukan palindrom.
Alur ini diimplementasikan ke beberapa fungsi, yaitu fungsi append, fungsi reverse, fungsi isPalindrome, fungsi printlist, dan fungsi main. Fungsi append untuk menambahkan node baru di akhir linked list. Fungsi reverse untuk embalik linked list dan mengembalikan pointer ke head dari linked list yang dibalik. Fungsi isPalindrome untuk menemukan titik tengah linked list menggunakan dua pointer. Membalik separuh kedua dari linked list mulai dari titik tengah. Membandingkan dua setengah linked list. Mengembalikan linked list ke bentuk aslinya setelah pemeriksaan (opsional). Mengembalikan true jika linked list adalah palindrom, false jika tidak.
Fungsi printList untuk mencetak linked list. Dan fungsi main untuk menguji fungsi dengan linked list contoh dan mencetak hasilnya.
![Screenshot 2024-03-25 104628](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/1da6da1f-e9da-4230-ab4d-39379d3e1bc4)
![Screenshot 2024-03-25 104712](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/f1a81068-d7df-4440-b4ed-c81a4f8afe5b)
![Screenshot 2024-03-25 104720](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/7960d35e-647e-4544-b068-98c106939801)

#### Full Screenshot

![Screenshot 2024-03-25 104745](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/00b15a05-3857-4ff4-b661-487969c97c42)

