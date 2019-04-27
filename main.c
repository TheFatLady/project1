#include <stdio.h>
#include <ctype.h>


void rotation_enc(int key);
void rotation_dec(int key);
void encr(int key);



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
    printf("c. ENCRYPTION with substitution cypher\n");
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
        
    case 'c':
        printf("\nSearching for data...\n");
        printf("\nencrypting...\n\n");
        encr(key);      //call decryption function
    
    default:
        printf("invalid input\n");          //default response in case invalid response is entered
            break;
}
    return 0;
}





void rotation_enc(int key){
    int i = 0;
   
    FILE *input1; //open files, remember to close them in the function aswell
    FILE *output1;
    char aft[640];
    input1 = fopen("input1.txt", "r"); //read mode
    output1 = fopen("output1.txt", "w");

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
     fprintf(output1, "%c", aft[i]);
     i++;
}
printf("\n \n \n ");
   fclose(input1);
   fclose(output1);
   }



void rotation_dec(int key){
    int i = 0;
    FILE *output1;               //open files, remember to close them in the function aswell
    FILE *output2;
    char aft[640];
    output1 = fopen("output1.txt", "r"); //read mode
    output2 = fopen("output2.txt", "w");

    while(feof(output1) == 0){
           fscanf(output1, "%c", &aft[i]);                  //while(filescanf(filename "%d", &savetoarray as long as this does not equal 0))
     //aft[i] = aft[i] + key;
     
     if((aft[i] >= 97) && (aft[i] <= 122)) {        // ASCII all lowercase numbers (97-122)
         aft[i] = aft[i] - 32;                      //minus 32 to convert to uppercase
}
      if ((aft[i] >= 65) && (aft[i] <= 90))  {           //modulous operation
        aft[i] = (aft[i] - 65 - key)%26+65;         // - key for decryption
}   
  
      if ((aft[i] >= 40) && (aft[i] <= 64) ) {
          aft[i] = aft[i] +26;
}
  

     printf("%c", aft[i]);
        fprintf(output2, "%c", aft[i]);
     i++;
}
printf("\n \n \n ");
   fclose(output1);
   fclose(output2);
   }
   
   
void encr(int key) {
    FILE *input1; 
    FILE *output3;
    char aft[640];
    input1 = fopen("input1.txt", "r"); //read mode
    output3 = fopen("output3.txt", "w");


    while(feof(input1) == 0){
            int i = 0;
           fscanf(input1, "%c", &aft[i]);                  //while(filescanf(filename "%d", &savetoarray as long as this does not equal 0))
     //aft[i] = aft[i] + key;
     
     if((aft[i] >= 97) && (aft[i] <= 122)) {        // ASCII all lowercase numbers (97-122)
         aft[i] = aft[i] - 32;                      //minus 32 to convert to uppercase
}

     if ((aft[i] >= 65) && (aft[i] <= 90))  {           //modulous operation
        aft[i] = (aft[i] - 65 + key)%26+65;           // - key for decryption
}
     if(aft[i] == 'Z') {
         aft[i]= 'A';
}
   if(aft[i] == 'E') {
         aft[i]= 'X';
}
   if(aft[i] == 'B') {
         aft[i]= 'C';
}
   if(aft[i] == 'R') {
         aft[i]= 'D';
}
   if(aft[i] == 'A') {
         aft[i]= 'M';
}
   if(aft[i] == 'L') {
         aft[i]= 'F';
}      
   if(aft[i] == 'P') {
         aft[i]= 'G';
}
     
     printf("%c", aft[i]);
     fprintf(output3, "%c", aft[i]);
     i++;
}
printf("\n \n \n ");
   fclose(input1);
   fclose(output3);
return;
}








     
   

    



