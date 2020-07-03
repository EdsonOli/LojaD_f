
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <locale.h>

#define tam_n 50//tamanho para string de nome
#define tam_l 20//tamanho para vetor de lista

//base para geraÃ§Ã£o de ID
int U_ID = 1000;

//Contadores dos vetores
int contEstDiscos = 0;
int contEstCamisas = 0;
int contFornecedores = 0;
int contClientes = 0;
int contVendas = 0;
int contFuncionarios = 2;

//permiÃ§Ãµes de login
int permicao = 0;
int IDF = 0;

//Data
int sDia;
int sMes;
int sAno;

//Valores de inicialisaÃ§Ã£o para os vetores
int Ldiscos = 20;
int Lcamisas = 20;
int Lfornecedores = 20;
int Lfuncionarios = 20;
int Lclientes = 20;
int Lvendas = 20;

//InformaÃ§Ãµes de lucro;
float lucro;
float divida;
float desconto = 0.75;

//lixo

char lixo[tam_n];


//Estruturas
typedef struct
{
    char CEP[10];
    char rua[tam_n];
    int numero;
    char bairro[tam_n];
    char cidade[tam_n];
    char estado[tam_n];
} Endereco;

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    char email[tam_n];
    char tel[tam_l];
} Contato;


typedef struct
{
    char nome[tam_n];
    char estiloMusical[tam_l];
    char nomeArtista[tam_n];
    int ano;
    int ID;
    float preco;
    float precoAtacado;
    int quantidadeEstoque;
    int IDfornecedor;
} Disco;

typedef struct
{
    char nome[tam_n];
    int ID;
    char tamanho[2];
    float preco;
    float precoAtacado;
    int quantidadeEstoque;
    int IDfornecedor;

} Camisa;

typedef struct
{
    char nomeDaEmpresa[tam_n];
    int cnpj;
    Endereco end;
    Data dataDoContrato;
    Contato contato;
    int ID;
} Fornecedor;

typedef struct
{
    char nome[tam_n];
    char login[15];
    char senha[15];
    int ID;
    int tipo;
} Usuario;

typedef struct
{
    char nome[tam_n];
    float preco;
    char tipo[tam_l];
} Produto;


typedef struct
{
    Produto produto[10];
    Data data;
    float total;
    int ID_Vendedor;
    char CPF_Cliente[tam_l];
} Venda;

typedef struct
{
    char nome[tam_n];
    Endereco end;
    char CPF[tam_l];
    //Data dataDoCadastro;
    Data dataDeNas;
    int ID;
    int quant_de_comp;
} Cliente;

typedef struct
{
    int IDproduto;
    Cliente cliente;
    Usuario vendedor;
    Data data;
    int status;
} Encomenda;

//FunÃ§Ãµes genÃ©ricas

void CadEndereco(Endereco *e)
{
    printf("CEP:");
    fgets(e->CEP, tam_l, stdin);
    printf("Rua: ");
    fgets(e[0].rua, tam_n, stdin);
    printf("Numero: ");
    scanf("%i", &e[0].numero);
    getchar();
    printf("Bairro: ");
    fgets(e[0].bairro, tam_n, stdin);
    printf("Cidade: ");
    fgets(e[0].cidade, tam_n, stdin);
    printf("Estado: ");
    fgets(e[0].estado, tam_n, stdin);

}

void CadData(Data *d)
{
    printf("Dia: ");
    scanf("%i", &d[0].dia);
    printf("MÃªs: ");
    scanf("%i", &d[0].mes);
    printf("Ano: ");
    scanf("%i", &d[0].ano);
    getchar();
}

void CadContato(Contato *c)
{
    printf("Telefone: ");
    fgets(c[0].tel, tam_l, stdin);
    printf("E-mail: ");
    fgets(c[0].email, tam_n, stdin);


}


void Cabecalho()
{
    system("cls");

    printf("\n\n=======================================\n");
    printf("===================LojaD===============\n");
    printf("=======================================\n\n");
};

int GeraID(int n)
{
    int ID = n;
    ID++;
    U_ID = ID;
    return ID;
}

void CadDataSist(Data *d)
{
    d->dia = sDia;
    d->mes = sMes;
    d->ano = sAno;
}


//FunÃ§Ãµes de cadastro

void CadDisco(Disco *d, int i)
{
    Cabecalho();
    int alx;
    printf("Novo cadastro!");
    getchar();
    printf("\nNome: ");
    fgets(d[i].nome, tam_n, stdin);
    printf("Artista: ");
    fgets(d[i].nomeArtista, tam_n, stdin);
    d[i].ID = GeraID(U_ID);
    printf("Ano de lanÃ§amento: ");
    scanf("%i", &d[i].ano);
    printf("PreÃ§o: ");
    scanf("%f", &d[i].preco);

    int sair = 1;
    do
    {
        printf("\nEstilo Musical:\n1-Rock\n2-Pop\n3-Religiosa\n4-ForrÃ³\n5-MPB\n6-Jazz\n");
        scanf("%i", &alx);
        getchar();

        switch (alx)
        {

        case 1:
            strcpy(d[i].estiloMusical, "Rock");
            sair = 0;
            break;
        case 2:
            strcpy(d[i].estiloMusical, "Pop");
            sair = 0;
            break;
        case 3:
            strcpy(d[i].estiloMusical, "Religiosa");
            sair = 0;
            break;
        case 4:
            strcpy(d[i].estiloMusical, "ForrÃ³");
            sair = 0;
            break;
        case 5:
            strcpy(d[i].estiloMusical, "MPB");
            sair = 0;
            break;
        case 6:
            strcpy(d[i].estiloMusical, "Jazz");
            sair = 0;
            break;
        default:
            printf("\nOpÃ§Ã£o invÃ¡lida!\n");
            break;
        }
    }
    while(sair!=0);

    printf("\nPreÃ§o compra: ");
    scanf("%f", &d[i].precoAtacado);
    printf("Quantidade em Estoque: ");
    scanf("%i", &d[i].quantidadeEstoque);
    printf("ID Fornecedor: ");
    scanf("%i", &d[i].IDfornecedor);
    getchar();
    contEstDiscos++;

    if(contEstDiscos >= Ldiscos - 10)
    {
        d = realloc(d, (Ldiscos + 10) * sizeof(d));
        Ldiscos += 10;
    }


}

