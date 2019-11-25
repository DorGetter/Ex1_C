 #include <stdio.h>
 #include "myBank.h"
  #include <string.h>         
//Bank data storage;colums=diff acounts;row_0=acount balance;row_1=account status;
           static double BankAccounts[2][50]; 
           
//Point into the next available account free;           
           static int BankNextAvailableSpot=0;
    
	
/*
 * function provides 0- if there is available accounts;
 *                   1- if there no available accounts;
 */
            int openRequestChecker()
            {
                if(BankNextAvailableSpot<=49){return 0;};
                return 1;    
            }
            
           
            
            
/*
 * returns the next available account;
 */
            int NewAccount()
            {
                    return BankNextAvailableSpot;
            }
            
            
            
/*
*clears the scanf stack. 
*/		 
            void clear_buffer()
			{
				char b; 

				while(((b = getchar()) != '\n') && (b != EOF));
			}
            
            
/*
 * function open new Bank account for User;
 * @param ammount- the initual amount of diposet.
 */
            void OpenBankAcount(double ammount)
            {
                
                //The bank account assigned to the user; 
                int newAcountNumber = BankNextAvailableSpot+901;
                    
                //making the transaction;
                double transaction = (int) ammount*100;
				ammount = (transaction/100);
                BankAccounts[0][BankNextAvailableSpot]=(BankAccounts[0][BankNextAvailableSpot]+ammount); 
                
                //updating the account status;
                BankAccounts[1][BankNextAvailableSpot]=1;
                
                double temp= (int)(ammount*100);
				ammount = (double) temp/100;
                printf("Bank Account Successfully Opened\n\tAccount Status:\nAccount Number: %d\nAccount Balance: %.2fl" , newAcountNumber,ammount);
                
                //promote the BankNextAvailableSpot;    
                BankNextAvailableSpot=(BankNextAvailableSpot+1);
        
                return ;
            }

            
            
            
            
            
            
            
/*
 * function show the User the current Balance in the account;
 * @param numberOfaccount- User account number; 
 */
            void BalanceCheck(int numberOfaccount)
            { 
                //check if valid account number;
                if (numberOfaccount<901 || numberOfaccount>950)
                {
                    printf("unvalid Bank account number!\nPlease try again");
                    return ;
                }
                
                
                //check if the account is active;
                if (BankAccounts [1][numberOfaccount-901]==0)//if the account is closed;
                {
                    printf("This account is closed!");
                    return ;
                    
                }
                
                //reading the Balance in the account;
                double Balance = BankAccounts[0][numberOfaccount-901]; 
                    
                printf("Balance status:\naccount number: %d\nCurrent balance is: %.2fl",numberOfaccount,Balance);
                return ;
            }
            
            
            
            
            
            
            
            
/*
 * function for commit a diposet in the account; 
 * param numberOfaccount- User account number;
 */
            void Diposet(int numberOfaccount, double diposet)
                
            {
                //check valid account number;
                if (numberOfaccount<901 || numberOfaccount>950)
                {
                    printf("unvalid Bank account number!\nPlease try again");
                    return ;
                }
                
        
                //check if the account active;
                if (BankAccounts[1][numberOfaccount-901]==0)//if the account is closed;
                {
                    printf("This account is closed!");
                    return ;
                    
                }
				//Unvalid -negative diposet;
                if(diposet<0)
				{
				printf("UnValid ammount for diposet");
				return ;
				}
                
				double temp= (int)(diposet*100);
				diposet = (double) temp/100;
				
                //commit the diposet;
                BankAccounts[0][numberOfaccount-901]=BankAccounts[0][numberOfaccount-901]+diposet;
                
                //reading the Balance in the account;
                double Balance = BankAccounts[0][numberOfaccount-901]; 
                
                printf("Balance status:\naccount number: %d\nCurrent balance is: %.2fl",numberOfaccount,Balance);
                
                return ;               
            }
            
            
            
            
            
            
            
            
            
            
/*
*function for withdraw opperation;
* param numberOfaccount- User account number;
*/  
             void Withdraw(int numberOfaccount, double withDraw )
             {
				//check valid account number;
                if (numberOfaccount<901 || numberOfaccount>950)
                {
                    printf("unvalid Bank account number!\nPlease try again");
                    return ;
                }
                
        
                //check if the account active;
                if (BankAccounts [1][numberOfaccount-901]==0)//if the account is closed;
                {
                    printf("This account is closed!");
                    return ;
                }  
                
                //check if action will cause for overdraft; 
                double Balance = BankAccounts[0][numberOfaccount-901]; 
                double afterWithdraw= Balance-withDraw;
                
                if(afterWithdraw<0)
                {
                    printf("There is not enough money in the account to make a withdrawal");
                    return ; 
                }                 
                
                //Valid money withdrawal; 
                //commit withdraw;
				double temp= (int)(afterWithdraw*100);
				afterWithdraw = (double) temp/100;
				
                BankAccounts[0][(numberOfaccount-901)]=afterWithdraw;
                
                double balance2;
                balance2 = (double) BankAccounts[0][(numberOfaccount-901)]; 
                
                printf("Balance status:\naccount number: %d\nCurrent balance is: %0.2lf",numberOfaccount,balance2);
                
                return ; 
             } 
             
             
             
             
             
             
             
             
             
                   
             
             
/*
*function for close account;
*param numberOfaccount- User account number;  
*/
            
             void Close(int numberOfaccount)
             {
                 //check valid account number;
                if (numberOfaccount<901 || numberOfaccount>950)
                {
                    printf("unvalid Bank account number!\nPlease try again");
                    return ;
                }
                
        
                //check if the account active;
                if (BankAccounts [1][numberOfaccount-901]==0)
                {
                    printf("This account allready closed!");
                    return ;
                }  
                
                //if its active account close it;
                BankAccounts [1][numberOfaccount-901]=0;
                
                printf("\naccount is closed\n");
                return ;
                
             }
             
             
             
             
             
             
             
             
/*
 *function for adding a rate for all the active accounts in the Bank; 
 *@param ratePre- represents interest at a percentage rate;
 */
             void AddRate(double ratePre)
             {
                //Going over all the Bank accounts and update balance by new rate;
                 for(int i=0; i<=49; ++i)
                 {
                    if(BankAccounts[1][i]==1)
                    {
						double current=BankAccounts[0][i]*((ratePre+100.0)/100);
						double temp= (int) current*100;
						current = (double) temp/100;
						
                        BankAccounts[0][i]=current;
                
					}	
                 }
				 PrintStatus();
                 return ;
             }
             
             
             
             
             
             
             
             
             
/*
 * function for Printing the Bank status, 
 * will print all the Open bank accounts numbers and their Balance state;
 */
             void PrintStatus()
             {
                printf("\n\tBank Current Status:\nAccount Num:\t\tBalancec:\n");  
                
                //Going over all the Bank accounts print the accout number and the Balance;
                for(int i=0; i<=49; ++i)
                {
                    if(BankAccounts[1][i]==1)
                    {
                        int account = i+901;
                        printf("%d\t\t\t%.2lf\n",account,BankAccounts[0][i]);
						
                    }
                }
             }
             
             
             
             
             
             
             
             
             
             
/*
 *function for Clear the Bank And Exit the Bank app;
 * initialized all variables back to 0 ; 
 */                 
             int Exit()
             {

                 for(int i=0; i<=49; ++i)
                 {
                     BankAccounts[0][i]=0;
                     BankAccounts[1][i]=0;
                 }
				 
                 return 0; 
             }
               
            


			

