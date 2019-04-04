#include <stdio.h>

int a(int bef[3]={"raw"}, int aft[3]={"enc"});

int main (void)
{
    char menu_option;
    

    printf("    ROTATION AND SUBSTITUTION CYPHER ENCRYPTION/DECRYPTION\n");
    printf("---------------------------------------------------------------\n\n");

//comment
    do{
    printf("Main Menu\n");
    printf("a. ENCRYPT with rotation cypher\n");
    printf("b. DECRYPTION of rotation cypher given rotation amount\n");
    printf("c. DECRYPTION of rotation cypher\n");
    printf(" Please enter an option from the main menu: ");
    scanf("%c",&menu_option);


//comment
    switch(menu_option){

    case 'a':
        printf("Searching for data...");
        printf("encrypting...");
        a(aft[n]);
        for (n = 0, n<25, n++){
        printf(" %d", aft[n]);
        break;
       return 0;
       
    default:
        printf("invalid input");
            break;
    }

    }while(menu_option !='e');
    }
    return 0;
}

int a(int bef[7]={"message"}){ 
    char enc, key = 4;
    int i = 0, n = 0;
    while (i<10){   //make it less than letters  
    aft[n] = (bef[i]+key)*(%26);
    i++;
    }
}
