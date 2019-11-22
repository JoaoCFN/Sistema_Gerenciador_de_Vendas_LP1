#include <stdio.h>
#include <stdlib.h>

// DECLARAÇÃO DE VARIÁVEIS GLOBAIS
int i, j, z, opcao = 0, continuar = 1, dia = 0, produto = 0, produto_mais_vendeu_unidade, produto_menos_vendeu_unidade;
int quantidade[10][7], total_vendas_semana_unidade[10], opcao_alteraracao, posicao, novo_valor_unidade;
float preco[10], tot_vendas_pordia_unidade[7], tot_vendas_pordia_reais[7], qts_vendas_final_reais = 0,  qts_vendas_final_unidade = 0;
float total_vendas_semana_reais[10], produto_mais_vendeu_reais, produto_menos_vendeu_reais, novo_valor_reais;


// MATRIZ DO NOME DOS PRODUTOS
char nomes_dos_produtos[10][20] = {"Farinha       ",
                                   "Arroz         ",
                                   "Feijao        ",
                                   "Frango        ",
                                   "Carne         ",
                                   "Sabonete      ",
                                   "Escova        ",
                                   "Pasta         ",
                                   "Shampoo       ",
                                   "Condicionador "};

// MATRIZ PARA OS DIAS DA SEMANA
char dia_semana[7][10] = {"Domingo  ",
                          "Segunda  ",
                          "Terca    ",
                          "Quarta   ",
                          "Quinta   ",
                          "Sexta    ",
                          "Sabado   "};


// FUNÇÃO QUE POSSIBILITA A ALTERARAÇÃO DE DADOS POR PARTE DO USUÁRIO DO PROGRAMA - EM UNIDADE
void alterar_dados_unidade(int posicao){
  /* A FUNÇÃO COMEÇA PEDINDO O DIA ESPECÍFICO QUE O USUÁRIO DESEJA ALTERAR, POIS COM ESSA INFORMAÇÃO OBTEREMOS A COLUNA 
  RESPECTIVA PARA A MUDANÇA. APÓS ISSO, LI O NOVO VALOR E ARMAZENEI NA POSIÇÃO */
  printf(" \n------------------------------------------------ \n");
  printf("ESCOLHA O DIA: \n0 - DOMINGO \n1 - SEGUNDA \n2 - TERCA \n3 - QUARTA \n4 - QUINTA \n5 - SEXTA \n6 - SABADO\n");
  scanf("%d", &dia);

  if (dia >= 0 && dia < 7){
      printf(" \n------------------------------------------------ \n");
      printf("Valor atual:\n%s: %d Unidades\n", nomes_dos_produtos[posicao], quantidade[posicao][dia]);
      printf("Digite o novo valor desejado para o respectivo produto\n"); 
      scanf("%d", &novo_valor_unidade);
      printf(" \n------------------------------------------------ \n");
      quantidade[posicao][dia] = novo_valor_unidade;
      printf("Valor atualizado!\n");
  }
  else{
    printf("Opcao Invalida\n");
  }
  
}

// FUNÇÃO QUE POSSIBILITA A ALTERARAÇÃO DE DADOS POR PARTE DO USUÁRIO DO PROGRAMA - EM REAIS
void alterar_dados_reais(int posicao){
  /*LI O NOVO VALOR DO USUÁRIO E ARMAZENEI NA POSIÇÃO */
  printf(" \n------------------------------------------------ \n");
  printf("Valor atual:\n%s: R$%.2f \n", nomes_dos_produtos[posicao], preco[posicao]);
  printf("Digite o novo valor desejado para o respectivo produto\n");
  scanf("%f", &novo_valor_reais);
  printf(" \n------------------------------------------------ \n");
  preco[posicao] = novo_valor_reais;
  printf("Valor atualizado!\n");
}


