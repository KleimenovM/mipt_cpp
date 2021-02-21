#include <iostream>

int find_neighbours(int * *matr, int x, int y, int N, int M) {
    int shift[3] = {-1, 0, 1};
    int counter = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (x + shift[i] < 0 || x + shift[i] > N - 1)
                continue;
            else if (y + shift[j] < 0 || y + shift[j] > M - 1)
                continue;
            else if (matr[x + shift[i]][y + shift[j]] == -1)
                counter ++;
        }
    }
    return counter;
}

int main()
{
    int N, M, K;
    std::cin >> N; // lines
    std::cin >> M; // columns
    std::cin >> K; // mines

    int **matr = new int*[N];

    for (int i = 0; i < N; i++)
        matr[i] = new int[M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            matr[i][j] = 0;
    }

    int x, y; // place mines
    for (int k = 0; k < 2 * K; k += 2) {
        std::cin >> x;
        std::cin >> y;
        matr[x-1][y-1] = -1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matr[i][j] == -1) continue;
            else matr[i][j] = find_neighbours(matr, i, j, N, M);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) std::cout << matr[i][j] << ' ';
        std::cout << std::endl;
    }

    for (int i = 0; i < N; i++) delete []matr[i];
        delete []matr;

    return 0;
}
