#include <iostream>
#include <vector>
using namespace std;

class dokter;

class pasien {      //Assosiasi
    public:
        string nama;
        vector<dokter*> daftar_doktor;
        pasien(string pNama): nama(pNama) {
            cout << "Pasien \"" << nama << "\" ada\n";
        }

        ~pasien() {
            cout << "Pasien \"" << nama << "\" tidak ada\n";
        }

        void tambahDokter(dokter*);
        void cetakDokter();
};

class dokter {
    public:
        string nama;
        vector<pasien*> daftar_pasien;
        dokter(string pNama): nama(pNama) {
            cout << "Dokter \"" << nama << "\" ada\n";
        }

        ~dokter() {
            cout << "Dokter \"" << nama << "\" tidak ada\n";
        }

        void tambahPasien(pasien*);
        void cetakPasien();
};