void CadCami(Camisa *c, int i)
{
    Cabecalho();
    printf("Novo produto!");
    getchar();
    printf("\nNome: ");
    fgets(c[i].nome, tam_n, stdin);
    printf("Tamanho: ");
    fgets(c[i].tamanho, 2, stdin);
    getchar();
    printf("PreÃ§o: ");
    scanf("%f", &c[i].preco);
    c[i].ID = GeraID(U_ID);
    printf("PreÃ§o de Atacado: ");
    scanf("%f", &c[i].precoAtacado);
    printf("Quantidade em Estoque: ");
    scanf("%i", &c[i].quantidadeEstoque);
    printf("ID Fornecedor: ");
    scanf("%i", &c[i].IDfornecedor);

    if(contEstCamisas >= Lcamisas - 10)
    {
        c = realloc(c, (Lcamisas + 20) * sizeof(c));
        Lcamisas += 20;
    }

    contEstCamisas++;
}


void CadFornecedor(Fornecedor *f, int i)
{

    Cabecalho();
    printf("Novo fornecedor");
    getchar();
    printf("\nNome: ");
    fgets(f[i].nomeDaEmpresa, tam_n, stdin);
    printf("CNPJ: ");
    scanf("%i", &f[i].cnpj);
    CadEndereco(&f[i].end);
    CadData(&f[i].dataDoContrato);
    CadContato(&f[i].contato);
    f[i].ID = GeraID(U_ID);
    if(contEstDiscos >= Ldiscos - 10)
    {
        f = realloc(f, (Lfornecedores + 10) * sizeof(f));
        Lfornecedores += 10;
    }

    contFornecedores++;
}

