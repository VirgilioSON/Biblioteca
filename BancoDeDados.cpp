#include "BancoDeDados.h"
#include <locale.h>


BancoDeDados::BancoDeDados(){
}

std::string BancoDeDados::entregaLivro(std::string livro){
    std::fstream arq;
    std::vector<std::string> livroArq, lAchou;
    std::string procura, removido;
    int op;

    arq.open("BancoDeDados.txt", std::ios::in);
    if(!arq.is_open()){
        std::cout << "*****Não foi possivel abrir arquivo do Banco de Dados*****" << std::endl;
    }

    do{
        std::getline(arq, procura);

        livroArq.push_back(procura); //salvando o arquivo inteiro

        if(procura.find(livro) != std::string::npos){
            lAchou.push_back(procura); //salvando os nomes parecidos
        }

    }while(!arq.eof());
    arq.close();

    if(lAchou.size() > 0){
        for(int i = 0; i < lAchou.size()-1; i++){
            for(int j = i+1; j < lAchou.size(); j++){
                if(lAchou[i] == lAchou[j])
                    lAchou.erase(lAchou.begin()+j);
            }
        }
    }

    if(lAchou.size() == 1){
        std::cout << "\nDeseja mesmo " << lAchou[0] << "?" << std::endl
                  << "1 - Sim" << std::endl
                  << "2 - Não" << std::endl;
        std::cin >> op;

        if(op == 2){
            return "oi";
        }

        removido = lAchou[0];

    //achou mais de 1
    }else if(lAchou.size() > 1){
        std::cout << "\nLivros encontrados:" << std::endl;


        for(int i = 0; i < lAchou.size(); i++){
            std::cout << " " << i + 1 << " - " << lAchou[i] << std::endl;
        }

        std::cout << "\nDigite o número do livro que você deseja (0 para retornar):" << std::endl;
        std::cin >> op;

        if(op == 0){
            return "oi";
        }

        removido = lAchou[op - 1];

    //não achou
    }else{
        std::cout << "\n*****Nenhum livro foi encontrado*****\n" << std::endl;
        return "oi";
    }

    ///Reescrever o arquivo sem o livro removido
    arq.open("BancoDeDados.txt", std::ios::out);

    bool removeu = false;//Variável que mostra se ja excluiu ou não o livro
    for(int i = 0; i < livroArq.size(); i++){
        if(livroArq[i] != removido && livroArq[i] != ""){
            arq << livroArq[i] + "\n";
        } else if(removeu == false && livroArq[i] != ""){
            //Se for a primeira vez, ele não escreve no arquivo e a variavel msotra que foi excluido
            removeu = true;
        } else if(livroArq[i] != ""){
            //Se ja passou da primeira vez ele escreve no arquivo mesmo sendo o nome removido
            arq << livroArq[i] + "\n";
        }
    }

    arq.close();

    std::cout << "opa" << std::endl;
    return removido;
}

void BancoDeDados::devolveLivro(std::string livro){
    std::ofstream arq;

    arq.open("BancoDeDados.txt", std::ios::app);

    arq << livro + "\n";

    arq.close();
}

void BancoDeDados::addLivro(){
    setlocale(LC_ALL, "Portuguese");

    std::ofstream arq;
    std::string livro;
    int op;

    arq.open("BancoDeDados.txt", std::ios::app);

    while(1){
        std::cout << "Digite o livro que deseja adicionar no banco de dados: " << std::endl;
        std::getline(std::cin, livro);
        std::cout << std::endl;

        arq << livro + "\n";

        std::cout << "Deseja adicionar outro livro?" << std::endl
                  << "1 - Sim" << std::endl
                  << "2 - Não" << std::endl;
        std::cin >> op;
        std::cin.ignore();

        if(op == 2){
            break;
        }

        system("cls");
    }

    system("cls");

    arq.close();
}

