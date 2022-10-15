#include <stdio.h>
#include <string.h>
#include "app.h"


int main(void)
{
    appStart();
    return 0;
}

void appStart (void)
{   
    ST_cardData_t user;
    ST_terminalData_t atm;
    ST_accountsDB_t account;

    getCardHolderName(&user);
    getCardPAN(&user);
    getCardExpiryDate(&user);
    getTransactionDate (&atm);

    if( 2 == isCardExpired(user, &atm))
    {
        printf("Declined Expired Card\n");
        return;
    }

    else
    {
        getTransactionAmount(&atm);
        setMaxAmount(&atm);

        if ( 5 == isBelowMaxAmount(&atm))
        {
            printf("Declined Amount Exceeding Limit\n");
            return;
        }

        else
        {
           if ( 3 == isValidAccount(&user, &account))
               {
                printf("Declined Invalid Account\n");
                return;

               } 
            else
                {
                    if ( 5 == isBlockedAccount(&account))
                    {
                        printf("Declined Stolen Card\n");
                        return;
                    }
                
            else
                {
                if( 4 == isAmountAvailable(&atm, &account))
                {  

                    printf("Declined Insufficient Fund\n");
                    return;
                }

                else
                {
                    account.balance = atm.transAmount - account.balance;
                    ST_transaction allData = {user, atm, APPROVED, (uint8_t)sequenceNumber};
                    saveTransaction(&allData);

                    printf("Please, remove your card and wait for your money\n");
                    return;
                }
            }    
        }
    }
    }
}
