#include "terminal.h"

int getLen_t (uint8_t arr_name[])
{
    int count = 0;
    for (int i = 0; i < 100; ++i)
    {
        if (arr_name[i])    count++;
        else    break;
    }
    return count;
}

int RightFormat_t(unsigned char arr_date[])
{
    int check_t = 1;
    for (int i = 0; i < 11; ++i)
    {
        // Digits of days
        if( ('0' <= arr_date[0] && arr_date[0] <= '3') &&
        ('1' <= arr_date[1] && arr_date[1] <= '9') );

        else    check_t = 0;

        // Digits of months
        if ( (arr_date[3] >= '0' && arr_date[3] <= '3') &&
        ('1' <= arr_date[4] && arr_date[4] <= '9') );

        else check_t = 0;

        if (arr_date[2] == '/' && arr_date[5] == '/') ;
        else    check_t = 0;

        // Digits of years (assumed from 2000 : 2022)
        if ( ('2' == arr_date[6]) && (arr_date[7] == '0' ) &&
        (('0' <= arr_date[8]) && (arr_date[8] <= '2'))&&
        (('0' <= arr_date[9]) && (arr_date[9] <= '9')) );

        else    check_t = 0;
    }

    return check_t;
}

int CheckExpired (ST_cardData_t *arr_date1, ST_terminalData_t* arr_date2)
{ 
    /* Comparison depends on the format of
    the 1st date (expiration date) mm/yy, noting that
    the yy means the last two digits of the year
    */

    uint8_t yearofexpiry [3], yearoftrans [3];
    uint8_t monthofexpiry [3], monthoftrans [3];

    for (int i = 0; i < 6; ++i)
    {
        if (i == 2) continue;   // ignore the 1st /.

        else if (i == 0 || i == 1)
            monthofexpiry [i] = arr_date1->cardExpirationDate[i];
            
        else if (i == 3 || i == 4)
            yearofexpiry [i - 3] = arr_date1->cardExpirationDate[i];
    }
    
    for (int j = 3; j < 11; ++j)
        {
            if (j == 5 || j == 6 || j == 7)   continue; // ignore the 2nd / and 
            // first two digits of the year.
            
            else if (j == 3 || j == 4)
                    monthoftrans [j - 3] = arr_date2->transactionDate[j];  

            else if (j == 8 || j == 9)  
                    yearoftrans [j - 8] = arr_date2->transactionDate[j];
        }
    

    if (strcmp( (char*) yearoftrans,(char*) yearofexpiry) > 0)  // expiry date is before trans date.
        return 1;   // expired
    
    else if ( strcmp((char*) yearoftrans,(char*) yearofexpiry) == 0)
    {
        if ( strcmp((char*) monthoftrans,(char*) monthofexpiry) > 0)
            return 1;

        else    
            return 0;
    }

    else return 0; 
}

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
    int getLen_t (uint8_t arr_name[]) ; // To get the length of t_date
    int RightFormat_t(unsigned char arr_date[]); // To check the format

    // Ask user to enter his transaction date
    printf("Please, enter your transcation date in (DD/MM/YY):");
    scanf("%[^\n]", termData->transactionDate); // Get the transaction date
    getc(stdin);    // To clean the buffer

    int length = getLen_t(termData->transactionDate);

    if (length == 0 || length < 10)
        return WRONG_DATE;

    else if (!RightFormat_t(termData->transactionDate)) // if not right format
        return WRONG_DATE; // 1

    else    
        return TERMINAL_OK; // 0

}

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t *termData)
{   
    int CheckExpired (ST_cardData_t *, ST_terminalData_t *);
    int check = CheckExpired(&cardData, termData);

    if (check)
        return EXPIRED_CARD;

    else    
        return TERMINAL_OK;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    printf("Input Data(TransactionAmount):");
    scanf("%f", &termData->transAmount);
    getc(stdin);

    if (termData->transAmount <= 0.0)
        return INVALID_AMOUNT;

    else    
        return TERMINAL_OK;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{
    printf("Input Data(MaxAmount):");
    scanf("%f", &termData->maxTransAmount);

    if (termData->maxTransAmount <= 0.0)
        return INVALID_MAX_AMOUNT;

    else    
        return TERMINAL_OK;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    if (termData->transAmount > termData->maxTransAmount)
        return EXCEED_MAX_AMOUNT;
    
    else    
        return TERMINAL_OK;
}
