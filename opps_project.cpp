#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<stdlib.h>//for atoi
using namespace std;

int ct=1;
string dt;
ofstream group5;
ofstream group5c;
//class for company visited
class company_visited
{
protected:
    string name_of_company;
    int offer ;
    int year;
    int no_of_stu_selected;
public:
    void get_comapany_visitd();
};
void company_visited::get_comapany_visitd()
{
    cout<<"Enter name of the company visited"<<endl;;
    getchar();
    getline(cin,name_of_company);
    cout<<"Enter pay package offered"<<endl;;
    cin>>offer;
    cout<<"\nEnter No. of students placed"<<endl;;
    cin>>no_of_stu_selected;
    //check1://for goto function
    cout<<"\nEnter year of visit"<<endl;;
    cin>>year;

     group5<<"Company:"<<","<<"YEAR OF VISIT"<<","<<"OFFER"<<","<<"STUDENTS PLACED"<<endl;
    group5<<name_of_company<<","<<year<<","<<offer<<","<<no_of_stu_selected<<endl;


}
/*Provide their total intake capacity for 1st year B.Tech. program.
Mention the various branches available and their respective strength.*/

class btech
{
protected:
    int male_strength;
    int female_strength;
public:
    void get_btech()
    {
        cout<<"enter male strength"<<endl;
        cin>>male_strength;
        cout<<"enter female strength"<<endl;
        cin>>female_strength;

        group5<<","<<"MALE STRENGTH"<<","<<"FEMALE STRENGTH"<<endl;
        group5<<","<<male_strength<<","<<female_strength<<endl;

    }
};

//Mention the various branches available
class branch
{
protected:
    string name_of_branch;
    int number_of_student_in_branch;
public:
    void add_branch()
    {
        cout<<"ENTER THE BRANCH THAT YOU WANT TO ADD IN FILE:"<<endl;
        cin.ignore();
        getline(cin,name_of_branch);
        cout<<"ENTER THE TOTAL STRENGTH OF BRANCH:"<<endl;
        cin>>number_of_student_in_branch;

         group5<<","<<"NAME OF BRANCH:"<<","<<"BRANCH STRENGTH"<<endl;
         group5<<","<<name_of_branch<<","<<number_of_student_in_branch<<endl;

    }
};

//class for engineering colleges in bhubaneswar.
class college
{
protected:
    string college_name;
    int a[5][7];
    branch b;
    company_visited c;
    int intake;
public:
    void get_last_five_year();

};
void college::get_last_five_year()
{
    int i=0,j=0;
    string exam;
    cout<<"ENTER THE FIVE YEAR ADMISSION DETAIL:";
    group5<<"YEAR"<<","<<"SELECTION FROM EXAM"<<","<<"OPENING MARKS"<<","<<"CLOSING MARKS"<<","<<"TOTAL STUDENT"<<","<<"MALE STRENGTH"<<","<<"FEMALE STRENGTH"<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<7;j++)
        {
            switch(j)
            {
            case 0:
                cout<<"\nDETAILS OF YEAR "<<2018-i<<":";
                a[i][j]=2018-i;
                group5<<a[i][j]<<",";
                break;
            case 1:
                cout<<"\nENTER THE EXAM:";
                cin.ignore();
                getline(cin,exam);
                group5<<exam<<",";
                break;
            case 2:
                ck2:
                cout<<"\nENTER OPENING MARKS/RANK:";
                cin>>a[i][j];
                //cout << "check2 ===== " << a[i][j] << endl;
                if(a[i][j]>360)
                {
                 cout<<"\nEnter marks less than 360";
                goto ck2;
                }
                group5<<a[i][j]<<",";
                break;
            case 3:
                ck3:
                cout<<"\nEnter CLOSING MARKS/RANK:";
                cin>>a[i][j];
                if(a[i][j]>a[i][j-1])
                {
                    cout<<"\n WRONG INPUT(OPENING MARKS>CLOSING MARKS) ";
                    goto ck3;
                }
                group5<<a[i][j]<<",";
                break;
            case 4:
                    cout<<"\nTOTAL STUDENT INTAKE:";
                    cin>>a[i][j];
                    group5<<a[i][j]<<",";
                    break;
            case 5:
                check4:
                    cout<<"\nENTER THE MALE STRENGTH:";
                    cin>>a[i][j];
                    if(a[i][j]>a[i][j-1])
                    {
                        cout<<"\nplease enter male strength less than total intake"<<endl;
                        goto check4;
                    }
                    group5<<a[i][j]<<",";
                    break;

            case 6:
                    cout<<"\nENTER THE FEMALE STRENGTH:";
                    cin>>a[i][j];
                    group5<<a[i][j]<<",";
                    break;

            }

        }
        group5<<endl;
    }
}
class collegename:public college
{
protected:
    string name;
public:
    void get_college_inf();
};
class collegename1 : public college
{
    protected:
            string name;//for private and government
    public:

