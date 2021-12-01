#include <stdio.h> //bibliotéca padrão
#include <math.h>  //bibliotéca para operações matemáticas

//REGISTRADORES DA IMAGEM COLORIDA
typedef struct 
{
	int ponto [3];
} Rgb;

typedef struct
{
	Rgb img [3][3];
} ColorImagem;

//REGISTRADORES DOS TONS DE CINZA
typedef struct
{
	int		val;
} Cin;
typedef struct
{
	Cin blwt [3][3];
}	CinzaImagem;

int VerificaVal (int valor)
{
	if (valor < 0 || valor > 255)
	{
		do
		{
			printf("Valor inválido, digite números ente 0 - 255: ");
			scanf("%d", &valor);
		} while (valor < 0 || valor > 255);
	}	//fim if

	return valor;
}	//Função que verifica se os valores estão entre 0 - 255

int VericaImgColor (int v)
{
	int x = 0;
	if (v != 1)
	{
		printf("Image colorida não registrada, favor registre ela antes de realizar essa operação!\n");
	}	//fim if
	else
	{
		x = 1;
	}
	return x;
}	//fim procedimento que verifica se a imgColor foi preeenchida

void TonsDeCinza (int  veri, ColorImagem imagem[3][3], CinzaImagem	c[3][3], int * verito)
{
	//VARIÁVEIS
	int				i, j, k;	//contadores
	int				calc = 0;	//calcula para conversão
	int				verif = 0;	//verificação
	
	//INÍCIO
	verif = VericaImgColor (veri);
	
	if (verif == 1)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				calc = 0; 
				for (k = 0; k < 3; k++)
				{
					calc = calc + imagem[i][j].img[i][j].ponto[k];
				}	//fim for
				c[i][j].blwt[i][j].val = (calc/3);
			}	//fim for
		}	//fim for
		printf("Cores convertidas com sucesso!\n\n");
		*verito = 1;
	}	//fim if
	
}	//converte imagem para cinza

void ColorizeImagem (int * veri, ColorImagem imagem[3][3])
{
	//VARIÁVEIS
	int				i, j, k;	//contadores
	
	//INÍCIO
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				printf("lin: %d, col: %d, ponto: %d -> ", i, j, k);
				scanf("%d", &imagem[i][j].img[i][j].ponto[k]);
				imagem[i][j].img[i][j].ponto[k] = VerificaVal (imagem[i][j].img[i][j].ponto[k]);
			}	//fim for
			printf("\n");
		}	//fim for
	}	//fim for
	
	*veri = 1;
}	//Montar a imagem colorida

void ImpriImg (int veri, ColorImagem imagem[3][3], CinzaImagem c[3][3], int verito)
{
	//VARIÁVEIS
	int				i, j, k;	//contadores
	int				verif = 0;	//verificação
	CinzaImagem		cinza;		//cinza
	ColorImagem		ima;		//imagem
	
	//INÍCIO
	verif = VericaImgColor (veri);
	
	if (verif == 1 && verito == 1)
	{
		//color
		printf("*** Imagem Colorida (R,G,B) ***\n");
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				for (k = 0; k < 3; k++)
				{
					printf("%d", imagem[i][j].img[i][j].ponto[k]);
					if (k < 2)
					{
						printf(", ");
					}	//fim if
				}	//fim for
				if (j < 2)
				{
					printf("| ");	
				}	//fim if
			}	//fim for
			printf("\n");
		}	//fim for
		
		printf("\n");
		
		//blwt
		printf("*** Imagem em Tons de Cinza ***\n");
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("%d", c[i][j].blwt[i][j].val);
				if (j < 2)
				{
					printf("| ");	
				}
			}	//fim for
			printf("\n");
		}	//fim for	
	}	//fim else
	else
	{
		printf("A conversão para tons de cinza não foi realizada!");
	}	//fim else
}

int VerificaSaida (int op)
{
	//VARIÁVEIS
	int ok;
	
	//INÍCIO
	do
	{
		printf("Tem certeza que deseja sair? (1 - sim, 0 - não)\nR: ");
		scanf("%d", &ok);	
	} while (ok != 1 && ok != 0);
	
	if (ok == 1)
	{
		op = 4;
	}
	else
	{
		op = 5;
	}	//fim if - else
	return op;
}	//fim da verificação do menu.

void Menu ()
{
	//VARIÁVEIS
	int op, veri = 0, verito = 0;
	ColorImagem imagem[3][3];
	CinzaImagem	cinza[3][3];
	//INÍCIO
	do
	{
		printf("1. Preencher a imagem colorida\n");
		printf("2. Transformar em Tons de Cinza\n");
		printf("3. Imprimir as 2 imagens\n");
		printf("4. Sair\nR: ");
		scanf("%d", &op);
		printf("\n");
		switch (op)
		{
				case 1:
					printf("Imagem colorida\n");
					ColorizeImagem (&veri, imagem);
				break;
				
				case 2:
					printf("Tons de Cinza\n");
					TonsDeCinza (veri, imagem, cinza, &verito);
				break;				

				case 3:
					printf("Impressão\n");
					ImpriImg (veri, imagem, cinza, verito);
					printf("\n");
				break;

				case 4:
					op = VerificaSaida (op);
					printf("\n");
				break;
				
				default:
					printf("Valor inválido!");
		}	//fim switch
	} while (op != 4);
}	//procedimento do menu

int main()
{
	//INÍCIO
	Menu();	
	
	printf("Fim do programa!");
	
	return 0;	
}	//Final main
