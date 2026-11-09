#pragma once
#include "usuario.h"

extern Usuario usrAtual;

int menu();
void consultSaldo(Usuario *usr);
int mostrarTransacoes(Usuario *usr);
void listarReceitas(Usuario *usr);
void listarDespesas(Usuario *usr);
void listarTodas(Usuario *usr);
void cadastrarTransacao(Usuario *usuario);
int removerTransacoes(Usuario *usr);
void editarTransacao(Usuario *usr);
