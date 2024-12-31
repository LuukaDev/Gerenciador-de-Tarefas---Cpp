#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

// Estrutura que representa uma tarefa
struct Tarefa {
    int Id;
    string Descricao;
};

// Declaração de funções
void Banner();
void AdicionarTarefa();
void ExibirTarefas();
void PesquisarTarefa();
void DeletarTarefa();
void AtualizarTarefa();

int main() {
    int opcao;

    while (true) {
        system("cls"); // Limpa a tela para uma experiência visual mais limpa
        Banner();
        cout << "---------------- Gerenciador De Tarefas -------------------" << endl;
        cout << "\n1 - Adicionar Uma Tarefa" << endl;
        cout << "2 - Ver as suas Tarefas" << endl;
        cout << "3 - Pesquisar Tarefa" << endl;
        cout << "4 - Deletar uma Tarefa" << endl;
        cout << "5 - Atualizar Tarefa" << endl;
        cout << "0 - Sair" << endl;
        cout << "----------------------------------------------------------" << endl;

        cout << "\nEscolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                AdicionarTarefa();
                break;
            case 2:
                ExibirTarefas();
                break;
            case 3:
                PesquisarTarefa();
                break;
            case 4:
                DeletarTarefa();
                break;
            case 5:
                AtualizarTarefa();
                break;
            case 0:
                cout << "Saindo do programa..." << endl;
                return 0;
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
                break;
        }

        system("pause"); // Aguarda o usuário pressionar uma tecla
    }

    return 0;
}

void Banner() {
    cout << "-----------------------" << endl;
    cout << "     Minhas Tarefas    " << endl;
    cout << "-----------------------" << endl;
}

void AdicionarTarefa() {
    system("cls");
    Banner();

    Tarefa novaTarefa;
    char salvarMais;

    cout << "Adicionar uma nova tarefa:\n";
    cin.ignore(); // Limpa o buffer
    getline(cin, novaTarefa.Descricao);

    ifstream arquivoEntrada("ListaTarefas.txt");
    int ultimoId = 0;
    string linha;

    // Determina o próximo ID com base no arquivo existente
    while (getline(arquivoEntrada, linha)) {
        ultimoId++;
    }
    arquivoEntrada.close();

    novaTarefa.Id = ultimoId + 1;

    ofstream arquivoSaida("ListaTarefas.txt", ios::app);
    if (arquivoSaida.is_open()) {
        arquivoSaida << novaTarefa.Id << ": " << novaTarefa.Descricao << endl;
        arquivoSaida.close();
        cout << "Tarefa adicionada com sucesso!" << endl;
    } else {
        cout << "Erro ao abrir o arquivo para escrita!" << endl;
    }

    cout << "Deseja adicionar outra tarefa? (S/N): ";
    cin >> salvarMais;
    salvarMais = toupper(salvarMais);

    if (salvarMais == 'S') {
        AdicionarTarefa();
    }
}

void ExibirTarefas() {
    system("cls");
    Banner();

    ifstream arquivoEntrada("ListaTarefas.txt");
    Tarefa tarefa;
    string linha;
    bool encontrouTarefas = false;

    if (arquivoEntrada.is_open()) {
        cout << "Minhas Tarefas:\n";
        while (getline(arquivoEntrada, linha)) {
            encontrouTarefas = true;
            cout << linha << endl;
        }
        arquivoEntrada.close();

        if (!encontrouTarefas) {
            cout << "Nenhuma tarefa encontrada." << endl;
        }
    } else {
        cout << "Erro ao abrir o arquivo para leitura!" << endl;
    }
}

void PesquisarTarefa() {
    system("cls");
    Banner();

    int idBusca;
    cout << "Digite o ID da tarefa que deseja pesquisar: ";
    cin >> idBusca;

    ifstream arquivoEntrada("ListaTarefas.txt");
    Tarefa tarefa;
    bool encontrada = false;
    string linha;

    if (arquivoEntrada.is_open()) {
        while (getline(arquivoEntrada, linha)) {
            size_t pos = linha.find(": ");
            if (pos != string::npos) {
                tarefa.Id = stoi(linha.substr(0, pos));
                tarefa.Descricao = linha.substr(pos + 2);

                if (tarefa.Id == idBusca) {
                    cout << "Tarefa encontrada: " << tarefa.Id << ": " << tarefa.Descricao << endl;
                    encontrada = true;
                    break;
                }
            }
        }
        arquivoEntrada.close();

        if (!encontrada) {
            cout << "Tarefa nao encontrada!" << endl;
        }
    } else {
        cout << "Erro ao abrir o arquivo para leitura!" << endl;
    }
}

void DeletarTarefa() {
    system("cls");
    Banner();

    int idDeletar;
    cout << "Digite o ID da tarefa que deseja deletar: ";
    cin >> idDeletar;

    ifstream arquivoEntrada("ListaTarefas.txt");
    ofstream arquivoTemp("Temp.txt");
    Tarefa tarefa;
    bool deletada = false;
    string linha;

    if (arquivoEntrada.is_open() && arquivoTemp.is_open()) {
        while (getline(arquivoEntrada, linha)) {
            size_t pos = linha.find(": ");
            if (pos != string::npos) {
                tarefa.Id = stoi(linha.substr(0, pos));
                tarefa.Descricao = linha.substr(pos + 2);

                if (tarefa.Id != idDeletar) {
                    arquivoTemp << tarefa.Id << ": " << tarefa.Descricao << endl;
                } else {
                    deletada = true;
                }
            }
        }

        arquivoEntrada.close();
        arquivoTemp.close();

        remove("ListaTarefas.txt");
        rename("Temp.txt", "ListaTarefas.txt");

        if (deletada) {
            cout << "Tarefa deletada com sucesso!" << endl;
        } else {
            cout << "Tarefa nao encontrada!" << endl;
        }
    } else {
        cout << "Erro ao abrir os arquivos!" << endl;
    }
}

void AtualizarTarefa() {
    system("cls");
    Banner();

    int idAtualizar;
    cout << "Digite o ID da tarefa que deseja atualizar: ";
    cin >> idAtualizar;
    cin.ignore();

    ifstream arquivoEntrada("ListaTarefas.txt");
    ofstream arquivoTemp("Temp.txt");
    Tarefa tarefa;
    bool atualizada = false;
    string linha;

    if (arquivoEntrada.is_open() && arquivoTemp.is_open()) {
        while (getline(arquivoEntrada, linha)) {
            size_t pos = linha.find(": ");
            if (pos != string::npos) {
                tarefa.Id = stoi(linha.substr(0, pos));
                tarefa.Descricao = linha.substr(pos + 2);

                if (tarefa.Id == idAtualizar) {
                    cout << "Digite a nova descricao da tarefa: ";
                    getline(cin, tarefa.Descricao);
                    atualizada = true;
                }

                arquivoTemp << tarefa.Id << ": " << tarefa.Descricao << endl;
            }
        }

        arquivoEntrada.close();
        arquivoTemp.close();

        remove("ListaTarefas.txt");
        rename("Temp.txt", "ListaTarefas.txt");

        if (atualizada) {
            cout << "Tarefa atualizada com sucesso!" << endl;
        } else {
            cout << "Tarefa nao encontrada!" << endl;
        }
    } else {
        cout << "Erro ao abrir os arquivos!" << endl;
    }
}
