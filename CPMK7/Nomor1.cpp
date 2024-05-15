#include <iostream>
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
