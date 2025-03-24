#include <iostream>
#include <string>
using namespace std;

int main() {
    string namaPengguna[100]; 
    string nimPengguna[100];
    int jumlahPengguna = 1;

    namaPengguna[0] = "Riduan Ali";
    nimPengguna[0] = "114";

    string Barang[100][2];
    int stok[100];
    int jumlahBarang = 5;

    Barang[0][0] = "Lampu Projie Biru";   Barang[0][1] = "15000000";   stok[0] = 25;
    Barang[1][0] = "Lampu Projie Ungu";   Barang[1][1] = "25000000";   stok[1] = 20;
    Barang[2][0] = "Lampu Projie Putih";  Barang[2][1] = "20000000";   stok[2] = 15;
    Barang[3][0] = "Lampu LED Kuning";    Barang[3][1] = "10000000";   stok[3] = 30;
    Barang[4][0] = "Lampu LED RGB";       Barang[4][1] = "18000000";   stok[4] = 10;

    while (true) {
        cout << "\n===== MENU UTAMA =====" << endl;
        cout << "1. Login" << endl;
        cout << "2. Daftar Akun" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        int menu;
        cin >> menu;

        if (menu == 1) {
            string nama, nim;
            int percobaan = 0;
            int loginBerhasil = 0;
            int isAdmin = 0;

            while (percobaan < 3 && loginBerhasil == 0) {
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM: ";
                getline(cin, nim);

                for (int i = 0; i < jumlahPengguna; i++) {
                    if (namaPengguna[i] == nama && nimPengguna[i] == nim) {
                        loginBerhasil = 1;
                        if (i == 0) isAdmin = 1;
                        break;
                    }
                }
                
                if (loginBerhasil == 0) {
                    percobaan++;
                    cout << "Nama atau NIM salah! Percobaan ke-" << percobaan << " dari 3 percobaan.\n";
                }
            }

            if (loginBerhasil == 0) {
                cout << "Anda sudah mencoba 3 kali. Program berhenti." << endl;
                return 0;
            }

            if (isAdmin) {
                while (true) {
                    cout << "\n===== MENU ADMIN =====" << endl;
                    cout << "1. Lihat Barang" << endl;
                    cout << "2. Tambah Barang" << endl;
                    cout << "3. Ubah Barang" << endl;
                    cout << "4. Hapus Barang" << endl;
                    cout << "5. Keluar" << endl;
                    cout << "Pilih menu: ";
                    int pilihan;
                    cin >> pilihan;
                    cin.ignore();

                    if (pilihan == 1) {
                        cout << "\n===== DAFTAR BARANG =====" << endl;
                        for (int i = 0; i < jumlahBarang; i++) {
                            cout << i + 1 << ". " << Barang[i][0] << " | Stok: " << stok[i] << " | Harga: " << Barang[i][1] << endl;
                        }
                    } else if (pilihan == 2) {
                        cout << "Masukkan nama Barang: ";
                        getline(cin, Barang[jumlahBarang][0]);
                        cout << "Masukkan harga Barang: ";
                        getline(cin, Barang[jumlahBarang][1]);
                        cout << "Masukkan jumlah stok: ";
                        cin >> stok[jumlahBarang];
                        cin.ignore();
                        jumlahBarang++;
                        cout << "Barang berhasil ditambahkan!" << endl;
                    } else if (pilihan == 3) {
                        cout << "Pilih nomor Barang yang ingin diubah: ";
                        int index;
                        cin >> index;
                        cin.ignore();
                        if (index > 0 && index <= jumlahBarang) {
                            cout << "Masukkan nama baru Barang: ";
                            getline(cin, Barang[index - 1][0]);
                            cout << "Masukkan harga baru: ";
                            getline(cin, Barang[index - 1][1]);
                            cout << "Masukkan jumlah stok baru: ";
                            cin >> stok[index - 1];
                            cin.ignore();
                            cout << "Barang berhasil diperbarui!" << endl;
                        } else {
                            cout << "Nomor Barang tidak valid!" << endl;
                        }
                    } else if (pilihan == 4) {
                        cout << "Pilih nomor Barang yang ingin dihapus: ";
                        int index;
                        cin >> index;
                        cin.ignore();
                        if (index > 0 && index <= jumlahBarang) {
                            for (int i = index - 1; i < jumlahBarang - 1; i++) {
                                Barang[i][0] = Barang[i + 1][0];
                                Barang[i][1] = Barang[i + 1][1];
                                stok[i] = stok[i + 1];
                            }
                            jumlahBarang--;
                            cout << "Barang berhasil dihapus!" << endl;
                        } else {
                            cout << "Nomor Barang tidak valid!" << endl;
                        }
                    } else if (pilihan == 5) {
                        cout << "Keluar dari menu admin." << endl;
                        break;
                    } else {
                        cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
                    }
                }
            } else {

                while (true) {
                    cout << "\n===== MENU PENGGUNA =====" << endl;
                    cout << "1. Lihat Barang" << endl;
                    cout << "2. Keluar" << endl;
                    cout << "Pilih menu: ";
                    int pilihan;
                    cin >> pilihan;
                    cin.ignore();

                    if (pilihan == 1) {
                        cout << "\n===== DAFTAR BARANG =====" << endl;
                        for (int i = 0; i < jumlahBarang; i++) {
                            cout << i + 1 << ". " << Barang[i][0] << " | Stok: " << stok[i] << " | Harga: " << Barang[i][1] << endl;
                        }
                    } else if (pilihan == 2) {
                        cout << "Keluar dari menu pengguna." << endl;
                        break;
                    } else {
                        cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
                    }
                }
            }
        } else if (menu == 2) {
            if (jumlahPengguna >= 100) {
                cout << "Pendaftaran penuh! Tidak bisa menambahkan pengguna baru." << endl;
            } else {
                cout << "Masukkan Nama: ";
                cin.ignore(); 
                getline(cin, namaPengguna[jumlahPengguna]);
                cout << "Masukkan NIM: ";
                getline(cin, nimPengguna[jumlahPengguna]);
                jumlahPengguna++;
                cout << "Akun berhasil didaftarkan! Silakan login." << endl;
            }
        } else if (menu == 3) {
            cout << "Keluar dari program. Sampai jumpa!" << endl;
            break;
        } else {
            cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }
    }
    return 0;
}