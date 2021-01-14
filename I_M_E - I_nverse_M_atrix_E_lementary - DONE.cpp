/* Este algoritmo foi criado para fins educativos e com o objetivo de alcançar a aprovação na discilpina 
*  de ALGORITMOS E PROGRAMAÇÃO, ministrada pelo PROFESSOR DR. ENG. RODRIGO VARELLA, 
*  no curso de ENGENHARIA ELÉTRICA da UNIVERSIDADE FEDERAL DE SANTA MARIA, CAMPUS CACHOEIRA DO SUL.
*  
*  Grupo: BRUNO PONCIANO; MARCOS ALVES DOS SANTOS; MARIANNA T. BATISTA.
*
*                            Cachoeira do Sul, RS - Brazil
*                                         2017
*/


#include<stdio.h>
#include<stdlib.h>

int i,j,k,r,l,g,n,escolha;
float A[20][20],c;
int soma_da_primeira_linha_da_identidade;

main()
{
do{ 

fflush(stdin);           

/////////////////////////////////////////////  C O L E T A   D A   M A T R I Z  //////////////////////////////////////////////////////////////      
do{
///////////////////////////// ORDEM DA MATRIZ ////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\tEscreva a ordem da matriz: "); scanf("%d", &n);
    
    fflush(stdin);
///////////////////////////// MATRIZ /////////////////////////////////////////////////////////////////////////////////////////////////////////
	printf("Escreva os elementos da matriz: \n\n");
	for(i=1; i<=n; i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("A[%d][%d] : ", i,j);
			scanf("%f", &A[i][j]);
		}
	}
	
	
//////////////////////////// IDENTIDADE //////////////////////////////////////////////////////////////////////////////////////////////////////
		for(i=1; i<=n; i++) //Varre as linhas da matriz I
		{
		for(j=n+1; j<=2*n; j++) //Varre as colunas da matriz I
		{
			if(j==n+i)
			{
				A[i][j]=1;
			}
			else
			{
				A[i][j]=0;
			}	
		}
		}
		
system("cls");


/////////////////////////// MOSTRA A MATRIZ A SER INVERTIDA ///////////////////////////////////////////////////////////////////////////////////
	printf("\n\t\tA matriz a ser invertida e: \n\n");
		for(i=1; i<=n; i++) 
	{
		for(j=1; j<=n; j++)
		{
			printf("%15.2f", A[i][j]);
		}
		putchar('\n');
	}
	
////////////////////////// PERGUNTA SE QUER REESCREVER A MATRIZ //////////////////////////////////////////////////////////////////////////////
	printf("\n\n\t\tPRESSIONE 1 PARA INVERTER ESTA MATRIZ PELO MÉTODO ELEMENTAR\n\t\t\tOU PRESSIONE 0 PARA REESCREVER A MATRIZ\n"); 
    scanf("%d", &escolha);
    system("cls");
}while( escolha != 1 );	

/////////////////////////////////////////////  C Á L C U L O S  //////////////////////////////////////////////////////////////////////////////
	
///////////////////////////////ESCALONAMENTOOOO//////////////////////
	for(j=1;j<=n;j++)
	{	
		for(i=1;i<=n;i++)
		{
			if(i>j) //LINHAS
			{
				c=-(A[i][j]/A[j][j]);
				for(k=1;k<=n+n;k++)
				{
					A[i][k]=c*A[j][k]+A[i][k];
				}
			}
			if(j>i) //COLUNAS
			{
				c=-(A[i][j]/A[j][j]);
				for(r=1;r<=n+n;r++)
				{
					A[i][r]=c*A[j][r]+A[i][r];
				}
			}
		}
	}
	
//////// DIVISÃO DAS LINHAS PELOS ELEMENTOS DA DIAGONAL PRINCIPAL DA MATRIZ DADA ////
    for(l=n; l>=1; l--)
    {
     	for(g=2*n; g>=1; g--)
     	{
        	if(A[l][l] == 1)
			{
		            continue;
		    }
		    if(A[l][l] != 0)
			{
				A[l][g] = A[l][g]/A[l][l];
			}
		}
	}
                        ///////////////////  SOMATÓRIO PARA VERIFICAÇÃO DA IVERSIBILIDADE  //////////////////////////
						soma_da_primeira_linha_da_identidade = 0;
                        for(j=1; j<=n; j++)
                        {
				            soma_da_primeira_linha_da_identidade = soma_da_primeira_linha_da_identidade + A[j][1];
						}

///////////////////////////////////////////  V E R I F I C A   S E    É   I N V E R S Í V E L  //////////////////////////////////////////////	 
	 if( soma_da_primeira_linha_da_identidade != 1 )
{
	printf("\nA matriz nAo e' inversIvel! Por favor, digite uma matriz inversIvel.\n\n");

}
else
{
    soma_da_primeira_linha_da_identidade = 1;
}
}while( soma_da_primeira_linha_da_identidade != 1 );

////////////////////////////////////////////  F I M   D O S   C Á L C U L O S  ///////////////////////////////////////////////////////////////

system("cls");

///////////////////////////////////////////  EXIBIÇÃO DA MATRIZ IDENTIDADE E DA MATRIZ INVERTIDA /////////////////////////////////////////////
	printf("\n\t\tMATRIZ IDENTIDADE \tE A \tMATRIZ INVERTIDA: \n\n");
		for(i=1; i<=n; i++) 
	{
		for(j=1; j<=2*n; j++)
		{
			if(j<=n)
			{
				if(j==1)
				{putchar('|');
				}
			    printf("%5.0f", A[i][j]);
			    if(j==n)
			    {printf("\t|");
				}
			}
			else
			{
				if(j==n+1)
				{printf("\t|");
				 printf("%10.2f", A[i][j]);
				}
				else
				{printf("%10.2f", A[i][j]);
				}
			    if(j == 2*n)
			    {printf("\t|");
			    }
			}
		}
		putchar('\n');
	}
////////////////////////////////////////// G L Ó R I A  A  D E U S  ! ! ! :D  ////////////////////////////////////////////////////////////////
}

