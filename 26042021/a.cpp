#include <iostream>

int find_max(int a, int b){
    if (a > b)
        return  a;
    else
        return b;
}

int **allocate_grid(int size_y, int size_x){
    int** grid = new int *[size_y];
    for (int i = 0; i < size_y; i++)
        grid[i] = new int [size_x];

    return grid;
}

void clear_grid(int **grid, int n, int m){
    for (int i = 0; i < n; i++){
        delete grid[i];
    }

    delete grid;
}

int max_coins(int **grid, int n, int m){
    int **coins_grid = allocate_grid(n, m);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            coins_grid[i][j] = 0;
    }

    for (int i = n - 1; i >= 0; i--){
        for (int j = m - 1; j >= 0; j--){
            if (i == n - 1 && j == m - 1)
                coins_grid[i][j] = grid[i][j];
            else{
                int val, val_1 = 0, val_2 = 0;
                if (i + 1 < n)
                    val_1 = coins_grid[i+1][j];
                if (j + 1 < m)
                    val_2 = coins_grid[i][j+1];
                val = find_max(val_1, val_2);
                coins_grid[i][j] = grid[i][j] + val;
            }
        }
    }
    int ans = coins_grid[0][0];
    clear_grid(coins_grid, n, m);

    return ans;
}

int main(){
    int n, m;
    std::cin >> n >> m;

    int **grid = allocate_grid(n, m);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            std::cin >> grid[i][j];
    }

    // filled 2-dimensional grid with information about coins

    std::cout << max_coins(grid, n, m) << std::endl;

    clear_grid(grid, n, m);

    return 0;
}
