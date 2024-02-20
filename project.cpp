#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <unistd.h>
using namespace std;
void main_display();
void fun();
static bool PasswordCheck(string p)
{
    int len = 0;
    while (p[len] != '\0')
    {
        len++;
    }
    if (len < 9)
    {
        return 0;
    }
    bool special_characters = false;
    bool upper_case = false;
    bool lower_case = false;
    bool digit = false;
    for (int i = 0; i < len; i++)
    {
        if ((p[i] >= 32 && p[i] <= 47) || (p[i] >= 58 && p[i] <= 64) || (p[i] >= 91 && p[i] <= 96) || (p[i] >= 123 && p[i] <= 126))
        {
            special_characters = true;
        }
        if (p[i] >= 65 && p[i] <= 90)
        {
            upper_case = true;
        }
        if (p[i] >= 97 && p[i] <= 122)
        {
            lower_case = true;
        }
        if (p[i] >= 48 && p[i] <= 57)
        {
            digit = true;
        }
    }
    if (special_characters && upper_case && lower_case && digit)
    {
        return 1;
    }
    return 0;
}
// checks if cnic is valid
bool cnicCheck(string c)
{
    int len = 0;
    while (c[len] != '\0')
    {
        len++;
    }
    if (len != 13)
    {
        return 0;
    }
    for (int i = 0; i < len; i++)
    {
        if (c[i] < 48 || c[i] > 57)
        {
            return 0;
        }
    }
    return 1;
}
class Product
{
    char name[50];
    double price;
    char category[50];
    int quantity;
    char unit[50];

public:
    void set_unit(string n)
    {
        strcpy(unit, n.c_str());
    }
    void product_name(string n)
    {
        strcpy(name, n.c_str());
    }
    void set_category(string n)
    {
        strcpy(category, n.c_str());
    }
    void set_price(double d)
    {
        price = d;
    }
    void set_quantity(int n)
    {
        quantity = n;
    }
    string get_product_name()
    {
        return name;
    }
    string get_category()
    {
        return category;
    }
    double get_price()
    {
        return price;
    }
    int get_quantity()
    {
        return quantity;
    }
    string get_unit()
    {
        return unit;
    }
};
class Cart : public Product
{
};
class Inventory : public Product
{
public:
    void add_item()
    {
    }
    void remove_item()
    {
    }
    void update_item()
    {
    }
};
class Food : public Product
{
public:
    void add_item()
    {
    }
    void remove_item()
    {
    }
    void update_item()
    {
    }
};
class Pershible : public Food
{
public:
    int menu()
    {
        int option;
        cout << "----------------------------" << endl;
        cout << "\t1.Meat" << endl;
        cout << "\t2.Fruit" << endl;
        cout << "\t3.Vegetables" << endl;
        cout << "\t4.Dairy" << endl;
        cout << "\t5.Main Page" << endl;
        cout << "----------------------------" << endl;
        do
        {
            cout << "Choose Option:";
            cin >> option;
        } while (option < 1 || option > 5);
        return option;
    }
    bool checkmeat(string n)
    {
        bool check = false;
        Pershible A;
        ifstream myFile;
        myFile.open("Meat.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Already in Catalogue" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    bool checkfruit(string n)
    {
        bool check = false;
        Pershible A;
        ifstream myFile;
        myFile.open("Fruit.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Already in Catalogue" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    bool checkvege(string n)
    {
        bool check = false;
        Pershible A;
        ifstream myFile;
        myFile.open("vegetable.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Already in Catalogue" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    bool checkdairy(string n)
    {
        bool check = false;
        Pershible A;
        ifstream myFile;
        myFile.open("Dairy.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Already in Catalogue" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    void add_item()
    {
        int option = menu();
        if (option == 1)
        {
            cout << "---Meat---" << endl;
            string n, u;
            double p;
            fstream myfile;
            myfile.open("Meat.bin", ios::binary | ios::app);
            cout << "Name:";
            cin.ignore();
            getline(cin, n);
            bool valid = checkmeat(n);
            while (valid == true)
            {
                cout << "Name:";
                getline(cin, n);
                valid = checkmeat(n);
            }
            cout << "Price:";
            cin >> p;
            cout << "Unit:";
            cin.ignore();
            getline(cin, u);
            this->product_name(n);
            this->set_price(p);
            this->set_unit(u);
            myfile.write((char *)&(*this), sizeof(*this));
            myfile.close();
        }
        else if (option == 2)
        {
            cout << "---Fruit---" << endl;
            string n, u;
            double p;
            fstream myfile;
            myfile.open("Fruit.bin", ios::binary | ios::app);
            cout << "Name:";
            cin.ignore();
            getline(cin, n);
            bool valid = checkfruit(n);
            while (valid == true)
            {
                cout << "Name:";
                getline(cin, n);
                valid = checkfruit(n);
            }
            cout << "Price:";
            cin >> p;
            cout << "Unit:";
            cin.ignore();
            getline(cin, u);
            this->product_name(n);
            this->set_price(p);
            this->set_unit(u);
            myfile.write((char *)&(*this), sizeof(*this));
            myfile.close();
        }
        else if (option == 3)
        {
            cout << "---Vegetable---" << endl;
            string n, u;
            double p;
            fstream myfile;
            myfile.open("Vegetable.bin", ios::binary | ios::app);
            cout << "Name:";
            cin.ignore();
            getline(cin, n);
            bool valid = checkvege(n);
            while (valid == true)
            {
                cout << "Name:";
                getline(cin, n);
                valid = checkvege(n);
            }
            cout << "Price:";
            cin >> p;
            cout << "Unit:";
            cin.ignore();
            getline(cin, u);
            this->product_name(n);
            this->set_price(p);
            this->set_unit(u);
            myfile.write((char *)&(*this), sizeof(*this));
            myfile.close();
        }
        else if (option == 4)
        {
            cout << "---Dairy---" << endl;
            string n, u;
            double p;
            fstream myfile;
            myfile.open("Dairy.bin", ios::binary | ios::app);
            cout << "Name:";
            cin.ignore();
            getline(cin, n);
            bool valid = checkdairy(n);
            while (valid == true)
            {
                cout << "Name:";
                getline(cin, n);
                valid = checkdairy(n);
            }
            cout << "Price:";
            cin >> p;
            cout << "Unit:";
            cin.ignore();
            getline(cin, u);
            this->product_name(n);
            this->set_price(p);
            this->set_unit(u);
            myfile.write((char *)&(*this), sizeof(*this));
            myfile.close();
        }
        else if (option == 5)
        {
            fun();
        }
    }
    void remove_item()
    {
        int option = menu();
        if (option == 1)
        {
            cout << "---Meat---" << endl;
            string nme;
            cout << "Name:";
            cin.ignore();
            getline(cin, nme);
            Pershible A;
            fstream myFile;
            myFile.open("Meat.bin", ios::binary | ios::in);
            ofstream myFile_temp("temp.bin", ios::app | ios::binary);
            while (myFile.read((char *)&A, sizeof(A)))
            {
                if (A.get_product_name() != nme)
                {
                    myFile_temp.write((char *)&A, sizeof(A));
                }
                if (A.get_product_name() == nme)
                {
                    cout << "Item Found and Removed Successfully" << endl;
                }
            }
            myFile.close();
            myFile_temp.close();
            remove("Meat.bin");
            rename("temp.bin", "Meat.bin");
        }
        else if (option == 2)
        {
            cout << "---Fruit---" << endl;
            string nme;
            cout << "Name:";
            cin.ignore();
            getline(cin, nme);
            Pershible A;
            fstream myFile;
            myFile.open("Fruit.bin", ios::binary | ios::in);
            ofstream myFile_temp("temp.bin", ios::app | ios::binary);
            while (myFile.read((char *)&A, sizeof(A)))
            {
                if (A.get_product_name() != nme)
                {
                    myFile_temp.write((char *)&A, sizeof(A));
                }
                if (A.get_product_name() == nme)
                {
                    cout << "Item Found and Removed Successfully" << endl;
                }
            }
            myFile.close();
            myFile_temp.close();
            remove("Fruit.bin");
            rename("temp.bin", "Fruit.bin");
        }
        else if (option == 3)
        {
            cout << "---Vegetable---" << endl;
            string nme;
            cout << "Name:";
            cin.ignore();
            getline(cin, nme);
            Pershible A;
            fstream myFile;
            myFile.open("Vegetable.bin", ios::binary | ios::in);
            ofstream myFile_temp("temp.bin", ios::app | ios::binary);
            while (myFile.read((char *)&A, sizeof(A)))
            {
                if (A.get_product_name() != nme)
                {
                    myFile_temp.write((char *)&A, sizeof(A));
                }
                if (A.get_product_name() == nme)
                {
                    cout << "Item Found and Removed Successfully" << endl;
                }
            }
            myFile.close();
            myFile_temp.close();
            remove("Vegetable.bin");
            rename("temp.bin", "Vegetable.bin");
        }
        else if (option == 4)
        {
            cout << "---Dairy---" << endl;
            string nme;
            cout << "Name:";
            cin.ignore();
            getline(cin, nme);
            Pershible A;
            fstream myFile;
            myFile.open("Dairy.bin", ios::binary | ios::in);
            ofstream myFile_temp("temp.bin", ios::app | ios::binary);
            while (myFile.read((char *)&A, sizeof(A)))
            {
                if (A.get_product_name() != nme)
                {
                    myFile_temp.write((char *)&A, sizeof(A));
                }
                if (A.get_product_name() == nme)
                {
                    cout << "Item Found and Removed Successfully" << endl;
                }
            }
            myFile.close();
            myFile_temp.close();
            remove("Dairy.bin");
            rename("temp.bin", "Dairy.bin");
        }
        else
        {
            fun();
        }
    }
    bool check_item(string n)
    {
        Pershible A;
        string n1, u;
        bool check = false;
        double p;
        int id;
        ifstream myFile;
        myFile.open("Meat.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Item Found" << endl;
                check = true;
                cout << "Updated Name:";
                getline(cin, n1);
                cout << "Updated Price:";
                cin >> p;
                cout << "Updated Unit:";
                cin.ignore();
                getline(cin, u);
                fstream myfile("Meat.bin", ios::in | ios::out | ios::binary);
                while (myfile.read((char *)&(*this), sizeof(*this)))
                {
                    this->product_name(n1);
                    this->set_price(p);
                    this->set_unit(u);
                    int current = myFile.tellg();
                    int oneblock = sizeof(*this);
                    myfile.seekg(current - oneblock);
                    myfile.write((char *)&(*this), sizeof(*this));
                    myfile.close();
                }
            }
        }
        myFile.close();
        return check;
    }
    bool check_item1(string n)
    {
        Pershible A;
        string n1, u;
        bool check = false;
        double p;
        int id;
        ifstream myFile;
        myFile.open("Fruit.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Item Found" << endl;
                check = true;
                cout << "Updated Name:";
                getline(cin, n1);
                cout << "Updated Price:";
                cin >> p;
                cout << "Updated Unit:";
                cin.ignore();
                getline(cin, u);
                fstream myfile("Fruit.bin", ios::in | ios::out | ios::binary);
                while (myfile.read((char *)&(*this), sizeof(*this)))
                {
                    this->product_name(n1);
                    this->set_price(p);
                    this->set_unit(u);
                    int current = myFile.tellg();
                    int oneblock = sizeof(*this);
                    myfile.seekg(current - oneblock);
                    myfile.write((char *)&(*this), sizeof(*this));
                    myfile.close();
                }
            }
        }
        myFile.close();
        return check;
    }
    bool check_item2(string n)
    {
        Pershible A;
        string n1, u;
        bool check = false;
        double p;
        int id;
        ifstream myFile;
        myFile.open("Vegetable.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Item Found" << endl;
                check = true;
                cout << "Updated Name:";
                getline(cin, n1);
                cout << "Updated Price:";
                cin >> p;
                cout << "Updated Unit:";
                cin.ignore();
                getline(cin, u);
                fstream myfile("Vegetable.bin", ios::in | ios::out | ios::binary);
                while (myfile.read((char *)&(*this), sizeof(*this)))
                {
                    this->product_name(n1);
                    this->set_price(p);
                    this->set_unit(u);
                    int current = myFile.tellg();
                    int oneblock = sizeof(*this);
                    myfile.seekg(current - oneblock);
                    myfile.write((char *)&(*this), sizeof(*this));
                    myfile.close();
                }
            }
        }
        myFile.close();
        return check;
    }
    bool check_item3(string n)
    {
        Pershible A;
        string n1, u;
        bool check = false;
        double p;
        int id;
        ifstream myFile;
        myFile.open("Dairy.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Item Found" << endl;
                check = true;
                cout << "Updated Name:";
                getline(cin, n1);
                cout << "Updated Price:";
                cin >> p;
                cout << "Updated Unit:";
                cin.ignore();
                getline(cin, u);
                fstream myfile("Dairy.bin", ios::in | ios::out | ios::binary);
                while (myfile.read((char *)&(*this), sizeof(*this)))
                {
                    this->product_name(n1);
                    this->set_price(p);
                    this->set_unit(u);
                    int current = myFile.tellg();
                    int oneblock = sizeof(*this);
                    myfile.seekg(current - oneblock);
                    myfile.write((char *)&(*this), sizeof(*this));
                    myfile.close();
                }
            }
        }
        myFile.close();
        return check;
    }
    void update_item()
    {
        int option = menu();
        if (option == 1)
        {
            cout << "---Meat---" << endl;
            Pershible M;
            string n, p;
            fstream myfile;
            myfile.open("Meat.bin", ios::binary | ios::app);
            cout << "Enter Item Name You Want to Update:";
            cin.ignore();
            getline(cin, n);
            bool valid = check_item(n);
            while (valid == false)
            {
                cout << "Enter Item Name You Want to Update:";
                getline(cin, n);
                valid = check_item(n);
            }
            myfile.close();
        }
        else if (option == 2)
        {
            cout << "---Fruit---" << endl;
            Pershible M;
            string n, p;
            fstream myfile;
            myfile.open("Fruit.bin", ios::binary | ios::app);
            cout << "Enter Item Name You Want to Update:";
            cin.ignore();
            getline(cin, n);
            bool valid = check_item1(n);
            while (valid == false)
            {
                cout << "Enter Item Name You Want to Update:";
                getline(cin, n);
                valid = check_item1(n);
            }
            myfile.close();
        }
        else if (option == 3)
        {
            cout << "---Vegetable---" << endl;
            Pershible M;
            string n, p;
            fstream myfile;
            myfile.open("Vegetable.bin", ios::binary | ios::app);
            cout << "Enter Item Name You Want to Update:";
            cin.ignore();
            getline(cin, n);
            bool valid = check_item2(n);
            while (valid == false)
            {
                cout << "Enter Item Name You Want to Update:";
                getline(cin, n);
                valid = check_item2(n);
            }
            myfile.close();
        }
        else if (option == 4)
        {
            cout << "---Dairy---" << endl;
            Pershible M;
            string n, p;
            fstream myfile;
            myfile.open("Dairy.bin", ios::binary | ios::app);
            cout << "Enter Item Name You Want to Update:";
            cin.ignore();
            getline(cin, n);
            bool valid = check_item3(n);
            while (valid == false)
            {
                cout << "Enter Item Name You Want to Update:";
                getline(cin, n);
                valid = check_item3(n);
            }
            myfile.close();
        }
        else if (option == 5)
        {
            fun();
        }
    }
};
class Non_pershible : public Food
{
public:
    bool checksnack(string n)
    {
        bool check = false;
        Non_pershible A;
        ifstream myFile;
        myFile.open("snacks.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Already in Catalogue" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    bool checkspices(string n)
    {
        bool check = false;
        Non_pershible A;
        ifstream myFile;
        myFile.open("spices.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Already in Catalogue" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    bool checkgrain(string n)
    {
        bool check = false;
        Non_pershible A;
        ifstream myFile;
        myFile.open("grains.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Already in Catalogue" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    bool checkcereal(string n)
    {
        bool check = false;
        Non_pershible A;
        ifstream myFile;
        myFile.open("cereal.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Already in Catalogue" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    int menu()
    {
        int option;
        cout << "----------------------------" << endl;
        cout << "\t1.Snacks" << endl;
        cout << "\t2.Spices" << endl;
        cout << "\t3.Grains" << endl;
        cout << "\t4.Cereal" << endl;
        cout << "\t5.Main Page" << endl;
        cout << "----------------------------" << endl;
        do
        {
            cout << "Choose Option:";
            cin >> option;
        } while (option < 1 || option > 5);
        return option;
    }
    void add_item()
    {
        int option = menu();
        if (option == 1)
        {
            cout << "---Snacks---" << endl;
            string n, u;
            double p;
            fstream myfile;
            myfile.open("snacks.bin", ios::binary | ios::app);
            cout << "Name:";
            cin.ignore();
            getline(cin, n);
            bool valid = checksnack(n);
            while (valid == true)
            {
                cout << "Name:";
                getline(cin, n);
                valid = checksnack(n);
            }
            cout << "Price:";
            cin >> p;
            cout << "Unit:";
            cin.ignore();
            getline(cin, u);
            this->product_name(n);
            this->set_price(p);
            this->set_unit(u);
            myfile.write((char *)&(*this), sizeof(*this));
            myfile.close();
        }
        else if (option == 2)
        {
            cout << "---Spices---" << endl;
            string n, u;
            double p;
            fstream myfile;
            myfile.open("spices.bin", ios::binary | ios::app);
            cout << "Name:";
            cin.ignore();
            getline(cin, n);
            bool valid = checkspices(n);
            while (valid == true)
            {
                cout << "Name:";
                getline(cin, n);
                valid = checkspices(n);
            }
            cout << "Price:";
            cin >> p;
            cout << "Unit:";
            cin.ignore();
            getline(cin, u);
            this->product_name(n);
            this->set_price(p);
            this->set_unit(u);
            myfile.write((char *)&(*this), sizeof(*this));
            myfile.close();
        }
        else if (option == 3)
        {
            cout << "---Grains---" << endl;
            string n, u;
            double p;
            fstream myfile;
            myfile.open("grains.bin", ios::binary | ios::app);
            cout << "Name:";
            cin.ignore();
            getline(cin, n);
            bool valid = checkgrain(n);
            while (valid == true)
            {
                cout << "Name:";
                getline(cin, n);
                valid = checkgrain(n);
            }
            cout << "Price:";
            cin >> p;
            cout << "Unit:";
            cin.ignore();
            getline(cin, u);
            this->product_name(n);
            this->set_price(p);
            this->set_unit(u);
            myfile.write((char *)&(*this), sizeof(*this));
            myfile.close();
        }
        else if (option == 4)
        {
            cout << "---Cereal---" << endl;
            string n, u;
            double p;
            fstream myfile;
            myfile.open("cereal.bin", ios::binary | ios::app);
            cout << "Name:";
            cin.ignore();
            getline(cin, n);
            bool valid = checkcereal(n);
            while (valid == true)
            {
                cout << "Name:";
                getline(cin, n);
                valid = checkcereal(n);
            }
            cout << "Price:";
            cin >> p;
            cout << "Unit:";
            cin.ignore();
            getline(cin, u);
            this->product_name(n);
            this->set_price(p);
            this->set_unit(u);
            myfile.write((char *)&(*this), sizeof(*this));
            myfile.close();
        }
        else if (option == 5)
        {
            fun();
        }
    }
    void remove_item()
    {
        int option = menu();
        if (option == 1)
        {
            cout << "---Snacks---" << endl;
            string nme;
            cout << "Name:";
            cin.ignore();
            getline(cin, nme);
            Non_pershible A;
            fstream myFile;
            myFile.open("snacks.bin", ios::binary | ios::in);
            ofstream myFile_temp("temp.bin", ios::app | ios::binary);
            while (myFile.read((char *)&A, sizeof(A)))
            {
                if (A.get_product_name() != nme)
                {
                    myFile_temp.write((char *)&A, sizeof(A));
                }
                if (A.get_product_name() == nme)
                {
                    cout << "Item Found and Removed Successfully" << endl;
                }
            }
            myFile.close();
            myFile_temp.close();
            remove("snacks.bin");
            rename("temp.bin", "snacks.bin");
        }
        else if (option == 2)
        {
            cout << "---Spices---" << endl;
            string nme;
            cout << "Name:";
            cin.ignore();
            getline(cin, nme);
            Non_pershible A;
            fstream myFile;
            myFile.open("spices.bin", ios::binary | ios::in);
            ofstream myFile_temp("temp.bin", ios::app | ios::binary);
            while (myFile.read((char *)&A, sizeof(A)))
            {
                if (A.get_product_name() != nme)
                {
                    myFile_temp.write((char *)&A, sizeof(A));
                }
                if (A.get_product_name() == nme)
                {
                    cout << "Item Found and Removed Successfully" << endl;
                }
            }
            myFile.close();
            myFile_temp.close();
            remove("spices.bin");
            rename("temp.bin", "spices.bin");
        }
        else if (option == 3)
        {
            cout << "---Grains---" << endl;
            string nme;
            cout << "Name:";
            cin.ignore();
            getline(cin, nme);
            Non_pershible A;
            fstream myFile;
            myFile.open("grains.bin", ios::binary | ios::in);
            ofstream myFile_temp("temp.bin", ios::app | ios::binary);
            while (myFile.read((char *)&A, sizeof(A)))
            {
                if (A.get_product_name() != nme)
                {
                    myFile_temp.write((char *)&A, sizeof(A));
                }
                if (A.get_product_name() == nme)
                {
                    cout << "Item Found and Removed Successfully" << endl;
                }
            }
            myFile.close();
            myFile_temp.close();
            remove("grains.bin");
            rename("temp.bin", "grains.bin");
        }
        else if (option == 4)
        {
            cout << "---Cereal---" << endl;
            string nme;
            cout << "Name:";
            cin.ignore();
            getline(cin, nme);
            Non_pershible A;
            fstream myFile;
            myFile.open("cereal.bin", ios::binary | ios::in);
            ofstream myFile_temp("temp.bin", ios::app | ios::binary);
            while (myFile.read((char *)&A, sizeof(A)))
            {
                if (A.get_product_name() != nme)
                {
                    myFile_temp.write((char *)&A, sizeof(A));
                }
                if (A.get_product_name() == nme)
                {
                    cout << "Item Found and Removed Successfully" << endl;
                }
            }
            myFile.close();
            myFile_temp.close();
            remove("cereal.bin");
            rename("temp.bin", "cereal.bin");
        }
        else
        {
            fun();
        }
    }
    bool check_item(string n)
    {
        Non_pershible A;
        string n1, u;
        bool check = false;
        double p;
        int id;
        ifstream myFile;
        myFile.open("snacks.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Item Found" << endl;
                check = true;
                cout << "Updated Name:";
                getline(cin, n1);
                cout << "Updated Price:";
                cin >> p;
                cout << "Updated Unit:";
                cin.ignore();
                getline(cin, u);
                fstream myfile("snacks.bin", ios::in | ios::out | ios::binary);
                while (myfile.read((char *)&(*this), sizeof(*this)))
                {
                    this->product_name(n1);
                    this->set_price(p);
                    this->set_unit(u);
                    int current = myFile.tellg();
                    int oneblock = sizeof(*this);
                    myfile.seekg(current - oneblock);
                    myfile.write((char *)&(*this), sizeof(*this));
                    myfile.close();
                }
            }
        }
        myFile.close();
        return check;
    }
    bool check_item1(string n)
    {
        Non_pershible A;
        string n1, u;
        bool check = false;
        double p;
        int id;
        ifstream myFile;
        myFile.open("spices.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Item Found" << endl;
                check = true;
                cout << "Updated Name:";
                getline(cin, n1);
                cout << "Updated Price:";
                cin >> p;
                cout << "Updated Unit:";
                cin.ignore();
                getline(cin, u);
                fstream myfile("spices.bin", ios::in | ios::out | ios::binary);
                while (myfile.read((char *)&(*this), sizeof(*this)))
                {
                    this->product_name(n1);
                    this->set_price(p);
                    this->set_unit(u);
                    int current = myFile.tellg();
                    int oneblock = sizeof(*this);
                    myfile.seekg(current - oneblock);
                    myfile.write((char *)&(*this), sizeof(*this));
                    myfile.close();
                }
            }
        }
        myFile.close();
        return check;
    }
    bool check_item2(string n)
    {
        Non_pershible A;
        string n1, u;
        bool check = false;
        double p;
        int id;
        ifstream myFile;
        myFile.open("grains.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Item Found" << endl;
                check = true;
                cout << "Updated Name:";
                getline(cin, n1);
                cout << "Updated Price:";
                cin >> p;
                cout << "Updated Unit:";
                cin.ignore();
                getline(cin, u);
                fstream myfile("grains.bin", ios::in | ios::out | ios::binary);
                while (myfile.read((char *)&(*this), sizeof(*this)))
                {
                    this->product_name(n1);
                    this->set_price(p);
                    this->set_unit(u);
                    int current = myFile.tellg();
                    int oneblock = sizeof(*this);
                    myfile.seekg(current - oneblock);
                    myfile.write((char *)&(*this), sizeof(*this));
                    myfile.close();
                }
            }
        }
        myFile.close();
        return check;
    }
    bool check_item3(string n)
    {
        Non_pershible A;
        string n1, u;
        bool check = false;
        double p;
        int id;
        ifstream myFile;
        myFile.open("cereal.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Item Found" << endl;
                check = true;
                cout << "Updated Name:";
                getline(cin, n1);
                cout << "Updated Price:";
                cin >> p;
                cout << "Updated Unit:";
                cin.ignore();
                getline(cin, u);
                fstream myfile("cereal.bin", ios::in | ios::out | ios::binary);
                while (myfile.read((char *)&(*this), sizeof(*this)))
                {
                    this->product_name(n1);
                    this->set_price(p);
                    this->set_unit(u);
                    int current = myFile.tellg();
                    int oneblock = sizeof(*this);
                    myfile.seekg(current - oneblock);
                    myfile.write((char *)&(*this), sizeof(*this));
                    myfile.close();
                }
            }
        }
        myFile.close();
        return check;
    }
    void update_item()
    {
        int option = menu();
        if (option == 1)
        {
            cout << "---Snacks---" << endl;
            Non_pershible M;
            string n, p;
            fstream myfile;
            myfile.open("snacks.bin", ios::binary | ios::app);
            cout << "Enter Item Name You Want to Update:";
            cin.ignore();
            getline(cin, n);
            bool valid = check_item(n);
            while (valid == false)
            {
                cout << "Enter Item Name You Want to Update:";
                getline(cin, n);
                valid = check_item(n);
            }
            myfile.close();
        }
        else if (option == 2)
        {
            cout << "---Spices---" << endl;
            Non_pershible M;
            string n, p;
            fstream myfile;
            myfile.open("spices.bin", ios::binary | ios::app);
            cout << "Enter Item Name You Want to Update:";
            cin.ignore();
            getline(cin, n);
            bool valid = check_item1(n);
            while (valid == false)
            {
                cout << "Enter Item Name You Want to Update:";
                getline(cin, n);
                valid = check_item1(n);
            }
            myfile.close();
        }
        else if (option == 3)
        {
            cout << "---Grains---" << endl;
            Non_pershible M;
            string n, p;
            fstream myfile;
            myfile.open("grains.bin", ios::binary | ios::app);
            cout << "Enter Item Name You Want to Update:";
            cin.ignore();
            getline(cin, n);
            bool valid = check_item2(n);
            while (valid == false)
            {
                cout << "Enter Item Name You Want to Update:";
                getline(cin, n);
                valid = check_item2(n);
            }
            myfile.close();
        }
        else if (option == 4)
        {
            cout << "---Cereal---" << endl;
            Non_pershible M;
            string n, p;
            fstream myfile;
            myfile.open("cereal.bin", ios::binary | ios::app);
            cout << "Enter Item Name You Want to Update:";
            cin.ignore();
            getline(cin, n);
            bool valid = check_item3(n);
            while (valid == false)
            {
                cout << "Enter Item Name You Want to Update:";
                getline(cin, n);
                valid = check_item3(n);
            }
            myfile.close();
        }
        else if (option == 5)
        {
            fun();
        }
    }
};
class Hygiene : public Product
{
public:
    bool checkitem(string n)
    {
        bool check = false;
        Hygiene A;
        ifstream myFile;
        myFile.open("hygiene.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Already in Catalogue" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    void add_item()
    {
        cout << "---Hygiene---" << endl;
        string n, u;
        double p;
        fstream myfile;
        myfile.open("hygiene.bin", ios::binary | ios::app);
        cout << "Name:";
        cin.ignore();
        getline(cin, n);
        bool valid = checkitem(n);
        while (valid == true)
        {
            cout << "Name:";
            getline(cin, n);
            valid = checkitem(n);
        }
        cout << "Price:";
        cin >> p;
        cout << "Unit:";
        cin.ignore();
        getline(cin, u);
        this->product_name(n);
        this->set_price(p);
        this->set_unit(u);
        myfile.write((char *)&(*this), sizeof(*this));
        myfile.close();
    }
    void remove_item()
    {
        cout << "---Hygiene---" << endl;
        string nme;
        cout << "Name:";
        cin.ignore();
        getline(cin, nme);
        Hygiene A;
        fstream myFile;
        myFile.open("hygiene.bin", ios::binary | ios::in);
        ofstream myFile_temp("temp.bin", ios::app | ios::binary);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() != nme)
            {
                myFile_temp.write((char *)&A, sizeof(A));
            }
            if (A.get_product_name() == nme)
            {
                cout << "Item Found and Removed Successfully" << endl;
            }
        }
        myFile.close();
        myFile_temp.close();
        remove("hygiene.bin");
        rename("temp.bin", "hygiene.bin");
    }
    bool check_item(string n)
    {
        Hygiene A;
        string n1, u;
        bool check = false;
        double p;
        int id;
        ifstream myFile;
        myFile.open("hygiene.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Item Found" << endl;
                check = true;
                cout << "Updated Name:";
                getline(cin, n1);
                cout << "Updated Price:";
                cin >> p;
                cout << "Updated Unit:";
                cin.ignore();
                getline(cin, u);
                fstream myfile("hygiene.bin", ios::in | ios::out | ios::binary);
                while (myfile.read((char *)&(*this), sizeof(*this)))
                {
                    this->product_name(n1);
                    this->set_price(p);
                    this->set_unit(u);
                    int current = myFile.tellg();
                    int oneblock = sizeof(*this);
                    myfile.seekg(current - oneblock);
                    myfile.write((char *)&(*this), sizeof(*this));
                    myfile.close();
                }
            }
        }
        myFile.close();
        return check;
    }
    void update_item()
    {
        Hygiene M;
        string n, p;
        fstream myfile;
        myfile.open("hygiene.bin", ios::binary | ios::app);
        cout << "Enter Item Name You Want to Update:";
        cin.ignore();
        getline(cin, n);
        bool valid = check_item(n);
        while (valid == false)
        {
            cout << "Enter Item Name You Want to Update:";
            getline(cin, n);
            valid = check_item(n);
        }
        myfile.close();
    }
    void show()
    {
        cout << this->get_product_name() << endl;
        cout << this->get_price() << endl;
        cout << this->get_unit() << endl;
    }
};
class Household : public Product
{
public:
    bool checkitem(string n)
    {
        bool check = false;
        Household A;
        ifstream myFile;
        myFile.open("household.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Already in Catalogue" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    void add_item()
    {
        cout << "---Household---" << endl;
        string n, u;
        double p;
        fstream myfile;
        myfile.open("household.bin", ios::binary | ios::app);
        cout << "Name:";
        cin.ignore();
        getline(cin, n);
        bool valid = checkitem(n);
        while (valid == true)
        {
            cout << "Name:";
            getline(cin, n);
            valid = checkitem(n);
        }
        cout << "Price:";
        cin >> p;
        cout << "Unit:";
        cin.ignore();
        getline(cin, u);
        this->product_name(n);
        this->set_price(p);
        this->set_unit(u);
        myfile.write((char *)&(*this), sizeof(*this));
        myfile.close();
    }
    void remove_item()
    {
        cout << "---Household---" << endl;
        string nme;
        cout << "Name:";
        cin.ignore();
        getline(cin, nme);
        Hygiene A;
        fstream myFile;
        myFile.open("household.bin", ios::binary | ios::in);
        ofstream myFile_temp("temp.bin", ios::app | ios::binary);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() != nme)
            {
                myFile_temp.write((char *)&A, sizeof(A));
            }
            if (A.get_product_name() == nme)
            {
                cout << "Item Found and Removed Successfully" << endl;
            }
        }
        myFile.close();
        myFile_temp.close();
        remove("household.bin");
        rename("temp.bin", "household.bin");
    }
    bool check_item(string n)
    {
        Hygiene A;
        string n1, u;
        bool check = false;
        double p;
        int id;
        ifstream myFile;
        myFile.open("household.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Item Found" << endl;
                check = true;
                cout << "Updated Name:";
                getline(cin, n1);
                cout << "Updated Price:";
                cin >> p;
                cout << "Updated Unit:";
                cin.ignore();
                getline(cin, u);
                fstream myfile("household.bin", ios::in | ios::out | ios::binary);
                while (myfile.read((char *)&(*this), sizeof(*this)))
                {
                    this->product_name(n1);
                    this->set_price(p);
                    this->set_unit(u);
                    int current = myFile.tellg();
                    int oneblock = sizeof(*this);
                    myfile.seekg(current - oneblock);
                    myfile.write((char *)&(*this), sizeof(*this));
                    myfile.close();
                }
            }
        }
        myFile.close();
        return check;
    }
    void update_item()
    {
        cout << "---Household---" << endl;
        Household M;
        string n, p;
        fstream myfile;
        myfile.open("household.bin", ios::binary | ios::app);
        cout << "Enter Item Name You Want to Update:";
        cin.ignore();
        getline(cin, n);
        bool valid = check_item(n);
        while (valid == false)
        {
            cout << "Enter Item Name You Want to Update:";
            getline(cin, n);
            valid = check_item(n);
        }
        myfile.close();
    }
};
class Product_Catalogue
{
    Food F;
    Hygiene H;
    Household D;
};
class Feedback
{
    char feedback[100];

public:
    void set_feed(string f = "")
    {
        strcpy(feedback, f.c_str());
    }
    string get_feed()
    {
        return feedback;
    }
};
class Person
{
    char name[100];
    char password[20];
    char city[100];
    char gender;

public:
    Person(string n = "", string pass = "", char g = 'M', string c = " ")
    {
        strcpy(name, n.c_str());
        strcpy(password, pass.c_str());
        strcpy(city, c.c_str());
        gender = g;
    }
    void set_name(string n = "")
    {
        strcpy(name, n.c_str());
    }
    void set_password(string pass = "")
    {
        stpcpy(password, pass.c_str());
    }
    void set_gender(char p)
    {
        gender = p;
    }
    void set_city(string c = " ")
    {
        strcpy(city, c.c_str());
    }
    string get_name()
    {
        return name;
    }
    string get_pass()
    {
        return password;
    }
    char get_gender()
    {
        return gender;
    }
    string get_city()
    {
        return city;
    }
    virtual void display()
    {
    }
};
class Simulation
{
    double time;

public:
    void settime(double d)
    {
        time = d;
    }
    double gettime()
    {
        return time;
    }
};
class Payment
{
public:
    virtual void pay()
    {
    }
};
class COD : public Payment
{
public:
    void pay()
    {
        cout << "Cash on Delivery" << endl;
    }
};
class Card : public Payment
{
public:
    void pay()
    {
        cout << "Card Service" << endl;
    }
};
class Easypaisa : public Payment
{
public:
    void pay()
    {
        cout << "Easypaisa Service" << endl;
    }
};
class Jazzcash : public Payment
{
public:
    void pay()
    {
        cout << "Jazzcash Service" << endl;
    }
};
class Manager : public Person
{
    char store_name[50];
    int store_id;

public:
    void set_store(string n = "")
    {
        strcpy(store_name, n.c_str());
    }
    string get_store()
    {
        return store_name;
    }
    void set_store_id(int id)
    {
        store_id = id;
    }
    int get_store_id()
    {
        return store_id;
    }
    // void menu(Manager &B)
    // {
    //     int opt;
    //     cout << "-----Manager Main-----" << endl;
    //     cout << "1.Check Data" << endl;
    //     cout << "2.Manage Inventory" << endl;
    //     cout << "3.Log out" << endl;
    //     cout << "----------------------" << endl;
    //     do
    //     {
    //         cout << "Choose Option:";
    //         cin >> opt;
    //     } while (opt < 1 || opt > 3);
    //     if (opt == 1)
    //     {
    //         B.display();
    //         sleep(3);
    //         system("clear");
    //         menu(B);
    //     }
    //     else if (opt == 2)
    //     {
    //         manage_inventory();
    //     }
    //     else if (opt == 3)
    //     {
    //         system("clear");
    //         login();
    //     }
    // }
    void login()
    {
        int opt;
        cout << "----------------------------" << endl;
        cout << "\tManager Page" << endl;
        cout << "\t1.Login" << endl;
        cout << "\t2.Back" << endl;
        cout << "----------------------------" << endl;
        do
        {
            cout << "Choose Option:";
            cin >> opt;
        } while (opt < 1 || opt > 2);
        if (opt == 1)
        {
            system("clear");
            cout << "---Manager Login---" << endl;
            string nme;
            string pass;
            cout << "Name:";
            cin.ignore();
            getline(cin, nme);
            cout << "password:";
            getline(cin, pass);
            Manager B;
            ifstream myFile;
            myFile.open("manager.bin", ios::binary | ios::in);
            while (myFile.read((char *)&B, sizeof(B)))
            {
                if (B.get_name() == nme && B.get_pass() == pass)
                {
                    system("clear");
                    cout << "Successfully Login" << endl;
                jump:
                    cout << "-----Manager Main-----" << endl;
                    cout << "1.Check Data" << endl;
                    cout << "2.Manage Inventory" << endl;
                    cout << "3.Check Store Items" << endl;
                    cout << "4.Log out" << endl;
                    cout << "5.Search" << endl;
                    cout << "6.View" << endl;
                    cout << "7.Remove Feedback" << endl;
                    cout << "----------------------" << endl;
                    do
                    {
                        cout << "Choose Option:";
                        cin >> opt;
                    } while (opt < 1 || opt > 7);
                    if (opt == 1)
                    {
                        B.display();
                        sleep(3);
                        system("clear");
                        goto jump;
                    }
                    else if (opt == 2)
                    {
                        system("clear");
                        B.manage_inventory();
                        system("clear");
                        goto jump;
                    }
                    else if (opt == 3)
                    {
                        B.check_store();
                        sleep(4);
                        system("clear");
                        goto jump;
                    }
                    else if (opt == 4)
                    {
                        system("clear");
                        login();
                    }
                    else if (opt == 5)
                    {
                        search();
                        sleep(5);
                        system("clear");
                        goto jump;
                    }
                    else if (opt == 6)
                    {
                        view();
                        sleep(5);
                        system("clear");
                        goto jump;
                    }
                    else if (opt == 7)
                    {
                        remove_feedback();
                        cout << "Feedback Removed" << endl;
                        sleep(5);
                        system("clear");
                        goto jump;
                    }
                }
            }
            myFile.close();
            system("clear");
            login();
        }
        else
        {
            system("clear");
            main_display();
        }
    }
    void remove_feedback()
    {
        int nme;
        cout << "---Remove Store Feedback---" << endl;
        cout << "Enter Store ID:";
        cin >> nme;
        Feedback A;
        fstream myFile;
        myFile.open("feedback" + to_string(nme) + ".bin", ios::binary | ios::in);
        ofstream myFile_temp("temp.bin", ios::app | ios::binary);
        myFile.close();
        myFile_temp.close();
        string f = "feedback" + to_string(nme) + ".bin";
        char arr[100];
        strcpy(arr, f.c_str());
        remove(arr);
        rename("temp.bin", arr);
    }
    bool valid_id(int id)
    {
        bool check = false;
        Manager A;
        ifstream myFile;
        myFile.open("manager.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_store_id() == id)
            {
                cout << "Store Found" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    void search()
    {
        int id;
        cout << "Enter Store ID from you want to Search:";
        cin >> id;
        bool check = valid_id(id);
        while (check == false)
        {
            cout << "Enter Store ID from you want to Search:";
            cin >> id;
            check = valid_id(id);
        }
        string name;
        cout << "Product Name:";
        cin.ignore();
        getline(cin, name);
        Inventory A;
        ifstream myFile;
        // cout << "Product  Quantity   Price" << endl;
        myFile.open("inventory" + to_string(id) + ".bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == name)
            {
                cout << "Product Available" << endl;
                cout << "Price:" << A.get_price() << endl;
            }
        }
        myFile.close();
    }
    void view()
    {
        int id;
        cout << "Enter Store ID:";
        cin >> id;
        bool check = valid_id(id);
        while (check == false)
        {
            cout << "Enter Store ID:";
            cin >> id;
            check = valid_id(id);
        }
        Inventory A;
        ifstream myFile;
        cout << "Product  Quantity   Price" << endl;
        myFile.open("inventory" + to_string(id) + ".bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            cout << A.get_product_name() << "\t    " << A.get_quantity() << "\t     " << A.get_price() << endl;
        }
        myFile.close();
    }
    void display()
    {
        cout << "----------------------------" << endl;
        cout << "\tName:" << this->get_name() << endl;
        cout << "\tPassword:" << this->get_pass() << endl;
        cout << "\tCity:" << this->get_city() << endl;
        cout << "\tStore Assigned:" << this->get_store() << endl;
        cout << "\tStore ID:" << this->get_store_id() << endl;
        cout << "----------------------------" << endl;
    }
    bool check_inventory(string n)
    {
        bool check = false;
        Inventory A;
        ifstream myFile;
        myFile.open("inventory.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    bool check_already(string n)
    {
        bool check = false;
        Inventory A;
        ifstream myFile;
        myFile.open("inventory" + to_string(this->get_store_id()) + ".bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                cout << "Already in Store" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    void check_store()
    {
        Inventory A;
        ifstream myFile;
        cout << "Product  Quantity   Price" << endl;
        myFile.open("inventory" + to_string(this->get_store_id()) + ".bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            cout << A.get_product_name() << "\t    " << A.get_quantity() << "\t     " << A.get_price() << endl;
        }
        myFile.close();
    }
    bool check_item(string n)
    {
        Inventory B;
        string n1, u;
        bool check = false;
        int quantity;
        ifstream myFile;
        myFile.open("inventory" + to_string(this->get_store_id()) + ".bin", ios::binary | ios::in);
        while (myFile.read((char *)&B, sizeof(B)))
        {
            if (B.get_product_name() == n)
            {
                cout << "Item Found" << endl;
                check = true;
                cout << "Enter Updated Quantity:";
                cin >> quantity;
                Inventory A;
                fstream myfile("inventory" + to_string(this->get_store_id()) + ".bin", ios::binary | ios::in | ios::out);
                while (myfile.read((char *)&A, sizeof(A)))
                {
                    A.set_quantity(quantity);
                    A.product_name(n);
                    A.set_price(B.get_price());
                    int current = myFile.tellg();
                    int oneblock = sizeof(A);
                    myfile.seekg(current - oneblock);
                    myfile.write((char *)&A, sizeof(A));
                    myfile.close();
                }
            }
        }
        myFile.close();
        return check;
    }
    void manage_inventory()
    {
        Inventory A;
        cout << "---Product Catalog---\n"
             << endl;
        cout << "Item Name\t\t\t\t\tPrice" << endl;
        ifstream myFile;
        myFile.open("inventory.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            cout << A.get_product_name() << "\t\t\t\t\t\t" << A.get_price() << endl;
        }
        myFile.close();
        int option;
        cout << "\t-------------------------" << endl;
        cout << "\t1.Add Item" << endl;
        cout << "\t2.Remove Item" << endl;
        cout << "\t3.Update Item" << endl;
        cout << "\t4.Logout" << endl;
        cout << "-----------------------" << endl;
        do
        {
            cout << "Choose Option:";
            cin >> option;
        } while (option < 1 || option > 4);
        if (option == 1)
        {
            Inventory A;
            string n;
            int quantity;
            fstream myfile("inventory" + to_string(this->get_store_id()) + ".bin", ios::binary | ios::app);
            cout << "Enter Name:";
            cin.ignore();
            getline(cin, n);
            bool valid = check_inventory(n);
            while (valid == false)
            {
                cout << "Enter Name:";
                getline(cin, n);
                valid = check_inventory(n);
            }
            bool check = check_already(n);
            while (check == true)
            {
                cout << "Enter Name:";
                getline(cin, n);
                check = check_already(n);
            }
            cout << "Enter Quantity:";
            cin >> quantity;
            A.product_name(n);
            A.set_quantity(quantity);
            fstream f("inventory.bin", ios::binary | ios::in);
            Inventory I;
            double price;
            while (f.read((char *)&I, sizeof(I)))
            {
                if (I.get_product_name() == n)
                {
                    price = I.get_price();
                }
            }
            f.close();
            A.set_price(price);
            myfile.write((char *)&A, sizeof(A));
            myfile.close();
            system("clear");
            manage_inventory();
        }
        else if (option == 2)
        {
            string nme;
            cout << "Name:";
            cin.ignore();
            getline(cin, nme);
            Inventory A;
            fstream myFile;
            myFile.open("inventory" + to_string(this->get_store_id()) + ".bin", ios::binary | ios::in);
            ofstream myFile_temp("temp.bin", ios::app | ios::binary);
            while (myFile.read((char *)&A, sizeof(A)))
            {
                if (A.get_product_name() != nme)
                {
                    myFile_temp.write((char *)&A, sizeof(A));
                }
            }
            myFile.close();
            myFile_temp.close();
            string name = "inventory" + to_string(this->get_store_id()) + ".bin";
            char arr[100];
            strcpy(arr, name.c_str());
            remove(arr);
            rename("temp.bin", arr);
            system("clear");
            manage_inventory();
        }
        else if (option == 3)
        {
            // cout << this->get_store_id() << endl;
            Inventory M;
            string n, p;
            fstream myfile;
            myfile.open("inventory" + to_string(this->get_store_id()) + ".bin", ios::binary | ios::app);
            cout << "Enter Item Name You Want to Update:";
            cin.ignore();
            getline(cin, n);
            bool valid = check_item(n);
            while (valid == false)
            {
                cout << "Enter Item Name You Want to Update:";
                getline(cin, n);
                valid = check_item(n);
            }
            myfile.close();
            system("clear");
            manage_inventory();
        }
        else if (option == 4)
        {
            system("clear");
            login();
        }
    }
};
class Customer : public Person
{
    char cnic[20];

public:
    void set_cnic(string n = "")
    {
        strcpy(cnic, n.c_str());
    }
    string get_cnic()
    {
        return cnic;
    }
    bool checkvalidity(string n)
    {
        bool check = false;
        Customer A;
        ifstream myFile;
        myFile.open("customer.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_name() == n)
            {
                cout << "Username is already Taken" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    bool checkspam(string n)
    {
        bool check = false;
        Customer A;
        ifstream myFile;
        myFile.open("spam.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_name() == n)
            {
                cout << "Spam Username" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    void registeration()
    {
        cout << "---Customer SignUp---" << endl;
        Customer A;
        string n, p, c, ci;
        char g;
        fstream myfile;
        myfile.open("customer.bin", ios::binary | ios::app);
        cout << "Name:";
        cin.ignore();
        getline(cin, n);
        bool check2 = checkspam(n);
        while (check2 == true)
        {
            cout << "Name:";
            getline(cin, n);
            check2 = checkspam(n);
        }
        bool valid = checkvalidity(n);
        while (valid == true)
        {
            cout << "Name:";
            getline(cin, n);
            valid = checkvalidity(n);
        }
        cout << "Password (one upper, one lower case letter, one special character,length 9):";
        getline(cin, p);
        bool check = PasswordCheck(p);
        while (check == false)
        {
            cout << "Password (one upper, one lower case letter, one special character,length 9):";
            getline(cin, p);
            check = PasswordCheck(p);
        }
        cout << "Gender(M)/(F):";
        cin >> g;
        cout << "CNIC (13-digits):";
        cin.ignore();
        getline(cin, c);
        bool check1 = cnicCheck(c);
        while (check1 == false)
        {
            cout << "CNIC (13-digits):";
            getline(cin, c);
            check1 = cnicCheck(c);
        }
        cout << "City:";
        getline(cin, ci);
        A.set_name(n);
        A.set_password(p);
        A.set_city(ci);
        // A.set_gender(g);
        A.set_cnic(c);
        myfile.write((char *)&A, sizeof(A));
        myfile.close();
    }
    void edit_profile()
    {
        string n, p;
        cout << "---Edit Profile---" << endl;
        cout << "Name:";
        cin.ignore();
        getline(cin, n);
        cout << "Password (one upper, one lower case letter, one special character):";
        getline(cin, p);
        bool check = PasswordCheck(p);
        while (check == false)
        {
            cout << "Password (one upper, one lower case letter, one special character):";
            getline(cin, p);
            check = PasswordCheck(p);
        }
        fstream myFile("customer.bin", ios::in | ios::out | ios::binary);
        while (myFile.read((char *)&(*this), sizeof(*this)))
        {
            this->set_name(n);
            this->set_password(p);
            int current = myFile.tellg();
            int oneblock = sizeof(*this);
            myFile.seekg(current - oneblock);
            myFile.write((char *)&*this, sizeof(*this));
            myFile.close();
        }
    }
    void login()
    {
        int opt;
        system("clear");
        cout << "------------------------" << endl;
        cout << "\tCustomer Page" << endl;
        cout << "\t1.Login" << endl;
        cout << "\t2.Sign up" << endl;
        cout << "\t3.Back" << endl;
        cout << "------------------------" << endl;
        do
        {
            cout << "Choose Option:";
            cin >> opt;
        } while (opt < 1 || opt > 4);
        if (opt == 1)
        {
            string nme;
            string pass;
            system("clear");
            cout << "---Customer Login---" << endl;
            cout << "Name:";
            cin.ignore();
            getline(cin, nme);
            cout << "password:";
            getline(cin, pass);
            ifstream myFile;
            Customer A;
            myFile.open("customer.bin", ios::binary | ios::in);
            while (myFile.read((char *)&(A), sizeof(A)))
            {
                if (A.get_name() == nme && A.get_pass() == pass)
                {
                    system("clear");
                    cout << "Successfully Login" << endl;
                    int opt;
                jump:
                    cout << "---Customer Main---" << endl;
                    cout << "1.Edit Profile" << endl;
                    cout << "2.Check Profile" << endl;
                    cout << "3.Log Out" << endl;
                    cout << "4.Shopping" << endl;
                    cout << "-------------------" << endl;
                    do
                    {
                        cout << "Choose Option:";
                        cin >> opt;
                    } while (opt < 1 || opt > 4);
                    if (opt == 1)
                    {
                        system("clear");
                        A.edit_profile();
                        goto jump;
                    }
                    else if (opt == 2)
                    {
                        A.display();
                        sleep(3);
                        system("clear");
                        goto jump;
                    }
                    else if (opt == 3)
                    {
                        system("clear");
                        login();
                    }
                    else if (opt == 4)
                    {
                        Inventory A;
                        cout << "---Product Catalog---\n"
                             << endl;
                        cout << "Item Name\t\t\t\t\tPrice" << endl;
                        ifstream myFile;
                        myFile.open("inventory.bin", ios::binary | ios::in);
                        while (myFile.read((char *)&A, sizeof(A)))
                        {
                            cout << A.get_product_name() << "\t\t\t\t\t\t" << A.get_price() << endl;
                        }
                        myFile.close();
                        string item;
                    go:
                        cout << "\t---Online Shopping---" << endl;
                        cout << "Enter Item:";
                        cin.ignore();
                        getline(cin, item);
                        bool check = find_item(item);
                        while (check == false)
                        {
                            // system("clear");
                            cout << "Enter Item:";
                            cin.ignore();
                            getline(cin, item);
                            check = find_item(item);
                        }
                        sleep(3);
                        // cout << "\nEnter Your City:";
                        // cin >> id;
                        // bool valid = valid_id(id);
                        // while (valid == false)
                        // {
                        //     cout << "\nEnter Your City:";
                        //     cin >> id;
                        //     valid = valid_id(id);
                        // }
                        // sleep(5);
                        // cout<<"2.Checkout"<<endl;
                        system("clear");
                        // goto go;
                    }
                }
            }
            myFile.close();
            goto jump;
        }
        else if (opt == 2)
        {
            system("clear");
            registeration();
            system("clear");
            login();
        }
        else if (opt == 3)
        {
            system("clear");
            main_display();
        }
    }
    bool find_item(string id)
    {
        bool check = false;
        int choice;
        Manager A;
        ifstream myFile;
        bool valid = true;
        int quan;
        Cart C;
        myFile.open("manager.bin", ios::binary | ios::in);
        // cout << "\nProduct  Quantity   Price" << endl;
        while (myFile.read((char *)&A, sizeof(A)))
        {
            // cout << A.get_store_id() << endl;
            if (valid == true)
            {
                ifstream myFile1;
                Inventory B;
                myFile1.open("inventory" + to_string(A.get_store_id()) + ".bin", ios::binary | ios::in);
                while (myFile1.read((char *)&B, sizeof(B)))
                {

                    if (B.get_product_name() == id)
                    {
                        cout << "Enter Quantity:";
                        cin >> quan;
                        if (quan <= B.get_quantity())
                        {
                            int option;
                            cout << "1.Add to Cart" << endl;
                            cout << "Option:";
                            cin >> option;
                            if (option == 1)
                            {
                                fstream c;
                                c.open("cart.bin", ios::binary | ios::app);
                                C.product_name(id);
                                C.set_price(B.get_price());
                                C.set_quantity(quan);
                                c.write((char *)&C, sizeof(C));
                                c.close();
                            }
                            Inventory B1;
                            ifstream myFile2;
                            myFile2.open("inventory" + to_string(A.get_store_id()) + ".bin", ios::binary | ios::in);
                            while (myFile2.read((char *)&B1, sizeof(B1)))
                            {
                                if (B1.get_product_name() == id)
                                {
                                    // cout << B.get_product_name() << "\t    " << B.get_quantity() << "\t     " << B.get_price() << endl;
                                    Inventory A1;
                                    fstream myfile("inventory" + to_string(A.get_store_id()) + ".bin", ios::binary | ios::in | ios::out);
                                    while (myfile.read((char *)&A1, sizeof(A1)))
                                    {
                                        A1.set_quantity(B.get_quantity() - quan);
                                        A1.product_name(id);
                                        A1.set_price(B.get_price());
                                        int current = myFile2.tellg();
                                        int oneblock = sizeof(A1);
                                        myfile.seekg(current - oneblock);
                                        myfile.write((char *)&A1, sizeof(A1));
                                        myfile.close();
                                    }
                                }
                                check = true;
                                valid = false;
                            }
                            myFile2.close();
                        }
                        cout << "2.Checkout:";
                        cin >> choice;
                        if (choice == 2)
                        {
                            check_out(A.get_store_id());
                        }
                    }
                }
                myFile1.close();
            }
        }
        myFile.close();
        return check;
    }
    void check_out(int id)
    {
        Cart A;
        Simulation S;
        double time;
        ifstream myFile;
        double price = 0;
        myFile.open("cart.bin", ios::binary | ios::in);
        cout << "Product\tQuantity\tPrice" << endl;
        while (myFile.read((char *)&A, sizeof(A)))
        {
            cout << A.get_product_name() << "\t" << A.get_quantity() << "\t" << A.get_price() << endl;
            price += A.get_price() * A.get_quantity();
            time += 2 * A.get_quantity();
        }
        myFile.close();
        cout << "Total Bill:" << price << endl;
        if (price > 5000)
        {
            cout << "You are Given 5 percent Discount" << endl;
            cout << "Discount:" << 0.05 * price << endl;
            cout << "Bill after Discount:" << price - (0.05 * price) << endl;
        }
        int opt;
    go:
        cout << "---Payment Option---" << endl;
        cout << "1.Cash on Delivery" << endl;
        cout << "2.Card Service" << endl;
        cout << "3.Easypaisa" << endl;
        cout << "4.Jazzcash" << endl;
        do
        {
            cout << "Choose Option:";
            cin >> opt;
        } while (opt < 1 || opt > 4);
        Payment *P;
        switch (opt)
        {
        case 1:
            P = new COD;
            time += 60;
            break;
        case 2:
            P = new Card;
            time += 120;
            break;
        case 3:
            P = new Easypaisa;
            break;
        case 4:
            P = new Jazzcash;
            break;
        default:
            goto go;
            break;
        }
        P->pay();
        delete P;
        S.settime(time);
        cout << "\nTotal Time:" << S.gettime() << endl;
        fstream my;
        my.open("simulation.bin", ios::binary | ios::app);
        my.write((char *)&S, sizeof(S));
        my.close();
        Feedback F;
        string n;
        fstream myfile;
        myfile.open("feedback" + to_string(id) + ".bin", ios::binary | ios::app);
        cout << "\nFeedback:";
        cin.ignore();
        getline(cin, n);
        F.set_feed(n);
        myfile.write((char *)&F, sizeof(F));
        myfile.close();
        fstream myfile1;
        myfile.open("revenue.bin", ios::binary | ios::app);
        myfile.write((char *)&(A), sizeof(A));
        Cart C;
        fstream myFile1;
        myFile1.open("cart.bin", ios::binary | ios::in);
        ofstream myFile_temp("temp.bin", ios::app | ios::binary);
        myFile1.close();
        myFile_temp.close();
        remove("cart.bin");
        rename("temp.bin", "cart.bin");
        main_display();
    }
    bool check_inventory(string n, int id)
    {
        bool check = false;
        Inventory A;
        ifstream myFile;
        myFile.open("inventory" + to_string(id) + ".bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_product_name() == n)
            {
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    bool valid_id(string id)
    {
        Inventory B;
        bool check = false;
        Manager A;
        ifstream myFile;
        myFile.open("manager.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_city() == id)
            {
                cout << "Store Found in Your City" << endl;
                ifstream myFile1;
                cout << "\nProduct  Quantity   Price" << endl;
                myFile1.open("inventory" + to_string(A.get_store_id()) + ".bin", ios::binary | ios::in);
                while (myFile1.read((char *)&B, sizeof(B)))
                {
                    cout << B.get_product_name() << "\t    " << B.get_quantity() << "\t     " << B.get_price() << endl;
                }
                myFile1.close();
                int opt;
                cout << "-------------------------" << endl;
                cout << "\t1.Add to Cart" << endl;
                cout << "-------------------------" << endl;
                do
                {
                    cout << "Choose Option:";
                    cin >> opt;
                } while (opt < 1 || opt > 1);
                if (opt == 1)
                {
                    string n;
                    cout << "Enter Name:";
                    cin.ignore();
                    getline(cin, n);
                    bool valid = check_inventory(n, A.get_store_id());
                    while (valid == false)
                    {
                        cout << "Enter Name:";
                        getline(cin, n);
                        valid = check_inventory(n, A.get_store_id());
                    }
                }

                check = true;
            }
        }
        myFile.close();
        return check;
    }
    void display()
    {
        cout << "----------------------------" << endl;
        cout << "\tName:" << this->get_name() << endl;
        cout << "\tPassword:" << this->get_pass() << endl;
        cout << "\tCity:" << this->get_city() << endl;
        // cout << "\tGender:" << A.get_gender() << endl;
        cout << "\tCNIC:" << this->get_cnic() << endl;
        cout << "----------------------------" << endl;
    }
};

class Admin : public Person
{
public:
    void menu()
    {
        int opt;
        cout << "-------------Admin Main-------------" << endl;
        cout << "\t1.Register Manager" << endl;
        cout << "\t2.Assign Store" << endl;
        cout << "\t3.Manage Product Catalogue" << endl;
        cout << "\t4.Edit Profile" << endl;
        cout << "\t5.Remove Customer" << endl;
        cout << "\t6.Spam Customers" << endl;
        cout << "\t7.Log Out" << endl;
        cout << "\t8.Feedback" << endl;
        cout << "------------------------------------" << endl;
        do
        {
            cout << "Choose Option:";
            cin >> opt;
        } while (opt < 1 || opt > 8);
        if (opt == 1)
        {
            system("clear");
            regiester_manager();
            cout << "Regiester Successfully" << endl;
            sleep(3);
            system("clear");
            menu();
        }
        else if (opt == 2)
        {
            system("clear");
            assign_store();
            system("clear");
            menu();
        }
        else if (opt == 3)
        {
            system("clear");
            manage_product_catalogue();
            system("clear");
            menu();
        }
        else if (opt == 4)
        {
            system("clear");
            edit_profile();
            menu();
        }
        else if (opt == 5)
        {
            system("clear");
            remove_customer();
            menu();
        }
        else if (opt == 6)
        {
            system("clear");
            spam_customer();
            sleep(3);
            system("clear");
            menu();
        }
        else if (opt == 7)
        {
            Inventory I;
            system("clear");
            ofstream myfile;
            myfile.open("inventory.bin", ios::binary | ios::out);
            Pershible A;
            ifstream myFile;
            myFile.open("Meat.bin", ios::binary | ios::in);
            while (myFile.read((char *)&A, sizeof(A)))
            {
                I.product_name(A.get_product_name());
                I.set_price(A.get_price());
                myfile.write((char *)&(A), sizeof(A));
            }
            myFile.close();
            ifstream myFile1;
            myFile1.open("Fruit.bin", ios::binary | ios::in);
            while (myFile1.read((char *)&A, sizeof(A)))
            {
                I.product_name(A.get_product_name());
                myfile.write((char *)&(A), sizeof(A));
            }
            myFile1.close();
            ifstream myFile2;
            myFile2.open("Vegetable.bin", ios::binary | ios::in);
            while (myFile2.read((char *)&A, sizeof(A)))
            {
                I.product_name(A.get_product_name());
                myfile.write((char *)&(A), sizeof(A));
            }
            myFile2.close();
            ifstream myFile3;
            myFile3.open("Dairy.bin", ios::binary | ios::in);
            while (myFile3.read((char *)&A, sizeof(A)))
            {
                I.product_name(A.get_product_name());
                myfile.write((char *)&(A), sizeof(A));
            }
            myFile3.close();
            Non_pershible B;
            ifstream myFile4;
            myFile4.open("snacks.bin", ios::binary | ios::in);
            while (myFile4.read((char *)&B, sizeof(B)))
            {
                I.product_name(B.get_product_name());
                myfile.write((char *)&(B), sizeof(B));
            }
            myFile4.close();
            ifstream myFile5;
            myFile5.open("cereal.bin", ios::binary | ios::in);
            while (myFile5.read((char *)&B, sizeof(B)))
            {
                I.product_name(B.get_product_name());
                myfile.write((char *)&(B), sizeof(B));
            }
            myFile5.close();
            ifstream myFile6;
            myFile6.open("spices.bin", ios::binary | ios::in);
            while (myFile6.read((char *)&B, sizeof(B)))
            {
                I.product_name(B.get_product_name());
                myfile.write((char *)&(B), sizeof(B));
            }
            myFile6.close();
            ifstream myFile7;
            myFile6.open("grains.bin", ios::binary | ios::in);
            while (myFile7.read((char *)&B, sizeof(B)))
            {
                I.product_name(B.get_product_name());
                myfile.write((char *)&(B), sizeof(B));
            }
            myFile7.close();
            Household Ho;
            ifstream myFile8;
            myFile8.open("household.bin", ios::binary | ios::in);
            while (myFile8.read((char *)&Ho, sizeof(Ho)))
            {
                I.product_name(Ho.get_product_name());
                myfile.write((char *)&(Ho), sizeof(Ho));
            }
            myFile8.close();
            Hygiene H;
            ifstream myFile9;
            myFile9.open("hygiene.bin", ios::binary | ios::in);
            while (myFile9.read((char *)&H, sizeof(H)))
            {
                I.product_name(H.get_product_name());
                myfile.write((char *)&(H), sizeof(H));
            }
            myFile9.close();

            myfile.close();
            login();
        }
        else if (opt == 8)
        {
            system("clear");
            remove_feedback();
            menu();
        }
    }
    void spam_customer()
    {
        cout << "---Spam Customers List---" << endl;
        ifstream myFile;
        Customer a;
        myFile.open("spam.bin", ios::binary | ios::in);
        cout << "\nName"
             << "\t"
             << "Password" << endl;
        while (myFile.read((char *)&a, sizeof(a)))
        {
            cout << a.get_name() << "\t" << a.get_pass() << endl;
        }
        myFile.close();
    }
    void login()
    {
        // string n, p;
        // n = "Abdul";
        // p = "123";
        // ofstream myfile;
        // myfile.open("admin.bin", ios::binary | ios::out);
        // Admin A;
        // A.set_name(n);
        // A.set_password(p);
        // myfile.write((char *)&A, sizeof(A));
        // myfile.close();
        cout << "-------------------" << endl;
        cout << "\tAdmin Page" << endl;
        int opt;
        cout << "\t1.Login" << endl;
        cout << "\t2.Back" << endl;
        cout << "-------------------" << endl;
        do
        {
            cout << "Choose Option:";
            cin >> opt;
        } while (opt < 1 || opt > 2);
        if (opt == 1)
        {
            string nme;
            string pass;
            system("clear");
            cout << "---Admin Login---" << endl;
            cout << "Name:";
            cin.ignore();
            getline(cin, nme);
            cout << "password:";
            getline(cin, pass);
            ifstream myFile;
            Admin a;
            myFile.open("admin.bin", ios::binary | ios::in);
            while (myFile.read((char *)&a, sizeof(a)))
            {
                if (a.get_name() == nme && a.get_pass() == pass)
                {
                    system("clear");
                    cout << "Successfully Login" << endl;
                    menu();
                }
                else if (a.get_name() != nme || a.get_pass() != pass)
                {
                    system("clear");
                    login();
                }
            }
            myFile.close();
        }
        else
        {
            system("clear");
            main_display();
        }
    }
    void remove_feedback()
    {
        int nme;
        cout << "---Remove Store Feedback---" << endl;
        cout << "Enter Store ID:";
        cin >> nme;
        Feedback A;
        fstream myFile;
        myFile.open("feedback" + to_string(nme) + ".bin", ios::binary | ios::in);
        ofstream myFile_temp("temp.bin", ios::app | ios::binary);
        myFile.close();
        myFile_temp.close();
        string f = "feedback" + to_string(nme) + ".bin";
        char arr[100];
        strcpy(arr, f.c_str());
        remove(arr);
        rename("temp.bin", arr);
    }
    void remove_customer()
    {
        string nme;
        string pass;
        cout << "---Remove Customer---" << endl;
        cout << "Name:";
        cin.ignore();
        getline(cin, nme);
        // cout << "password:";
        // getline(cin, pass);
        Customer A;
        fstream myFile;
        myFile.open("customer.bin", ios::binary | ios::in);

        ofstream spam;
        spam.open("spam.bin", ios::binary | ios::app);

        ofstream myFile_temp("temp.bin", ios::app | ios::binary);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_name() != nme)
            {
                myFile_temp.write((char *)&A, sizeof(A));
            }
            if (A.get_name() == nme)
            {
                cout << "Customer Found and Deleted Successfully" << endl;
                spam.write((char *)&A, sizeof(A));
            }
        }
        myFile.close();
        spam.close();
        myFile_temp.close();
        remove("customer.bin");
        rename("temp.bin", "customer.bin");
    }
    void edit_profile()
    {
        string n, p;
        cout << "---Edit Profile---" << endl;
        cout << "Name:";
        cin.ignore();
        getline(cin, n);
        cout << "password:";
        getline(cin, p);
        Admin A;
        fstream myFile("admin.bin", ios::in | ios::out | ios::binary);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            A.set_name(n);
            A.set_password(p);
            int current = myFile.tellg();
            int oneblock = sizeof(A);
            myFile.seekg(current - oneblock);
            myFile.write((char *)&A, sizeof(A));
            myFile.close();
        }
    }
    bool checkvalidity1(string n)
    {
        bool check = false;
        Manager A;
        ifstream myFile;
        myFile.open("manager.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_name() == n)
            {
                cout << "Username is already assigned" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    void regiester_manager()
    {
        cout << "---Regiester Manager---" << endl;
        Manager M;
        string n, p;
        char g;
        fstream myfile;
        myfile.open("manager.bin", ios::binary | ios::app);
        cout << "Name:";
        cin.ignore();
        getline(cin, n);
        bool valid = checkvalidity1(n);
        while (valid == true)
        {
            cout << "Name:";
            getline(cin, n);
            valid = checkvalidity1(n);
        }
        cout << "Password (one upper, one lower case letter, one special character,length 9):";
        getline(cin, p);
        bool check = PasswordCheck(p);
        while (check == false)
        {
            cout << "Password (one upper, one lower case letter, one special character,length 9):";
            getline(cin, p);
            check = PasswordCheck(p);
        }
        int id;
        cout << "Store ID:";
        cin >> id;
        bool valid1 = check_id(id);
        while (valid1 == true)
        {
            cout << "Store ID:";
            cin >> id;
            valid1 = check_id(id);
        }
        M.set_name(n);
        M.set_password(p);
        M.set_store_id(id);
        fstream of("inventory" + to_string(id) + ".bin", ios::binary | ios::app);
        of.close();
        myfile.write((char *)&M, sizeof(M));
        myfile.close();
    }
    bool check_id(int id)
    {
        bool check = false;
        Manager A;
        ifstream myFile;
        myFile.open("manager.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_store_id() == id)
            {
                cout << "ID is Already Assigned" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    bool check_store(string p)
    {
        bool check = false;
        Manager A;
        ifstream myFile;
        myFile.open("manager.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_store() == p)
            {
                cout << "Store is Already Assigned" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    bool check_city(string c)
    {
        bool check = false;
        Manager A;
        ifstream myFile;
        myFile.open("manager.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_city() == c)
            {
                cout << "City is Already Assigned Store" << endl;
                check = true;
            }
        }
        myFile.close();
        return check;
    }
    bool check_manager(string n)
    {
        Manager A;
        bool check = false;
        string p, ci;
        ifstream myFile;
        myFile.open("manager.bin", ios::binary | ios::in);
        while (myFile.read((char *)&A, sizeof(A)))
        {
            if (A.get_name() == n)
            {
                cout << "Manager Found" << endl;
                Manager M;
                fstream myfile("manager.bin", ios::in | ios::out | ios::binary);
                while (myfile.read((char *)&M, sizeof(M)))
                {
                    M.set_name(n);
                    M.set_password(A.get_pass());
                    M.set_store_id(A.get_store_id());
                    cout << "Store Name:";
                    getline(cin, p);
                    bool valid = check_store(p);
                    while (valid == true)
                    {
                        cout << "Store Name:";
                        getline(cin, p);
                        valid = check_store(p);
                    }
                    cout << "City:";
                    getline(cin, ci);
                    bool valid1 = check_city(ci);
                    while (valid1 == true)
                    {
                        cout << "City:";
                        getline(cin, ci);
                        valid1 = check_city(ci);
                    }
                    M.set_store(p);
                    M.set_city(ci);
                    check = true;
                    int current = myFile.tellg();
                    int oneblock = sizeof(M);
                    myfile.seekg(current - oneblock);
                    myfile.write((char *)&M, sizeof(M));
                    myfile.close();
                }
            }
        }
        myFile.close();
        return check;
    }
    void assign_store()
    {
        Manager M;
        string n, p;
        fstream myfile;
        cout << "---Assign Store---" << endl;
        myfile.open("manager.bin", ios::binary | ios::app);
        cout << "Enter Manager Name You Want to assign Store:";
        cin.ignore();
        getline(cin, n);
        bool valid = check_manager(n);
        while (valid == false)
        {
            cout << "Enter Manager Name You Want to assign Store:";
            getline(cin, n);
            valid = check_manager(n);
        }
        myfile.close();
    }
    void manage_product_catalogue()
    {
        int opt;
        cout << "---Manage Product Catalogue---" << endl;
        cout << "\t1.Food" << endl;
        cout << "\t2.Personal Hygiene" << endl;
        cout << "\t3.Household" << endl;
        cout << "\t4.Back" << endl;
        cout << "------------------------------" << endl;
        do
        {
            cout << "Choose Option:";
            cin >> opt;
        } while (opt < 1 || opt > 4);
        if (opt == 1)
        {
            int choice;
            system("clear");
            cout << "----------Food---------" << endl;
            cout << "\t1.Perishable Goods" << endl;
            cout << "\t2.Non-Perishable Goods" << endl;
            cout << "\t3.Choose Category" << endl;
            cout << "-----------------------" << endl;
            do
            {
                cout << "Choose Option:";
                cin >> choice;
            } while (choice < 1 || choice > 3);
            if (choice == 1)
            {
                int option;
                system("clear");
                cout << "-------Pershible-------" << endl;
                cout << "\t1.Add Item" << endl;
                cout << "\t2.Remove Item" << endl;
                cout << "\t3.Update Item" << endl;
                cout << "\t4.Main Page" << endl;
                cout << "-----------------------" << endl;
                do
                {
                    cout << "Choose Option:";
                    cin >> option;
                } while (option < 1 || option > 4);
                if (option == 1)
                {
                    Pershible H;
                    system("clear");
                    H.add_item();
                }
                else if (option == 2)
                {
                    Pershible H;
                    system("clear");
                    H.remove_item();
                }
                else if (option == 3)
                {
                    Pershible H;
                    system("clear");
                    H.update_item();
                }
                else if (option == 4)
                {
                    system("clear");
                    manage_product_catalogue();
                }
            }
            else if (choice == 2)
            {
                int option;
                system("clear");
                cout << "-----Non-Pershible-----" << endl;
                cout << "\t1.Add Item" << endl;
                cout << "\t2.Remove Item" << endl;
                cout << "\t3.Update Item" << endl;
                cout << "\t4.Main Page" << endl;
                cout << "-----------------------" << endl;
                do
                {
                    cout << "Choose Option:";
                    cin >> option;
                } while (option < 1 || option > 4);
                if (option == 1)
                {
                    Non_pershible H;
                    system("clear");
                    H.add_item();
                }
                else if (option == 3)
                {
                    Non_pershible H;
                    system("clear");
                    H.update_item();
                }
                else if (option == 2)
                {
                    Non_pershible H;
                    system("clear");
                    H.remove_item();
                }
                else if (option == 4)
                {
                    system("clear");
                    manage_product_catalogue();
                }
            }
            else if (choice == 3)
            {
                system("clear");
                manage_product_catalogue();
            }
        }
        else if (opt == 2)
        {
            int option;
            system("clear");
            cout << "--------Hyiene--------" << endl;
            cout << "\t1.Add Item" << endl;
            cout << "\t2.Remove Item" << endl;
            cout << "\t3.Update Item" << endl;
            cout << "\t4.Main Page" << endl;
            cout << "-----------------------" << endl;
            do
            {
                cout << "Choose Option:";
                cin >> option;
            } while (option < 1 || option > 4);
            if (option == 1)
            {
                Hygiene H;
                system("clear");
                H.add_item();
            }
            else if (option == 3)
            {
                Hygiene H;
                system("clear");
                H.update_item();
            }
            else if (option == 2)
            {
                Hygiene H;
                system("clear");
                H.remove_item();
            }
            else if (option == 4)
            {
                system("clear");
                manage_product_catalogue();
            }
        }
        else if (opt == 3)
        {
            system("clear");
            int option;
            cout << "-------Household-------" << endl;
            cout << "\t1.Add Item" << endl;
            cout << "\t2.Remove Item" << endl;
            cout << "\t3.Update Item" << endl;
            cout << "\t4.Main Page" << endl;
            cout << "-----------------------" << endl;
            do
            {
                cout << "Choose Option:";
                cin >> option;
            } while (option < 1 || option > 4);
            if (option == 1)
            {
                Household H;
                H.add_item();
            }
            else if (option == 3)
            {
                Household H;
                H.update_item();
            }
            else if (option == 2)
            {
                Household H;
                H.remove_item();
            }
            else if (option == 4)
            {
                manage_product_catalogue();
            }
        }
        else if (opt == 4)
        {
            system("clear");
            menu();
        }
    }
    void display()
    {
        cout << "Name:" << this->get_name() << endl;
        cout << "Password:" << this->get_pass() << endl;
    }
};
void fun()
{
    Admin A;
    A.manage_product_catalogue();
}
void main_display()
{
    int option;
    cout << "-----------------------" << endl;
    cout << "\t1.Admin" << endl;
    cout << "\t2.Customer" << endl;
    cout << "\t3.Manager" << endl;
    cout << "\t4.Exit" << endl;
    cout << "-----------------------" << endl;
    do
    {
        cout << "Choose Option:";
        cin >> option;
    } while (option < 1 || option > 4);
    if (option == 2)
    {
        system("clear");
        Customer A;
        A.login();
    }
    else if (option == 4)
    {
        exit(0);
    }

    else if (option == 1)
    {
        system("clear");
        Admin A1;
        A1.login();
    }
    else if (option == 3)
    {
        system("clear");
        Manager A1;
        A1.login();
    }
}
int main()
{
    main_display();
}
