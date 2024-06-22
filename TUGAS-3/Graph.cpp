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