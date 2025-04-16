#include <iostream>
#include "GUIAluno.h"

//  g++ main.cpp Aluno.h GUIAluno.h DAOAluno.h -o Aplicativo.exe
//  ./Aplicativo.exe
int main() {
    GUIAluno gui;
    gui.exibirMenu();
    return 0;
}
