#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    int NIM, partisipasi, tugas, uts, uas;
    float nilaiAkhir;
};

float nilai_akhir(int partisipasi, int tugas, int uts, int uas) {
    return (partisipasi * 0.2) + (tugas * 0.3) + (uts * 0.2) + (uas * 0.3);
}

void selection_sort(mahasiswa mhs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_loc = i;
        for (int j = i + 1; j < n; j++) {
            if (mhs[j].nilaiAkhir > mhs[max_loc].nilaiAkhir) {
                max_loc = j;
            }
        }
        //menukar elemen dengan nilai akhir terbesar ke posisi awal apabila max_loc tidak sama posisinya dengan i
        if (max_loc != i) {
            mahasiswa temp = mhs[i];
            mhs[i] = mhs[max_loc];
            mhs[max_loc] = temp;
        }
    }
}

void binary_search(float cari, mahasiswa mhs[], int n) {
    int i = 0, r = n - 1, mid, ktm = 0;
    while (i <= r && ktm == 0) {
        mid = (i + r) / 2;
        if (cari == mhs[mid].nilaiAkhir) {
            ktm = 1;
        }
        else if (cari > mhs[mid].nilaiAkhir) {
            r = mid - 1;
        }
        else {
            i = mid + 1;
        }
    }
    if (ktm == 1) {
        cout << "Mahasiswa berada di nomor ke " << ++mid << endl;
    }
    else
    {
        cout << "data tidak ketemu" << endl;
    }
}

int main() {
    const int max = 50;
    int n;

    //input jumlah mahasiswa
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    //array dengan tipe dat struct mahasiswa untuk menyimpah data mahasiswa
    mahasiswa mhs[max];

    //membatasi nilai maksimal array
    if (n <= max) {
        // input data mahasiswa
        for (int i = 0; i < n; i++) {
            cout << "\nData mahasiswa ke-" << i + 1 << endl;
            cout << "Nama: ";
            cin >> mhs[i].nama;
            cout << "Masukkan NIM: ";
            cin >> mhs[i].NIM;
            cout << "Nilai Partisipasi: ";
            cin >> mhs[i].partisipasi;
            cout << "Nilai Tugas: ";
            cin >> mhs[i].tugas;
            cout << "Nilai UTS: ";
            cin >> mhs[i].uts;
            cout << "Nilai UAS: ";
            cin >> mhs[i].uas;

            //hitung nilai akhir menggunakan fungsi nilai_akhir
            mhs[i].nilaiAkhir = nilai_akhir(mhs[i].partisipasi, mhs[i].tugas, mhs[i].uts, mhs[i].uas);
        }

        //sort data mahasiswa berdasarkan nilai akhir menggunakan fungsi selection_sort
        selection_sort(mhs, n);

        //mencetak nilai keseluruhan
        system("cls");
        cout << "==============================================================================" << endl;
        cout << "No.\tNIM\tNama\tPartisipasi\tTugas\tUTS\tUAS\tNilai Akhir" << endl;
        cout << "==============================================================================" << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ".\t" << mhs[i].NIM << "\t" << mhs[i].nama << "\t" << mhs[i].partisipasi << "\t\t" << mhs[i].tugas << "\t" << mhs[i].uts << "\t" << mhs[i].uas << "\t" << mhs[i].nilaiAkhir << endl;
        }
        cout << "==============================================================================" << endl;

        //searching
        char is_search;
        float cari;

        do{
            cout << "\nIngin mencari nama mahasiswa?(y/n): ";
            cin >> is_search;
            cout << "Masukkan nilai akhir mahasiswa: ";
            cin >> cari;
            binary_search(cari, mhs, n);

        } while (is_search=='y');

    }
    else {
        cout << "Jumlah mahasiswa terlalu banyak!" << endl;
        cout << sizeof(mhs);
    }
}
