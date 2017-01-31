#!usr/bin/python
# DEFININDO O INTERPRETOR A SER UTILIZADO

#-*- conding: utf-8 -*-
# DEFININDO A CODIFICAÇÃO DE CARACTERES UTILIZADA

import serial #IMPORTANDO BIBLIOTECA SERIAL DO PYTHON
import time #IMPORTANDO BIBLIOTECA TIME DO PYTHON

# DEFININDO A VARIÁVEL QUE UTILIZAREMOS PARA FAZER A CONEXÃO SERIAL
serial = serial.Serial('COM5', 9600, timeout = 1)

# DEFININDO A PRIMEIRO FUNÇÃO
def control():
    while(1):
        #EXIBINDO AO USUÁRIO AS FUNÇÕES DISPONÍVEIS
        op = input('\nPorta 5 - LED Verde\nPorta 6 - LED Amarelo\nPorta 7 - LED Vermelho\n0 - Apagar LEDs\n\nOpção: ')
        #EVIANDO ATRAVÉS DA CONEXÃO SERIAL A OPÇÃO AO ARDUINO
        serial.write(op.encode())
        #RECEBENDO DADOS ENVIADOS PELA PLACA
        read = str(serial.read())
        #INICIANDO COMPARAÇÃO DOS DADOS RECEBIDOS
        if (read == "b'5'"):
            print('LED Verde aceso!')

        elif (read == "b'6'"):
            print('LED Amarelo aceso!')

        elif (read == "b'7'"):
            print('LED Vermelho aceso!')

        elif (read == "b'0'"):
            print('LEDs apagados!')

        else:
            print(read)

#DEFININDO A FUNÇÃO PRINCIPAL
def main():
    print('\n-=* ARDUINO *=-')
    print('\nAutor: Gabriel Barreto')
    print('\nContato: barreto-gabriel@outlook.com')
    print('Instituição: Fatec Itapetininga')
    print('\nComunicação Serial - Arduino -> Python')
    print('\n ***CONTROLANDO LEDS COM PYTHON***')
    #INICIANDO A FUNÇÃO DE CONTROLE
    control()

#INICIANDO A FUNÇÃO PRINCIPAL
main()
