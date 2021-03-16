#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

#define menuPrincipal 0
#define jogando 1
#define creditos 2
#define classificacao 3
#define sair 4
#define perdeu 5

static int tela[128][128];

//Numeros

int numeros[5][40]={
0,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,
0,1,0,1,0,0,1,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,
0,1,0,1,0,0,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,
0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,
0,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1
};

//Pontos

int pontos[5][25]={
1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,
1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,0,0,1,
1,1,1,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,1,1,0,0,
1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,1,
1,0,0,0,1,1,1,0,1,0,1,0,0,1,0,0,1,1,1,0,1,1,1,0,0
};

int voceperdeu[5][57]={
1,0,0,1,0,0,1,1,0,0,0,1,1,1,0,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,0,1,1,1,0,0,1,1,1,0,0,1,1,1,1,0,1,0,0,1,0,0,1,0,1,0,
1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,1,0,
1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,1,1,1,0,0,1,0,0,1,0,1,1,1,0,0,1,0,0,1,0,0,1,0,1,0,
1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
0,1,1,0,0,0,1,1,0,0,0,1,1,1,0,1,1,1,1,0,0,0,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1,0,0,1,0,1,0
};

int vocevenceu[5][51]={
1,0,0,1,0,0,1,1,0,0,0,1,1,1,0,1,1,1,1,0,0,0,1,0,0,1,0,1,1,1,1,0,1,0,0,1,0,0,1,1,1,0,1,1,1,1,0,1,0,0,1,
1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,
1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,1,0,1,1,1,0,0,1,1,0,1,0,1,0,0,0,0,1,1,1,0,0,1,0,0,1,
1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,1,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,
0,1,1,0,0,0,1,1,0,0,0,1,1,1,0,1,1,1,1,0,0,0,0,1,1,0,0,1,1,1,1,0,1,0,0,1,0,0,1,1,1,0,1,1,1,1,0,1,1,1,1
};

int escolhanome[0][0];

//Letras

int A[5][4]={
0,1,1,0,
1,0,0,1,
1,1,1,1,
1,0,0,1,
1,0,0,1
};
int B[5][4]={
1,1,1,0,
1,0,0,1,
1,1,1,0,
1,0,0,1,
1,1,1,0
};
int C[5][4]={
0,1,1,1,
1,0,0,0,
1,0,0,0,
1,0,0,0,
0,1,1,1
};
int D[5][4]={
1,1,1,0,
1,0,0,1,
1,0,0,1,
1,0,0,1,
1,1,1,0
};
int E[5][4]={
1,1,1,1,
1,0,0,0,
1,1,1,0,
1,0,0,0,
1,1,1,1
};
int F[5][4]={
1,1,1,1,
1,0,0,0,
1,1,1,0,
1,0,0,0,
1,0,0,0
};
int G[5][4]={
0,1,1,1,
1,0,0,0,
1,0,1,1,
1,0,0,1,
0,1,1,1
};
int H[5][4]={
1,0,0,1,
1,0,0,1,
1,1,1,1,
1,0,0,1,
1,0,0,1
};
int I[5][4]={
1,1,1,0,
0,1,0,0,
0,1,0,0,
0,1,0,0,
1,1,1,0
};
int J[5][4]={
0,0,0,1,
0,0,0,1,
0,0,0,1,
1,0,0,1,
0,1,1,0
};
int K[5][4]={
1,0,0,1,
1,0,1,0,
1,1,0,0,
1,0,1,0,
1,0,0,1
};
int L[5][4]={
1,0,0,0,
1,0,0,0,
1,0,0,0,
1,0,0,0,
1,1,1,0
};
int M[5][4]={
1,0,0,1,
1,1,1,1,
1,0,0,1,
1,0,0,1,
1,0,0,1
};
int N[5][4]={
1,0,0,1,
1,0,0,1,
1,1,0,1,
1,0,1,1,
1,0,0,1
};
int O[5][4]={
0,1,1,0,
1,0,0,1,
1,0,0,1,
1,0,0,1,
0,1,1,0
};
int P[5][4]={
1,1,1,0,
1,0,0,1,
1,1,1,0,
1,0,0,0,
1,0,0,0
};
int Q[5][4]={
0,1,1,0,
1,0,0,1,
1,0,0,1,
1,0,1,1,
0,1,1,1
};
int R[5][4]={
1,1,1,0,
1,0,0,1,
1,1,1,0,
1,0,1,0,
1,0,0,1
};
int S[5][4]={
0,1,1,1,
1,0,0,0,
0,1,1,0,
0,0,0,1,
1,1,1,0
};
int T[5][4]={
1,1,1,0,
0,1,0,0,
0,1,0,0,
0,1,0,0,
0,1,0,0
};
int U[5][4]={
1,0,0,1,
1,0,0,1,
1,0,0,1,
1,0,0,1,
1,1,1,1
};
int V[5][4]={
1,0,0,1,
1,0,0,1,
1,0,0,1,
1,0,0,1,
0,1,1,0
};
int W[5][4]={
1,0,0,1,
1,0,0,1,
1,0,0,1,
1,1,1,1,
0,1,1,0
};
int X[5][4]={
1,0,0,1,
1,0,0,1,
1,1,1,1,
1,1,1,1,
1,0,0,1
};
int Y[5][4]={
1,0,1,0,
1,0,1,0,
1,1,1,0,
0,1,0,0,
0,1,0,0
};
int Z[5][4]={
1,1,1,1,
0,0,0,1,
0,0,1,0,
0,1,0,0,
1,1,1,1
};

