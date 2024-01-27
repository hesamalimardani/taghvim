#include<stdio.h>
#include<stdlib.h>


void clear()
{
    int c;
    while ((c = getchar()) != '\n');
}

int days_in_persian[] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};//29 in the end & 0 in the first
char *persian_months[] = {
    "               Farvardin              ",
    "              Ordibehesht             ",
    "                Khordad               ",
    "                  Tir                 ",
    "                 Mordad               ",
    "               Shahrivar              ",
    "                  Mehr                ",
    "                  Aban                ",
    "                  Azar                ",
    "                  Dey                 ",
    "                 Bahman               ",
    "                 Esfand               "
};



int getYear()//mahdodiat haye sal vorodi ra moshakhas mikonim
{
    int year;

    do
    {
        printf("Please enter a Year: \n");
        printf("--------------------\n");
        scanf("%d", &year);

        if (year == 0)
        {
            return 0;
        }

        if (year < 1206 || year > 1498)
        {
            printf("\n%s.\n","Invalid year! Please enter a year between 1206 and 1498");
            printf("\nPress Enter to try again...");
            clear();
            getchar(); 
            system("cls"); 
        }
    } 
    while (year < 1206 || year > 1498);

    return year;
}

int getMonth()
{
    int month;//mahdodiat haye mah vorodi ra moshakhas mikonim 
    do
    {
        printf("Please enter a month: \n");
        printf("---------------------\n");
        scanf("%d", &month);

        if (month == 0)
        {
            return 0;
        }

        if (month < 1 || month > 12)
        {
            printf("\n%s.\n", "Invalid month! Please enter a month between 1 and 12");
            printf("\nPress Enter to try again...");
            clear();
            getchar(); 
            system("cls"); 
        }
    } 
    while (month < 1 || month > 12);

    return month;
}

int faseleh(int year, int month)
{
    int faselehhh = (year * 365 + (year / 4) + 1) % 7;

    for (int i = 1; i < month; i++)
    {
        faselehhh = (faselehhh + days_in_persian[i]) % 7;// roozi ra moshkhas mikonad ke az anga tagvim shoroo shavad
    }

    return faselehhh;
}

void kabisee(int year)//mohasebe rooz kabise
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 100 == 0))
    {
        days_in_persian[12 - 1] = 30;// kabise bashad esfand 30 rooz hesab mishavad 
    }
    else
    {
        days_in_persian[12 - 1] = 29;//kabise nabashad esfand 29 rooz hesab mishavad 
    }
}

int mainMenu()
{
    int choice;

    printf("\n[0] Quit\n");
    printf("[1] Calendar\n");
    printf("[2] Age\n");
    printf("[3] Conversion\n");
    printf("------------------------------------\n");
    printf("Select Option: ");
    scanf("%d", &choice);

    return choice;
}

void calendar(int month, int faselehhh)
{
    printf("\n%s\n\n",persian_months[month - 1]);
    printf("%s    %s    %s    %s    %s    %s    %s\n\n", "SH", "YE", "DO", "SE", "CH", "PA", "JO");

    for (int day = 1; day <= faselehhh; day++)// emal gesmat haye khali dar tagvim
    {
        printf("      ");
    }

    for (int day = 1; day <= days_in_persian[month]; day++)
    {
        printf("%-6d", day); //-6 => For 5 spaces

        if ((day + faselehhh) % 7 == 0 || day == days_in_persian[month])
            printf("\n");// paeen raftan satr dar tagvim
    }
    printf("\n%s\n", "--------------------------------------");
}

