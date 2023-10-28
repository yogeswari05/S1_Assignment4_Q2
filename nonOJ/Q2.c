#include<stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
   int n;
   float c1[100];
   float c2[100];
} complexNumber;
complexNumber cNum;

int main(){
   char oper[10];
   int n;
   while(1){
      scanf("%s", oper);
      if(strcmp(oper, "-1") == 0){
         break;
      }
      scanf("%d", &n);
      for (int i = 0; i < n;i++){
         scanf("%f", &cNum.c1[i]);
      }
      for (int i = 0; i < n;i++){
         scanf("%f", &cNum.c2[i]);
      }

      if(strcmp(oper, "ADD") == 0){
         for (int i = 0; i < n; i++){
            printf("%.2f ", cNum.c1[i] + cNum.c2[i]);
         }
      }
      else if(strcmp(oper, "SUB") == 0){
         for (int i = 0; i < n; i++){
            printf("%.2f ", cNum.c1[i] - cNum.c2[i]);
         }
      }
      else if(strcmp(oper, "COSINE") == 0){
         float dot = 0;
         for (int i = 0; i < n;i++){
            dot = dot + cNum.c1[i] * cNum.c2[i];
         }

         float modC1 = 0;
         for (int i = 0; i < n; i++){
            modC1 = modC1 + cNum.c1[i] * cNum.c1[i];
         }
         modC1 = sqrt(modC1);

         float modC2 = 0;
         for (int i = 0; i < n; i++){
            modC2 = modC2 + cNum.c2[i] * cNum.c2[i];
         }
         modC2 = sqrt(modC2);

         float modProduct = 0;
         modProduct = modC1 * modC2;

         printf("%.2f ", dot / modProduct);
      }
   }
   return 0;
}