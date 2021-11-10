#include <iostream>
#include <iomanip>
#include <locale.h>
#include <vector>
#include "Clientes.h"
#include "ClienteVip.h"
#include "Emprestimo.h"

using namespace std;

namespace Cliente{
ClienteVip::ClienteVip()
{

}

ClienteVip::~ClienteVip()
{
    //dtor
}

bool ClienteVip::getVip(){
    return true;
}

void ClienteVip::AdicionaEmprestimo(Emprestimo emp, int data){

        emprestimos.push_back(emp);
        for(int i = 0; i <emprestimos.size(); i++){
            emprestimos[i].setPrazo(data);
        }
}

void ClienteVip::setEmp(Emprestimo emp, int op){
    if(op == 1)
        emprestimos[0] = emp;
    if(op == 2)
        emprestimos[1] = emp;
}

Emprestimo ClienteVip::getEmp(int op){
    if(op == 1)
        return emprestimos[0];
    if(op == 2)
        return emprestimos[1];
}

void ClienteVip::AtualizaPrazo(){
    for(int i = 0; i < emprestimos.size(); i++)
        emprestimos[i].setPrazo(emprestimos[i].getPrazo() - 1);
}

void ClienteVip::MostrarLista(){
    setlocale(LC_ALL, "Portuguese");

        std::cout << std::endl;
        std::cout << "Nome: " << emprestimos[0].getNomes() << std::endl;
        std::cout << "Livro(s): " << std::endl;

        if(emprestimos[0].getLivros() != "/")
            std::cout << "  " + emprestimos[0].getLivros() << std::endl;
        if(emprestimos[1].getLivros() != "/")
            std::cout << "  " + emprestimos[1].getLivros() << std::endl;

        if(emprestimos[0].getPrazo() >= 0){
            std::cout << "Prazo de devolução: " << emprestimos[0].getPrazo() << " dias" << std::endl;
            std::cout << std::endl;

        }else{
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Prazo de devolução expirado a " << emprestimos[0].getPrazo() * (-1) << " dia(s)" << std::endl;
            std::cout << "Multa a ser paga: R$" << emprestimos[0].getPrazo() * (-1) * 2.0 << std::endl;
        }

}

int ClienteVip::ExcluirEmprestimo(std::string procuraL, std::string procuraN){
    setlocale(LC_ALL, "Portuguese");

    if(emprestimos[0].getLivros() == "/" && emprestimos[1].getLivros() == "/")
        return 1;

    for(int i = 0; i < emprestimos.size(); i++){
        if(emprestimos[i].getNomes().find(procuraN) != std::string::npos && emprestimos[i].getLivros().find(procuraL) != std::string::npos){
            std::cout << std::endl;
            std::cout << "Livro: " << emprestimos[i].getLivros() << std::endl;
            std::cout << "Nome: " << emprestimos[i].getNomes() << std::endl;

            if(emprestimos[i].getPrazo() >= 0){
            std::cout << "Prazo de devolução: " << emprestimos[i].getPrazo() << " dias" << std::endl;
            std::cout << std::endl;
            }else{
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "Prazo de devolução expirado a " << emprestimos[i].getPrazo() * (-1) << " dia(s)" << std::endl;
                std::cout << "Multa a ser paga: R$" << emprestimos[i].getPrazo() * (-1) * 2.0 << std::endl;
            }
            std::cout << "Emprestimo 0: " << emprestimos[0].getLivros() << std::endl;
            std::cout << "Emprestimo 1: " << emprestimos[1].getLivros() << std::endl;
            std::cout << "Deseja realmente excluir esse empréstimo?\n"
                         "1 - Sim\n"
                         "2 - Não" << std::endl;
            int op = 0;
            std::cin >> op;
            getchar();

            if(op == 2)
                return 4;
            else{
                if(i != 1){
                   // emprestimos.erase(emprestimos.begin()+i);
                    return 3;
                }
                //else
                   // emprestimos[1].setLivros("/");

                if(emprestimos[0].getLivros() == "/" && emprestimos[1].getLivros() == "/")
                    return 1;
                else
                    return 2;
            }
        }
    }


    return 0;
}

bool ClienteVip::AlterarEmprestimo(std::string procuraL, std::string procuraN){
    setlocale(LC_ALL, "Portuguese");
    int alterar = -1;
    std::string nvLivro, nvNome;
    int nvPrazo;

    for(int i = 0; i < emprestimos.size(); i++){
        if(emprestimos[i].getNomes().find(procuraN) != std::string::npos && emprestimos[i].getLivros().find(procuraL) != std::string::npos){
            std::cout << std::endl;
            std::cout << "Livro: " << emprestimos[i].getLivros() << std::endl;
            std::cout << "Nome: " << emprestimos[i].getNomes() << std::endl;

            if(emprestimos[i].getPrazo() >= 0){
                std::cout << "Prazo de devolução: " << emprestimos[i].getPrazo() << " dias" << std::endl;
                std::cout << std::endl;
            }else{
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "Prazo de devolução expirado a " << emprestimos[i].getPrazo() * (-1) << " dia(s)" << std::endl;
                std::cout << "Multa a ser paga: R$" << emprestimos[i].getPrazo() * (-1) * 2.0 << std::endl;
            }
            std:: cout << std::endl;

            std::cout << "-------O que deseja alterar?-------" << std::endl;
            std::cout << "1 - Nome do livro\n"
                        "2 - Nome do cliente\n"
                        "3 - Prazo de entrega\n"
                        "4 - Cancelar alteração" << std::endl;
            int op = 0;
            std::cin >> op;
            getchar();

            switch(op){
                case 1:
                    std::cout << "Digite o novo nome do livro: ";
                    std::getline(std::cin, nvLivro);
                    emprestimos[i].setLivros(nvLivro);
                    std::cout << std::endl;
                    std::cout << "----Nome do livro alterado com sucesso----" << std::endl;
                    return true;

                case 2:
                    std::cout << "Digite o novo nome do cliente: ";
                    std::getline(std::cin, nvNome);
                    emprestimos[i].setNomes(nvNome);
                    std::cout << std::endl;
                    std::cout << "----Nome do cliente alterado com sucesso----" << std::endl;
                    return true;

                case 3:
                    std::cout << "Digite o novo prazo: ";
                    std::cin >> nvPrazo;
                    getchar();
                    emprestimos[i].setPrazo(nvPrazo);
                    std::cout << std::endl;
                    std::cout << "----Prazo alterado com sucesso----" << std::endl;
                    return true;

                case 4:
                    return true;
            }
        }
    }
}

int ClienteVip::opcaoEditar(){
    int op = 0;

  while(1){
    std::cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n"
                "          Menu de Edição da Biblioteca!\n"
                "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << std::endl;
    std::cout << std::endl;
    std::cout << "-------Edição de empréstimos-------\n" << std::endl;
    std::cout << "1 - Excluir um empréstimo\n"
                 "2 - Alterar um empréstimo\n"
                 "3 - Voltar ao Menu Principal" << std::endl;
    std::cin >> op;
    getchar();
    return op;
  }

}
}
