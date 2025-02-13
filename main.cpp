/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string.h>
#include <math.h>
#define TRUE 1
using namespace std;

int ch;

class Login
{
public:
    int flag = 0, st_counter = 0, ch, x = 0;
    char username[100], password[100],st_un[100][100] , st_password[100][100];

    int input()
    {
        do
        {
            cout << "1. Login" << endl;
            cout << "2. Sign Up" << endl;
            cout << "3. Exit" << endl;
            cout << "Please make a choice" << endl;
            cin >> ch;

            switch (ch)
            {
                case 1: login();
                        if(x == 1)
                        {
                            return x;
                        }
                        break;
                case 2: sign_up();
                        break;
                case 3: cout << "Session Ends" << endl ;
                default : cout << "Error! Please enter a suitable value. " << endl;
            }
        } while(ch != 3);
        
    }

    void login()
    {
        int y;
        cout << "Please enter your username: " << endl;
        cin >> username;
                
        cout << "Please enter your password: " << endl;
        cin >> password;

        encrypt();

        y = validate();

        if (y == 1)
        {
            x = 1;
        }
        else if (y == 2)
        {
            cout << "Incorrect Password entered. Please try again !" << endl;
        }
        else 
        {
            cout << "Login Failed ! Please create an account first !" << endl;
        }
    }

    void sign_up()
    {
        cout << "Please enter your username: " << endl;
        cin >> username;
        cout << "Please enter your password: " << endl;
        cin >> password;
        encrypt();
        strcpy(st_un[st_counter], username);
        strcpy(st_password[st_counter], password);
        st_counter++;
        cout << "Your account has been successfully created. Please log in once you reach the main screen." << endl;
    }

    void encrypt()
    {
        int e;
        int n = strlen(password);
        for (int i = 0; i < n ; i++)
        {
            e = (int)password[i];
            e += 2;
            password[i] = (char)e;
        }        
    }

    int validate()
    {   
        int no = 100;
        for (int i = 0; i < no; i++)
        {
            if (strcmp(st_password[i],password) == 0 && strcmp(st_un[i],username) == 0)
            {
                flag = 1;
                break;
            }
            else if (strcmp(st_un[i],username) == 0)
            {
                flag = 2;
                break;
                
            }
            else
            {
                flag = 0;
            }

        }
        return flag;
        
        
    }

};
class Finance
{
public:
    float pr;

