# <h1 align="center">Tugas 3</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Berikan penjelasan dan contoh program(beserta penjelasan alur program) dari masing-masing materi struktur data berikut:
### a.	Priority Queue
### b.	Hash Table
### c.	Rekursif
### d.	Graph & Tree
 

## a. Priority Queue


Priority queue adalah struktur data yang menyimpan elemen berdasarkan nilai prioritasnya. Elemen dengan prioritas tertinggi akan dihapus lebih dulu. Priority queue digunakan untuk menyimpan node yang akan dikunjungi dalam algoritma pencarian terbaik, dengan prioritas diberikan pada node yang memiliki nilai heuristik lebih tinggi [1].
Ketika priority queue pertama kali dibuat, konstruktor dipanggil dengan parameter keamanan λ yang diinginkan. Setelah itu, priority queue mendukung operasi-operasi berikut [2]

- ref ← Insert(k, v): Menyisipkan nilai v dengan kunci k ke dalam priority queue, dan mengembalikan referensi (handle) ke elemen yang disisipkan, yang disebut ref.
- • (k, v,ref) ← FindMin(): Mengembalikan item dengan kunci terkecil (item minimum) dalam priority queue tanpa menghapusnya.
- Delete(ref): Menghapus item yang diidentifikasi oleh referensi ref dari priority queue.
- • (k, v) ← ExtractMin(): Menghapus dan mengembalikan item minimum dari priority queue.


#### Kode Program

``` C++
#include <iostream>
#include <algorithm>
using namespace std;

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n, value;
    cout << "Masukkan jumlah elemen untuk dimasukkan ke heap: ";
    cin >> n;

    cout << "Masukkan elemen-elemen:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insert(value);
    }

    cout << "Queue Prioritas: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Node dengan prioritas maksimum: " << extractMax() << "\n";

    cout << "Queue prioritas setelah mengekstrak maksimum: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Masukkan indeks dan prioritas baru untuk changePriority: ";
    int index, newPriority;
    cin >> index >> newPriority;
    changePriority(index, newPriority);
    cout << "Queue prioritas setelah perubahan prioritas: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Masukkan indeks untuk dihapus: ";
    cin >> index;
    remove(index);
    cout << "Queue prioritas setelah menghapus elemen: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    return 0;
}


```

Program berjalan dengan mendeklarasikan array dengan nama H untuk menyimpan elemen heap dan "heapSize" untuk melacak ukuran heap. Untuk mendapatkan indeks parent dari elemen, program menggunakan fungsi "int parent(int i)". Untuk mendapatkan indeks anak kiri dari elemen, menggunakan fungsi "int leftChild(int i). Begitupun sebaliknya, untuk mendapatkan indeks anak kanan elemen, menggunakan fungsi "int rightChild(int i)".

Untuk menggeser elemen, baik ke atas dan ke bawah agar heap property terpenuhi, program menggunakan fungsi shiftUp dan shiftDown. Fungsi shiftUp berjalan dengan memeriksa elemen parent dengan elemen saat ini. Jika elemen parent lebih kecil daripada elemen saat ini, elemen parent ditukar dengan elemen saat ini. Kemudian, indeks akan dipindahkan ke parent untuk memeriksa heap property berikutnya. Sedangkan, fungsi shiftDown berjalan dengan mendapatkan indeks anak kiri dan kanan melalui leftChild dan rightChild, lalu diperiksa apakah  anak kiri dan anak kanan lebih besar dari elemen saat ini. Jika  anak kiri dan kanan lebih besar dari elemen saat ini, set maxIndex ke anak kiri dan set maxIndex ke anak kanan. Jika maxIndex bukan elemen saat ini, elemen saat ini ditukar dengan elemen maxIndex. Pada baris berikutnya adalah rekursi untuk menggeser ke bawah pada maxIndexselan. Indeks dipindahkan ke parent untuk periksa heap property berikutnya. 

Untuk menyisipkan elemen ke dalam heap, menggunakan fungsi insert. Awalnya, ukuran heap aan ditambah. Kemudian elemen baru dimasukkan di akhir heap. Dan elemen tersebut digeser ke atas unutk menjaga heap property.

Untuk mengekstrak elemen maksimum dari heap, menggunakan fungsi extractMax. Elemen maksimum adalah elemen pada indeks 0 di array. Elemen terakhir dipindahkan ke posisi root. Setelah ukuran heap dikurangi, elemen digeser ke bawah untuk menjaga heap property.

