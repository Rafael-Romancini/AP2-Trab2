#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structs do programa */
typedef struct 
{
    char NomeProduto[30];
    float quantidadeVendas;
} Produto;

typedef struct
{
    char NomeFilial[50];
    Produto **MatrizProdutosTrimestre;
} Filial;

/* Variáveis Globais */
int QuantidadeProdutos = 0;
int QuantidadeFiliais = 0;
Produto ***CuboProdutos;
Filial *ListaFiliais;
char **listaNomeProdutos;
char **listaNomeFiliais;

/* Métodos do Cubo */

Produto*** AlocaCuboProdutos(int QuantidadeFiliais, int QuantidadeProdutos)
{
    Produto ***NovoCuboProdutos = (Produto ***)malloc(4 * sizeof(Produto **));
    if(NovoCuboProdutos == NULL) return NULL;

    for (int i = 0; i < 4; i++) {
        NovoCuboProdutos[i] = (Produto **)malloc(QuantidadeFiliais * sizeof(Produto *));
        if(NovoCuboProdutos[i] == NULL) return NULL;

        for (int j = 0; j < QuantidadeFiliais; j++) {
            NovoCuboProdutos[i][j] = (Produto *)malloc(QuantidadeProdutos * sizeof(Produto));
            if(NovoCuboProdutos[i][j] == NULL) return NULL;
        }
    }

    //CuboProdutos[TrimestreAno][Nº Filial][Nº Produto]
    return NovoCuboProdutos;
}

Filial* AlocaListaFiliais(int QuantidadeFiliais, Produto ***CuboProdutos)
{
    Filial *novaListaFiliais;
    novaListaFiliais = (Filial *)malloc(QuantidadeFiliais*sizeof(Filial));
    if(novaListaFiliais == NULL) return NULL;

    for(int i = 0; i < QuantidadeFiliais; i++)
    {
        novaListaFiliais[i].MatrizProdutosTrimestre = (Produto **)malloc(4 * sizeof(Produto*));
        for(int j = 0; j < 4; j++)
        {
            novaListaFiliais[i].MatrizProdutosTrimestre[j] = CuboProdutos[j][i];
        }
    }
    return novaListaFiliais;

    //ListaFiliais[Nº Filial].MatrizProdutosTrimestre[TrimestreAno][Nº Produto]
}

char** AlocaListaNomeProdutos(int QuantidadeProdutos)
{
    char **novaListaNomes = (char**)malloc(QuantidadeProdutos * sizeof(char*));
    if(novaListaNomes == NULL) return NULL;

    for(int i = 0; i < QuantidadeProdutos; i++)
    {
        novaListaNomes[i] = (char *)malloc(30 * sizeof(char));
        if(novaListaNomes[i] == NULL) return NULL;
    }
    return novaListaNomes;
}

char** AlocaListaNomeFiliais(int QuantidadeFiliais)
{
    char **novaListaNomes = (char**)malloc(QuantidadeFiliais * sizeof(char*));
    if(novaListaNomes == NULL) return NULL;

    for(int i = 0; i < QuantidadeFiliais; i++)
    {
        novaListaNomes[i] = (char *)malloc(50 * sizeof(char));
        if(novaListaNomes[i] == NULL) return NULL;
    }
    return novaListaNomes;
}

/* Métodos Menu */
void Headder(int qntProdutos, int qntFiliais)
{
    printf("\t*****************************************\n");
    printf("\t*\t\t\t\t\t*\n");
    printf("\t*\tSISTEMA DE GESTAO MARKET++\t*\n");
    printf("\t*\t\t\t\t\t*\n");
    printf("\t*****************************************\n");
    if(qntProdutos > 0 && qntFiliais > 0)
    {
        printf("\nProdutos:%d\n", qntProdutos);
        printf("Filiais:%d", qntFiliais);
    }
    printf("\n______________________________________________________\n");
}

void Erro(char msg[])
{
    system("cls");
    system("color 4F");
    printf("%s\n", msg);
}

int MenuInserir()
{
    int OpcaoMenu = 1;
    do
    {
        system("cls");
        Headder(QuantidadeProdutos,QuantidadeFiliais);
        printf("\n \t\t=== Menu Insercao ===\n\n");
        printf("1 - Inserir venda de um produto/trimestre\n");
        printf("2 - Inserir venda de um produto/filial\n");
        printf("3 - Inserir novo produto\n");
        printf("4 - Inserir nova filial\n");
        printf("5 - Sair\n");
        if(OpcaoMenu < 1 || OpcaoMenu > 5)
            printf("\nOpcao anterior invalida!\n");
        printf("\nSelecione uma opcao do menu: ");
        scanf(" %d", &OpcaoMenu);
    } while (OpcaoMenu < 1 || OpcaoMenu > 5);
    switch (OpcaoMenu)
    {
    case 1:
        printf("Implementar produto/trimestre\n");
        system("pause");
        break;
    case 2:
        printf("Implementar produto/filial\n");
        system("pause");
        break;
    case 3:
        printf("Implementar produto\n");
        system("pause");
        break;    
    case 4:
        printf("Implementar nova filial\n");
        system("pause");
        break;    
    default:
        return;
    }
}

