#include <iostream>
#include <string>

using namespace std;

// Struktur untuk data nasabah
struct Nasabah {
    int nomorRekening;
    string nama;
    double saldo;
    Nasabah* next;
    int NPM[15] = {2, 3, 1, 0, 6, 3, 1, 1, 7, 0, 1, 5, 6};
};

// Fungsi untuk menambahkan data nasabah
void tambahNasabah(Nasabah*& head, int nomorRek, const string& nama, double saldo) {
    Nasabah* baru = new Nasabah;
    baru->nomorRekening = nomorRek;
    baru->nama = nama;
    baru->saldo = saldo;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Nasabah* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Data nasabah berhasil ditambahkan.\n";
}

// Fungsi untuk menampilkan seluruh data nasabah
void tampilkanNasabah(Nasabah* head) {
    Nasabah* temp = head;
    while (temp != nullptr) {
        cout << "Nomor Rekening: " << temp->nomorRekening << endl;
        cout << "Nama: " << temp->nama << endl;
        cout << "Saldo: " << temp->saldo << endl << endl;
        temp = temp->next;
    }
}

// Fungsi untuk mencari data nasabah berdasarkan nomor rekening
void cariNasabah(Nasabah* head, int nomorRek) {
    Nasabah* temp = head;
    while (temp != nullptr) {
        if (temp->nomorRekening == nomorRek) {
            cout << "Data nasabah ditemukan:\n";
            cout << "Nomor Rekening: " << temp->nomorRekening << endl;
            cout << "Nama: " << temp->nama << endl;
            cout << "Saldo: " << temp->saldo << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Data nasabah dengan nomor rekening " << nomorRek << " tidak ditemukan.\n";
}

// Fungsi untuk menghapus data nasabah berdasarkan nomor rekening
void hapusNasabah(Nasabah*& head, int nomorRek) {
    Nasabah* curr = head;
    Nasabah* prev = nullptr;

    while (curr != nullptr && curr->nomorRekening != nomorRek) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Data nasabah dengan nomor rekening " << nomorRek << " tidak ditemukan.\n";
        return;
    }

    if (prev == nullptr) {
        head = curr->next;
    } else {
        prev->next = curr->next;
    }
    delete curr;
    cout << "Data nasabah berhasil dihapus.\n";
}

int main() {
    Nasabah* head = nullptr;
    int pilihan, nomorRek;
    string nama;
    double saldo;

    do {
        cout << "\n===== Program Manajemen Data Nasabah Bank =====\n";
        cout << "1. Tambah Data Nasabah\n";
        cout << "2. Tampilkan Data Nasabah\n";
        cout << "3. Cari Data Nasabah\n";
        cout << "4. Hapus Data Nasabah\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nomor Rekening: ";
                cin >> nomorRek;
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Saldo: ";
                cin >> saldo;
                tambahNasabah(head, nomorRek, nama, saldo);
                break;
            case 2:
                tampilkanNasabah(head);
                break;
            case 3:
                cout << "Masukkan Nomor Rekening yang Ingin Dicari: ";
                cin >> nomorRek;
                cariNasabah(head, nomorRek);
                break;
            case 4:
                cout << "Masukkan Nomor Rekening yang Ingin Dihapus: ";
                cin >> nomorRek;
                hapusNasabah(head, nomorRek);
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 0);

    // Bersihkan memori linked list
    Nasabah* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
