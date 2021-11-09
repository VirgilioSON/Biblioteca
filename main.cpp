#include "Emprestimo.h"
#include "Clientes.h"
#include "ClienteVip.h"
#include "ClienteNormal.h"
#include "Controle.h"
#include "BancoDeDados.h"
#include <iostream>
#include <locale.h>
#include <iomanip>
#include <vector>
#include <fstream>

#define PRAZO_VIP 60

int main(){
    std::fstream arq;
    Controle ctl;
    std::string livros, nomes, datas;
    std::string sArq1, sArq2, sArq3, sArq4;
    Emprestimo emp;
    std::vector<Clientes*> cl;
    Clientes *cls;
    BancoDeDados bdd;
    int opcao = 0;
    int loop = 1;
    int vip;
    std::string lvr;

    std::string procuraL, procuraN;
    int valorEdita;

    setlocale(LC_ALL, "Portuguese");

    arq.open("EmprestimoNormal.txt", std::ios::in);


    while(!arq.eof()){
        std::getline(arq, sArq1);
        if(sArq1 != ""){
            std::getline(arq, sArq2);
            std::getline(arq, sArq3);
            std::getline(arq, sArq4);
            if(sArq4 == "*"){
                cls = new Cliente::ClienteNormal();

                //sArq1 = nome
                //sArq2 = emprestimo
                //sArq3 = Prazo
                //sArq4 = *

                emp.setNomes(sArq1);
                emp.setLivros(sArq2);
                emp.setPrazo(stoi(sArq3));

                cls->AdicionaEmprestimo(emp, PRAZO_VIP);

                cl.push_back(cls);
            }else if(sArq4 == "/"){
                cls = new Cliente::ClienteVip();

                //sArq1 = nome
                //sArq2 = emprestimo
                //sArq3 = Prazo
                //sArq4 = /

                emp = Emprestimo(sArq2, sArq1);
                cls->AdicionaEmprestimo(emp,stoi(sArq3));

                emp = Emprestimo("/", sArq1);
                cls->AdicionaEmprestimo(emp,stoi(sArq3));

                cl.push_back(cls);

            }else{
                cls = new Cliente::ClienteVip();

                //sArq1 = nome
                //sArq2 = emprestimos[0]
                //sArq3 = Prazo
                //sArq4 = emprestimos[1]

                emp = Emprestimo(sArq2, sArq1);
                cls->AdicionaEmprestimo(emp, stoi(sArq3));

                emp = Emprestimo(sArq4, sArq1);
                cls->AdicionaEmprestimo(emp, stoi(sArq3));

                cl.push_back(cls);
            }
        }
    }




    arq.close();



    while(1){
        ctl.menuPrincipal();

        std::cin >> opcao;
        getchar();

        switch(opcao){
            case 1:
                loop = 1;
                while(loop){
                    system("cls");
                    ctl.menuBancoDeDados();
                    std::cin >> opcao;
                    std::cin.ignore();

                    switch(opcao){
                        case 1:
                            system("cls");
                            bdd.addLivro();
                            break;

                        case 2:
                            system("cls");
                            bdd.removeLivro();
                            system("cls");
                            break;

                        case 3:
                            system("cls");
                            bdd.mostraBanco();
                            break;

                        case 4:
                            loop = 0;
                            break;

                        default:
                            system("cls");
                            std::cout << "*****Opcao Invalida*****" << std::endl;
                            system("pause");
                            break;
                    }
                }
                system("cls");
                break;

            case 2:
                //adicionar um emprestimo
                system("cls");
                std::cout << "\nO cliente possui cartão VIP?\n"
                            "1 - Sim\n"
                            "2 - Não\n";
                std::cin >> vip;
                getchar();

                if(vip == 1){
                    cls = new Cliente::ClienteVip();

                }else{
                    cls = new Cliente::ClienteNormal();

                }

                std::cout << "Nome do cliente: ";
                std::getline(std::cin, nomes);

                std::cout << std::endl;
                std::cout << "Nome do livro: ";
                std::getline(std::cin, livros);

                lvr = bdd.entregaLivro(livros);
                if(lvr == "oi"){
                    std::cout << "opa1" << std::endl;
                    system("pause");
                    system("cls");
                    break;
                }
                std::cout << "opa2" << std::endl;
                emp = Emprestimo(lvr, nomes);
                cls->AdicionaEmprestimo(emp, PRAZO_VIP);
                if(vip == 1){
                    std::cout << "\nDeseja adicionar outro empréstimo?\n"
                                "1 - Sim\n"
                                "2 - Não\n";
                    std::cin >> vip;
                    getchar();

                    if(vip == 1){
                        std::cout << std::endl;
                        std::cout << "Nome do livro: ";
                        std::getline(std::cin, livros);

                        lvr = bdd.entregaLivro(livros);
                        if(lvr == "oi"){
                            system("pause");
                            system("cls");
                            break;
                        }

                        emp = Emprestimo(lvr, nomes);
                        cls->AdicionaEmprestimo(emp, PRAZO_VIP);

                        std::cout << std::endl;
                        std::cout << "----Empréstimo adicionado com sucesso----\n" << std::endl;
                        system("pause");
                        system("cls");
                    } else {
                        std::cout << std::endl;
                        std::cout << "----Empréstimo adicionado com sucesso----\n" << std::endl;
                        system("pause");
                        system("cls");
                    }
                } else {
                    std::cout << std::endl;
                    std::cout << "----Empréstimo adicionado com sucesso----\n" << std::endl;
                    system("pause");
                    system("cls");
                }
                cl.push_back(cls);
                break;

            case 3:
                //atualiza prazos

                for(int i = 0; i < cl.size(); i++){
                    cl[i]->AtualizaPrazo();
                }

                std::cout << std::endl;
                std::cout << "----Prazos atualizados com sucesso----\n" << std::endl;
                system("pause");
                system("cls");
                break;

            case 4:
                //Mostra lista
                system("cls");
                std::cout << std::endl;
                std::cout << "-------Lista de empréstimos-------" << std::endl;
                std::cout << std::endl;
                for(int i = 0; i < cl.size(); i++){
                    cl[i]->MostrarLista();
                }
                std::cout << std::endl;
                system("pause");
                system("cls");
                break;

            case 5:
                if(cl.size() != 0){
                    system("cls");
                    loop = 1;
                    while(loop){
                        switch(cl[0]->opcaoEditar()){
                            case 1:
                                std::cout << "Digite o nome do cliente: ";
                                std::getline(std::cin, procuraN);
                                std::cout << "Digite o nome do livro: ";
                                std::getline(std::cin, procuraL);

                                valorEdita = 0;
                                for(int i = 0; i < cl.size(); i++){
                                    valorEdita = cl[i]->ExcluirEmprestimo(procuraL, procuraN);
                                    if(valorEdita == 1){
                                        cl.erase(cl.begin()+i);
                                        std::cout << std::endl;
                                        std::cout << "----Empréstimo excluído com sucesso----" << std::endl;
                                        break;
                                    }
                                    if(valorEdita == 2){
                                        break;
                                    }
                                    if(cl.size() - i == 1){
                                        std::cout << "Empréstimo não encontrado" << std::endl;
                                    }
                                }
                                system("pause");
                                system("cls");
                                break;

                            case 2:

                                std::cout << "Digite o nome do cliente: ";
                                std::getline(std::cin, procuraN);
                                std::cout << "Digite o nome do livro: ";
                                std::getline(std::cin, procuraL);

                                for(int i = 0; i < cl.size(); i++){
                                    if(cl[i]->AlterarEmprestimo(procuraL, procuraN) == true)
                                        break;
                                    if(cl.size() - i == 1){
                                        std::cout << "Empréstimo não encontrado\n" << std::endl;
                                    }
                                }
                                system("pause");
                                system("cls");
                                break;

                            case 3:
                                loop = 0;
                                system("cls");
                                break;

                            default:
                                std::cout << "*****Opção inválida*****\n" << std::endl;
                                system("pause");
                                system("cls");
                        }
                    }
                }else{
                    std::cout << "Ainda não há nenhum empréstimo.\n" << std::endl;
                    system("pause");
                    system("cls");
                }

            break;

            case 6:

                arq.open("EmprestimoNormal.txt", std::ios::out);

                for(int i = 0; i < cl.size(); i++){
                    if(cl[i]->getVip() == true){
                        arq << cl[i]->getEmp(1).getNomes() + "\n";
                        arq << cl[i]->getEmp(1).getLivros() + "\n";
                        arq << std::to_string(cl[i]->getEmp(1).getPrazo()) + "\n";

                        if(cl[i]->getEmp(1).getLivros() != cl[i]->getEmp(2).getLivros() && cl[i]->getEmp(2).getLivros() != "/"){
                            arq << cl[i]->getEmp(2).getLivros() + "\n";
                            std::cout << "oi1\n";
                        }else{
                            arq << "/\n";
                        std::cout << "oi2\n";
                        }
                        std::cout << "oi3\n";
                    }
                }
                std::cout << "oi4\n";
                for(int i = 0; i < cl.size(); i++){
                    if(cl[i]->getVip() == false){
                        arq << cl[i]->getEmp(1).getNomes() + "\n";
                        arq << cl[i]->getEmp(1).getLivros() + "\n";
                        arq << std::to_string(cl[i]->getEmp(1).getPrazo()) + "\n";
                        arq << "*\n";
                    }
                }

                arq.close();

                for(int i = 0; i < cl.size(); i++){
                    delete cl[i];
                }
                cl.clear();

                std::cout << "Até a próxima!!!\n";
                return 0;

            default:
                std::cout << "*****Opção inválida*****\n" << std::endl;
                system("pause");
                system("cls");
        }
    }
}
