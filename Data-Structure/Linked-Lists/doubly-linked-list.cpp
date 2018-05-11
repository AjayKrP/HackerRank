#include <iostream>
using namespace std;

int compare_fn(int a,int b)
{
    if(a>b)
        return 1;
    else if(b>a)
        return -1;
}

int compare_no=1;
struct node
{
    int data;
    node *prev;
    node *next;
};
node *top = nullptr;

int searchint(int x) {
    int count=0;
    node *searchele = top;
    while( searchele!=nullptr) {
        if(compare_fn(x,searchele->data)==compare_no) {
            searchele=searchele->next;
            count+=1;
        } else
            break;
    }
    return count;
}

int insertdata(int x) {
    if(top==nullptr) {
        top=new node;
        top->data=x;
        top->next=nullptr;
        top->prev=nullptr;
    } else if(compare_fn(top->data ,x)==compare_no) {
        node *n=new node;
        n->data=x;
        n->next=top;
        n->prev=nullptr;
        top->prev=n;
        top=n;
    } else {
        int c=searchint(x);
        node *insertele=top;
        for(int i=0;i<c-1;i++)
            insertele=insertele->next;
        node *n=new node;
        n->data=x;
        node *b=insertele->next;
        node *N =insertele;
        n->prev=insertele;
        n->next=b;
        insertele->next=n;
        if(b!=nullptr)
            b->prev=n;
    }
}

void display() {
    cout<<"Element In The Linked List Are : ";
    node *disp=top;
    while(disp!=nullptr) {
        cout<<" "<<disp->data;
        if(disp->next==nullptr) {
            break;
        }
        disp=disp->next;
    }
}


void deleteint(int x) {
    node *del=top;
    if(del->data == x) {
        if(del->next==nullptr && del->prev==nullptr) {
            top=nullptr;
            return;
        }
        del->next->prev=nullptr;
        top=del->next;
    }
    else {
        node *delsuc=del->next;
        if(nullptr == del) {
            cout<<"\nElement Not Found\n";
            return;
        }
        if(delsuc==nullptr) {
            cout<<"\nElement Not Found\n";
            return;
        }
        while(delsuc->data != x) {
            del=del->next;
            delsuc=delsuc->next;
            if(del==nullptr) {
                cout<<"\nElement Not Found\n";
                return;
            }
            if(delsuc==nullptr) {
                cout<<"\nElement Not Found\n";
                return;
            }
        }
        del->next=delsuc->next;
        if(delsuc->next!=nullptr)
            delsuc->next->prev=del;
    }
}
void reversel() {
    node *a=top;
    node *b,*c,*d;
    while(a!=nullptr) {
        d=a;
        c=a->next;
        b=a->prev;
        a->prev=a->next;
        a->next=b;
        a=c;
    }
    top=d;
    cout<<"After Reversing the linked list";
    display();
    compare_no*=-1;
}



int main()
{
    int ch,d,y;
    char ans='y';
    while(true) {
        cout << "\n\t 1.Insert        2. Delete        3.Reverse      4.EXIT\nEnter Choice : ";
        cin >> ch;
        if(ch == 1) {
            cout<<"Enter An Element To be inserted : ";
            cin>>d;
            d = insertdata(d);
            display();
        }
        else if(ch==2)
        {
            cout<<"Enter Element To Be Deleted : ";
            cin>>d;
            deleteint(d);
            display();
        }
        else if(ch==3)
            reversel();
        else
            return 0;
    }
    return 0;
}