            void get_college_inf();
};
/*check*/
void collegename :: get_college_inf()
{
    cout<<"\nENTER THE COLLEGE NAME:";
    getchar();
    getline(cin,college_name);
    cout<<"\nGOVERNMENT/PRIVATE ";
    getline(cin,name);
    cout<<"\nENTER TOTAL STUDENT OF FIRST YEAR:";
    cin>>intake;
    char x;

    group5<<"NAME OF INSTITUTE"<<","<<"PRIVATE/GOVERNMENT"<<","<<"TOTAL STUDENT(1ST YEAR)"<<endl;
    group5<<college_name<<","<<name<<","<<intake<<endl;
    group5c<<"NAME OF INSTITUTE"<<endl;
    group5c<<college_name<<endl;
    get_last_five_year();

    cout<<"\n\nADD BRANCH: Y/N\n";
    cin>>x;
    string t;
    while(x=='y' || x=='Y')
    {
        b.add_branch();
        cout<<"\nADD MORE BRANCH: Y/N\n";
        cin>>x;
         /*check*/
        if(x=='n'||x=='N')
        {
           cout<<"you want to exit program yes/no"<<endl;
            cin>>t;
            if(t=="yes")
            {
                exit(0);
            }
        }
    }
    cout<<"\n\nADD COMPANY:Y/N\n";
    cin>>x;
    while(x=='y'||x=='Y')
    {
        c.get_comapany_visitd();
        cout<<"\nADD ANOTHER COMAPNY?:Y/N\n";
        cin>>x;
        /*check*/
        if(x=='n'||x=='N')
        {
            exit(0);
        }
    }
}

void collegename1 :: get_college_inf()
{
    cout<<"\nENTER THE COLLEGE NAME: ";
    getchar();
    getline(cin,college_name);
    cout<<"\nGOVERNMENT/PRIVATE ";
    getline(cin,name);
    cout<<"\nTOTAL STUDENT OF FIRST YEAR:";
    cin>>intake;
    char x;
    string t;

    group5<<"NAME OF INSTITUTE"<<","<<"GOVERRNMENT/PRIVATE"<<","<<"TOTAL STUDENT(IST YEAR)"<<endl;
    group5<<college_name<<","<<name<<","<<intake<<endl;
    group5c<<"NAME OF INSTITUTE"<<endl;
    group5c<<college_name<<endl;
    cout<<"Provide admission details\n";
    get_last_five_year();

    cout<<"\n\nDo you want to add a branch?Y/N";
    cin>>x;
    while(x=='y' || x=='Y')
    {
        b.add_branch();
        cout<<"\nADD another branch?\n";
        cin>>x;
         /*check*/
        if(x=='n'||x=='N')
        {
            cout<<"you want to exit program yes/no"<<endl;
            cin>>t;
            if(t=="yes")
            {
                exit(0);
            }
        }
    }
    cout<<"\n\nADD COMPANY:?Y/N";
    cin>>x;
    while(x=='y'||x=='Y')
    {
        c.get_comapany_visitd();
        cout<<"\nADD ANOTHER COMPANY?\n";
        cin>>x;
        /*check*/
        if(x=='n'||x=='N')
        {
            //exit(0);
            break;
        }
    }
}
/*check*/

void search1()
{
        ifstream  data("collegefile.csv");
            ct++;
            int j=0;
            string line;
            while(getline(data,line))
            {
                j=0;
                while(line[j]!='\0')
                {
                    if(line[j]!=',')
                    cout<<line[j];
                    else
                    cout<<", ";

                    j++;

                }
                cout<<endl;
            }
            data.close();
}
void search2()
{
        ifstream  data1("collegename.csv");
            ct++;
            int j=0;
            string sea;
            while(getline(data1,sea))
            {
                j=0;
                while(sea[j]!='\0')
                {
                    if(sea[j]!=',')
                    cout<<sea[j];
                    else
                    cout<<", ";

                    j++;

                }
                cout<<endl;
            }
            data1.close();
}
/*check*/

