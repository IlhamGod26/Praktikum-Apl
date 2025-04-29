#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void tukar(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortNamaBarangDesc(string Barang[][2], int stok[], int jumlahBarang) {
    for (int i = 0; i < jumlahBarang - 1; i++) {
        for (int j = i + 1; j < jumlahBarang; j++) {
            if (Barang[i][0] < Barang[j][0]) {
                tukar(Barang[i][0], Barang[j][0]);
                tukar(Barang[i][1], Barang[j][1]);
                tukar(stok[i], stok[j]);
            }
        }
    }
}

void sortHargaBarangAsc(string Barang[][2], int stok[], int jumlahBarang) {
    for (int i = 0; i < jumlahBarang - 1; i++) {
        for (int j = i + 1; j < jumlahBarang; j++) {
            if (stoi(Barang[i][1]) > stoi(Barang[j][1])) {
                tukar(Barang[i][0], Barang[j][0]);
                tukar(Barang[i][1], Barang[j][1]);
                tukar(stok[i], stok[j]);
            }
        }
    }
}

void sortStokAsc(string Barang[][2], int stok[], int jumlahBarang) {
    for (int i = 0; i < jumlahBarang - 1; i++) {
        for (int j = i + 1; j < jumlahBarang; j++) {
            if (stok[i] > stok[j]) {
                tukar(Barang[i][0], Barang[j][0]);
                tukar(Barang[i][1], Barang[j][1]);
                tukar(stok[i], stok[j]);
            }
        }
    }
}

void lihatBarang(string Barang[][2], int stok[], int jumlahBarang) {
    cout << "\n===== DAFTAR BARANG =====" << endl;
    for (int i = 0; i < jumlahBarang; i++) {
        cout << i + 1 << ". " << Barang[i][0] << " | Stok: " << stok[i] << " | Harga: " << Barang[i][1] << endl;
    }
}

void daftarAkun(string namaPengguna[], string nimPengguna[], int *jumlahPengguna) {
    cout << "Masukkan nama pengguna baru: ";
    cin.ignore();
    getline(cin, namaPengguna[*jumlahPengguna]);
    cout << "Masukkan NIM pengguna baru: ";
    getline(cin, nimPengguna[*jumlahPengguna]);
    (*jumlahPengguna)++;
    cout << "Akun berhasil didaftarkan!" << endl;
}

void login(string namaPengguna[], string nimPengguna[], int jumlahPengguna, int *isAdmin, int *loginBerhasil) {
    string nama, nim;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "Masukkan nama: ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        for (int i = 0; i < jumlahPengguna; i++) {
            if (nama == namaPengguna[i] && nim == nimPengguna[i]) {
                cout << "Login berhasil!" << endl;
                *loginBerhasil = 1;
                if (nim.back() % 2 == 0) {
                    *isAdmin = 1;
                } else {
                    *isAdmin = 0;
                }
                return;
            }
        }
        percobaan++;
        cout << "Login gagal! Sisa percobaan: " << (3 - percobaan) << endl;
    }
    *loginBerhasil = 0;
}

void menuUser(string Barang[][2], int stok[], int jumlahBarang) {
    int pilihan;
    do {
        cout << "\n===== MENU USER =====" << endl;
        cout << "1. Lihat Barang" << endl;
        cout << "2. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            lihatBarang(Barang, stok, jumlahBarang);
        } else if (pilihan == 2) {
            cout << "Keluar dari menu user." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }
    } while (true);
}

void menuAdmin(string Barang[][2], int stok[], int &jumlahBarang, int isAdmin) {
    int pilihan;
    do {
        cout << "\n===== MENU ADMIN =====" << endl;
        cout << "1. Lihat Barang" << endl;
        cout << "2. Tambah Barang" << endl;
        cout << "3. Ubah Barang" << endl;
        cout << "4. Hapus Barang" << endl;
        cout << "5. Sorting Barang" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        
        if (pilihan == 1) {
            lihatBarang(Barang, stok, jumlahBarang);
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
            if (isAdmin) {
                int sortingChoice;
                cout << "\n===== MENU SORTING =====" << endl;
                cout << "1. Sorting Nama Barang (Descending)" << endl;
                cout << "2. Sorting Harga Barang (Ascending)" << endl;
                cout << "3. Sorting Stok Barang (Ascending)" << endl;
                cout << "Pilih metode sorting: ";
                cin >> sortingChoice;
                
                if (sortingChoice == 1) {
                    sortNamaBarangDesc(Barang, stok, jumlahBarang);
                    cout << "Nama barang berhasil diurutkan (Descending)." << endl;
                } else if (sortingChoice == 2) {
                    sortHargaBarangAsc(Barang, stok, jumlahBarang);
                    cout << "Harga barang berhasil diurutkan (Ascending)." << endl;
                } else if (sortingChoice == 3) {
                    sortStokAsc(Barang, stok, jumlahBarang);
                    cout << "Stok barang berhasil diurutkan (Ascending)." << endl;
                } else {
                    cout << "Pilihan tidak valid!" << endl;
                }
            }
        } else if (pilihan == 6) {
            cout << "Keluar dari menu admin." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }
    } while (true);
}

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

    int menu;
    do {
        cout << "\n===== MENU UTAMA =====" << endl;
        cout << "1. Login" << endl;
        cout << "2. Daftar Akun" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == 1) {
            int isAdmin = 0, loginBerhasil = 0;
            login(namaPengguna, nimPengguna, jumlahPengguna, &isAdmin, &loginBerhasil);

            if (loginBerhasil == 0) {
                cout << "Anda sudah mencoba 3 kali. Program berhenti." << endl;
                return 0;
            }

            if (isAdmin) {
                menuAdmin(Barang, stok, jumlahBarang, isAdmin);
            } else {
                menuUser(Barang, stok, jumlahBarang);
            }
        } else if (menu == 2) {
            daftarAkun(namaPengguna, nimPengguna, &jumlahPengguna);
        } else if (menu == 3) {
            cout << "Keluar dari program. Sampai jumpa!" << endl;
        } else {
            cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }
    } while (menu != 3);

    return 0;
}