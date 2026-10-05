#include <iostream>
#include <string>
using namespace std;
const int MAXN = 100; // max songs supported
 
class Song {
public:
    string title, genre;
    int duration;
    bool isExplicit;
    Song(string t="", string g="", int d=0, bool e=false){
        title=t; genre=g; duration=d; isExplicit=e;
    }
};
 
class Node {
public:
    Song song;
    Node* next;
    Node(Song s){ song=s; next=NULL; }
};
 
class Playlist {
    Node* head;
    int opCount;
 
    int length(){
        int c=0; Node* t=head;
        while(t){ c++; t=t->next; }
        return c;
    }
 
    Node* getNode(int pos){
        Node* t=head;
        for(int i=0;i<pos && t;i++) t=t->next;
        return t;
    }
 
    bool genreConflict(int pos, string genre){
        if(pos>0 && getNode(pos-1)->song.genre==genre) return true;
        Node* atPos=getNode(pos);
        if(atPos && atPos->song.genre==genre) return true;
        return false;
    }
 
    bool durationConflict(int pos, int dur){
        int d[MAXN], n=0;
        Node* t=head;
        while(t){ d[n++]=t->song.duration; t=t->next; }
        if(pos>n) pos=n;
        // shift right to make space at pos, then insert dur
        for(int i=n;i>pos;i--) d[i]=d[i-1];
        d[pos]=dur;
        n++;
        for(int i=0;i+2<n;i++)
            if(d[i]+d[i+1]+d[i+2]>600) return true;
        return false;
    }
 
    int findValidPos(int pos, Song s){
        int n=length();
        for(int p=pos;p<=n;p++)
            if(!genreConflict(p,s.genre) && !durationConflict(p,s.duration)) return p;
        for(int p=0;p<pos;p++)
            if(!genreConflict(p,s.genre) && !durationConflict(p,s.duration)) return p;
        return n; // no valid spot found, insert at end anyway
    }
 
    // core insert logic, no op counting (used internally too)
    void rawInsert(int pos, Song s){
        int vp=findValidPos(pos,s);
        Node* nn=new Node(s);
        if(vp==0){ nn->next=head; head=nn; }
        else{
            Node* prev=getNode(vp-1);
            nn->next=prev->next;
            prev->next=nn;
        }
        cout<<"Inserted \""<<s.title<<"\" at position "<<vp<<"\n";
    }
 
    void checkAndFix(){
        cout<<"[Constraint check after 3 operations]\n";
        bool changed=true;
        while(changed){
            changed=false;
            Node* t=head; int pos=0;
            while(t && t->next){
                if(t->song.genre==t->next->song.genre){
                    Song s=t->next->song;
                    Node* rm=t->next;
                    t->next=rm->next;
                    delete rm;
                    rawInsert(pos+1, s);
                    changed=true;
                    break;
                }
                t=t->next; pos++;
            }
        }
        int d[MAXN], n=0;
        Node* t=head;
        while(t){ d[n++]=t->song.duration; t=t->next; }
        for(int i=0;i+2<n;i++)
            if(d[i]+d[i+1]+d[i+2]>600)
                cout<<"Warning: 600s limit exceeded around position "<<i<<"\n";
    }
 
    void countOp(){
        opCount++;
        if(opCount%3==0) checkAndFix();
    }
 
public:
    Playlist(){ head=NULL; opCount=0; }
 
    void insertSong(int pos, Song s){
        rawInsert(pos,s);
        countOp();
    }
 
    void deleteSong(int pos){
        Node* target=getNode(pos);
        if(!target){ cout<<"Invalid position!\n"; return; }
        if(target->song.isExplicit){
            cout<<"Cannot delete \""<<target->song.title
                <<"\": explicit flag is true. Set it false first.\n";
            return;
        }
        if(pos==0) head=target->next;
        else getNode(pos-1)->next=target->next;
        cout<<"Deleted \""<<target->song.title<<"\" from position "<<pos<<"\n";
        delete target;
        countOp();
    }
 
    void searchSong(string title){
        Node* t=head; int pos=0;
        while(t){
            if(t->song.title==title){
                cout<<"Found \""<<title<<"\" at pos "<<pos<<" | "<<t->song.genre
                    <<" | "<<t->song.duration<<"s | Explicit: "
                    <<(t->song.isExplicit?"Yes":"No")<<"\n";
                countOp();
                return;
            }
            t=t->next; pos++;
        }
        cout<<"\""<<title<<"\" not found.\n";
        countOp();
    }
 
    void setExplicit(string title, bool val){
        Node* t=head;
        while(t){
            if(t->song.title==title){
                t->song.isExplicit=val;
                cout<<"\""<<title<<"\" explicit flag set to "<<(val?"true":"false")<<"\n";
                return;
            }
            t=t->next;
        }
        cout<<"Song not found.\n";
    }
 
    void display(){
        Node* t=head; int pos=0;
        cout<<"---- Playlist ----\n";
        while(t){
            cout<<pos<<". "<<t->song.title<<" ["<<t->song.genre<<", "
                <<t->song.duration<<"s, Explicit:"<<(t->song.isExplicit?"Y":"N")<<"]\n";
            t=t->next; pos++;
        }
        cout<<"------------------\n";
    }
};
 
int main(){
    Playlist pl;
    pl.insertSong(0, Song("Blinding Lights","pop",200,false));
    pl.insertSong(1, Song("Bohemian Rhapsody","rock",300,false));
    pl.insertSong(2, Song("Take Five","jazz",180,false));
    pl.display();
 
    pl.insertSong(1, Song("Levitating","pop",210,true)); // pop next to pop -> auto shifts
    pl.display();
 
    pl.searchSong("Take Five");     // 3rd op -> triggers constraint check
 
    pl.deleteSong(1);               // fails if still explicit
    pl.setExplicit("Levitating", false);
    pl.deleteSong(1);
    pl.display();
 
    return 0;
}
 