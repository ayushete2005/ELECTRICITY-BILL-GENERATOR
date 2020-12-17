// BY - Ayush Shete

#include <stdio.h>
#include <strings.h>
#include <time.h>
void line()
{
    printf("\n\n\n");
    for (int i = 0; i < 150; i++)
    {
        printf("-");
    }
    printf("\n\n\n");
}
void time()
{

    time_t local_time;
    time(&local_time);
    printf("\tTime:- %s", ctime(&local_time));
}

int Billprint(char *name, int id, int a, float b, float c)
{

    printf("\n\t\t\t\tELECTRICITY BILL\n\n");
    printf("\t\t\t\t\t\t\t\t\t");
    time();
    printf("\n\tNAME :- ");
    while (*name != '\0')
    {
        printf("%c", *name);
        *name++;
    }
    printf("\t\t\t\tCONSUMER id :- %d\n\n", id);
    printf("\tConsumption in a month:-    \t %d units.\n", a);
    printf("\tEnergy charge is :-         \t Rs %.2f\n", b);
    printf("\tFixed Rate :-               \t Rs %.2f\n", c);
    printf("\tSupply Charges:-            \t Rs 10.5\n");
    printf("\tOther charges :-            \t Rs 5.2\n");
    printf("\n\n\t\tTotal charge you have to pay :- Rs %.2f/-only\n", ((a * b) + c)+15.7);
    printf("\n\t\tTHANK YOU......\n");

    printf("\n\n\n");
    for (int i = 0; i < 150; i++)
    {
        printf("*");
    }
    printf("\npress 1 for print ELECTRICITY BILL: ");
    scanf("%d", &a);
    printf("\n\n\t\tError!!!  You have no connection of printer\n\n\t\tTHANK YOU......");
    line();
    return 0;
}

