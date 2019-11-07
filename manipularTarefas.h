
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

void adicionarLembretes( vector <string> lembretes){

    ifstream leitura;
    string linha;
    ofstream arquivo;

    leitura.open("Lembretes.txt");

    while (!leitura.eof()){
        getline(leitura,linha);

        if(!linha.empty()) {
            lembretes.push_back(linha);
        }
    }

    leitura.close();

    arquivo.open("Lembretes.txt");

    sort(begin(lembretes), end(lembretes));

    for (int i = 0; i < (int) lembretes.size(); ++i) {

        arquivo << i + 1 << "º " << lembretes[i] << endl;
    }

    arquivo.close();
}
void lerlembretes(){

    vector <string> lembretesAtuais;
    lembretesAtuais.clear();

    ifstream arquivo;
    string lembreteAtual;

    arquivo.open("Lembretes.txt");

    while(!arquivo.eof()){
        getline(arquivo, lembreteAtual);
        lembretesAtuais.push_back(lembreteAtual);
    }

    if(lembretesAtuais.empty()){
        cout << "NAO HA LEMBRETES NO MOMENTO" << endl;
    }
    else {
        for (const auto & lembretesAtual : lembretesAtuais) {
            cout << lembretesAtual << endl;
        }
    }
}
void deletarLembrete(){

    ifstream lembreteArquivo;
    ofstream arquivo;
    vector <string> lembretes;
    string lembrete;
    char condicao;
    int posicao;

    lembreteArquivo.open("Lembretes.txt");

    while (!lembreteArquivo.eof()){
        getline(lembreteArquivo, lembrete);
        lembretes.push_back(lembrete);
    }

    for (const auto & lembrete2 : lembretes) {

        cout <<  lembrete2 << endl;
    }

    do{

       cout << "Escolha a posição do lembrete para deletá-lo: ";
       cin >> posicao;

       lembretes.erase(begin(lembretes)+(posicao - 1));

       cout << "Deseja apagar outra [S/N]: ";
       do{
           cin >> condicao;
           cin.ignore();

       }while(condicao != 'S' && condicao != 'N');

    }while(condicao != 'N');

    lembreteArquivo.close();
    sort(begin(lembretes), end(lembretes));

    arquivo.open("Lembretes.txt");

    for(const auto & lembreteFor : lembretes){
        arquivo << lembrete << endl;
    }

    arquivo.close();

}

