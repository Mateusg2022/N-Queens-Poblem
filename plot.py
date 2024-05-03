import matplotlib.pyplot as plt
import numpy as np

def ler_matriz_do_arquivo(nome_arquivo):
    linhas = []

    with open(nome_arquivo, 'r') as arquivo:
        for linha in arquivo:
            linha_limpa = linha.strip()
            if linha_limpa:
                linhas.append([int(valor) for valor in linha_limpa.split()])

    matriz = np.array(linhas)
    return matriz

def plotar_tabuleiro_com_rainhas(matriz):
    fig, ax = plt.subplots()

    tabuleiro = np.zeros_like(matriz, dtype=int)
    tabuleiro[::2, ::2] = 1 
    tabuleiro[1::2, 1::2] = 1  
    tabuleiro[::2, 1::2] = 0 
    tabuleiro[1::2, ::2] = 0 

    ax.imshow(tabuleiro, cmap='binary', interpolation='nearest')

    for i in range(matriz.shape[0]):
        for j in range(matriz.shape[1]):
            if matriz[i, j] == 1:
                ax.text(j, i, '♛', fontsize=24, ha='center', va='center', color='red') #♛

    ax.set_xlim(-0.5, matriz.shape[1] - 0.5)
    ax.set_ylim(-0.5, matriz.shape[0] - 0.5)

    ax.set_xticks([])
    ax.set_yticks([])

    plt.title("NQueens 12x12")
    plt.show()

nome_arquivo = 'solucao.txt'
matriz_solucao = ler_matriz_do_arquivo(nome_arquivo)

plotar_tabuleiro_com_rainhas(matriz_solucao)