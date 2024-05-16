**N-Queens's Poblem**

autoria: Mateus Augusto Gomes

livro de estudo: Competitive Programmer's Handbook - Antti Laaksonen

Tópico: Backtracking

Encontrar uma maneira de colocar N rainhas em um tabuleiro NxN sem que exista duas rainhas 
que possam atacar uma à outra.
Ou seja:

	Invalido:
 
		- 2 ou mais rainhas na mesma linha
		- 2 ou mais rainhas na mesma coluna
		- 2 ou mais rainhas na mesma diagonal
  
O programa em C++ encontra todas as soluçoes e as imprime na saída padrão, com exceção da primeira,
que é impressa no arquivo 'solucao.txt'. Isso é feito para que o programa em python possa
usar essa solucao para um plot visual ao usuário.

<div align="center">
<img src="https://github.com/Mateusg2022/N-Queens-Poblem/assets/168873690/6a960bf4-c8a9-48e5-9e7c-19c0d9394752.png"
" width="900px" />
</div>

Para N = 27 existem 234907967154122528 soluções. N >= 15 pode provocar um processo demorado.