int main()
{
    int choice, persian_year, persian_month, faselehh;

    do 
    {
    choice = mainMenu();
        
    switch (choice) 
    {
    case 0:
    system("cls");
    printf("Goodbye!\n");
    break;
    //=========================================================================
    case 1:
    system("cls");
    persian_year = getYear();
    if (persian_year == 0)
    {
    break;
    }

    persian_month = getMonth();
    if (persian_month == 0)
    {
    break;
    }

    faselehh = faseleh(persian_year, persian_month);
    kabisee(persian_year);
    system("cls");

    calendar(persian_month,faselehh);

    printf("\nPress Enter to continue...");
    clear();
    getchar();
    break;
    //==============================================================================
    case 2:
    printf("You selected Age.\n");
               
    int year2;
    int month2;
    int day2;
    printf("Enter your year of birth:");
    scanf("%d",&year2);
    printf("Enter your month of birth:");
    scanf("%d",&month2);
    printf("Enter your day of birth:");
    scanf("%d",&day2);
    printf("------------------------\n");
    int age = 1402 - year2;
    printf("your age is: %d\n" , age);
    switch (month2)
    {
        case 1:
        printf("your birthday: %d" , day2);
        printf(" Farvardin\n");
        break;

        case 2:
        printf("your birthday: %d" , day2);
        printf(" Ordibehesht\n");
        break;

        case 3:
        printf("your birthday: %d" , day2);
        printf(" Khordad\n");
        break;

        case 4:
        printf("your birthday: %d" , day2);
        printf(" Tir\n");
        break;

        case 5:
        printf("your birthday: %d" , day2);
        printf(" Mordad\n");
        break;

        case 6:
        printf("your birthday: %d" , day2);
        printf(" Shahrivar\n");
        break;

        case 7:
        printf("your birthday: %d" , day2);
        printf(" Mehr\n");
        break;

        case 8:
        printf("your birthday: %d" , day2);
        printf(" Ababn\n");
        break;

        case 9:
        printf("your birthday: %d" , day2);
        printf(" Azar\n");
        break;

        case 10:
        printf("your birthday: %d" , day2);
        printf(" Dey\n");
        break;

        case 11:
        printf("your birthday: %d" , day2);
        printf(" Bahman\n");
        break;

        case 12:
        printf("your birthday: %d" , day2);
        printf(" Esfand\n");
        break;

        default:
       printf("Not founded");
        break;
            
    }
    int the_number_of_days_you_have_lived = age * 365;
    printf("the number of days you have lived: %d day\n" ,the_number_of_days_you_have_lived);
    printf("--------------------------------------\n");
    printf("date of birth in solar terms:");
    printf(" %d.%d.%d\n", year2 , month2, day2);
    printf("date of birth in AD:");
    if (month2 == 1 && day2 <= 11)
    {
        int b = 621 + year2;
        printf("%d" , b);
        printf(" . 3(march)\n");  
    }
    else if (month2 == 1 && day2 >= 12)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 4(april)\n");
    }
    else if (month2 == 2 && day2 <= 10)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 4(april)\n");
    }
    else if (month2 == 2 && day2 >= 10)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 5(may)\n");
    }
    else if (month2 == 3 && day2 <= 10)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . may(5)\n");
    }
    else if (month2 == 3 && day2 >= 11)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 6(june)\n");
    }
    else if ( month2 == 4 && day2 <= 9)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 6(june)\n");
    }
    else if (month2 == 4 && day2 >= 10)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 7(july)\n");
    }
    else if (month2 == 5 && day2 <= 9)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 7(july)\n");
    }
    else if (month2 == 5 && day2 >= 10)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 8(agust)\n");
    }
    else if (month2 == 6 && day2 <= 9)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 8(agust)\n");
    }
    else if (month2 == 6 && day2 >= 10)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 9(september)\n");
    }
    else if (month2 == 7 && day2 <= 8)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 9(september)\n");
    }
    else if (month2 == 7 && day2 >= 9)
    {
    int b = 621 + year2; 
    printf("%d" , b);
    printf(" . 10(october)\n");
    }
    else if (month2 == 8 && day2 <= 9)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 10(october)\n");
    }
    else if (month2 == 8 && day2 >= 10)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 11(november)\n");
    }
    else if (month2 == 9 && day2 <= 9)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 11(november)\n");
    }
    else if (month2 == 9 && day2 >= 10)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 12(december)\n");
    }
    else if (month2 == 10 && day2 <= 10)
    {
    int b = 621 + year2;
    printf("%d" , b);
    printf(" . 12(december)\n");
    }
    else if (month2 == 10 && day2 >= 11)
    {
    int c = 622 + year2;
    printf("%d" , c);
    printf(" . 1(january)\n");
    }
    else if (month2 == 11 && day2 <= 11)
    {
    int c = 622 + year2;
    printf("%d" , c);
    printf(" . 1(january)\n");
    }
    else if (month2 == 11 && day2 >= 12)
    {
    int c = 622 + year2;
    printf("%d" , c);
    printf(" . 2(february)\n");
    }
    else if (month2 == 12 && day2 <= 9)
    {
    int c = 622 + year2;
    printf("%d" , c);
    printf(" . 2(february)\n");
    }
    else if (month2 == 12 && day2 >= 10)
    {
    int c = 622 + year2;
    printf("%d" , c);
    printf(" . 3(march)\n");
    printf("---------------------------------------\n");
    }


    break;
    //========================================================================================
    case 3:
    printf("You selected Conversion.\n");
    printf("enter your option :\n 0 = shamsi be miladi \n 1 = miladi be shamsi\n");
    int choises;
    scanf("%d" , &choises);
    do
    {
        switch (choises)
        {
        case 0:
        system("cls");
        printf("you choise convert shamsi date to miladi date\n");

        int year3;
        int month3;
        int day3;
        printf("enter your birth year:");
        scanf("%d" , &year3);

        printf("enter your month of birth:");
        scanf("%d" , &month3);

        printf("enter your day of birth:");
        scanf("%d" , &day3);
        
        if (month3 == 1 && day3 <= 11)
        {
            int b = 621 + year3;
            printf("%d" , b);
            printf(" . 3(march)\n");  
        }
        else if (month3 == 1 && day3 >= 12)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 4(april)\n");
        }
        else if (month3 == 2 && day3 <= 10)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 4(april)\n");
        }
        else if (month3 == 2 && day3 >= 10)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 5(may)\n");
        }
        else if (month3 == 3 && day3 <= 10)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . may(5)\n");
        }
        else if (month3 == 3 && day3 >= 11)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 6(june)\n");
        }
        else if ( month3 == 4 && day3 <= 9)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 6(june)\n");
        }
        else if (month3 == 4 && day3 >= 10)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 7(july)\n");
        }
        else if (month3 == 5 && day3 <= 9)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 7(july)\n");
        }
        else if (month3 == 5 && day3 >= 10)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 8(agust)\n");
        }
        else if (month3 == 6 && day3 <= 9)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 8(agust)\n");
        }
        else if (month3 == 6 && day3 >= 10)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 9(september)\n");
        }
        else if (month3 == 7 && day3 <= 8)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 9(september)\n");
        }
        else if (month3 == 7 && day3 >= 9)
        {
        int b = 621 + year3; 
        printf("%d" , b);
        printf(" . 10(october)\n");
        }
        else if (month3 == 8 && day3 <= 9)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 10(october)\n");
        }
        else if (month3 == 8 && day3 >= 10)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 11(november)\n");
        }
        else if (month3 == 9 && day3 <= 9)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 11(november)\n");
        }
        else if (month3 == 9 && day3 >= 10)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 12(december)\n");
        }
        else if (month3 == 10 && day3 <= 10)
        {
        int b = 621 + year3;
        printf("%d" , b);
        printf(" . 12(december)\n");
        }
        else if (month3 == 10 && day3 >= 11)
        {
        int c = 622 + year3;
        printf("%d" , c);
        printf(" . 1(january)\n");
        }
        else if (month3 == 11 && day3 <= 11)
        {
        int c = 622 + year3;
        printf("%d" , c);
        printf(" . 1(january)\n");
        }
        else if (month3 == 11 && day3 >= 12)
        {
        int c = 622 + year3;
        printf("%d" , c);
        printf(" . 2(february)\n");
        }
        else if (month3 == 12 && day3 <= 9)
        {
        int c = 622 + year3;
        printf("%d" , c);
        printf(" . 2(february)\n");
        }
        else if (month3 == 12 && day3 >= 10)
        {
        int c = 622 + year3;
        printf("%d" , c);
        printf(" . 3(march)\n");
        printf("---------------------------------------\n");
        }
        clear();
        getchar();
        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        break;
       

        case 1:
            system("cls");
            printf("you choise convert miladi date to shamsi date");

            int year4;
            int month4;
            int day4;
            printf("enter your birth year:");
            scanf("%d" , &year4);

            printf("enter your month of birth:");
            scanf("%d" , &month4);

            printf("enter your day of birth;");
            scanf("%d" , &day4);
            
            if (month4 == 3 && day4 <= 11)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . farvardin\n");  
            }
            else if (month4 == 4 && day4 >= 12)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . farvardin\n");
            }
            else if (month4 == 4 && day4 <= 10)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . ordibehesht\n");
            }
            else if (month4 == 5 && day4 >= 10)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . ordibehesht\n");
            }
            else if (month4 == 5 && day4 <= 10)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . khordad\n");
            }
            else if (month4 == 6 && day4 >= 11)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . khordad\n");
            }
            else if ( month4 == 6 && day4 <= 9)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . tir\n");
            }
            else if (month4 == 7 && day4 >= 10)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . tir\n");
            }
            else if (month4 == 7 && day4 <= 9)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . mordad\n");
            }
            else if (month4 == 8 && day4 >= 10)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . mordad\n");
            }
            else if (month4 == 8 && day4 <= 9)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . shahrivar\n");
            }
            else if (month4 == 9 && day4 >= 10)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . shahrivar\n");
            }
            else if (month4 == 9 && day4 <= 8)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . mehr\n");
            }
            else if (month4 == 10 && day4 >= 9)
            {
            int b = year4 - 621; 
            printf("%d" , b);
            printf(" . mehr\n");
            }
            else if (month4 == 10 && day4 <= 9)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . aban\n");
            }
            else if (month4 == 11 && day4 >= 10)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . aban\n");
            }
            else if (month4 == 11 && day4 <= 9)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . azar\n");
            }
            else if (month4 == 12 && day4 >= 10)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . azar\n");
            }
            else if (month4 == 12 && day4 <= 10)
            {
            int b = year4 - 621;
            printf("%d" , b);
            printf(" . dey\n");
            }
            else if (month4 == 1 && day4 >= 11)
            {
            int c = year4 - 622;
            printf("%d" , c);
            printf(" . dey\n");
            }
            else if (month4 == 1 && day4 <= 11)
            {
            int c = year4 - 622;
            printf("%d" , c);
            printf(" . bahman\n");
            }
            else if (month4 == 2 && day4 >= 12)
            {
            int c = year4 - 622;
            printf("%d" , c);
            printf(" . bahman\n");
            }
            else if (month4 == 2 && day4 <= 9)
            {
            int c = year4 - 622;
            printf("%d" , c);
            printf(" . esfand\n");
            }
            else if (month4 == 3 && day4 >= 10)
            {
            int c = year4 - 622;
            printf("%d" , c);
            printf(" .esfand\n");
            printf("---------------------------------------\n");
            }
            clear();
            getchar();
        
        break;

        default:
        printf("invalid input");
        break;
        } 
     //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++              
    } 
    while (choises != 0);
                
    break;
    default:
    printf("Invalid option. Please try again.\n");
    break;
    }
    } 
    while (choice != 0);

    return 0;
}