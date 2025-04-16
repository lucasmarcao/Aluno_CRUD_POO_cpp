#ifndef GUIALUNO_H
#define GUIALUNO_H

#include "DAOAluno.h"
#include <iostream>

class GUIAluno
{
private:
    DAOAluno dao;

public:
    void exibirMenu()
    {
        int opcao;
        do
        {
            std::cout << "\nMenu Aluno:\n";
            std::cout << "1. Adicionar Aluno\n";
            std::cout << "2. Listar Alunos\n";
            std::cout << "3. Atualizar Aluno\n";
            std::cout << "4. Excluir Aluno\n";
            std::cout << "5. Sair\n";
            std::cout << "Escolha uma opcao: ";
            std::cin >> opcao;
            std::cin.ignore(); // Limpa o buffer do cin

            switch (opcao)
            {
            case 1:
                adicionarAluno();
                break;
            case 2:
                listarAlunos();
                break;
            case 3:
                atualizarAluno();
                break;
            case 4:
                excluirAluno();
                break;
            case 5:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
                break;
            }
        } while (opcao != 5);
    }

private:
    void adicionarAluno()
    {
        std::string ra, nome, data_nasc;
        float coeficiente;

        std::cout << "RA: ";
        std::getline(std::cin, ra);
        std::cout << "Nome: ";
        std::getline(std::cin, nome);
        std::cout << "Coeficiente: ";
        std::cin >> coeficiente;
        std::cin.ignore(); // Limpa o buffer
        std::cout << "Data de Nascimento (dd/mm/yyyy): ";
        std::getline(std::cin, data_nasc);

        Aluno aluno(ra, nome, coeficiente, data_nasc);
        dao.criarAluno(aluno);
        std::cout << "Aluno adicionado com sucesso!\n";
    }

    void listarAlunos()
    {
        std::vector<Aluno> alunos = dao.lerAlunos();
        for (const auto &aluno : alunos)
        {
            aluno.exibirAluno();
            std::cout << "----------------------------\n";
        }
    }

    void atualizarAluno()
    {
        std::string ra;
        std::cout << "Digite o RA do aluno a ser atualizado: ";
        std::getline(std::cin, ra);

        // Busca o aluno
        std::vector<Aluno> alunos = dao.lerAlunos();
        Aluno alunoAtualizado("", "", 0.0, "");

        for (auto &aluno : alunos)
        {
            if (aluno.getRA() == ra)
            {
                std::string nome, data_nasc;
                float coeficiente;

                std::cout << "Novo nome (atual: " << aluno.getNome() << "): ";
                std::getline(std::cin, nome);
                std::cout << "Novo coeficiente (atual: " << aluno.getCoeficiente() << "): ";
                std::cin >> coeficiente;
                std::cin.ignore();
                std::cout << "Nova data de nascimento (atual: " << aluno.getDataNascimento() << "): ";
                std::getline(std::cin, data_nasc);

                alunoAtualizado = Aluno(ra, nome, coeficiente, data_nasc);
                dao.atualizarAluno(alunoAtualizado);
                std::cout << "Aluno atualizado com sucesso!\n";
                break;
            }
        }
    }

    void excluirAluno()
    {
        std::string ra;
        std::cout << "Digite o RA do aluno a ser excluído: ";
        std::getline(std::cin, ra);
        dao.excluirAluno(ra);
        std::cout << "Aluno excluído com sucesso!\n";
    }
};

#endif // GUIALUNO_H
