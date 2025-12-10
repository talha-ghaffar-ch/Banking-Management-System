// Libraries:
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

// Abstract Parent Class:
class Bank {

    // Private Data Members:
private:
    int account_number;
    string name;
    double balance;
    string type;

    // Public Data Members and Functions:
public:

    // Default Constructor:
    Bank() {
        account_number = 0;
        name = "";
        balance = 0.00;
        type = "";
    }

    // Parameterized Constructor:
    Bank(int account_number, string name, double balance, string type) {
        this->account_number = account_number;
        this->name = name;
        this->balance = balance;
        this->type = type;
    }

    // Setter Functions:
    void set_account_number(int account_number) {
        this->account_number = account_number;
    }
    void set_name(string name) {
        this->name = name;
    }
    void set_balance(double balance) {
        this->balance = balance;
    }
    void set_type(string type) {
        this->type = type;
    }

    // Getter Functions:
    int get_account_number() const {
        return account_number;
    }
    string get_name() const {
        return name;
    }
    double get_balance() const {
        return balance;
    }
    string get_type() const {
        return type;
    }

    // Pure Virtual Functions:
    virtual void create_account() = 0;
    virtual void save_to_file(string file_name) = 0;
    virtual void modify_account() = 0;
    virtual void delete_account() = 0;
    virtual void display_bank_name() const = 0;

    // Friend Functions:
    friend void display_account_details(const Bank& account);
    friend void perform_transaction(Bank& account);
};

// Vector:
vector<Bank*> account;

// Functions:
void display_account_details(const Bank& account) {
    system("cls");
    cout << "------------------------" << endl;
    cout << endl;
    account.display_bank_name();
    cout << "Account Number: " << account.get_account_number() << endl;
    cout << "Account Holder's Name: " << account.get_name() << endl;
    cout << "Account Balance: " << account.get_balance() << endl;
    cout << "Account Type: " << account.get_type() << endl;
    cout << endl;
    cout << "------------------------" << endl;
    cout << endl;
    cout << "Press Enter to Continue..." << endl;
    cin.ignore();
    cin.get();
}

void perform_transaction(Bank& account) {
    system("cls");
    int choice;
    double amount;
    cout << "------------------------" << endl;
    cout << endl;
    cout << "1. Deposit Amount" << endl;
    cout << "2. Withdraw Amount" << endl;
    cout << endl;
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Enter Amount to Deposit: ";
        cin >> amount;
        account.set_balance(account.get_balance() + amount);
        cout << "Amount Deposited Successfully!" << endl;
        cout << endl;
        cout << "------------------------" << endl;
        cout << endl;
        system("cls");
        cout << "------------------------" << endl;
        cout << endl;
        cout << "  Transaction Receipt   " << endl;
        cout << endl;
        cout << "Account Holder: " << account.get_name() << endl;
        cout << "Account Type: " << account.get_type() << endl;
        cout << endl;
        cout << "Deposited Amount: " << "Rs. " << amount << endl;
        cout << "Current Balance: " << "Rs. " << account.get_balance() << endl;
        cout << endl;
        cout << "------------------------" << endl;
        cout << endl;
        cout << "Press Enter to Continue..." << endl;
        cin.ignore();
        cin.get();
        break;

    case 2:
        cout << "Enter Amount to Withdraw: ";
        cin >> amount;
        if (amount <= account.get_balance()) {
            account.set_balance(account.get_balance() - amount);
            cout << "Amount Withdrawn Successfully!" << endl;
            cout << endl;
            cout << "------------------------" << endl;
            cout << endl;
            system("cls");
            cout << "------------------------" << endl;
            cout << endl;
            cout << "  Transaction Receipt   " << endl;
            cout << endl;
            cout << "Account Holder: " << account.get_name() << endl;
            cout << "Account Type: " << account.get_type() << endl;
            cout << endl;
            cout << "Withdrawn Amount: " << "Rs. " << amount << endl;
            cout << "Current Balance: " << "Rs. " << account.get_balance() << endl;
            cout << endl;
            cout << "------------------------" << endl;
            cout << endl;
            cout << "Press Enter to Continue..." << endl;
            cin.ignore();
            cin.get();
        }
        else {
            cout << endl;
            cout << "Insufficient Balance!" << endl;
            cout << endl;
            cout << "------------------------" << endl;
            cout << endl;
            cout << "Press Enter to Continue..." << endl;
            cin.ignore();
            cin.get();
        }
        break;

    default:
        cout << endl;
        cout << "Invalid Choice Entered!" << endl;
        cout << endl;
        cout << "------------------------" << endl;
        cout << endl;
        cout << "Press Enter to Continue..." << endl;
        cin.ignore();
        cin.get();
        break;
    }
}

