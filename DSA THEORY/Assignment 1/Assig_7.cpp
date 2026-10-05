#include <iostream>
#include <string>
using namespace std;

const int MAX_ROUNDS = 10;

// ---- simple own random number generator (no extra libs) ----
unsigned long rngSeed = 1;

void seedRNG(unsigned long s){
    rngSeed = s;
}

int myRand(){
    rngSeed = rngSeed * 1103515245UL + 12345UL;
    return (int)((rngSeed / 65536UL) % 32768UL);
}

int randomInRange(int lo, int hi){ // inclusive
    int range = hi - lo + 1;
    return lo + (myRand() % range);
}

class Combatant {
public:
    string name;
    int hp;
    int atk;
    Combatant(string n="", int h=0, int a=0){ name=n; hp=h; atk=a; }
};

class Node {
public:
    Combatant c;
    Node* prev;
    Node* next;
    Node(Combatant cc){ c=cc; prev=NULL; next=NULL; }
};

class Team {
public:
    Node* head;
    Node* tail;
    string teamName;

    Team(string n=""){ head=NULL; tail=NULL; teamName=n; }

    void addMember(Combatant c){
        Node* nn = new Node(c);
        if(head==NULL){ head=tail=nn; }
        else{ tail->next=nn; nn->prev=tail; tail=nn; }
    }

    bool isEmpty(){ return head==NULL; }

    int count(){
        int c=0; Node* t=head;
        while(t){ c++; t=t->next; }
        return c;
    }

    Node* findByName(string name){
        Node* t=head;
        while(t){
            if(t->c.name==name) return t;
            t=t->next;
        }
        return NULL;
    }

    Node* findByPosition(int pos){ // 1-indexed
        int i=1; Node* t=head;
        while(t){
            if(i==pos) return t;
            t=t->next; i++;
        }
        return NULL;
    }

    bool isNumber(string s){
        if(s.length()==0) return false;
        for(int i=0;i<(int)s.length();i++)
            if(s[i]<'0' || s[i]>'9') return false;
        return true;
    }

    Node* findByInput(string input){
        if(isNumber(input)) return findByPosition(atoi(input.c_str()));
        return findByName(input);
    }

    void removeNode(Node* n){
        if(n->prev) n->prev->next=n->next;
        else head=n->next;
        if(n->next) n->next->prev=n->prev;
        else tail=n->prev;
        delete n;
    }

    void displayNames(){
        cout<<teamName<<" remaining: ";
        if(isEmpty()){ cout<<"None"; }
        Node* t=head;
        while(t){
            cout<<t->c.name;
            if(t->next) cout<<", ";
            t=t->next;
        }
        cout<<"\n";
    }

    void displayFull(){
        cout<<"---- "<<teamName<<" ----\n";
        Node* t=head;
        while(t){
            cout<<t->c.name<<" | HP: "<<t->c.hp<<" | Attack: "<<t->c.atk<<"\n";
            t=t->next;
        }
    }

    int totalHealth(){
        int sum=0; Node* t=head;
        while(t){ sum+=t->c.hp; t=t->next; }
        return sum;
    }

    Node* getAt(int pos){ return findByPosition(pos); }
};

// attacker strikes target; removes target from targetTeam if defeated
void performAttack(Node* attacker, Node* target, Team& targetTeam){
    int randVal = randomInRange(1,3); // 1 to 3
    int damage = attacker->c.atk * randVal;
    target->c.hp -= damage;
    cout<<attacker->c.name<<" attacks "<<target->c.name<<" for "<<damage<<" damage!\n";
    if(target->c.hp <= 0){
        cout<<target->c.name<<" has been defeated!\n";
        targetTeam.removeNode(target);
    }
}

int main(){
    int seedHelper;
    seedRNG((unsigned long)&seedHelper); // seed using stack address, changes every run

    Team heroTeam("Heroes");
    heroTeam.addMember(Combatant("Arthur",60,4));
    heroTeam.addMember(Combatant("Lancelot",55,5));
    heroTeam.addMember(Combatant("Merlin",40,3));
    heroTeam.addMember(Combatant("Tristan",50,4));
    heroTeam.addMember(Combatant("Gawain",65,3));

    Team enemyTeam("Enemies");
    enemyTeam.addMember(Combatant("Goblin",30,2));
    enemyTeam.addMember(Combatant("Orc",45,3));
    enemyTeam.addMember(Combatant("Troll",70,4));
    enemyTeam.addMember(Combatant("Skeleton",25,2));
    enemyTeam.addMember(Combatant("DarkMage",35,5));

    int round=1;
    bool instantWin=false;
    string winner="";

    while(round<=MAX_ROUNDS && !heroTeam.isEmpty() && !enemyTeam.isEmpty()){
        cout<<"\n===== Round "<<round<<" =====\n";

        // ---- Hero turn ----
        Node* attacker=NULL;
        string input;
        do{
            cout<<"Choose your attacker (name or position): ";
            cin>>input;
            attacker=heroTeam.findByInput(input);
            if(!attacker) cout<<"Invalid attacker. Try again.\n";
        }while(!attacker);

        Node* target=NULL;
        do{
            cout<<"Choose enemy target (name or position): ";
            cin>>input;
            target=enemyTeam.findByInput(input);
            if(!target) cout<<"Invalid target. Try again.\n";
        }while(!target);

        performAttack(attacker, target, enemyTeam);
        heroTeam.displayNames();
        enemyTeam.displayNames();

        if(enemyTeam.isEmpty()){
            instantWin=true; winner="Heroes";
            break;
        }

        int enemyPos = randomInRange(1, enemyTeam.count());
        int heroPos  = randomInRange(1, heroTeam.count());
        Node* eAttacker = enemyTeam.getAt(enemyPos);
        Node* eTarget   = heroTeam.getAt(heroPos);

        performAttack(eAttacker, eTarget, heroTeam);
        heroTeam.displayNames();
        enemyTeam.displayNames();

        if(heroTeam.isEmpty()){
            instantWin=true; winner="Enemies";
            break;
        }

        round++;
    }

    cout<<"\n===== BATTLE OVER =====\n";

    if(instantWin){
        cout<<winner<<" win the battle!\n";
        if(winner=="Heroes") heroTeam.displayFull();
        else enemyTeam.displayFull();
    }
    else{
        int heroHP = heroTeam.totalHealth();
        int enemyHP = enemyTeam.totalHealth();
        cout<<"Max rounds reached.\n";
        cout<<"Heroes total HP: "<<heroHP<<" | Enemies total HP: "<<enemyHP<<"\n";
        if(heroHP > enemyHP){
            cout<<"Heroes win by total health!\n";
            heroTeam.displayFull();
        }
        else if(enemyHP > heroHP){
            cout<<"Enemies win by total health!\n";
            enemyTeam.displayFull();
        }
        else{
            cout<<"The battle ends in a DRAW!\n";
            heroTeam.displayFull();
            enemyTeam.displayFull();
        }
    }

    return 0;
}