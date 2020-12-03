#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <conio.c>
char word[20], dica[20], digitadas[26], confere[26];
int erros=0;


int menu () 
{
    int op;
    clrscr(); 
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
        printf ("Opção inválida! Siga o menu");
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
     printf("O jogo deve ser jogado em 2 jogadores.");
     gotoxy(15,6);
     printf("Um jogador deve pensar em uma palavra (que o outro");
     gotoxy(15,7);
     printf("jogador não deve saber) e em uma dica para essa palavra.");
     textcolor(7);
     gotoxy(15,8);
     printf("Obs.:");
     textcolor(15);
     printf(" palavra e dica devem ter no máximo 20 caracteres.");
     gotoxy(15,9);
     printf("Então ele deverá digitar ambos conforme o jogo exigir.");
     gotoxy(15,10);
     printf("O outro jogador deve tentar descobrir qual é a palavra");
     gotoxy(15,11);
     printf("através da escolha de determinadas letras.");
     gotoxy(15,12);
     printf("Caso a letra esteja presente na palavra, ela aparecerá");
     gotoxy(15,13);
     printf("no devido local. Caso ela não esteja na palavra, uma");
     gotoxy(15,14);
     printf("parte do boneco aparece na forca.");
     gotoxy(15,15);
     printf("O jogador só pode errar 6 vezes, senão perde o jogo.");
     gotoxy(15,16);
     printf("Caso ele descubra a palavra antes que o boneco esteja");
     gotoxy(15,17);
     printf("completo na forca, ele vence o jogo. ");
     textcolor(7);
     gotoxy(16,22);
     printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
     getch();           
}


void digita()
{
     char aux, compara[20]; 
     int x=0;
     gotoxy(7,2);
     printf("Obs.: nas palavras serão aceitos apenas letras e espaços em branco.");
     gotoxy(15,5);
     printf("Digite a palavra (máx 20 caracteres): ");
     do
     {
         fflush(stdin);
         aux=getch();   
         if (isalpha(aux) || aux==32)
         {
            printf("*"); 
            word[x]=toupper(aux);
            x++;            
         } 
         else if (aux==8 && x>0)
         {
            gotoxy(52+x,5);
            printf(" ");
            gotoxy(52+x,5);  
            x--;
         }        
     } while (aux!=13 && x<=19);
     word[x]='\0';
     x=0;
     gotoxy(15,7);
     printf("Digite novamente (máx 20 caracteres): ");
     do
     {
         fflush(stdin);
         aux=getch();   
         if (isalpha(aux) || aux==32)
         {
            printf("*");    
            compara[x]=toupper(aux); 
            x++;           
         } 
         else if (aux==8 && x>0)
         {
            gotoxy(52+x,7);
            printf(" ");
            gotoxy(52+x,7);  
            x--;
         }        
     } while (aux!=13 && x<=19);
     compara[x]='\0';
     x=-1;
     do
     {
       x++; 
       if (word[x]!=compara[x] || word[0]=='\0')
       {
          gotoxy (10,20);
          textcolor(15);
          printf("AS PALAVRAS DIGITADAS NÃO SÃO IDÊNTICAS OU ESTÃO EM BRANCO!");
          gotoxy (15,21);
          textcolor(7);
          printf("Pressione qualquer tecla para digitar novamente."); 
          getch();
          memset(word, '\0', sizeof(word));
          clrscr();
          digita();
       }
     }while (word[x]!='\0' && compara[x]!='\0');
     gotoxy(15,10);
     printf("Digite a dica (máx 20 caracteres): "); 
     gets(dica);
     dica[20]='\0';
 }


void forca()
{
     int i;
     for (i=4;i<10;i++)
     {
         gotoxy(4,i);
         printf("|");
     }
     gotoxy(3,10);
     printf("_|_");
     gotoxy(5,3);
     printf("_ _ _");
     gotoxy(10,4);
     printf("|");    
}


void iniciaconfere()
{
     int x=-1;
     do
     {
        x++;
        if (!isalpha(word[x]))
           confere[x]=' ';
        else
            confere[x]='1';         
     } while (word[x]!='\0');  
     confere[x]='\0';  
     for (x=0;x<26;x++)
         digitadas[x]='0';      
}


void inseremolde()
{
     int x=0;
     gotoxy(30,10);
     do
     {
         if (confere[x]=='1')
            printf ("-");
         else
             printf(" ");
         x++;
     } while (confere[x]!='\0');    
}


void insere()
{
     gotoxy((70-sizeof(word)+6)/2,2);
     printf("Dica: ");
     textcolor(15);
     printf("%s",dica);
     textcolor(7);
     gotoxy(14,15);
     textcolor(9);
     printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
     textcolor(15);
     iniciaconfere();
     inseremolde();
     textcolor(7);   
}


int conferep()
{
     int x=0;
     do
     {
         if (word[x]!=confere[x])
         {
            return 0;               
         }
         x++;            
     } while (word[x]!='\0');
     return 1;
     
}


int leletras()
{
     char aux;
     int x=0, acerto=0;
     gotoxy (30,19);
     printf("Próxima letra: ");
     do
     {
         gotoxy(45,19);
         clreol();
         fflush(stdin);
         scanf("%c", &aux);    
     } while (!isalpha(aux) || digitadas[toupper(aux)-65]=='1');
     aux=toupper(aux);
     digitadas[aux-65]='1';
     do
     {
         if (word[x]==aux)
         {
            acerto=1;
            gotoxy(30+x,10);
            printf("%c",word[x]);  
            confere[x]=aux;               
         }
         x++;            
     } while (word[x]!='\0');
     if (acerto==0)
     {
       erros++;
       textcolor(12);
       switch(erros)
       {
           case 1: gotoxy(10,5);
                   printf("O");
                   break;
           case 2: gotoxy(10,6);
                   printf("|");
                   break;
           case 3: gotoxy(10,7);
                   printf("|");
                   break;
           case 4: gotoxy(9,6);
                   printf("_");
                   break;
           case 5: gotoxy(11,6);
                   printf("_");
                   break;
           case 6: gotoxy(9,8);
                   printf("/");
                   break;
           case 7: gotoxy(11,8);
                   printf("\\");
                   break;   
       }
       textcolor(7);
     }
     gotoxy((aux-65)*2+14,15);
     textcolor(12);
     printf("%c", aux);
     textcolor(7);
     if (!conferep() && erros<7)
        leletras();
     else
     {
         gotoxy(20,21);
         textcolor(15);
         if (erros==7)
            printf("Você perdeu o jogo! A palavra era %s", word);
         else
             printf("PARABÉNS! Você acertou a palavra.");
         gotoxy (30,19);
         clreol();
         gotoxy(16,23);
         textcolor(7);
         printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
     }
}

void jogo()
{
     char aux;
     digita();
     clrscr();
     forca();
     insere();
     leletras();
         
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
        memset(word, '\0', sizeof(word));
        memset(confere, '\0', sizeof(confere));
        erros=0;
        jogo();
     }
     else if (jogar==2)
     {
          tutorial();
     }
    } while (jogar!=0);
    getchar();
}