//Vidas

int vidas[7][7]={
0,1,1,0,1,1,0,
1,1,1,1,1,1,1,
1,1,1,1,1,1,1,
0,1,1,1,1,1,0,
0,0,1,1,1,0,0,
0,0,0,1,0,0,0,
1,1,1,1,1,1,1
};

//Matriz do frog

int frog[7][10]={
0,1,0,0,1,1,0,0,1,0,
1,1,0,1,1,1,1,0,1,1,
0,1,1,1,1,1,1,1,1,0,
0,0,0,1,1,1,1,0,0,0,
0,1,1,1,1,1,1,1,1,0,
1,1,0,1,1,1,1,0,1,1,
0,1,0,0,1,1,0,0,1,0
};

//Matrizes dos carros

int carro1[8][11]={
0,0,1,1,0,0,0,1,1,0,0,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
0,0,1,1,0,0,0,1,1,0,0
};

int carro2[8][11]={
0,0,1,1,0,0,0,1,1,0,0,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
0,0,1,1,0,0,0,1,1,0,0
};

int carro3[8][11]={
0,0,1,1,0,0,0,1,1,0,0,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
0,0,1,1,0,0,0,1,1,0,0
};

int carro4[8][11]={
0,0,1,1,0,0,0,1,1,0,0,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
0,0,1,1,0,0,0,1,1,0,0
};

int carro5[8][11]={
0,0,1,1,0,0,0,1,1,0,0,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
0,0,1,1,0,0,0,1,1,0,0
};

int carro6[8][11]={
0,0,1,1,0,0,0,1,1,0,0,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
0,0,1,1,0,0,0,1,1,0,0
};

int carro7[8][11]={
0,0,1,1,0,0,0,1,1,0,0,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
0,0,1,1,0,0,0,1,1,0,0
};

int carro8[8][11]={
0,0,1,1,0,0,0,1,1,0,0,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,
0,0,1,1,0,0,0,1,1,0,0
};

static int keyUP=0, keyDOWN=0, keyLEFT=0, keyRIGHT=0, keyFIRE=0;

void keyPressed(unsigned char key, int x, int y){
	switch(key){
		case 'w':
			keyUP = 1;
			break;
		case 's':
			keyDOWN = 1;
			break;
		case 'a':
			keyLEFT = 1;
			break;
		case 'd':
			keyRIGHT = 1;
			break;
		case ' ':
			keyFIRE = 1;
			break;
	}
}

