# **Projeto CRUD Aluno em C++**

Este projeto é uma implementação de um CRUD (Criar, Ler, Atualizar e Deletar) de uma classe `Aluno`, com interação através de arquivos. A classe `Aluno` possui informações como RA, nome, coeficiente e data de nascimento. O projeto é dividido em 4 arquivos principais: `Aluno.h`, `DAOAluno.h`, `GUIAluno.h` e `main.cpp`.

## **Estrutura do Projeto**

O código está dividido nos seguintes arquivos:

### 1. **`Aluno.h`**
   Contém a definição da classe `Aluno`, com atributos e métodos para acessar e exibir os dados do aluno.
   
### 2. **`DAOAluno.h`**
   Contém a classe `DAOAluno`, que realiza as operações de CRUD (interação com arquivos) para os alunos.

### 3. **`GUIAluno.h`**
   Contém a interface gráfica (no console) para interação do usuário, com opções de criar, listar, atualizar e excluir alunos.

### 4. **`main.cpp`**
   Ponto de entrada do programa. Inicializa a GUI e executa o menu interativo.

---

## **Como Executar**

### Pré-requisitos:

- **Compilador C++** (GCC, Clang, MSVC, etc.)
- **Ambiente de desenvolvimento** configurado para compilar e executar código C++.

### Passos:

1. Clone o repositório ou faça o download dos arquivos.
2. Compile os arquivos com um compilador C++. Exemplo de compilação com GCC:
   
   ```bash
   g++ -o crud_aluno Aluno.h DAOAluno.h GUIAluno.h main.cpp
   ```

3. Execute o programa compilado:
   
   ```bash
   ./crud_aluno
   ```

---

## **Como Funciona**

O programa segue um fluxo simples de operações CRUD:

1. **Criar** um novo aluno, onde o usuário fornece os dados do aluno (RA, nome, coeficiente e data de nascimento) e o aluno é adicionado ao arquivo.
   
2. **Listar** todos os alunos armazenados no arquivo.
   
3. **Atualizar** os dados de um aluno, identificando-o pelo RA e modificando as informações.
   
4. **Excluir** um aluno, removendo-o do arquivo com base no RA fornecido.

---

## **Estrutura de Classes e Funções**

### **`Aluno.h`** - Definição da classe `Aluno`

- **Atributos:**
  - `RA`: Número de matrícula do aluno.
  - `nome`: Nome do aluno.
  - `coeficiente`: Coeficiente de rendimento acadêmico.
  - `data_nascimento`: Data de nascimento do aluno.

- **Métodos:**
  - `getRA()`, `getNome()`, `getCoeficiente()`, `getDataNascimento()`: Métodos de acesso para os atributos.
  - `exibirAluno()`: Método para exibir as informações de um aluno.

#### **Documentação C++:**
- [Manipulação de strings em C++](https://en.cppreference.com/w/cpp/string/basic_string)
- [Streams de entrada e saída em C++](https://en.cppreference.com/w/cpp/io)

### **`DAOAluno.h`** - Interação com Arquivos

- **Métodos:**
  - `criarAluno(const Aluno& aluno)`: Cria um novo aluno no arquivo.
  - `lerAlunos()`: Lê todos os alunos do arquivo.
  - `atualizarAluno(const Aluno& aluno)`: Atualiza os dados de um aluno no arquivo.
  - `excluirAluno(const std::string& ra)`: Exclui um aluno do arquivo com base no RA.

#### **Documentação C++:**
- [Manipulação de arquivos em C++](https://en.cppreference.com/w/cpp/io/fstream)
- [Vetores em C++](https://en.cppreference.com/w/cpp/container/vector)

### **`GUIAluno.h`** - Interface Gráfica (Console)

- **Métodos:**
  - `exibirMenu()`: Exibe o menu para o usuário e chama as funções CRUD.
  - `adicionarAluno()`: Lê os dados e adiciona um novo aluno.
  - `listarAlunos()`: Exibe todos os alunos cadastrados.
  - `atualizarAluno()`: Atualiza os dados de um aluno existente.
  - `excluirAluno()`: Exclui um aluno pelo RA.

#### **Documentação C++:**
- [Entrada e saída em C++](https://en.cppreference.com/w/cpp/io)
- [Laços de repetição e controle de fluxo](https://en.cppreference.com/w/cpp/language/for)

### **`main.cpp`** - Ponto de Entrada

- O `main.cpp` apenas chama a função `exibirMenu()` da classe `GUIAluno` para iniciar o fluxo de interação com o usuário.

#### **Documentação C++:**
- [Função main em C++](https://en.cppreference.com/w/cpp/language/main_function)

---

## **Tecnologias Utilizadas**

- **C++:** Linguagem de programação orientada a objetos usada para implementar o CRUD e manipulação de arquivos.
- **Streams (fstream):** Utilizado para ler e escrever dados em arquivos.
- **Vetores (std::vector):** Usado para armazenar os alunos temporariamente antes de interagir com o arquivo.
- **Funções de manipulação de strings (std::string):** Para facilitar o processamento de dados como o nome, RA e data de nascimento.

---

## **Checklist de Funcionalidades**

- [x] **Adicionar aluno** (CRUD)
- [x] **Listar alunos** (CRUD)
- [x] **Atualizar aluno** (CRUD)
- [x] **Excluir aluno** (CRUD)
- [x] **Armazenamento persistente em arquivo** (Arquivo `alunos.dat`)
- [x] **Menu interativo via console**

---

## **Melhorias Futuras**

- [ ] Implementar validação de dados (por exemplo, validar se o RA é único ou se a data está no formato correto).
- [ ] Implementar uma interface gráfica (GUI) para interação com o usuário.
- [ ] Adicionar manipulação de exceções para lidar com possíveis erros de leitura e escrita em arquivos.
- [ ] Permitir a pesquisa de alunos por nome ou RA.

---

## **Links Úteis**

- [Documentação C++ - cppreference](https://en.cppreference.com/)
- [Guia do C++ para iniciantes - Cplusplus.com](http://www.cplusplus.com/)
- [C++ Input/Output - Cplusplus.com](http://www.cplusplus.com/doc/tutorial/files/)

---

## **Licença**

Este projeto é de código aberto e distribuído sob a Licença MIT. Sinta-se à vontade para modificar e contribuir com o código.

---

Este `README.md` fornece um guia completo para entender, compilar, executar e melhorar o seu projeto de CRUD de alunos em C++.