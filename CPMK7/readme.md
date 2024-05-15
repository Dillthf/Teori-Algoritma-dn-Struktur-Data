# <h1 align="center">Evaluasi CPMK Sub-CPMK 7</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## 1. Tulislah sebuah program dari operasi queue seperti enqueue/add, dequeue/remove, isEmpty, isFull, dll(min 5)!  

```C++
##include <iostream>
using namespace std;

const int maxQueueSize = 10; // Ukuran maksimum queue

class Queue {
private:
    int front;
    int rear;
    int count;
    int queueArray[maxQueueSize];

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == maxQueueSize);
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Antrian penuh, tidak dapat menambah nomor antrian.\n";
        } else {
            rear = (rear + 1) % maxQueueSize;
            queueArray[rear] = data;
            count++;
            cout << "Nomor antrian " << data << " telah ditambahkan.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong, tidak ada nomor antrian yang dihapus.\n";
        } else {
            cout << "Nomor antrian " << queueArray[front] << " telah dihapus.\n";
            front = (front + 1) % maxQueueSize;
            count--;
        }
    }

    int getFront() {
        if (!isEmpty()) {
            return queueArray[front];
        } else {
            cout << "Antrian kosong.\n";
            return -1;
        }
    }

    int getCount() {
        return count;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong.\n";
        } else {
            cout << "Nomor antrian saat ini: ";
            for (int i = 0; i < count; i++) {
                int index = (front + i) % maxQueueSize;
                cout << queueArray[index] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue antrian;

    antrian.enqueue(101);
    antrian.enqueue(102);
    antrian.enqueue(103);
    antrian.enqueue(104);
    antrian.enqueue(105);

    antrian.printQueue();

    cout << "Nomor antrian di depan: " << antrian.getFront() << endl;

    antrian.dequeue();
    antrian.printQueue();

    cout << "Jumlah nomor antrian saat ini: " << antrian.getCount() << endl;

    antrian.enqueue(106);
    antrian.enqueue(107);
    antrian.enqueue(108);
    antrian.enqueue(109);
    antrian.enqueue(110);
    antrian.enqueue(111); // Harus menunjukkan bahwa antrian penuh

    antrian.printQueue();

    return 0;
}

```
Program ini bertujuan untuk membuat nomor antrian masuk sebuah museum. Pada awal baris program, diinisialisasi front, rear, dan count dengan nilai awal. Fungsi berikutnya adalah isEmpty() yang akan mengembalikan true jika antrian kosong (count == 0), false jika sebaliknya. Sebaliknya, fungsi isFull() mengembalikan true jika antrian penuh (count == maxQueueSize), false jika sebaliknya.
Fungsi enqueue(int data)bertujuan menambahkan elemen baru (data) ke dalam antrian. Fungsi akan memeriksa apakah antrian penuh. Jika tidak penuh, rear ditambah dan disimpan di queueArray[rear]. Kemudian mencetak pesan bahwa elemen baru telah ditambahkan.
Fungsi dequeue() bertujuan menghapus elemen terdepan dari antrian. Hampir mirip dengan alur enqueue, fungsi terlebih dahulu memeriksa apakah antrian kosong. Jika tidak kosong, elemen terdepan (queueArray[front]) dicetak. Kemudian mencetak pesan bahwa elemen terdepan telah dihapus.
Fungsi getFront() bertujuan mengembalikan elemen terdepan dari antrian (nilai queueArray[front]), atau -1 jika antrian kosong.
Funsi getCount() bertujuan mengembalikan jumlah elemen yang ada di dalam antrian (count).
printQueue() bertujuan mencetak isi antrian saat ini.
Fungsi utama program adalah menciptakan objek antrian dari class Queue. Memasukkan beberapa nomor antrian (enqueue) ke dalam antrian. Mencetak isi antrian menggunakan printQueue().
Mencetak nomor antrian terdepan menggunakan getFront(). Menghapus elemen terdepan (dequeue) dan mencetak isi antrian lagi. Mencetak jumlah elemen saat ini menggunakan getCount().
Mencoba memasukkan beberapa nomor antrian lagi, salah satunya akan menunjukkan pesan antrian penuh karena melebihi maxQueueSize. Mencetak isi antrian setelah mencoba enambahkan elemen melebihi batas.
### ss



## 2. Sebuah selter hewan terlantar, yang mana hanya menerima kucing dan anjing, menerapkan konsep “first in, first out” dalam proses adopsi. Orang-orang yang hendak mengadopsi harus mengikuti aturan berikut: 1) mengadopsi hewan yang paling “tua” (berdasarkan waktu masuk ke selter) dan tidak dapat memilih kucing atau anjing; 2) memilih antara kucing atau anjing, namun akan menerima yang paling tua. Buatlah data struktur untuk mengimplementasikan kondisi tersebut, silahkan menggunakan beberapa operasi queue seperti enquee, dequeueAny, dequeueDog, dan dequeueCat.



