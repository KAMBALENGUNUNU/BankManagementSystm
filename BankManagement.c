#include<stdio.h>

struct Bank{

    char DateOfcreation[20];
    int AccountNumber;
    char Name[20];
    char DateOfBirth[20];
    int Age;
    char Address[50];
    int CitizenshipNumber;
    char PhoneNumber[15];
    int AmountDeposit;
    char TypeOfAccount[20];

}bk;

void main()
{
    int pass = 0;
    system("COLOR 06");
    printf("\n\n\t\t\xB2\xB2\xB2\ WELCOME TO THE BANK MANAGEMENT SYSTEM \xB2\xB2\xB2");
    printf("\n\t\t   ---------------------------------------");

    do{

        printf("\n\n\t\t\tEnter the password to login:");
        scanf("%d",&pass);
        switch(pass)
        {
        case 1234:
            choices();
            break;
        default:
            printf("\n\t\t\t\Wrong password, Try again....\n");
        }

    }while(pass != 1234);
}

void choices()
{
   int choice_case;
   choice_case = 0;
   do{
       printf("\n\n\t\t--> A. Press 1 to create an account");
       printf("\n\t\t--> B. Press 2 to update informations");
       printf("\n\t\t--> C. Press 3 for transactions");
       printf("\n\t\t--> D. Press 4 to search an account");
       printf("\n\t\t--> E. Press 5 to delete an account");
       printf("\n\t\t--> F. Press 6 to display all accounts");
       printf("\n\t\t--> G. Press 0 to exit");
       printf("\n\n\t\tChoices :");

       scanf("%d",&choice_case);
       switch(choice_case)
       {
            case 1:
                CreateAccount();
                break;
            case 2:
                UpdateAccount();
                break;
            case 3:
                Transactions();
                break;
            case 4:
                SearchAnAccount();
                break;
            case 5:
                DeleteAccount();
                break;
            case 6:
                DisplayAccount();
                break;
            case 0:
                printf("\nThank you for using our system, good bye!");
                break;
            default:
                printf("\n Invalid choice!");
        }

    }while(choice_case !=0);
}

