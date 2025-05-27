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

void pasien::tambahDokter(dokter* pDokter) {
    daftar_doktor.push_back(pDokter);
}

void pasien::cetakDokter() {
    cout << "Daftar dokter yang menangani pasien \"" << this->nama << "\":\n";
    //auto digunakan dalam perulangan
    for(auto& a : daftar_doktor) {
        cout << a->nama << "\n";
    }

    cout << endl;
}

void dokter::tambahPasien(pasien* pPasien) {
    daftar_pasien.push_back(pPasien);
}

void dokter::cetakPasien() {
    cout << "Daftar pasien yang dari dokter \"" << this->nama << "\":\n";
    for (auto& a : daftar_pasien) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

int main() {
    dokter* Dokter1 = new dokter("dr.Budi");
    dokter* Dokter2 = new dokter("dr.Tono");
    pasien* Pasien1 = new pasien("Andi");
    pasien* Pasien2 = new pasien("Lia");

    Dokter1->tambahPasien(Pasien1);
    Dokter1->tambahPasien(Pasien2);
    Dokter2->tambahPasien(Pasien1);

    Pasien1->tambahDokter(Dokter1);
    Pasien2->tambahDokter(Dokter1);
    Pasien1->tambahDokter(Dokter2);

    Dokter1->cetakPasien();
    Dokter2->cetakPasien();
    Pasien1->cetakDokter();
    Pasien2->cetakDokter();

    delete Dokter1;
    delete Dokter2;
    delete Pasien1;
    delete Pasien2;

    return 0;
}

