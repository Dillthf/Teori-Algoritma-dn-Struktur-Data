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
