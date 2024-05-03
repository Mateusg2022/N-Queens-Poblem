#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
bool FirstFoundSolution = true;

#define fori(i,n) for(int i=0;i<N;i++)
#define forj(j,n) for(int j=0;j<N;j++)

//PARA MUDAR O TAMANHO DO TABULEIRO, MUDE '#DEFINE N 8' PARA '#DEFINE N <TAMANHO_DESEJADO>'
#define N 8

vector<vector<int>> board(N, vector<int>(N,0));

//columns, diag1, diag2 sao vetores que me dizem se existe rainha dominando a coluna,diagonal1 ou
//diagonal2 da casa atual

vector<int> columns(N,0);
//a quantidade de diagonais é sempre 2*N - 1
vector<int> diag1(2*N - 1);
vector<int> diag2(2*N - 1);

void print(long long int count){

  //imprime a primeira solucao em um arquivo
  //somente para plotar
  if(FirstFoundSolution){
    FirstFoundSolution=false;
    ofstream arquivo("solucao.txt");
    fori(i,n){
      forj(j,n){
        arquivo << board[i][j] << " ";
      }arquivo << endl;
    }

  }else{

    cout << "contador: " << count << endl;
    fori(i,n){
      forj(j,n){
        cout << board[i][j] << " ";
      }cout << endl;
    }cout << "-------------------------------------" << endl;

  }
}

void NQueens(int k, long long int& count){

  if(k == N){
    print(count);
    return;
  }

  fori(i,n){
    
    if(columns[i] || diag1[i+k] || diag2[i-k+N-1])
      continue;
  
    columns[i]=1;
    diag1[i+k]=1;
    diag2[i-k+N-1]=1;
    //backtracking
    board[k][i] = 1;
    count++;
    NQueens(k+1, count);
    //libero
    board[k][i] = 0;
    columns[i]=0;
    diag1[i+k]=0;
    diag2[i-k+N-1]=0;
  }

}

int main(){
  long long int count=0;
  NQueens(0, count);
  return 0;
}