Untuk mengubah prioritas elemen pad indeks i ke p, menggunakan fungsi changePriority. Elemen prioritas diubah. Jika prioritas baru lebih besar, maka elemen akan digeser ke atas. Namun, jika prioritas baru ebih kecil atau sama, elemen akan digeser ke bawah.

Untuk mendapatkan elemen maksimum dari heap tanpa menghapus, menggunakan getMax. Jika elemen maksimum adalah elemen di indeks 0. Dan untuk menghapus elemen pada indkes i dari heap, menggunakan fungsi remove. Dengan menaikkan prioritas elemen menjadi lebih tinggi dari maksimum dan elemen digeser ke atas. Kemudian ekstrak elemen maksimum (elemen yang dihapus).

Fungsi utama program, untuk memasukkan jumlah elemen yang dimasukkan ke heap, memasukkan elemen-elemen tersebut, menampilkan priority queue, menampilkan node dengan prioritas maksimum, menampilkan priority queue setelah mengekstarak maksimum, memasukkan indeks dan elemen baru untuk diubah, menampilkan priority queue setelah diubah, memasukkan indeks untuk dihapus, dan menampilkan priority queue setelah dihapus.


## b. Hash Table

Hash table adalah struktur data yang memudahkan proses pencarian nilai berdasarkan kunci. Ini menghindari pencarian kunci secara berurutan dengan langsung mengambil nilai yang sesuai. Hash table menggunakan fungsi hash untuk mengonversi kunci menjadi indeks, kemudian menyimpan nilai yang sesuai pada entri array di indeks tersebut. Dengan kunci hash, pencarian dilakukan dengan mengubah kunci tersebut menjadi indeks melalui fungsi hash dan langsung mengakses entri array pada indeks yang sesuai [3]. Struktur hash table memiliki keunggulan luar biasa: sebagian besar operasinya memiliki waktu konstan (diamortisasi, rata-rata, dll.), dengan kompleksitas teoretis O(1) [4].
Dalam C++, operasi pada hash table mencakup berbagai tugas untuk pengelolaan data yang efisien [5]:

- Insertion: Menambahkan pasangan kunci dan nilai ke dalam hash table.
- Search: Menemukan nilai berdasarkan kunci yang diberikan.
- Deletion: Menghapus pasangan kunci dan nilai sesuai kebutuhan.
- Resizing: Menyesuaikan ukuran hash table untuk meningkatkan kinerja.
-Collision Handling: Mengelola situasi di mana beberapa kunci dipetakan ke indeks yang sama.
- Load Factor Maintenance: Memastikan keseimbangan optimal antara jumlah elemen dan ukuran tabel.
- Traversal: Melakukan iterasi melalui pasangan kunci dan nilai untuk mengakses atau memproses data.
- Clearing: Mengosongkan hash table dengan menghapus semua elemen.


#### Kode program 

```C++
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


```
Kode program menggunakan hash table untuk menyimpan data mahasiswa berdasarkan NIM dan Nilai. Program menyediakan beberapa fungsi yang ditampilkan pada menu awal.

 Program menyediakan fungsi menambahkan, menggunanakan fungsi insert. fungsi akan menghitung indeks hash menggunakan hashFunc. Kemudian memeriksa apakah NIM sudah ada di indeks tersebut. Jika ada, nilai diperbarui. Jika tidak ada, data baru ditambahkan ke vector pada indeks tersebut.

 Fungsi selanjutnya adalah menghapus data mahasiswa berdasarkan NIM menggunakan fungsi remove dengan menghitung indeks hash menggunakan hashFunc. Fungsi mencari dan menghapus elemen yang sesuai di vector pada indeks tersebut. 

 Fungsi pencarian berdasarkan NIM diinisialisasikan dengan fungsi searchByNim. Fungsi menghitung indeks hash menggunakan hashFunc. Setekah itu mencari elemen yang sesuai di vector pada indeks tersebut.

 Fungsi yang terakhhir mencari data mahasiswa berdasarkan rentang nilai. Fungsi akan memeriksa semua elemen di seluruh hash table dan mengumpulkan elemen yang nilai mereka berada dalam rentang yang ditentukan.



## Rekursif

