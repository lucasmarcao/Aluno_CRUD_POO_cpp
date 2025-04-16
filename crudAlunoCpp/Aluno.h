#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <iostream>
#include <iomanip>

class Aluno
{
private:
    std::string RA;
    std::string nome;
    float coeficiente;
    std::string data_nascimento;

public:
    // Construtor
    Aluno(std::string ra, std::string nome, float coef, std::string data_nasc)
        : RA(ra), nome(nome), coeficiente(coef), data_nascimento(data_nasc) {}

    // Métodos de acesso
    std::string getRA() const { return RA; }
    std::string getNome() const { return nome; }
    float getCoeficiente() const { return coeficiente; }
    std::string getDataNascimento() const { return data_nascimento; }

    // Método para exibir os dados do aluno
    void exibirAluno() const
    {
        std::cout << "RA: " << RA
                  << " - Nome: " << nome << " . \n"
                  << "Coeficiente: " << coeficiente
                  << " - Data de Nascimento: " << data_nascimento << " .\n";
    }
};

#endif // ALUNO_H
