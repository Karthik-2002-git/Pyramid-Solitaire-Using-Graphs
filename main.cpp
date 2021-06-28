
//some blocks of code are commented for your reference
#include <ctime>
#include <iostream>
#include <bits/stdc++.h> 
#include <string.h>
using namespace std;

int top=0,top1=0,game_choice;
string* deck=new string[52];
string* waste=new string[52];
string* stock=new string[52];


struct Node
{
    string card;
    struct Node* fwd_left;
    struct Node* fwd_right;
    struct Node* bwd_left;
    struct Node* bwd_right;
}*root,*ptr,*flag,*par;

Node* getnode(string data)
{
    struct Node* n=new Node;
    n->card=data;
    n->fwd_left=NULL;
    n->fwd_right=NULL;
    n->bwd_left=NULL;
    n->bwd_right=NULL;
    return n;
}

void create_tree()
{
    struct Node* n1=getnode(deck[0]);
    root=n1;

    struct Node* n2=getnode(deck[1]);
    n2->bwd_right=n1;
    n1->fwd_left=n2;

    struct Node* n3=getnode(deck[2]);
    n3->bwd_left=n1;
    n1->fwd_right=n3;

    struct Node* n4=getnode(deck[3]);
    n4->bwd_right=n2;
    n2->fwd_left=n4;

    struct Node* n5=getnode(deck[4]);
    n5->bwd_left=n2;
    n2->fwd_right=n5;
    n5->bwd_right=n3;
    n3->fwd_left=n5;

    struct Node* n6=getnode(deck[5]);
    n6->bwd_left=n3;
    n3->fwd_right=n6;

    struct Node* n7=getnode(deck[6]);
    n7->bwd_right=n4;
    n4->fwd_left=n7;

    struct Node* n8=getnode(deck[7]);
    n8->bwd_left=n4;
    n4->fwd_right=n8;
    n8->bwd_right=n5;
    n5->fwd_left=n8;

    struct Node* n9=getnode(deck[8]);
    n9->bwd_left=n5;
    n5->fwd_right=n9;
    n9->bwd_right=n6;
    n6->fwd_left=n9;

    struct Node* n10=getnode(deck[9]);
    n10->bwd_left=n6;
    n6->fwd_right=n10;

    struct Node* n11=getnode(deck[10]);
    n11->bwd_right=n7;
    n7->fwd_left=n11;

    struct Node* n12=getnode(deck[11]);
    n12->bwd_left=n7;
    n7->fwd_right=n12;
    n12->bwd_right=n8;
    n8->fwd_left=n12;

    struct Node* n13=getnode(deck[12]);
    n13->bwd_left=n8;
    n8->fwd_right=n13;
    n13->bwd_right=n9;
    n9->fwd_left=n13;

    struct Node* n14=getnode(deck[13]);
    n14->bwd_left=n9;
    n9->fwd_right=n14;
    n14->bwd_right=n10;
    n10->fwd_left=n14;

    struct Node* n15=getnode(deck[14]);
    n15->bwd_left=n10;
    n10->fwd_right=n15;

    struct Node* n16=getnode(deck[15]);
    n16->bwd_right=n11;
    n11->fwd_left=n16;

    struct Node* n17=getnode(deck[16]);
    n17->bwd_left=n11;
    n11->fwd_right=n17;
    n17->bwd_right=n12;
    n12->fwd_left=n17;

    struct Node* n18=getnode(deck[17]);
    n18->bwd_left=n12;
    n12->fwd_right=n18;
    n18->bwd_right=n13;
    n13->fwd_left=n18;

    struct Node* n19=getnode(deck[18]);
    n19->bwd_left=n13;
    n13->fwd_right=n19;
    n19->bwd_right=n14;
    n14->fwd_left=n19;

    struct Node* n20=getnode(deck[19]);
    n20->bwd_left=n14;
    n14->fwd_right=n20;
    n20->bwd_right=n15;
    n15->fwd_left=n20;

    struct Node* n21=getnode(deck[20]);
    n21->bwd_left=n15;
    n15->fwd_right=n21;

    struct Node* n22=getnode(deck[21]);
    n22->bwd_right=n16;
    n16->fwd_left=n22;

    struct Node* n23=getnode(deck[22]);
    n23->bwd_left=n16;
    n16->fwd_right=n23;
    n23->bwd_right=n17;
    n17->fwd_left=n23;

    struct Node* n24=getnode(deck[23]);
    n24->bwd_left=n17;
    n17->fwd_right=n24;
    n24->bwd_right=n18;
    n18->fwd_left=n24;

    struct Node* n25=getnode(deck[24]);
    n25->bwd_left=n18;
    n18->fwd_right=n25;
    n25->bwd_right=n19;
    n19->fwd_left=n25;

    struct Node* n26=getnode(deck[25]);
    n26->bwd_left=n19;
    n19->fwd_right=n26;
    n26->bwd_right=n20;
    n20->fwd_left=n26;

    struct Node* n27=getnode(deck[26]);
    n27->bwd_left=n20;
    n20->fwd_right=n27;
    n27->bwd_right=n21;
    n21->fwd_left=n27;

    struct Node* n28=getnode(deck[27]);
    n28->bwd_left=n21;
    n21->fwd_right=n28;

}


