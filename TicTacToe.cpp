#include <bits/stdc++.h>
using namespace std;
//Manually checks for winning  conditions
bool checker(char arr[3][3]){
    if(arr[0][0]==arr[0][1]&&arr[0][1]==arr[0][2]&&arr[0][0]!='.')return true;
    else if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]&&arr[0][0]!='.')return true;
    else if(arr[0][0]==arr[1][0]&&arr[1][0]==arr[2][0]&&arr[0][0]!='.')return true;
    else if(arr[1][0]==arr[1][1]&&arr[1][1]==arr[1][2]&&arr[1][0]!='.')return true;
    else if(arr[2][0]==arr[2][1]&&arr[2][1]==arr[2][2]&&arr[2][0]!='.')return true;
    else if(arr[0][1]==arr[1][1]&&arr[1][1]==arr[2][1]&&arr[0][1]!='.')return true;
    else if(arr[0][2]==arr[1][2]&&arr[1][2]==arr[2][2]&&arr[0][2]!='.')return true;
    else if(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]&&arr[0][2]!='.')return true;
    else return false;
}
int main(){
    char arr[3][3];
    int x,y;
    //Initialising the Board
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[i][j]='.';
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    bool check = false;
    int k=0;
    int l=0;
    int n=0;
    //The variable k signifies which player's turn is it. If k is even, it's player 1's turn and player 2's turn when odd

    /*Variable n keeps track of how many squares on the board have been filled in and the loop is broken 
    when it reaches 9 (aka when the board is filled), this mostly helps in game drawn situations*/ 
    
    /*Variable l notes which player made the last move, so whenever a winning condition is achieved, l can be used to 
    print out the winner message*/
    while(check==false&&n<9){
        if(k%2==0){
            cout<<"Enter coordinates for X(player 1):";
            cin >> x >> y;
            //Checking for invalid input
            while(arr[x-1][y-1]!='.'||x>3||y>3||x<1||y<1){
                cout<<"Invalid Input. \n Please Enter Again:"<<endl;
                cin >> x >> y;
            }
            arr[x-1][y-1]='X';
            n++;
            k++;
            check = checker(arr);
            if(check==true){
                l=1;
            }
        }
        else{
            cout<<"Enter coordinates for O(player 2):";
            cin >> x >> y;
            //Checking for invalid input
            while(arr[x-1][y-1]!='.'||x>3||y>3||x<1||y<1){
                cout<<"Invalid Input Please Enter Again:"<<endl;
                cin >> x >> y;
            }
            arr[x-1][y-1]='O';
            n++;
            k++;
            check = checker(arr);
            if(check==true){
                l=2;
            }
        }
        //The board is printed out after every move
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<arr[i][j]<<" ";
            }
        cout<<endl;
        }
    }
    if(l!=0)cout<<"The Winner is Player "<<l<<"!!!"<<endl;
    else cout<<"Match Drawn"<<endl;
}