// Child Class:
class UBL : public Bank {

    // Private Data Members:
private:
    string bank_name;

    // Public Data Members and Functions:
public:

    // Default Constructor:
    UBL() {
        bank_name = "United Bank Limited";
    }

    // Getter Functions:
    string get_bank_name() const {
        return bank_name;
    }

    // Functions:
    void create_account() override {
        system("cls");
        int account_number;
        string name;
        double balance;
        string type;
        cout << "------------------------" << endl;
        cout << "Enter Account Number: ";
        cin >> account_number;
        set_account_number(account_number);
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);
        set_name(name);
        cout << "Enter Account Type (Current/Saving): ";
        cin >> type;
        set_type(type);
        cout << "Enter Initial Deposit Amount: ";
        cin >> balance;
        set_balance(balance);
        cout << endl;
        cout << "Account Created Successfully!" << endl;
        cout << "------------------------" << endl;
    }

    void save_to_file(string file_name) override {
        ofstream file(file_name + "_" + to_string(get_account_number()));

        file << get_account_number() << endl;
        file << get_name() << endl;
        file << get_type() << endl;
        file << get_balance() << endl;

        file.close();
    }

    void modify_account() override {
        system("cls");
        string name;
        string type;
        cout << "------------------------" << endl;
        cout << "Enter New Name: ";
        cin.ignore();
        getline(cin, name);
        set_name(name);
        cout << "Enter New Type (Current/Saving): ";
        cin >> type;
        set_type(type);
        cout << endl;
        cout << "Account Modified Successfully!" << endl;
        cout << "------------------------" << endl;
    }

    void delete_account() override {
        system("cls");
        int choice;
        cout << "------------------------" << endl;
        cout << "Are you sure you want to delete account? " << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == 1) {
            auto it = find(account.begin(), account.end(), this);
            if (it != account.end()) {
                account.erase(it);
                cout << "Account Deleted Successfully!" << endl;
                cout << "------------------------" << endl;
            }
            else {
                cout << "Account Not Found!" << endl;
                cout << "------------------------" << endl;
            }
        }
    }

    void display_bank_name() const override {
        cout << "Bank Name: " << get_bank_name() << endl;
    }
};

// Child Class
class HBL : public Bank {

    // Private Data Members:
private:
    string bank_name;

    // Public Data Members and Functions:
public:

    // Default Constructor:
    HBL() {
        bank_name = "Habib Bank Limited";
    }

    // Getter Functions:
    string get_bank_name() const {
        return bank_name;
    }

    // Functions:
    void create_account() override {
        system("cls");
        int account_number;
        string name;
        double balance;
        string type;
        cout << "------------------------" << endl;
        cout << "Enter Account Number: ";
        cin >> account_number;
        set_account_number(account_number);
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);
        set_name(name);
        cout << "Enter Account Type (Current/Saving): ";
        cin >> type;
        set_type(type);
        cout << "Enter Initial Deposit Amount: ";
        cin >> balance;
        set_balance(balance);
        cout << endl;
        cout << "Account Created Successfully!" << endl;
        cout << "------------------------" << endl;
    }

    void save_to_file(string file_name) override {
        ofstream file(file_name + "_" + to_string(get_account_number()));

        file << get_account_number() << endl;
        file << get_name() << endl;
        file << get_type() << endl;
        file << get_balance() << endl;

        file.close();
    }

    void modify_account() override {
        system("cls");
        string name;
        string type;
        cout << "------------------------" << endl;
        cout << "Enter New Name: ";
        cin.ignore();
        getline(cin, name);
        set_name(name);
        cout << "Enter New Type (Current/Saving): ";
        cin >> type;
        set_type(type);
        cout << endl;
        cout << "Account Modified Successfully!" << endl;
        cout << "------------------------" << endl;
    }

    void delete_account() override {
        system("cls");
        int choice;
        cout << "------------------------" << endl;
        cout << "Are you sure you want to delete account? " << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == 1) {
            auto it = find(account.begin(), account.end(), this);
            if (it != account.end()) {
                account.erase(it);
                cout << "Account Deleted Successfully!" << endl;
                cout << "------------------------" << endl;
            }
            else {
                cout << "Account Not Found!" << endl;
                cout << "------------------------" << endl;
            }
        }
    }

    void display_bank_name() const override {
        cout << "Bank Name: " << get_bank_name() << endl;
    }
};

