#include <stdio.h>
#include <ctype.h>


void rotation_enc(int key);             //function definition, input is the key
void rotation_dec(int key);
void encr(int key);
void decr(int key);



int main () {
    
    int key;
    char menu_option;
    
     
   
   
    printf("---------------------------------------------------------------\n---------------------------------------------------------------\n");
    printf("    ROTATION AND SUBSTITUTION CYPHER ENCRYPTION & DECRYPTION\n");
    printf("---------------------------------------------------------------\n---------------------------------------------------------------\n");

                        
    
    printf("Main Menu\n");                                                  //made a menu interface here to make program less confusing 
    printf("a. ENCRYPT with rotation cypher\n");
    printf("b. DECRYPTION of rotation cypher given rotation amount\n");
    printf("c. ENCRYPTION with substitution cypher\n");
    printf("d. DECRYPTION with substitution cypher\n");
    printf(" Please enter an option from the main menu: ");
    scanf(" %c",&menu_option);
  



    switch(menu_option){

    case 'a':                                                               //switch case statements call a function for the desired case
        printf("Enter a key: \n");                  
    scanf("%d", &key);                                                      //user inputs key inside case
    if (key > 26) {
       perror("Error\n");                                                   //print key error if > 26, alphabet = 26
        return 0;
    }
        printf("\nSearching for data...\n");                                //aesthetic text
        printf("\nencrypting...\n \n");
        rotation_enc(key);                                                  //call rotation encryption function
        break;                                                              //use break  so program does not keep running after one task
      
    
    case 'b':
        printf("Enter a key: \n");
    scanf("%d", &key); 
    if (key > 26) {
        printf("Error\n");
        return 0;
    }
        printf("\nSearching for data...\n");
        printf("\ndecrypting...\n\n");
        rotation_dec(key);                                                   //call rotation decryption function
        break;
        
    case 'c':
        printf("\nSearching for data...\n");
        printf("\nencrypting...\n\n");
        encr(key);                                                            //call substitution encryption function
        break;
    
    case 'd':
        printf("\nSearching for data...\n");
        printf("\ndecrypting...\n\n");
        decr(key);                                                            //call substitution decryption function
        break;
    
    default:
        printf("invalid input\n");                                            //default response in case invalid response is entered
            break;
}
    return 0;
}





