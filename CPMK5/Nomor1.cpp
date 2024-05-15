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
