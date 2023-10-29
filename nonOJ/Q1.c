#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Completed
typedef enum {
   savings,
   current
}accountType;

typedef struct{
   int accountNumber;
   accountType accType;
   char name[50];
   float balance;
} accountInfo;

int num_accounts = 0;
accountInfo accounts[1000];

void createAccount (accountType acctype, char Name[], float amount){  //insert Node
   for (int i = 0; i < num_accounts; i++){
      if(strcmp(accounts[i].name, Name) == 0 && accounts[i].accType == acctype){
         printf("Invalid: User already exists!\n");
         return;
      }
   }

   accountInfo newAccount;
   int flag = 0;
   for (int i = 0; i < num_accounts; i++){
      if(accounts[i].accountNumber==100){
         flag = 1;
      }
   }
   if(flag==0){
      newAccount.accountNumber = 100;
   }
   else{
      int accNumSum = 0;
      int sum = 0;
      for (int i = 0; i < num_accounts; i++){
         accNumSum += accounts[i].accountNumber;
      }
      int x = 100;
      for (int i = 0; i < num_accounts; i++){
         sum += x;
         x++;
      }
      if(accNumSum==sum){
         newAccount.accountNumber = 100 + num_accounts;
      }
      else{
         int diff = accNumSum - sum;
         newAccount.accountNumber = 100 + diff;
      }
   }
   newAccount.accType = acctype;
   strcpy(newAccount.name, Name);
   newAccount.balance = amount;
   accounts[num_accounts] = newAccount;
   num_accounts++;
}
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void display(){  // print
   if(num_accounts == 0){
      printf("No Accounts to display\n");
   }
   else{
      qsort(accounts, num_accounts, sizeof(accountInfo), cmpfunc);
      printf("Account Number\tAccount Type\tName\n");
      for (int i = 0; i < num_accounts;i++){
         char *acctype = accounts[i].accType == savings ? "savings" : "current";
         printf("%d\t%s\t%s\t%.2f\n", accounts[i].accountNumber, acctype, accounts[i].name, accounts[i].balance);
      }
   }
}

void deleteAccount(accountType acc_type, char name[]){
   int ind = -1;
   for (int i = 0; i < num_accounts; i++){
      if(strcmp(accounts[i].name, name) == 0 && accounts[i].accType == acc_type){
         ind = i;
         break;
      }
   }
   if(ind != -1){
      for (int i = ind; i < num_accounts - 1; i++){
         accounts[i] = accounts[i + 1];
      }
      num_accounts--;
      printf("Account deleted successfully\n");
   }
   else{
      printf("Invalid: User does not exist\n");
   }
}

void transaction(int accountNumber, float amount, int code){
   for (int i = 0; i < num_accounts;i++){
      if(accounts[i].accountNumber == accountNumber){
         if(code == 0 && (accounts[i].balance-amount < 100)){
            printf("The balance is insufficient for the specified withdrawl.\n");
            return;
         }
         if(code == 1){
            accounts[i].balance += amount;
            printf("Updated balance is Rs %f\n", accounts[i].balance);
         }
         else{
            accounts[i].balance -= amount;
            printf("Updated balance is Rs %f\n", accounts[i].balance);
         }
         return;
      }
   }
   printf("Invalid: User does not exist\n");
}

void lowBalanceAccounts(){
   for (int i = 0; i < num_accounts; i++){
      if(accounts[i].balance < 100){
         printf("Account Number: %d, Name: %s, Balance: %.0f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
      }
   }
}

int main(){

   char f[10];
   while (1){
      scanf("%s", f);
      if (strcmp(f, "EXIT") == 0){
         break;
      }
      else if(strcmp(f, "CREATE") == 0){
         char acType_str[10];
         char name[20];
         float balance;
         scanf("%s %s %f", acType_str, name, &balance);
         accountType acc_type = (strcmp(acType_str, "savings") == 0) ? savings : current;
         createAccount(acc_type, name, balance);
      }
      else if (strcmp(f, "DELETE") == 0){
         char acType_str[10];
         char name[20];

         scanf("%s %s", acType_str, name);
         accountType acc_type = (strcmp(acType_str, "savings") == 0) ? savings : current;
         deleteAccount(acc_type, name);
      }
      else if(strcmp(f, "TRANSACTION") == 0){
         int acc_num;
         int code;
         float balance;
         scanf("%d %f %d", &acc_num, &balance, &code);
         transaction(acc_num, balance, code);
      }
      else if (strcmp(f, "LOWBALANCE") == 0){
         lowBalanceAccounts();
      }
      else if (strcmp(f, "DISPLAY") == 0){
         display();
      }

   }
   return 0;
}