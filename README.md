
# 🛠 Custom Linked List with Undo Feature in C++  

## 📌 Overview  
This project is a **template-based implementation of a singly linked list in C++** with an **advanced Undo system**. The Undo functionality is built using a **stack data structure**, allowing the user to revert operations step by step.  

## 🔹 Features  
✅ **Generic Linked List using Templates** (works with any data type)  
✅ **Insert, Delete, and Traverse Operations**  
✅ **Undo Functionality Using Stack**  
✅ **Handles Consecutive Undo Operations**  
✅ **Efficient Memory Management**  

## 🚀 How It Works  
- The **linked list** supports basic operations like `Append`, `InsertAt`, and `DeleteAt`.  
- The **Undo system** saves operations in a **stack**, allowing users to **revert the last action**.  
- Supports **multiple consecutive undos**, even after a mix of operations.  

## 🏗 Implementation Details  
- **Data Structure Used:** **Singly Linked List (implemented as a template)**  
- **Undo Mechanism:** Implemented using a **stack** (LIFO behavior)  
- **Template Usage:** Allows the linked list to store any data type (`int`, `float`, `std::string`, etc.)  
- **Edge Case Handling:** Prevents undo on an empty list and ensures safe memory management  

## ⚙️ Compilation & Usage  
### **🔹 Compile then run the Code**  
**To make a compilation file:** g++ -std=c++11 -o linkedlist main.cpp  
**Run the code:** ./linkedlist  

## 📂 File Structure
📦 LinkedList-Undo  
 ┣ 📜 LinkedList.h      # Template-based Linked List (implementation inside)  
 ┣ 📜 main.cpp          # Test cases and execution logic  
 ┣ 📜 README.md         # Project documentation  