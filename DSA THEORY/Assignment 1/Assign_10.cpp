#include <iostream>
#include <string>
using namespace std;

class Combatant {
public:
    string name; int hp, atk;
    Combatant(string n = "", int h = 0, int a = 0) { name = n; hp = h; atk = a; }
};

class Node {
public:
    Combatant c;
    Node *prev, *next;
    Node(Combatant cc) { c = cc; prev = NULL; next = NULL; }
};

class Team { 
public:
    Node *head = NULL, *tail = NULL;
    string teamName;
    Team(string n = "") { teamName = n; }

    void addMember(Combatant c) {
        Node* nn = new Node(c);
        if(!head) head = tail = nn;
        else { tail->next = nn; nn->prev = tail; tail = nn; }
    }

    bool isEmpty() { return head == NULL; }

    Node* getAt(int pos) {
        int i = 1;
        for(Node* t = head; t; t = t->next, i++)
            if(i == pos) return t;
        return NULL;
    }

    Node* findByName(string name) {
        for(Node* t = head; t; t = t->next)
            if(t->c.name == name) return t;
        return NULL;
    }

    Node* findByInput(string in) {
        if(in[0] >= '1' && in[0] <= '9') return getAt(in[0] - '0');
        return findByName(in);
    }

    void removeNode(Node* n) {
        if(!n) return;
        if(n->prev) n->prev->next = n->next; else head = n->next;
        if(n->next) n->next->prev = n->prev; else tail = n->prev;
        delete n;
    }

    void displayNames() {
        cout << teamName << " remaining: ";
        for(Node* t = head; t; t = t->next) cout << t->c.name << (t->next ? ", " : "");
        cout << "\n";
    }

    void displayFull() {
        cout << "---- " << teamName << " ----\n";
        for(Node* t = head; t; t = t->next)
            cout << t->c.name << " | HP: " << t->c.hp << " | Atk: " << t->c.atk << "\n";
    }

    int totalHealth() {
        int sum = 0;
        for(Node* t = head; t; t = t->next) sum += t->c.hp;
        return sum;
    }
};

void performAttack(Node* att, Node* target, Team& targetTeam) {
    int dmg = att->c.atk * 2;
    target->c.hp -= dmg;
    cout << att->c.name << " attacks " << target->c.name << " for " << dmg << " damage!\n";
    if(target->c.hp <= 0) {
        cout << target->c.name << " has been defeated!\n";
        targetTeam.removeNode(target);
    }
}

int main() {
    Team heroTeam("Heroes"), enemyTeam("Enemies");

    heroTeam.addMember(Combatant("Arthur", 60, 4));
    heroTeam.addMember(Combatant("Lancelot", 55, 5));
    heroTeam.addMember(Combatant("Merlin", 40, 3));
    heroTeam.addMember(Combatant("Tristan", 50, 4));
    heroTeam.addMember(Combatant("Gawain", 65, 3));

    enemyTeam.addMember(Combatant("Goblin", 30, 2));
    enemyTeam.addMember(Combatant("Orc", 45, 3));
    enemyTeam.addMember(Combatant("Troll", 70, 4));
    enemyTeam.addMember(Combatant("Skeleton", 25, 2));
    enemyTeam.addMember(Combatant("DarkMage", 35, 5));

    for(int round = 1; round <= 10 && !heroTeam.isEmpty() && !enemyTeam.isEmpty(); round++) {
        cout << "\n===== Round " << round << " =====\n";

        string attIn, tarIn;
        Node *att = NULL, *tar = NULL;
        do {
            cout << "Choose attacker (name/pos): "; cin >> attIn;
            att = heroTeam.findByInput(attIn);
        } while(!att);

        do {
            cout << "Choose target (name/pos): "; cin >> tarIn;
            tar = enemyTeam.findByInput(tarIn);
        } while(!tar);

        performAttack(att, tar, enemyTeam);
        heroTeam.displayNames(); enemyTeam.displayNames();

        if(enemyTeam.isEmpty()) break;

        // Enemy counterattack
        performAttack(enemyTeam.head, heroTeam.head, heroTeam);
        heroTeam.displayNames(); enemyTeam.displayNames();
    }

    cout << "\n===== BATTLE OVER =====\n";
    int hHP = heroTeam.totalHealth(), eHP = enemyTeam.totalHealth();

    if(enemyTeam.isEmpty() || hHP > eHP) {
        cout << "Heroes win!\n"; heroTeam.displayFull();
    } else if(heroTeam.isEmpty() || eHP > hHP) {
        cout << "Enemies win!\n"; enemyTeam.displayFull();
    } else {
        cout << "Draw!\n";
    }

    return 0;
}