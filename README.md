# 🏦 Banking Management System – C++ (OOP Project)

A fully object-oriented **Banking Management System** developed in C++.  
This project demonstrates core OOP concepts such as **abstraction, inheritance, polymorphism, encapsulation, virtual functions, friend functions**, and **dynamic memory handling** with vectors.

The system supports multiple banks, allows account creation, modification, deletion, viewing details, and performing transactions (deposit/withdrawal).  
It also includes **file handling** to store account data.

---

## 🚀 Features

### ✔ Multi-Bank Support
Users can create accounts under different banks:
- United Bank Limited (UBL)  
- Habib Bank Limited (HBL)  
- Bank Alfalah  
- Meezan Bank  
- Allied Bank  

Each bank class inherits from the abstract `Bank` class.

---

## ✔ Account Operations

### ➤ Create Account
- Enter account number  
- Holder name  
- Account type (Current / Saving)  
- Initial deposit  
- Saved to file automatically  

### ➤ View Account Details
Displays:
- Bank name  
- Account number  
- Holder name  
- Account type  
- Current balance  

### ➤ Perform Transactions
Supports:
- **Deposit money**  
- **Withdraw money** (with balance validation)  
- Generates a transaction receipt  

### ➤ Modify Account
Update:
- Account holder's name  
- Account type  

### ➤ Delete Account
- Removes account from vector storage  
- Confirmation prompt included  

---

## 🛠 Concepts Used
This project applies multiple deeper C++ concepts:

### 🔹 OOP Principles
- Abstraction (abstract Bank class)
- Inheritance (Child classes: UBL, HBL, Alfalah, Meezan, Allied)
- Polymorphism (virtual functions used for runtime binding)
- Encapsulation (private data members with setters/getters)

### 🔹 Data Handling
- `vector<Bank*>` for dynamic account storage  
- Searching using `std::find_if()`  
- Deleting using vector erase  
- File I/O with `fstream` for saving account details  

### 🔹 UI & Control
- Clean menu-driven interface  
- Screen clearing using `system("cls")`  
- Pausing with `cin.get()`  

---

## 📦 How to Run

1. Save the project as `code.cpp`
2. Compile with: g++ code.cpp -o banking
3. Run: ./banking