void rotation_enc(int key){
    int i = 0;                                                                  //initialise integer for array index
   
    FILE *input1;                                                               //FILE IO declare pointer 
    FILE *output1;
    char aft[640];
    input1 = fopen("input1.txt", "r");                                          //open input file in read mode
    output1 = fopen("output1.txt", "w");                                        //open output file in write mode

    while(feof(input1) == 0){                                                   //while(file_end_of_file(filename) returns 0, this while loop encrypts individual characters from a file
           fscanf(input1, "%c", &aft[i]);                                       //filescanf(filename, "%d", &savetoarray)             
          
     
     if((aft[i] >= 97) && (aft[i] <= 122)) {                                    //IF arrayindex = any ASCII lowercase numbers (97-122)
         aft[i] = aft[i] - 32;                                                  //minus 32 from array index to convert to uppercase
}

     if ((aft[i] >= 65) && (aft[i] <= 90))  {                                   //IF arrayindex = any ASCII uppercase numbers (65-90)
            aft[i] = (aft[i] - 65 + key)%26+65;                                 // arrayindex + key is then modulated by 26 to loop the alphabet rotation
     if(aft[i] == 40) {                                                         // IF arrayindex is a space then do not encrypt this index
         aft[i]= aft[i];
}
      
     
     printf("%c", aft[i]);                                                      //print the encrypted arrayindex by each individual character as per the while loop
     fprintf(output1, "%c", aft[i]);                                            //print to output file using fprintf, this will be the input file for rotation decrption
     i++;
}
printf("\n \n \n ");
   fclose(input1);                                                              //close both files
   fclose(output1);
   }



void rotation_dec(int key){
    int i = 0;
    FILE *output1;               
    FILE *output2;
    char aft[640];
    output1 = fopen("output1.txt", "r");                                        //open input file in read mode
    output2 = fopen("output2.txt", "w");                                        //open output file in write mode

    while(fscanf(output1, "%c", &aft[i]) != EOF){                               //while(filescanf(filename "%d", &savetoarray as long as this does not equal 0))
     
     
     if((aft[i] >= 97) && (aft[i] <= 122)) {                                    //IF loop test for lower case numbers
         aft[i] = aft[i] -  32;                                                 //minus 32 to convert to uppercase
}
      if ((aft[i] >= 65) && (aft[i] <= 90))  {                                  //If loop tests for upper case numbers
        aft[i] = (aft[i] - 65 - key)%26+65;                                     // arrayindex - key to counteract the rotations of the encryption, note the key needs to be the same for sucessful decryption
}   
  
      if ((aft[i] >= 40) && (aft[i] <= 64) ) {                                  //IF number decrypted is not upper case letter + 26 to counter - key
          aft[i] = aft[i] +26;
}
  

     printf("%c", aft[i]);
        fprintf(output2, "%c", aft[i]);                                         //print the output to file
     i++;                                                                       //increment arrayindex to save the next value to a new char
}
printf("\n \n \n ");
   fclose(output1);                                                             //close these to avoid problems
   fclose(output2);
   }
   
   
void encr(int key) {                                                            //subsitution encryption cypher
    FILE *input1;                                                               //open original input file to make input easier
    FILE *output3;
    char aft[640];
    input1 = fopen("input1.txt", "r");                                          //standard opening files
    output3 = fopen("output3.txt", "w");

int i = 0;                                                          
    
            
           while (fscanf(input1, "%c", &aft[i]) != EOF){                        //while(filescanf(filename "%d", &savetoarray as long as this does not equal END_OF_FILE)

     
     if((aft[i] >= 97) && (aft[i] <= 122)) {                                    // test for lower case numbers
         aft[i] = aft[i] - 32;                                                  //minus 32 to convert to uppercase
}

     if ((aft[i] >= 65) && (aft[i] <= 90))  {                                   //test for upper case numbers
        aft[i] = (aft[i] - 65)%26+65;                                           // modulous operation
}
     if(aft[i] == 'Z') {                                                        //i didnt understand pointers or any other way of doing this so i hard coded the swaps between letters
         aft[i]= 'A';                                                           //overall there are 16 letters being swapped
         goto zebra;
}
   if(aft[i] == 'E') {
         aft[i]= 'X';
         goto zebra;                                                            //used goto statements to jump over other if statements once letter was swapped 
}
   if(aft[i] == 'B') {
         aft[i]= 'C';
         goto zebra;
}
   if(aft[i] == 'R') {
         aft[i]= 'D';
         goto zebra;
}
   if(aft[i] == 'A') {
         aft[i]= 'M';
         goto zebra;
}
   if(aft[i] == 'L') {
         aft[i]= 'F';
         goto zebra;
}      
   if(aft[i] == 'P') {
         aft[i]= 'G';
         goto zebra;
}
if(aft[i] == 'H') {
         aft[i]= 'O';
         goto zebra;
}
if(aft[i] == 'A') {
         aft[i]= 'Z';
         goto zebra;
}                                                                              
   if(aft[i] == 'X') {
         aft[i]= 'E';
         goto zebra;
}
   if(aft[i] == 'C') {
         aft[i]= 'B';
         goto zebra;
}
   if(aft[i] == 'D') {
         aft[i]= 'R';
         goto zebra;
}
   if(aft[i] == 'V') {
         aft[i]= 'M';
         goto zebra;
}
   if(aft[i] == 'F') {
         aft[i]= 'L';
         goto zebra;
}      
   if(aft[i] == 'G') {
         aft[i]= 'P';
         goto zebra;
}
if(aft[i] == 'O') {
         aft[i]= 'H';
         goto zebra;
}                                                                            
     
     zebra:
     printf("%c", aft[i]);                                                       //print encrypted character to screen
     fprintf(output3, "%c", aft[i]);                                             //print output to file, will be input for substitution decryption
     i++;
}
printf("\n \n \n ");
   fclose(input1);
   fclose(output3);
return;
}

void decr(int key) {                                                             //substitution decryption function
    FILE *output3; 
    FILE *output4;
    char aft[640];
    output3 = fopen("output3.txt", "r");                                         //open files
    output4 = fopen("output4.txt", "w");

int i = 0;                                                                       //initialise integer as array index
    
            
           while (fscanf(output3, "%c", &aft[i]) != EOF){                        //while loop to decrypt each individual character
     
     
     if((aft[i] >= 97) && (aft[i] <= 122)) {                                     // ASCII all lowercase numbers (97-122)
         aft[i] = aft[i] - 32;                                                   //minus 32 to convert to uppercase
}

     
     if(aft[i] == 'A') {                                                        //if statements decrypt individual characters of encrypted text with this hardcoded key
         aft[i]= 'Z';
         goto zebra1;
}
   if(aft[i] == 'X') {
         aft[i]= 'E';
         goto zebra1;
}
   if(aft[i] == 'C') {
         aft[i]= 'B';
         goto zebra1;
}
   if(aft[i] == 'D') {
         aft[i]= 'R';
         goto zebra1;
}
   if(aft[i] == 'M') {
         aft[i]= 'A';
         goto zebra1;
}
   if(aft[i] == 'F') {
         aft[i]= 'L';
         goto zebra1;
}      
   if(aft[i] == 'G') {
         aft[i]= 'P';
         goto zebra1;
}
if(aft[i] == 'O') {
         aft[i]= 'H';
         goto zebra1;
}
if(aft[i] == 'Z') {
         aft[i]= 'A';
         goto zebra1;
}
   if(aft[i] == 'E') {
         aft[i]= 'X';
         goto zebra1;
}
   if(aft[i] == 'B') {
         aft[i]= 'C';
         goto zebra1;
}
   if(aft[i] == 'R') {
         aft[i]= 'D';
         goto zebra1;
}
   if(aft[i] == 'M') {
         aft[i]= 'V';
         goto zebra1;
}
   if(aft[i] == 'L') {
         aft[i]= 'F';
         goto zebra1;
}      
   if(aft[i] == 'P') {
         aft[i]= 'G';
         goto zebra1;
}
if(aft[i] == 'H') {
         aft[i]= 'O';
         goto zebra1;
}
     
     zebra1:
     printf("%c", aft[i]);
     fprintf(output4, "%c", aft[i]);                                             //print to file 
     i++;   
}
printf("\n \n \n ");
   fclose(output3);                                                              //close files
   fclose(output4);
return;     

}






     
   

    