// FUNÇÃO QUE MOSTRA A TABELA DE PRODUTOS
void mostrar_tabela_vendas(){

  // DIAS DA SEMANA
    printf("                   ");
    for (i = 0; i < 7; i++)
        printf("%s", dia_semana[i]);
    printf("\n");

    // FUNÇÕES PARA PRINTAR A MATRIZ DE QUANTIDADE DO TXT
    for (i = 0; i < 10; i++){
        printf("%s", nomes_dos_produtos[i]);
        for (j = 0; j < 7; j++){
            // PRINTAR MATRIZ
            printf("%9.1d", quantidade[i][j]);
        }
        printf("\n");
    }
  
}

// FUNÇÃO QUE MOSTRA A TABELA DE PRECOS
void mostrar_tabela_preco(){
    printf("PRECO DOS PRODUTOS: \n");
    // FUNÇÕES PARA PRINTAR O VETOR DE PREÇO DO TXT
    for (i = 0;  i < 10; i++){
          printf("\n%s %.2f \n", nomes_dos_produtos[i], preco[i]);
    }


}

// FUNÇÃO QUE CALCULA OS PRODUTOS A PARTIR DE UM DIA ESCOLHIDO
void calcula_quantidade_dia(){
  // TOTAL DE VENDAS POR DIA EM UNIDADE E EM REAIS
    for (j = 0; j < 7; j++){
        tot_vendas_pordia_unidade[j] = 0;
        tot_vendas_pordia_reais[j] = 0;
        for (i = 0; i < 10; i++){
            // TOTAL DE VENDAS EM UM DIA (POR UNIDADE)
            tot_vendas_pordia_unidade[j] += quantidade[i][j];
            // TOTAL DE VENDAS EM UM DIA (REAIS
            tot_vendas_pordia_reais[j] += quantidade[i][j]*preco[i];
        }

    }

}

// FUNÇÃO QUE EXIBE OS PRODUTOS A PARTIR DE UM DIA ESCOLHIDO
void exiba_quantidade_dia(){

  printf(" \n------------------------------------------------ \n");
  printf("ESCOLHA O DIA: \n0 - DOMINGO \n1 - SEGUNDA \n2 - TERCA \n3 - QUARTA \n4 - QUINTA \n5 - SEXTA \n6 - SABADO\n");
  scanf("%d", &dia);
  if (dia >= 0 && dia < 7){
    printf(" \n------------------------------------------------ \n");
    for (i = 0; i < 10; i++)
      printf("%c", dia_semana[dia][i]);

    printf("\nO total de produtos vendidos (unidade) foi %.0f \n", tot_vendas_pordia_unidade[dia]);
    printf("O total de produtos vendidos (reais) foi %.2f \n", tot_vendas_pordia_reais[dia]);
    printf(" \n------------------------------------------------ \n"); 
  }

  else {
    printf("Opcao Invalida\n");
  }
  

}

// FUNÇÃO QUE A PARTIR DE UM PRODUTO CALCULA AS VENDAS NA SEMANA
void calcula_quantidade_semana(){

  for (i = 0; i < 10; i++){
        // AQUI EU INICIO A SOMA DOS PRODUTOS
        total_vendas_semana_unidade[i] = 0;
        for (j = 0; j < 7; j++){
            // SOMA DOS PRODUTOS SEMANAL
            total_vendas_semana_unidade[i] += quantidade[i][j];     
        }
    }

    // TOTAL DE VENDAS POR PRODUTO (REAIS)
    
    for (i = 0; i  < 10; i++){
      total_vendas_semana_reais[i] = preco[i]*total_vendas_semana_unidade[i];
    }

}