```C++
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Definisikan struktur untuk hewan yang diadopsi
struct Hewan {
    string jenis;
    int waktuMasuk;
};

class AdopsiHewan {
private:
    queue<Hewan> antrianKucing;
    queue<Hewan> antrianAnjing;

public:
    // Fungsi untuk menambahkan hewan ke antrian sesuai jenisnya
    void enqueue(string jenis, int waktuMasuk) {
        Hewan hewan = {jenis, waktuMasuk};
        if (jenis == "Kucing") {
            antrianKucing.push(hewan);
        } else if (jenis == "Anjing") {
            antrianAnjing.push(hewan);
        } else {
            cout << "Jenis hewan tidak valid!" << endl;
        }
    }

    // Fungsi untuk mengadopsi hewan tertua dari antrian
    Hewan dequeueAny() {
        Hewan hewan;
        if (antrianKucing.empty() && antrianAnjing.empty()) {
            cout << "Antrian kosong!" << endl;
        } else if (antrianKucing.empty()) {
            hewan = antrianAnjing.front();
            antrianAnjing.pop();
        } else if (antrianAnjing.empty()) {
            hewan = antrianKucing.front();
            antrianKucing.pop();
        } else {
            if (antrianKucing.front().waktuMasuk < antrianAnjing.front().waktuMasuk) {
                hewan = antrianKucing.front();
                antrianKucing.pop();
            } else {
                hewan = antrianAnjing.front();
                antrianAnjing.pop();
            }
        }
        return hewan;
    }

    // Fungsi untuk mengadopsi kucing tertua
    Hewan dequeueCat() {
        Hewan hewan;
        if (antrianKucing.empty()) {
            cout << "Antrian kucing kosong!" << endl;
        } else {
            hewan = antrianKucing.front();
            antrianKucing.pop();
        }
        return hewan;
    }

    // Fungsi untuk mengadopsi anjing tertua
    Hewan dequeueDog() {
        Hewan hewan;
        if (antrianAnjing.empty()) {
            cout << "Antrian anjing kosong!" << endl;
        } else {
            hewan = antrianAnjing.front();
            antrianAnjing.pop();
        }
        return hewan;
    }
};

int main() {
    AdopsiHewan adopsiHewan;

    // Menambahkan beberapa hewan ke dalam antrian
    adopsiHewan.enqueue("Kucing", 1);
    adopsiHewan.enqueue("Anjing", 2);
    adopsiHewan.enqueue("Kucing", 3);
    adopsiHewan.enqueue("Anjing", 4);

    // Menu untuk pengguna
    int pilihan;
    do {
        cout << "\nMenu Adopsi Hewan Terlantar:" << endl;
        cout << "1. Adopsi Hewan Tertua (Kucing atau Anjing)" << endl;
        cout << "2. Adopsi Kucing Tertua" << endl;
        cout << "3. Adopsi Anjing Tertua" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                Hewan hewan = adopsiHewan.dequeueAny();
                if (hewan.jenis != "") {
                    cout << "Hewan yang diadopsi: " << hewan.jenis << " (masuk pada waktu: " << hewan.waktuMasuk << ")" << endl;
                }
                break;
            }
            case 2: {
                Hewan hewan = adopsiHewan.dequeueCat();
                if (hewan.jenis != "") {
                    cout << "Kucing yang diadopsi: " << " (masuk pada waktu: " << hewan.waktuMasuk << ")" << endl;
                }
                break;
            }
            case 3: {
                Hewan hewan = adopsiHewan.dequeueDog();
                if (hewan.jenis != "") {
                    cout << "Anjing yang diadopsi: " << " (masuk pada waktu: " << hewan.waktuMasuk << ")" << endl;

                }
                break;
            }
            case 4: {
                cout << "Keluar dari program." << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}
 ```

Program ini bertujuan untuk mensimulasikan proses adopsi hewan dari sebuah shelter hewan terlantar yang hanya menerima kucing dan anjing.
Program dimulai dengan mendefinisikan struktur data Hewan yang memiliki dua atribut: jenis (string) dan waktuMasuk (integer). Atribut jenis digunakan untuk menunjukkan jenis hewan (kucing atau anjing), sedangkan waktuMasuk digunakan untuk menyimpan waktu kapan hewan tersebut masuk ke dalam shelter. Program selanjutnya mendefinisikan kelas AdopsiHewan yang berisi operasi-operasi yang terkait dengan adopsi hewan, seperti enqueue, dequeueAny, dequeueCat, dan dequeueDog. Fungsi enqueue digunakan untuk menambahkan hewan baru ke dalam antrian (queue) sesuai dengan jenisnya. Jika jenis hewan yang dimasukkan adalah kucing, maka hewan tersebut dimasukkan ke dalam antrian kucing. Begitu juga dengan anjing. Fungsi dequeueAny digunakan untuk mengeluarkan hewan tertua dari antara antrian kucing dan anjing. Pertama, fungsi ini memeriksa apakah antrian kucing atau anjing kosong. Jika salah satu antrian kosong, maka fungsi akan mengeluarkan hewan dari antrian yang tidak kosong. Jika kedua-duanya tidak kosong, maka fungsi akan membandingkan waktu masuk hewan terdepan pada kedua antrian dan mengeluarkan yang paling tua. Fungsi dequeueCat digunakan untuk mengeluarkan kucing tertua dari antrian kucing. Fungsi dequeueDog digunakan untuk mengeluarkan anjing tertua dari antrian anjing. Di dalam fungsi utama, pengguna diberikan menu untuk memilih jenis adopsi yang ingin dilakukan. Pengguna dapat memilih untuk mengadopsi hewan tertua (kucing atau anjing), kucing tertua, atau anjing tertua. Setelah pengguna memilih, program akan menampilkan hewan yang diadopsi beserta waktu masuknya.