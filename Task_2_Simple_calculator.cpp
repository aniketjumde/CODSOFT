#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    cout<<"\n Calculator to perform Addition,Substraction,Multiplication,Divistion."<<endl;

    char ch;
    float num1;
    float num2;
    float ans;
    char choice;
    

    while(true)
    {

        cout<<"\n Enter the first number :";
        cin>>num1;

        cout<<"\n Enter the second number :";
        cin>>num2;

        cout<<"\n Which operation you perform(+,-,*,/) :";
        cin>>ch;
        
        switch(ch)
        {
            case '+':
                     ans=num1+num2;
                     cout<<" Addition : "<<ans<<endl;
                     break;

            case '-':
                     ans=num1-num2;
                     cout<<" Substraction : "<<ans<<endl;
                     break;

            case '*':
                     ans=num1 * num2;
                     cout<<" Multiplication : "<<ans<<endl;
                     break;

            case '/':
                     ans=num1 / num2;
                     cout<<" Divistion : "<<ans<<endl;
                     break;

            default :         
                     cout<<"Invalid option!"<<endl;
                     cout<<"Enter invalid option!!"<<endl;
                     break;
              
        }

        cout<<"\n Do You want to continue (Y/N):";
        cin>>choice;

        if(choice=='N')
        {
            exit(0);
        }
        else if(choice=='Y')
        {
            continue;
        }
        else
        {
            cout<<"\n Invalide Choice."<<endl;
            exit(0);
        }
    }

    cout<<" Exiting the calculator program."<<endl;

    return 0;
}