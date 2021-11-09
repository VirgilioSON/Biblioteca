#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class BancoDeDados{
    public:
        BancoDeDados();
        ///a fazer
        std::string entregaLivro(std::string livro);
        void devolveLivro(std::string livro);

        void addLivro();
        void removeLivro();
        void mostraBanco();
        void menu();
};