    void fin_choice(float p)
    {
        int ch, x, cr_s;
        long int c_no, ch_no ;
        char ch_name[50];

        pr = p;
        cout << "1. Pay by Cash. " << endl;
        cout << "2. Pay by Card. " << endl;
        cout << "3. Pay by Cheque. " << endl;
        cout << "4. Pay via financing. " << endl;
        cout << "5. Exit. " << endl;
        cout << "Please make a choice. " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1: Pay();
                break;
        
        case 2: cout << "Please enter your card number: " << endl ;
                cin >> c_no;
                Pay(c_no);
                break;
        
        case 3: cout << "Please enter the bank from which cheque is being issued: " << endl;
                cin >> ch_name;
                cout << "Please enter cheque number: " << endl;
                cin >> ch_no;
                Pay(ch_name, ch_no);
                break;
        case 4: cout << " Please enter your CIBIL credit score: " << endl;
                cin >> cr_s;
                Pay (cr_s);
                break;
        case 5: cout << "Session ended! Thank you!" << endl;
                break;
        default: cout << "Error! Please enter correct value." << endl;
        }

        
        
    }

    void Pay()
    {
        cout << " Thank you for paying Rs. " << pr << "by cash." << endl;        
    }

    void Pay(long int cn)
    {
        int cvv,otp;
        cout << " Your card number is: " << cn << endl;
        cout << " Please enter your cvv: " << endl;
        cin >> cvv;
        cout << " Please enter your OTP: " << endl;
        cin >> otp;
        cout << "Transaction successful ! " << endl;

    }

    void Pay(char bn[50], long int chn)
    {
        cout << " Your cheque issued under " << bn << "bank with number: "<< chn  << "will be cashed in 7-12 business days."<< endl;
    }

    void Pay (int crs)
    {
        if (crs <549)
        {
            cout << "Your credit score is poor! " << endl;
            float intrst = 0.18;
            cout << "Your monthly interest rate is: "<< (intrst*100) << "percent" << endl;
            float downpayment = 0.7 * pr;
            cout << "You need to pay Rs. " << downpayment << "as downpayment" << endl;
            float left = pr - downpayment;
            float emi = (left * intrst * pow(1 + intrst, 24))/ (pow(1+intrst, 24)-1);
            cout << "You need to pay " << emi << "for the next 2 years. " << endl;
        }
        else if (550 < crs < 749)
        {
            cout << "Your credit score is good! " << endl;
            float intrst = 0.07;
            cout << "Your monthly interest rate is: "<< (intrst*100) << "percent" << endl;
            float downpayment = 0.5 * pr;
            cout << "You need to pay Rs. " << downpayment << "as downpayment" << endl;
            float left = pr - downpayment;
            float emi = (left * intrst * pow(1 + intrst, 24))/ (pow(1+intrst, 24)-1);
            cout << "You need to pay " << emi << "for the next 2 years. " << endl;
        }
        else 
        {
            cout << "Your credit score is excellent! " << endl;
            float intrst = 0.04;
            cout << "Your monthly interest rate is: "<< (intrst*100) << "percent" << endl;
            float downpayment = 0.1 * pr;
            cout << "You need to pay Rs. " << downpayment << "as downpayment" << endl;
            float left = pr - downpayment;
            float emi = (left * intrst * pow(1 + intrst, 24))/ (pow(1+intrst, 24)-1);
            cout << "You need to pay " << emi << "for the next 2 years. " << endl;
        }
    }

    
};

class buy_sell : public Finance
{
public:
  int i, j;			//row and column number
  int b_s_ch;			//choice for buy or sell 
  int select;			//select number of car we are buying

  char car_name[30];
  float price;

  char car_list[5][25] = { "Tata_Punch", "Suzuki_Swift", "Toyota_Innova" , "Renault_Kwid", "Kia_Seltos" };
  float car_price[5]= {500000, 700000, 1800000, 400000, 800000 }; 



  void choice ()
  {
    cout << "Enter option if you want to buy or Sell." << endl;
    cout << "Enter 1 if you want to buy." << endl;
    cout << "Enter 2 if you want to sell." << endl;
    cout << "Enter your option: ";
    cin >> b_s_ch;

    switch (b_s_ch)
    {
        case 1: buy ();
                fin_choice(price);
                break;
        case 2: sell ();
                fin_choice(price);
                break;
        default: cout << "Please enter an option between 1 and 2. Thank you" << endl;
                
    }
    
  }

  void buy ()
  {
    for (int i = 0; i < 5; i++)
      {
	    cout << i+1 << car_list[i] << car_price[i] << " ";
	    cout << "\n";
      }

    cout << "\n\nPlease enter the car number from the list of cars: ";
    cin >> select;
    
    strcpy(car_name, car_list[select-1]);
    price = car_price[select-1];
    
    cout << "\nThe car you bought is " << car_list[select-1] << "worth Rs." << car_price[select-1] << endl;
  }

  void sell ()
  {
    cout << "Enter the car name you want to sell: ";
    cin >> car_name;
    cout << "Enter the price at which you want to sell the car at: ";
    cin >> price;
  }

  friend class Rent_Lease;
};

class Rent_Lease : public Finance
{
    private:
    int choice, select ;
    float days, years, amount;
    char selection[25];
    
