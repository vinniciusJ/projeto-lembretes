#include <vector>
#include <iostream>
#include <iomanip>
#include <clocale>
#include "adicionarTexto.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "Portuguese");

    //Declaração de variaveis
    char opcao, condicao;
    bool executar = true;
    string lembrete;
    vector <string> lembretes;
    lembretes.clear();
    //---------------------------------------------------------------------------//
    cout << "LEMBRETES: " << endl;
    do{
        cout << endl << "OPÇÔES: " << endl;
        cout << "[A] Adicionar Lembretes" << endl;
        cout << "[D] Deletar Lembretes" << endl;
        cout << "[V] Ver Lembretes" << endl;
        cout << "[S] Sair" << endl;
        cin >> opcao;
        cin.ignore();

        while(opcao != 'A' &&  opcao != 'D'  && opcao != 'V'  && opcao != 'S'){
            cin >> opcao;
            cin.ignore();
        }

        switch (opcao){
            case 'A':
                do {
                    cout << "Informe o Lembrete: ";
                    getline(cin, lembrete);
                    lembretes.push_back(lembrete);

                    cout << "Deseja adicionar outro lembrete [S/N]: ";
                    cin >> condicao;
                    cin.ignore();

                }while (condicao != 'N');

                adicionarLembretes(lembretes);
                break;

            case 'D':
               deletarLembrete();
               break;
            case 'V':
                lerlembretes();
                break;
            case 'S':
                executar = false;
                break;
        }

    }while(executar);

    return 0;
}