#include <stdio.h>
#include <conio.c>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
int pont=0, jogada=0, seq[100], melhor=0;


void pontuacao()
{
     gotoxy(50,25);
     printf("Pontuação: %d",pont);     
}


int menu () 
{
    int op;
    clrscr();
    gotoxy(50,25);
    printf("Melhor pontuação: %d",melhor);   
    textcolor(15); 
    gotoxy(30,8);
    printf("1 - JOGAR");
    gotoxy(30,9);
    printf("2 - COMO JOGAR");
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


void tutorial()
{
     clrscr();
     textcolor(15);
     gotoxy(15,5);
     printf("Após uma sequência de cores piscar na tela,");
     gotoxy(15,6);
     printf("o jogador deverá repeti-la através das teclas:");
     gotoxy(32,9);
     textcolor(14);
     printf("W = AMARELO\n");
     textcolor(12);
     gotoxy(32,10);
     printf("A = VERMELHO\n");
     textcolor(10);
     gotoxy(32,11);
     printf("S = VERDE\n");
     textcolor(9);
     gotoxy(32,12);
     printf("D = AZUL\n\n");
     textcolor(15);
     gotoxy(15,14);
     printf("(Sempre aguardar a cor selecionada piscar");
     gotoxy(15,15);
     printf("antes de pressionar a próxima)");
     gotoxy(15,17);
     printf("A cada acerto da sequência, ela aumenta.");
     gotoxy(15,18);
     printf("O jogo acaba quando o jogador errar alguma cor.");
     textcolor(7);
     gotoxy(16,22);
     printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
     getch();           
}


void pinta(int cor, int col, int lin)
{
     int i;
     textbackground(cor);
     for (i=0;i<8;i++)
     {
         gotoxy(col,lin+i);
         printf("                    ");    
     }     
     textbackground(0);
}


void pisca(int col, int lin)
{
     int i;
     textbackground(0);
     for (i=0;i<8;i++)
     {
         gotoxy(col,lin+i);
         printf("                    ");    
     }              
}


int proxcor()
{
    srand(time(NULL));
    return 1+(rand() % 4);
}


void piscacor(int x)
{
     switch (x)
     {
            case 1: pisca(30,2);
                    Sleep(500); //0.5 segundo
                    pinta(14,30,2);                    
                    break;
            case 2: pisca(10,10);
                    Sleep(500); 
                    pinta(12,10,10);                    
                    break;
            case 3: pisca(30,10);
                    Sleep(500); 
                    pinta(10,30,10);                    
                    break;
            case 4: pisca(50,10);
                    Sleep(500); 
                    pinta(9,50,10);
                    break;
     }
}


void teclas ()
{
     gotoxy(38,23);
     textcolor(6);
     textbackground(14);
     printf(" W "); 
     gotoxy(35,24);
     textcolor(4);
     textbackground(12);
     printf(" A "); 
     gotoxy(38,24);
     textcolor(2);
     textbackground(10);
     printf(" S "); 
     gotoxy(41,24);
     textcolor(1);
     textbackground(9);
     printf(" D ");
     textcolor(7);
     textbackground(0);          
}


int verifica()
{
    int i,x;
    char tecla;
    for (i=0;i<=jogada;i++)
    {
        do
        {
            fflush(stdin);
            tecla=getch();  
         } while (tecla!=87 && tecla!=119 && tecla!=65 && tecla!=97 && tecla!=83 && tecla!=115 && tecla!=68 && tecla!=100);
        switch (tecla)
        {
               case  87: x=1; 
                        break;
               case 119: x=1; 
                        break;
               case  65: x=2; 
                        break;
               case  97: x=2; 
                        break;
               case  83: x=3; 
                        break;
               case 115: x=3; 
                        break;
               case  68: x=4; 
                        break;
               case 100: x=4; 
                        break;
        }
        piscacor(x);
        Sleep(500);
        if (seq[i]!=x)
        {
           switch (x)
           {
                  case 1: pinta(6,30,2);
                          break;  
                  case 2: pinta(4,10,10);
                          break;
                  case 3: pinta(2,30,10);
                          break;
                  case 4: pinta(1,50,10);
                          break;     
           }
           switch (seq[i])
           {
                  case 1: pinta(6,30,2);
                          break;  
                  case 2: pinta(4,10,10);
                          break;
                  case 3: pinta(2,30,10);
                          break;
                  case 4: pinta(1,50,10);
                          break;     
           }
           return 0;
        }
        pont++;
        pontuacao();
    }
    return 1;
}


void fimjogo()
{
     gotoxy(1,20);
     clreol();
     gotoxy(1,23);
     clreol();
     gotoxy(1,24);
     clreol();
     gotoxy(1,25);
     clreol();
     textcolor(15);
     gotoxy(29,20);
     printf("VOCÊ ERROU A SEQUÊNCIA!");
     gotoxy(34,21);
     printf("FIM DE JOGO!");
     gotoxy(30,23);
     printf("Sua pontuação foi: %d",pont);
     if (pont>melhor)
     {
         
         printf(" - NOVO RECORDE");
         melhor=pont;                     
     }
     gotoxy(18,25);
     textcolor(7);
     printf("PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU");
     getch();
}
 
 
void jogo()
{
     int i;
     gotoxy(1,20);
     clreol();
     gotoxy(1,23);
     clreol();
     gotoxy(1,24);
     clreol();
     pinta (14,30,2);//amarelo
     pinta (12,10,10);//vermelho
     pinta (10,30,10);//verde
     pinta (9,50,10);//azul 
     Sleep(500);
     seq[jogada]=proxcor();
     for (i=0;i<=jogada;i++)
     {
         piscacor(seq[i]);
         Sleep(500);                
     }
     teclas();
     gotoxy(30,20);
     textcolor(15);
     printf("DIGITE A SEQUÊNCIA!");
     textcolor(7);
     if (verifica()==1)
     {
         jogada++;
         jogo();
     }
     else
         fimjogo();
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
        jogada=pont=0;
        pontuacao();
        jogo();
     }
     else if (jogar==2)
     {
          tutorial();
     }
    } while (jogar!=0);
    getchar();
}
