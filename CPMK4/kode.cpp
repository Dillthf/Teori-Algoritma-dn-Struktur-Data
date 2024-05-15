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
  band favorit
  {
    /* data */
  };
   favorit;

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
