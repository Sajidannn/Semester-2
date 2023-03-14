#include<iostream>
#define n 3
using namespace std;

int luas(int a);
int jumlahLuas(int a[]);
int main() {
	int a, i, Luas[n];
	for (i = 0; i < n; i++) {
		cout << "masukkan panjang sisi bujur sangkar ke " << i + 1 << ": ";
		cin >> a;
		Luas[i] = luas(a);
		cout << "Luas bujur sangkar pertama: " << Luas[i] << endl;
	}
	cout << "Jumlah luas " << n << " bujur sangkar " << jumlahLuas(Luas) << endl;
}
int luas(int a) {
	int luas;
	luas = a * a;
	return luas;
}
int jumlahLuas(int Luas[]) {
	int jumlah = 0;
	for (int i = 0; i < n; i++)
	{
		jumlah += Luas[i];
	}
	return jumlah;
}

