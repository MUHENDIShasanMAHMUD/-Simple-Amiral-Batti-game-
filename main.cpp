#include <iostream>
#include <windows.h>
#include <unistd.h>
#include<ctime>

using namespace std;

void hasan(int a, int v, int e, int done[10][10])//check matrex and boombing matrex
{

    done[a][v] = e;

}

void matrix(int x, int y, int z, int batti[10][10])//this ase the basic matrex in which the user can insert ships in it.
{

    batti[x][y] = z;

}

int main()
{
    int time_before_game_begins = time(NULL);//used to color the lines in the code.
     int batti[10][10]=
     {
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     };

     int x,y,z;
     while(1)//to make the code restart every time .
    {
        label1:
     HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

   cout<<"  impot your number pleas : ";
    cin>>z;
    if(z!=1)
    {
        cout<<endl;
        SetConsoleTextAttribute(h,3);
        cout<<"  your number is not suitable for playing pleas enter an appropriate number "<<endl;
        cout<<endl<<endl;
        continue;
    }
    int ship1[3]={1,1,1};//the tipe of ships you have .(3 location )
     SetConsoleTextAttribute(h,5);
    cout<<"  you have 2 ship from this type"<<endl;
    for(int s=0;s<3;s++)
    {
         cout<<"  "<<ship1[s]<<"  ";
    }
    cout<<endl;
        int ship2[2]={1,1};//(2 location )
         SetConsoleTextAttribute(h,9);
    cout<<"  you have 3 ship from this type"<<endl;
    for(int k=0;k<2;k++)
    {
         cout<<"  "<<ship2[k]<<"  ";
    }
    cout<<endl;
        int ship3[4]={1,1,1,1};//(4 location )
         SetConsoleTextAttribute(h,12);
    cout<<"  you have 1 ship from this type"<<endl;
    for(int p=0;p<4;p++)
    {
         cout<<"  "<<ship3[p]<<"  ";
    }
    cout<<endl;
        int ship4[1]={1};//(1 location )
         SetConsoleTextAttribute(h,6);
    cout<<"  you have 4 ship from this type"<<endl;
    for(int r=0;r<1;r++)
    {
         cout<<"  "<<ship4[r]<<"  ";
    }
    cout<<endl;
      SetConsoleTextAttribute(h,1);
    cout<<"  IMPORTANT::: YOU CAN PLACE YOUR SHIPS ONLY VERTICALLY OR HORIZONTALLY ."<<endl;//you start to input the ships .
     SetConsoleTextAttribute(h,11);
    cout<<"  impot the raw: ";
    cin>>x;
     SetConsoleTextAttribute(h,14);
    cout<<"  impot the column: ";
    cin>>y;
    x=x-1;//Becouse the program starts from 0 and the user starts from 1.
    y=y-1;

    matrix(x,y,z,batti);//output the ships matrex

    for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
                {
                     SetConsoleTextAttribute(h,6);
                    cout<<batti[i][j];
                    cout<<"   ";
                }
            cout<<endl;
        }

while(1)
{
    int done[10][10]=//to show the bombing sites and use them in the check box (if the user hit or mis)
      {
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     };

            bool check;//if the user done will int the number 9 to start the game
            int q;
            cout<<"if you done Click 9: "<<endl;
            cin>>q;
            if(q==9)
            {
                cout<<"you can play now"<<endl;
                check = true;

            }
            else if(q!=9)
            {
              goto label1;
            }
   while(check)//the checkbox
   {
        label2:
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
        int e,a,v;

        cout<<"  input 1 for Rocket launch : ";
        cin>>e;
        if(e!=1)
            {
                cout<<endl;
                SetConsoleTextAttribute(h,6);
                cout<<"  your number is not suitable for playing pleas enter an appropriate number "<<endl;
                cout<<endl<<endl;
                continue;
            }
        SetConsoleTextAttribute(h,11);
        cout<<"  input the raw: ";
        cin>>a;
        SetConsoleTextAttribute(h,14);
        cout<<"  input the column: ";
        cin>>v;
        int a_mnemonic = a-1;
        int v_mnemonic = v-1;
        int value,c;
        hasan(a_mnemonic,v_mnemonic,e,done);


        for(int k=0;k<10;k++)//to show the boombing mtrex .
            {
                for(int F=0;F<10;F++)
                    {
                        SetConsoleTextAttribute(h,6);
                        cout<<done[k][F];
                        cout<<"   ";
                    }
                cout<<endl;
            }
        if (batti[a_mnemonic][v_mnemonic] == 1)//check if the user hit or mis
            {
            cout<<"you hit!!!"<<endl;
            matrix(a_mnemonic,v_mnemonic,0,batti);
        }
        else
            {
            cout<<"you MISS!!!"<<endl;
        }
        bool gameCheck = true;//check if the user done from game or not
        for(int k=0;k<10;k++)
            {
                for(int F=0;F<10;F++)
                    {
                       if(batti[k][F] != 0)
                       {
                           gameCheck = false;
                       }
                    }
            }
            if(gameCheck){
                cout<<"you WÝNNNN!!!"<<endl;
                int time_after_game_ends = time(NULL);

                int time_diff = time_after_game_ends - time_before_game_begins;
                cout << "Time taken to play the game = " << time_diff << " seconds.";
                exit(0);
            }
    }

    }
    }
return 0;
}