void keyReleased(unsigned char key, int x, int y){
	switch(key){
		case 'w':
			keyUP = 0;
			break;
		case 's':
			keyDOWN = 0;
			break;
		case 'a':
			keyLEFT = 0;
			break;
		case 'd':
			keyRIGHT = 0;
			break;
		case ' ':
			keyFIRE = 0;
			break;
	}
}

void keySpecialPressed(int key, int x, int y){
	switch(key){
		case GLUT_KEY_UP:
			keyUP = 1;
			break;
		case GLUT_KEY_DOWN:
			keyDOWN = 1;
			break;
		case GLUT_KEY_LEFT:
			keyLEFT = 1;
			break;
		case GLUT_KEY_RIGHT:
			keyRIGHT = 1;
			break;
	}
}

void keySpecialReleased(int key, int x, int y){
	switch(key){
		case GLUT_KEY_UP:
			keyUP = 0;
			break;
		case GLUT_KEY_DOWN:
			keyDOWN = 0;
			break;
		case GLUT_KEY_LEFT:
			keyLEFT = 0;
			break;
		case GLUT_KEY_RIGHT:
			keyRIGHT = 0;
			break;
	}
}


//Declarar posição para a movimentação do Frog e Carros

int pos1=57, pos2=121;
int pos3=60, pos4=87;
int pos5=90, pos6=100;
int pos7=30, pos8=62;
int pos9=110, pos10=75;
int pos11=40, pos12=50;
int pos13=70, pos14=37;
int pos15=65, pos16=25;
int pos17=25, pos18=12;

//Velocidades pros carros

int cont1=8;
int cont2=6;
int cont3=4;
int cont4=2;


//Numero de Vidas

int nv=5;

//Pontuacao

int pontuacao=0;

int centena=0;
int dezena=0;
int unidade=0;

int atual=0;

int li=90, ls=97;
int li2=0, ls2=7, le=0, ld=7;

int contador=20;

