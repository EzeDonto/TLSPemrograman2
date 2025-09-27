#include <iostream>
#include <string>
using namespace std;

//Input durasi lampu masing-masing (angka)
const int tHijau = 20;
const int tKuning = 3;
const int tMerah = 80;
const int SiklusSekali = tHijau + tKuning + tMerah; //20+3+80=103

//Input data awal yang diketahui (terjadi lampu kuning pada detik ke-45)
const int tAwal = 45;
const int AwalSiklus = tHijau; //posisi siklus dimulai saat lampu kuning pertama

//Fungsi penentuan warna lampu pada waktu yang ditentukan (t)
string kodeWarna(int t){
    int selisih = t - tAwal; //selisih dari waktu awal siklus
    int kondisi = (AwalSiklus + selisih) % SiklusSekali; //posisi relatif dalam siklus lampunya

    //proses meninjau warna lampu yang muncul terhadap posisi relatif dalam siklus lampunya
    if (kondisi >= 0 && kondisi < tHijau){
        return "Hijau";
    }
    else if (kondisi >= tHijau && kondisi < tHijau + tKuning){
        return "Kuning";
    }
    else {
        return "Merah";
    }
}

int main(){
    //Memasukkan input detik yang ditanyakan (sesuai Tugas Pemrograman 1)
    int t1 = 80, t2 = 135, t3 = 150, t4 = 212;

    cout << "Detik ke-" << t1 << " ---> " << kodeWarna(t1) << endl;
    cout << "Detik ke-" << t2 << " ---> " << kodeWarna(t2) << endl;
    cout << "Detik ke-" << t3 << " ---> " << kodeWarna(t3) << endl;
    cout << "Detik ke-" << t4 << " ---> " << kodeWarna(t4) << endl;

    return 0;
}