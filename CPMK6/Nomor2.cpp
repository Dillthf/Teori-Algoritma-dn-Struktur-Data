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
