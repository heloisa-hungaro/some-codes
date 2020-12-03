// sistema para manipulação de arquivos de .dat
// o programa permite alterações no sistema windows
// o arquivo de ajuda é criptografado a cada inicialização do programa

#include <stdio.h>
#include <conio.c>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
int opcao=1,crip;
FILE *arq, *ajuda;

struct campos
{
       int ra,idade;
       char nome[50],sexo,rg[15];
};

void abrearq()
{
     if ((arq=fopen("alunos.dat","a+b"))==NULL)
     {
       printf("\nErro ao abrir/criar arquivo!\n");
       exit(1);
     }
}


void aguarda()
{
     printf("\n\n\nPRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
     getch();
}

void numcrip()
{
     do
     {
         time_t timer;
         char seg[3];
         struct tm * timeinfo;
         time(&timer);
         timeinfo=localtime(&timer);
         strftime(seg,3,"%S",timeinfo);
         crip=atoi(seg);
     }
     while(crip==0);
}

void criptografa(char s[])
{
     int i;
     for (i=0;i<strlen(s);i++)
     {
         s[i]=s[i]+crip;   
     }
}

void descriptografa(char s[])
{
     int i;
     for (i=0;i<strlen(s);i++)
     {
         s[i]=s[i]-crip;   
     }
}

void criaajuda()
{
     if ((ajuda=fopen("ajuda.txt","w"))==NULL)
     {
       printf("\nErro ao criar arquivo de ajuda!\n");
       exit(1);
     }
     numcrip();
     char s[84];
     strcpy(s,"Algumas funcionalidades desse programa funcionam somente em WINDOWS.\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"No menu principal:\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"- MANIPULAR ARQUIVO DE ALUNOS traz o menu de arquivo na tela;\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"- CONSULTAR ARQUIVOS EM PASTA permite que o usuário consulte quais arquivos\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"\testão em determinada pasta do sistema;\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"- RENOMEAR/MOVER ARQUIVO permite que o usuário renomeie ou mova algum arquivo\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"\tdo sistema, bastando inserir o caminho novo do arquivo para movê-lo;\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"- REMOVER ARQUIVO permite que o usuário remova qualquer arquivo do sistema;\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"- ALTERAR DATA DO SISTEMA permite que o usuário altere a data do sistema de\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"\tmodo prático;\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"- ALTERAR HORÁRIO DO SISTEMA permite que o usuário altere o horário do sistema\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"\tde modo prático.\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"No menu de arquivo:\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"- CADASTRAR permite que o usuário insira um novo registro no arquivo de alunos;\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"- ALTERAR permite que o usuário altere um registro do arquivo de alunos;\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"- EXCLUIR permite que o usuário exclua (exclusão lógica e física) um registro\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"\tdo arquivo de alunos;\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"- CONSULTAR POR RA permite que o usuário consulte um registro no arquivo de\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"\talunos através do RA do aluno;\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"- CONSULTAR POR NOME permite que o usuário consulte um registro no arquivo de\n");
     criptografa(s);
     fputs(s,ajuda);
     strcpy(s,"\talunos através do NOME do aluno.");
     criptografa(s);
     fputs(s,ajuda);
     fclose(ajuda);
}

void mostraajuda()
{
     char s[84];
     gotoxy(1,1);
     clrscr();
     if ((ajuda=fopen("ajuda.txt","r"))==NULL)
     {
       printf("\nErro ao criar arquivo de ajuda!\n");
       exit(1);
     }
     while (fgets(s,84,ajuda)!=NULL)
     {
           descriptografa(s);
           printf("%s",s);
     }
     fclose(ajuda);
     aguarda();
}

int letecla(int *lin)
{
    const int 
      cima=72,baixo=80,setas=224,f1=59,func=0,enter=13;
    int tec;
    fflush(stdin);
    tec = getch();
    if (tec == setas||tec == func)
    {
       fflush(stdin);
       tec = getch();
       switch (tec)
       {
           case cima: *lin-=1; printf("cima");
                      return -1;
                      break;
           case baixo:*lin+=1; printf("baixo");
                      return -1;
                      break;
           case f1:   return -2;
                      break;
           default:   return -1;
       }
    }
    else if (tec==enter)
         return *lin;
    else return -1;
}

int menu(int lin)
{
    int op,col=2;
    clrscr();
    gotoxy(1,1);
    printf("[ ] - MANIPULAR ARQUIVO DE ALUNOS\n[ ] - CONSULTAR ARQUIVOS EM PASTA\n[ ] - RENOMEAR/MOVER ARQUIVO\n[ ] - REMOVER ARQUIVO\n[ ] - ALTERAR DATA DO SISTEMA\n[ ] - ALTERAR HORÁRIO DO SISTEMA\n[ ] - SAIR\n\n\n\nF1 - AJUDA");
    gotoxy(col,lin);
    textcolor(12);
    printf("X");
    textcolor(7);
    gotoxy(col,lin);
    op=letecla(&lin);
    if (lin<1)
       lin=7;
    else if (lin>7)
       lin=1;
    if (op==-1)
       menu(lin);
    else if (op==-2)
    {
         mostraajuda();
         menu(lin);   
    } 
    else 
         opcao=op;
}

void consultar()
{
     char nome[50],dir[55];
     clrscr();
     gotoxy(1,1);
     printf("Digite o nome/caminho da pasta a ser consultada (deixar vazio para pasta atual):\n");
     gets(nome);
     strcpy(dir,"dir ");
     strcat(dir,nome);
     system(dir);  
     aguarda();  
}

void renomear()
{
     char nome[50],novo[50];
     clrscr();
     gotoxy(1,1);
     printf("Digite o nome/caminho do arquivo a ser renomeado/movido:\n");
     gets(nome);
     printf("\nDigite o novo nome/caminho do arquivo:\n");
     gets(novo);
     if (rename(nome,novo)!=0)
        perror( "\n\nErro ao renomear arquivo");
     else
         printf("\n\nArquivo renomeado");
     aguarda();    
}

void remover()
{
     char nome[50];
     clrscr();
     gotoxy(1,1);
     printf("Digite o nome/caminho do arquivo a ser removido:\n");
     gets(nome);
     if (remove(nome)!=0)
        perror( "\n\nErro ao deletar arquivo");
     else
         printf("\n\nArquivo deletado");
     aguarda();    
}

void mudadata()
{
     clrscr();
     gotoxy(1,1);
     system("DATE"); 
     aguarda();    
}

void mudahora()
{
     clrscr();
     gotoxy(1,1);
     system("TIME");
     aguarda();
}

void incluir()
{
     campos dados;
     char id[3],ra[15],r;
     gotoxy(1,1);
     abrearq();
     do
     {
       clrscr();
       printf("\n\nNome: ");
       fflush(stdin);
       gets(dados.nome);
       printf("\nRG: ");
       fflush(stdin);
       gets(dados.rg);
       printf("\nSexo: ");
       fflush(stdin);
       scanf("%c",&dados.sexo);
       printf("\nIdade: ");
       fflush(stdin);
       gets(id);
       dados.idade = atoi(id);
       printf("\nRA: ");
       fflush(stdin);
       gets(ra);
       dados.ra = atoi(ra);
       fwrite(&dados, sizeof(dados), 1, arq);
       printf("\n\nDeseja cadastrar outro aluno? (S/N) ");
       do
       {
          r=toupper(getch());
       }while (r!='S' && r!='N');             
     }while (r!='N');
     fclose(arq);  
}

void excluir()
{
     campos dados;
     FILE *aux;
     int ra,rem=0;
     gotoxy(1,1);
     abrearq();
     if ((aux=fopen("alunosaux.dat","w+b"))==NULL)
     {
       printf("\nErro ao criar arquivo auxiliar!\n");
       exit(1);
     }
     
     clrscr();
     printf("Digite o RA do aluno a ser excluído: ");
     scanf("%d",&ra);
     while (fread(&dados,sizeof(dados),1,arq)==1) 
     {
           if (dados.ra!=ra)
              fwrite(&dados, sizeof(dados), 1, aux);
           else
              rem=1;    
     }     
     if (!rem)
        printf("\n\nRegistro não encontrado!");
     else
        printf("\n\nRegistro excluído!"); 
     rewind(aux);
     fclose(arq);
     remove("alunos.dat");
     abrearq();
     while (fread(&dados,sizeof(dados),1,aux)==1) 
     {
           fwrite(&dados, sizeof(dados), 1, arq);   
     }   
     fclose(aux);
     fclose(arq);
     if (remove("alunosaux.dat")!=0)
     {
       printf("\nErro ao apagar arquivo auxiliar!\n");
     }
     aguarda();
}

void alterar()
{
     campos dados;
     char i[3],r[15];
     FILE *aux;
     int alt=0,ra;
     gotoxy(1,1);
     abrearq();
     if ((aux=fopen("alunosaux.dat","w+b"))==NULL)
     {
       printf("\nErro ao criar arquivo auxiliar!\n");
       exit(1);
     }
     clrscr();
     printf("Digite o RA do aluno a ser alterado: ");
     scanf("%d",&ra);
     while (fread(&dados,sizeof(dados),1,arq)==1) 
     {
           printf("x");
           if (dados.ra==ra)
           {  
               printf("\n\nNome: ");
               fflush(stdin);
               gets(dados.nome);
               printf("\nRG: ");
               fflush(stdin);
               gets(dados.rg);
               printf("\nSexo: ");
               fflush(stdin);
               scanf("%c",&dados.sexo);
               printf("\nIdade: ");
               fflush(stdin);
               gets(i);
               dados.idade = atoi(i);
               dados.ra = ra;
               alt=1;    
           }
           fwrite(&dados, sizeof(dados), 1, aux);
     }     
     if (!alt)
        printf("\n\nRegistro não encontrado!");
     else
     {
         printf("\n\nRegistro alterado!");
         rewind(aux);
         fclose(arq);
         remove("alunos.dat");
         abrearq();
         while (fread(&dados,sizeof(dados),1,aux)==1) 
         {
               fwrite(&dados, sizeof(dados), 1, arq);   
         }   
     }
     fclose(aux);
     fclose(arq);
     if (remove("alunosaux.dat")!=0)
     {
       printf("\nErro ao apagar arquivo auxiliar!\n");
     }
     aguarda();
}


void consultara()
{
      campos dados;
      int ra,con=0;
      gotoxy(1,1);
      clrscr();
      printf("Digite o RA do aluno a ser consultado: ");
      scanf("%d",&ra);
      abrearq();
      while (fread(&dados,sizeof(dados),1,arq)==1) 
      {
            if (dados.ra==ra)
           {
               printf("\nNome: %s",dados.nome);
               printf("\nRG: %s",dados.nome);
               printf("\nSexo: %c",dados.sexo);
               printf("\nIdade: %d",dados.idade);
               printf("\nRA: %d",dados.ra);
               con=1;
           }
      }
      if (!con)
        printf("\n\nRegistro não encontrado!");
      fclose(arq);
      aguarda();
 }

void consultanome()
{
      campos dados;
      char nome[50];
      int con=0;
      gotoxy(1,1);
      clrscr();
      printf("Digite o nome do aluno a ser consultado: ");
      fflush(stdin);
      gets(nome);
      abrearq();
      while (fread(&dados,sizeof(dados),1,arq)==1) 
      {
            if (strcmp(dados.nome,nome)==0)
           {
               printf("\nNome: %s",dados.nome);
               printf("\nRG: %s",dados.nome);
               printf("\nSexo: %c",dados.sexo);
               printf("\nIdade: %d",dados.idade);
               printf("\nRA: %d",dados.ra);
               con=1;
           }
      }
      if (!con)
        printf("\n\nRegistro não encontrado!");
      fclose(arq);
      aguarda();
}

int menuarq(int lin)
{
    int op,col=2;
    clrscr();
    gotoxy(1,1);
    printf("[ ] - CADASTRAR\n[ ] - ALTERAR\n[ ] - EXCLUIR\n[ ] - CONSULTAR POR RA\n[ ] - CONSULTAR POR NOME\n[ ] - VOLTAR\n\n\n\n\nF1 - AJUDA");
    gotoxy(col,lin);
    textcolor(12);
    printf("X");
    textcolor(7);
    gotoxy(col,lin);
    op=letecla(&lin);
    if (lin<1)
       lin=6;
    else if (lin>6)
       lin=1;
    if (op==-1)
       menuarq(lin);
    else if (op==-2)
    {
         mostraajuda();
         menuarq(lin);   
    } 
    else 
         opcao=op;
}

void arquivo()
{
     opcao=1;
     do
    {
        menuarq(opcao);
    	switch(opcao)
    	{
            case 1: incluir();
                    break;
            case 2: alterar();
                    break;
            case 3: excluir();
                    break;
            case 4: consultara();
                    break;
            case 5: consultanome();
                    break;
            case 6: opcao=1;
                    return;
                    break;
        }
    } while (opcao!=6); 
}

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    opcao=1;
    criaajuda();
    do
    {
        menu(opcao);
    	switch(opcao)
    	{
            case 1: arquivo();
                    break;
            case 2: consultar();
                    break;
            case 3: renomear();
                    break;
            case 4: remover();
                    break;
            case 5: mudadata();
                    break;
            case 6: mudahora();
                    break;
            case 7: exit(0);
                    break;
        }
    } while (opcao!=7);
}
