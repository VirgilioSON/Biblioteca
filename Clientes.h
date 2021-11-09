#pragma once
#include "Emprestimo.h"

class Clientes
{
    public:
        Clientes();
        virtual ~Clientes();

        virtual bool getVip() = 0;
        virtual void AdicionaEmprestimo(Emprestimo emp, int data) = 0;
        virtual void setEmp(Emprestimo emp) = 0;
        virtual Emprestimo getEmp(int op) = 0;
        virtual void AtualizaPrazo() = 0;
        virtual void MostrarLista() = 0;
        virtual int ExcluirEmprestimo(std::string procuraL, std::string procuraN) = 0;
        virtual bool AlterarEmprestimo(std::string procuraL, std::string procuraN) = 0;
        virtual int opcaoEditar() = 0;


    protected:


    private:

};
