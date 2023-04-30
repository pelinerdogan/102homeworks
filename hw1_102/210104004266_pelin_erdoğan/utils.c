#include <stdio.h>
#include "utils.h"
#define true 1
#define false 0


  
  
  
  
int find_divisible(int x,int y , int z){ //find divisible funciton start
  
 int f_i = -1; // if there is no integer divided by z this will return error code
 int first = false; // I've used this as a boolean to have the first divider only
  
    for(int i = x;i<=y;i++){
  
     if(i%z==0 && first == false){
       f_i = i;
       first = true;   
     }
   }
  
 return f_i; 
  
} //find divisible funciton end



int find_nth_divisible(int n,int f_i , int z){ //find nth divisible funciton start
  
 int nth_divisible = n*z + f_i;
   
 return nth_divisible;
   
}//find nth divisible funciton end
  
  

  
int validate_identity_number(char identity_number [ ]){//validate ID start
  
  int boolean_for_return = true;
  int identity_integer[11];
  
     for(int i = 0 ; i<11;i++){
      
      identity_integer[i] = identity_number [i] - '0';
       
      if ( identity_integer[i] > 9  || identity_integer[i] < 0) { //tr number every digit must be a digit
       boolean_for_return = false;
      

  }
     }
  
   
  
  
  if ( identity_integer[0] == 0 ) { //tr number can't start with 0
   boolean_for_return = false;

  }
  int  sumOf1_3_5_7_9 = identity_integer[0]+identity_integer[2]+identity_integer[4]+identity_integer[6]+identity_integer[8];
  int  sumOf2_4_6_8 = identity_integer[1]+identity_integer[3]+identity_integer[5]+identity_integer[7];
  int  to_find_10th_num = ((sumOf1_3_5_7_9 *7) - sumOf2_4_6_8 );
   
  to_find_10th_num =  to_find_10th_num%10;
    
    

       if ( to_find_10th_num != identity_integer[9]){ //10th number rule
       boolean_for_return = false;
       }
     
   int sum = 0;
   
       for(int m = 0 ; m<10;m++){
     
        sum = sum + identity_integer[m]; 
  
       }
     
   int  to_find_11th_num ; 
   to_find_11th_num =  sum%10;
 
     if ( to_find_11th_num != identity_integer[10]){ //11th number rule
     boolean_for_return = false;
     }
return boolean_for_return;
}

int check_login(char identity_number [ ], int password){ //this will check if real password and ID is the same with input


  FILE *input ; 
  
  input = fopen ("customeraccount.txt","r");
  
  char tc1,tc2,tc3,tc4,tc5,tc6,tc7,tc8,tc9,tc10,tc11,cama;
  int pass;
  
  fscanf(input,"%c%c%c%c%c%c%c%c%c%c%c" ,&tc1,&tc2,&tc3,&tc4,&tc5,&tc6,&tc7,&tc8,&tc9,&tc10,&tc11);
  fscanf(input,"%c%d" ,&cama,&pass);
  
  fclose(input);
  
  char file_identity_number[11] ={tc1,tc2,tc3,tc4,tc5,tc6,tc7,tc8,tc9,tc10,tc11 }; //ID from file
  
  int customer_boolean = true; //it will stay true if the login is true otherwise it fill change to false
  
     for (int l = 0;l<11;l++){
  
       if( file_identity_number[l] != identity_number [l]){ // to check ID in file and ID user input are the same
         customer_boolean  = false;
       } 
    }
  
  
   if(customer_boolean == true){ // if ID is not the same it will not check password so program will be faster
   
     if (pass !=password){
       customer_boolean  = false;
    }
   }
  
   return customer_boolean ;
 }

  
int create_customer(char identity_number [ ], int password){ //we will write to the file

   FILE *output ;
  
   output = fopen ("customeraccount.txt","w");
  
   for (int p = 0; p<11;p++){
   
     fprintf(output,"%c",identity_number [p]);
   
   } 
     fprintf(output,",%d",password);
  
  
    fclose(output);
  

return 0;  // doesn't need to return a value to main function. İt also could be void function


} 
  
  
  
int withdrawable_amount(float cash_amount){


 int cash = (int) cash_amount;
 
   if ( cash%10 != 0){
     cash = cash - (cash%10);
  }

 return cash;
}  



