#include <stdio.h>
#include <conio.c>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
int mat[3][3], jogador=-1, p1=0, p2=0;


void placar()
{
     gotoxy(50,25);
            printf("(Jogador 1) %d x %d (Jogador 2)",p1,p2);     
}


int menu () 
{
    int op;
    clrscr();
    placar();
    textcolor(15); 
    gotoxy(30,8);
    printf("1 - JOGAR");
    gotoxy(30,9);
    printf("2 - ZERAR PLACAR");
    gotoxy(30,10);
    printf("0 - SAIR ");
    textcolor(7); 
    gotoxy(30,13);
    printf("Opção: ");
    scanf("%d",&op); 
    while (op!=0 && op!=1 && op!=2)
    {
        gotoxy(30,15);
        textcolor(15); 
        printf("Opção inválida! Siga o menu");
        textcolor(7); 
        gotoxy(37,13); 
        clreol();
        scanf("%d",&op);
    }
    return op;    
}


void limpamat()
{
     mat[0][0]=mat[0][1]=mat[0][2]=mat[1][0]=mat[1][1]=mat[1][2]=mat[2][0]=mat[2][1]=mat[2][2]=0;
}


void desenhatab()
{   
    int i;
    for (i=0;i<7;i++)
    {
        gotoxy(37,6+i);
        printf("|");
        gotoxy(41,6+i);
        printf("|");
    }    
}


int checa()
{
    if ((mat[0][0]==jogador && mat[0][1]==jogador && mat[0][2]==jogador)||
        (mat[1][0]==jogador && mat[1][1]==jogador && mat[1][2]==jogador)||
        (mat[2][0]==jogador && mat[2][1]==jogador && mat[2][2]==jogador)||
        (mat[0][0]==jogador && mat[1][0]==jogador && mat[2][0]==jogador)||
        (mat[0][1]==jogador && mat[1][1]==jogador && mat[2][1]==jogador)||
        (mat[0][2]==jogador && mat[1][2]==jogador && mat[2][2]==jogador)||
        (mat[0][0]==jogador && mat[1][1]==jogador && mat[2][2]==jogador)||
        (mat[2][0]==jogador && mat[1][1]==jogador && mat[0][2]==jogador))
    {
       return jogador;
    }
    else return 0;
}

void jogo()
{
     int l,c,jogadas=0;
     do
     {
         if (jogador!=1) jogador=1; 
         else jogador=2;
         gotoxy(42,16);
         clreol();
         gotoxy(43,17);
         clreol();
         gotoxy(35,15);
         textcolor(15); 
         printf("VEZ DO JOGADOR %d",jogador);
         if (jogador==1) printf(" (X) ");
         else printf(" (O) ");
         textcolor(7); 
         gotoxy(35,16);
         printf("Linha: ");
         gotoxy(35,17);
         printf("Coluna: ");
         gotoxy(42,16);
         scanf("%d",&l);
         gotoxy(43,17);
         scanf("%d",&c);
         while ((l<1||l>3||c<1||c>3)||(mat[l-1][c-1]!=0))
         {
            gotoxy(25,19);
            textcolor(15); 
            printf("Posição inválida! Já ocupada ou inexistente");
            gotoxy(35,20);
            printf("Jogue novamente");
            textcolor(7); 
            gotoxy(43,17);
            clreol();
            gotoxy(42,16);
            clreol();
            scanf("%d",&l);
            gotoxy(25,19);
            clreol();
            gotoxy(25,20);
            clreol();
            gotoxy(43,17);
            scanf("%d",&c);                       
         }
         gotoxy(31+4*c,5+2*l);
         if (jogador==1)
         { 
            textcolor(9);
            printf("X");
            textcolor(7);
         }
         else 
         {
            textcolor(12);
            printf("O");
            textcolor(7);
         }
         mat[l-1][c-1]=jogador;
         jogadas++;        
     } while (checa()==0 && jogadas<9);
     gotoxy(25,15);
     clreol();
     textcolor(15); 
     if (checa()==0) printf("DEU VELHA! NINGUÉM GANHOU");
     else 
     {
          printf("O JOGADOR %d VENCEU A PARTIDA!",jogador);
          if (jogador==1) p1++;
          else p2++;
     }
     textcolor(7); 
     gotoxy(20,16);
     clreol();
     printf("Digite qualquer tecla para retornar ao menu");
     placar();
     gotoxy(35,17);
     clreol();
     getch();   
     
}



int main ()
{
    int jogar;
    setlocale(LC_ALL, "Portuguese");
    do
    {
     jogar=menu();
     if (jogar==1)
     {
        clrscr();
        limpamat();
        desenhatab(); 
        placar(); 
        jogo();  
     }
     else if (jogar==2)
     {
          p1=p2=0;
     }
    } while (jogar!=0);
    getchar();
}
