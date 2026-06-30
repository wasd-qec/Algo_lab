#include <iostream>
using namespace std;

int random(int min, int max){
    return min + rand() % (max-min+1);
}
int main(){
    // Create a C++ program that can play a game Rock-Paper-Scissor. 
    // The game plays between the user against the computer.
    srand(time(0));
    int user_score = 0, computer_score = 0;
    string option[] = {"rock","paper","scissor"};
    int i;
    
    while(true) {
        cout<<"What will the user choose?"<<endl;
        cout<<"1. Scissor"<<endl;
        cout<<"2. Paper"<<endl;
        cout<<"3. Rock"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"option : ";
        cin>>i;
        cout<<endl<<endl;
        
        if(i == 4) {
            cout<<"Exiting the game..."<<endl;
            break;
        }
        
        if(i >= 1 && i <= 3) {
            int j = random(0,2);
            string opp = option[j];
            cout<<"User picks : "<< option[i-1]<<"\tI pick :"<<opp<<endl;
            if(option[i-1] == "rock" && opp == "scissor") {
                cout<<"User wins!"<<endl;
                user_score++;
            }
            else if(option[i-1] == "paper" && opp == "rock") {
                cout<<"User wins!"<<endl;
                user_score++;
            }
            else if(option[i-1] == "scissor" && opp == "paper") {
                cout<<"User wins!"<<endl;
                user_score++;
            }
            else if(option[i-1] == opp) {
                cout<<"It's a tie!"<<endl;
            }
            else {
                cout<<"Computer wins!"<<endl;
                computer_score++;
            }
            cout<<"Score - User: "<<user_score<<" | Computer: "<<computer_score<<endl<<endl;
        }
        else {
            cout<<"Invalid option!"<<endl<<endl;
        }
    }
    
    cout<<"\nFinal Score - User: "<<user_score<<" | Computer: "<<computer_score<<endl;
    return 0;
}