int MenuRemover()
{
    int OpcaoMenu = 1;
    char resp = ' ';
    do
    {
        system("cls");
        Headder(QuantidadeProdutos,QuantidadeFiliais);
        printf("\n \t\t=== Menu Remocao ===\n\n");
        printf("1 - Remover Produto\n");
        printf("2 - Remover filial\n"); //Adicao
        printf("3 - Reiniciar todo o sistema (!)\n");
        printf("4 - Sair\n");
        if(OpcaoMenu < 1 || OpcaoMenu > 4)
            printf("\nOpcao anterior invalida!\n");
        printf("\nSelecione uma opcao do menu: ");
        scanf(" %d", &OpcaoMenu);
    } while (OpcaoMenu < 1 || OpcaoMenu > 4);
    switch (OpcaoMenu)
    {
    case 1:
        printf("Implementar Remover Produto\n");
        system("pause");
        break;
    case 2:
        printf("Implementar Remover filial\n");
        system("pause");
        break;
    case 3:
        system("cls");
        Headder(QuantidadeProdutos, QuantidadeFiliais);
        system("color 4f");
        printf("\n === ATENCAO === \n\n");
        printf("Deseja mesmo reiniciar todo o sistema? (s/n)\n");
        scanf(" %c", &resp);
        system("color 0f");
            if(resp == 's')
            {
            printf("Implementar Limpar Sistema\n");
            system("pause");
            }
        break; 
    default:
        return;
    }
}

int MenuRelatorios()
{
    int OpcaoMenu = 1;
    do
    {
        system("cls");
        Headder(QuantidadeProdutos,QuantidadeFiliais);
        printf("\n \t\t=== Menu Relatorios ===\n\n");
        printf("1 - Produto mais vendido por filial\n");
        printf("2 - Filial que mais vende produtos\n");
        printf("3 - Produto mais vendido\n");
        printf("4 - Filial que mais vende\n");
        printf("5 - Melhor trimestre\n");
        printf("6 - Sair\n");
        if(OpcaoMenu < 1 || OpcaoMenu > 6)
            printf("\nOpcao anterior invalida!\n");
        printf("\nSelecione uma opcao do menu: ");
        scanf(" %d", &OpcaoMenu);
    } while (OpcaoMenu < 1 || OpcaoMenu > 6);
    switch (OpcaoMenu)
    {
    case 1:
        printf("Produto mais vendido por filial\n");
        system("pause");
        break;
    case 2:
        printf("Filial que mais vende produtos\n");
        system("pause");
        break;    
    case 3:
        printf("Produto mais vendido\n");
        system("pause");
        break;    
    case 4:
        printf("Filial que mais vende\n");
        system("pause");
        break;    
    case 5:
        printf("Melhor trimestre\n");
        system("pause");
        break; 
    default:
        return;
    }
}

int MenuPrincipal()
{
    int OpcaoMenu = 1;
    do
    {
        system("cls");
        Headder(QuantidadeProdutos,QuantidadeFiliais);
        printf("\n \t\t=== Menu Principal ===\n\n");
        printf("1 - Inserir dados\n");
        printf("2 - Remover dados\n");
        printf("3 - Relatorios\n");
        printf("4 - Sair\n");
        if(OpcaoMenu < 1 || OpcaoMenu > 4)
            printf("\nOpcao anterior invalida!\n");
        printf("\nSelecione uma opcao do menu: ");
        scanf(" %d", &OpcaoMenu);
    } while (OpcaoMenu < 1 || OpcaoMenu > 4);   
    switch (OpcaoMenu)
    {
    case 1:
        MenuInserir();
        MenuPrincipal();
        break;
    case 2:
        MenuRemover();
        MenuPrincipal();
        break;
    case 3:
        MenuRelatorios();
        MenuPrincipal();
        break;    
    default:
        return;
    }
}

/* Métodos para inputs */

void LeituraQuantidadeFiliais()
{
    int validacao = 1;
    do {
        system("cls");
        Headder(0,0);
        if(!validacao)
        {
            printf("Numero anterior invalido!Digite novamente.\n");
        }
        validacao = 1;
        printf("Digite a quantidade de filiais: ");
        scanf(" %d", &QuantidadeFiliais);
        if(QuantidadeFiliais <= 0) validacao = 0;
    } while(!validacao);
}

