#include "card.h"

int getLen_c (uint8_t arr_name[])
{
    int count = 0;
    for (int i = 0; i < 100; ++i)
    {
        if (arr_name[i])    count++;

        else    break;
    }
    
    return count;
}

int RightFormat_c(unsigned char arr_date[])
{
    int check = 1;

    for (int i = 0; i < 5; ++i)
    {   
        // Digit 0 must be 0 or 1, but digit 1 may take values from 1 to 9

        if ( (arr_date[0] = '0' || arr_date[0] == '1') && 
        ('1' <= arr_date[1] && arr_date[1] <= '9') );   // Do nothing

        else check = 0;

        if (arr_date[2] == '/') ;

        else check = 0;

        // I assumed starting from 00 (2000) to 25 (2025)

        if ( ('0' <= arr_date[3] && arr_date[3] <= '2' ) && 
        ('0' <= arr_date[4] && arr_date[4] <= '9') ) ;

        else check = 0;
    }

    return check;
}


EN_cardError_t getCardHolderName (ST_cardData_t *cardData)
{
    int getLen_c (uint8_t arr_name[]) ;  // To know the length of user name.

    // Ask user to enter his card's name

    printf("Input Your name:");
    scanf("%[^\n]*c", cardData->cardHolderName); // Get the card holder name
    //getc(stdin);
    
    int length = getLen_c (cardData->cardHolderName); // Get the length
    
    if (length == 0 || length < 20 || length > 25)
        return WRONG_NAME;  // 1

    else    return CARD_OK; // 0
}

EN_cardError_t getCardExpiryDate (ST_cardData_t *cardData)
{   
    int getLen_c (uint8_t arr_name[]) ; // To know the length of expiration date.
    int RightFormat_c(uint8_t arr_date[] ); // To check the format of expiration date
    
    // Ask user to enter his card's expiration date

    printf("Please, enter your expiration date in format(mm/yy):");
    scanf("%[^\n]*c", cardData->cardExpirationDate); // Get the card expiration date
    //getc(stdin);

    int length = getLen_c(cardData->cardExpirationDate); // Get the length

    if (length == 0|| length < 5 || length > 5)  
        return WRONG_EXP_DATE;  // 2

    // If the format is not right, return wrong date.

    else if (!RightFormat_c(cardData->cardExpirationDate)) 
        return WRONG_EXP_DATE;

    else    return CARD_OK;
}

EN_cardError_t getCardPAN (ST_cardData_t *cardData)
{   
    int getLen_c (uint8_t arr_name[]) ; // To know the length of PAN number.

    // Ask user to enter his pan number

    printf("Please, enter your PAN: ");
    scanf("%[^\n]*c", cardData->primaryAccountNumber);    // Get pan number
    //getc(stdin);
    
    int length = getLen_c(cardData->primaryAccountNumber); // Get the length

    if (length == 0 || length < 16 || length > 19)
        return WRONG_PAN;

    else    return CARD_OK;

}



