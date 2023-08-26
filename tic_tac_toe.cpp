#include <iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void board_display()
{
    cout<<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<endl;
    cout<<"     |     |     "<<endl;
    
}
int main()
{
    int i;
    int flag=0;
    int count=0;
    board_display();
    do
    {   
        if(count%2==0)
        {
            cout<<"player 1 turn"<<endl;
            cout<<"enter your choice"<<endl;
            cin>>i;
            switch(i)
            {
                case 1: board[0][0]='x';
                    break;
                case 2: board[0][1]='x';
                    break;
                case 3: board[0][2]='x';
                    break;
                case 4: board[1][0]='x';
                    break;
                case 5: board[1][1]='x';
                    break;
                case 6: board[1][2]='x';
                    break;
                case 7: board[2][0]='x';
                    break;
                case 8: board[2][1]='x';
                    break;
                case 9: board[2][2]='x';
                    break;
                default: cout<<"invalid choice"<<endl;
            }
            board_display();
            
        }
        else
        {
            cout<<"player 2 turn"<<endl;
            cout<<"enter your choice"<<endl;
            cin>>i;
            switch(i)
            {
                case 1: board[0][0]='o';
                    break;
                case 2: board[0][1]='o';
                    break;
                case 3: board[0][2]='o';
                    break;
                case 4: board[1][0]='o';
                    break;
                case 5: board[1][1]='o';
                    break;
                case 6: board[1][2]='o';
                    break;
                case 7: board[2][0]='o';
                    break;
                case 8: board[2][1]='o';
                    break;
                case 9: board[2][2]='o';
                    break;
                default: cout<<"invalid choice"<<endl;
            }
            board_display();
        }
    if((board[0][0]=='x' && board[0][1]=='x' && board[0][2]=='x') 
    || (board[0][0]=='x' && board[1][0]=='x' && board[2][0]=='x')
    || (board[2][0]=='x' && board[2][1]=='x' && board[2][2]=='x')
    || (board[0][2]=='x' && board[1][2]=='x' && board[2][2]=='x')
    || (board[0][0]=='x' && board[1][1]=='x' && board[2][2]=='x')
    || (board[0][2]=='x' && board[1][1]=='x' && board[2][0]=='x'))
    {
        cout<<"** GAME OVER **"<<endl;
        cout<<"player 1 WON !!"<<endl;
        flag=1;
    }

    else if((board[0][0]=='o' && board[0][1]=='o' && board[0][2]=='o') 
    || (board[0][0]=='o' && board[1][0]=='o' && board[2][0]=='o')
    || (board[2][0]=='o' && board[2][1]=='o' && board[2][2]=='o')
    || (board[0][2]=='o' && board[1][2]=='o' && board[2][2]=='o')
    || (board[0][0]=='o' && board[1][1]=='o' && board[2][2]=='o')
    || (board[0][2]=='o' && board[1][1]=='o' && board[2][0]=='o'))
    {
        cout<<"** GAME OVER **"<<endl;
        cout<<"player 2 WON !!"<<endl;
        flag=1;
    }
    
    else if(count==9)
    {
        cout<<"** GAME OVER"<<endl;
        cout<<"GAME TIE"<<endl;
        flag=1;
    }

    count ++;
    

    } while (flag==0);
    
    
    return 0;
    
}