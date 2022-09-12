/////////////////////////////////////////////////////////////////
//  Name:- Kunal Deshmane.
//  Project discription:- Solve problems on 'Digit' and 'Numbers'.
//  Upgradation required:- Need to add more facilities & reduce time complexcity.
//////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////
class ProblemOnDigit
{
    public:
    int iSum = 0;
    int iNo = 0;
    public:

    void DisplayDigit()//
    {
        cout<<"Enter the number:- ";
        cin>>iNo;

        cout<<"Digit present in number is: ";
        while(iNo != 0)
        {
            cout<<" "<<iNo % 10;

            iNo = iNo / 10;
        }
        cout<<"\n";

    }
    void DisplayReverse()//
    {
        cout<<"Enter the number:- ";
        cin>>iNo;
        int x = 0;
        while(iNo != 0)
        {
            x = x * 10 + (iNo % 10);
            iNo = iNo / 10;
        }
        cout<<"Number after reverse is: "<<x;
        cout<<"\n";
    }
    void DisplayEvenDigit()//
    {
        cout<<"Enter the number:- ";
        cin>>iNo;
        cout<<"Even digit present in given number is: ";
        while(iNo != 0)
        {
            if(((iNo % 10) % 2) == 0)
            {
                cout<<" "<<iNo % 10;
            }
            iNo = iNo / 10;
        }
        cout<<"\n";
        
    }
    void DisplayOddDigit()
    {
        cout<<"Enter the number:- ";
        cin>>iNo;
        cout<<"Odd digit present in given number is: ";
        while(iNo != 0)
        {
            if(((iNo % 10) % 2) != 0)
            {
                cout<<" "<<iNo % 10;
            }
            iNo = iNo / 10;
        }
        cout<<"\n";
        
    }
    void SumEvenDigit()
    {
        cout<<"Enter the number:- ";
        cin>>iNo;
        iSum = 0;
        while(iNo != 0)
        {
            if((iNo % 10) % 2 ==0)
            {
                iSum = iSum + (iNo % 10);
            }
            iNo = iNo / 10;
        }
        cout<<"Summation of even digit is: "<<iSum;
        cout<<"\n";
    }

    void SumOddDigit()
    {
        cout<<"Enter the number:- ";
        cin>>iNo;
        iSum = 0;
        while(iNo != 0)
        {
            if((iNo % 10) % 2 !=0)
            {
                iSum = iSum + (iNo % 10);
            }
            iNo = iNo / 10;
        }
        cout<<"Summation of odd digit is: "<<iSum;
        cout<<"\n";
    }
    void SumAllDigit()
    {
        cout<<"Enter the number:- ";
        cin>>iNo;
        iSum = 0;
        while(iNo != 0)
        {
            iSum = iSum + (iNo % 10);
            iNo = iNo / 10;
        }
        cout<<"Summation of all digit present in given number is: "<<iSum;
        cout<<"\n";
    }

};
///////////////////////////////////////////////////////////////////////////////
class ProblemOnNumber
{
    public:
    int i = 0;
    int iCount = 0;
    int iNo = 0;

    public:
    void CheckEvenOdd()
    {
        cout<<"Enter the number:- ";
        cin>>iNo;
        if(iNo % 2 == 0)
        {
            cout<<"Entered Number is 'Even number'";
        }
        else
        {
            cout<<"Entered Number is 'Odd number'";
        }
        cout<<"\n";
     return;
    }

