#include <stdio.h>

char rotation_enc(int key);




int main ()
{
    int key;
    char menu_option;
    
     printf("Enter your access key: \n");
    scanf("%d", &key);
   

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



    switch(menu_option){

    case 'a':
        printf("Searching for data...");
        printf("encrypting...");
        rotation_enc(key);      //call function
    
        break;
      //return 0;
       
    default:
        printf("invalid input");
            break;
    }
    
    }
    while(menu_option !='e');
    return 0;
}



char rotation_enc(int key){ 
    
    int i = 0;
    FILE *input1;
    char aft[100];
    input1 = fopen("text1.txt", "r"); //read mode
    
    
    while(fscanf(input1, "%c", &aft[i]) != EOF) {                //while(filescanf(filename "%d", &savetoarray as long as this does not equal 0))
     aft[i] = aft[i] + key;
     printf("%c", aft[i]);
    
    
}
   fclose(input1);
    }



