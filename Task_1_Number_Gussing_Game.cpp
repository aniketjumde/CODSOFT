#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
    //cout<<endl<<" \t \t \t \t WELCOME TO NUMBER GUSSING GAME !!"<<endl<<endl;
    cout<<endl<<"------------------------------------------ WELCOME TO NUMBER GUSSING GAME !!-----------------------------------------------------------"<<endl;
    
    cout<<"You have to gussing number between 1 to 100 "<<endl;
    cout<<"You have to limited choice based on the level of you choice. "<<endl;
    cout<<"-------------------------------------------------Good Luck-------------------------------------------------------------------------------- "<<endl;   

    int difficult_level;
    int Number;
    int playerChoise;
    

    while(1)
    {
        cout<<"The difficulty level:"<<endl<<endl;
        cout<<" 1 : Easy level. \t";
        cout<<" 2 : Medium level. \t";
        cout<<" 3 : Difficult level. \t";
        cout<<" 0 : Ending the game. \t"<<endl<<endl;

        
        cout<<"Enter the dificult level :";
        cin>>difficult_level;
        cout<<endl;

        srand( time(NULL) );
        Number= 1 + (rand() % 100) ; 

        if(difficult_level==1)
        {
          cout<<"You have 10 choices for finding the secret number between 1 and 100."<<endl<<endl;

          int choiceleft=10;
          
          for(int i=1;i<=10;i++)
          {
             cout<<"Guess the number :";
             cin>>playerChoise;
             cout<<endl;

             if(Number == playerChoise )
             {
                cout<<"----------------------------------------------you win-------------------------------------------------------------------------------- "<<endl;   
                cout<<"----------------------------------------  "<<playerChoise<<" is the secret number.-----------------------------------------------------------"<<endl;
                cout<<"----------------------------------------Thanks for playing--------------------------------------------------------------------------------"<<endl;
                cout<<"Play again with us."<<endl<<endl;
                break;
             }
             else
             {
                cout<<playerChoise<<" is Not the secret number."<<endl;

                if(Number>playerChoise)
                {
                    cout<<"Secret number is greater than the guess number."<<endl;
                    cout<<"Try again !"<<endl;
                }
                else
                {
                    cout<<"Secret number is less than the guess number."<<endl;
                    cout<<"Try again !"<<endl;

                }
                choiceleft--;
                cout<<choiceleft<<" choices left"<<endl<<endl;
                if(choiceleft==0)
                {
                    cout<<"You could not find the secret number."<<endl;
                    cout<<"Secret number is "<<Number<<" you lose"<<endl;
                    cout<<"Play the game again to Win."<<endl<<endl;  
                }
             }
          }
        }
        else if(difficult_level == 2)
        {
            cout<<"You have 6 choices for finding the secret number between 1 and 100."<<endl<<endl;

            int choiceleft=6;

            for(int i=1;i<=6;i++)
            {
                cout<<"Guess the number :";
                cin>>playerChoise;
                cout<<endl;

                if(Number==playerChoise)
                {
                    cout<<"----------------------------------------------you win-------------------------------------------------------------------------------- "<<endl;   
                    cout<<"------------------------------------- "<<playerChoise<<" is the secret number.-----------------------------------------------------------"<<endl;
                    cout<<"----------------------------------------Thanks for playing--------------------------------------------------------------------------------"<<endl;
                    cout<<"Play again with us."<<endl<<endl;
                    break;
                }
                else 
                {
                    cout<<playerChoise<<" is not a secret number."<<endl;

                    if(Number > playerChoise)
                    {
                        cout<<"Secret number is greater than the guess number."<<endl;
                        cout<<"Try again !"<<endl;
                    }
                    else
                    {
                        cout<<"Secret number is less than the guess number."<<endl;
                        cout<<"Try again !"<<endl;
                    }
                    choiceleft--;
                    cout<<choiceleft<<" choices left"<<endl<<endl;
                    if(choiceleft == 0)
                    {
                    cout<<"You could not find the secret number."<<endl;
                    cout<<"Secret number is "<<Number<<" you lose"<<endl;
                    cout<<"Play the game again to Win."<<endl<<endl;  
                    }
                }
            
            }
        }
        else if(difficult_level==3)
        {
            cout<<"You have 4 choices for finding the secret number between 1 and 100."<<endl<<endl;
            int choiceleft=4;

            for(int i=1;i<=4;i++)
            {
                cout<<"Guess the number :";
                cin>>playerChoise;
                cout<<endl;

                if(Number==playerChoise)
                {
                    cout<<"----------------------------------------------you win-------------------------------------------------------------------------------- "<<endl;   
                    cout<<"------------------------------------- "<<playerChoise<<" is the secret number.-----------------------------------------------------------"<<endl;
                    cout<<"----------------------------------------Thanks for playing--------------------------------------------------------------------------------"<<endl;
                    cout<<"Play again with us."<<endl<<endl;
                    break;
                }
                else
                {
                    cout<<playerChoise<<" is not a secret number."<<endl;

                    if(Number > playerChoise)
                    {
                        cout<<"Secret number is greater than the guess number."<<endl;
                        cout<<"Try again !"<<endl;
                    }
                    else
                    {
                        cout<<"Secret number is less than the guess number."<<endl;
                        cout<<"Try again !"<<endl;
                    }
                    choiceleft--;
                    cout<<choiceleft<<" choices left"<<endl<<endl;
                    if(choiceleft==0)
                    {
                        cout<<"You could not find the secret number."<<endl;
                        cout<<"Secret number is "<<Number<<" you lose"<<endl;
                        cout<<"Play the game again to Win."<<endl<<endl;  
                    }
                }
                
               
            }
        }
        else if(difficult_level==0)
        {
            exit(0);
        }
        else
        {
            cout<<"Wrong choice "<<endl;
            cout<<"Enter valid choice to play again(0,1,2,3)"<<endl;

        }
    }
    
    return 0;
}