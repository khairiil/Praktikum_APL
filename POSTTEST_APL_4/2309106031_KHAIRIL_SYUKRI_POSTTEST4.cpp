#include <iostream>
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

// Fungsi untuk menampilkan menu dan memilih opsi
int tampilkanMenu(Acara rundown[], int &indeks);

// Prosedur untuk memperbarui acara
void perbaruiAcara(Acara rundown[], int &indeks) {
    // Memperbarui acara
    if (rundown[0].kegiatan == "") {
        cout << "\nRundown Acara Kosong.\n";
    } else {
        cout << "\nMasukkan Nomor Acara Yang Ingin Diperbarui: ";
        cin >> indeks;

        if (indeks > 0 && indeks <= 25 && rundown[indeks - 1].kegiatan != "") {
            cout << "\nNama Acara: ";
            cin.ignore();
            getline(cin, rundown[indeks - 1].kegiatan);
            cout << "Waktu Acara (jam): ";
            cin >> rundown[indeks - 1].waktu.jam;
            cout << "Waktu Acara (menit): ";
            cin >> rundown[indeks - 1].waktu.menit;
            cout << "Acara Berhasil Diperbarui\n";
        } else {
            cout << "\nNomor Acara Tidak Valid.\n";
        }
    }
}

// Prosedur untuk menghapus acara
void hapusAcara(Acara rundown[], int &indeks) {
    // Menghapus acara
    if (rundown[0].kegiatan == "") {
        cout << "\nRundown Acara Kosong.\n";
    } else {
        cout << "\nMasukkan Nomor Acara Yang Ingin Dihapus: ";
        cin >> indeks;
        if (indeks > 0 && indeks <= 25 && rundown[indeks - 1].kegiatan != "") {
            // Hapus acara yang dipilih
            rundown[indeks - 1].kegiatan = "";
            rundown[indeks - 1].waktu.jam = "0";
            rundown[indeks - 1].waktu.menit = "0";
            cout << "Acara Berhasil Dihapus\n";
            // Menggeser acara jika diperlukan
            for (int i = indeks - 1; i < 24; ++i) {
                rundown[i] = rundown[i + 1];
            }
            // Hapus acara terakhir yang duplikat
            rundown[24].kegiatan = "";
            rundown[24].waktu.jam = "0";
            rundown[24].waktu.menit = "0";
        } else {
            cout << "\nNomor Acara Tidak Valid.\n";
        }
    }
}

// Fungsi untuk menampilkan rundown acara
void tampilkanRundownAcara(Acara rundown[], int index = 0) {
    if (rundown[index].kegiatan != "") {
        cout << "Acara " << index + 1 << ":\n";
        cout << "Nama: " << rundown[index].kegiatan << endl;
        cout << "Waktu: " << rundown[index].waktu.jam << ":" << rundown[index].waktu.menit << endl << endl;
        tampilkanRundownAcara(rundown, index + 1); // Rekursif untuk menampilkan acara berikutnya
    }
}

// Fungsi untuk menambahkan acara baru
void tambahAcara(Acara rundown[], int index = 0) {
    if (rundown[index].kegiatan == "") {
        Acara acaraBaru;
        cout << "\nNama Acara: ";
        cin.ignore();
        getline(cin, acaraBaru.kegiatan);
        cout << "Waktu Acara (jam): ";
        cin >> acaraBaru.waktu.jam;
        cout << "Waktu Acara (menit): ";
        cin >> acaraBaru.waktu.menit;
        rundown[index] = acaraBaru;
        cout << "Acara Berhasil Ditambahkan\n";
    } else {
        tambahAcara(rundown, index + 1); // Rekursif untuk mencari slot kosong berikutnya
    }
}

// Fungsi untuk menampilkan menu dan memilih opsi
int tampilkanMenu(Acara rundown[], int &indeks) {
    int menu;
    cout << "\nMenu\n";
    cout << "---------------------------\n";
    cout << "1. Tambah Acara\n";
    cout << "2. Tampilkan Rundown Acara\n";
    cout << "3. Perbarui Acara\n";
    cout << "4. Hapus Acara\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu (1/2/3/4/5): ";
    cin >> menu;

    switch (menu) {
        case 1: {
            tambahAcara(rundown);
            break;
        }
        case 2: {
            tampilkanRundownAcara(rundown);
            break;
        }
        case 3: {
            tampilkanRundownAcara(rundown);
            perbaruiAcara(rundown, indeks);
            break;
        }
        case 4: {
            tampilkanRundownAcara(rundown); 
            hapusAcara(rundown, indeks);
            break;
        }
        case 5: {
            cout << "Terima Kasih";
            return 0;
        }
        default:
            cout << "Menu Tidak Ada, Harap Coba Lagi";
    }

    tampilkanMenu(rundown, indeks); // Rekursif untuk menampilkan menu lagi
    return menu;
}

// Fungsi untuk menampilkan menu utama dan memilih opsi
int tampilkanMenuUtama(Acara rundown[], int &indeks) {
    string login;
    int salah = 0;

    do {
        cout << "\nPilih Menu\n";
        cout << "-----------\n";
        cout << "1. Login\n";
        cout << "2. Keluar\n";
        cout << "Pilih Menu (1/2): ";
        cin >> login;

        if (login == "1") {
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
        } else if (login == "2") {
            cout << "Terima Kasih Telah Menggunakan Program Ini";
            return 0;
        } else {
            cout << "Menu Tidak ada, Harap Coba Lagi";
        }
    }
    // Loop sampai pengguna berhasil login
    while (login != "1");

    // Setelah login berhasil, tampilkan menu utama
    return tampilkanMenu(rundown, indeks);
}

int main() {
    Acara rundown[25]; // Array untuk menyimpan rundown acara
    int indeks;

    // Tampilkan menu utama setelah login berhasil
    tampilkanMenuUtama(rundown, indeks);

    return 0;
}