    void CheckPrime()
    {
        cout<<"Enter the number:- ";
        cin>>iNo;
        iCount = 0;

        for(i = 1;i<iNo;i++)
        {
            if((iNo % i)==0)
            {
                iCount++;
            }
        }
        if(iCount < 2)
        {
            cout<<"Entered number is 'Prime number'";
        }
        else
        {
           cout<<"Entered number is 'not a Prime number'";
        }
        cout<<"\n";
     return;
    }
    void DisplayFactors()
    {
        cout<<"Enter the number:- ";
        cin>>iNo;
        if(iNo < 0)
        {
            iNo = -iNo;
        }
        cout<<"Factors of given number is:";
        for(i = 1; i <=(iNo/2); i++)
        {
            if((iNo % i) == 0)
            {
                cout<<i<<"  ";
            }
        }
        cout<<"\n";
     return;
    }
    void DisplayNonFactors()
    {
        cout<<"Enter the number:- ";
        cin>>iNo;
        i = 0;
        if(iNo < 0)
        {
            iNo = -iNo;
        }
    cout<<"Non factors of given number is: ";
        for(i = 1; i < iNo ; i++)
        {
            if((iNo % i) != 0)
            {
                cout<<i<<"  ";
            }
        }
        cout<<"\n";
     return;
    }
    void CheckPerfect()
    {
        cout<<"Enter the number:- ";
        cin>>iNo;
        int iSum = 0;
        if(iNo < 0)
        {
            iNo = -iNo;
        }
        for(i = (iNo/2); ((i >= 1) && (iSum <= iNo)); i--)
        {
            if((iNo % i) == 0)
            {
                iSum =  iSum + i;
            }
        }
        if(iSum == iNo)
        {
            cout<<"Given number is Perfect number.";
        }
        else
        {
            cout<<"Given number is not a perfect number.";
        }
        cout<<"\n";
     return;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////
class ProblemsOnString
{
    public:
    char Arr[100];
    int i = 0;
    
    void CountandDisplayLowerCase()
    {
        i = 0;
        int Count = 0;
        cout<<"Enter the string: ";
        cin.getline(Arr,100);

        cout<<"Small letter present in given word is:";

        while(Arr[i] != '\0')
        {
            if((Arr[i] >= 'a')&&(Arr[i] <= 'z'))
            {
                Count++;
                cout<<" "<<Arr[i];
            }
            i++;
        }
        cout<<endl;
        cout<<"Number of small case present in given word is: "<<Count<<endl;
    }
    void CountandDisplayUpperCase()
    {
        i = 0;
        int Count = 0;
        cout<<"Enter the string: ";
        cin.getline(Arr,100);

        cout<<"Upper case present in given word is: "<<endl;
        while (Arr[i] != '\0')
        {
            if((Arr[i] >= 'A')&&(Arr[i] <= 'Z'))
            {
                Count++;
                cout<<" "<<Arr[i];
            }
            i++;
        }
        cout<<endl;
        cout<<"Number of upper case present in given word is: "<<Count<<endl;
    }

    void DisplayInCapital()
    {
        i = 0;
        cout<<"Enter the string: ";
        cin.getline(Arr,100);

        cout<<"Given string in Upper case is: ";
        while(Arr[i] != '\0')
        {
            if((Arr[i] >= 'a')&&(Arr[i] <= 'z'))
            {
                Arr[i] = Arr[i] - 32;
            }
            cout<<Arr[i];
            i++;
        }
        cout<<endl;
     return;
    }

    void DisplayInSmall()
    {
        i = 0;
        cout<<"Enter the string: ";
        cin.getline(Arr,100);

        cout<<"Given string in Upper case is: ";
        while(Arr[i] != '\0')
        {
            if((Arr[i] >= 'A')&&(Arr[i] <= 'Z'))
            {
                Arr[i] = Arr[i] + 32;
            }
            cout<<Arr[i];
            i++;
        }
        cout<<endl;
     return;
    }

    void DisplayReverse()
    {
        i=0;

        cout<<"Enter the string: ";
        cin.getline(Arr,100);

        char *start = Arr;
        char *end = Arr;
        char temp;

        while(*end != '\0')
        {
            end++; //or end = end + sizeof(char);
        }
        end--; //or end = end - sizeof(char);
    
        while(start < end)
        {
            temp = *start;
           *start = *end;
           *end = temp;
           start++;
           end--;
        }

        while(Arr[i] != '\0')
        {
            cout<<Arr[i];
            i++;
        }
        cout<<endl;
        return;
    }
    void DisplayStringConcat()
    {
        char Brr[100];

        cout<<"Enter First string: ";
        cin.getline(Arr,100);

        cout<<"Enter Second string: ";
        cin.getline(Brr,100);

        char *src = Arr;
        char *dest = Brr;

        char temp = '\0';
    
        while(*src != '\0')
        {
            src++;
        }
        
        while(*dest != '\0')
        {
            *src = *dest;
            src++;
            dest++;
        }
        *src = '\0';

        i = 0;
        cout<<"String after concat is: ";
        while(Arr[i] != '\0')
        {
            cout<<Arr[i];
            i++;
        }
        cout<<endl;
        return;
    }
    /*void CheckLetterFrequency()
    {
        Enter string:
        Marvellous@1998
        {@=1, a=1, e=1, l=2, M=1, o=1, 1=1, r=1, s=1, u=1, v=1, 8=1, 9=2}
    }
    */
};
/////////////////////////////////////////////////////////////////
template<class T>
class ProblemsOnNumberArray
{
    int i = 0;
    T Arr[100];

    void DisplayEvenNumbers()
    {

    }
    

    
};

void helpfun()
{
    cout<<"Type 'Clear' To clear the whole consol."<<"\n";
    cout<<"Type 'Option' To know the different problem statements."<<"\n";
    cout<<"Type 'Exit' To terminate the process."<<"\n";
}
void Option()
{
    cout<<"Type: 'Digit' To use problems on digits."<<"\n";
    cout<<"Type: 'Number' To use problems on digits."<<"\n";
}
void DigitOption()
{
    cout<<"Type 'GD' to get digit of given number."<<"\n";
    cout<<"Type 'GR' to get reverse of given number."<<"\n";
    cout<<"Type 'GE' to get even digit of given number."<<"\n";
    cout<<"Type 'GO' to get odd digit of given number."<<"\n";
    cout<<"Type 'GSE' to get sum of even digit of given number."<<"\n";
    cout<<"Type 'GSO' to get sum of odd digit of given number."<<"\n";
    cout<<"Type 'GSA' to get sum of all digit of given number."<<"\n";
}
void NumberOption()
{
    cout<<"Type 'CEO' to check given number is Even or Odd."<<"\n";
    cout<<"Type 'CP' to check given number is Prime or not."<<"\n";
    cout<<"Type 'DF' to display factors of given number."<<"\n";
    cout<<"Type 'DNF' to display non factors of given number."<<"\n";
    cout<<"Type 'CPER' to check given number is Perfect or not."<<"\n";
}
void StringOption()
{
    cout<<"Type 'DUC' to display and count in Upper case from given string."<<"\n";
    cout<<"Type 'DLC' to display and count in Lower case from given string."<<"\n";
    cout<<"Type 'DIC' to display given string in Capital letters."<<"\n";
    cout<<"Type 'DIS' to display given string in Small letters."<<"\n";
    cout<<"Type 'DR' to display given string in Reverse format."<<"\n";
    cout<<"Type 'SC' to concat the given two strings."<<"\n";
}

int main()
{ 
    cout<<"Welcome to my template library >"<<"\n";
    char Arr[80];

    ProblemOnDigit dobj;
    ProblemOnNumber pobj;
    ProblemsOnString sobj;

    while(1)
    {
        fflush(stdin);  //This is the important line to clear array simultaneously.
        cout<<"Enter command=>";   
        cin.getline(Arr,80);

        if(strcmp(Arr,"Help")==0)
        {
            helpfun();
            continue;
        }
        else if(strcmp(Arr,"Clear")==0)
        {
            system("cls");
            continue;
        }
        else if(strcmp(Arr,"Option")==0)
        {
            Option();
            continue;
        }
        else if(strcmp(Arr,"Exit")==0)
        {
            break;
        }
        else if(strcmp(Arr,"Digit")==0)
        {
            DigitOption();
            continue;
        }
        else if(strcmp(Arr,"Number")==0)
        {
            NumberOption();
            continue;
        }
        else if(strcmp(Arr,"String") == 0)
        {
            StringOption();
            continue;
        }
        else if(strcmp(Arr,"GD")==0)
        {
            dobj.DisplayDigit();
            continue;
        }
        else if(strcmp(Arr,"GR")==0)
        {
            dobj.DisplayReverse();
            continue;
        }
        else if(strcmp(Arr,"GE")==0)
        {
            dobj.DisplayEvenDigit();
            continue;
        }
        else if(strcmp(Arr,"GO")==0)
        {
            dobj.DisplayOddDigit();
            continue;
        }
        else if(strcmp(Arr,"GSE")==0)
        {
            dobj.SumEvenDigit();
            continue;
        }
        else if(strcmp(Arr,"GSO")==0)
        {
            dobj.SumOddDigit();
            continue;
        }
        else if(strcmp(Arr,"GSA")==0)
        {
            dobj.SumAllDigit();
            continue;
        }
        else if(strcmp(Arr,"CEO")==0)
        {
            pobj.CheckEvenOdd();
            continue;
        }
        else if(strcmp(Arr,"CP")==0)
        {
            pobj.CheckPrime();
            continue;
        }
        else if(strcmp(Arr,"DF")==0)
        {
            pobj.DisplayFactors();
            continue;
        }
        else if(strcmp(Arr,"CPER")==0)
        {
            pobj.CheckPerfect();
            continue;
        }
        else if(strcmp(Arr,"DNF")==0)
        {
            pobj.DisplayNonFactors();
            continue;
        }
        else if(strcmp(Arr,"DUC") == 0) 
        {
            sobj.CountandDisplayUpperCase();
            continue;
        }
        else if(strcmp(Arr,"DLC") == 0)
        {
            sobj.CountandDisplayLowerCase();
            continue;
        }
        else if(strcmp(Arr,"DIC")==0)
        {
            sobj.DisplayInCapital();
            continue;
        }
        else if(strcmp(Arr,"DIS") == 0)
        {
            sobj.DisplayInSmall();
            continue;
        }
        else if(strcmp(Arr,"DR") == 0)
        {
            sobj.DisplayReverse();
            continue;
        }
        else if(strcmp(Arr,"SC")==0)
        {
            sobj.DisplayStringConcat();
            continue;
        }
        else
        {
            cout<<"Please enter correct command.."<<"\n";
            cout<<"For help type: 'Help'"<<"\n";
            continue;
        }
    }
    cout<<"Thank you for using this application...."<<"\n";
 return 0;
}