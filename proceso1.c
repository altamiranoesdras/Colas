#include <stdio.h>
#include <stdlib.h>

int main(){
	int p1,p2,opcion,a;
	char p3;
	
	do{
		system("clear");
		printf("   MENU    \n\n");
		printf("1) SUMA \n");
		printf("2) RESTA \n");
		printf("3) MULTIPLICACION \n");
		printf("4) DIVICION \n");
		printf("5) SALIR \n");
		printf("-_-_-_-_-_-_-_-_-_-\n");
		printf("elige tu opcion : ");
		scanf("%d",&opcion);
		
		switch(opcion){

			case 1 :
			system("clear");
			printf(" SUMA \n");
			printf("ingrese operando 1 : ");scanf("%d",& p1);
			printf("ingrese operando 2 : ");scanf("%d",& p2);
			printf("desea aproximar s = si n = no  : ");scanf("%s",& p3);
			a = getchar();
			break;


			case 2 :

			system("clear");
			printf(" RESTA \n");
			printf("ingrese operando 1 : ");scanf("%d",& p1);
			printf("ingrese operando 2 : ");scanf("%d",& p2);
			printf("desea aproximar s = si n = no  : ");scanf("%s",& p3);
			a = getchar();
			break;


			case 3 :

			system("clear");
			printf(" MULTIPLICACION \n");
			printf("ingrese operando 1 : ");scanf("%d",& p1);
			printf("ingrese operando 2 : ");scanf("%d",& p2);
			printf("desea aproximar s = si n = no  : ");scanf("%s",& p3);
			a = getchar();
			break;


			case 4 :

			system("clear");
			printf(" DIVICION \n");
			printf("ingrese operando 1 : ");scanf("%d",& p1);
			printf("ingrese operando 2 : ");scanf("%d",& p2);
			printf("desea aproximar s = si n = no  : ");scanf("%s",& p3);
			a = getchar();

			break;

			/*
			case default:
				system("clear");
				printf("OPCION NO VALIDA");
				a =getchar();
			break;
			*/
		}

	}while(opcion!=5);

}