void BancoDeDados::removeLivro(){
    setlocale(LC_ALL, "Portuguese");

    std::fstream arq;
    std::string livro, procura, removido;
    std::vector<std::string> lAchou, livroArq;
    int op;

    ///livro para ser retirado
    std::cout << "Digite o nome do livro que deseja retirar do banco de dados:" << std::endl;
    std::getline(std::cin, livro);

    ///procura o livro no arquivo
    arq.open("BancoDeDados.txt", std::ios::in);
    if(!arq.is_open()){
        std::cout << "*****Não foi possivel abrir arquivo do Banco de Dados*****" << std::endl;
    }

    do{
        std::getline(arq, procura);

        livroArq.push_back(procura); //salvando o arquivo inteiro

        if(procura.find(livro) != std::string::npos){
            lAchou.push_back(procura); //salvando os nomes parecidos
        }

    }while(!arq.eof());
    arq.close();

    //retira nomes repetidos do vector lAchou
    for(int i = 0; i < lAchou.size()-1; i++){
        for(int j = i+1; j < lAchou.size(); j++){
            if(lAchou[i] == lAchou[j])
                lAchou.erase(lAchou.begin()+j);
        }
    }

    ///Conferir a quantidade de livros achados para definir o livro que será removido
    //achou 1
    if(lAchou.size() == 1){
        std::cout << "\nDeseja excluir " << lAchou[0] << " do Banco de Dados?" << std::endl
                  << "1 - Sim" << std::endl
                  << "2 - Não" << std::endl;
        std::cin >> op;

        if(op == 2){
            return;
        }

        removido = lAchou[0];

    //achou mais de 1
    }else if(lAchou.size() > 1){
        std::cout << "\nLivros encontrados:" << std::endl;


        for(int i = 0; i < lAchou.size(); i++){
            std::cout << " " << i + 1 << " - " << lAchou[i] << std::endl;
        }

        std::cout << "\nDigite o numero do livro que deseja excluir (0 para retornar):" << std::endl;
        std::cin >> op;

        if(op == 0){
            return;
        }

        removido = lAchou[op - 1];

    //não achou
    }else{
        std::cout << "\n*****Nenhum livro foi encontrado*****\n" << std::endl;
        system("pause");
        return;
    }

    ///Reescrever o arquivo sem o livro removido
    arq.open("BancoDeDados.txt", std::ios::out);

    bool removeu = false;//Variável que mostra se ja excluiu ou não o livro
    for(int i = 0; i < livroArq.size(); i++){
        if(livroArq[i] != removido && livroArq[i] != ""){
            arq << livroArq[i] + "\n";
        } else if(removeu == false && livroArq[i] != ""){
            //Se for a primeira vez, ele não escreve no arquivo e a variavel msotra que foi excluido
            removeu = true;
        } else if(livroArq[i] != ""){
            //Se ja passou da primeira vez ele escreve no arquivo mesmo sendo o nome removido
            arq << livroArq[i] + "\n";
        }
    }

    arq.close();

    std::cout << "\nLivro excluído com sucesso!\n" << std::endl;
    system("pause");
}

void BancoDeDados::mostraBanco(){
    setlocale(LC_ALL, "Portuguese");

    std::ifstream arq;
    std::string livro;
    std::vector<std::string> livros;

    std::cout << "Livros disponíveis:" << std::endl;

    arq.open("BancoDeDados.txt");
    if(!arq.is_open()){
        std::cout << "*****Não foi possivel abrir arquivo do Banco de Dados*****" << std::endl;
    }

    do{
        std::getline(arq, livro);
        livros.push_back(livro);

    }while(!arq.eof());

    //Retira nomes repetidos do lAchou
    int flag;
    for(int i = 0; i < livros.size(); i++){
        flag = 0;
        for(int j = i+1; j < livros.size(); j++){
            if(i!= livros.size()-1){
                if(livros[i] == livros[j]){
                    livros.erase(livros.begin()+j);
                    flag++;
                }
            }
        }
        if(flag == 0 && livros[i] != ""){
            livros[i] += " (1)";
        }else if(livros[i] != ""){
            livros[i] += " (" + std::to_string(flag+1) + ")";
        }
    }

    for(int i = 0; i < livros.size(); i++){
        if(livros[i] != ""){
            std::cout << "   - " << livros[i] << std::endl;
        }
    }


    std::cout << std::endl;
    system("pause");
    system("cls");

    arq.close();
}
