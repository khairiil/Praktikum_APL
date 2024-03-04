#include <iostream>
using namespace std;

int main(){
    // Deklarasi variabel
    string login, username, password, nama = "Khairil", nim = "031";
    float rupiah, dollar, euro, yen;
    int salah = 0, menu;

    cout << "------------------------------------------------\n";
    cout << "| SELAMAT DATANG DI PROGRAM KONVERSI MATA UANG |\n";
    cout << "------------------------------------------------\n";
    
    // Loop sampai pengguna berhasil login
    do{
        cout << "\nPilih Menu\n";
        cout << "-----------\n";
        cout << "1. Login\n";
        cout << "2. Keluar\n";
        cout << "Pilih Menu (1/2): ";
        cin >> login;

        if (login == "1"){
            // Meminta pengguna untuk login
            do {
                cout << "Masukan Username: ";
                cin >> username;
                cout << "Masukkan Password: ";
                cin >> password;
                salah++;
            }
            // Loop jika username dan password salah
            while ((username != nama || password != nim)&& salah < 3);
            // Jika salah 3 kali, program akan berhenti
            if (salah == 3){
                cout << "Anda Telah Melebihi Batas Percobaan Login";
                return 0;
            }
            cout << "\nLogin Berhasil";
        }      
        else if (login == "2"){
            cout << "Terima Kasih Telah Menggunakan Program Ini";
            return 0;
        }
        else {
            // Jika pengguna salah input menu
            cout << "Menu Tidak ada, Harap Coba Lagi";
        }
    }
    // Loop sampai pengguna berhasi login
    while (login != "1");

    // Menu konversi mata uang
    do {
        cout << "\nMenu Konversi Mata Uang\n";
        cout << "-------------------------------------\n";
        cout << "1. Rupiah -> Dollar, Euro dan Yen\n";
        cout << "2. Dollar -> Rupiah, Euro dan Yen\n";
        cout << "3. Euro -> Rupiah, Dollar dan Euro\n";
        cout << "4. Yen -> Rupiah, Dollar dan Euro\n";
        cout << "Pilih Menu (1/2/3/4) Atau Ketik '0' Untuk Keluar: ";
        cin >> menu;

        // Switch case untuk memproses pilihan menu
        switch (menu){
            case 1:
            // Konversi rupiah ke dollar, euro dan yen
                cout << "\nMasukkan Nominal Rupiah: ";
                cin >> rupiah;
                cout << rupiah << " IDR = " << rupiah*0.000064 << " USD\n";
                cout << rupiah << " IDR = " << rupiah*0.000059 << " EUR\n";
                cout << rupiah << " IDR = " << rupiah*0.0096 << " JPY\n";
                break;
            case 2:
            // Konversi dollar ke rupiah, euro dan yen
                cout << "\nMasukkan Nominal Dollar: ";
                cin >> dollar;
                cout << dollar << " USD = " << dollar*15701.95 << " IDR\n";
                cout << dollar << " USD = " << dollar*0.92 << " EUR\n";
                cout << dollar << " USD = " << dollar*150.10 << " JPY\n";
                break;
            case 3:
            // Konversi euro ke rupiah, dollar dan yen
                cout << "\nMasukkan Nominal Euro: ";
                cin >> euro;
                cout << euro << " EUR = " << euro*17043.68 << " IDR\n";
                cout << euro << " EUR = " << euro*1.09 << " USD\n";
                cout << euro << " EUR = " << euro*162.93 << " JPY\n";
                break;
            case 4:
            // Konversi yen ke rupiah, dollar dan euro
                cout << "\nMasukkan Nominal Yen: ";
                cin >> yen;
                cout << yen << " JPY = " << yen*104.61 << " IDR\n";
                cout << yen << " JPY = " << yen*0.0067 << " USD\n";
                cout << yen << " JPY = " << yen*0.0061 << " EUR\n";
                break;
            case 0:
                cout << "\nTerima Kasih Telah Menggunakan Program Ini";
                break;
            default:
            // Jika pengguna salah input menu
                cout << "\nMenu Tidak Ada, Harap Coba Lagi";
        }
    }
    // Loop samapi pengguna memilih untuk keluar
    while (menu != 0);
    return 0;
}