// Child Class:
class Alfalah : public Bank {

    // Private Data Members:
private:
    string bank_name;

    // Public Data Members and Functions:
public:

    // Default Constructor:
    Alfalah() {
        bank_name = "Bank Alfalah";
    }

    // Getter Functions:
    string get_bank_name() const {
        return bank_name;
    }

    // Functions:
    void create_account() override {
        system("cls");
        int account_number;
        string name;
        double balance;
        string type;
        cout << "------------------------" << endl;
        cout << "Enter Account Number: ";
        cin >> account_number;
        set_account_number(account_number);
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);
        set_name(name);
        cout << "Enter Account Type (Current/Saving): ";
        cin >> type;
        set_type(type);
        cout << "Enter Initial Deposit Amount: ";
        cin >> balance;
        set_balance(balance);
        cout << endl;
        cout << "Account Created Successfully!" << endl;
        cout << "------------------------" << endl;
    }

    void save_to_file(string file_name) override {
        ofstream file(file_name + "_" + to_string(get_account_number()));

        file << get_account_number() << endl;
        file << get_name() << endl;
        file << get_type() << endl;
        file << get_balance() << endl;

        file.close();
    }

    void modify_account() override {
        system("cls");
        string name;
        string type;
        cout << "------------------------" << endl;
        cout << "Enter New Name: ";
        cin.ignore();
        getline(cin, name);
        set_name(name);
        cout << "Enter New Type (Current/Saving): ";
        cin >> type;
        set_type(type);
        cout << endl;
        cout << "Account Modified Successfully!" << endl;
        cout << "------------------------" << endl;
    }

    void delete_account() override {
        system("cls");
        int choice;
        cout << "------------------------" << endl;
        cout << "Are you sure you want to delete account? " << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == 1) {
            auto it = find(account.begin(), account.end(), this);
            if (it != account.end()) {
                account.erase(it);
                cout << "Account Deleted Successfully!" << endl;
                cout << "------------------------" << endl;
            }
            else {
                cout << "Account Not Found!" << endl;
                cout << "------------------------" << endl;
            }
        }
    }

    void display_bank_name() const override {
        cout << "Bank Name: " << get_bank_name() << endl;
    }
};

// Child Class:
class Meezan : public Bank {

    // Private Data Members:
private:
    string bank_name;

    // Public Data Members and Functions:
public:

    // Default Constructor:
    Meezan() {
        bank_name = "Meezan Bank";
    }

    // Getter Functions:
    string get_bank_name() const {
        return bank_name;
    }

    // Functions:
    void create_account() override {
        system("cls");
        int account_number;
        string name;
        double balance;
        string type;
        cout << "------------------------" << endl;
        cout << "Enter Account Number: ";
        cin >> account_number;
        set_account_number(account_number);
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);
        set_name(name);
        cout << "Enter Account Type (Current/Saving): ";
        cin >> type;
        set_type(type);
        cout << "Enter Initial Deposit Amount: ";
        cin >> balance;
        set_balance(balance);
        cout << endl;
        cout << "Account Created Successfully!" << endl;
        cout << "------------------------" << endl;
    }

    void save_to_file(string file_name) override {
        ofstream file(file_name + "_" + to_string(get_account_number()));

        file << get_account_number() << endl;
        file << get_name() << endl;
        file << get_type() << endl;
        file << get_balance() << endl;

        file.close();
    }

    void modify_account() override {
        system("cls");
        string name;
        string type;
        cout << "------------------------" << endl;
        cout << "Enter New Name: ";
        cin.ignore();
        getline(cin, name);
        set_name(name);
        cout << "Enter New Type (Current/Saving): ";
        cin >> type;
        set_type(type);
        cout << endl;
        cout << "Account Modified Successfully!" << endl;
        cout << "------------------------" << endl;
    }

    void delete_account() override {
        system("cls");
        int choice;
        cout << "------------------------" << endl;
        cout << "Are you sure you want to delete account? " << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == 1) {
            auto it = find(account.begin(), account.end(), this);
            if (it != account.end()) {
                account.erase(it);
                cout << "Account Deleted Successfully!" << endl;
                cout << "------------------------" << endl;
            }
            else {
                cout << "Account Not Found!" << endl;
                cout << "------------------------" << endl;
            }
        }
    }

    void display_bank_name() const override {
        cout << "Bank Name: " << get_bank_name() << endl;
    }
};

