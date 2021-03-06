#include <stdio.h>
 
void myprint(void);
int array[10000][10000], multiply[10000][10000];
void myprint() {
  int m, n, c, d, k, num, sum, countx, county = 0;
  
  FILE *file;
  file = fopen("./mat10000.dat", "r");
  if (file) {
    while (fscanf(file, "%d", &num)!=EOF){
      if(m==0) {
        m = num;
        n = num;
      }
      else {
        if(countx<10000) {
          array[countx][county] = num;
          countx++;
        }
        else {
          countx = 0;
          county++;
          array[countx][county] = num;
        }
      }
    }
    fclose(file);
  }
 
  for (c = 0; c < m; c++) {
    for (d = 0; d < n; d++) {
      for (k = 0; k < m; k++) {
        sum = sum + array[c][k]*array[k][d];
      }
      multiply[c][d] = sum;
      sum = 0;
    }
  }
  // printf("%d\t",array[0][0]);
  printf("\nProduct of entered matrices: \n"); 
  for (c = 0; c < m; c++) {
    for (d = 0; d < n; d++)
      printf("%d\t", multiply[c][d]);
    printf("\n");
  }
}