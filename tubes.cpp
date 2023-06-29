#include <iostream>
#include <string>
using namespace std;

struct MenuItem
{
    string name;
    int price;
    MenuItem* next;
};

class MenuList
{
private:
    MenuItem* head;

public:
    MenuList()
    {
        head = NULL;
    }

    void addMenuItem(string name, int price)
    {
        MenuItem* menuItem = new MenuItem;
        menuItem->name = name;
        menuItem->price = price;
        menuItem->next = head;
        head = menuItem;
        cout << "Menu " << name << " dengan harga " << price << " telah ditambahkan.\n";
    }

    void updateMenuItem(string name, int price)
    {
        MenuItem* temp = head;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                temp->price = price;
                cout << "Menu " << name << " telah diubah dengan harga " << price << ".\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Menu " << name << " tidak ditemukan.\n";
    }

    void deleteMenuItem(string name)
    {
        MenuItem* temp = head;
        MenuItem* prev = NULL;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                if (prev == NULL)
                {
                    head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Menu " << name << " telah dihapus.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Menu " << name << " tidak ditemukan.\n";
    }

    void displayMenu()
    {
        MenuItem* temp = head;
        cout << "Daftar Menu:\n";
        while (temp != NULL)
        {
            cout << temp->name << " - " << temp->price << "\n";
            temp = temp->next;
        }
    }

    void placeOrder()
    {
        string order;
        int total = 0;
        cout << "Masukkan nama menu yang ingin dipesan (selesai untuk selesai):\n";
        getline(cin, order);
        while (order != "selesai")
        {
            MenuItem* temp = head;
            while (temp != NULL)
            {
                if (temp->name == order)
                {
                    total += temp->price;
                    break;
                }
                temp = temp->next;
            }
            getline(cin, order);
        }
        cout << "Total harga: " << total << "\n";
    }
};

int main()
{
    int choice, price;
    string name;
    MenuList menuList;
    do
    {
        cout << "\nMenu Utama\n";
        cout << "1. Tambah menu\n";
        cout << "2. Ubah menu\n";
        cout << "3. Hapus menu\n";
        cout << "4. Tampilkan menu\n";
        cout << "5. Pesan menu\n";
        cout << "0. Keluar\n";
        cout << "Masukkan pilihan anda: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
            case 1:
                cout << "Masukkan nama menu: ";
                getline(cin, name);
                cout << "Masukkan harga: ";
                cin >> price;
                menuList.addMenuItem(name, price);
                break;
            case 2:
                cout << "Masukkan nama menu yang ingin diubah: ";
                getline(cin, name);
                cout << "Masukkan harga baru: ";
                cin >> price;
                menuList.updateMenuItem(name, price);
                break;
            case 3:
                cout << "Masukkan nama menu yang ingin dihapus: ";
                getline(cin, name);
                menuList.deleteMenuItem(name);
                break;
            case 4:
                menuList.displayMenu();
                break;
            case 5:
                menuList.placeOrder();
                break;
            case 0:
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 0);
    
    return 0;
}