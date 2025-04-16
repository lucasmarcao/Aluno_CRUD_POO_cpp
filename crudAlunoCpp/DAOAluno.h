#ifndef DAOALUNO_H
#define DAOALUNO_H

#include "Aluno.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

class DAOAluno {
private:
    std::string nome_arquivo = "alunos.dat";

public:
    // Função para criar (adicionar) um aluno ao arquivo
    void criarAluno(const Aluno& aluno) {
        std::ofstream arquivo(nome_arquivo, std::ios::app);
        if (arquivo.is_open()) {
            arquivo << aluno.getRA() << "," 
                    << aluno.getNome() << ","
                    << aluno.getCoeficiente() << ","
                    << aluno.getDataNascimento() << "\n";
            arquivo.close();
        } else {
            std::cerr << "Erro ao abrir arquivo para criação\n";
        }
    }

    // Função para ler todos os alunos do arquivo
    std::vector<Aluno> lerAlunos() {
        std::vector<Aluno> alunos;
        std::ifstream arquivo(nome_arquivo);
        std::string linha;
        
        while (std::getline(arquivo, linha)) {
            std::stringstream ss(linha);
            std::string ra, nome, data_nasc;
            float coeficiente;

            std::getline(ss, ra, ',');
            std::getline(ss, nome, ',');
            ss >> coeficiente;
            ss.ignore();
            std::getline(ss, data_nasc);

            alunos.push_back(Aluno(ra, nome, coeficiente, data_nasc));
        }
        return alunos;
    }

    // Função para atualizar o aluno (baseado no RA)
    void atualizarAluno(const Aluno& aluno) {
        std::vector<Aluno> alunos = lerAlunos();
        std::ofstream arquivo(nome_arquivo, std::ios::trunc);
        
        if (arquivo.is_open()) {
            for (const auto& a : alunos) {
                if (a.getRA() == aluno.getRA()) {
                    arquivo << aluno.getRA() << ","
                            << aluno.getNome() << ","
                            << aluno.getCoeficiente() << ","
                            << aluno.getDataNascimento() << "\n";
                } else {
                    arquivo << a.getRA() << ","
                            << a.getNome() << ","
                            << a.getCoeficiente() << ","
                            << a.getDataNascimento() << "\n";
                }
            }
            arquivo.close();
        } else {
            std::cerr << "Erro ao abrir arquivo para atualização\n";
        }
    }

    // Função para excluir aluno
    void excluirAluno(const std::string& ra) {
        std::vector<Aluno> alunos = lerAlunos();
        std::ofstream arquivo(nome_arquivo, std::ios::trunc);
        
        if (arquivo.is_open()) {
            for (const auto& a : alunos) {
                if (a.getRA() != ra) {
                    arquivo << a.getRA() << ","
                            << a.getNome() << ","
                            << a.getCoeficiente() << ","
                            << a.getDataNascimento() << "\n";
                }
            }
            arquivo.close();
        } else {
            std::cerr << "Erro ao abrir arquivo para exclusão\n";
        }
    }
};

#endif // DAOALUNO_H
