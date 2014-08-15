#include <iostream>
#include <sstream>

using namespace std;



int registro = 0; //variavel GLOBAL

const int LIMITE_OPERACOES = 10;



void getEntrada (int produtos[2][2], int produto, int qtd);


void getSaida (int produtos[2][2], int produto, int qtd);


void relsaldo(int matriz[2][2], int linhas, int campos);


void getmovimento(string movimento[LIMITE_OPERACOES][4],string data, int produto, int qtd, char operacao);


void relmovimento(string matriz[2][4]);

string getmenu();




int main()
{
    int i = 0 , j = 0;
    int opcao;
    int produtos[2][2];

 string movimento[LIMITE_OPERACOES][4];

 string data;

    int produto, qtd;
    char operacao ;
    //produtos

 produtos [0][0] = 15 ;
 produtos [1][0] = 20;
    // saldos

produtos [0][1] = 250;
produtos [1][1] = 490;



 do{


    cout << getmenu();

    cout << "Opcao desejada: " ;
    cin >> opcao;


switch (opcao) {


case 1:

    cout << "Informe a data: "  ;
    cin >> data;


    cout << "Produto: "         ;
    cin >> produto;


    cout << "Qtd: "             ;
    cin >> qtd;


getEntrada (produtos,produto, qtd) ;


    cout << "Entrada realizada com sucesso!" << endl;


getmovimento(movimento,data, produto, qtd, 'E');

break;

case 2:

    cout << "Informe a data: "  ;
    cin >> data;


    cout << "Produto: "         ;
    cin >> produto;


    cout << "Qtd: "             ;
    cin >> qtd;


getSaida   (produtos,produto, qtd) ;

    cout << "Saida realizada com sucesso!" << endl;


getmovimento(movimento,data, produto, qtd, 'S');

break;


case 3:


relsaldo(produtos,2,2);


break;

case 4:


relmovimento(movimento);


break;



case 5:


cout << "Obrigado e ate a proxima!!" << endl;

break;

default:

   cout << "Opcao invalida!" << endl;

break;

  }

 }

while(opcao != 5);


  return 0;
}


    string getmenu(){


    string menu;

    menu =   " --- CONTROLE DE ESTOQUE --- \n" ;
    menu +=  "1 - Entrada                  \n" ;
    menu +=  "2 - Saida                    \n" ;
    menu +=  "3 - Saldos                  \n" ;
    menu +=  "4 - Movimento               \n" ;
    menu +=  "5 - Sair                    \n";

return menu;
}

void getEntrada (int produtos[2][2], int produto, int qtd){
    for (int i = 0; i < 2; i++) {
            if (produtos[i][0] == produto){
                produtos[i][1] += qtd;
            }
    }
}
void getSaida (int produtos[2][2], int produto, int qtd){
    for (int i = 0; i < 2; i++) {
            if (produtos[i][0] == produto){
                if (qtd <= produtos[i][1]){
                    produtos[i][1] -= qtd;
                }else{
                    cout << "Saldo Insuficiente!" << endl;
                }

            }
    }
}
void getmovimento(string movimento[LIMITE_OPERACOES][4],string data, int produto, int qtd, char operacao){
ostringstream codpro, quantidade;

codpro      << produto;
quantidade  << qtd;

    if (registro < 10) {
        movimento[registro][0] = data;
        movimento[registro][1] = codpro.str();
        movimento[registro][2] = quantidade.str();
        movimento[registro][3] = operacao;
        registro++;

    } else {
        cout << "Atingiu o limite de OPERACOES DIARIAS!" << endl;
    }

}
void relsaldo(int matriz[2][2], int linhas, int campos){
    cout << "Produto \tSaldo \n"
         << "-----------------------" << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < campos; j++) {
            cout << matriz[i][j] << "\t\t";
        }
        cout << "\n";
    }
}

void relmovimento(string matriz[LIMITE_OPERACOES][4]){
    for (int i = 0; i < LIMITE_OPERACOES; i++) {
        for (int j = 0; j < 4; j++) {
            if (cout << matriz[i][j] != "")
               cout << matriz[i][j] << "\t\t";
        }
        cout << "\n";
    }
}