    public:
    void rent(buy_sell b)
    {
        for (int i = 0 ; i < 5 ; i++ )
        {
            cout << i+1 << "." << b.car_list[i];
        }
        cout<<"Choose the car you want to rent:"<<endl;
        cin>>select;
        strcpy(selection, b.car_list[select-1] );
        amount = b.car_price[select-1];
        cout<<endl;
        
        cout<<"Enter the duration of the rent:"<<endl;
        cin>>days;
        cout<<endl;
        if (days > 30)
        {
            cout<<"Invalid duration"<<endl;
            exit(0);
        } 
        cout<<"The car has been rented for "<<days<<" days"<<endl<<endl;
        
        if (1<days && days<5) 
        {
          cout<<"The cost of rent is "<<0.05*amount<<endl;
        } 
        else if (6<days && days<12) 
        {
          cout<<"The cost of rent is "<<0.07*amount<<endl;
        } 
        else if (13<days && days<20) 
        {
          cout<<"The cost of rent is "<<0.09*amount<<endl;
        } 
         else 
        {
          cout<<"The cost of rent is "<<0.12*amount<<endl;
        }
       
    }
    
    void lease(buy_sell s)
    {
        for (int i = 0 ; i < 5 ; i++ )
        {
            cout << i+1 << "." << s.car_list[i];
        }
        cout<<"Choose the car you want to lease:"<<endl;
        cin>>select;
        cout<<endl;
        strcpy(selection , s.car_list[select-1]) ;
        amount = s.car_price[select-1];
        cout<<endl;

        
        cout<<"Enter for how many years you want to lease the car :"<<endl;
        cin>>years;
        cout<<endl;
         if (years > 6)
        {
            cout<<"Invalid duration"<<endl;
            exit(0);
        } 
        cout<<"The car has been leased for "<<years<<" years"<<endl;
        
       if (1<=years && years<=2) 
        {
          cout<<"The cost of the lease is "<<0.15*amount<<endl;
        } 
        else if (3<=years && years<=4) 
        {
          cout<<"The cost of the lease is "<<0.2* amount<<endl;
        }
         else 
        {
          cout<<"The cost of the lease is "<<0.25*amount<<endl;
        }
    }
    
    void display()
    {
    cout<<"MENU"<<endl; 
    cout <<"1.Rent a car" <<endl;
    cout <<"2.Lease a car" <<endl;
    cout <<"3.Exit" << endl;
    cout <<"What would you like to choose?"<<endl ;
    cin >> choice;
    cout << endl;
    buy_sell b_s;
    
    switch(choice)
    {
        case 1: rent(b_s); 
                fin_choice(amount);
                break;
        case 2: lease(b_s);
                fin_choice(amount);
                break;
        case 3: cout <<"Thank you availing our services"<< endl;
                break;
        default: cout <<"Error"<<endl;
    }
    }
};


class Accessories : public Finance
{
    public:
        float LED= 2500;
        float TV = 5000;
        float PMount = 500;
        float Camera = 1750;
        float sensor = 1200;
        float cover = 3000;
        int item, count;
        float cost;
        
        void disp()
        {
        cout<<"ACCESSORIES LIST"<<endl;
        cout<<"1. LED Lights : Rs 2500"<<endl;
        cout<<"2. Touchscreen TV : Rs 5000"<<endl;
        cout<<"3. Phone Mount :Rs 500"<<endl;
        cout<<"4. Dashboard Camera : Rs 1750"<<endl;
        cout<<"5. Parking Sensors : Rs 1200"<<endl;
        cout<<"6. Seat Cover : Rs 3000"<<endl;
        
        cout<<"Choose Your Accessory : "<<endl;
        cin>> item;
       
   
   switch(item) 
   {
        case 1:
              cout << "LED Lights"<<endl;
              cost=LED;
              calculate();
              fin_choice(cost);
        break;
    
        case 2:
              cout << "Touchscreen TV"<<endl;
              cost=TV;
              calculate();
              fin_choice(cost);
        break;
        
        case 3:
              cout << "Phone Mount"<<endl;
              cost=PMount;
              calculate();
              fin_choice(cost);
        break;
        
        case 4:
              cout << "Dashboard Camera"<<endl;
              cost=Camera;
              calculate();
              fin_choice(cost);
        break;
        
        case 5:
              cout << "Parking Sensors"<<endl;
              cost=sensor;
              calculate();
              fin_choice(cost);
        break;
        
        case 6:
              cout << "Seat Covers"<<endl;
              cost=cover;
              calculate();
              fin_choice(cost);
        break;
 
     }
     }