Ketika sebuah fungsi memanggil dirinya sendiri, itu disebut panggilan rekursif. Menurut Sianpar, metode rekursif adalah metode yang memanggil dirinya sendiri baik secara langsung maupun tidak langsung. Kata "rekursif" berarti "memiliki sifat kembali atau berulang." Dalam konteks ini, pemanggilan fungsi diulangi oleh fungsi itu sendiri. Jenis rekursi ini sering disebut rekursi langsung karena fungsi tersebut secara langsung memanggil dirinya sendiri. Selain itu, ada jenis rekursi lain yang disebut rekursi tidak langsung. Rekursi tidak langsung terjadi ketika fungsi A memanggil fungsi B, dan kemudian fungsi B memanggil kembali fungsi A, sehingga melibatkan rekursi tidak langsung.
Ketika sebuah fungsi rekursif memanggil dirinya sendiri, memori untuk panggilan fungsi baru dialokasikan di atas memori untuk fungsi pemanggil, dan salinan variabel lokal yang berbeda dibuat untuk setiap panggilan. Ketika kasus dasar tercapai, fungsi mengembalikan nilainya kepada fungsi pemanggil, yang kemudian melanjutkan eksekusi sambil melepaskan memori yang digunakan. Kekurangan dari program rekursif adalah memerlukan ruang yang lebih besar dibandingkan program iteratif karena semua panggilan fungsi tetap ada di tumpukan sampai kasus dasar tercapai. Program rekursif juga memerlukan lebih banyak waktu karena ada overhead dari pemanggilan dan pengembalian fungsi. Namun, kelebihan rekursi adalah menyediakan cara yang bersih dan sederhana untuk menulis kode. [6]

#### Kode Program

``` C++
#include <iostream>
using namespace std;

// Deklarasi fungsi-fungsi yang saling memanggil
int faktorialB(int n);

int faktorialA(int n) {
    if (n <= 1) {
        return 1; // Basis rekursi
    } else {
        return n * faktorialB(n - 1); // Panggilan rekursi ke fungsi B
    }
}

int faktorialB(int n) {
    return faktorialA(n); // Panggilan rekursi ke fungsi A
}

int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;
    
    if (num < 0) {
        cout << "Bilangan harus positif." << endl;
    } else {
        int hasil = faktorialA(num); // Memulai rekursi dari fungsi A
        cout << "Faktorial dari " << num << " adalah: " << hasil << endl;
    }

    return 0;
}


```
Program ini menggunakan rekursi tidak langsung untuk menghitung faktorial dari sebuah bilangan bulat positif yang dimasukkan oleh pengguna. Program dimulai dan meminta pengguna untuk memasukkan bilangan bulat positif. Saat pengguna memasukkan bilangan, program mengecek apakah bilangan tersebut positif. Jika bilangan negatif, program mencetak pesan kesalahan dan selesai. Jika bilangan positif atau nol, program melanjutkan untuk menghitung faktorial. Program mendefinisikan dua fungsi, faktorialA dan faktorialB, yang saling memanggil secara rekursif untuk menghitung faktorial dari bilangan tersebut. FaktorialA menerima satu argumen integer n. Kemudian ,embuat kondisi basis dari rekursi: jika n kurang dari atau sama dengan 1, fungsi mengembalikan nilai 1.
Jika n lebih besar dari 1, eksekusi blok berikutnya: return n * faktorialB(n - 1).
Ini mengembalikan hasil perkalian n dengan hasil pemanggilan rekursif faktorialB(n - 1), mengurangi nilai n secara berulang hingga mencapai kondisi basis. FaktorialB juga menerima satu argumen integer n dan memanggil faktorialA(n) secara rekursif.
Fungsi utama yang akan dieksekusi saat program dijalankan adalah, awalnya, variabel num dideklarasikan untuk menyimpan input dari pengguna.Fungsi mencetak pesan untuk meminta input dari pengguna dan membaca input tersebut, menyimpannya ke dalam variabel num. Pada kondisi if (num < 0), program mengecek apakah nilai num kurang dari 0. Jika num kurang dari 0, fungsi mencetak pesan kesalahan bahwa bilangan harus positif.Jika num tidak kurang dari 0, eksekusi blok berikutnya:
Fungsi faktorialA dipanggil dengan argumen num dan menyimpan hasilnya ke dalam variabel hasil. Di akhir, program mencetak hasil perhitungan faktorial.

## Graph & Tree

### A. Graph

