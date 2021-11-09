#pragma once
#include <iostream>


class Emprestimo
{
    public:
        Emprestimo();
        Emprestimo(std::string livros, std::string nomes);
        virtual ~Emprestimo();

        void setLivros(std::string livros);
        void setNomes(std::string nomes);
        void setPrazo(int prazo);
        std::string getLivros();
        std::string getNomes();
        int getPrazo();

    protected:

    private:
        std::string livros;
        std::string nomes;
        int prazo;
};
