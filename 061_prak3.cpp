#include <iostream>
#include <string>

using namespace std;

//deklarasi linked list
struct DataMahasiswa {
	string nama, prodi, NIM;
	DataMahasiswa* next = nullptr;
};

//Deklarasi variabel global
DataMahasiswa* head, * tail, * cur, * baru, * del;
int maksimalData=5;

void createStack(string nama,string prodi, string NIM) {
	head = new DataMahasiswa();
	head->nama = nama;
	head->prodi = prodi;
	head->NIM = NIM;
	head->next = NULL;
	tail = head;
}


//menghitung jumlah node
int CountNode() {
	int banyak = 0;

	if (head != NULL) {
		cur = head;
		while (cur != NULL) {
			banyak++;
			cur = cur->next;
		}
	}
	return banyak;
}

//isFull
bool isFullData()
{
	if (CountNode() == maksimalData) {
		return true;
	}
	else {
		return false;
	}
}

//isEmpty
bool isEmptyData()
{
	if (CountNode() == 0) {
		return true;
	}
	else {
		return false;
	}
}

//menambahkan data di depan
void insertDepan(string nama, string nim, string prodi) {
	baru = new DataMahasiswa;
	baru->nama = nama;
	baru->NIM = nim;
	baru->prodi = prodi;
	baru->next = NULL;
	if (head == NULL) {
		head = baru;
		tail = head;
		head->next = NULL;
		tail->next = NULL;
	}
	else {
		baru->next = head;
		head = baru;
	}
}


//push stack
void push(string nama, string prodi, string NIM)
{
	if (isFullData()) {
		cout << "Stack Full!!" << endl;
	}
	else {
		if (isEmptyData()) {
			createStack(nama, prodi, NIM);
		}
		else {
			insertDepan(nama, prodi, NIM);
		}
	}
}

//menghapus data dari depan / bisa juga POP stack
void HapusnPop() {
	if (head != NULL) {
		if (head->next != NULL) {
			del = head;
			head = head->next;
			delete del;
		}
		else {
			head = NULL;
			tail = NULL;
		}
		cout << "Data berhasil dihapus" << endl;
	}
	else {
		cout << "Stack belum dibuat" << endl;
	}
}



//mencari node dengan key nama
void cariData(string nama) {
	bool found = false;
	cur = head;
	while (cur != NULL) {
		if (cur->nama == nama) {
			found = true;
			cout << "Nama	: " << cur->nama << endl;
			cout << "NIM	: " << cur->NIM << "\n" << endl;
			cout << "Prodi	: " << cur->prodi << endl;
		}
		cur = cur->next;
	}
	if (!found) {
		cout << "Data tidak ditemukan\n";
	}
}


//mencetak linked list
void printStack() {
	if (head != NULL) {
		cur = head;
		while (cur != NULL) {
			cout << "Nama	: " << cur->nama << endl;
			cout << "NIM	: " << cur->NIM  << endl;
			cout << "Prodi	: " << cur->prodi << endl;
			cur = cur->next;
		}
	}
	else {
		cout << "Stack belum dibuat" << endl;
	}
}

//fungsi untuk mengambil menu
int getOption() {
	int input;
	system("cls");
	cout << "====================================================================" << endl;
	cout << "1. Tambah Stack" << endl;
	cout << "2. Hapus Stack" << endl;
	cout << "3. Cetak Stack" << endl;
	cout << "4. Cari Stack" << endl;
	cout << "====================================================================" << endl;
	cout << "Masukkan 1 - 9 : ";
	cin >> input;
	return input;
}

int main() {
	string nama, nim, prodi;
	int position, option = getOption();
	char is_continue;

	while (option != 5)
	{
		switch (option)
		{
		case 1:
			cout << "==========Insert data dari depan==========" << endl;
			cout << "Masukkan Nama	:"; cin >> nama;
			cout << "Masukkan NIM	:"; cin >> nim;
			cout << "Masukkan Prodi:"; cin >> prodi;
			push(nama, nim, prodi);
			printStack();
			break;
		case 2:
			HapusnPop();
			printStack();
			break;
		case 3:
			printStack();
			break;
		case 4:
			if (head != NULL) {
				cout << "==========Cari data di node==========" << endl;
				cout << "Masukkan nama yang dicari : "; cin >> nama;
				cariData(nama);
			}
			else {
				cout << "Stack belum dibuat" << endl;
			}
		default:
			cout << "Pilihan tidak ditemukan" << endl;
			break;
		}
	label_continue:

		cout << "Lanjutkan?(y/n) : ";
		cin >> is_continue;
		if (is_continue == 'y' || is_continue == 'Y') {
			option = getOption();
		}
		else if (is_continue == 'n' || is_continue == 'N') {
			break;
		}
		else {
			goto label_continue;
		}
	}
	cout << "Program selesai" << endl;

}