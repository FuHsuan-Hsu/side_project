#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int n, m  ;
int B[10][256][256] ;
// Function

int lineS (int i, int j, int k)
{
	int bingo = 1 ;
	for (int num = 0 ; num < m; num++ ){
		if (B[i][num][k] != -1 ){
			bingo = 0 ;
		}
	}
	if (bingo == 1) return 1;
	else return 0;
}

int lineH (int i, int j, int k)
{
	int bingo = 1 ;
	for (int num = 0 ; num < m ; num++ ){
		if (B[i][j][num] != -1 )
			bingo = 0 ;
		
	}
	if (bingo == 1) return 1;
	else return 0;
}

int lineC (int i, int j, int k)
{
	
	if ( ! ((j==k) || (j+k == m-1))) return 0;  // 提早判斷數字是否在對角線上
	int bingo = 1 ;
	for (int num = 0 ; num < m ; num++ ){
		if ( B[i][num][num] != -1 ) 
			bingo=0;
	}
	if (bingo == 1 ) return 1;
	
	bingo = 1 ;
	for(int num = 0 ; num < m ; num++){
		if (B[i][num][m-1-num] != -1)
			bingo=0;
	}
	if (bingo == 1 ) return 1;
	
	else return 0;
	}	
	
int *randomlize(int *a, int n)
{
    srand(time(NULL));
    int i = 0,j = 0, k = 0;    
    for(i = 0; i < n; i++)        
    {        
        j = rand()%(n-i)+i;        
        k = a[i];        
        a[i] = a[j];        
        a[j] = k;        
    }    
}


//
int main() {
	
	 int i , j ,k , num , x;
	 int count ;
	 int bingo = 0;
	 printf("How many player & how big ? \n");
	 scanf("%d %d" , &n ,&m );
	 
	 if (n > 1){
	 	for(i=0 ; i<n ;i++){
	 	 	printf("Enter player %d pattern \n", i);
	 		for(j=0 ; j< m ; j++){
	 		for (k=0 ; k< m ; k++){
	 			
	 			scanf("%d" , &B[i][j][k]);
	 		}
	 	}
	 }
}
	 else {
	 
	 	printf("Enter player %d pattern \n", i);
	 		for(j=0 ; j< m ; j++){
	 		for (k=0 ; k< m ; k++){
	 			
	 			scanf("%d" , &B[0][j][k]);
	 		}
	 	}
	 	    int a[m*m];
    		for (i=1; i<=m*m; i++){
    			a[i-1] = i ;
				}
	 	randomlize(a,m*m);
	 	
	 		for(j=0 ; j< m ; j++){
	 		for (k=0 ; k< m ; k++){
	 		B[1][j][k] = a[m*j+k] ;
			
			printf("%d " , B[1][j][k]) ;	
	 		n = 2;
		 }printf("\n");
	 	
	 }
}

	 printf("Enter Bingo number \n");
	 for (num = 0 ; num < m*m ; num++ ){
	 	scanf("%d" , &count );
	 	
	 	for (i=0 ; i<n ;i++){
	 		for(j=0 ; j< m ; j++){
	 			for (k=0 ; k< m ; k++){
	 				if (count == B[i][j][k]){
	 					B[i][j][k] = -1 ;     // mark
	 					//printf("i = %d  lineS = %d  lineH = %d  lineC = %d \n" , i,lineS(i,j,k),lineH(i,j,k),lineC(i,j,k) ) ;
	 					
						 x = ((lineS(i,j,k) + lineH(i,j,k) + lineC(i,j,k)) );
	 						if( x == 1 ){
	 						bingo = 1;
	 						printf("The winner is player %d \n", i);
	 						//printf("%d ", i);
	 						}
	 					}//printf("%d " , B[i][j][k]);
	 				//printf("%d ", B[i][j][k]) ;
	 				}//printf("\n");
	 			}//printf("\n");
	 		}
	 		if (bingo == 1) break;
	 		
	 	}
	 	
	 	printf("\nBingo number = %d " , count) ;
	 	

	
	
	return 0;
}