void CadCliente(Cliente *cl, int i)
{
    char CPF[tam_l];
    int cont = 0;
    int tam = 0;
    int comp;
    int j = contClientes;
    getchar();
    printf("\nCPF: ");
    fgets(CPF, 12, stdin);
    tam = strlen(CPF);
    int k;
    for (k = 0; k < j; k++)
    {
        comp = strncmp(cl[k].CPF, CPF, tam);
        if(comp == 0)
        {
            printf("CPF jÃ¡ cadastrado!");
            getch();
            k = j;
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("%s", CPF);
        getchar();
        printf("\nNome: ");
        fgets(cl[i].nome, tam_n, stdin);
        getchar();
        strcpy(cl[i].CPF, CPF);
        CadEndereco(&cl[i].end);
        printf("Data de nascimento: \n");
        CadData(&cl[i].dataDeNas);
        //CadDataSist(&cl[i].dataDoCadastro);
        cl[i].ID = GeraID(U_ID);
        cl[i].quant_de_comp = 0;
        contClientes ++;
    }
    if(contClientes >= Lclientes - 10)
    {
        cl = realloc(cl, (Lclientes + 10) * sizeof(cl));
        Lclientes += 10;
    }

}

void CadFuncionario(Usuario *u, int i)
{
    getchar();
    printf("\nNome: ");
    fgets(u[i].nome, tam_n, stdin);
    printf("\nLogin: ");
    fgets(u[i].login, 15, stdin);
    printf("\nSenha (nÃ£o pode ter mais que 8 caracteres): ");
    fgets(u[i].senha, 7, stdin);
    u[i].ID = GeraID(U_ID);
    printf("\nTipo: ");
    scanf("%i", &u[i].tipo);
    contFuncionarios++;
    if(contFuncionarios >= Lfuncionarios - 10)
    {
        u = realloc(u, (Lfuncionarios + 10) * sizeof(u));
        Lfuncionarios += 10;
    }

}


//Funï¿½ï¿½es mostrar


void MostData(Data *d)
{
    printf("Data: %i/%i/%i", d[0].dia, d[0].mes, d[0].ano);
}

void MostEnd(Endereco *e, int i)
{
    printf("Rua: %s", e[0].rua);
    printf("Bairro: %s", e[0].bairro);
    printf("Numero: %i", e[0].numero);
    printf("Cidade: %s", e[0].cidade);
    printf("CEP: %s", e[0].CEP);
}


void MostDiscoE(Disco *d, int i)
{
    printf("\n===============================================\n");
    printf("Nome: %s", d[i].nome);
    printf("Ano: %i",  d[i].ano);
    printf("\nArtista: %s", d[i].nomeArtista);
    printf("Estilo: %s", d[i].estiloMusical);
    printf("\nPreÃ§o de Venda: %.2f", d[i].preco);
    printf("\nID: %i", d[i].ID);
    printf("\nPreÃ§o de Compra: %.2f", d[i].precoAtacado);
    printf("\nQuantidade em estoque: %i", d[i].quantidadeEstoque);
    printf("\n===============================================\n");
}

void MostVetDisc(Disco *d, int cont)
{
    int i;
    for(i = 0; i < cont; i++)
    {
        MostDiscoE(d, i);
    }
    getch();
}

void MostCamisa(Camisa *c, int i)
{
    printf("\n===================================\n");
    printf("Camisa: %s", c[i].nome);
    printf("Tamanho: %s", c[i].tamanho);
    printf("\nPreÃ§o: %.2f\n", c[i].preco);
    printf("PreÃ§o de Compra: %.2f\n", c[i].precoAtacado);
    printf("Quantidade em Estoque: %i", c[i].quantidadeEstoque);
    printf("\n===================================\n");
}
void MostVetCamisa(Camisa *c, int i)
{
    int j;
    for(j = 0; j < i; j++)
    {
        MostCamisa( c, j);
    }
    getch();
}

void MostCliente(Cliente *cl, int i)
{
    printf("\n===============================================\n");
    printf("Nome: %s", cl[i].nome);
    printf("CPF: %s", cl[i].CPF);
    printf("\nData de Nascimento: %i/ %i/ %i", cl[i].dataDeNas.dia, cl[i].dataDeNas.mes, cl[i].dataDeNas.ano);
    printf("\nEndere?o:\nCEP: %sRua: %sNumero: %i\nBairro: %sCidade: %sEstado: %s", cl[i].end.CEP, cl[i].end.rua, cl[i].end.numero, cl[i].end.bairro, cl[i].end.cidade, cl[i].end.estado);
    printf("ID: %i", cl[i].ID);
    //printf("\nData do cadastro: %i/%i/%i", cl[i].dataDoCadastro. dia, cl[i].dataDoCadastro.mes, cl[i].dataDoCadastro.ano);
    printf("\nQuantidade de compras: %i", cl[i].quant_de_comp);
    printf("\n===============================================\n");
}

void MostVetCliente(Cliente *cl, int cont)
{
    int i;
    for(i = 0; i < cont; i++)
    {
        MostCliente(cl, i);
    }
    getch();
}

void MostFuncionario(Usuario *u, int i)
{
    printf("\n===============================================\n");
    printf("Nome: %s", u[i].nome);
    printf("Login: %s", u[i].login);
    printf("ID: %i\n", u[i].ID);
    printf("Tipo: %i", u[i].tipo);
    printf("\n===============================================\n");
}

void MostVetFuncionario(Usuario *u, int cont)
{
    int i;
    for(i = 0; i < cont; i++)
    {
        MostFuncionario(u, i);
    }
    getch();
}

void MostFornecedor(Fornecedor *f, int i)
{
    printf("\n===============================================\n");
    printf("Nome: %s", f[i].nomeDaEmpresa);
    printf("CNPJ: %i", f[i].cnpj);
    printf("Endere?o:\nCEP: %sRua: %s\nNï¿½mero: %i\nBairro: %sCidade: %sEstado: %s", f[i].end.CEP, f[i].end.rua, f[i].end.numero, f[i].end.bairro, f[i].end.cidade, f[i].end.estado);
    printf("Data de Contrato: %i/ %i/ %i", f[i].dataDoContrato.dia, f[i].dataDoContrato.mes, f[i].dataDoContrato.ano);
    printf("Contato\nTelefone: %sE-mail:%s", f[i].contato.tel, f[i].contato.email);
    printf("ID: %i", f[i].ID);
    printf("\n===============================================\n");
}

void MostVetForncedor(Fornecedor *f, int cont)
{
    int i;
    for(i = 0; i < cont; i++)
    {
        MostFornecedor(f, i);
    }
    getch();
}

//Funï¿½ï¿½es arquivos

void AbreVariaveis()
{

    FILE *va = fopen("VariaveisGlobais.txt", "r");
    if(va != NULL)
    {
        fscanf(va, "%i %i %i %i %i %i %i %i %i %i %i %i %i %f %f", &contVendas, &contClientes, &contEstDiscos, &contEstCamisas, &contFornecedores, &contFuncionarios, &Ldiscos, &Lvendas, &Lcamisas, &Lclientes, &Lfornecedores, &Lfuncionarios, &U_ID, &lucro, &divida);
    }

    if(va == NULL)
    {
        va = fopen("VariaveisGlobais.txt", "w");
    }

    fclose(va);

}


void FechaVariaveis()
{
    FILE *va = fopen("VariaveisGlobais.txt", "w");
    if(va == NULL)
    {
        printf("Erro de registro!");
    }

    fprintf(va, "%i %i %i %i %i %i %i %i %i %i %i %i %i %f %f", contVendas, contClientes, contEstDiscos, contEstCamisas, contFornecedores, contFuncionarios, Ldiscos, Lvendas, Lcamisas, Lclientes, Lfornecedores, Lfuncionarios, U_ID, lucro, divida);
    fclose(va);

}


void AbreArquivo(Disco *d, Camisa *c, Cliente *cl, Usuario *fu, Fornecedor *fo, Venda *v)
{
    FILE *fd, *fc, *fcl, *ffu, *ffo, *fv;
    fd = fopen("estoqueDeDiscos.txt", "rb");
    if(fd == NULL)
    {
        fd = fopen("estoqueDeDiscos.txt", "wb");
    }

    fc = fopen("estoqueDeCamisas.txt", "rb");
    if(fc == NULL)
    {
        fc = fopen("estoqueDeCamisas.txt", "wb");
    }

    fcl = fopen("listaClientes.txt", "rb");
    if(fcl == NULL)
    {
        fcl = fopen("listaClientes.txt", "wb");
    }

    ffu = fopen("listaDeFuncionarios.txt", "rb");
    if(ffu == NULL)
    {
        ffu = fopen("listaDeFuncionarios.txt", "wb");
    }

    ffo = fopen("listaDeFornecedores.txt", "rb");
    if(ffo == NULL)
    {
        ffo = fopen("listaDeFornecedores.txt", "wb");
    }

    fv = fopen("listaDeVendas.txt", "rb");
    if(fv == NULL)
    {
        fv = fopen("listaDeVendas.txt", "wb");
    }

    fread(d, sizeof(Disco), contEstDiscos, fd);
    fread(c, sizeof(Camisa), contEstCamisas, fc);
    fread(cl, sizeof(Cliente), contClientes, fcl);
    fread(fu, sizeof(Usuario), contFuncionarios, ffu);
    fread(fo, sizeof(Fornecedor), contFornecedores, ffo);
    fread(v, sizeof(Venda), contVendas, fv);

    fclose(fd);
    fclose(fc);
    fclose(fcl);
    fclose(ffu);
    fclose(ffo);
    fclose(fv);

}

void FechaArquivo(Disco *d, Camisa *c, Cliente *cl, Usuario *fu, Fornecedor *fo, Venda *v)
{
    FILE *fd, *fc, *fcl, *ffu, *ffo, *fv;
    fd = fopen("estoqueDeDiscos.txt", "wb");
    if(fd == NULL)
    {
        printf("Erro no arquivamento!");
    }

    fc = fopen("estoqueDeCamisas.txt", "wb");
    if(fc == NULL)
    {
        printf("Erro no arquivamento!");
    }

    fcl = fopen("listaClientes.txt", "wb");
    if(fcl == NULL)
    {
        printf("Erro no arquivamento!");
    }

    ffu = fopen("listaDeFuncionarios.txt", "wb");
    if(ffu == NULL)
    {
        printf("Erro no arquivamento!");
    }

    ffo = fopen("listaDeFornecedores.txt", "wb");
    if(ffo == NULL)
    {
        printf("Erro no arquivamento!");
    }

    fv = fopen("listaDeVendas.txt", "wb");
    if(fv == NULL)
    {
        printf("Erro no arquivamento!");
    }

    if(fwrite(d, sizeof(Disco), contEstDiscos, fd) != contEstDiscos)
    {
        printf("Erro de armazenamento");
    }
    fwrite(c, sizeof(Camisa), contEstCamisas, fc);
    fwrite(cl, sizeof(Cliente), contClientes, fcl);
    fwrite(fu, sizeof(Usuario), contFuncionarios, ffu);
    fwrite(fo, sizeof(Fornecedor), contFornecedores, ffo);
    fwrite(v, sizeof(Venda), contVendas, fv);

    fclose(fd);
    fclose(fc);
    fclose(fcl);
    fclose(ffu);
    fclose(ffo);
    fclose(fv);

}

//Funï¿½ï¿½es de busca

int BuscDisco(Disco *d)
{
    Cabecalho();
    int opc, comp, tam;
    int cont = 0;
    int i, indice;
    char nomeD[tam_n];
    printf("\n1-Nome\n2-Estilo\n3-Artista\n4-ID\n5-Sair\n");
    scanf("%i", &opc);
    switch(opc)
    {
    case 1:
        getchar();
        printf("\nNome: ");
        fgets(nomeD, tam_n,stdin);
        tam = strlen(nomeD);

        for(i = 0; i < contEstDiscos; i++)
        {
            comp = strncmp(nomeD, d[i].nome, tam);
            if(comp == 0)
            {
                MostDiscoE(d, i);
                cont++;
                indice = i;
            }
        }
        getch();
        if(cont == 0)
        {
            printf("\nDisco n?o encontrado!\n");
            getch();
            return -1;
        }
        else if(cont > 0)
        {
            return indice;
        }
        break;

    case 2:

        getchar();
        printf("\nEstilo: ");
        fgets(nomeD, tam_n,stdin);
        tam = strlen(nomeD);

        if(nomeD[tam - 1] == '\n')
        {
            nomeD[tam - 1] = '\0';
        }
        int i;
        for(i = 0; i < contEstDiscos; i++)
        {
            comp = strncmp(nomeD, d[i].nome, tam);
            if(comp == 0)
            {
                MostDiscoE(d, i);
                cont++;
                indice = i;
            }
        }
        getch();
        if(cont == 0)
        {
            printf("\nDisco nÃ£o encontrado!\n");
            getch();
            return -1;
        }
        if(cont > 0)
        {
            return indice;
        }

        break;


    case 3:
        getchar();
        printf("\nArtista: ");
        fgets(nomeD, tam_n,stdin);
        tam = strlen(nomeD);

        int j;
        for(j = 0; j < contEstDiscos; j++)
        {
            comp = strncmp(nomeD, d[j].nomeArtista, tam);
            if(comp == 0)
            {
                MostDiscoE(d, j);
                cont++;
                indice = j;
            }
        }
        getch();
        if(cont == 0)
        {
            printf("\nDisco nÃ£o encontrado!\n");
            return -1;
        }
        getch();
        if(cont > 0)
        {
            return indice;
        }

        break;
    case 4:
        getchar();
        printf("\nID: ");
        scanf("%i", &comp);

        int k;
        for(k = 0; k < contEstDiscos; k++)
        {
            if(comp == d[k].ID)
            {
                MostDiscoE(d, k);
                cont++;
                indice = k;
            }
        }
        getch();
        if(cont == 0)
        {
            printf("Disco nÃ£o encontrado!");
            return -1;
        }
        getch();
        if(cont > 0)
        {
            return indice;
        }
        break;
    case 5:
        break;
    default:
        printf("OpÃ§Ã£o invÃ¡lida!");
        getch();
        break;
    }

}

int BuscarCami(Camisa *d)
{
    Cabecalho();
    int opc, comp, tam;
    int cont = 0;
    int i, indice;
    char nomeD[tam_n];
    printf("\n1-Nome\n2-Tamanho\n3-ID\n4-Sair\n");
    scanf("%i", &opc);
    switch(opc)
    {
    case 1:
        getchar();
        printf("\nNome: ");
        fgets(nomeD, tam_n,stdin);
        tam = strlen(nomeD);

        for(i = 0; i < contEstCamisas; i++)
        {
            comp = strncmp(nomeD, d[i].nome, tam);
            if(comp == 0)
            {
                MostCamisa(d, i);
                cont++;
                indice = i;
            }
        }
        getch();
        if(cont == 0)
        {
            printf("\nProduto nÃ£o encontrado!\n");
            getch();
            return -1;
        }
        else if(cont > 0)
        {
            return indice;
        }
        break;

    case 2:

        getchar();
        printf("\nTamanho: ");
        fgets(nomeD, tam_n,stdin);
        tam = strlen(nomeD);

        if(nomeD[tam - 1] == '\n')
        {
            nomeD[tam - 1] = '\0';
        }
        int i;
        for(i = 0; i < contEstCamisas; i++)
        {
            comp = strncmp(nomeD, d[i].nome, tam);
            if(comp == 0)
            {
                MostCamisa(d, i);
                cont++;
                indice = i;
            }
        }
        getch();
        if(cont == 0)
        {
            printf("\nProduto nÃ£o encontrado!\n");
            getch();
            return -1;
        }
        if(cont > 0)
        {
            return indice;
        }

        break;


    case 3:
        getchar();
        printf("\nID: ");
        scanf("%i", &comp);

        int c;
        for(c = 0; c < contEstCamisas; c++)
        {
            if(comp == d[c].ID)
            {
                MostCamisa(d, c);
                cont++;
                indice = c;
            }
        }
        getch();
        if(cont == 0)
        {
            printf("Produto nÃ£o encontrado!");
            return -1;
        }
        getch();
        if(cont > 0)
        {
            return indice;
        }
        break;
    case 4:
        break;
    default:
        printf("OpÃ§Ã£o invÃ¡lida!");
        getch();
        break;
    }

}

int BuscCliente(Cliente *cl)
{
    Cabecalho();
    int indice;
    int cont, tam = 0;
    int comp;
    char CPF[tam_l];
    getchar();
    printf("\nDigite o CPF: ");
    fgets(CPF, 12, stdin);
    tam = strlen(CPF);
    if(CPF[tam-1] == "\n")
    {
        CPF[tam-1] = "\0";
    }
    int k;
    for (k = 0; k < contClientes; k++)
    {
        comp = strcmp(cl[k].CPF, CPF);
        if(comp == 0)
        {
            MostCliente(cl, k);
            cont++;
            indice = k;
        }
    }
    getch();
    if(cont == 0)
    {
        printf("Cliente nÃ£o cadastrado!");
        getch();
        return -1;
    }
    else
    {
        return indice;
    }
}

int BuscFornecedor(Fornecedor *f)
{
    Cabecalho();
    int id, indice;
    int cont = 0;
    printf("\nDigite o ID: ");
    scanf("%i", &id);

    int k;
    for (k = 0; k < contFornecedores; k++)
    {
        if(f[k].ID == id)
        {
            MostFornecedor(f, k);
            cont ++;
            indice = k;
        }
    }
    if(cont == 0)
    {
        printf("Fornecedor nÃ£o cadastrado!");
        return -1;
    }
    else
    {
        return indice;
    }
}

int BuscFuncionario(Usuario *u)
{
    Cabecalho();
    int id, indice;
    int cont = 0;
    printf("\nDigite o ID: ");
    scanf("%i", &id);

    int k;
    for (k = 0; k < contFuncionarios; k++)
    {
        if(u[k].ID == id)
        {
            MostFuncionario(u, k);
            cont ++;
            indice = k;
        }
    }
    if(cont == 0)
    {
        printf("Funcionï¿½rio nao cadastrado!");
        return -1;
    }
    else
    {
        return indice;
    }
}


//Funï¿½ï¿½es de apagar

void ApagarDisco(Disco *d, int j)
{
    int indice;
    indice = BuscDisco(d);
    printf("\n%i\n", indice);

    if(indice >= 0)
    {
        int i;
        for(i = indice; i < j-1; i++)
        {
            d[i].ano = d[i+1].ano;
            strcpy(d[i].nome, d[i+1].nome);
            strcpy(d[i].nomeArtista, d[i+1].nomeArtista);
            strcpy(d[i].estiloMusical, d[i+1].estiloMusical);
            d[i].ID = d[i+1].ID;
            d[i].IDfornecedor = d[i+1].IDfornecedor;
            d[i].quantidadeEstoque = d[i+1].quantidadeEstoque;
            d[i].preco = d[i+1].preco;
            d[i].precoAtacado = d[i+1].precoAtacado;
        }
        contEstDiscos-=1;
        MostVetDisc(d, j);
        getch();
    }
    else
    {
        printf("\nTente novamente!\n");
    }
}

void ApagarCamisa(Camisa *d, int j)
{
    int indice;
    indice = BuscarCami(d);
    printf("\n%i\n", indice);

    if(indice >= 0)
    {
        int i;
        for(i = indice; i < j-1; i++)
        {
            strcpy(d[i].nome, d[i+1].nome);
            strcpy(d[i].tamanho, d[i+1].tamanho);
            d[i].ID = d[i+1].ID;
            d[i].IDfornecedor = d[i+1].IDfornecedor;
            d[i].quantidadeEstoque = d[i+1].quantidadeEstoque;
            d[i].preco = d[i+1].preco;
            d[i].precoAtacado = d[i+1].precoAtacado;
        }
        contEstCamisas-=1;
        MostVetCamisa(d, j);
        getch();
    }
    else
    {
        printf("\nTente novamente!\n");
    }
}


int ApagarCliente (Cliente *cl, int k)
{
    int indice;
    indice = BuscCliente(cl);
    printf("\n%i", indice);

    int i;
    for(i = indice; i < k-1; i++)
    {
        strcpy(cl[i].nome, cl[i+1].nome);
        strcpy(cl[i].CPF, cl[i+1].CPF);
        strcpy(cl[i].end.bairro, cl[i+1].end.bairro);
        strcpy(cl[i].end.CEP, cl[i+1].end.CEP);
        strcpy(cl[i].end.cidade, cl[i+1].end.cidade);
        strcpy(cl[i].end.estado, cl[i+1].end.estado);
        strcpy(cl[i].end.rua, cl[i+1].end.rua);
        cl[i].end.numero = cl[i+1].end.numero;
        cl[i].dataDeNas = cl[i+1].dataDeNas;
        // cl[i].dataDoCadastro = cl[i+1].dataDoCadastro;
        cl[i].ID = cl[i+1].ID;
        cl[i].quant_de_comp = cl[i+1].quant_de_comp;
        contClientes-=1;
        getch();
    }
}

int ApagarFornecedor (Fornecedor *f, int k)
{
    int indice;
    indice = BuscFornecedor(f);
    printf("\n%i", indice);

    int i;
    for(i = indice; i < k-1; i++)
    {
        strcpy(f[i].nomeDaEmpresa, f[i+1].nomeDaEmpresa);
        f[i].cnpj = f[i+1].cnpj;
        f[i].end = f[i+1].end;
        f[i].dataDoContrato = f[i+1].dataDoContrato;
        f[i].contato = f[i+1].contato;
        f[i].ID  = f[i+1].ID ;

        contFornecedores-=1;
        getch();
    }
}

int ApagarFuncionario (Usuario *u, int k)
{
    int indice;
    indice = BuscFuncionario(u);
    printf("\n%i", indice);

    int i;
    for(i = indice; i < k-1; i++)
    {
        strcpy(u[i].nome, u[i+1].nome);
        strcpy(u[i].login, u[i+1].login);
        strcpy(u[i].senha, u[i+1].senha);
        u[i].ID  = u[i+1].ID ;
        u[i].tipo = u[i+1].tipo;

        contFuncionarios-=1;
        getch();
    }
}


//login

int Login(Usuario *u)
{
    char login[15];
    int cont, cont2, cont3 = 0;
    char senha[8];
    printf("\nLogin: ");
    fgets(login, 15, stdin);
    cont = strlen(login);
    if(login[cont - 1] == '\n')
    {
        login[cont - 1] = '\0';
    }
    printf("\nSenha: ");
    fgets(senha, 8, stdin);
    cont = strlen(senha);
    if(senha[cont - 1] == '\n')
    {
        senha[cont - 1] = '\0';
    }

    int i;
    for(i = 0; i < contFuncionarios; i++)
    {
        if((strcmp(login, u[i].login) == 0) && (strcmp(senha, u[i].senha) == 0))
        {
            permicao = u[i].tipo;
            IDF = u[i].ID;
            cont2++;
            return 0;
        }
    }
    if(cont2 == 0)
    {
        printf("\nUsuÃ¡rio ou senha nÃ£o encontrados!\n");
        return 1;
    }
}
//Vendas
int VendCalc(float *tV, float *tG, float *desc, int *cont, int i, Cliente *cl)
{
    float alx;
    float troco = 0;

    if((*cont + cl[i].quant_de_comp) >= 5)
    {
        *tV *= *desc;
        printf("\nTotal: %.2f\n", *tV);
        getch;
        printf("Pago: ");
        scanf("%f", &alx);
        {
            troco = (alx - *tV);
        }
        printf("\nTroco: %.2f\n", troco);
        getch;
    }
    else
    {
        printf("\nTotal: %.2f\n", *tV);
        getch;
        printf("Pago: ");
        scanf("%f", &alx);
        {
            troco = (alx - *tV);
        }
        printf("\nTroco: %.2f\n", troco);
        getch;

    }
    lucro += *tV;
    divida += *tG;
    return 1;
}

int VendCalc_sc(float *tV, float *tG)
{
    float alx;
    float troco = 0;

    printf("\nTotal: %.2f\n", *tV);
    getch;
    printf("Pago: ");
    scanf("%f", &alx);
    {
        troco = (alx - *tV);
    }
    printf("\nTroco: %.2f\n", troco);
    getch;
    lucro += *tV;
    divida += *tG;
    return 1;
}


void Vendas(Venda *ve, Disco *d, Camisa *c, Usuario *f, Cliente *cl)
{
    int i1,i2,i3;
    int opc1, opc2, opc4, opc5;
    char opc3;
    char CPF[tam_l];
    int sair1, sair2 = 1;
    int cont = 0;
    float total_venda = 0;
    float total_gasto = 0;
    float Desc_venda = desconto;
    int vendido = 0;

    do
    {
        Cabecalho();
        printf("\nProduto:\n1-Exibir Produtos\n2-Venda de Disco\n3-Venda de Camisa\n4-Finalizar Compra\n");
        scanf("%i", &sair1);
        switch(sair1)
        {
        case 1:
            printf("\n==========================CAMISAS==========================\n");
            MostVetCamisa(c, contEstCamisas);
            getch();
            printf("\n===========================DISCOS==========================\n");
            MostVetDisc(d, contEstDiscos);
            getch();
            break;
        case 2:
            i1 = BuscDisco(d);
            if(i1 >= 0)
            {
                strcpy(ve[contVendas].produto[cont].nome, d[i1].nome);
                ve[contVendas].produto[cont].preco = d[i1].preco;
                strcpy(ve[contVendas].produto[cont].tipo, "Disco");
                total_venda += d[i1].preco;
                total_gasto += d[i1].precoAtacado;
                d[i1].quantidadeEstoque -= 1;
                cont++;
            }
            break;
        case 3:
            i2 = BuscarCami(c);
            if(i2 >= 0)
            {
                strcpy(ve[contVendas].produto[cont].nome, c[i2].nome);
                ve[contVendas].produto[cont].preco = c[i2].preco;
                strcpy(ve[contVendas].produto[cont].tipo, "Camisa");
                total_venda += c[i2].preco;
                total_gasto += c[i2].precoAtacado;
                c[i2].quantidadeEstoque -= 1;
                cont++;
            }

            break;
        case 4:
            break;
        default:
            printf("OpÃ§Ã£o InvÃ¡lida");
            break;
        }
    }
    while (sair1!=4);

    do
    {
        getchar();
        printf("\nO cliente possui cadastro?(s/n)\n");
        scanf("%c", &opc3);
        switch (opc3)
        {
        case 's':
            i3 = BuscCliente(cl);
            if(i3>=0)
            {
                cl[i3].quant_de_comp += cont;
                vendido = VendCalc(&total_venda, &total_gasto, &Desc_venda, &cont, i3, cl);
                strcpy(CPF, cl[i3].CPF);
            }
            else
            {
                printf("Cliente nÃ£o cadastrado!");
            }
            break;
        case 'n':
            printf("\n1-Cadastrar novo cliente\n2-Compra sem Cadastro\n");
            scanf("%i", &opc4);
            switch (opc4)
            {
            case 1:
                CadCliente(cl, contClientes);
                break;
            case 2:
                vendido = VendCalc_sc(&total_venda, &total_gasto);
                break;
            default:
                break;
            }

            break;
        default:
            break;
        }
        if(vendido == 1)
        {
            ve[contVendas].total = total_venda;
            ve[contVendas].ID_Vendedor = IDF;
            strcpy(ve[contVendas].CPF_Cliente, CPF);
            contVendas++;
            opc3 = 'x';
        }
    }
    while (opc3 != 'x');
    printf("\nVenda efetuada!\n");
    getch();
}
int main(void)
{
    //preencher variaveis
    AbreVariaveis();

    int opc, opc2, opc3, opc5 = 0;
    char esc;
    int chave = 1;

    //FunÃ§Ã£o para permitir acentuaÃ§Ã£o
    setlocale(LC_ALL, "Portuguese");

    //Vetores e listas
    Disco *estDiscos = calloc(Ldiscos, sizeof(Disco));
    if(estDiscos == NULL)
    {
        printf("Erro de memÃ³ria(Discos)!");
    }


    Camisa *estCamisas = calloc(Lcamisas, sizeof(Camisa));
    if(estCamisas == NULL)
    {
        printf("Erro de memÃ³ria(Camisas)!");
    }

    Fornecedor *listFornecedores = calloc(Lfornecedores, sizeof(Fornecedor));
    if(listFornecedores == NULL)
    {
        printf("Erro de memÃ³ria(Fornecedores)!");
    }

    Usuario *listFuncionarios = calloc(Lfuncionarios, sizeof(Usuario));
    if(listFuncionarios == NULL)
    {
        printf("Erro de memÃ³ria(funcion?rios)!");
    }
    Cliente *listClientes = calloc(Lclientes, sizeof(Cliente));
    if(listClientes == NULL)
    {
        printf("Erro de memÃ³ria (Clientes)!");
    }
    Venda *listVendas = calloc(Lvendas, sizeof(Venda));
    if(listVendas == NULL)
    {
        printf("Erro de memÃ³ria (Vendas)!");
    }
    //preencher vetores. Fica no inicio do programa
    AbreArquivo(estDiscos, estCamisas, listClientes, listFuncionarios, listFornecedores, listVendas);

    //data do sistema (Infelizemnte a funÃ§Ã£o ta quebrando o programa em um erro inesperado
    /*{
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(segundos);


        sDia = data_hora_atual->tm_mday;
        sMes = data_hora_atual->tm_mon+1;
        sAno = data_hora_atual->tm_year+1900;
    }*/

    //Usuï¿½rio ADM
    {
        strcpy(listFuncionarios[0].nome, "usuario");
        strcpy(listFuncionarios[0].senha, "0000");
        listFuncionarios[0].ID = 1000;
        strcpy(listFuncionarios[0].login, "adm");
        listFuncionarios[0].tipo = 2;

        strcpy(listFuncionarios[1].nome, "usuario2");
        strcpy(listFuncionarios[1].login, "adm2");
        strcpy(listFuncionarios[1].senha, "0000");
        listFuncionarios[1].ID = 0000;
        listFuncionarios[1].tipo = 1;


    }

    do
    {
        chave = Login(listFuncionarios);
    }
    while(chave);


    if(permicao > 0)
    {
        do
        {
            Cabecalho();
            printf("\n1-Buscar\n2-Cadastros\n3-Exibir Estoque\n4-Vendas\n5-Apagar\n6-UsuÃ¡rio\n7-Sair\n");
            scanf("%i", &opc);

            switch (opc)
            {
            case 1:
                Cabecalho();
                printf("\n1-Buscar Disco\n2-Buscar Camisa\n3-Buscar Cliente\n4-Buscar Fornecedor\n5-Buscar Funcionario\n6-Voltar");
                scanf("%i",&opc2);

                switch(opc2)
                {
                case 1:
                    BuscDisco(estDiscos);
                    break;
                case 2:
                    BuscarCami(estCamisas);
                    break;
                case 3:
                    BuscCliente(listClientes);
                    break;
                case 4:
                    BuscFornecedor(listFornecedores);
                    break;
                case 5:
                    BuscFuncionario(listFuncionarios);
                    break;
                case 6:
                    break;
                default:
                    printf("OpÃ§Ã£o InvÃ¡lida");
                    break;
                }
                break;
            case 2:
                do
                {
                Cabecalho();
                printf("\n1-Cadastrar Disco\n2-Cadastrar Camisa\n3-Voltar\n");
                scanf("%i", &opc2);
                switch(opc2)
                {
                case 1:
                    CadDisco(estDiscos, contEstDiscos);
                    break;
                case 2:
                    CadCami(estCamisas, contEstCamisas);
                    break;
                case 3:
                    break;
                default:
                    printf("\nOpÃ§Ã£o invÃ¡lida!\n");
                    break;
                }
                }while(opc2 != 3);
                break;
            case 3:
                do
                {
                Cabecalho();
                printf("1-Discos\n2-Camisas\n3-Voltar\n");
                scanf("%i", &opc2);
                switch(opc2)
                {
                case 1:
                    MostVetDisc(estDiscos, contEstDiscos);
                    break;
                case 2:
                    MostVetCamisa(estCamisas, contEstCamisas);
                    break;
                case 3:
                    break;
                default:
                    printf("OpÃ§Ã£o InvÃ¡lida!");
                    break;
                }
                }while(opc2 != 3);
                break;
            case 4:
                do
                {
                Cabecalho();
                printf("\n1-Realizar venda\n2-Sair\n");
                scanf("%i", &opc2);
                switch(opc2)
                {
                    case 1:
                        Vendas(listVendas, estDiscos, estCamisas, listFuncionarios, listClientes);
                        break;
                    default:
                        break;
                }
                }while(opc2 != 2);
                break;
            case 5:
                do
                {
                    Cabecalho();
                    printf("\n1-Apagar Disco\n2-Apagar Camisa\n3-Voltar\n");
                    scanf("%i", &opc5);
                    switch(opc5)
                    {
                    case 1:
                        ApagarDisco(estDiscos, contEstDiscos);
                        break;
                    case 2:
                        ApagarCamisa(estCamisas, contEstCamisas);
                        break;
                    case 3:
                        break;
                    default:
                        printf("OpÃ§Ã£o InvÃ¡lida");
                        break;
                    }
                }while(opc5 != 3);
                break;
            case 6:

                if(permicao == 2)
                {
                    do
                    {
                        Cabecalho();
                        printf("\n1-Cadastrar usuario\n2-Cadastrar cliente\n3-Cadastrar Fornecedor\n4-Mostrar usuarios\n5-Mosrar clientes\n6-Mostrar Fornecedores\n7-Apagar FuncionÃ¡rio\n8-Apagar Cliente\n9-Apagar Fornecedor\n10-Voltar\n");
                        scanf("%i", &opc3);

                        switch(opc3)
                        {
                        case 1:
                            CadFuncionario(listFuncionarios, contFuncionarios);
                            break;
                        case 2:
                            CadCliente(listClientes, contClientes);
                            break;
                        case 3:
                            CadFornecedor(listFornecedores, contFornecedores);
                            break;
                        case 4:
                            MostVetFuncionario(listFuncionarios, contFuncionarios);
                            break;
                        case 5:
                            MostVetCliente(listClientes, contClientes);
                            break;
                        case 6:
                            MostVetForncedor(listFornecedores, contFornecedores);
                            break;
                        case 7:
                            ApagarFuncionario(listFuncionarios, contFuncionarios);
                            break;
                        case 8:
                            ApagarCliente(listClientes, contClientes);
                            break;
                        case 9:
                            ApagarFornecedor(listFornecedores, contFornecedores);
                            break;
                        case 10:
                            break;
                        default:
                            printf("OpÃ§Ã£o InvÃ¡lida");
                            break;
                        }
                    }
                    while(opc3 != 10);
                }
                else
                {
                    Cabecalho();
                    printf("VocÃª nÃ£o tem permiÃ§Ã£o para acessar essa sessÃ£o!");
                    getch();
                };

            default:
                break;
            }
        }while (opc != 7);


        //Fecha arquivos e variÃ¡veis fica no fim do programa
        FechaArquivo(estDiscos, estCamisas, listClientes, listFuncionarios, listFornecedores, listVendas);
        FechaVariaveis();
    }


    return 0;
}