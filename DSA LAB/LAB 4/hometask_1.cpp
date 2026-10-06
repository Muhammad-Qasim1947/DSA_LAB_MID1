#include <iostream>
#include <string>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        DNode* cur = head;
        while (cur) {
            DNode* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    void displayForward() {
        if (!head) { cout << "(empty list)" << endl; return; }
        DNode* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " <-> ";
            cur = cur->next;
        }
        cout << endl;
    }

    void displayBackward() {
        if (!tail) { cout << "(empty list)" << endl; return; }
        DNode* cur = tail;
        while (cur) {
            cout << cur->data;
            if (cur->prev) cout << " <-> ";
            cur = cur->prev;
        }
        cout << endl;
    }

    void insertAtStart(int val) {
        DNode* node = new DNode(val);
        if (!head) {
            head = tail = node;
            return;
        }
        node->next = head;
        head->prev = node;
        head = node;
    }

    void insertAtEnd(int val) {
        DNode* node = new DNode(val);
        if (!tail) {
            head = tail = node;
            return;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    void insertAtPosition(int pos, int val) {
        if (pos <= 0 || !head) {
            insertAtStart(val);
            return;
        }

        DNode* cur = head;
        int idx = 0;
        while (cur && idx < pos) {
            cur = cur->next;
            idx++;
        }

        if (!cur) {
            insertAtEnd(val);
            return;
        }

        DNode* node = new DNode(val);
        DNode* before = cur->prev;

        node->prev = before;
        node->next = cur;
        cur->prev = node;

        if (before) before->next = node;
        else head = node;
    }

    void deleteFromStart() {
        if (!head) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        DNode* toDelete = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete toDelete;
    }

    void deleteFromEnd() {
        if (!tail) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        DNode* toDelete = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete toDelete;
    }

    void deleteValue(int val) {
        DNode* cur = head;
        while (cur) {
            if (cur->data == val) {
                if (cur == head) { deleteFromStart(); return; }
                if (cur == tail)  { deleteFromEnd();   return; }
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur;
                return;
            }
            cur = cur->next;
        }
        cout << "Value " << val << " not found in the list." << endl;
    }

    void reverse() {
        DNode* cur = head;
        DNode* temp = nullptr;
        while (cur) {
            temp = cur->prev;
            cur->prev = cur->next;
            cur->next = temp;
            cur = cur->prev;
        }
        temp = head;
        head = tail;
        tail = temp;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    CNode* head;
    CNode* tail;

public:
    CircularLinkedList() : head(nullptr), tail(nullptr) {}

    ~CircularLinkedList() {
        if (!head) return;
        CNode* cur = head->next;
        while (cur != head) {
            CNode* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        delete head;
    }

    void display() {
        if (!head) { cout << "(empty list)" << endl; return; }
        CNode* cur = head;
        do {
            cout << cur->data;
            if (cur->next != head) cout << " -> ";
            cur = cur->next;
        } while (cur != head);
        cout << " -> (back to " << head->data << ")" << endl;
    }

    void append(int val) {
        CNode* node = new CNode(val);
        if (!head) {
            head = tail = node;
            node->next = node;
            return;
        }
        tail->next = node;
        node->next = head;
        tail = node;
    }

    void insert(int pos, int val) {
        if (pos <= 0 || !head) {
            CNode* node = new CNode(val);
            if (!head) {
                head = tail = node;
                node->next = node;
                return;
            }
            node->next = head;
            tail->next = node;
            head = node;
            return;
        }

        CNode* cur = head;
        int idx = 0;

        while (idx < pos - 1 && cur->next != head) {
            cur = cur->next;
            idx++;
        }

        CNode* node = new CNode(val);
        node->next = cur->next;
        cur->next = node;
        if (cur == tail) tail = node;
    }

    void deleteValue(int val) {
        if (!head) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        if (head == tail && head->data == val) {
            delete head;
            head = tail = nullptr;
            return;
        }

        CNode* cur = head;
        CNode* prev = tail;
        do {
            if (cur->data == val) {
                prev->next = cur->next;
                if (cur == head) head = cur->next;
                if (cur == tail) tail = prev;
                delete cur;
                return;
            }
            prev = cur;
            cur = cur->next;
        } while (cur != head);

        cout << "Value " << val << " not found in the list." << endl;
    }

    bool search(int key) {
        if (!head) return false;
        CNode* cur = head;
        do {
            if (cur->data == key) return true;
            cur = cur->next;
        } while (cur != head);
        return false;
    }
};

class TurnNode {
public:
    string name;
    TurnNode* next;
    TurnNode(const string& n) : name(n), next(nullptr) {}
};

class TurnManager {
private:
    TurnNode* current; 
    TurnNode* tail;    

public:
    TurnManager() : current(nullptr), tail(nullptr) {}

    ~TurnManager() {
        if (!current) return;
        TurnNode* cur = current->next;
        while (cur != current) {
            TurnNode* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        delete current;
    }

    void addPlayer(const string& name) {
        TurnNode* node = new TurnNode(name);
        if (!current) {
            current = tail = node;
            node->next = node;
            return;
        }
        tail->next = node;
        node->next = current;
        tail = node;
    }

    string nextTurn() {
        if (!current) {
            cout << "No players in the game." << endl;
            return "";
        }
        current = current->next;
        cout << current->name << endl;
        return current->name;
    }

    void removePlayer(const string& name) {
        if (!current) {
            cout << "No players to remove." << endl;
            return;
        }

        if (current == tail && current->name == name) {
            delete current;
            current = tail = nullptr;
            return;
        }

        TurnNode* cur = current;
        TurnNode* prev = tail;
        do {
            if (cur->name == name) {
                prev->next = cur->next;
                if (cur == tail) tail = prev;
                if (cur == current) current = prev;
                delete cur;
                return;
            }
            prev = cur;
            cur = cur->next;
        } while (cur != current);

        cout << "Player " << name << " not found." << endl;
    }
};

int main() {
    cout << "=== Doubly Linked List ===" << endl;
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(30);
    dll.insertAtPosition(1, 20);

    cout << "Forward:  ";
    dll.displayForward();  
    cout << "Backward: ";
    dll.displayBackward(); 

    cout << "\nAfter reverse():" << endl;
    dll.reverse();
    cout << "Forward:  ";
    dll.displayForward(); 

    cout << "\nDeleting value 20:" << endl;
    dll.deleteValue(20);
    dll.displayForward(); 

    cout << "\n=== Circular Linked List ===" << endl;
    CircularLinkedList cll;
    cll.append(1);
    cll.append(2);
    cll.append(3);
    cll.insert(1, 99);
    cout << "List: ";
    cll.display();

    cout << "Search 99: " << (cll.search(99) ? "found" : "not found") << endl;
    cll.deleteValue(99);
    cout << "After deleting 99: ";
    cll.display();

    cout << "\nRound-Robin Turn Manager ===" << endl;
    TurnManager game;
    game.addPlayer("Ali");
    game.addPlayer("Beena");
    game.addPlayer("Cara");

    cout << "Four calls to nextTurn():" << endl;
    for (int i = 0; i < 4; i++) {
        game.nextTurn();
    }

    cout << "\nRemoving Cara mid-game, then two more turns:" << endl;
    game.removePlayer("Cara");
    game.nextTurn();
    game.nextTurn();

    return 0;
}