void LeituraQuantidadeProdutos()
{
    int validacao = 1;
    do {
        system("cls");
        Headder(0,0);
        if(!validacao)
        {
            printf("Numero anterior invalido!Digite novamente.\n");
        }
        validacao = 1;
        printf("Digite a quantidade de produtos no catalogo: ");
        scanf(" %d", &QuantidadeProdutos);
        if(QuantidadeProdutos <= 0) validacao = 0;
    } while(!validacao);
}

void LeituraListaProdutos()
{
    for(int i = 0; i < QuantidadeProdutos; i++)
    {
        setbuf(stdin, 0);
        system("cls");
        Headder(QuantidadeProdutos,QuantidadeFiliais);
        printf("Digite o nome do produto %d: ", i+1);
        fgets(listaNomeProdutos[i],30,stdin);
    }
}

void LeituraNomeFiliais()
{
    for(int i = 0; i < QuantidadeFiliais; i++)
    {
        setbuf(stdin, 0);
        system("cls");
        Headder(QuantidadeProdutos,QuantidadeFiliais);
        printf("Digite o nome da Filial numero %d: ", i+1);
        fgets(listaNomeFiliais[i],50,stdin);
    }
}

void PreencherDadosCubo()
{
    //Preenchendo dados das filiais
    for(int i = 0; i < QuantidadeFiliais; i++)
    {
        strcpy(ListaFiliais[i].NomeFilial, listaNomeFiliais[i]);
        for(int j = 0; j < QuantidadeProdutos; j++)
        {
            strcpy(CuboProdutos[0][i][j].NomeProduto, listaNomeProdutos[j]);
            strcpy(CuboProdutos[1][i][j].NomeProduto, listaNomeProdutos[j]);
            strcpy(CuboProdutos[2][i][j].NomeProduto, listaNomeProdutos[j]);
            strcpy(CuboProdutos[3][i][j].NomeProduto, listaNomeProdutos[j]);
        }
    }
}

/* Metodos do programa - Organização */
int IniciarSistema()
{
    LeituraQuantidadeFiliais();
    LeituraQuantidadeProdutos();

    CuboProdutos = AlocaCuboProdutos(QuantidadeFiliais,QuantidadeProdutos);
    if(CuboProdutos == NULL)
    {
        Erro("Nao foi possivel alocar o cubo de produtos!");
        return 0;
    }

    ListaFiliais = AlocaListaFiliais(QuantidadeFiliais,CuboProdutos);
    if(ListaFiliais == NULL)
    {
        Erro("Nao foi possivel alocar a lista de produtos!");
        return 0;
    }

    listaNomeProdutos = AlocaListaNomeProdutos(QuantidadeProdutos);
    if(listaNomeProdutos == NULL)
    {
        Erro("Nao foi possivel alocar a lista de nome dos produtos!");
        return 0;
    }

    listaNomeFiliais = AlocaListaNomeFiliais(QuantidadeFiliais);
    if(listaNomeFiliais == NULL)
    {
        Erro("Nao foi possivel alocar a lista de nome dos produtos!");
        return 0;
    }

    LeituraListaProdutos();
    LeituraNomeFiliais();
    PreencherDadosCubo(CuboProdutos);
    return 1;
}

/* 

        ORDEM DE MANIPULAÇÃO DOS DADOS 
    CuboProdutos[TrimestreAno][Nº Filial][Nº Produto]
        - NomeProduto
        - quantidadeVendas
    
    ListaFiliais[Nº Filial]
        - NomeFiliai
        - MatrizProdutosTrimestre[TrimestreAno][Nº Produto]
            - NomeProduto
            - quantidadeVendas  
*/

int main()
{
    int ControleDeFluxo = 0;
    ControleDeFluxo = IniciarSistema();
    if(!ControleDeFluxo) return 0;

    MenuPrincipal();

    // Preenchendo o cubo com valores de exemplo
    // for (int t = 0; t < 4; t++) {
    //     for (int f = 0; f < QuantidadeFiliais; f++) {
    //         for (int p = 0; p < QuantidadeProdutos; p++) {
    //             snprintf(CuboProdutos[t][f][p].NomeProduto, 30, "Produto%d_T%d_F%d", p + 1, t + 1, f + 1);
    //             // CuboProdutos[t][f][p].ValorProduto = (p + 1) * (t + 1) * (f + 1) * 10.0; // Exemplo de valor
    //         }
    //     }
    // }

    // Acesso aos dados do cubo
    printf("DEBUG CuboProdutos[0][0][0].NomeProduto: %s\n", CuboProdutos[0][0][0].NomeProduto);
    printf("DEBUG ListaFiliais[0].NomeFilial: %s\n", ListaFiliais[0].NomeFilial);

    return 0;
}