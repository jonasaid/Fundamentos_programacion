#include <stdio.h> 


int p1(int n ,int r){
	int i;
	int acum;
	acum = 1;
	i=n;
	do{
		acum*=i;
		i--;
	} while(i>n-r);
	printf("%d \n", acum);
	return acum;
}


int p2(int x){
	int i;
	i=0;
	while(x){
		if(x%2)
		i++;
	x/=2;	
	}
	printf("%d \n", i);
	return i;
}

void p3(void){
	int i;
	for(i=0; i<10; i++)
		if(i%2==0)
		printf("*");
	else
		printf("-");
	printf("\n");
}


void p4(void){
	int i;
	for(i=0; i<3; i+=2)
		printf("*");
	printf("\n");
}


void p5(void){
	int i;
	for(i=0, printf("1"); i<5&&printf("2");i+=2,printf("3"))
		printf("4");
}

int p22(void){
	char x;
	x='R';
	printf("\n");
	while(x!='A'){
		printf("%c", x--);
	}
	return 0;
}

void p10(void){
	int i;
	for(i=0; i<10; i++)
		printf(" %d ", i);
}

char f(char a, char b){
	do{
		a++;
		b++;
	}while((a+b)%2);
	printf(" %c ", (a+b)/2);
	return(a+b)/2;
		
}

int main(){
	p1(7,2);
	p2(3);
	p3();
	p4();
	p5();
	p22();
	p10();
	f('B','D');
}
