cmake_minimum_required(VERSION 3.13)
project(LingProg)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Aula04
        Aula4.cpp
        agenda.h
        agenda.cpp
        agenda_array.h
        agenda_array.cpp
        agenda_classe.h
        agenda_classe.cpp
        agenda_classe_vector.h
        agenda_classe_vector.cpp
        grafos.h
        grafos.cpp)

add_executable(Aula05
        Aula5.cpp
        agenda_ponteiro.cpp
        agenda_ponteiro.h
        grafo_arquivo.cpp
        grafo_arquivo.h)

add_executable(Aula06
        Aula6.cpp
        nome.h
        nome.cpp
        nome_ponteiro.h
        nome_ponteiro.cpp
        Relogio.h
        Relogio.cpp
        RelogioP.h
        RelogioP.cpp)

add_executable(Aula07
        Aula7.cpp
        carrinho.cpp
        carrinho.h
        jogo.cpp
        jogo.h)

add_executable(Aula08
        Aula8.cpp
        forca.cpp
        forca.h
        pilha.cpp
        pilha.h)

add_executable(Aula09
        Aula9.cpp
        agenda_overload.cpp
        agenda_overload.h
        agenda_herda_vetor.cpp
        agenda_herda_vetor.h)