void CreateAccount()
{
    printf("\n\n\t\t\xB2\xB2\xB2\ CREATE AN ACCOUNT \xB2\xB2\xB2");
    printf("\n\t\t   ---------------------------------");

    FILE *p;
    p = fopen("Bank.txt","a");

    printf("\nEnter the creation date(dd/mm/yyyy)::");
    scanf("%s",bk.DateOfcreation);

    printf("\nEnter the account number:: ");
    scanf("%d",&bk.AccountNumber);

    printf("\nEnter your name:: ");
    scanf("%s",bk.Name);

    printf("\nEnter the date of Birth(dd/mm/yyyy)::");
    scanf("%s",bk.DateOfBirth);

    printf("\nEnter your age ::");
    scanf("%d",&bk.Age);

    printf("\nEnter your address ::");
    scanf("%s",bk.Address);

     printf("\nEnter your citizenship number::");
     scanf("%d",&bk.CitizenshipNumber);

    printf("\nEnter your Phone number:: ");
    scanf("%s",bk.PhoneNumber);

     printf("\nEnter the deposit amount $::");
    scanf("%d",&bk.AmountDeposit);

    printf("\nEnter The type of account:: ");

    printf("\nPress 1 to create a current account:");
    printf("\nPress 2 to create a saving account:");
    printf("\nPress 3 to create a salary account:\n");
    printf("\n\n\t\tChoices :");
    scanf("%s",bk.TypeOfAccount);

    fprintf(p,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,bk.AccountNumber,bk.Name,bk.DateOfBirth,bk.Age,
             bk.Address,bk.CitizenshipNumber,bk.PhoneNumber,bk.AmountDeposit,bk.TypeOfAccount);
     printf("\nAccount created successfully!");
     fclose(p);
}
void UpdateAccount()
{
        FILE *p,*t;

    // We open the first file by using the Reading mode and the second one by using the Append mode
       p  = fopen ("Bank.txt","r");
       t  = fopen("newFile.txt","w");

       int account;
       int temp;

       temp =0;

    // We display the title

       printf("\n\n\t\t\xB2\xB2\xB2\ UPDATE INFORMATION \xB2\xB2\xB2");
       printf("\n\t\t   ----------------------------------");

       printf("\nEnter the account number:");
       scanf("%d",&account);

     // We create our While () loop function for updating employee�s details

     while(fscanf(p,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,&bk.AccountNumber,bk.Name,bk.DateOfBirth,&bk.Age,
                 bk.Address,&bk.CitizenshipNumber,bk.PhoneNumber,&bk.AmountDeposit,bk.TypeOfAccount)!=EOF){

             if(bk.AccountNumber ==account){
                    temp=temp+1;

                    printf("\nModify the name: ");
                    scanf("%s",bk.Name);

                    printf("\nModify the date of Birth(dd/mm/yyyy): ");
                    scanf("%s",bk.DateOfBirth);

                    printf("\nModify the age: ");
                    scanf("%d",&bk.Age);

                    printf("\nModify the address:");
                    scanf("%s",bk.Address);

                    printf("\nModify the Phone number: ");
                    scanf("%s",bk.PhoneNumber);

                  // We save all updated details in a new file
                  fprintf(t,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,bk.AccountNumber,bk.Name,bk.DateOfBirth,bk.Age,
                          bk.Address,bk.CitizenshipNumber,bk.PhoneNumber,bk.AmountDeposit,bk.TypeOfAccount);

             }
             else{
                // We save previous employee�s details in a new file
                fprintf(t,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,bk.AccountNumber,bk.Name,bk.DateOfBirth,bk.Age,
                          bk.Address,bk.CitizenshipNumber,bk.PhoneNumber,bk.AmountDeposit,bk.TypeOfAccount);
             }

         }
       // We test in order to make sure that the file exists or not
       if (temp ==0){
            printf("This file doesn�t Exist");
       }
      fclose(p);
      fclose(t);

      // We remove the former file and we remain with the new one and we rename it.
      remove("Bank.txt");
      rename("newFile.txt","Bank.txt");

}
void Transactions()
{
   int choice_case;
   choice_case = 0;
   do{
        printf("\n\n\t\t--> A. Press 1 to depose :");
       printf("\n\t\t--> B. Press 2 to withdraw:");
       printf("\n\t\t--> C. Press 3 to transfer:");
       printf("\n\t\t--> D. Press 0 to exit");
       printf("\n\nChoices :");

       scanf("%d",&choice_case);
       switch(choice_case)
       {
            case 1:
                DepositFunction();
                break;
            case 2:
                WithdrawalFunction();
                break;
            case 3:
                TansferFunction();
                break;
            default :
                printf("\nThanks for doing transaction with us!!");
        }
       } while(choice_case !=0);
}

void TansferFunction(){

      FILE *p,*t;

       p  = fopen ("Bank.txt","r");
       t  = fopen("newFile.txt","w");

       int flag = 1;

    int amount,senderNo,receiverNo,temp1,temp2;
    temp1 = 0;

    printf("\nEnter the account no. of the sender: ");
    scanf("%d", &senderNo);

    while(!feof(p)){

        fscanf(p,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,&bk.AccountNumber,bk.Name,bk.DateOfBirth,&bk.Age,
             bk.Address,&bk.CitizenshipNumber,bk.PhoneNumber,&bk.AmountDeposit,bk.TypeOfAccount);

        if(senderNo == bk.AccountNumber){


             printf("\nEnter the account.no of the receiver:");
             scanf("%d", &receiverNo);

             do{
                printf("\nEnter the amount to transfer $:");
                scanf("%d",&amount);
            }
            while(amount > bk.AmountDeposit);

              bk.AmountDeposit = bk.AmountDeposit-amount;
            printf("\n\t\t%s has transfered %d. The new balance is %d ",bk.Name,amount,bk.AmountDeposit);

              // We save all updated details in a new file
              fprintf(t,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,bk.AccountNumber,bk.Name,bk.DateOfBirth,bk.Age,
                      bk.Address,bk.CitizenshipNumber,bk.PhoneNumber,bk.AmountDeposit,bk.TypeOfAccount);
              flag = 0;


          }
        else{

            fprintf(t,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,bk.AccountNumber,bk.Name,bk.DateOfBirth,bk.Age,
                              bk.Address,bk.CitizenshipNumber,bk.PhoneNumber,bk.AmountDeposit,bk.TypeOfAccount);
        }
    }

    fclose(p);
    fclose(t);

    // We remove the former file and we remain with the new one and we rename it.
    remove("Bank.txt");
    rename("newFile.txt","Bank.txt");

    p  = fopen ("Bank.txt","r");
    t  = fopen("newFile.txt","w");

    if(flag ==0){
         while(!feof(p)){
             fscanf(p,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,&bk.AccountNumber,bk.Name,bk.DateOfBirth,&bk.Age,
                 bk.Address,&bk.CitizenshipNumber,bk.PhoneNumber,&bk.AmountDeposit,bk.TypeOfAccount);

             if(receiverNo == bk.AccountNumber){


              bk.AmountDeposit = bk.AmountDeposit+amount;
              printf("\n\t\t%s has received %d. The new balance is %d ",bk.Name,amount,bk.AmountDeposit);
              // We save all updated details in a new file
              fprintf(t,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,bk.AccountNumber,bk.Name,bk.DateOfBirth,bk.Age,
                      bk.Address,bk.CitizenshipNumber,bk.PhoneNumber,bk.AmountDeposit,bk.TypeOfAccount);


            }
            else{

                fprintf(t,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,bk.AccountNumber,bk.Name,bk.DateOfBirth,bk.Age,
                      bk.Address,bk.CitizenshipNumber,bk.PhoneNumber,bk.AmountDeposit,bk.TypeOfAccount);
            }

        }
    }

    fclose(p);
    fclose(t);

    // We remove the former file and we remain with the new one and we rename it.
    remove("Bank.txt");
    rename("newFile.txt","Bank.txt");
    printf("\n\n\t\tTransaction successful! Thank you for using our platform");

}


