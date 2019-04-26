#include <stdio.h>
#include <ctype.h>


void rotation_enc(int key);
void rotation_dec(int key);



int main () {
    
    int key;
    char menu_option;
    
     printf("Enter a key: \n");
    scanf("%d", &key); //make it between 0 and 25
    if (key > 26) {
        printf("error");
        return 0;
    }
   
   

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
        printf("\nSearching for data...\n");    //aesthetic text
        printf("\nencrypting...\n \n");
        rotation_enc(key);      //call function
    
        break;
      //return 0;
    
    case 'b':
        printf("\nSearching for data...\n");
        printf("\ndecrypting...\n\n");
        rotation_dec(key);      //call decryption function
        
        break;
    
    default:
        printf("invalid input\n");          //default response in case invalid response is entered
            break;
}

    
    return 0;
}



void rotation_enc(int key){
    int i = 0;
    FILE *input1;               //open files, remember to close them in the function aswell
    FILE *output1;
    char aft[640];
    input1 = fopen("input1.txt", "r"); //read mode
    output1 = fopen("output1.txt", "w");    //write mode

    while(feof(input1) == 0){
           fscanf(input1, "%c", &aft[i]);                  //while(filescanf(filename "%d", &savetoarray as long as this does not equal 0))
     aft[i] = aft[i] + key;
     
      if ((aft[i] >= 'A') && (aft[i] <= 'Z'))  {           //modulous operation
        aft[i] = (aft[i] - 'A' + key)%26+'A';           // - key for decryption
    }
     else if(aft[i] >= 'a') && (aft[i] <= 'z')) {
         aft[i] = aft[i] - 32
     }
     
     printf("%c", aft[i]);
     i++;
}
printf("\n \n \n ");
   fclose(input1);
      fclose(output1);
   
}

void rotation_dec(int key){
    int i = 0;                 //open files, remember to close them in the function aswell
    FILE *input2;
    char aft[640];
    input2 = fopen("input2.txt", "r"); //read modeb
    while(feof(input2) == 0){
        fscanf(input2, "%c", &aft[i]);                  //while(filescanf(filename "%d", &savetoarray as long as this does not equal 0))
        
    
        
         if ((aft[i] >= 'A') && (aft[i] <= 'Z')) {             //modulous operation
        aft[i] = aft[i] - 32;                                   // minus 32 to get upper case 
    else if ( )
    
        aft[i] = (aft[i] - key)%26+'A';                   




        printf("%c", aft[i]);
        i++;
    }

printf(" the complete string: \n%s", aft);

printf("\n \n \n ");
   fclose(input2);
     
   
}
    



