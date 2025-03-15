#include <iostream>
#include "LinkedList.h"


// Helper function to print the linked list
void printList(LinkedList<int>& list) {
    cout << "List: ";
    for (int i = 1; i <= list.Length(); i++) {
        cout << list.At(i) << " ";
    }
    cout << endl;
}

int main() {
    LinkedList<int> list;

    cout << "===================================" << endl;
    cout << "  TESTING LINKED LIST WITH UNDO" << endl;
    cout << "===================================\n" << endl;

    //Test code of Undo logic.... Check it out!
    cout << ">>> Test 1: Append and Insert" << endl;
    list.Append(5);
    list.Append(15); // Initial State  : 5 15
    list.InsertAt(1, 100); // Insert 100 at position 1
    list.InsertAt(3, 200); // Insert 200 at position 3
    printList(list); // Expected: 100 5 200 15

    cout << "\n>>> Test 2: Undo Last Insert" << endl;
    list.Undo(); // Undo insert 200
    printList(list); // Expected: 100 5 15

    cout << "\n>>> Test 3: Delete and Undo" << endl;
    list.DeleteAt(2); // Delete 5
    printList(list); // Expected: 100 15
    list.Undo(); // Undo delete 5
    printList(list); // Expected: 100 5 15

    cout << "\n>>> Test 4: Append and Delete All" << endl;
    list.Append(25);
    list.Append(30);
    printList(list); // Expected: 100 5 15 25 30

    while (list.Length() > 0) {
        list.DeleteAt(1);
        printList(list);
    }
    // Expected step-by-step deletion:
    // List: 5 15 25 30
    // List: 15 25 30
    // List: 25 30
    // List: 30
    // List: (empty)

    cout << "\n>>> Test 5: Undo All Deletions" << endl;
    list.Undo(); // Undo delete 30
    list.Undo(); // Undo delete 25
    list.Undo(); // Undo delete 15
    list.Undo(); // Undo delete 5
    list.Undo(); // Undo delete 100
    printList(list); // Expected: 100 5 15 25 30

    cout << "\n>>> Test 6: Final Undo to Restore Initial State" << endl;
    list.Undo(); // Undo append 30
    list.Undo(); // Undo append 25
    list.Undo(); // Undo insert 100
    printList(list); // Expected: 5 15



    cout << "\n>>> Test 7: Final Undo to Restore empty list" << endl;
    list.Undo();//Undo append 15
    list.Undo();//Undo append 5
    printList(list);

    cout << "\n>>> Test 8: Undo on Empty List" << endl;
        list.Undo();
        
    return 0;
}