// FUNÇÃO QUE A PARTIR DE UM PRODUTO EXIBE AS VENDAS NA SEMANA
void exiba_quantidade_semana(){

  printf(" \n------------------------------------------------ \n");
  printf("ESCOLHA O PRODUTO: \n0 - FARINHA \n1 - ARROZ \n2 - FEIJAO \n3 - FRANGO \n4 - CARNE \n5 - SABONETE \n6 - ESCOVA \n7 - PASTA \n8 - SHAMPOO \n9 - CONDICIONADOR \n");
  scanf("%d", &produto);
  printf(" \n------------------------------------------------ \n");

  if (produto >= 0 && produto < 10){

      printf("%s", nomes_dos_produtos[produto]);
      printf("\nTotal de Vendas na semana (Em Unidade) %d \n", total_vendas_semana_unidade[produto]);
      printf("Total de Vendas na semana (Em reias) %.2f \n", total_vendas_semana_reais[produto]);

  }
  else {
    printf("Opcao Invalida\n");
  }
   
}

// FUNÇÃO QIE GERA O RELATÓRIO FINAL EM TXT
void gerar_relatorio (relatorio){
  // GRAVAR RELATÓRIO NO ARQUIVO TXT 
    fprintf(relatorio, " \n------------------------------------------------ \n");
                
    // DIAS DA SEMANA
    fprintf(relatorio, "                   ");
    for (i = 0; i < 7; i++)
        fprintf(relatorio,"%s", dia_semana[i]);
    fprintf(relatorio,"\n");

    // FUNÇÕES PARA PRINTAR A MATRIZ DE QUANTIDADE DO TXT
    for (i = 0; i < 10; i++){
        // AQUI EU INICIO A SOMA DOS PRODUTOS
        fprintf(relatorio, "%s", nomes_dos_produtos[i]);
        for (j = 0; j < 7; j++){
            // PRINTAR MATRIZ
            fprintf(relatorio, "%9.1d", quantidade[i][j]);
        }
        fprintf(relatorio, "\n");
    }

    fprintf(relatorio, "\n------------------------------------------------ \n");
     // FUNÇÕES PARA PRINTAR O VETOR DE PREÇO DO TXT
    for (i = 0;  i < 10; i++){
          fprintf(relatorio, "\n%s %.2f \n", nomes_dos_produtos[i], preco[i]);
    }


    fprintf(relatorio, "\n------------------------------------------------ \n");
    // TOTAL DE VENDAS POR DIA (UNIDADE)
    fprintf(relatorio, "Total de Vendas Por Dia (Em Unidade)\n");
    // DIAS DA SEMANA
    for (i = 0; i < 7; i++)
        fprintf(relatorio, "%s", dia_semana[i]);
    fprintf(relatorio, "\n");
    for (i = 0; i < 7; i++){
        // QUANTIDADE TOTAL DE VENDAS UNIDADE
        qts_vendas_final_unidade += tot_vendas_pordia_unidade[i];
        fprintf(relatorio, "%5.0f    ", tot_vendas_pordia_unidade[i]);
    }

    fprintf(relatorio, "\n------------------------------------------------ \n");
    // TOTAL DE VENDAS POR DIA (REAIS)
    fprintf(relatorio, "Total de Vendas Por Dia (Em Reais) \n");
    for (i = 0; i < 7; i++)
        fprintf(relatorio, "%s  ", dia_semana[i]);
    fprintf(relatorio, "\n");
    for (i = 0; i < 7; i++){
        qts_vendas_final_reais += tot_vendas_pordia_reais[i];
        fprintf(relatorio, " %5.2f    ", tot_vendas_pordia_reais[i]);
    }

    fprintf(relatorio, "\n------------------------------------------------ \n");
    // TOTAL DE VENDAS POR PRODUTO (UNIDADE)
    fprintf(relatorio, "Total de Vendas Por Produto (Em Unidade) \n");
    for (i = 0; i < 10; i++){
        fprintf(relatorio, "%s %d \n", nomes_dos_produtos[i], total_vendas_semana_unidade[i]);
    }

    fprintf(relatorio, " \n------------------------------------------------ \n");
    // TOTAL DE VENDAS POR PRODUTO (REAIS)
    fprintf(relatorio, "Total de Vendas Por Produto (Em reais) \n");
    for (i = 0; i  < 10; i++){
        fprintf(relatorio, "%s %.2f \n", nomes_dos_produtos[i], total_vendas_semana_reais[i]);
    }

    fprintf(relatorio, " \n------------------------------------------------ \n");
    fprintf(relatorio, "Total das Vendas (Em unidade): %.f", qts_vendas_final_unidade);
    fprintf(relatorio, " \n------------------------------------------------ \n");
    fprintf(relatorio, "Total das Vendas (Em reais): %.2f", qts_vendas_final_reais);
    fprintf(relatorio, " \n------------------------------------------------ \n");

    
    
    /* PARA DESCOBRIR OS PRODUTOS MAIS VENDIDOS EU ZERO MINHAS VARIÁVEIS DE COMPARAÇÃO
    E FAÇO UMA COMPRAÇÃO COM CADA POSIÇÃO DO MEU VETOR DE VENDAS SEMANAIS. SE FOR MAIOR OU IGUAL PRINTA E SOBREPÕE. */
    produto_mais_vendeu_unidade = 0;
    produto_mais_vendeu_reais = 0;

    // MOSTRA OS PRODUTOS QUE MAIS VENDERAM EM UNIDADE
    fprintf(relatorio, "Produto que mais vendeu (em unidade)\n");
    for (i = 0; i < 10; i++)
    {
      if (total_vendas_semana_unidade[i] >= produto_mais_vendeu_unidade){        
        produto_mais_vendeu_unidade = total_vendas_semana_unidade[i];
        fprintf(relatorio, "%s %d \n", nomes_dos_produtos[i], total_vendas_semana_unidade[i]);
      } 
    }

    fprintf(relatorio, "\n------------------------------------------------ \n");

    // MOSTRA OS PRODUTOS QUE MAIS VENDERAM EM REAIS
    fprintf(relatorio, "Produto que mais vendeu (em reais)\n");
    for (i = 0; i < 10; i++)
    {
      if (total_vendas_semana_reais[i] >= produto_mais_vendeu_reais){        
        produto_mais_vendeu_reais = total_vendas_semana_reais[i];
        fprintf(relatorio, "%s R$%.2f \n", nomes_dos_produtos[i], total_vendas_semana_reais[i]);
      } 
    }

    fprintf(relatorio, "\n------------------------------------------------ \n");

    produto_menos_vendeu_unidade = 0;
    produto_menos_vendeu_reais = 0;

    // MOSTRA OS PRODUTOS QUE MENOS VENDERAM EM UNIDADE
    fprintf(relatorio, "Produto que mais vendeu (em unidade)\n");
    for (i = 0; i < 10; i++)
    {
      if (total_vendas_semana_unidade[i] <= produto_menos_vendeu_unidade){       
        produto_menos_vendeu_unidade = total_vendas_semana_unidade[i];
        fprintf(relatorio, "%s %d \n", nomes_dos_produtos[i], total_vendas_semana_unidade[i]);
      } 
    }

    fprintf(relatorio, "\n------------------------------------------------ \n");

    // MOSTRA OS PRODUTOS QUE MENOS VENDERAM EM REAIS
    fprintf(relatorio, "Produto que mais vendeu (em reais)\n");
    for (i = 0; i < 10; i++)
    {
      if (total_vendas_semana_reais[i] <= produto_menos_vendeu_reais){       
        produto_mais_vendeu_reais = total_vendas_semana_reais[i];
        fprintf(relatorio, "%s R$%.2f \n", nomes_dos_produtos[i], total_vendas_semana_reais[i]);
      } 
    }

    fprintf(relatorio, "\n------------------------------------------------ \n");
    printf("Relatorio gerado com sucesso!\n");

}