bool home_screen()
{

    string myText,enter;
    ifstream file("ascii art.txt");
    while(getline(file, myText))
    {
        cout << myText<<"\n";
    }
    file.close();

    cout<<"1. Play      2. Rules        3. Exit\n";
    cin>>game_choice;
    if(game_choice==1)
        return true;
    else if(game_choice==2)
    {
        string myText;
        ifstream file("rules.txt");
        while(getline(file, myText))
        {
            cout << myText<<"\n";
        }
        file.close();
        cin>>enter;
        system("CLS");
        return false;
    }
    else
        exit(0);



}

long int random()
{
    srand((unsigned) time(0));
    int randomNumber;
    randomNumber = (rand() % 100);
    //cout << "randomNumber = "<<randomNumber << endl;
    return randomNumber;
}

int* num_arr()
{
    int* arr=new int[52];
    for(int i=0;i<52;i++)
    {
        arr[i]=i+1;
    }

    long int seed = random();
    shuffle(arr, arr + 52,default_random_engine(seed));
    return arr;
}

void number_to_card(int* arr)
{

    string suit;
    int rem_cards;
    for(int i=0;i<52;i++)
    {
        if(arr[i]<=52 && arr[i]>39)
        {
            suit="S";
            rem_cards=39;
        }
        else if(arr[i]<=39 && arr[i]>26)
        {
            suit="C";
            rem_cards=26;
        }
        else if(arr[i]<=26 && arr[i]>13)
        {
            suit="H";
            rem_cards=13;
        }
        else                                //arr[i]<=13 && arr[i]>0
        {
            suit="D";
            rem_cards=0;
        }

        if (arr[i]-rem_cards==13)
            deck[i]="K"+suit;
        else if(arr[i]-rem_cards==12)
            deck[i]="Q"+suit;
        else if(arr[i]-rem_cards==11)
            deck[i]="J"+suit;
        else if(arr[i]-rem_cards==1)
            deck[i]="A"+suit;
        else
            deck[i]= to_string(arr[i]-rem_cards)+suit;

    }
}

void remaining_cards()
{

    waste[0]="**";
    stock[0]="**";

    for(int i=28;i<=51;i++)
    {
        top++;
        stock[i-27]=deck[i];

    }

}

void display()
{
    /*cout<<"\nstock = ";
    for(int i=0;stock[i]!="\0";i++)
    {
        cout<<stock[i]<<", ";

    }
    cout<<"\nstock top = "<<stock[top]<<"\nwaste = ";
    for(int i=0;waste[i]!="\0";i++)
    {
        cout<<waste[i]<<", ";

    }*/

    for(int i=0;i<10;i++)
            cout<<"\n";
    int indentation=6;
    cout<<"\n\n\nPYRAMID:-\n\n\n";
    ptr=root;
    flag=ptr;

    while(flag!=NULL)
    {
        if(flag==ptr)
        {
            for(int i=0;i<indentation;i++)
                cout<<"\t";
            indentation--;
        }
        cout<<ptr->card<<"\t\t";
        if(ptr->bwd_right!=NULL)
             ptr=ptr->bwd_right->fwd_right;
        else
        {
            ptr=flag->fwd_left;
            flag=ptr;
            cout<<"\n\n";

        }
    }
    cout<<"Stock : "<<stock[top]<<"\t"<<"Waste : "<<waste[top1];
}

string cardtoupper(string card1)
{
    for(int i=0;i<card1.size();i++)
        card1[i]=toupper(card1[i]);
    return(card1);
}
bool validity_check(string card1)
{
    ptr=root;
    flag=ptr;

    while(flag!=NULL)
    {

        if(ptr->card==card1)
        {
            if((ptr->fwd_left==NULL && ptr->fwd_right==NULL)||(ptr->fwd_left->card=="**" && ptr->fwd_right->card=="**"))
            {
                return true;
            }
        }
        if(ptr->bwd_right!=NULL)
             ptr=ptr->bwd_right->fwd_right;
        else
        {
            ptr=flag->fwd_left;
            flag=ptr;


        }

    }

    if(stock[top]==card1)
    {
        return true;
    }
    if(waste[top1]==card1)
    {
        return true;
    }
    return false;

}

int card_to_number(string card)
{
    int num;
    if(card[0]=='K')
        num=13;
    else if(card[0]=='Q')
        num=12;
    else if(card[0]=='J')
        num=11;
    else if(card[0]=='A')
        num=1;
    else if(card[1]=='0')
        num=10;
    else
        num=card[0]-48;
    return num;
}

void removecard(string card1)
{
    ptr=root;
    flag=ptr;
    while(flag!=NULL)
    {

        if(ptr->card==card1)
        {
            ptr->card="**";
        }
        if(ptr->bwd_right!=NULL)
             ptr=ptr->bwd_right->fwd_right;
        else
        {
            ptr=flag->fwd_left;
            flag=ptr;


        }

    }

    if(stock[top]==card1)
    {
        stock[top]="**";
        top--;

    }

    if(waste[top1]==card1)
    {
        top1--;

    }

}

