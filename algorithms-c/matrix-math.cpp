#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.c>

void aguarda()
{
     gotoxy (1,24);
     textcolor(15);
     printf("DIGITE QUALQUER TECLA PARA VOLTAR AO MENU");
     textcolor(7);
     getch();
}

void ajuda()
{
     clrscr();
     printf("     O programa trabalha com uma ou duas matrizes, \ndependendo da função que se deseja utilizar.\n");
     printf("     Quando a função utilizar apenas uma matriz, \no usuário poderá selecionar entre usar a matriz 1 ou a 2.\n");
     printf("     Quando forem utilizadas as duas matrizes, \no usuário deve necessariamente ter digitado ambas.\n");
     printf("     Todos os testes são realizados para que as matrizes \nestejam dentro dos padrões requisitados pelas funções.\n");
     printf("     As únicas observações são:\n");
     printf("- Na função subtração, sempre iremos subtrair matriz 1 - matriz 2;\n");
     printf("- Na função multiplicação, sempre iremos multiplicar matriz 1 x matriz 2.\n");
     
}


int testa(int mat[][20])
{
    clrscr();
    gotoxy(1,1);
    if (mat[0][0]=='\0')
       return 0;
    return 1;
}


int escolhe()
{
    int op;
    clrscr(); 
    textcolor(15); 
    gotoxy(30,10);
    printf("1 - MATRIZ 1");
    gotoxy(30,11);
    printf("2 - MATRIZ 2");
    textcolor(7); 
    gotoxy(30,14);
    printf("Opção: ");
    scanf("%d",&op); 
    while ((op<1)||(op>2))
    {
        gotoxy(30,17);
        textcolor(15); 
        printf ("Opção inválida! Siga o menu");
        textcolor(7); 
        gotoxy(37,14); 
        clreol();
        scanf("%d",&op);
    }
    clrscr();
    gotoxy(1,1);
    return op;    

}


int menu () 
{
    int op;
    clrscr(); 
    textcolor(15); 
    gotoxy(30,4);
    printf("1 - AJUDA");
    gotoxy(30,6);
    printf("2 - DIGITAR MATRIZ");
    gotoxy(30,7);
    printf("3 - IMPRIMIR MATRIZ");
    gotoxy(30,8);
    printf("4 - SOMAR MATRIZES");
    gotoxy(30,9);
    printf("5 - SUBTRAIR MATRIZES (MATRIZ 1 - MATRIZ 2)");
    gotoxy(30,10);
    printf("6 - MULTIPLICAR MATRIZES (MATRIZ 1 x MATRIZ 2)");
    gotoxy(30,11);
    printf("7 - TRANSPOSTA DA MATRIZ");
    gotoxy(30,12);
    printf("8 - VERIFICAR SE É SIMÉTRICA");   
    gotoxy(30,13);
    printf("9 - VERIFICAR SE É QUADRADO MÁGICO");
    gotoxy(29,14);
    printf("10 - VERIFICAR SE É QUADRADO LATINO");
    gotoxy(29,15);
    printf("11 - VERIFICAR SE É PERMUTAÇÃO");
    gotoxy(30,17);
    printf("0 - SAIR");
    textcolor(7); 
    gotoxy(30,20);
    printf("Opção: ");
    scanf("%d",&op); 
    while ((op<0)||(op>11))
    {
        gotoxy(30,22);
        textcolor(15); 
        printf ("Opção inválida! Siga o menu");
        textcolor(7); 
        gotoxy(37,20); 
        clreol();
        scanf("%d",&op);
    }
    return op;    
}


int ordemigual(int c, int c2, int l, int l2)
{
    if (c!=c2 || l!=l2)
       return 0;
    return 1;
}


int cliguais(int c, int l)
{
    if (c!=l)
       return 0;
    return 1;
}



void soma(int c, int l, int mat[][20], int mat2[][20], int r[][20])
{
     int i, j;
     for (i=0;i<l;i++)
     {
        for (j=0;j<c;j++) 
        {  
            r[i][j]=mat[i][j]+mat2[i][j];
        }
     }
}