int main(){
    // Criei o meu ponteiro de dados e apontei para o local do arquivo
    // Criei o meu ponteiro para o relatorio
    FILE * dados;
    FILE * relatorio;
    dados = fopen("dados.txt", "r");
    relatorio = fopen("relatorio.txt", "w");



    // FUNÇÕES PARA PREENCHER A MATRIZ COM OS DADOS DE QUANTIDADE DO TXT
    for (i = 0; i < 10; i++){
        for (j = 0; j < 7; j++){
            fscanf(dados, "%d", &quantidade[i][j]);
        }
    }

    // FUNÇÕES PARA PREENCHER O VETOR COM OS DADOS DE PREÇO DO TXT
    for (i = 0;  i < 10; i++){
        fscanf(dados, "%f", &preco[i]);
    }
 

    while (continuar != 0){
        // MENU
        printf("---------------------------------------------------------------------------\n");
        printf("SEJA BEM VINDO SEU ZE \n");
        printf("---------------------------------------------------------------------------\n");
        printf("1 - VER TABELA DE PRODUTOS \n"); 
        printf("2 - VER PRECOS DOS PRODUTOS\n");
        printf("3 - PARA ALTERAR DADOS INFORMADOS \n"); 
        printf("4 - VER A QUANTIDADE DE PRODUTOS VENDIDOS A PARTIR DE UM DIA DA SEMANA (EM UNIDADE E EM REAIS)\n");
        printf("5 - VER A QUANTIDADE DO MESMO PRODUTO VENDIDO NA SEMANA (EM UNIDADE E EM REAIS)\n");
        printf("6 - GERAR RELATORIO \n");
        printf("OUTRO VALOR - PARA SAIR DO PROGRAMA \n");
        printf("---------------------------------------------------------------------------\n");
        scanf("%d", &opcao);

        //LIMPAR TELA
        system("cls");

        // CASO O CAMINHO DO ARQUIVO ESTEJA ERRADO, ESSA MENSAGEM SERÁ EXIBIDA
        if (dados == NULL){
            printf("Não foi possível abrir o arquivo");
        }

        // OPÇÕES DO MENU
        switch(opcao){
          case 1:

              mostrar_tabela_vendas();
            
          break;

          case 2:

              mostrar_tabela_preco();

          break;

          case 3:
              printf(" \n------------------------------------------------ \n");
              printf("ESCOLHA O PRODUTO: \n0 - FARINHA \n1 - ARROZ \n2 - FEIJAO \n3 - FRANGO \n4 - CARNE \n5 - SABONETE \n6 - ESCOVA \n7 - PASTA \n8 - SHAMPOO \n9 - CONDICIONADOR \n");
              scanf("%d", &posicao);
              printf(" \n------------------------------------------------ \n");
              if (posicao >= 0 && posicao < 10){
                  printf("Qual dos dados do produto voce deseja alterar? \n");
                  printf("1 - UNIDADE\n");
                  printf("2 - REAIS\n");
                  printf(" \n------------------------------------------------ \n");
                  scanf("%d", &opcao_alteraracao);

                  if (opcao_alteraracao == 1){
                    alterar_dados_unidade(posicao);
                  }
                  else if (opcao_alteraracao == 2){
                    alterar_dados_reais(posicao);
                  }
                  else{
                    printf("Opcao Invalida!\n");
                  }

              }

              else {
                printf("Opcao Invalida!\n");
              }
            
          break;

          case 4:

            calcula_quantidade_dia();
            exiba_quantidade_dia();

          break;

          case 5:

            calcula_quantidade_semana();
            exiba_quantidade_semana();

          break;

          case 6:
            // FUNÇÕES PARA ALIMENTAR O RELATÓRIO
            calcula_quantidade_dia();
            calcula_quantidade_semana();

          // GERAR RELATÓRIO
            gerar_relatorio(relatorio);

          break;

          default:
            return 0;
          break;

           

        }

        printf("\nVoce deseja fazer mais alguma acao ? [OUTRO VALOR] SIM [0] NAO \n");
        scanf("%d", &continuar);
        //LIMPAR TELA
        system("cls");

    }

    // FECHAR PONTEIROS
    fclose(dados);
    fclose(relatorio);

    return 0;
}
