#include <stdio.h>
void file_handling( float balance, float rate, int fd_year , float fd_amount , float interest , float total_interest , int bank_name);


int main(){
    int bank ,fd_period ,fd_year ,bank_name;
    char answer3 ;
    float balance ,fd_amount ,interest_rate ,interest ,total_interest;

    printf("\tEnter Your Remaining Balance : Rs ");
    scanf("%f",&balance);
    printf("\n\tDo you want any Financial Investment advice for your Remaining Balance..? (Y/N)  ");
    scanf("%s",&answer3);



    if(answer3=='n' || answer3=='N')
        {
        printf("\n\t\t\t\t\t--*|\t THANK YOU.!\t|*--\n");
        }
    else if(answer3=='y' || answer3=='Y')
    { if(balance>=5000){ //if the balance<5000 we can't open a FD.
         LOOP:
        while(1){
        printf("\n\t\t\t\t\tPlease select a Bank for Transactions. \n");
        printf("\n\t\t\t\t\t|\tPeople's Bank - 1\t|\n");
        printf("\t\t\t\t\t|\tBank of Ceylon - 2\t|\n");
        printf("\n\t\t\tEnter Bank Code : ");
        scanf("%d",&bank);
            if(bank>2 || bank<1){
              printf("\n\t\t\t\t* Invalid input. Please enter 1 or 2. *\n");
              continue;
            }
            switch(bank){
                case 1: //People's Bank
                    bank_name=1;
                    printf("\t\t\t\t\t\tPEOPLE'S BANK\n");
                    while(1){
                        printf("\n\tYour Remaining Balance is %.2f\n",balance);
                        printf("\tPlease enter the amount you wish to deposit (Minimum deposit Rs. 5,000/-) : Rs. ");
                        scanf("%f",&fd_amount);
                        if(fd_amount>balance || fd_amount<5000){
                            printf("\n\t* Please enter amount between Rs. 5000.00 /- and Rs. %.2f /- *\n",balance);
                           continue;}
                        while(1){
                            printf("\n\t\t\t\t\tPlease select the deposit period \n");
                            printf("\n\t\t\t\t\t|\t01 year deposit - 1\t|\n");
                            printf("\t\t\t\t\t|\t02 year deposit - 2\t|\n");
                            printf("\t\t\t\t\t|\t05 year deposit - 3\t|\n");
                            printf("\n\t\t\tEnter Deposit Code : ");
                            scanf("%d",&fd_period);
                                if(fd_period>3 || fd_period<1){
                                    printf("\n\t\t\t\t* Invalid input. *");
                                continue;}
                                    switch(fd_period){
                                    case 1:
                                        printf("\n\t\tInterest rate is \t= 8.00 %% \n");
                                        interest_rate=8.00/100;
                                        fd_year=1;
                                        break;
                                    case 2:
                                        printf("\n\t\tInterest rate is \t= 9.00 %% \n");
                                        interest_rate=9.00/100;
                                        fd_year=2;
                                        break;
                                    case 3:
                                        printf("\n\t\tInterest rate is \t= 10.50 %% \n");
                                        interest_rate=10.50/100;
                                        fd_year=5;
                                        break;
                                    }
                        break;}

                    break;}

                    break;

                case 2:
                    if(balance>=10000){ //if the balance < 10000 we can't open FD in BOC.
                    printf("\t\t\t\t\t\tBANK OF CEYLON\n"); //Bank of Ceylon.
                    bank_name=2;
                    while(1){
                        printf("\n\tYour Remaining Balance is %.2f /-\n",balance);
                        printf("\tPlease enter the amount you wish to deposit (Minimum deposit Rs. 10,000/-) : Rs. ");
                        scanf("%f",&fd_amount);
                        if(fd_amount>balance || fd_amount<10000){
                            printf("\n\t* Please enter amount between Rs. 10000.00 /- and Rs. %.2f/- *\n",balance);
                           continue;}
                        while(1){
                            printf("\n\t\t\t\t\tPlease select the deposit period \n");
                            printf("\n\t\t\t\t\t|\t01 year deposit - 1\t|\n");
                            printf("\t\t\t\t\t|\t02 year deposit - 2\t|\n");
                            printf("\t\t\t\t\t|\t05 year deposit - 3\t|\n");
                            printf("\n\t\t\tEnter Deposit Code : ");
                            scanf("%d",&fd_period);
                                if(fd_period>3 || fd_period<1){
                                    printf("\n\t\t\t\t* Invalid input. *");
                                continue;}
                                    switch(fd_period){
                                    case 1:
                                        printf("\n\t\tInterest rate is \t= 8.00 %% \n");
                                        interest_rate=8.00/100;
                                        fd_year=1;
                                        break;
                                    case 2:
                                        printf("\n\t\tInterest rate is \t= 8.50 %% \n");
                                        interest_rate=8.50/100;
                                        fd_year=2;
                                        break;
                                    case 3:
                                        printf("\n\t\tInterest rate is \t= 9.50 %% \n");
                                        interest_rate=9.50/100;
                                        fd_year=5;
                                        break;
                                    }
                        break;}

                    break;}
                    break;
                    }else
                    printf("\n\t\t** You don't have enough balance to go for a INVESTMENT PLAN in BOC Bank. **\n"); goto LOOP;
                }

        break; }

    interest=fd_amount*interest_rate;
    printf("\t\tThe Annual Interest you get for a deposit of Rs. %.2f /- is \t= Rs. %.2f /-\n",fd_amount ,interest);
        total_interest=fd_year*interest;
    printf("\t\tTotal Interest after %d year/years \t\t\t\t\t= Rs. %.2f /-\n\n",fd_year ,total_interest);
    printf("\n\t\t\t\t\t----*|\t  THANK YOU.!\t|*----\n\n");

    }
     else {
    printf("\n\t\t** You don't have enough balance to go for a INVESTMENT PLAN. **\n");
    printf("\n\t\t\t\t----*|\t  THANK YOU.!\t|*----\n\n");
    }}

    file_handling(balance, interest_rate, fd_year , fd_amount , interest , total_interest , bank_name);
return 0;
}

void file_handling( float balance, float rate, int fd_year , float fd_amount , float interest , float total_interest , int bank_name){
    FILE *fp;
    fp=fopen("InvestmentPlan.txt","w");
    switch(bank_name){
    case 1:
        fprintf(fp,"\t\t\t\t\t\t\tPeople's Bank\n\n");
        break;
    case 2:
        fprintf(fp,"\t\t\t\t\t\t\tBank of Ceylon\n\n");
        break;
    }


    fprintf(fp,"\t\tYour Remaining Balance              \t\t\t\t\t= Rs. %.2f /-\n",balance);
    fprintf(fp,"\t\tInterest Rate according to your plan\t\t\t\t\t= %.2f \n",rate);
    fprintf(fp,"\t\tThe Annual Interest you get for a deposit of Rs. %.2f /- is \t= Rs. %.2f /-\n",fd_amount ,interest);
    fprintf(fp,"\t\tTotal Interest after %d year/years \t\t\t\t\t= Rs. %.2f /-\n",fd_year ,total_interest);
    fprintf(fp,"\n\t\t\t\t\t\t----*|\t  THANK YOU.!\t|*----\n\n");
    fclose(fp);
}
