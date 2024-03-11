#include <iostream>
using namespace std;

struct acara {
    string kegiatan;
    string waktu;
};

int main() {
    acara rundown[25]; // Array untuk menyimpan rundown acara
    string login, username, password, nama = "Khairil", nim = "031";
    int salah = 0, menu, indeks;

    // Menu utama
    do {
        cout << "\nPilih Menu\n";
        cout << "-----------\n";
        cout << "1. Login\n";
        cout << "2. Keluar\n";
        cout << "Pilih Menu (1/2): ";
        cin >> login;

        if (login == "1") {
            // Meminta pengguna untuk login
            do {
                cout << "Masukan Username: ";
                cin >> username;
                cout << "Masukkan Password: ";
                cin >> password;
                salah++;
            }
            // Loop jika username dan password salah
            while ((username != nama || password != nim) && salah < 3);
            if (salah == 3) {
                cout << "\nAnda Telah Melebihi Batas Percobaan Login";
                return 0;
            }
            cout << "\nLogin Berhasil\n";
        }      
        else if (login == "2") {
            cout << "Terima Kasih Telah Menggunakan Program Ini";
            return 0;
        }
        else {
            cout << "Menu Tidak ada, Harap Coba Lagi";
        }
    }
    // Loop sampai pengguna berhasil login
    while (login != "1");
    
    do {
        // Tampilkan menu opsi setelah login berhasil
        cout << "\nMenu\n";
        cout << "---------------------------\n";
        cout << "1. Tambah Acara\n";
        cout << "2. Tampilkan Rundown Acara\n";
        cout << "3. Perbarui Acara\n";
        cout << "4. Hapus Acara\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1/2/3/4/5): ";
        cin >> menu;

        switch(menu){
            case 1: {
                // Menambah acara baru
                acara acaraBaru;
                cout << "\nNama Acara: ";
                cin.ignore();
                getline(cin, acaraBaru.kegiatan);
                cout << "Waktu Acara: ";
                getline(cin, acaraBaru.waktu);

                // Menambahkan acara baru ke dalam array rundown acara
                for (int i = 0; i < 25; i++) {
                    if (rundown[i].kegiatan == "") {
                        rundown[i] = acaraBaru;
                        cout << "Acara Berhasil Ditambahkan\n";
                        break;
                    }
                }
                break;
            }
            case 2: {
                // Menampilkan rundown acara
                if (rundown[0].kegiatan == "") {
                    cout << "\nRundown Acara Kosong.\n";
                } 
                else {
                    cout << "\nRundown Acara:\n";
                    for (int i = 0; i < 25; i++) {
                        if (rundown[i].kegiatan != "") {
                            cout << "Acara " << i+1 << ":\n";
                            cout << "Nama: " << rundown[i].kegiatan << endl;
                            cout << "Waktu: " << rundown[i].waktu << endl << endl;
                        }
                    }
                }
                break;
            }
            case 3: {
                // Memperbarui acara
                if (rundown[0].kegiatan == "") {
                    cout << "\nRundown Acara Kosong.\n";
                } 
                else {
                    cout << "\nMasukkan Nomor Acara Yang Ingin Diperbarui: ";
                    cin >> indeks;

                    if (indeks > 0 && indeks <= 25 && rundown[indeks - 1].kegiatan != "") {
                        cout << "\nNama Acara: ";
                        cin.ignore();
                        getline(cin, rundown[indeks - 1].kegiatan);
                        cout << "Waktu Acara: ";
                        getline(cin, rundown[indeks - 1].waktu);
                        cout << "Acara Berhasil Diperbarui\n";
                    } 
                    else {
                        cout << "\nNomor Acara Tidak Valid.\n";
                    }
                }
                break;
            }
            case 4: {
                // Menghapus acara
                if (rundown[0].kegiatan == "") {
                    cout << "\nRundown Acara Kosong.\n";
                } 
                else {
                    cout << "\nMasukkan Nomor Acara Yang Ingin Dihapus: ";
                    cin >> indeks;
                    if (indeks > 0 && indeks <= 25 && rundown[indeks - 1].kegiatan != "") {
                        // Hapus acara yang dipilih
                        rundown[indeks - 1].kegiatan = "";
                        rundown[indeks - 1].waktu = "";
                        cout << "Acara Berhasil Dihapus\n";
                        // Menggeser acara jika diperlukan
                        for (int i = indeks - 1; i < 24; ++i) {
                            rundown[i] = rundown[i + 1];
                        }
                        // Hapus acara terakhir yang duplikat
                        rundown[24].kegiatan = "";
                        rundown[24].waktu = "";
                    } 
                    else {
                        cout << "\nNomor Acara Tidak Valid.\n";
                    }
                }
                break;
            }
            case 5: {
                cout << "Terima Kasih";
                break;
            }
            default: 
                cout << "Menu Tidak Ada, Harap Coba Lagi";
        }
    } 
    // Loop sampai pengguna ingin keluar
    while (menu != 5);
    return 0;
}