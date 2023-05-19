#include <iostream>
using namespace std;

// node
struct Tree {
    int data;
    Tree* left;
    Tree* right;
};

// fungsi untuk membuat node baru
Tree *createNode(int data) {
    Tree *newNode = new Tree;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// fungsi untuk menambahkan node ke dalam pohon
void insertNode(Tree **root, int data) {
    if (*root == nullptr) {
        *root = createNode(data);
        return;
    }

    if (data < (*root)->data) {
        insertNode(&(*root)->left, data);
    }
    else if (data > (*root)->data) {
        insertNode(&(*root)->right, data);
    }
    else {
        cout << "Data sudah ada!" << endl;
    }
}

//search data 
Tree *search(Tree *root, int data) {
    if (root==nullptr || root->data==data)
    {
        return root;
    }
    else if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
};

// Fungsi untuk mencari nilai terkecil dalam subpohon kanan
Tree* minValueNode(Tree* root) {
    Tree* current = root;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Fungsi untuk menghapus node dengan nilai tertentu dari pohon
Tree* deleteNode(Tree* root, int data) {
    if (root == nullptr) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            Tree* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Tree* temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Tree* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// preorder traversal
void preorder(Tree *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// inorder traversal
void inorder(Tree* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// postorder traversal
void postorder(Tree* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


int getOption() {
    int input;
    system("cls");
    cout << "====================================================================" << endl;
    cout << "1. Tambah data tree" << endl;
    cout << "2. Mencari data" << endl;
    cout << "3. Menghapus data" << endl;
    cout << "4. Membaca data tree" << endl;
    cout << "====================================================================" << endl;
    cout << "Masukkan 1 - 4 : ";
    cin >> input;
    return input;
}

int main() {
    Tree *root = nullptr, *found;
    int data, jumlah, option = getOption();
    char is_continue;
 
    while (option < 5) {
        switch (option) {
        case 1:
            cout << "======================Tambah data tree=============================" << endl;
            cout << "Berapa jumlah data yang akan dimasukkan? " << endl;
            cin >> jumlah;
            cout << "Masukkan data :" << endl;
            for (int i = 0; i < jumlah; i++) {
                cin >> data;
                insertNode(&root, data);
            }
            break;
        case 2:
            cout << "===========================Mencari data============================" << endl;
            cout << "Masukkan data : ";
            cin >> data;
            found = search(root, data);
            if (found!=nullptr) {
                cout << "Data " << data <<  " ditemukan!" << endl;
            }
            else {
                cout << "Data " << data << " tidak ditemukan!" << endl;
            }
            break;
        case 3:
            cout << "==========================Menghapus data===========================" << endl;
            cout << "Masukkan data yang dihapus" << endl;
            cin >> data;
            root = deleteNode(root, data);
            cout << "Data terhapus" << endl;
            break;
        case 4:
            cout << "===========================Membaca data============================" << endl;
            cout << "\nPreorder" << endl;
            preorder(root);
            cout << "\ninorder" << endl;
            inorder(root);
            cout << "\npost order" << endl;
            postorder(root);
        default:
            break;
        }
        cout << "\nLanjutkan?(y/n) : ";
        cin >> is_continue;
        if (is_continue == 'y' || is_continue == 'Y') {
            option = getOption();
        }
        else {
            option = 5;
        }
    }
    return 0;
}