void sub(int c, int l, int mat[][20], int mat2[][20], int r[][20])
{
     int i, j;
     for (i=0;i<l;i++)
     {
        for (j=0;j<c;j++) 
        {  
            r[i][j]=mat[i][j]-mat2[i][j];
        }
     }
}


void mult(int c, int l, int n, int mat[][20], int mat2[][20], int r[][20])
{
     int i, j, k;
     for (i=0;i<l;i++)
     {
        for (j=0;j<c;j++) 
        {   
            r[i][j]=0;
            for (k=0;k<n;k++)
                r[i][j]=r[i][j]+(mat[i][k]*mat2[k][j]); 
        }
     }
}


void trans(int c, int l, int mat[][20], int r[][20])
{
     int i, j;
     for (i=0;i<l;i++)
     {
        for (j=0;j<c;j++) 
        {  
            r[j][i]=mat[i][j];
        }
     }
}


int compara(int c, int l, int mat[][20], int r[][20])
{
     int i, j;
     for (i=0;i<l;i++)
     {
        for (j=0;j<c;j++) 
        {  
            if (r[i][j]!=mat[i][j])
               return 0;
        }
     }
     return 1;
}


void le(int c, int l, int mat[][20])
{
     int i, j;
     for (i=0;i<l;i++)
     {
        for (j=0;j<c;j++) 
        {  
            gotoxy(1+j*4,6+i);
            scanf("%d",&mat[i][j]);
        }
     }
}


void imprime (int c, int l, int mat[][20]) 
{
     int i, j;
     for (i=0;i<l;i++)
     {
        for (j=0;j<c;j++) 
        {  
            gotoxy(1+j*4,6+i);
            printf ("%d",mat[i][j]);
        }
     }
}


int permuta(int n, int mat[][20])
{
    int i, j, zcol=0, ucol=0, zlin=0, ulin=0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)   
        {
            if (mat[i][j]==0)
               zcol++;
            else if (mat[i][j]==1)
                 ucol++;
            else return 0;
            if (mat[j][i]==0)
               zlin++;
            else if (mat[j][i]==1)
                 ulin++;
            else return 0;
        }
        if ((zcol!=(n-1))||(zlin!=(n-1))||(ucol!=1)||(ulin!=1))
           return 0;
        zcol=0;
        zlin=0;
        ucol=0;
        ulin=0;
    }
    return 1;
}

  
int magico(int n, int mat[][20])
{
    int i, j, slin[n], scol[n], sdp=0, sds=0;
    for (i=0;i<n;i++)
    {
        slin[i]=0;
        scol[i]=0;
        for (j=0;j<n;j++)   
        {
            if (i==j) sdp+=mat[i][j];
            if (i+j==n-1) sds+=mat[i][j];
            slin[i]+=mat[i][j];
            scol[i]+=mat[j][i];
        }
        if (slin[i]!=scol[i])
           return 0;
        if (i>0)
        {
                if (slin[i]!=slin[i-1] || scol[i]!=scol[i-1])
                   return 0;
        }
    }
    if (sdp!=sds || sdp!=slin[0])
       return 0;
    printf("\n\n\n(Soma = %d)",sdp);
    return 1;
}
            

int latino(int n, int mat[][20])
{
    int i,j,k, continual=0, continuac=0, total=0, somal=0,somac=0;
    for (k=1;k<=n;k++)
        total+=k;
    for (i=0;i<n;i++)
    {
        somal=0;
        somac=0;
        for (j=0;j<n;j++)   
        {
            continual=0;
            continuac=0;
            for (k=1;k<=n;k++)   
            {
                if (mat[i][j]==k)
                {
                   continual=1;
                   somal+=k;
                }
                if (mat[j][i]==k)
                {
                   continuac=1;
                   somac+=k;
                }
            }
            if (!continual || !continuac)
               return 0;
        }
        if (somal!=total || somac!=total)
           return 0;
    }
    return 1;
}


