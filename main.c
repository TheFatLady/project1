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
        printf("Error\n");
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
    char aft[640];
    input1 = fopen("input1.txt", "r"); //read mode

    while(feof(input1) == 0){
           fscanf(input1, "%c", &aft[i]);                  //while(filescanf(filename "%d", &savetoarray as long as this does not equal 0))
     //aft[i] = aft[i] + key;
     
     if((aft[i] >= 97) && (aft[i] <= 122)) {        // ASCII all lowercase numbers (97-122)
         aft[i] = aft[i] - 32;                      //minus 32 to convert to uppercase
}

     if ((aft[i] >= 65) && (aft[i] <= 90))  {           //modulous operation
        aft[i] = (aft[i] - 65 + key)%26+65;           // - key for decryption
}
     if(aft[i] == 40) {
         aft[i]= aft[i];
}
      
     
     printf("%c", aft[i]);
     i++;
}
printf("\n \n \n ");
   fclose(input1);
   }



void rotation_dec(int key){
    int i = 0;
   
    FILE *input2;               //open files, remember to close them in the function aswell
    char aft[640];
    input2 = fopen("input2.txt", "r"); //read mode

    while(feof(input2) == 0){
           fscanf(input2, "%c", &aft[i]);                  //while(filescanf(filename "%d", &savetoarray as long as this does not equal 0))
     //aft[i] = aft[i] + key;
     
     if((aft[i] >= 97) && (aft[i] <= 122)) {        // ASCII all lowercase numbers (97-122)
         aft[i] = aft[i] - 32;                      //minus 32 to convert to uppercase
}

      if ((aft[i] >= 65) && (aft[i] <= 90))  {           //modulous operation
        aft[i] = (aft[i] - 65 - key)%26+65;         // - key for decryption
}   
       


      if ((aft[i] >= 30) && (aft[i] <= 64) && aft[i]!=40) {
          aft[i] = aft[i] +26;
}
        
      
     
     printf("%c", aft[i]);
     i++;
}
printf("\n \n \n ");
   fclose(input2);
   }



//void rotation_dec(int key){
    //int i = 0;                 //open files, remember to close them in the function aswell
    //FILE *input2;
    //char aft[640];
     //printf("test1");
    //input2 = fopen("input2.txt", "r"); //read mode
    //while(feof(input2) == 0){
        //scanf(input2, "%c", &aft[i]);                  //while(filescanf(filename "%d", &savetoarray as long as this does not equal 0))
      //printf("teest");
    //if ((aft[i] >= 97) && (aft[i] <= 122)) {             //modulous operation
      //aft[i] = aft[i] - 32;                                   // minus 32 to get upper case 
     // printf("%c:%d"\n, aft[i], aft[i]);
  
  //printf("test");
       




          //fclose(input2);
        //i++;
    //}





     
   

    