void WithdrawalFunction(){
    FILE *p,*t;

    // We open the first file by using the Reading mode and the second one by using the Append mode
       p  = fopen ("Bank.txt","r");
       t  = fopen("newFile.txt","w");

       int account;
       int temp;

       temp =0;

       printf("\nEnter an account number:");
       scanf("%d",&account);


     // We create our While () loop function for updating employee�s details

     while(fscanf(p,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,&bk.AccountNumber,bk.Name,bk.DateOfBirth,&bk.Age,
                 bk.Address,&bk.CitizenshipNumber,bk.PhoneNumber,&bk.AmountDeposit,bk.TypeOfAccount)!=EOF){

             if(bk.AccountNumber ==account){
                    temp=temp+1;
                    int amount = 0;
                    do{
                        printf("\nEnter the withdrawal amount $:");
                        scanf("%d",&amount);
                    }while(amount<=0 || amount>bk.AmountDeposit);

                    bk.AmountDeposit = bk.AmountDeposit-amount;
                  // We save all updated details in a new file
                  fprintf(t,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,bk.AccountNumber,bk.Name,bk.DateOfBirth,bk.Age,
                          bk.Address,bk.CitizenshipNumber,bk.PhoneNumber,bk.AmountDeposit,bk.TypeOfAccount);

             }
             else{
                // We save previous employee�s details in a new file
                fprintf(t,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,bk.AccountNumber,bk.Name,bk.DateOfBirth,bk.Age,
                          bk.Address,bk.CitizenshipNumber,bk.PhoneNumber,bk.AmountDeposit,bk.TypeOfAccount);
             }

         }
       // We test in order to make sure that the file exists or not
       if (temp ==0){
            printf("This account does not exist");
       }
      fclose(p);
      fclose(t);

      // We remove the former file and we remain with the new one and we rename it.
      remove("Bank.txt");
      rename("newFile.txt","Bank.txt");
      printf("Withdrawal successful!");
}
void DepositFunction()
{
    FILE *p,*t;

    // We open the first file by using the Reading mode and the second one by using the Append mode
       p  = fopen ("Bank.txt","r");
       t  = fopen("newFile.txt","w");

       int account;
       int temp;

       temp =0;


       printf("\nEnter an account number:");
       scanf("%d",&account);

     // We create our While () loop function for updating employee�s details

     while(fscanf(p,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\nn",bk.DateOfcreation,&bk.AccountNumber,bk.Name,bk.DateOfBirth,&bk.Age,
                 bk.Address,&bk.CitizenshipNumber,bk.PhoneNumber,&bk.AmountDeposit,bk.TypeOfAccount)!=EOF){

             if(bk.AccountNumber ==account){
                    temp=temp+1;

                    int amount = 0;
                    do{
                        printf("\nEnter the deposit amount $:");
                        scanf("%d",&amount);
                    }while(amount<=0);
                    //withdrawalTransaction(withdrawal);
                    bk.AmountDeposit = bk.AmountDeposit+amount;
                  // We save all updated details in a new file
                  fprintf(t,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,bk.AccountNumber,bk.Name,bk.DateOfBirth,bk.Age,
                          bk.Address,bk.CitizenshipNumber,bk.PhoneNumber,bk.AmountDeposit,bk.TypeOfAccount);

             }
             else{
                // We save previous employee�s details in a new file
                fprintf(t,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,bk.AccountNumber,bk.Name,bk.DateOfBirth,bk.Age,
                          bk.Address,bk.CitizenshipNumber,bk.PhoneNumber,bk.AmountDeposit,bk.TypeOfAccount);
             }

         }
       // We test in order to make sure that the file exists or not
       if (temp ==0){
            printf("This account does not exist");
       }
      fclose(p);
      fclose(t);

      // We remove the former file and we remain with the new one and we rename it.
      remove("Bank.txt");
      rename("newFile.txt","Bank.txt");
      printf("Deposit successful!");

}
void SearchAnAccount()
{

    FILE *p;
    p = fopen("Bank.txt","r");
    printf("\n\n\t\t\xB2\xB2\xB2\ SEARCH AN ACCOUNT \xB2\xB2\xB2");
    printf("\n\t\t   -------------------------");
    int account ;

    int temp = 0;
    printf("\nEnter an account number:");
    scanf("%d",&account);

    printf("\nACCOUNT.NO\tDATEOFCREATION\tNAME\tADDRESS\tPHONE\t\tBALANCE\n");
    while(!feof(p)){
            //fread(&bk,sizeof(struct Bank),1,p);
             fscanf(p,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,&bk.AccountNumber,bk.Name,bk.DateOfBirth,&bk.Age,
                 bk.Address,&bk.CitizenshipNumber,bk.PhoneNumber,&bk.AmountDeposit,bk.TypeOfAccount);

            if(account == bk.AccountNumber){
                 temp = 1;
                 printf("%d\t\t%s\t%s\t%s\t%s\t%d\n",bk.AccountNumber,bk.DateOfcreation,bk.Name,
                 bk.Address,bk.PhoneNumber,bk.AmountDeposit);
            }
    }
    if(!temp){
          printf("\nAccount not found! ");
    }

 fclose(p);
}
void DeleteAccount()
{
   FILE *p,*t;

   p  = fopen ("Bank.txt","r");
   t  = fopen("newFile.txt","w");

   int account;
   int temp;

   temp =0;

    // We display the title

       printf("\n\n\t\t\xB2\xB2\xB2\ DELETE AN ACCOUNT \xB2\xB2\xB2");
       printf("\n\t\t   -----------------------");

       printf("\nEnter an account number to delete:");
       scanf("%d",&account);


     // We create our While()loop function for updating Bank details

     while(fscanf(p,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,&bk.AccountNumber,bk.Name,bk.DateOfBirth,&bk.Age,
                 bk.Address,&bk.CitizenshipNumber,bk.PhoneNumber,&bk.AmountDeposit,bk.TypeOfAccount)!=EOF){

         if(bk.AccountNumber == account){
                temp = 1;
         }
         else{
            // We save all updated details in a new file
            fprintf(t,"%s\t\t%d\t\t%s\t%s\t%d\t%s\t%d\t\t%s\t%d\t%s\n",bk.DateOfcreation,bk.AccountNumber,bk.Name,bk.DateOfBirth,bk.Age,
                  bk.Address,bk.CitizenshipNumber,bk.PhoneNumber,bk.AmountDeposit,bk.TypeOfAccount);
        }
    }
      fclose(p);
      fclose(t);
      if(temp){
        remove("Bank.txt");
        rename("newFile.txt","Bank.txt");
        printf("\nRecord deleted!");
      }

      // We remove the former file and we remain with the new one and we rename it.

}
void DisplayAccount()
{
    FILE *p;
    p =fopen("Bank.txt","r");
    printf("\n\n\t\t\xB2\xB2\xB2\ DISPLAY RESULTS \xB2\xB2\xB2");
    printf("\n\t\t   -------------------\n");

    printf("\nACC. NO\t\t NAME\t\t ADDRESS\t\t PHONE\t\t\t BALANCE\n");
    if(p == NULL){
        printf("\nThis file is empty");

    }

    
    fclose(p);
                        }