Teori Graf merupakan salah satu
metode yang digunakan untuk menyelesaikan permasalahan diskrit yang ada,
misalnya merepresentasikan objek–objek
diskrit dan hubungan antara objek–objek
tersebut [7]. Graf G terdiri dari dua himpunan, yaitu himpunan V dan himpunan E. Vertex (simpul) adalah himpunan V, yang merupakan himpunan simpul terbatas dan tidak kosong. Edge (sisi/ruas) adalah himpunan E, yang merupakan himpunan busur atau garis yang menghubungkan pasangan simpul. Simpul pada graf biasanya diidentifikasi dengan huruf atau angka, sementara sisi biasanya dinamai dengan himpunan simpul yang dihubungkannya. Simpul-simpul pada graf bisa berupa objek sembarang seperti nama kota, komponen elektronik, dan sebagainya. Busur dapat menunjukkan hubungan sembarang, seperti rute penerbangan, jalan raya, sambungan telepon, jalur data, dan lainnya [8]. 
```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int dill_2311110048;
    cout << "Silahkan masukan jumlah simpul: ";
    cin >> dill_2311110048;

    vector<string> namaSimpul(dill_2311110048);
    for (int i = 0; i < dill_2311110048; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> namaSimpul[i];
    }

    vector<vector<int>> horanghae(dill_2311110048, vector<int>(dill_2311110048, 0));
    for (int i = 0; i < dill_2311110048; i++) {
        for (int j = 0; j < dill_2311110048; j++) {
            cout << namaSimpul[i] << " --> " << namaSimpul[j] << " = ";
            cin >> horanghae[i][j];
        }
    }

    cout << endl;
    cout << "Bobot simpul:" << endl;
    cout << "  ";
    for (int i = 0; i < dill_2311110048; i++) {
        cout << namaSimpul[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < dill_2311110048; i++) {
        cout << namaSimpul[i] << " ";
        for (int j = 0; j < dill_2311110048; j++) {
            cout << horanghae[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```
Program ini memungkinkan pengguna untuk memasukkan graf berbobot dengan jumlah simpul yang ditentukan. Program ini meminta pengguna untuk memberikan nama setiap simpul dan bobot (berat) antara setiap pasangan simpul, kemudian menampilkan matriks bobot tersebut. 
Program akan meminta pengguna untuk memasukkan jumlah simpul  yang akan ada dalam graf dan menyimpannya dalam variabel dill_2311110048. Dengan perulangan, pengguna akan memasukkan nama setiap simpul dan menympannya dalam vektor namaSimpul. Alur berikutnya adalah menggunakan perulangan bersarang untuk meminta pengguna memasukkan bobot untuk setiap pasangan simpul (i, j) dan menyimpannya dalam matriks 2D yang diberi nama horanghae. Di akhir, program menampilkan nama-nama simpul di baris pertama dan dengan perulangan menampilkan setiap baris dari matriks bobot, dengan nama simpul di kolom pertama dan bobot yang sesuai.


### B. Tree

Konsep pohon (tree) adalah salah satu yang paling terkenal dan signifikan dalam teori graf, karena mampu menyelesaikan berbagai masalah terapan dalam graf. Misalnya, konsep pohon merentang (Spanning Tree) digunakan oleh perusahaan kereta api untuk menentukan jalur kereta dengan biaya minimum. Ketika konsep spanning tree diterapkan untuk menemukan bobot minimum pada sebuah graf berbobot, itu dikenal sebagai MST (Minimum Spanning Tree) [9]. Ada berbagai jenis pohon (tree) serta cabang ilmu lain yang berkaitan dengan jenis-jenis pohon tersebut. Salah satunya adalah pohon biner (binary tree). Jenis pohon ini memiliki ciri khas di mana setiap parent hanya memiliki dua anak [10].  


