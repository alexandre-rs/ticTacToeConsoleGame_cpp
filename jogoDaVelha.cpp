#include <iostream>

using namespace std;

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << tabuleiro[i][j] << " ";
    }
    cout << endl;
  }
}

// Função para verificar se a jogada é válida
bool jogadaValida(char tabuleiro[3][3], int linha, int coluna) {
  if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
    return false;
  }
  return tabuleiro[linha][coluna] == ' ';
}

// Função para marcar a jogada no tabuleiro
void marcarJogada(char tabuleiro[3][3], int linha, int coluna, char simbolo) {
  tabuleiro[linha][coluna] = simbolo;
}

// Função para verificar se há vencedor
char verificarVencedor(char tabuleiro[3][3]) {
  // Verificar linhas
  for (int i = 0; i < 3; i++) {
    if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
      return tabuleiro[i][0];
    }
  }

  // Verificar colunas
  for (int i = 0; i < 3; i++) {
    if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
      return tabuleiro[0][i];
    }
  }

  // Verificar diagonais
  if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
    return tabuleiro[0][0];
  }
  if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
    return tabuleiro[0][2];
  }

  // Se não há vencedor, verificar se o jogo empatou
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tabuleiro[i][j] == ' ') {
        return ' ';
      }
    }
  }

  // Jogo empatado
  return 'E';
}

int main() {
  // Variáveis para o jogo
  char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  char jogador = 'X';
  int jogadas = 0;

  // Loop principal do jogo
  while (jogadas < 9) {
    exibirTabuleiro(tabuleiro);

    // Obter a jogada do jogador atual
    int linha, coluna;
    cout << "Jogador " << jogador << ", digite sua jogada (linha, coluna): ";
    cin >> linha >> coluna;

    // Validar a jogada
    while (!jogadaValida(tabuleiro, linha - 1, coluna - 1)) {
      cout << "Jogada inválida! Tente novamente: ";
      cin >> linha >> coluna;
    }

    // Marcar a jogada no tabuleiro
    marcarJogada(tabuleiro, linha - 1, coluna - 1, jogador);

    // Verificar se há vencedor
    char vencedor = verificarVencedor(tabuleiro);

    // Trocar o jogador
    if (jogador == 'X') {
      jogador = 'O';
    } else {
      jogador = 'X';
    }

    // Exibir mensagem de acordo com o resultado
    if (vencedor != ' ') {
      exibirTabuleiro(tabuleiro);
      cout << "O jogador " << vencedor << " venceu!" << endl;
      break;
    } else  if (vencedor == 'E') {
         cout << "Empate!" << endl;
        break;
    }
  }
  return 0;
}
