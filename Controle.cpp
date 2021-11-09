#include <iostream>
#include "Controle.h"

using namespace std;


Controle::Controle()
{
    //ctor
}

Controle::~Controle()
{
    //dtor
}

void Controle::menuPrincipal(){
    std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
                "Ol�, bem-vindo(a) ao Menu de empr�stimo da Biblioteca!\n"
                "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << std::endl;
    std::cout << std::endl;
    std::cout << "--------Escolha opera��o--------";
    std::cout << std::endl;
    std::cout << "\n1 - Menu do Banco de Dados\n"
                "2 - Adicionar um empr�stimo\n"
                "3 - Atualizar datas de empr�stimo\n"
                "4 - Mostrar lista de empr�stimos\n"
                "5 - Editar empr�stimo\n"
                "6 - Sair do programa\n" << std::endl;

}

void Controle::menuBancoDeDados(){
    std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
                "              Menu do Banco de Dados\n"
                "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n" << std::endl;
    std::cout << "--------Escolha opera��o--------\n" << std::endl
              << "1 - Adicionar livro no banco de dados" << std::endl
              << "2 - Retirar livro do banco de dados" << std::endl
              << "3 - Mostrar banco de dados" << std::endl
              << "4 - Voltar" << std::endl;
}
