#!/bin/bash
function compilar(){
    echo "Compilando..."
    if gcc -g -Wall main.c -o main; then
        return true;
    else
        return false;
    fi
}

function executar(){
    jogar="";
    if [ -f ./main ]; then
        read -p "Jogar? [S/n]: " jogar
        if [ $jogar = "S" ] || [ $jogar = "s" ]; then
            ./main
            # echo "Volte sempre!"
            return;
        else
            # echo "Da proxima tente jogar!"
            return;
        fi
    else
        echo "Erro ao inicar o jogo"
    fi
}

function verificarMain(){
    if [ -f ./main.c ]; then
        return true;
    else
        return false;
    fi    
}

function verificarLibs(){
    if [ -f ./cartela.h ] && [ -f ./numeros.h ] && [ -f ./rack.h ]; then
        return true;
    else
        return false;
    fi
}

if [ verificarMain ]; then
    if [ verificarLibs ]; then
        if [ compilar ]; then
            echo "Compilado!"
            executar
        else
            echo "Erro ao compilar"
        fi
    else
        echo "Esta faltando alguma(s) bibliotecas"
    fi
else
    echo "Esta faltando o arquivo main.c"
fi