    #include <stdio.h>
	#include <string.h>
    #include "myBank.c"
    #include "myBank.h"



  

    int main ()
    {
	// as long as exitFlag on Stay in Bank; 
    int exitFlag = 1; 
    printf("Welcome to the Bank");
    // will hold the input as a string;
    char choice[100];
	
    
    while(exitFlag){
    
	
	char Valid_choice;
    printf("\n\n"
            "\nFor open a new account press:\n'O'"
            "\nFor checking account Balance press:\n'B'"
            "\nFor Deposit money press\n'D'"
            "\nFor withdraw money press\n'W'"
            "\nFor close an existing account press\n'C'"
            "\nFor adding interest rate press\n'I'"
            "\nFor print the Bank accounts status press\n'P'"
            "\nFor close all the accounts in the Bank and exit press\n'E'"
            "\n");
			
    //check if user is Enters only a valid input;
    scanf("%s",choice);
	if(strlen(choice) != 1)
	{
		choice[0] = '\0';
		Valid_choice='U';
	}			
	else
	{
		Valid_choice=choice[0];
	}
	
	clear_buffer();  
    switch(Valid_choice)
    {
        //Open Account:
        case 'O': ;
		
		
            //check if there is space for new account ; 
            if(openRequestChecker()) 
            {
                printf("Sorry there are no Acconts availble at the moment\n"); 
                break;
            }
			
             //open the account;
            double ammount=0; 
            printf("\nIn Order to create youre new account\nPlease commit a initial diposet: \n");
			
			scanf("%lf",&ammount);
			
			printf("%f", ammount);
            OpenBankAcount(ammount); 
         
            break;
        
        //Check Account Balance
        case 'B': ;
            int numberOfAccount1=0;
            printf("\nPlease enter youre Bank account number\n");
            scanf("%d",&numberOfAccount1);
            BalanceCheck(numberOfAccount1); 
            break;
        
        //Diposet    
        case 'D': ;
            int numberOfAccount2=0;
			double diposet=0;
			
            printf("\nPlease enter youre Bank account number\n");
            scanf("%d",&numberOfAccount2);
			
			printf("Please youre diposet");
            scanf("%lf",&diposet);

            Diposet(numberOfAccount2,diposet);
            break;    
            
        //Withdraw    
        case 'W': ;
            int numberOfAccount3=0;
			double withDraw=0.0;
			
            printf("\nPlease enter youre Bank account number\n");
            scanf("%d",&numberOfAccount3);
		    
			printf("Enter withdraw ammount:");
			scanf("%lf",&withDraw);
			
            Withdraw(numberOfAccount3,withDraw);
            break;    
       
        //close account  
        case 'C': ;
            int numberOfAccount4=0;
            printf("\nPlease enter youre Bank account number\n");
            scanf("%d",&numberOfAccount4);
            Close(numberOfAccount4);
            break;    
         
        //add interest_rate    
        case 'I': ;   
            double Newrate;
            printf("\nEnter the new interest rate\n");
            scanf("%lf",&Newrate);
            AddRate(Newrate);
            break; 
            
        //Show all acount status       
        case 'P':        
            PrintStatus(); 
            break;
            
        //close all accounts and Exit the Bank app; 
        case 'E': 
            exitFlag=0;
			Exit();
            break; 
                
        default:
				printf("\nUnvalid input- please make sure the following:\n1. Capital letter;\n2. inpt contain only the letter of the wish  operation.\n");
				
            break;
        
    }   
        
    }
		
		return 0;
    }