// Child Class:
class Allied : public Bank {

    // Private Data Members:
private:
    string bank_name;

    // Public Data Members and Functions:
public:

    // Default Constructor:
    Allied() {
        bank_name = "Allied Bank";
    }

    // Getter Functions:
    string get_bank_name() const {
        return bank_name;
    }

    // Functions:
    void create_account() override {
        system("cls");
        int account_number;
        string name;
        double balance;
        string type;
        cout << "------------------------" << endl;
        cout << "Enter Account Number: ";
        cin >> account_number;
        set_account_number(account_number);
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);
        set_name(name);
        cout << "Enter Account Type (Current/Saving): ";
        cin >> type;
        set_type(type);
        cout << "Enter Initial Deposit Amount: ";
        cin >> balance;
        set_balance(balance);
        cout << endl;
        cout << "Account Created Successfully!" << endl;
        cout << "------------------------" << endl;
    }

    void save_to_file(string file_name) override {
        ofstream file(file_name + "_" + to_string(get_account_number()));

        file << get_account_number() << endl;
        file << get_name() << endl;
        file << get_type() << endl;
        file << get_balance() << endl;

        file.close();
    }

    void modify_account() override {
        system("cls");
        string name;
        string type;
        cout << "------------------------" << endl;
        cout << "Enter New Name: ";
        cin.ignore();
        getline(cin, name);
        set_name(name);
        cout << "Enter New Type (Current/Saving): ";
        cin >> type;
        set_type(type);
        cout << endl;
        cout << "Account Modified Successfully!" << endl;
        cout << "------------------------" << endl;
    }

    void delete_account() override {
        system("cls");
        int choice;
        cout << "------------------------" << endl;
        cout << "Are you sure you want to delete account? " << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == 1) {
            auto it = find(account.begin(), account.end(), this);
            if (it != account.end()) {
                account.erase(it);
                cout << "Account Deleted Successfully!" << endl;
                cout << "------------------------" << endl;
            }
            else {
                cout << "Account Not Found!" << endl;
                cout << "------------------------" << endl;
            }
        }
    }

    void display_bank_name() const override {
        cout << "Bank Name: " << get_bank_name() << endl;
    }
};

// Control Panel Class:
class Control_Panel {
public:
    
