#include <iostream>
#include <string>

using namespace std;

//deklarasi linked list
struct DataMahasiswa{
	string nama, prodi, NIM;
	DataMahasiswa* prev=nullptr;
	DataMahasiswa* next=nullptr;
};

//Deklarasi variabel global
DataMahasiswa *head, *tail, *cur, *baru, *del, *afterNode;

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
	else {
		cout << "Linked list kosong" << endl;
	}
	return banyak;
}

//menambahkan data di depan
void insertDepan(string nama, string nim, string prodi) {
	baru = new DataMahasiswa;
	baru->nama = nama;
	baru->NIM = nim;
	baru->prodi = prodi;
	baru->next = NULL;
	baru->prev = NULL;
	if (head == NULL) {
		head = baru;
		tail = head;
		head->next = NULL;
		head->prev = NULL;
		tail->prev = NULL;
		tail->next = NULL;
	}
	else {
		baru->prev = NULL;
		baru->next = head;
		head->prev = baru;
		head = baru;
	}
}

//menambahkan data di belakang
void insertBelakang(string nama, string nim, string prodi) {
	baru = new DataMahasiswa;
	baru->nama = nama;
	baru->NIM = nim;
	baru->prodi = prodi;
	baru->next = NULL;
	baru->prev = NULL;
	if (head == NULL) {
		head = baru;
		tail = head;
		head->next = NULL;
		head->prev = NULL;
		tail->prev = NULL;
		tail->next = NULL;
	}
	else {
		baru->prev = tail;
		baru->next = NULL;
		tail->next = baru;
		tail = baru;
	}
}

//menambahkan data di tengah
void insertTengah(string nama, string nim, string prodi, int position) {

	baru = new DataMahasiswa;
	baru->nama = nama;
	baru->NIM = nim;
	baru->prodi = prodi;
	baru->next = NULL;
	baru->prev = NULL;
	//looping hingga sebelum posisi yang diinput
	cur = head;
	int count = 1;
	while (count < position - 1) {
		cur = cur->next;
		count++;
	}
	afterNode = cur->next;
	baru->prev = cur;
	baru->next = afterNode;
	cur->next = baru;
	afterNode->prev = baru;
	
}

//menghapus data dari depan
void hapusDepan() {
	if (head != NULL) {
		if (head->next != NULL) {
			del = head;
			head = head->next;
			head->prev = NULL;
			delete del;
		}
		else {
			head = NULL;
			tail = NULL;
		}
		cout << "Data berhasil dihapus" << endl;
	}
	else {
		cout << "Linked list belum dibuat" << endl;
	}
}

//menghapus data dari belakang
void hapusBelakang() {
	if (head != NULL) {
		if (head->next != NULL) {
			del = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete del;
		}
		else {
			head = NULL;
			tail = NULL;
		}
		cout << "Data berhasil dihapus" << endl;
	}
	else {
		cout << "Linked list belum dibuat" << endl;
	}
}

// hapus tengah
void hapusTengah(int posisi) {
	int count = 1;

	cur = head;
	while (count < posisi - 1) {
		cur = cur->next;
		count++;
	}
	del = cur->next;
	afterNode = del->next;
	cur->next = afterNode;
	afterNode->prev = cur;
	delete del;
	cout << "Data berhasil dihapus" << endl;
}

//mencari node dengan key nama
void cariData(string nama) {
	bool found = false;
	cur = head;
	while (cur != NULL) {
		if (cur->nama == nama) {
			found = true;
			cout << "Nama	: " << cur->nama << endl;
			cout << "Prodi	: " << cur->prodi << endl;
			cout << "NIM	: " << cur->NIM << "\n" << endl;
		}
		cur = cur->next;
	}
	if (!found) {
		cout << "Data tidak ditemukan\n";
	}
}


//mencetak linked list
void printLinkedList() {
	if (head != NULL) {
		cur = head;
		while (cur != NULL) {
			cout << "Nama	: " << cur->nama << endl;
			cout << "Prodi	: " << cur->prodi << endl;
			cout << "NIM	: " << cur->NIM << "\n" << endl;
			cur = cur->next;
		}
	}
	else {
		cout << "Linked list belum dibuat" << endl;
	}
}

//fungsi untuk mengambil menu
int getOption() {
	int input;
	system("cls");
	cout << "====================================================================" << endl;
	cout << "1. Tambah data depan" << endl;
	cout << "2. Tambah data belakang" << endl;
	cout << "3. Tambah data tengah" << endl;
	cout << "4. Hapus data depan" << endl;
	cout << "5. Hapus data belakang" << endl;
	cout << "6. Hapus data tengah" << endl;
	cout << "7. Cetak data" << endl;
	cout << "8. Cari data" << endl;
	cout << "9. Keluar dari program" << endl;
	cout << "====================================================================" << endl;
	cout << "Masukkan 1 - 9 : ";
	cin >> input;
	return input;
}

int main() {
	string nama, nim, prodi;
	int position, option = getOption();
	char is_continue;

	while (option != 9)
	{
		switch (option)
		{
		case 1:
			cout << "==========Insert data dari depan==========" << endl;
			cout << "Masukkan Nama	:"; cin >> nama;
			cout << "Masukkan nim	:"; cin >> nim;
			cout << "Masukkan prodi	:"; cin >> prodi;
			insertDepan(nama, nim, prodi);
			printLinkedList();
			break;
		case 2:
			cout << "==========Insert data belakang==========" << endl;
			cout << "Masukkan Nama	:"; cin >> nama;
			cout << "Masukkan nim	:"; cin >> nim;
			cout << "Masukkan prodi	:"; cin >> prodi;
			insertBelakang(nama, nim, prodi);
			printLinkedList();
			break;
		case 3:
			if (head != NULL)
			{
				//mengecek posisi
				cout << "==========Insert data tengah==========" << endl;
				cout << "Masukkan posisi data ke berapa ditambahkan :"; cin >> position;
				if (position == 1)
				{
					cout << "Itu bukan posisi tengah!" << endl;
				}
				else if (position < 1 || position > CountNode())
				{
					cout << "posisi di luar jangkauan!" << endl;
				}
				else
				{
					cout << "Masukkan Nama	:"; cin >> nama;
					cout << "Masukkan nim	:"; cin >> nim;
					cout << "Masukkan prodi	:"; cin >> prodi;
					insertTengah(nama, nim, prodi, position);
				}
				printLinkedList();
			}
			else {
				cout << "Linked list belum dibuat" << endl;
			}
			break;
		case 4:
			hapusDepan();
			printLinkedList();
			break;
		case 5:
			hapusBelakang();
			printLinkedList();
			break;
		case 6:
			if (head != NULL)
			{
				cout << "Masukkan posisi data yang dihapus :"; cin >> position;
				//mengecek apakah posisi itu ada
				if (position == 1 || position == CountNode()) {
					cout << "Posisi bukan posisi tegah!" << endl;
				}
				else if (position < 1 || position > CountNode()) {
					cout << "Posisi diluar jangkauan!" << endl;
				}
				else { hapusTengah(position); }
				printLinkedList();
			}
			else {
				cout << "Linked list belum dibuat" << endl;
			}
			break;
		case 7:
			printLinkedList();
			break;
		case 8:
			if (head != NULL) {
				cout << "==========Cari data di node==========" << endl;
				cout << "Masukkan nama yang dicari : "; cin >> nama;
				cariData(nama);
			}
			else {
				cout << "Linked list belum dibuat" << endl;
			}
			break;
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