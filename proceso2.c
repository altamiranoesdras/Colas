#include <stdio.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

// estructura enviar mensaje de menu
typedef struct s1
{
	long Id_Mensaje;
	float operador1;
	float operador2;
	int operacion;
	int aproximacion;
	char Mensaje[10];
}Mensaje1;

// estructura recibir mensaje del proceso


typedef struct s2
{
	long Id_Mensaje;
	float resultado;
	int operacion;
	char Mensaje[10];
} Mensaje2;

main(){
	printf("proceso 2 funcionando\n" );
	printf("=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	float p1,p2,p3;
	int o;
	
	key_t Clave1;
	int Id_Cola_Mensajes;
	Mensaje1 Un_Mensaje;
	Mensaje2 sd;
	//
	// Igual que en cualquier recurso compartido (memoria compartida, semaforos 
	//  o colas) se obtien una clave a partir de un fichero existente cualquiera 
	//  y de un entero cualquiera. Todos los procesos que quieran compartir este
	//  semaforo, deben usar el mismo fichero y el mismo entero.
	//
	Clave1 = ftok ("/bin/ls", 33);
	if (Clave1 == (key_t)-1)
	{
		printf("Error al obtener clave para cola mensajes");
		exit(-1);
	}

	//
	//	Se crea la cola de mensajes y se obtiene un identificador para ella.
	// El IPC_CREAT indica que cree la cola de mensajes si no lo está ya.
	// el 0600 son permisos de lectura y escritura para el usuario que lance
	// los procesos. Es importante el 0 delante para que se interprete en
	// octal.
	//
	Id_Cola_Mensajes = msgget (Clave1, 0600 | IPC_CREAT);
	if (Id_Cola_Mensajes == -1)
	{
		printf("Error al obtener identificador para cola mensajes");
		exit (-1);
	}

	//
	//	Se recibe un mensaje del otro proceso. Los parámetros son:
	//	- Id de la cola de mensajes.
	//	- Dirección del sitio en el que queremos recibir el mensaje,
	//	convirtiéndolo en puntero a (struct msgbuf *).
	//	- Tamaño máximo de nuestros campos de datos. 
	//	- Identificador del tipo de mensaje que queremos recibir. En este caso
	//	se quiere un mensaje de tipo 1, que es el que envia el proceso cola1.cc
	//	- flags. En este caso se quiere que el programa quede bloqueado hasta
	//	que llegue un mensaje de tipo 1. Si se pone IPC_NOWAIT, se devolvería
	//	un error en caso de que no haya mensaje de tipo 1 y el programa
	//	continuaría ejecutándose.
	//
	
	while(1){
	
	msgrcv (Id_Cola_Mensajes, (struct msgbuf *)&Un_Mensaje, 
			sizeof(Un_Mensaje.operador1)+sizeof(Un_Mensaje.operador2)+sizeof(Un_Mensaje.aproximacion)+sizeof(Un_Mensaje.Mensaje)+sizeof(Un_Mensaje.operacion), 
			1, 0);
			
	printf("000000---00000\n");
	printf("Recibido mensaje tipo 1\n");
	printf("operador 1 = %f\n",Un_Mensaje.operador1);
	printf("operador 2 = %f\n",Un_Mensaje.operador2);
	printf("operacion = %d\n",Un_Mensaje.operacion);
	printf("aproximacion = %d\n",Un_Mensaje.aproximacion);
	printf("mensaje   = %s\n",Un_Mensaje.Mensaje);
    
    p1=Un_Mensaje.operador1;
    p2=Un_Mensaje.operador2;
    o=Un_Mensaje.operacion;
	printf("--> 	%f\n",o);
	switch(o){
	
	case 1:
	p3=p1+p2;
	sd.Id_Mensaje=2;
	if(Un_Mensaje.aproximacion==1){
	//p3=round(p3);
	}
	sd.resultado =p3;
	printf("resultado  %f\n " ,p3);
	sd.operacion=1;
	strcpy (sd.Mensaje, "suma");
	
	msgsnd (Id_Cola_Mensajes, (struct msgbuf *)&sd, 
			sizeof(sd.resultado)+sizeof(sd.operacion)+sizeof(sd.Mensaje), 
			IPC_NOWAIT);
	
	break;
	
	case 2:
	p3=p1-p2;
	sd.Id_Mensaje=2;
	if(Un_Mensaje.aproximacion==1){
	//p3 = round (p3);
	}
	sd.resultado =p3;
	sd.operacion=2;
	strcpy (sd.Mensaje, "resta");
	
	msgsnd (Id_Cola_Mensajes, (struct msgbuf *)&sd, 
			sizeof(sd.resultado)+sizeof(sd.operacion)+sizeof(sd.Mensaje), 
			IPC_NOWAIT);
	break;
	
	case 3:
	p3=p1*p2;
	sd.Id_Mensaje=2;
	if(Un_Mensaje.aproximacion==1){
	//p3= round (p3);
	}
	sd.resultado =p3;
	sd.operacion=3;
	strcpy (sd.Mensaje, "multiplicacion");
	
	msgsnd (Id_Cola_Mensajes, (struct msgbuf *)&sd, 
			sizeof(sd.resultado)+sizeof(sd.operacion)+sizeof(sd.Mensaje), 
			IPC_NOWAIT);
	
	break;
	
	case 4:
	p3=p1/p2;
	sd.Id_Mensaje=2;
	if(Un_Mensaje.aproximacion==1){
	//p3=round(p3);
	}
	sd.resultado =p3;
	sd.operacion=4;
	strcpy (sd.Mensaje, "divicion");
	
	msgsnd (Id_Cola_Mensajes, (struct msgbuf *)&sd, 
			sizeof(sd.resultado)+sizeof(sd.operacion)+sizeof(sd.Mensaje), 
			IPC_NOWAIT);
	break;
	
	
	
	}
  }
}