    //Public Data Members:
    void Main_Menu() {
        cout << "\t\t\t\t\t ----------------------------------------" << endl;
        cout << "\t\t\t\t\t ----------------------------------------" << endl;
        cout << endl;
        cout << "\t\t\t\t\t | WELCOME TO BANKING MANAGEMENT SYSTEM |" << endl;
        cout << endl;
        cout << "\t\t\t\t\t |           -- Developers --           |" << endl;
        cout << endl;
        cout << "\t\t\t\t\t |   Talha Ghaffar & M. Usama Zafar     |" << endl;
        cout << "\t\t\t\t\t |   Maria Rizvi   & Tehreem Maqsood    |" << endl;
        cout << endl;
        cout << "\t\t\t\t\t ----------------------------------------" << endl;
        cout << "\t\t\t\t\t ----------------------------------------" << endl;
        cout << endl;

        cout << "Press Enter to Continue..." << endl;
        cin.get();

        system("cls");
        int choice;
        while (true) {
            cout << "------------------------" << endl;
            cout << endl;
            cout << "1. Create Account" << endl;
            cout << "2. View Account Details" << endl;
            cout << "3. Perform Transaction" << endl;
            cout << "4. Modify Account" << endl;
            cout << "5. Delete Account" << endl;
            cout << "6. Exit" << endl;
            cout << endl;
            cout << "------------------------" << endl;
            cout << endl;
            cout << "Enter Choice: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                system("cls");
                int bank_choice;
                cout << "------------------------" << endl;
                cout << endl;
                cout << "1. United Bank Limited" << endl;
                cout << "2. Habib Bank Limited" << endl;
                cout << "3. Bank Alfalah" << endl;
                cout << "4. Meezan Bank" << endl;
                cout << "5. Allied Bank" << endl;
                cout << endl;
                cout << "------------------------" << endl;
                cout << endl;
                cout << "Select Bank: ";
                cin >> bank_choice;
                Bank* new_account;
                if (bank_choice == 1) {
                    new_account = new UBL();
                }
                else if (bank_choice == 2) {
                    new_account = new HBL();
                }
                else if (bank_choice == 3) {
                    new_account = new Alfalah();
                }
                else if (bank_choice == 4) {
                    new_account = new Meezan();
                }
                else if (bank_choice == 5) {
                    new_account = new Allied();
                }
                else {
                    cout << endl;
                    cout << "Invalid Choice Entered!" << endl;
                    cout << "------------------------" << endl;
                    continue;
                }
                new_account->create_account();
                account.push_back(new_account);
                cout << "Enter File Name to Save Account: ";
                string file_name;
                cin >> file_name;
                new_account->save_to_file(file_name);
                cout << endl;
                cout << "Press Enter to Continue..." << endl;
                cin.ignore();
                cin.get();
                break;
            }

            case 2: {
                system("cls");
                int account_number;
                cout << "------------------------" << endl;
                cout << endl;
                cout << "Enter Account Number: ";
                cin >> account_number;
                auto it = find_if(account.begin(), account.end(),
                    [account_number](Bank* acc) {
                        return acc->get_account_number() == account_number;
                    });
                if (it != account.end()) {
                    display_account_details(**it);
                }
                else {
                    cout << endl;
                    cout << "Account Not Found!" << endl;
                    cout << "------------------------" << endl;
                    cout << endl;
                    cout << "Press Enter to Continue..." << endl;
                    cin.ignore();
                    cin.get();
                }
                break;
            }

            case 3: {
                system("cls");
                int account_number;
                cout << "------------------------" << endl;
                cout << endl;
                cout << "Enter Account Number: ";
                cin >> account_number;
                auto it = find_if(account.begin(), account.end(),
                    [account_number](Bank* acc) {
                        return acc->get_account_number() == account_number;
                    });
                if (it != account.end()) {
                    perform_transaction(**it);
                }
                else {
                    cout << endl;
                    cout << "Account Not Found!" << endl;
                    cout << "------------------------" << endl;
                    cout << endl;
                    cout << "Press Enter to Continue..." << endl;
                    cin.ignore();
                    cin.get();
                }
                break;
            }

            case 4: {
                system("cls");
                int account_number;
                cout << "------------------------" << endl;
                cout << endl;
                cout << "Enter Account Number: ";
                cin >> account_number;
                auto it = find_if(account.begin(), account.end(),
                    [account_number](Bank* acc) {
                        return acc->get_account_number() == account_number;
                    });
                if (it != account.end()) {
                    (*it)->modify_account();
                }
                else {
                    cout << endl;
                    cout << "Account Not Found!" << endl;
                    cout << "------------------------" << endl;
                    cout << endl;
                    cout << "Press Enter to Continue..." << endl;
                    cin.ignore();
                    cin.get();
                }
                break;
            }

            case 5: {
                system("cls");
                int account_number;
                cout << "------------------------" << endl;
                cout << endl;
                cout << "Enter Account Number: ";
                cin >> account_number;
                auto it = find_if(account.begin(), account.end(),
                    [account_number](Bank* acc) {
                        return acc->get_account_number() == account_number;
                    });
                if (it != account.end()) {
                    (*it)->delete_account();
                }
                else {
                    cout << endl;
                    cout << "Account Not Found!" << endl;
                    cout << "------------------------" << endl;
                    cout << endl;
                    cout << "Press Enter to Continue..." << endl;
                    cin.ignore();
                    cin.get();
                }
                break;
            }

            case 6:
                cout << endl;
                cout << "Exiting..." << endl;
                cout << "------------------------" << endl;
                exit(0);

            default:
                cout << endl;
                cout << "Invalid Choice Entered!" << endl;
                cout << "------------------------" << endl;
                cout << endl;
                cout << "Press Enter to Continue..." << endl;
                cin.ignore();
                cin.get();
                break;
            }
            system("cls");
        }
    }
};

// Main Function:
int main() {
    // Control Panel Class Object:
    Control_Panel Main_Menu;
    Main_Menu.Main_Menu();
    
    return 0;
} 
