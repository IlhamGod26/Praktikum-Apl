#include <iostream>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isValidCode(int code) {
    return (code % 2 == 0 && code % 3 == 0 && code % 5 != 0);
}

bool isPalindrome(int n) {
    string s = to_string(n);
    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) return false;
    }
    return true;
}

int main() {
    string username, password;
    string correctUsername = "IlhamGod";
    string correctPassword = "2409106114"; 
    cout << "=====================================" << endl;
    cout << "          LOGIN PROGRAM             " << endl;
    cout << "=====================================" << endl;

    while (true) {
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        if (username == correctUsername && password == correctPassword) {
            cout << "\nLogin berhasil!\n";
            break;
        } else {
            cout << "\nUsername atau Password salah! Silakan coba lagi.\n\n";
        }
    }

    int secretCode, choice;
    cout << "=====================================" << endl;
    cout << "     SELAMAT DATANG DI PROGRAM      " << endl;
    cout << "=====================================" << endl;

    while (true) {
        cout << "\nMasukkan kode sandi (angka antara 101 - 99998): ";
        cin >> secretCode;

        if (secretCode < 100 || secretCode > 99999) {
            cout << "Kode sandi tidak valid! Silakan coba lagi.\n";
            continue;
        }

        while (true) {
            cout << "\n=====================================" << endl;
            cout << "          MENU VERIFIKASI            " << endl;
            cout << "=====================================" << endl;
            cout << "1. Cek apakah kode sandi bilangan prima" << endl;
            cout << "2. Cek apakah kode sandi habis dibagi 2 dan 3 tetapi tidak 5" << endl;
            cout << "3. Cek apakah kode sandi palindrome" << endl;
            cout << "4. Keluar" << endl;
            cout << "=====================================" << endl;
            cout << "Pilih menu (1-4): ";
            cin >> choice;

            cout << "\n=====================================" << endl;
            cout << "          HASIL VERIFIKASI           " << endl;
            cout << "=====================================" << endl;

            switch (choice) {
                case 1:
                    if (isPrime(secretCode))
                        cout << "- " << secretCode << " adalah bilangan prima.\n";
                    else
                        cout << "- " << secretCode << " bukan bilangan prima.\n";
                    break;
                case 2:
                    if (isValidCode(secretCode))
                        cout << "- " << secretCode << " memenuhi aturan pembagian (dibagi 2 & 3 tapi tidak 5).\n";
                    else
                        cout << "- " << secretCode << " tidak memenuhi aturan pembagian.\n";
                    break;
                case 3:
                    if (isPalindrome(secretCode))
                        cout << "- " << secretCode << " adalah palindrome.\n";
                    else
                        cout << "- " << secretCode << " bukan palindrome.\n";
                    break;
                case 4:
                    cout << "=====================================" << endl;
                    cout << "   TERIMA KASIH TELAH MENGGUNAKAN    " << endl;
                    cout << "            PROGRAM INI              " << endl;
                    cout << "=====================================" << endl;
                    return 0; 
                default:
                    cout << "Pilihan tidak valid! Silakan pilih lagi.\n";
            }
        }
    }
}