#include <stdio.h>

void rotation_enc(int key);
//char rotation_dec(int key);



int main () {
    
    int key;
    char menu_option;
    
     printf("Enter a key: \n");
    scanf("%d", &key);
   

    printf("    ROTATION AND SUBSTITUTION CYPHER ENCRYPTION/DECRYPTION\n");
    printf("---------------------------------------------------------------\n\n");

//comment
    
    printf("Main Menu\n");
    printf("a. ENCRYPT with rotation cypher\n");
    printf("b. DECRYPTION of rotation cypher given rotation amount\n");
    printf("c. DECRYPTION of rotation cypher\n");
    printf(" Please enter an option from the main menu: ");
    scanf(" %c",&menu_option);
  



    switch(menu_option){

    case 'a':
        printf("\nSearching for data...\n");
        printf("\nencrypting...\n \n");
        rotation_enc(key);      //call function
    
        break;
      //return 0;
       
    default:
        printf("invalid input");
            break;
}

    
    return 0;
}



void rotation_enc(int key){
    int i = 0;
    FILE *input1;
    FILE *output1;
    char aft[100];
    input1 = fopen("input1.txt", "r"); //read mode
    output1 = fopen("output1.txt", "w");

    
    while(fscanf(input1, "%c", &aft[i]) == 1) {
     fscanf(input1, "%c", &aft[i]);                  //while(filescanf(filename "%d", &savetoarray as long as this does not equal 0))
     aft[i] = aft[i] + key;
     printf("%c", aft[i]);
     
     i++;
}
fprintf(output1, "%s", aft);
printf("%s", aft);

printf("\n \n \n ");
   fclose(input1);
      fclose(output1);
   
}

//char rotation_dec(int key){
    

    