void stock_rotation()
{
    if(stock[top]=="**")
    {
        while(waste[top1]!="**")
        {
            top++;
            stock[top]=waste[top1];
            top1--;
        }
    }
    else
    {
        top1++;
        waste[top1]=stock[top];
        top--;
    }
}

bool winconditions()
{
    if(stock[top]=="**" && waste[top1]=="**" && root->card=="**")
        return true;
    return false;

}

bool endconditions()
{
    string* end_arr=new string[10];
    string* end_arr1=new string[30];

    ptr=root;
    flag=ptr;
    int ind=0;

    while(flag!=NULL)
    {


        if((ptr->fwd_left==NULL && ptr->fwd_right==NULL)||(ptr->fwd_left->card=="**" && ptr->fwd_right->card=="**"))
        {
            if(ptr->card!="**")
            {

                end_arr[ind]=ptr->card;
                ind++;
            }
        }

        if(ptr->bwd_right!=NULL)
             ptr=ptr->bwd_right->fwd_right;
        else
        {
            ptr=flag->fwd_left;
            flag=ptr;
        }

    }

    /*cout<<"\nEnd arr : ";
    for(int i=0;end_arr[i]!="\0";i++)
    {
        cout<<end_arr[i]<<",";
    }*/



    int i1=0;
    for(int i=0;i<=top;i++)
    {
        if(stock[i]!="**")
        {
            end_arr1[i1]=stock[i];
            i1++;
        }
    }

    for(int i=top1;i>-1;i--)
    {
        if(waste[i]!="**")
        {
            end_arr1[i1]=waste[i];
            i1++;
        }
    }
    /*cout<<"\nEnd arr1 : ";
    for(int i=0;end_arr1[i]!="\0";i++)
    {
        cout<<end_arr1[i]<<",";
    }*/



    //comparison within leaf nodes
    for(int i=0;end_arr[i]!="\0";i++)
    {
        if(card_to_number(end_arr[i])==13)
           return true;                            //King Combination left!

        for(int j=i+1;end_arr[j]!="\0";j++)
        {
            if((card_to_number(end_arr[i])+card_to_number(end_arr[j]))==13)
                return true;              //Combination left!
        }
    }

    //comparison between leaf nodes and (stock or waste cards)
    for(int i=0;end_arr[i]!="\0";i++)
    {
        for(int j=0;end_arr1[j]!="\0";j++)
        {
            if((card_to_number(end_arr[i])+card_to_number(end_arr1[j]))==13)
                return true;                //Combination left!
        }
    }
    //comparison between consecutive cards of stock and waste
    for(int i=0;end_arr1[i]!="\0";i++)
    {
        if(card_to_number(end_arr1[i])==13)
            return true;      //King Combination left!
        if((card_to_number(end_arr1[i])+card_to_number(end_arr1[i+1]))==13)
            return true;           //Combination left!

    }
    return false;

}


int main()
{
    while(true)
    {
        if(home_screen())
            break;
    }


    int* arr=num_arr();

    /*for(int i=0;i<52;i++)
    {
        cout<<arr[i]<<", ";
    }*/

    number_to_card(arr);

    /*for(int i=0;i<52;i++)
    {
        cout<<deck[i]<<", ";
    }*/

    create_tree();
    remaining_cards();
    while(true)
    {


        if(winconditions())
        {
            cout<<"\nWon the Game! :) \n";
            break;
        }
        if(!endconditions())
        {
            cout<<"\nGame over ! :( \n";
            cout<<"No more pairing options, better luck next time \n";
            break;
        }

        l2:display();
        cout<<"\n\nEnter choice:\n1.Card Selection\t2.Stock Rotation\t3.End Game\n~>";
        int choice;
        cin>>choice;
        if(choice==1)
        {
            string card1,card2;
            l1:cout<<"\nEnter card 1 or B - back : ";
            cin>>card1;
            card1=cardtoupper(card1);

            if(card1=="B")
                goto l2;

            else if(validity_check(card1) && card1[0]=='K')
            {
                removecard(card1);
            }

            else if(validity_check(card1))
            {
                cout<<"\nEnter card 2 or B - back : ";
                cin>>card2;
                card2=cardtoupper(card2);
                if(card2=="B")
                        goto l2;
                if(validity_check(card2))
                {
                    if((card_to_number(card1)+card_to_number(card2))==13)
                    {
                        //cout<<"\nSum : "<<card_to_number(card1)+card_to_number(card2)<<endl;
                        removecard(card1);
                        removecard(card2);
                    }
                    else
                    {
                        //cout<<"\nSum : "<<card_to_number(card1)+card_to_number(card2)<<endl;
                        cout<<"\nSum not equal to 13!\n";
                        goto l1;
                    }
                }
                else
                {
                    cout<<"\nPlease enter a valid card!\n";
                    goto l1;
                }
            }

            else
            {
                cout<<"\nPlease enter a valid card!\n";
                goto l1;
            }
        }
        else if(choice==2)
        {
            stock_rotation();
        }
        else if(choice==3)
        {
            break;

        }
    }
}








