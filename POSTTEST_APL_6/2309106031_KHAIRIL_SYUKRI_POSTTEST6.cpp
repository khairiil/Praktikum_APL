#include <iostream>
#include <limits> 
using namespace std;

// Struct untuk menyimpan waktu dengan jam dan menit
struct Waktu {
    string jam, menit;
};

// Struct untuk menyimpan detail acara
struct Acara {
    string kegiatan;
    Waktu waktu;
};

// Fungsi untuk memvalidasi inputan angka
int validasiInputAngka() {
    int input;
    while (!(cin >> input)) {
        cout << "Input Tidak Valid. Harap Masukkan Angka.\n";
        cin.clear(); // Menghapus flag error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    return input;
}

// Fungsi untuk memperbarui acara
void perbaruiAcara(Acara rundown[], int* indeks, int jumlahAcara) {
    // Memperbarui acara
    if (rundown[0].kegiatan == "") {
        cout << "\nRundown Acara Kosong.\n";
    } else {
        cout << "\nMasukkan Nomor Acara Yang Ingin Diperbarui: ";
        *indeks = validasiInputAngka();

        if (*indeks > 0 && *indeks <= jumlahAcara && rundown[*indeks - 1].kegiatan != "") {
            cout << "\nNama Acara: ";
            getline(cin, rundown[*indeks - 1].kegiatan);
            cout << "Waktu Acara (jam): ";
            rundown[*indeks - 1].waktu.jam = to_string(validasiInputAngka());
            cout << "Waktu Acara (menit): ";
            rundown[*indeks - 1].waktu.menit = to_string(validasiInputAngka());
            cout << "Acara Berhasil Diperbarui\n";
        } else {
            cout << "\nNomor Acara Tidak Valid.\n";
        }
    }
}

// Fungsi untuk menghapus acara
void hapusAcara(Acara rundown[], int* indeks, int* jumlahAcara) {
    // Menghapus acara
    if (rundown[0].kegiatan == "") {
        cout << "\nRundown Acara Kosong.\n";
    } else {
        cout << "\nMasukkan Nomor Acara Yang Ingin Dihapus: ";
        *indeks = validasiInputAngka();
        if (*indeks > 0 && *indeks <= *jumlahAcara && rundown[*indeks - 1].kegiatan != "") {
            // Hapus acara yang dipilih
            rundown[*indeks - 1].kegiatan = "";
            rundown[*indeks - 1].waktu.jam = "0";
            rundown[*indeks - 1].waktu.menit = "0";
            cout << "Acara Berhasil Dihapus\n";
            // Menggeser acara jika diperlukan
            for (int i = *indeks - 1; i < *jumlahAcara - 1; ++i) {
                rundown[i] = rundown[i + 1];
            }
            // Hapus acara terakhir yang duplikat
            rundown[*jumlahAcara - 1].kegiatan = "";
            rundown[*jumlahAcara - 1].waktu.jam = "0";
            rundown[*jumlahAcara - 1].waktu.menit = "0";
            *jumlahAcara -= 1; // Kurangi jumlah acara setelah penghapusan
        } else {
            cout << "\nNomor Acara Tidak Valid.\n";
        }
    }
}

// Fungsi untuk menampilkan rundown acara
void tampilkanRundownAcara(Acara rundown[], int jumlahAcara) {
    if (rundown[0].kegiatan == "") {
        cout << "\nRundown Acara Kosong.\n";
    } else {
        cout << "Rundown Acara:\n";
        for (int i = 0; i < jumlahAcara; ++i) {
            if (rundown[i].kegiatan != "") {
                cout << "Acara " << i + 1 << ":\n";
                cout << "Nama: " << rundown[i].kegiatan << endl;
                cout << "Waktu: " << rundown[i].waktu.jam << ":" << rundown[i].waktu.menit << endl << endl;
            }
        }
    }
}

// Fungsi untuk sorting huruf secara ascending (Bubble Sort)
void bubbleSortAscHuruf(Acara rundown[], int jumlahAcara) {
    for (int i = 0; i < jumlahAcara - 1; ++i) {
        for (int j = 0; j < jumlahAcara - i - 1; ++j) {
            if (rundown[j].kegiatan > rundown[j + 1].kegiatan) {
                Acara temp = rundown[j];
                rundown[j] = rundown[j + 1];
                rundown[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk sorting waktu (Jam) secara descending (Selection Sort)
void selectionSortDescJam(Acara rundown[], int jumlahAcara) {
    for (int i = 0; i < jumlahAcara - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < jumlahAcara; ++j) {
            if (rundown[j].waktu.jam > rundown[minIndex].waktu.jam) {
                minIndex = j;
            }
        }
        Acara temp = rundown[minIndex];
        rundown[minIndex] = rundown[i];
        rundown[i] = temp;
    }
}

// Fungsi untuk sorting waktu (Menit) secara ascending (Insertion Sort)
void insertionSortAscMenit(Acara rundown[], int jumlahAcara) {
    for (int i = 1; i < jumlahAcara; ++i) {
        Acara key = rundown[i];
        int j = i - 1;
        while (j >= 0 && rundown[j].waktu.menit > key.waktu.menit) {
            rundown[j + 1] = rundown[j];
            j = j - 1;
        }
        rundown[j + 1] = key;
    }
}

// Fungsi untuk pencarian binary pada data terurut secara ascending
int binarySearchAsc(const Acara rundown[], int jumlahAcara, const string& target) {
    int kiri = 0;
    int kanan = jumlahAcara - 1;
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (rundown[tengah].kegiatan == target) {
            return tengah;
        }
        if (rundown[tengah].kegiatan < target) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return -1;
}

// Fungsi untuk pencarian linear pada data terurut secara descending
int sequentialSearchDesc(const Acara rundown[], int jumlahAcara, const string& target) {
    for (int i = 0; i < jumlahAcara; ++i) {
        if (rundown[i].kegiatan == target) {
            return i;
        }
    }
    return -1;
}

// Fungsi untuk menampilkan menu dan memilih opsi
int tampilkanMenu(Acara rundown[], int* indeks, int jumlahAcara) {
    int menu;
    cout << "\nMenu\n";
    cout << "---------------------------\n";
    cout << "1. Tambah Acara\n";
    cout << "2. Tampilkan Rundown Acara\n";
    cout << "3. Perbarui Acara\n";
    cout << "4. Hapus Acara\n";
    cout << "5. Sorting Huruf Ascending\n";
    cout << "6. Sorting Jam Descending\n";
    cout << "7. Sorting Menit Ascending\n";
    cout << "8. Pencarian Binary Ascending\n";
    cout << "9. Pencarian Linear Descending\n";
    cout << "10. Keluar\n";
    cout << "Pilih menu (1-10): ";
    menu = validasiInputAngka();

    switch (menu) {
        case 1: {
            // Tambah acara baru
            if (jumlahAcara < 25) {
                // Ambil input untuk acara baru
                cout << "\nNama Acara: ";
                getline(cin, rundown[jumlahAcara].kegiatan);
                cout << "Waktu Acara (jam): "; 
                rundown[jumlahAcara].waktu.jam = to_string(validasiInputAngka());
                cout << "Waktu Acara (menit): ";
                rundown[jumlahAcara].waktu.menit = to_string(validasiInputAngka());
                ++jumlahAcara;
            } else {
                cout << "Rundown Acara sudah penuh.\n";
            }
            break;
        }
        case 2: {
            // Tampilkan rundown acara
            tampilkanRundownAcara(rundown, jumlahAcara);
            break;
        }
        case 3: {
            tampilkanRundownAcara(rundown, jumlahAcara);
            perbaruiAcara(rundown, indeks, jumlahAcara);
            break;
        }
        case 4: {
            tampilkanRundownAcara(rundown, jumlahAcara);
            hapusAcara(rundown, indeks, &jumlahAcara);
            break;
        }
        case 5: {
            // Sorting huruf secara ascending
            bubbleSortAscHuruf(rundown, jumlahAcara);
            cout << "Rundown Berhasil Diurutkan secara huruf ascending.\n";
            break;
        }
        case 6: {
            // Sorting jam secara descending
            selectionSortDescJam(rundown, jumlahAcara);
            cout << "Rundown Berhasil Diurutkan secara jam descending.\n";
            break;
        }
        case 7: {
            // Sorting menit secara ascending
            insertionSortAscMenit(rundown, jumlahAcara);
            cout << "Rundown Berhasil Diurutkan secara menit ascending.\n";
            break;
        }
        case 8: {
            // Pencarian binary pada data terurut secara ascending
            cout << "Masukkan Nama Acara yang ingin dicari: ";
            string target;
            getline(cin, target);
            int hasilPencarian = binarySearchAsc(rundown, jumlahAcara, target);
            if (hasilPencarian != -1) {
                cout << "Acara ditemukan pada indeks: " << hasilPencarian + 1 << endl;
            } else {
                cout << "Acara tidak ditemukan.\n";
            }
            break;
        }
        case 9: {
            // Pencarian linear pada data terurut secara descending
            cout << "Masukkan Nama Acara yang ingin dicari: ";
            string target;
            getline(cin, target);
            int hasilPencarian = sequentialSearchDesc(rundown, jumlahAcara, target);
            if (hasilPencarian != -1) {
                cout << "Acara ditemukan pada indeks: " << hasilPencarian + 1 << endl;
            } else {
                cout << "Acara tidak ditemukan.\n";
            }
            break;
        }
        case 10: {
            cout << "Terima Kasih";
            return 0;
        }
        default:
            cout << "Menu Tidak Ada, Harap Coba Lagi.\n";
    }
    return tampilkanMenu(rundown, indeks, jumlahAcara);
}

// Fungsi untuk menampilkan menu utama dan memilih opsi
int tampilkanMenuUtama(Acara rundown[], int* indeks, int* jumlahAcara) {
    int login;
    int salah = 0;

    do {
        cout << "\nPilih Menu\n";
        cout << "-----------\n";
        cout << "1. Login\n";
        cout << "2. Keluar\n";
        cout << "Pilih Menu (1/2): ";
        login = validasiInputAngka();

        if (login == 1) {
            string username, password;
            // Meminta pengguna untuk login
            do {
                cout << "Masukan Username: ";
                cin >> username;
                cout << "Masukkan Password: ";
                cin >> password;
                salah++;
            }       
            // Loop jika username dan password salah
            while ((username != "Khairil" || password != "031") && salah < 3);
            if (salah == 3) {
                cout << "\nAnda Telah Melebihi Batas Percobaan Login";
                return 0;
            }
            cout << "\nLogin Berhasil\n";
        } else if (login == 2) {
            cout << "Terima Kasih Telah Menggunakan Program Ini";
            return 0;
        } else {
            cout << "Menu Tidak ada, Harap Coba Lagi";
        }
    }
    // Loop sampai pengguna berhasil login
    while (login != 1);

    // Setelah login berhasil, tampilkan menu utama
    return tampilkanMenu(rundown, indeks, *jumlahAcara);
}

int main() {
    Acara rundown[25]; // Array untuk menyimpan rundown acara
    int indeks = 0;
    int jumlahAcara = 0;

    // Tampilkan menu utama setelah login berhasil
    tampilkanMenuUtama(rundown, &indeks, &jumlahAcara);

    return 0;
}