    void calculate()
   {
    cout<<"\nEnter the quantity :"<<endl;
    cin>>count;
 
    cout<<"Cost is : ";
    cost=cost*count;
    cout<<cost<<endl;
    } 
        
};

class enquiry: protected buy_sell, protected Accessories
{   
    private:
        int op;
        int i,u;
    
    public:
        int en()
        {
            do{
            cout << "*****ENQUIRY MENU*****" << endl;
            cout << "1. PRINT LIST OF AVAILABLE CARS" << endl;
            cout << "2. PRINT LIST OF ACCESORIES" << endl;
            cout << "3. EXIT" << endl;
            cout << "PLEASE ENTER YOUR CHOICE: " << endl;
            cin >> op;
            switch(op)
            {
                case 1: cout << "THE LIST OF AVAILABLE CARS ARE:" << endl;
                        for(i = 0; i<5;i++)
                        {
                            cout << i+1 << ". " << car_list[i];
                        }
                        break;
                case 2: cout << "THE LIST OF ACCESSORIES ARE:" << endl;
                        cout<<"1. LED Lights"<<endl;
                        cout<<"2. Touchscreen TV"<<endl;
                        cout<<"3. Phone Mount"<<endl;
                        cout<<"4. Dashboard Camera"<<endl;
                        cout<<"5. Parking Sensors"<<endl;
                        cout<<"6. Seat Cover"<<endl;
                        break;
                case 3: cout << "WOULD YOU LIKE TO LOGIN AND CONTINUE FURTHER?" << endl;
                        cout << "PRESS 1 TO CONTINUE AND 0 TO TERMINATE SESSION." << endl;
                        cout << "ENTER YOUR CHOICE" << endl;
                        cin >> u;
                        if(u==1)
                        {
                            return u;
                        }
                        else if(u == 0)
                        {
                            cout << "SESSION ENDED" << endl;
                            return u;
                        }
                        else
                        {
                            cout << "PLEASE ENTER EITHER 1 OR 0. Thank You" << endl;
                        }
                        break;
                default: cout << "ERROR! PLEASE ENTER AN APPROPRIATE VALUE." << endl;
            }
            }while(op!=3 && u == 1 || u == 0);   
        }
        
};


void bsrlacch()
{
    buy_sell bs;
    Rent_Lease rl;
    Accessories acc;
    do
    {
        cout << "1. Buy/Sell " << endl;
        cout << "2. Rent/Lease" << endl;
        cout << "3. Accessories" << endl;
        cout << "4. Exit" << endl;
        cout << "Please make a choice: " ;
        cin >> ch;
        cout << endl;
        
        switch(ch)
        {
            case 1: bs.choice();
                    break;
            case 2: rl.display();
                    break;
            case 3: acc.disp();
                    break;
            case 4: cout << "Session Ends!" << endl;
                    break;
            default: cout << "Error! " <<endl;
        }
    }while (ch !=4);
}

int main()
{
    Login l;
    enquiry e;
    

    int t, b;
    do
    {
    cout << "1. Login/Register" << endl;
    cout << "2. Enquiry" << endl;
    cout << "3. Exit" << endl;
    cout << "Please make a choice: " ;
    cin >> ch;
    cout << endl;
    
    switch(ch)
    {
        case 1: t = l.input();
                if(t == 1 )
                {
                    bsrlacch();
                }
                else
                {
                    ch = 3;
                }
                break;
                
        case 2: t = e.en();
                if (t == 1)
                {
                    b = l.input();
                    if (b == 1)
                    {
                        bsrlacch();
                    }
                    else
                    {
                        ch = 3;
                    }
                }
                else
                {
                    ch = 3;
                }
                break;
        case 3: cout << "Session ends! Thank you for using our services " << endl;
                break;
        default: cout << "Error! " <<endl;
    }
    
    }while (ch !=3);
    
}







