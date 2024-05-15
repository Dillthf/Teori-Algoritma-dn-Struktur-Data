# <h1 align="center">Evaluasi CPMK Sub-CPMK 4</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct!
### Penjelasan Struct
Struktur adalah kumpulan item data (bidang) atau variabel dari tipe data berbeda yang direferensikan dengan nama yang sama. Ini menyediakan cara yang mudah untuk menyimpan informasi terkait bersama-sama. Kata kunci struct memberi tahu kompiler bahwa templat struktur sedang ditentukan, yang dapat digunakan untuk membuat variabel struktur. Bidang-bidang yang membentuk struktur disebut anggota atau elemen struktur. Semua elemen dalam suatu struktur secara logis berhubungan satu sama lain.
## Contoh Program
```C++
#include <iostream>

using namespace std;

// Mendefinisikan struct buku dengan array
struct band {
  string namaBand[6];
  string albumFavorit[6];
  string laguFavorit[6];
  int jumlahPersonil[6];
};

int main() {
  // Mendeklarasikan variabel favorit dengan tipe band
  string favorit;

  // Mengisi data ke dalam array dalam variabel favorit
  favorit.namaBand[0] = "Day6";
  favorit.namaBand[1] = "The Rose";
  favorit.namaBand[2] = "Xdinary Heroes";
  favorit.namaBand[3] = "Mrs. GREEN APPLE";
  favorit.namaBand[4] = "Vierratale";
  favorit.namaBand[5] = "Coldplay";

  favorit.albumFavorit[0] = "Shoot Me: Youth Part 1";
  favorit.albumFavorit[1] = "Dual";
  favorit.albumFavorit[2] = "Livelock";
  favorit.albumFavorit[3] = "Attitude";
  favorit.albumFavorit[4] = "My First Love";
  favorit.albumFavorit[5] = "A Rush of Blood To The Head";

  favorit.laguFavorit[0] = "Somehow";
  favorit.laguFavorit[1] = "Back to me";
  favorit.laguFavorit[2] = "Pluto";
  favorit.laguFavorit[3] = "Inferno";
  favorit.laguFavorit[4] = "Rasa ini";
  favorit.laguFavorit[5] = "The Scientist";

  favorit.jumlahPersonil[0] = 3;
  favorit.jumlahPersonil[1] = 4;
  favorit.jumlahPersonil[2] = 6;
  favorit.jumlahPersonil[3] = 5;
  favorit.jumlahPersonil[4] = 3;
  favorit.jumlahPersonil[5] = 4;


  // Menampilkan informasi band favorit
  cout << "\tDaftar Band Favorit Saya" << endl;
  for (int i = 0; i < 6; i++) {
    cout << "\n\tBand ke-" << i + 1 << endl;
    cout << "\tNama Band : " << favorit.namaBand[i] << endl;
    cout << "\tAlbum Favorit  : " << favorit.albumFavorit[i] << endl;
    cout << "\tLagu Favorit : " << favorit.laguFavorit[i] << endl;
    cout << "\tJumlah Personil: " << favorit.jumlahPersonil[i] << " orang" << endl;
  }

  return 0;
}

```

Program ini menyimpan informasi mengenai band favorit dalam bentuk struct. Pada baris awal, struct band didefinisikan untuk menyimpan informasi tentang beberapa band favorit. dalam struct band terdapat array berupa namaBand, albumFavorit, laguFavorit, dan jumlahPersonil untuk menyimpan data. Setiap array akan berisi 6 elemen. Program menggunakan array karena dengan array, memungkinkan penyimpanan data dalam bentuk yang terstruktur dan terorganisir, memudahkan pengelolaan data.
 Di dalam fungsi utama, dideklarasikan variabel favorit. Kemudian, baris berikutnya adalah pengisian data secara terurut satu persatu sesuai nama array dan indeksnya. Program menggunakan perulangan for untuk menampilkan informasi keenam band tersebut.

#### Output

![Screenshot 2024-05-14 230626](https://github.com/Dillthf/Teori-Algoritma-dn-Struktur-Data/assets/161497877/2b402893-154e-408d-be52-a342155d9800)

![Screenshot 2024-05-14 230803](https://github.com/Dillthf/Teori-Algoritma-dn-Struktur-Data/assets/161497877/ff7d6fb6-e904-4ff9-a8fc-887c81e99a7a)

![Screenshot 2024-05-14 231818](https://github.com/Dillthf/Teori-Algoritma-dn-Struktur-Data/assets/161497877/0ad8bc89-4d38-4195-81fd-2d9d44c650cb)

![Screenshot 2024-05-14 231854](https://github.com/Dillthf/Teori-Algoritma-dn-Struktur-Data/assets/161497877/8cedd04e-7b48-4a62-b068-c7db275af063)

![Screenshot 2024-05-14 231908](https://github.com/Dillthf/Teori-Algoritma-dn-Struktur-Data/assets/161497877/e6ef43e4-7c01-4c77-833a-72fb7a1eabbc)

#### Full Screenshot

![Screenshot 2024-05-15 052211](https://github.com/Dillthf/Teori-Algoritma-dn-Struktur-Data/assets/161497877/834d2d10-5b24-4a53-b2d2-f3e78b8fe21d)