int main()
{
    char name[15];
    FILE *fileLV, *fileDomestic, *filenonDomestic, *filevolt, *fileHV;
    int Volt, C, S, E;
    int a, b;
    float Ec, Fr; // <---- Ec = Energy charge , Fr = Fixed rate
    long int id;

    printf("Please enter your Name: ");
    gets(name);

    printf("Please enter consumer id: ");
    scanf("%ld", &id);
    line();
    filevolt = fopen("filevolt.txt", "r");
    while (!feof(filevolt))
    {
        printf("%c", getc(filevolt));
    }

    scanf("%d", &Volt);
    line();
    switch (Volt)
    {
    case 1:
    {
        fileLV = fopen("fileLV.txt", "r");
        while (!feof(fileLV))
        {
            printf("%c", getc(fileLV));
        }

        scanf("%d", &C);
        switch (C)
        {
        case 1:
        {
            line();
            printf("\nChoose your supply\n\tPress 1 for Single Phase Domestic Supply\n\tPress 2 for Three Phase Domestic Supply\n\n\tEnter your sypply: ");
            scanf("%d", &S);
            line();
            switch (S)
            {
            case 1:
            {
                printf("\tContracted Load up to 500 W = Rs. 600/month\n\tContracted Load above 500 W = Rs. 1500/month\n\nEnter your Energy consumption: ");
                scanf("%d", &a);
                line();
                if (a <= 500)
                {
                    Ec = 600 / a;
                    Fr = 00;
                    if (Billprint(name, id, a, Ec, Fr) == 0)
                    {
                        return 0;
                    }
                }
                if (a > 500)
                {
                    Ec = 1500 / a;
                    Fr = 00;

                    if (Billprint(name, id, a, Ec, Fr) == 0)
                    {
                        return 0;
                    }
                }
                
            }

            case 2:
            {
                fileDomestic = fopen("fileDomestic.txt", "r");
                while (!feof(fileDomestic))
                {
                    printf("%c", getc(fileDomestic));
                }
                scanf("%d", &E);
                line();
                switch (E)
                {
                case 1:
                {
                    printf("\tConsumption\t\t\t\tEnergy Charge\t\t\tFixed Charge\n\n");
                    printf("\t0-30kWh/month\t\t\t\tRs.4.25/kWh\t\t\tRs.20/connection/month\n\n");
                    printf("Enter your consumption (between 0-30): ");
                    scanf("%d", &a);
                    line();
                    Ec = 4.25;
                    Fr = 20;
                    if (Billprint(name, id, a, Ec, Fr) == 0)
                    {
                        return 0;
                    }
                }

                case 2:
                {
                    printf("\tConsumption\t\t\t\tEnergy Charge\t\t\tFixed Charge\n\n");
                    printf("\t0-120kWh/month   \t\t\tRs.5.10/kWh\t\t\tRs.50/kw/month\n");
                    printf("\t121-240kWh/month\t\t\tRs.6.35/kWh\t\t\tRs.50/kw/month\n");
                    printf("\t241kWh/month and above\t\t\tRs.7.35/kWh\t\t\tRs.50/kw/month\n\n");
                    printf("Enter your energy consumption: ");
                    scanf("%d", &a);
                    line();
                    if (a <= 120)
                    {
                        Ec = 5.10;
                        Fr = 50;

                        if (Billprint(name, id, a, Ec, Fr) == 0)
                        {
                            return 0;
                        }
                    }
                    else if (a >= 121 && a <= 240)
                    {
                        Ec = 6.35;
                        Fr = 50;

                        if (Billprint(name, id, a, Ec, Fr) == 0)
                        {
                            return 0;
                        }
                    }
                    else if (a >= 241)
                    {
                        Ec = 7.35;
                        Fr = 50;

                        if (Billprint(name, id, a, Ec, Fr) == 0)
                        {
                            return 0;
                        }
                    }

                    if (Billprint(name, id, a, Ec, Fr) == 0)
                    {
                        return 0;
                    }
                }

                case 3:
                {
                    printf("\tConsumption\t\t\t\tEnergy Charge\t\t\tFixed Charge\n\n");
                    printf("\tFor all Consumption\t\t\tRs.6.95/kWh\t\t\tRs.70/kW/month\n\n");
                    printf("Enter your energy consumption: ");
                    scanf("%d", &a);
                    line();
                    Ec = 6.95;
                    Fr = 70;
                    if (Billprint(name, id, a, Ec, Fr) == 0)
                    {
                        return 0;
                    }
                }
                default:
                {
                    line();
                    printf("\tError!!!  Wrong key pressed!! Try again!!\n\n");
                    return 0;
                }
                break;
                }
            }
            default:
            {
                line();
                printf("\tError!!!  Wrong key pressed!! Try again!!\n\n");
                return 0;
            }
            break;
            }
        }

        case 2:
        {
            line();
            filenonDomestic = fopen("filenonDomestic.txt", "r");
            while (!feof(filenonDomestic))
            {
                printf("%c", getc(filenonDomestic));
            }
            scanf("%d", &S);
            line();
            switch (S)
            {
            case 1:
            {
                printf("\nChoose your supply\n\tPress 1 for Single Phase Non-Domestic Supply\n\tPress 2 for Three Phase Non-Domestic Supply\n\n\tEnter your sypply: ");
                scanf("%d", &E);
                line();
                switch (E)
                {
                case 1:
                {
                    printf("\tConsumption\t\t\t\tEnergy Charge\t\t\tFixed Charge\n\n");
                    printf("\t0-100kWh/month   \t\t\tRs.5.40/kWh\t\t\tRs.50/kw/month\n");
                    printf("\t101-400kWh/month\t\t\tRs.6.50/kWh\t\t\tRs.50/kw/month\n");
                    printf("\t401kWh/month  and above\t\t\tRs.7.90/kWh\t\t\tRs.50/kw/month\n\n");
                    printf("Enter your energy consumption: ");
                    scanf("%d", &a);
                    line();
                    if (a <= 100)
                    {
                        Ec = 5.40;
                        Fr = 50;

                        if (Billprint(name, id, a, Ec, Fr) == 0)
                        {
                            return 0;
                        }
                    }
                    else if (a <= 400 && a >= 101)
                    {
                        Ec = 6.50;
                        Fr = 50;

                        if (Billprint(name, id, a, Ec, Fr) == 0)
                        {
                            return 0;
                        }
                    }
                    else if (a >= 401)
                    {
                        Ec = 7.90;
                        Fr = 50;

                        if (Billprint(name, id, a, Ec, Fr) == 0)
                        {
                            return 0;
                        }
                    }

                    return 0;
                }
                case 2:
                {
                    printf("\tConsumption\t\t\t\tEnergy Charge\t\t\tFixed Charge\n\n");
                    printf("\t0-400kWh/month\t\t\t\tRs.6.50/kWh\t\t\tRs.150/kw/month\n");
                    printf("\t401kWh/month  and above\t\t\tRs.7.80/kWh\t\t\tRs.150/kw/month\n\n");
                    printf("Enter your energy consumption: ");
                    scanf("%d", &a);
                    line();
                    if (a <= 400)
                    {
                        Ec = 6.50;
                        Fr = 150;

                        if (Billprint(name, id, a, Ec, Fr) == 0)
                        {
                            return 0;
                        }
                    }
                    else if (a >= 401)
                    {
                        Ec = 7.80;
                        Fr = 150;

                        if (Billprint(name, id, a, Ec, Fr) == 0)
                        {
                            return 0;
                        }
                    }
                }

                default:
                {
                    line();
                    printf("\tError!!!  Wrong key pressed!! Try again!!\n\n");
                    return 0;
                }
                break;
                }

                break;
            }
            case 2:
            {
                printf("\tConsumption\t\t\tEnergy Charge\t\t\tFixed Charge\n\n");
                printf("\tFor All\t\t\t\tRs.4.40/kWh\t\t\tRs.80/kw/month\n\n");
                printf("Enter your energy consumption: ");
                scanf("%d", &a);
                line();
                Ec = 4.40;
                Fr = 80;
                if (Billprint(name, id, a, Ec, Fr) == 0)
                {
                    return 0;
                }
            }
            case 3:
            {
                printf("\tConsumption\t\t\tEnergy Charge\t\t\tFixed Charge\n\n");
                printf("\tUp to 18.7 kW\t\t\t\tRs.4.75/kWh\t\t\tRs.100/kw/month\n");
                printf("\tAbove 18.7kW to 112.5 kW\t\tRs.5.50/kWh\t\t\tRs.110/kw/month\n\n");
                printf("Enter your energy consumption: ");
                scanf("%d", &a);
                line();
                if (a <= 18.7)
                {
                    Ec = 4.75;
                    Fr = 100;
                    if (Billprint(name, id, a, Ec, Fr) == 0)
                    {
                        return 0;
                    }
                }
                else if (a >= 18.7)
                {
                    Ec = 5.5;
                    Fr = 110;
                    if (Billprint(name, id, a, Ec, Fr) == 0)
                    {
                        return 0;
                    }
                }
            }

            default:
            {
                line();
                printf("\tError!!!  Wrong key pressed!! Try again!!\n\n");
                return 0;
            }
            break;
            }
        }
        default:
        {
            line();
            printf("\tError!!!  Wrong key pressed!! Try again!!\n\n");
            return 0;
        }
        break;
        }
        break;
    }

    case 2:
    {
        fileHV = fopen("fileHV.txt", "r");
        while (!feof(fileHV))
        {
            printf("%c", getc(fileHV));
        }

        scanf("%d", &C);
        line();

        switch (C)
        {
        case 1:
        {
            printf("\n\tSupply Voltage\t\t\t\tEnergy Charge\t\t\tFixed Charge\n\n");
            printf("\tUp to 18.7 kW\t\t\t\tRs.4.20/kWh\t\t\tRs.350/kw/month\n");
            printf("\nEnter your energy consumption: ");
            scanf("%d", &a);
            line();
            Ec = 4.20;
            Fr = 350;
            if (Billprint(name, id, a, Ec, Fr) == 0)
            {
                return 0;
            }
        }
        case 2:
        {
            printf("Select Supply Voltage\n\n");
            printf("press 1 for 220V supply\n");
            printf("press 2 for 132V supply\n");
            printf("press 3 for 33V  Supply\n");
            printf("\nEnter your choice: ");
            scanf("%d", &b);
            line();
            switch (b)
            {

            case 1:
            {
                printf("\n\tSupply Voltage\t\t\t\tEnergy Charge\t\t\tFixed Charge\n\n");
                printf("\t220V Supply\t\t\t\tRs.5.91kWh\t\t\tRs.350/kw/month\n");
                printf("\nEnter your energy consumption: ");
                scanf("%d", &a);
                line();
                Ec = 5.91;
                Fr = 350;
                if (Billprint(name, id, a, Ec, Fr) == 0)
                {
                    return 0;
                }
            }
            case 2:
            {
                printf("\n\tSupply Voltage\t\t\t\tEnergy Charge\t\t\tFixed Charge\n\n");
                printf("\t132V Supply\t\t\t\tRs.6.01kWh\t\t\tRs.350/kw/month\n");
                printf("\nEnter your energy consumption: ");
                scanf("%d", &a);
                line();
                Ec = 6.01;
                Fr = 350;
                if (Billprint(name, id, a, Ec, Fr) == 0)
                {
                    return 0;
                }
            }
            case 3:
            {
                printf("\n\tSupply Voltage\t\t\t\tEnergy Charge\t\t\tFixed Charge\n\n");
                printf("\t33V\t\t\t\t\tRs.6.36kWh\t\t\tRs.350/kw/month\n");
                printf("\nEnter your energy consumption: ");
                scanf("%d", &a);
                line();
                Ec = 6.36;
                Fr = 350;
                if (Billprint(name, id, a, Ec, Fr) == 0)
                {
                    return 0;
                }
            }

            default:
            {
                line();
                printf("\tError!!!  Wrong key pressed!! Try again!!\n\n");
                return 0;
            }
            break;
            }
        }
        case 3:
        {
            printf("\n\tSupply Voltage\t\t\t\tEnergy Charge\t\t\tFixed Charge\n\n");
            printf("\t50V\t\t\t\t\tRs.5.70kWh\t\t\tRs.375kw/month\n");
            printf("\nEnter your energy consumption: ");
            scanf("%d", &a);
            line();
            Ec = 5.70;
            Fr = 375;
            if (Billprint(name, id, a, Ec, Fr) == 0)
            {
                return 0;
            }
        }

        default:
        {
            line();
            printf("\tError!!!  Wrong key pressed!! Try again!!\n\n");
            return 0;
        }
        }
    }

    default:
    {
        line();
        printf("\tError!!!  Wrong key pressed!! Try again!!\n\n");

        return 0;
    }
    break;
    }

    line();
    printf("\n\tError!!!  Wrong key pressed!! Try again!!\n\n");
    return 0;
}
// BY - Ayush Shete