``` C++
#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int dill_2311110048) {
        data = dill_2311110048;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void displayChild(TNode *node, int target) {
    if (node != NULL) {
        if (node->data == target) {
            if (node->left != NULL) {
                cout << "Child: " << node->left->data << endl;
            }
            if (node->right != NULL) {
                cout << "Child: " << node->right->data << endl;
            }
        } else {
            displayChild(node->left, target);
            displayChild(node->right, target);
        }
    }
}

void displayDescendant(TNode *node, int target) {
    if (node != NULL) {
        if (node->data == target) {
            preOrder(node);
        } else {
            displayDescendant(node->left, target);
            displayDescendant(node->right, target);
        }
    }
}

TNode* findNode(TNode* node, int target) {
    if (node == NULL) {
        return NULL;
    }
    if (node->data == target) {
        return node;
    }
    TNode* leftResult = findNode(node->left, target);
    if (leftResult != NULL) {
        return leftResult;
    }
    return findNode(node->right, target);
}

void addNode(TNode*& root) {
    int parentData, childData;
    char position;
    cout << "Masukkan data parent node: ";
    cin >> parentData;
    cout << "Masukkan data child node: ";
    cin >> childData;
    cout << "Masukkan posisi child (L/R): ";
    cin >> position;

    if (root == NULL) {
        root = new TNode(childData);
        cout << "Root node created with data: " << childData << endl;
        return;
    }

    TNode* parentNode = findNode(root, parentData);
    if (parentNode != NULL) {
        if (position == 'L' || position == 'l') {
            if (parentNode->left == NULL) {
                parentNode->left = new TNode(childData);
            } else {
                cout << "Left child already exists for node " << parentData << endl;
            }
        } else if (position == 'R' || position == 'r') {
            if (parentNode->right == NULL) {
                parentNode->right = new TNode(childData);
            } else {
                cout << "Right child already exists for node " << parentData << endl;
            }
        } else {
            cout << "Invalid position. Use 'L' for left or 'R' for right." << endl;
        }
    } else {
        cout << "Parent node with data " << parentData << " not found." << endl;
    }
}

int main() {
    TNode* root = NULL;

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Tambah node" << endl;
        cout << "2. Tampilkan tree" << endl;
        cout << "3. Tampilkan child" << endl;
        cout << "4. Tampilkan descendant" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addNode(root);
                break;
            case 2:
                cout << "Pre Order: ";
                preOrder(root);
                cout << endl;
                cout << "In Order: ";
                inOrder(root);
                cout << endl;
                cout << "Post Order: ";
                postOrder(root);
                cout << endl;
                break;
            case 3: {
                int target;
                cout << "Masukkan node target: ";
                cin >> target;
                displayChild(root, target);
                break;
            }
            case 4: {
                int target;
                cout << "Masukkan node target: ";
                cin >> target;
                displayDescendant(root, target);
                cout << endl;
                break;
            }
            case 5:
                cout << "Keluar." << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (choice != 5);

    return 0;
}

```
 Program ini dibuatuntuk mengelola dan menampilkan sebuah pohon biner (binary tree) dinamis. Pengguna dapat menambahkan node ke dalam pohon, serta menampilkan pohon dengan berbagai urutan traversal (pre-order, in-order, post-order), menampilkan child node dari suatu node, dan menampilkan seluruh descendant dari suatu node.
Program menginisialisasi root pohon sebagai NULL lalu menampilkan menu berulang kali hingga pengguna memilih untuk keluar. 

 Saat pengguna memilih pilihan 1, maka alur program akan meminta data node parent, data node child, dan posisi child (kiri/kanan). Jika root NULL, membuat node root dengan data child. Jika parent ditemukan, menambah child pada posisi yang sesuai jika belum ada child di posisi tersebut.

 Jika pengguna memilih pilihan 2, maka program akan menampilkan tree dalam berbagai traversal: pre-order, in-order, dan post-order. 

 Sementara itu, jika pengguna memilih untuk menampilkan child maupun descendant, maka program akan meminta pengguna memasukkan nilai node target kemudian menampilkan child node dari target node atau menampilkan seluruh descendant dari target node menggunakan pre-order traversal.



## Referensi 

[1]  T. Liu and X. Li, "Priority Queues in Machine Learning," arXiv preprint arXiv:2102.02015, 2021.

[2] Elaine Shi, "Path Oblivious Heap: Optimal and Practical
Oblivious Priority Queue," IEEE. 2020. DOI 10.1109/SP40000.2020.00037

[3]  Issariyakul, T., Hossain, E.Introduction to Network Simulator NS2. Jerman: Springr US. 2008.

[4] Santiago T. "Key Concepts, Weakness and Benchmark on Hash Table Data Structures" .(n.p). 2022

[5] Manish Bhojasia. C++ Program to Implement Hash Table  [Online]. Available: https://www.sanfoundry.com/cpp-program-implement-hash-tables/#google_vignette.

[6] Shofwan H., Wayan J. Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Edisi I. Yogyakarta:Andi. 2020.

[7] F. Daniel and P. N. L. Taneo, Teori Graf. Yogyakarta, Indonesia: Deepublish, 2019.

[8]  Z. Ramadhan, M. Zarlis, S. Efendi, and A. P. U. Siahaan, "Perbandingan 
Algoritma Prim dengan Algoritma Floyd-Warshall dalam Menentukan 
Rute Terpendek (Shortest Path Problem)," Jurnal Riset Komputer 
(JURIKOM), vol. 5, no. 2, pp. 136-139, Apr. 2018. [Online]. 

[9] H. Lubis and D. B. Srisulistiowati, "Algoritma Prim dan Kruskal dalam Mencari Minimum Spanning Tree pada Bahasa Pemrograman C," vol. 8, no. 2, 2021.

[10] H. Septian, I. Suhartini, I. P. N, L. A. Jihad, N. Lia, and T. F. A., "Implementasi Struktur Data Tree pada Game Pacman dengan C," JURNAL DIGIT, vol. 11, no. 2, pp. 120-129, Nov. 2021.