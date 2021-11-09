#pragma once
#include "Emprestimo.h"
#include <vector>

namespace Cliente{
class ClienteVip:public Clientes
{
    public:
        ClienteVip();
        virtual ~ClienteVip();

        bool getVip();
        void AdicionaEmprestimo(Emprestimo emp, int data);
        void setEmp(Emprestimo emp);
        Emprestimo getEmp(int op);
        void AtualizaPrazo();
        void MostrarLista();
        int ExcluirEmprestimo(std::string procuraL, std::string procuraN);
        bool AlterarEmprestimo(std::string procuraL, std::string procuraN);
        int opcaoEditar();



    protected:

    private:
        std::vector<Emprestimo> emprestimos;
};
}