void atualizaTela(){
	
	int x,a,b;
	
	for(x=0;x<128;x++){
		for(a=0;a<128;a++){
			tela[x][a]=0;
		}
	}
	
//Tela do Menu

if(atual==0){
//Declarar posição para a movimentação do Frog e Carros
pos1=57, pos2=121;
pos3=60, pos4=87;
pos5=90, pos6=100;
pos7=30, pos8=62;
pos9=110, pos10=75;
pos11=40, pos12=50;
pos13=70, pos14=37;
pos15=65, pos16=25;
pos17=25, pos18=12;
//Velocidades pros carros
cont1=6;
cont2=4;
cont3=2;
cont4=1;
//Numero de Vidas
nv=5;
//Pontuacao
pontuacao=0;
centena=0;
dezena=0;
unidade=0;
atual=0;
li=90, ls=97;
li2=0, ls2=7, le=0, ld=7;
contador=20;
	
	for(x=0;x<128;x++){
		for(a=0;a<128;a++){
			tela[x][a]=0;
		}
	}

for(x=0;x<5;x++){
	for(a=0;a<4;a++){
		//Jogar
		tela[a+52][x+91] = J[x][a];
		tela[a+57][x+91] = O[x][a];
		tela[a+62][x+91] = G[x][a];
		tela[a+67][x+91] = A[x][a];
		tela[a+72][x+91] = R[x][a];
		}
	}
	
	if(keyDOWN == 1){
		li=97;
		ls=104;
	}
	if(keyUP == 1){
		li=90;
		ls=97;
	}
	
	for(x=li;x<ls;x++){
		for(a=0;a<36;a++){
			if(tela[a+45][x] == 0){
				tela[a+45][x] = 1;
			}else {
				tela[a+45][x] = 0;
			}
		}
	}
	
	if(keyFIRE == 1 && li == 90){
		atual=1;
	}
	if(keyFIRE == 1 && li == 97){
		atual=2;
	}
	
}

//Tela do Jogo

if(atual==1){

//Mostrar Pontos

	for(x=0;x<5;x++){
		for(a=0;a<25;a++){
			tela[a+1][x+1] = pontos[x][a];
		}
	}
	
//Mostrar Vidas

int posv=120;
int cv;

	for(cv=0;cv<nv;cv++){
	for(x=0;x<7;x++){
		for(a=0;a<7;a++){
			tela[a+posv][x+1] = vidas[x][a];
		}
	}
		posv=posv-8;
	}
	
//Mostrar o Frog
	
	for(x=0;x<7;x++){
		for(a=0;a<10;a++){
			tela[a+pos1][x+pos2] = frog[x][a];
		}
	}
	
//Mostrar os carros

	for(x=0;x<8;x++){
		for(a=0;a<11;a++){
			if(a+pos3 >= 0 || a+pos3 <= 127){
				tela[a+pos3][x+pos4] = carro1[x][a];
			}
		}
 	}
 	 	
  	for(x=0;x<8;x++){
		for(a=0;a<11;a++){
			if(a+pos5 >= 0 || a+pos5 <= 127){
				tela[a+pos5][x+pos6] = carro2[x][a];
			}
		}
 	}
	 
 	for(x=0;x<8;x++){
		for(a=0;a<11;a++){
			if(a+pos7 >= 0 || a+pos7 <= 127){
				tela[a+pos7][x+pos8] = carro3[x][a];
			}
		}
 	}
	 
 	for(x=0;x<8;x++){
		for(a=0;a<11;a++){
			if(a+pos9 >= 0 || a+pos9 <= 127){
				tela[a+pos9][x+pos10] = carro4[x][a];
			}
		}
 	}
	 
 	for(x=0;x<8;x++){
		for(a=0;a<11;a++){
			if(a+pos11 >= 0 || a+pos11 <= 127){
				tela[a+pos11][x+pos12] = carro5[x][a];
			}
		}
 	}
	 
 	for(x=0;x<8;x++){
		for(a=0;a<11;a++){
			if(a+pos13 >= 0 || a+pos13 <= 127){
				tela[a+pos13][x+pos14] = carro6[x][a];
			}
		}
 	}	 
	 
 	for(x=0;x<8;x++){
		for(a=0;a<11;a++){
			if(a+pos15 >= 0 || a+pos15 <= 127){
				tela[a+pos15][x+pos16] = carro7[x][a];
			}
		}
 	}
	 
 	for(x=0;x<8;x++){
		for(a=0;a<11;a++){
			if(a+pos17 >= 0 || a+pos17 <= 127){
				tela[a+pos17][x+pos18] = carro8[x][a];
			}
		}
 	}
	
//Movimentar os carros
	
	cont1--;
	if(cont1 == 0){
		cont1 = 6;
		pos3 = pos3 - 1;
 		if(pos3 == 0)
 			pos3 = 120;
 			
		pos5 = pos5 + 1;
 		if(pos5 == 120)
 			pos5 = 0;
	
	}
	
	cont2--;
	if(cont2 == 0){
		cont2 = 4;
		pos7 = pos7 - 1;
 		if(pos7 == 0)
 			pos7 = 120;
 			
 		pos9 = pos9 + 1;
 		if(pos9 == 120)
 			pos9 = 0;
	}
	
	cont3--;
	if(cont3 == 0){
		cont3 = 2;
		pos11 = pos11 - 1;
 		if(pos11 == 0)
 			pos11 = 120;
 		
 		pos13 = pos13 + 1;
 		if(pos13 == 120)
 			pos13 = 0;
	}
	
	cont4--;
	if(cont4 == 0){
		cont4 = 1;
		pos15 = pos15 - 1;
 		if(pos15 == 0)
 			pos15 = 120;
 			
 		pos17 = pos17 + 1;
 		if(pos17 == 120)
 			pos17 = 0;
	}

//Movimentar o frog
	
	if(keyDOWN==1 && pos2<121){
		keyDOWN=0;
		pos2=pos2+5;
	}else
	if(keyUP==1 && pos2>2){
		keyUP=0;
		pos2=pos2-5;
	}else
	if(keyRIGHT==1 && pos1<116){
		keyRIGHT=0;
		pos1=pos1+5;
	}else
	if(keyLEFT==1 && pos1>2){
		keyLEFT=0;
		pos1=pos1-5;
	}
	
//Colisão
	
	int posx = pos1;
	int posy = pos2;
	
	//Colisao1
	
	if(((posx >= pos3 && posx <= pos3+11)||(posx + 7 >= pos3 && posx <= pos3+11))
		&&((posy >= pos4 && posy <= pos4+8)||(posy + 10 >= pos4 && posy <= pos4+8))){
		pos1 = 57;
		pos2 = 121;
		nv--;
	}
	//Colisao2
	
	if(((posx >= pos5 && posx <= pos5+11)||(posx + 7 >= pos5 && posx <= pos5+11))
		&&((posy >= pos6 && posy <= pos6+8)||(posy + 10 >= pos6 && posy <= pos6+8))){
		pos1 = 57;
		pos2 = 121;
		nv--;
	}
	
	//Colisao3
	
	if(((posx >= pos7 && posx <= pos7+11)||(posx + 7 >= pos7 && posx <= pos7+11))
		&&((posy >= pos8 && posy <= pos8+8)||(posy + 10 >= pos8 && posy <= pos8+8))){
		pos1 = 57;
		pos2 = 121;
		nv--;
	}
	
	//Colisao4
	
	if(((posx >= pos9 && posx <= pos9+11)||(posx + 7 >= pos9 && posx <= pos9+11))
		&&((posy >= pos10 && posy <= pos10+8)||(posy + 10 >= pos10 && posy <= pos10+8))){
		pos1 = 57;
		pos2 = 121;
		nv--;
	}
	
	//Colisao5
	
	if(((posx >= pos11 && posx <= pos11+11)||(posx + 7 >= pos11 && posx <= pos11+11))
		&&((posy >= pos12 && posy <= pos12+8)||(posy + 10 >= pos12 && posy <= pos12+8))){
		pos1 = 57;
		pos2 = 121;
		nv--;
	}
	
	//Colisao6
	
	if(((posx >= pos13 && posx <= pos13+11)||(posx + 7 >= pos13 && posx <= pos13+11))
		&&((posy >= pos14 && posy <= pos14+8)||(posy + 10 >= pos14 && posy <= pos14+8))){
		pos1 = 57;
		pos2 = 121;
		nv--;
	}
	
	//Colisao7
	
	if(((posx >= pos15 && posx <= pos15+11)||(posx + 7 >= pos15 && posx <= pos15+11))
		&&((posy >= pos16 && posy <= pos16+8)||(posy + 10 >= pos16 && posy <= pos16+8))){
		pos1 = 57;
		pos2 = 121;
		nv--;
	}
	
	//Colisao8
	
	if(((posx >= pos17 && posx <= pos17+11)||(posx + 7 >= pos17 && posx <= pos17+11))
		&&((posy >= pos18 && posy <= pos18+8)||(posy + 10 >= pos18 && posy <= pos18+8))){
		pos1 = 57;
		pos2 = 121;
		nv--;
	}
	
//Checar e mostrar pontuacao

if(pontuacao==0 && pos2 <= 85 && pos2 > 60){
	pontuacao=pontuacao+3;
}
if(pontuacao==3 && pos2 <= 60 && pos2 > 35){
	pontuacao=pontuacao+5;
}
if(pontuacao==8 && pos2 <= 35 && pos2 > 10){
	pontuacao=pontuacao+7;
}
if(pontuacao==15 && pos2 <= 10){
	pontuacao=pontuacao+10;
}

for(x=0;x<5;x++){
	for(a=0;a<4;a++){
		if(pontuacao<10){
		tela[a+28][x+1] = numeros[x][(4*pontuacao)+a];
		}else if(pontuacao<100){
			dezena=(pontuacao/10);
			tela[a+28][x+1] = numeros[x][(4*dezena)+a];
			unidade=pontuacao%10;
			tela[a+32][x+1] = numeros[x][(4*unidade)+a];
		}else {
			centena=(pontuacao/100);
			tela[a+28][x+1] = numeros[x][(4*centena)+a];
			dezena=(pontuacao%100);
			tela[a+32][x+1] = numeros[x][(4*dezena)+a];
			unidade=(pontuacao%100)%10;
			tela[a+36][x+1] = numeros[x][(4*unidade)+a];
		}
	}
}

//Mostrar a pista
	
	for(x=0;x<=127;x++){
		tela[x][110] = 1;	
	}

	for(a=0;a<=127;a=a+5){
		tela[a][97] = 1;
		tela[a+1][97] = 1;
		tela[a+2][97] = 1;	
		a++;
		a++;
		a++;
		a++;
	}

	for(x=0;x<=127;x++){
		tela[x][85] = 1;	
	}
	
	for(a=0;a<=127;a=a+5){
		tela[a][72] = 1;
		tela[a+1][72] = 1;
		tela[a+2][72] = 1;	
		a++;
		a++;
		a++;
		a++;
	}
	
	for(x=0;x<=127;x++){
		tela[x][60] = 1;		
	}

	for(a=0;a<=127;a=a+5){	
		tela[a][47] = 1;
		tela[a+1][47] = 1;
		tela[a+2][47] = 1;
		
		a++;
		a++;
		a++;
		a++;	
	}

	for(x=0;x<=127;x++){
		tela[x][35] = 1;	
	}

	for(a=0;a<=127;a=a+5){
		tela[a][22] = 1;
		tela[a+1][22] = 1;
		tela[a+2][22] = 1;	
		a++;
		a++;
		a++;
		a++;
	}

	for(x=0;x<=127;x++){
		tela[x][10] = 1;	
	}
	
//Checar se ganha ou perde

	if(nv == 0){
		atual=3;
		}
	}
	
	if(pos2 == 1){
		atual=4;
	}

//Tela Perdeu

if(atual == 3){
	for(x=0;x<5;x++){
		for(a=0;a<57;a++){
			tela[a+40][x+60]=voceperdeu[x][a];
		}
	}
	
	for(x=0;x<5;x++){
		for(a=0;a<4;a++){
			tela[a+54][x+80]=M[x][a];
			tela[a+59][x+80]=E[x][a];
			tela[a+64][x+80]=N[x][a];
			tela[a+69][x+80]=U[x][a];
		}
	}
	if(keyFIRE == 1){
		keyFIRE=0;
		atual=0;
	}
	/*
	for(x=0;x<5;x++){
		for(a=0;a<4;a++){
		if(pontuacao<10){
		tela[a+28][x+40] = numeros[x][(4*pontuacao)+a];
		}else{
			tela[a+28][x+40] = numeros[x][(4*dezena)+a];
			tela[a+32][x+40] = numeros[x][(4*unidade)+a];
		}
		}
	}
	*/
}

//Tela Venceu

if(atual == 4){
	for(x=0;x<5;x++){
		for(a=0;a<51;a++){
			tela[a+40][x+60]=vocevenceu[x][a];
			
		}
	}
	for(x=0;x<5;x++){
		for(a=0;a<4;a++){
			tela[a+54][x+80]=M[x][a];
			tela[a+59][x+80]=E[x][a];
			tela[a+64][x+80]=N[x][a];
			tela[a+69][x+80]=U[x][a];
		}
	}
	
	if(keyFIRE == 1){
		keyFIRE=0;
		atual=0;
	}
	/*
	for(x=0;x<5;x++){
		for(a=0;a<25;a++){
			tela[a+1][x+40]=pontos[x][a];
		}
	}
	pontuacao=pontuacao*nv;
	
	for(x=0;x<5;x++){
	for(a=0;a<4;a++){
		if(pontuacao<10){
			tela[a+28][x+40] = numeros[x][(4*pontuacao)+a];
		}else if(pontuacao >= 10 && pontuacao<100){
			dezena=pontuacao/10;
			tela[a+28][x+40] = numeros[x][(4*dezena)+a];
			unidade=pontuacao%10;
			tela[a+32][x+40] = numeros[x][(4*unidade)+a];
		}else {
			centena=(pontuacao/100);
			tela[a+28][x+40] = numeros[x][(4*centena)+a];
			dezena=(pontuacao%100);
			tela[a+32][x+40] = numeros[x][(4*dezena)+a];
			unidade=(pontuacao%100)%10;
			tela[a+36][x+40] = numeros[x][(4*unidade)+a];
		}
	}
	}
	
	*/
}


//Tela Escolha do nome

if(atual==2){
	for(x=0;x<5;x++){
		for(a=0;a<4;a++){
			tela[a+1][x+1] = A[x][a];
			tela[a+8][x+1] = B[x][a];
			tela[a+15][x+1] = C[x][a];
			tela[a+22][x+1] = D[x][a];
			tela[a+29][x+1] = E[x][a];
			tela[a+36][x+1] = F[x][a];
			tela[a+43][x+1] = G[x][a];
			tela[a+50][x+1] = H[x][a];
			tela[a+57][x+1] = I[x][a];
			tela[a+64][x+1] = J[x][a];
			tela[a+71][x+1] = K[x][a];
			tela[a+78][x+1] = L[x][a];
			tela[a+85][x+1] = M[x][a];
			tela[a+92][x+1] = N[x][a];
			tela[a+1][x+9] = O[x][a];
			tela[a+8][x+9] = P[x][a];
			tela[a+15][x+9] = Q[x][a];
			tela[a+22][x+9] = R[x][a];
			tela[a+29][x+9] = S[x][a];
			tela[a+36][x+9] = T[x][a];
			tela[a+43][x+9] = U[x][a];
			tela[a+50][x+9] = V[x][a];
			tela[a+57][x+9] = W[x][a];
			tela[a+64][x+9] = X[x][a];
			tela[a+71][x+9] = Y[x][a];
			tela[a+78][x+9] = Z[x][a];
		}
	}
	
	if(keyUP == 1){
		li2=0;
		ls2=7;
	}
	if(keyDOWN == 1){
		li2=8;
		ls2=15;
	}
	if(keyLEFT == 1 && le >= 7){
		le=le-7;
		ld=ld-7;
		keyLEFT=0;
	}
	if(keyRIGHT == 1 && ld <= 91){
		ld=ld+7;
		le=le+7;
		keyRIGHT=0;
	}

	for(x=li2;x<ls2;x++){
		for(a=le;a<ld;a++){
			if(tela[a][x] == 0){
				tela[a][x]=1;
			}else {
				tela[a][x]=0;
			}
		}
	}
	
	if(keyFIRE == 1){
		for(x=li2;x<ls2;x++){
			for(a=le;a<ld;a++){
				tela[a+1][x+10]=tela[a][x];
			}
		}
	}
	
}

}

void desenha(){
	int i, j;
	
	for(i=0; i<128; i++){
		for(j=0; j<128; j++){
			if(tela[i][j])
				glColor3f(1, 1, 1);
			else
				glColor3f(0, 0, 0);
			
			glBegin(GL_QUADS);
				glVertex2f(i,j+1);
				glVertex2f(i,j);
				glVertex2f(i+1,j);
				glVertex2f(i+1,j+1);
			glEnd();
		}
	}
	
	atualizaTela();
	
	glutSwapBuffers();
	
	glutPostRedisplay();
}

int main(int argc, char ** argv){
	
	glutInit(&argc, argv);
	
	glMatrixMode(GL_MODELVIEW);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	
	glutInitWindowSize(640, 640);
	glutCreateWindow("FROGGER");
	
	gluOrtho2D(0.0, 128.0, 128.0, 0.0);
	
	glutDisplayFunc(desenha);
	
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyReleased);
	
	glutSpecialFunc(keySpecialPressed);
	glutSpecialUpFunc(keySpecialReleased);
	
	glutMainLoop();
	
	return 0;
}
