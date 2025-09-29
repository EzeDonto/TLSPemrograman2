#include <iostream>
#include <string>
using namespace std;

// Fungsi pengecekan huruf vokal
bool hurufVokal(char v) {
    v = tolower(v);
    return (v == 'a' || v == 'i' || v == 'u' || v == 'e' || v == 'o');
}

// Fungsi mekanisme reverse tanpa 'reverse'
string cobaFlip(string s) {
    string hasil = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        hasil += s[i];
    }
    return hasil;
}

// Fungsi mekanisme enkripsi (membuat sandi)
string enkripsi(string huruf) {
    if (huruf.empty()) return "";

    // 1. Menyimpan huruf pertama
    char KarakterKe1 = huruf[0];
    int kodeASCII = (int)KarakterKe1;

    // 2. Menghilangkan huruf vokal
    string tanpaVokal = "";
    for (char a : huruf) {
        if (!hurufVokal(a)) {
            tanpaVokal += a;
        }
    }

    // 3. Membalikkan hasil tanpaVokal
    string terbalik = cobaFlip(tanpaVokal);

    // 4. Masukkan ASCII dari huruf pertama ke tengah kata
    int tengah = terbalik.size() / 2;
    string result = terbalik.substr(0, tengah) + to_string(kodeASCII) + terbalik.substr(tengah);

    return result;
}

// Fungsi mekanisme dekripsi (mendapatkan sebagian kata asli dari sandi)
void dekripsi(string kode) {
    int n = kode.size();
    string angka = "";
    int posisi = -1;

    // Mencari angka di tengah string
    for (int i = 0; i < n; i++) {
        if (isdigit(kode[i])) {
            if (posisi == -1) posisi = i;
            angka += kode[i];
        }
    }

    // Mengkonversi angka ke ASCII
    int kodeASCII = stoi(angka);
    char KarakterKe1 = (char)kodeASCII;

    // Menghapus angka dari string
    string temp = kode.substr(0, posisi) + kode.substr(posisi + angka.size());

    // Membalikkan posisi lagi
    string dibalikLagi = cobaFlip(temp);

    cout << "Kode sandi   : " << kode << endl;
    cout << "ASCII terdeteksi : " << kodeASCII << " ---> huruf pertama = " << KarakterKe1 << endl;
    cout << "Hasil setelah dibalik kembali (tanpa vokal) : " << dibalikLagi << endl;
    cout << "Kemungkinan kata asli diawali dengan huruf '" << KarakterKe1 << "'" << endl;
    cout << "Dimana kemungkinan kata tersebut adalah German atau Germania" << endl;
}

int main() {
    // Contoh enkripsi
    cout << " --- HASIL ENKRIPSI ---" << endl;
    cout << "banana    ---> " << enkripsi("banana") << endl;
    cout << "Jakarta   ---> " << enkripsi("Jakarta") << endl;
    cout << "TANGERANG ---> " << enkripsi("TANGERANG") << endl;

    // Contoh dekripsi
    cout << "\n--- HASIL DEKRIPSI ---" << endl;
    dekripsi("nm71rG");

    return 0;
}
