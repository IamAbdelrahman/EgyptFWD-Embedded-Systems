#include "server.h"

ST_accountsDB_t accountsDB[255] = {
    {2000.0, RUNNING, "8989374615436851"},
    {100000.0, BLOCKED, "5807007076043875"},
    {1000.0, RUNNING, "5807007076643875"},
    {4000.0, BLOCKED, "5807007076046851"},
    {80000.0, RUNNING, "1234374615436851"},
};

ST_transaction  transactionsDB [255] = {0};

int sequenceNumber = 0 ;
void increment (int*);

void increment (int *Ptr)
{
    ++*Ptr;
}


size_t linearSearch(ST_accountsDB_t array[], char* key, size_t size)
{   
    for (size_t n = 0; n < size; ++n) 
    {   
        if (strcmp( (char*) accountsDB[n].primaryAccountNumber,key )==0)
            return n;  
    }

    return -1;
} 


EN_transState_t receiveTransactionData(ST_transaction *transData)
{   
    // Search for the PAN into the accounts database

    int index =  linearSearch (accountsDB,
    (char*)transData->cardHolderData.primaryAccountNumber, 5);

    if (-1 == linearSearch (accountsDB,
    (char*)transData->cardHolderData.primaryAccountNumber, 5))    
        return FRAUD_CARD; //3  doesn't exist

    else if (transData->terminalData.transAmount > accountsDB[index].balance)
        return DECLINED_INSUFFICIENT_FUND; //1
    
    else if (accountsDB[index].state == BLOCKED)
        return DECLINED_STOLEN_CARD; //2

    else if (index > 255)   
        return INTERNAL_SERVER_ERROR;

    else    return APPROVED; //0  
}

EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountReference)
{
    int index =  linearSearch (accountsDB,
    (char*)cardData->primaryAccountNumber, 5);

    if (-1 == linearSearch (accountsDB,
    (char*)cardData->primaryAccountNumber, 5))
    {   
        strcpy( (char*) accountReference->primaryAccountNumber, "");
        return ACCOUNT_NOT_FOUND;

    }   
    
    else
    {
        strcpy( (char*) accountReference->primaryAccountNumber,
        (char*) accountsDB[index].primaryAccountNumber);
            return SERVER_OK;
    }    
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountReference)
{   
   for (int i = 0; i < 5; ++i)
   {
        if (strcmp ((char*)accountsDB[i].primaryAccountNumber,
        (char*)accountReference->primaryAccountNumber) == 0)
        {
            if (accountsDB[i].state == BLOCKED)
                return BLOCKED_ACCOUNT;
            else
                return SERVER_OK;
        }
    }
    return ACCOUNT_NOT_FOUND;

}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountReference)
{
   for (int i = 0; i < 5; ++i)
   {
        if (strcmp ((char*)accountsDB[i].primaryAccountNumber,
        (char*)accountReference->primaryAccountNumber) == 0)
        {
            if (accountsDB[i].balance < termData->transAmount)
                return LOW_BALANCE;
            else
                return SERVER_OK;
        }       
    } 
    return ACCOUNT_NOT_FOUND;
}

EN_serverError_t saveTransaction(ST_transaction *transData)
{   
    increment(&sequenceNumber);

    strcpy((char*)transData->cardHolderData.cardExpirationDate,"05/23");
    strcpy((char*)transData->cardHolderData.cardHolderName, "AbdelrahmanMohamedKamal");
    transData->terminalData.transAmount = 1000.00;
    strcpy((char*)transData->terminalData.transactionDate, "01/03/2022");
        strcpy((char*)transData->cardHolderData.primaryAccountNumber, "8989374615436851");
    transData->terminalData.maxTransAmount = 8000.00;
    transData->transactionSequenceNumber = sequenceNumber;
    transData->transState = APPROVED;
    
    strcpy((char*)transactionsDB[0].cardHolderData.cardExpirationDate,"05/23");
    strcpy((char*)transactionsDB[0].cardHolderData.primaryAccountNumber, "8989374615436851");
    transactionsDB[0].terminalData.transAmount = 1000.00;
    strcpy((char*)transactionsDB[0].terminalData.transactionDate, "01/03/2022");
    transactionsDB[0].terminalData.maxTransAmount = 8000.00;
    strcpy((char*)transactionsDB[0].cardHolderData.cardHolderName, "AbdelrahmanMohamedKamal");
    transactionsDB[0].transactionSequenceNumber = sequenceNumber;
    transactionsDB[0].transState = APPROVED;

    return SERVER_OK;
}

void listSavedTransactions(void)
{
    printf("Transaction Sequence: %u\n",transactionsDB[0].transactionSequenceNumber);
    printf("Transaction Date: %s\n", transactionsDB[0].terminalData.transactionDate);
    printf("Transaction Amount: %f\n", transactionsDB[0].terminalData.transAmount);
    printf("Transaction State: %d\n", transactionsDB[0].transState);
    printf("Terminal Max Amount: %f\n", transactionsDB[0].terminalData.maxTransAmount);
    printf("CardHolder Name: %s\n", transactionsDB[0].cardHolderData.cardHolderName);
    printf("PAN: %s\n", transactionsDB[0].cardHolderData.primaryAccountNumber);
    printf("Card expiration date: %s\n", transactionsDB[0].cardHolderData.cardExpirationDate);
}
