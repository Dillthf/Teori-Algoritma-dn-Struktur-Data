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
