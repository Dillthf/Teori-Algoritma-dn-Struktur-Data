#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

class HashNode {
public:
    int nim;
    float nilai;

    HashNode(int nim, float nilai) {
        this->nim = nim;
        this->nilai = nilai;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int nim, float nilai) {
        int hash_val = hashFunc(nim);

        for (auto node : table[hash_val]) {
            if (node->nim == nim) {
                node->nilai = nilai;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(nim, nilai));
    }

    void remove(int nim) {
        int hash_val = hashFunc(nim);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->nim == nim) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    float searchByNim(int nim) {
        int hash_val = hashFunc(nim);
        for (auto node : table[hash_val]) {
            if (node->nim == nim) {
                return node->nilai;
            }
        }
        return -1;
    }

    vector<HashNode*> searchByNilai(float nilai_min, float nilai_max) {
        vector<HashNode*> result;
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (auto node : table[i]) {
                if (node->nilai >= nilai_min && node->nilai <= nilai_max) {
                    result.push_back(node);
                }
            }
        }
        return result;
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->nim << ", " << pair->nilai << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap mahasiswa_map;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tambah data mahasiswa" << endl;
        cout << "2. Hapus data mahasiswa" << endl;
        cout << "3. Cari data mahasiswa berdasarkan NIM" << endl;
        cout << "4. Cari data mahasiswa berdasarkan rentang nilai" << endl;
        cout << "5. Keluar" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            int nim;
            float nilai;
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan nilai: ";
            cin >> nilai;
            mahasiswa_map.insert(nim, nilai);
            cout << "Data berhasil ditambahkan" << endl;
        } else if (choice == 2) {
            int nim;
            cout << "Masukkan NIM: ";
            cin >> nim;
            mahasiswa_map.remove(nim);
            cout << "Data berhasil dihapus" << endl;
        } else if (choice == 3) {
            int nim;
            cout << "Masukkan NIM: ";
            cin >> nim;
            float nilai = mahasiswa_map.searchByNim(nim);
            if (nilai != -1) {
                cout << "Nilai mahasiswa dengan NIM " << nim << " adalah " << nilai << endl;
            } else {
                cout << "Data tidak ditemukan" << endl;
            }
        } else if (choice == 4) {
            float nilai_min, nilai_max;
            cout << "Masukkan nilai minimum: ";
            cin >> nilai_min;
            cout << "Masukkan nilai maksimum: ";
            cin >> nilai_max;
            vector<HashNode*> result = mahasiswa_map.searchByNilai(nilai_min, nilai_max);
            if (!result.empty()) {
                cout << "Data mahasiswa dengan nilai antara " << nilai_min << " dan " << nilai_max << ":" << endl;
                for (auto node : result) {
                    cout << "NIM: " << node->nim << " Nilai: " << node->nilai << endl;
                }
            } else {
                cout << "Tidak ada data yang ditemukan" << endl;
            }
        } else if (choice == 5) {
            break;
        } else {
            cout << "Menu tidak valid" << endl;
        }
    }

    return 0;
}