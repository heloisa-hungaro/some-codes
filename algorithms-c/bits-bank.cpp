// Password: secreta 
// number format: 0,00
// o sistema "banco bits" permite cálculo automático de notas/moedas necessárias para um valor X (ex: 40 -> 2 de 20 e 1 de 5)
// o sistema reproduz preenchimento automático de cheque (45 -> quarenta e cinco bits) com data atual

#include <stdio.h>
#include <conio.h>
#include <conio.c>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <math.h>

void preenchecheque(double valor)
{
     char uni[10][100]={"","um","dois","três","quatro","cinco","seis","sete","oito","nove"},
          dez[10][100]={"","","vinte","trinta","quarenta","cinquenta","sessenta","setenta","oitenta","noventa"},
          dezdez[10][100]={"dez","onze","doze","treze","quatorze","quinze","dezesseis","dezessete","dezoito","dezenove"},
          cen[10][100]={"","cento","duzentos","trezentos","quatrocentos","quinhentos","seiscentos","setecentos","oitocentos","novecentos"};
     int i,tam,pto,esc=0,cont;
     char v[15],aux[15],cheque[200]="\0";
     sprintf (aux, "%.2lf", valor);  
     tam=strlen(aux);
     v[0]='\0';
     while (tam%3!=0)
     {
        strcat(v,"0");
        tam++;              
     }
     strcat(v,aux);
     for(i=0;i<tam;i+=3)
     {
           if (i!=0 && ((v[i]!='0' && v[i]!=',') || v[i+1]!='0' || v[i+2]!='0'))
                    printf (", ");
           cont=0;
           esc=0;
           if (v[i]=='1' && v[i+1]=='0' && v[i+2]=='0')
           {
                  printf("cem ");
                  esc=1;
           }
           else
           {       
               if (v[i]!='0' && v[i]!=',') 
               {
                      printf("%s ",cen[int(v[i]-'0')]);       
                      cont=1;  
                      esc=1;
               }
           
               if (v[i+1]!='0' && v[i+1]!='1')
               {
                   if (cont==1)
                      printf("e ");
                   printf("%s ",dez[int(v[i+1]-'0')]);
                   cont=2;
                   esc=1;
               }
               if (v[i+2]!='0' && v[i+1]!='1')
               {
                  if (cont==2)
                      printf("e ");
                  printf("%s ",uni[int(v[i+2]-'0')]);
                  esc=1;
               }
               if (v[i+1]=='1')
               {
                   if (cont==1)
                      printf("e ");
                   printf("%s ",dezdez[int(v[i+2]-'0')]);
                   esc=1;
               }
           }
           if (esc)
           {
              if (i==tam-3)
                 if (v[i]=='0' && v[i+1]=='0' && v[i+2]=='1')
                    printf("centbit"); 
                 else
                     printf("centbits"); 
              else if (i==tam-6)
                 if (v[i]=='0' && v[i+1]=='0' && v[i+2]=='1')
                    printf("bit"); 
                 else
                     printf("bits");
              else if (i==tam-9)
                     printf("mil");
              else if (i==tam-12)
                 if (v[i]=='0' && v[i+1]=='0' && v[i+2]=='1')
                    printf("milhão"); 
                 else
                     printf("milhões");
              else if (i==tam-15)
                 if (v[i]=='0' && v[i+1]=='0' && v[i+2]=='1')
                    printf("bilhão"); 
                 else
                     printf("bilhões");
           } 
     }
     time_t t = time(NULL);
     struct tm tm = *localtime(&t);
     printf("\n%d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}


void aguarda()
{
     gotoxy(1,24);
     printf("PRESSIONE QUALQUER TECLA PARA CONTINUAR...");
     getch();
     gotoxy(1,1);     
}


double recebevalor()
{
    double valor;
    gotoxy(1,1);
    printf("DIGITE 0 OU NEGATIVO PARA SAIR DO PROGRAMA\n\n\n");
	printf("Digite o valor de Bits desejado pelo cliente: ");
	scanf("%lf",&valor); 
    return valor;   
}


void contacedulas(double valor)
{
	int i; 
    double qtde;
	double tot;
	float c[11]={100,50,20,10,5,2,1,0.5,0.25,0.1,0.01};
	tot=valor+0.001;
	for (i=0;i<11;i++)
	{
        qtde=0;
		if(tot-c[i]>=0)
        {
            qtde=floor(tot/c[i]);
		    tot-=c[i]*qtde;
        }
		if (qtde>0)
		{
        	printf("\n- %.0lf",qtde);
	        if (c[i]>1)
		        printf(" nota(s) ");
	    	else
				printf(" moeda(s)");
			printf(" de B$ %6.2f",c[i]);	
		}
		if (tot<=0.001) break;	
	}	
}


int login()
{
	int x=0;
	char aux, senha[10];
	gotoxy(1,1);
	printf("DIGITE A SENHA DE ACESSO: ");
	do
     {
         fflush(stdin);
         aux=getch();   
         if (aux==8 && x>0)
         {
            gotoxy(26+x,1);
            printf(" ");
            gotoxy(26+x,1);  
            x--;
         }  
		 else if(aux!=13 && aux!=8)
		 {
            printf("*"); 
            senha[x]=aux;
            x++;            
         }       
     } while (aux!=13);
     senha[x]='\0';
	 if (strcmp(senha,"secreta")==0)
        return 1;
     return 0;	
}


int menu()
{
    int op;
    printf("1 - CONTAR CÉDULAS\n2 - PREENCHER CHEQUE\n3 - CONTAR CÉDULAS E PREENCHER CHEQUE\n\n\n");
    gotoxy(1,8);
    printf("Digite a opção: ");
    scanf("%d", &op);
    while (op<1 || op>3)
    {
      printf ("\n\nOpção inválida!");
      gotoxy(1,8);   
      printf("Digite a opção: "); 
      scanf("%d", &op);
    }
    return op;
}


int main ()
{
	setlocale(LC_ALL, "Portuguese");
    double val;
    int op;
	while (login()==0)
	{
		clrscr();
		gotoxy(1,5);
		printf("SENHA INVÁLIDA! TENTE NOVAMENTE");
	}
	do
	{
    	clrscr();
    	val=recebevalor();
    	if (val<=0) exit(0);
    	clrscr();
    	printf("VALOR: %6.2lf\n\n\n",val);
    	op=menu();
    	clrscr();
    	gotoxy(1,1);
    	switch(op)
    	{
            case 1: printf("VALOR: %6.2lf\n\n\n",val);
                    contacedulas(val);
                    break;
            case 2: printf("VALOR: %6.2lf\n\n\n",val);
                    preenchecheque(val);
                    break;
            case 3: printf("VALOR: %6.2lf\n\n\n",val);
                    contacedulas(val);
                    printf("\n\n\n\n");
                    preenchecheque(val);
                    break;
        }
        aguarda();
     } while (val>0);
     getch();
}