int main ()
{
    int op, mat[20][20], c, l, c2, l2, mat2[20][20], matr[20][20];
    mat[0][0]='\0';
    mat2[0][0]='\0';
    setlocale(LC_ALL, "Portuguese");
    do
    {
     op=menu();
     switch (op)
     {
            case  1: gotoxy(1,1);
                     ajuda();
                     aguarda();
                     break;
            case  2: switch (escolhe())
                     {
                            case 1: printf("Quantidade de linhas: ");
                                    scanf("%d", &l);
                                    printf("Quantidade de colunas: ");
                                    scanf("%d", &c);
                                    le(c,l,mat);
                                    aguarda();
                                    break;      
                            case 2: printf("Quantidade de linhas: ");
                                    scanf("%d", &l2);
                                    printf("Quantidade de colunas: ");
                                    scanf("%d", &c2);
                                    le(c2,l2,mat2);
                                    aguarda();
                                    break; 
                     }       
                     break;
            case  3: switch (escolhe())
                     {
                            case 1: gotoxy(1,1);
                                    if (testa(mat)) imprime(c,l,mat);
                                    else printf("A matriz 1 não foi digitada!");
                                    aguarda();
                                    break;      
                            case 2: gotoxy(1,1);
                                    if (testa(mat2))imprime(c2,l2,mat2);
                                    else printf("A matriz 2 não foi digitada!");
                                    aguarda();
                                    break; 
                     }
                     break;
            case  4: gotoxy(1,1);
                     if (testa(mat) && testa(mat2)) 
                     {
                        if (ordemigual(c,c2,l,l2)) 
                        {
                           soma(c,l,mat,mat2,matr);
                           imprime(c,l,matr);
                        }                    
                        else printf("Número de colunas ou linhas diferentes! Impossível somar.");                
                     }
                     else printf("Ao menos uma matriz não foi digitada!");
                     aguarda();
                     break;
            case  5: gotoxy(1,1);
                     if (testa(mat) && testa(mat2)) 
                     {
                        if (ordemigual(c,c2,l,l2)) 
                        {
                           sub(c,l,mat,mat2,matr);
                           imprime(c,l,matr);
                        }                    
                        else printf("Número de colunas ou linhas diferentes! Impossível subtrair.");                
                     }
                     else printf("Ao menos uma matriz não foi digitada!");
                     aguarda();
                     break;
            case  6: gotoxy(1,1);
                     if (testa(mat) && testa(mat2)) 
                     {
                        if (cliguais(c,l2)) 
                        {
                           mult(c2,l,c,mat,mat2,matr);
                           imprime(c2,l,matr);
                        }                    
                        else printf("Num. de colunas da matriz 1 diferente de num de linhas da matriz 2! \nImpossível multiplicar.");                
                     }
                     else printf("Ao menos uma matriz não foi digitada!");
                     aguarda();
                     break;
            case  7: switch (escolhe())
                     {
                            case 1: gotoxy(1,1);
                                    if (testa(mat)) 
                                    {
                                       trans(c,l,mat,matr);
                                       imprime(l,c,matr);
                                    }
                                    else printf("A matriz 1 não foi digitada!");
                                    aguarda();
                                    break;      
                            case 2: gotoxy(1,1);
                                    if (testa(mat2))
                                    {
                                       trans(c2,l2,mat2,matr);
                                       imprime(l2,c2,matr);
                                    }
                                    else printf("A matriz 2 não foi digitada!");
                                    aguarda();
                                    break; 
                     }
                     break;
            case  8: switch (escolhe())
                     {
                            case 1: gotoxy(1,1);
                                    if (testa(mat)) 
                                    {
                                      if (cliguais(c,l))
                                       {
                                           imprime(c,l,mat);
                                           trans(c,l,mat,matr);
                                           if (compara(c,l,mat,matr)) printf ("\n\nA matriz é simétrica!");
                                           else printf ("\n\nA matriz não é simétrica!");
                                       }
                                       else printf ("\n\nA matriz não é quadrada!");
                                    }
                                    else printf("A matriz 1 não foi digitada!");
                                    aguarda();
                                    break;      
                            case 2: gotoxy(1,1);
                                    if (testa(mat2))
                                    {
                                       if (cliguais(c2,l2))
                                       {
                                           imprime(c2,l2,mat2);
                                           trans(c2,l2,mat2,matr);
                                           if (compara(c2,l2,mat2,matr)) printf ("\n\nA matriz é simétrica!");
                                           else printf ("\n\nA matriz não é simétrica!");
                                       }
                                       else printf ("\n\nA matriz não é quadrada!");
                                    }
                                    else printf("A matriz 2 não foi digitada!");
                                    aguarda();
                                    break; 
                     }
                     break;
            case  9: switch (escolhe())
                     {
                            case 1: gotoxy(1,1);
                                    if (testa(mat)) 
                                    {
                                      if (cliguais(c,l))
                                       {
                                           imprime(c,l,mat);
                                           if (magico(c,mat)) printf ("\n\nA matriz é quadrado mágico!");
                                           else printf ("\n\nA matriz não é quadrado mágico!");
                                       }
                                       else printf ("\n\nA matriz não é quadrada!");
                                    }
                                    else printf("A matriz 1 não foi digitada!");
                                    aguarda();
                                    break;      
                            case 2: gotoxy(1,1);
                                    if (testa(mat2))
                                    {
                                       if (cliguais(c2,l2))
                                       {
                                           imprime(c2,l2,mat2);
                                           if (magico(c2,mat2)) printf ("\n\nA matriz é quadrado mágico!");
                                           else printf ("\n\nA matriz não é quadrado mágico!");
                                       }
                                       else printf ("\n\nA matriz não é quadrada!");
                                    }
                                    else printf("A matriz 2 não foi digitada!");
                                    aguarda();
                                    break; 
                     }
                     break;
            case 10: switch (escolhe())
                     {
                            case 1: gotoxy(1,1);
                                    if (testa(mat)) 
                                    {
                                      if (cliguais(c,l))
                                       {
                                           imprime(c,l,mat);
                                           if (latino(c,mat)) printf ("\n\nA matriz é quadrado latino!");
                                           else printf ("\n\nA matriz não é quadrado latino!");
                                       }
                                       else printf ("\n\nA matriz não é quadrada!");
                                    }
                                    else printf("A matriz 1 não foi digitada!");
                                    aguarda();
                                    break;      
                            case 2: gotoxy(1,1);
                                    if (testa(mat2))
                                    {
                                       if (cliguais(c2,l2))
                                       {
                                           imprime(c2,l2,mat2);
                                           if (latino(c2,mat2)) printf ("\n\nA matriz é quadrado latino!");
                                           else printf ("\n\nA matriz não é quadrado latino!");
                                       }
                                       else printf ("\n\nA matriz não é quadrada!");
                                    }
                                    else printf("A matriz 2 não foi digitada!");
                                    aguarda();
                                    break; 
                     }
                     break;
            case 11: switch (escolhe())
                     {
                            case 1: gotoxy(1,1);
                                    if (testa(mat)) 
                                    {
                                      if (cliguais(c,l))
                                       {
                                           imprime(c,l,mat);
                                           if (permuta(c,mat)) printf ("\n\nA matriz é permutação!");
                                           else printf ("\n\nA matriz não é permutação!");
                                       }
                                       else printf ("\n\nA matriz não é quadrada!");
                                    }
                                    else printf("A matriz 1 não foi digitada!");
                                    aguarda();
                                    break;      
                            case 2: gotoxy(1,1);
                                    if (testa(mat2))
                                    {
                                       if (cliguais(c2,l2))
                                       {
                                           imprime(c2,l2,mat2);
                                           if (permuta(c2,mat2)) printf ("\n\nA matriz é permutação!");
                                           else printf ("\n\nA matriz não é permutação!");
                                       }
                                       else printf ("\n\nA matriz não é quadrada!");
                                    }
                                    else printf("A matriz 2 não foi digitada!");
                                    aguarda();
                                    break; 
                     }
                     break;       
     }

    } while (op!=0);
    getchar();   
}
