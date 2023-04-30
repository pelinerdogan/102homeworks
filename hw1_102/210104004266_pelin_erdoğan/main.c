#include <stdio.h>
#include "utils.h"
#define true 1
#define false 0





int main(){



  int x,y,z;  // part 1 start
 
  printf("Enter the first integer:");
  scanf("%d",&x);
 
 
  printf("\nEnter the second integer:");
  scanf("%d",&y);


  printf("\nEnter the divisor:");
  scanf("%d",&z);

  int f_i = find_divisible(x, y ,z); 
  
    if (f_i == -1){
    
     printf("\nThere is not any integer between %d and %d can be divided by %d\n",x,y,z);
      
     }
    else{
  
     printf("\nThe first integer between %d and %d divided by %d is %d\n",x,y,z,f_i);
     
     int n ;
     
     printf("\nEnter the number how many next:");
     scanf("%d" , &n);
   
     int nth_divisible = find_nth_divisible(n,f_i,z);
   
       if ( nth_divisible > y){
   
        printf("\nNo possible to find %dth divisible between %d and %d divided by %d\n",n+1,x,y,z);
   
       }
       else{
       
       printf("\nThe %d rd integer between %d and %d divided by %d is %d\n" ,n+1,x,y,z,nth_divisible);
       }
    }
     
   
  // part 1 end
  
  //part 2 start
   char trash; 
   scanf("%c" , &trash); // scan takes \n as a char when ı dont put this
   
   char identity_number[11];
   int password;
  
  printf("\nEnter your identity number:");
  
      for(int k = 0; k<11;k++){
      
       scanf("%c",&identity_number[k]);
      
      }
      
  
  printf("\nEnter your password:");
  scanf("%d",&password);
  
  
  scanf("%c" , &trash);  // scan takes \n as a char when ı dont put this
  
 
  int resultID = validate_identity_number(identity_number);
 
    if (resultID == false ){
  
     printf("\nInvalid identity number or password\n");
  
    } 
    else{
    
     int customer_created = create_customer(identity_number , password);
     printf("\nNew customer has been created successfully\n");
     
     // part 2 end part 3 started
     
     printf("\nEnter your identity number:");
  
      for(int k = 0; k<11;k++){
      
       scanf("%c",&identity_number[k]);

      }
           
     printf("\nEnter your password:");
     scanf("%d",&password);
  

    int check_login_Boolean = check_login(identity_number , password);

 
     if(check_login_Boolean== true){
   
      int cashAmount;
    
      printf("\nLogin Successful\n\nEnter your withdraw amount:");
      scanf("%d",&cashAmount);
      
      int drawableCash = withdrawable_amount(cashAmount);
      
      printf("\nWithdrawable amount is:%d\n" , drawableCash);
   
   
     }
     else{
  
     printf("\nInvalid identity number or password\n");
  
     }


   }
  
   






return 0;

}