void search1(string c)
{
        ifstream data("collegefile.csv");
    string line;
        int l=c.length();
        bool f=true;
        while(getline(data,line))
        {
            f=true;
            for(int i=0;i<l;i++)
            {
             if(line[i]!=c[i])
                f=false;
            }
            if(f)
            {
                ct=0;
                cout<<"INSTITUTE,GOVERNMENT/PRIVATE,1st YEAR INTAKE"<<endl;
                cout<<line<<endl;
                int j;
                while(getline(data,line))
                {
                    j=0;
                    if(line[0]=='N'&&line[1]=='A'&&line[2]=='M'&&line[3]=='E'&&line[4]==' '&&line[5]=='O'&& line[6]=='F' && line[7]==' ' && line[8]=='I')
                        break;
                    while(line[j]!='\0')
                    {
                        if(line[j]!=',')
                        cout<<line[j];
                        else
                        cout<<", ";
                        j++;
                    }
                    cout<<endl;
                }
                break;
            }

        }
         if(ct==1)
        {
        cout<<" Not found";
        }
    data.close();
}

int main()
{
//##########################################################
//GRAPHIC DESIGNING
   cout<<"CHOICE THE COLOUR OF CONSOLE: "<<endl;
   cout<<"0.ENTER 0 FOR BLACK"<<endl;
   cout<<"1.ENTER 1 FOR BLUE:"<<endl;
   cout<<"2.ENTER 2 FOR GREEN:"<<endl;
   cout<<"3.ENTER 3 FOR AQUA:"<<endl;
   cout<<"4.ENTER 4 FOR RED:"<<endl;
   cout<<"5.ENTER 5 FOR PURPLE:"<<endl;
   cout<<"6.ENTER 6 FOR YELLOW:"<<endl;
   cout<<"7.ENTER 7 FOR WHITE:"<<endl;
   cout<<"8.ENTER 8 FOR GRAY:"<<endl;
   cout<<"9.ENTER 9 FOR LIGHT BLUE:"<<endl;
   cout<<"10.ENTER A FOR LIGHT GREEN:"<<endl;
   cout<<"11.ENTER B FOR LIGHT AQUA:"<<endl;
   cout<<"12.ENTER C FOR LIGHT RED:"<<endl;
   cout<<"13.ENTER D FOR LIGHT PURPLE:"<<endl;
   cout<<"14.ENTER E FOR LIGHT YELLOW:"<<endl;
   cout<<"15.ENTER F FOR BRIGHT WHITE:"<<endl;

char color;
cin>>color;
    if(color=='0')
      system("COLOR 0F");
    if(color=='1')
    system("COLOR 1F");
    if(color=='2')
    system("COLOR 2F");
    if(color=='3')
    system("COLOR 3F");
    if(color=='4')
    system("COLOR 4F");
    if(color=='5')
    system("COLOR 5F");
    if(color=='6')
    system("COLOR 6F");
    if(color=='7')
    system("COLOR 7F");
    if(color=='8')
    system("COLOR 8F");
    if(color=='9')
    system("COLOR 9F");
    if(color=='A')
    system("COLOR AF");
    if(color=='B')
    system("COLOR BF");
    if(color=='C')
    system("COLOR CF");
    if(color=='D')
    system("COLOR DF");
    if(color=='E')
    system("COLOR EF");
    if(color=='F')
    system("COLOR FF");

     //CLEAR THE SCREEN
     system("CLS");
   //system("COLOR F5");
//#########################################################
    string password = "";
    //strcpy(password,"rajesh");
    int ch,ch1,ch2,ch3;
    char x;
    char r;
    group5.open("collegefile.csv",ios::app | ios::ate);
    group5c.open("collegename.csv",ios::app | ios::ate);
    check_3:
    {
    //cout<<"ENTER TYPE:"<<endl;
    cout<<"1.ADMIN:"<<endl;
    cout<<"2.USER:"<<endl;
    cout<<"ENTER YOUR TYPE"<<endl;
    cin>>ch;
    int size1=0,ret=0;
     string p;
            p="rajesh";
    string school_name,s_n,s_n1,s_n2;
       school_name="dev samaj modern school";
    if(ch==1)
    {
        flag1:

            if(ret==3)
            {new1:
                new4:
            cout<<"FORGOT PASSWORD "<<endl;
            cout<<"RESET PASSWORD: YES/NO"<<endl;
            cin>>s_n;
            if(s_n=="NO")
            { ret=0;
                exit(0);
            }
            else if(s_n=="YES")
            {   new2:
                //s_n1="";
                cout<<"ENTER YOUR FIRST SCHOOL NAME?"<<endl;
                //cin.ignore();
                cin.clear();
                fflush(stdin);
                getline(cin,s_n1);
                if(s_n1==school_name)
                {
                    cout<<"ENTER YOUR NEW PASSWORD:"<<endl;
                   //cin.ignore();
                    getline(cin,s_n2);

                    p=s_n2;
                }
                else
                {
                    cout<<"invalid input"<<endl;
                    //cout<<"s_n1_"<<s_n1<<endl;
                    s_n1= "";
                    goto new2;
                }
                ret=0;
                //cout<<"s_n1_"<<s_n1<<endl;
            }
            else
            {
                cout<<"invalid option"<<endl;
                goto new1;
            }
            }
        cout<<"Enter password: ";
        password = "";
       while(r=getch())
       {
           if(r!=6&&size1<6)
           {
               //cout << "r ======= " << r << endl;
               password += r;
               //cout << "password ======== " << password << endl;
               cout<<"*";
               size1++;
           }
           else
           {
               cout<<endl;
               size1=0;
               break;
           }

       }


        if(password==p)
        {
          cout<<"***************************************"<<endl;
          cout<<"WELCOME RAJESH KUMAR SINGH"<<endl;
          cout<<"***************************************"<<endl;
          char check;
          do
          {
            FLAG1:
            cout<<"\n1.INSERT COLLEGE:"<<endl;
            cout<<"2.VIEW COLLEGE"<<endl;
           //cout<<"3.VIEW COLLEGE NAME"<<endl;
            cout<<"3.RESET PASSWORD"<<endl;
            //getchar();
            cin>>ch1;

            if(ch1==1)
            { string namec1;
                FLAG2:

                cout<<"\nTYPE 1 TO ADD A COLLEGE:"<<endl;;
                cin>>ch2;

                if(ch2==1)
                {
                    l3:
                    collegename c;
                    c.get_college_inf();
                    cout<<"ADD MORE COLLEGE: YES/NO"<<endl;
                    namec1="";
                    cin>>namec1;
                    if(namec1=="YES")
                    {
                        goto l3;
                    }
                    else
                    {
                        exit(0);
                    }
                }
                else
                {
                    cout<<"Invalid input1\n";
                    goto FLAG2;
                }
            }
            else if(ch1==2)
            {
                goto user;
            }
            else if(ch1==3)
            {
                goto new4;
            }

            else
            {
                cout<<"Invalid input\n";
                goto FLAG1;
            }
            cout<<"Continue?\n";
            cin>>x;
          }while(x=='y' || x=='Y');
            group5.close();
        }

        else
        {
        cout<<"Incorrect password\n";
        password = "";
        ret++;
        goto flag1;
        }
    }
    else if(ch==2)
    {
        user:

        check_2:
        col_name:
            l1:
            l2:
            l5:
        cout<<"\n1.COLLEGE DETAILS\n2.SEARCH\n";
        cout<<"3.COLLEGE LIST"<<endl;
        cin>>ch1;

        if(ch1==1)
        {
            search1();
            goto l1;
        }
      else if(ch1==2)
      {
          check_1:
        cout<<"\n1.PRESS 1:";
        cin>>ch3;
        if(ch3==1)
        {
            string search12,lert;
            cout<<"\nEnter the college to search:";
            cin>>search12;
            search1(search12);
            cout<<"EXIT: YES/NO"<<endl;
            cin>>lert;
            if(lert=="YES")
            {
                exit(0);
            }
            else if(lert=="NO")
            {
                 goto l2;
            }
            else
            {
                cout<<"invalid option"<<endl;
                goto l5;
            }

        }

        else
        {
            cout<<"\n Invalid input";
          goto check_1;
        }
      }
      else if(ch1==3)
      {
          search2();
          goto col_name;
      }
      else
      {
          cout<<"\n Invalid input";
          goto check_2;
      }
    }
    else
    {
        cout<<"Invalid input\n";
        goto check_3;
    }
    }

    group5.close();
    group5c.close();


    return 0;
}

