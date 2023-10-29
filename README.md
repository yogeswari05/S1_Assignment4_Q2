# Assignment4_Q1
In this code, I used structures, enums and arrays.
I declared accountType as an enumeration type which stores whether an account type is whether savings or current. accountInfo is a structure consisting of accountNumber of integer type, accType of enum type, name , and balance of float type.
accounts is an array which stores the details of all accounts.nums_accounts is an integer which stores the number of accounts in the accounts array.

createAccount: 
It creates a new account only if there exist no account with same name and accountType in accounts array.For each new account, it assigns unique accountNumber.

display: 
This function displays the details i.e, account numer, account type , name of the account holder and balance of all the accounts present in the accounts array in the increaing order of their account numbers. For the purpose of sorting the account numbers I used qsort function.This function doesnot require any arguments.

cmpfunc:
I used this function in order to sort the account numbers of all the accounts in the accounts array.

transaction: 
This function takes care of withdrawls and deposits.It does withdrawl iff the account has sufficient money.Then it prints the updated balance after transaction.(0->withdrawl, 1->deposit).
lowBalanceAccounts: 
It prints the details of all accounts with balance lesser than 100.

user commands, respective outputs:
CREATE accountType  Name Amount:
creates a new account with name as Name, account type, balance = Amount
DELETE AccountType Name:
deletes an account with AccountType and name as Name, prints Account deleted successfully deleted if it did so, else if it doesnot find thet account, it prints Invalid: User does not exist.
TRANSACTION AccountNumber Amount Code:
It implements transaction function.If Code = 0, it means withdrawl, else if Code = 1, it means deposit.
LOWBALANCE :
implements lowAccountBalance function.
DISPLAY :
implements display function.
EXIT :
This command makes the program stop running.The programs asks input from the user until the user enters EXIT command.

# Assignment4_Q2
In this code, I have used structures.
The structure complexNumber represents pair of complex numbers.Each complexNUmber has an integer n which stores the number of elements in the each complex number.
In main function :
If oper is ADD, it adds the corresponding elements of cNum.c1 and cNum.c2, prints the result of the addition.
If oper is SUB, it subtracts the corresponding elements of cNum.c1 and cNum.c2, prints the result of the subtraction.
If oper is DOT, it calculates the sum of products of corresponding float values of the complexNumbers c1 and c2.
If oper is COSINE, it calculates the value DOT of(c1, c2)/(mod of c1 * mod of c2) where mod is sqrt(c1.a1*c1.a1+c1.a2*c1.a2+...).

# Assignment4_Q3
This code contains a struct Node which represents a node in the single linked list.
an integer color and a pointer to the next node are the members of the struct.
Print : 
this function prints the data of each node of the linkedlist.
insertNode :
This function inserts a new node with a given color_data at the end of the linked list.
delete :
This function deletes the first occurance of a node with data equal to x.And returns the modified linked list after deletion.If the linked list is empty, it returns NULL.
removeDuplicates :
This function removes the duplicate nodes with the same data in the linked list.It returns the modified linked list.
