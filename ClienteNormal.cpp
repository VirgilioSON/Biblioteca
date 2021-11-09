#include <iostream>
#include <string>
#include <iomanip>
#include <locale.h>
#include <fstream>
#include <vector>
#include "Clientes.h"
#include "ClienteNormal.h"
#include "Emprestimo.h"

using namespace std;

namespace Cliente{
ClienteNormal::ClienteNormal()
{

}

ClienteNormal::~ClienteNormal()
{
    //dtor
}

bool ClienteNormal::getVip(){
    return false;
}

void ClienteNormal::AdicionaEmprestimo(Emprestimo emp, int data){
        emprestimo = emp;
}

void ClienteNormal::setEmp(Emprestimo emp){
    emprestimo = emp;
}

Emprestimo ClienteNormal::getEmp(int op){
    return emprestimo;
}

void ClienteNormal::AtualizaPrazo(){

    emprestimo.setPrazo(emprestimo.getPrazo() - 1);
}

void ClienteNormal::MostrarLista(){
    setlocale(LC_ALL, "Portuguese");

        std::cout << std::endl;
        std::cout << "Nome: " << emprestimo.getNomes() << std::endl;
        std::cout << "Livro: " << emprestimo.getLivros() << std::endl;

        if(emprestimo.getPrazo() >= 0){
            std::cout << "Prazo de devolução: " << emprestimo.getPrazo() << " dias" << std::endl;
            std::cout << std::endl;

        }else{
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Prazo de devolução expirado a " << emprestimo.getPrazo() * (-1) << " dia(s)" << std::endl;
            std::cout << "Multa a ser paga: R$" << emprestimo.getPrazo() * (-1) * 2.0 << std::endl;
        }


}

int ClienteNormal::ExcluirEmprestimo(std::string procuraL, std::string procuraN){
    setlocale(LC_ALL, "Portuguese");
    int exclusao = -1;

    if(emprestimo.getLivros().find(procuraL) != std::string::npos && emprestimo.getNomes().find(procuraN) != std::string::npos)
        exclusao = 1;

    if(exclusao == -1){
        return 0;
    }
    std::cout << std::endl;
    std::cout << "Livro: " << emprestimo.getLivros() << std::endl;
    std::cout << "Nome: " << emprestimo.getNomes() << std::endl;

    if(emprestimo.getPrazo() >= 0){
    std::cout << "Prazo de devolução: " << emprestimo.getPrazo() << " dias" << std::endl;
    std::cout << std::endl;
    }else{
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Prazo de devolução expirado a " << emprestimo.getPrazo() * (-1) << " dia(s)" << std::endl;
        std::cout << "Multa a ser paga: R$" << emprestimo.getPrazo() * (-1) * 2.0 << std::endl;
    }
        std::cout << "Deseja realmente excluir esse empréstimo?\n"
                    "1 - Sim\n"
                    "2 - Não" << std::endl;
    int op = 0;
    std::cin >> op;
    getchar();

    if(op == 2)
        return 2;
    return 1;
}

bool ClienteNormal::AlterarEmprestimo(std::string procuraL, std::string procuraN){
    setlocale(LC_ALL, "Portuguese");
    int alterar = -1;
    std::string nvLivro, nvNome;
    int nvPrazo;

        if(emprestimo.getLivros().find(procuraL) != std::string::npos && emprestimo.getNomes().find(procuraN) != std::string::npos)
            alterar = 1;

        if(alterar == -1){
            return false;
        }
          std::cout << std::endl;
          std::cout << "Livro: " << emprestimo.getLivros() << std::endl;
          std::cout << "Nome: " << emprestimo.getNomes() << std::endl;

          if(emprestimo.getPrazo() >= 0){
            std::cout << "Prazo de devolução: " << emprestimo.getPrazo() << " dias" << std::endl;
            std::cout << std::endl;
          }else{
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Prazo de devolução expirado a " << emprestimo.getPrazo() * (-1) << " dia(s)" << std::endl;
            std::cout << "Multa a ser paga: R$" << emprestimo.getPrazo() * (-1) * 2.0 << std::endl;
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
            emprestimo.setLivros(nvLivro);
            std::cout << std::endl;
            std::cout << "----Nome do livro alterado com sucesso----" << std::endl;
            return true;

          case 2:
            std::cout << "Digite o novo nome do cliente: ";
            std::getline(std::cin, nvNome);
            emprestimo.setNomes(nvNome);
            std::cout << std::endl;
            std::cout << "----Nome do cliente alterado com sucesso----" << std::endl;
            return true;

          case 3:
            std::cout << "Digite o novo prazo: ";
            std::cin >> nvPrazo;
            getchar();
            emprestimo.setPrazo(nvPrazo);
            std::cout << std::endl;
            std::cout << "----Prazo alterado com sucesso----" << std::endl;
            return true;

          case 4:
            return true;
        }
}

int ClienteNormal::opcaoEditar(){
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
