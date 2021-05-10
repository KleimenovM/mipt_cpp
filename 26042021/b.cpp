#include <iostream>
#include <string>

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

void clear_grid(int **grid, int n){
    for (int i = 0; i < n; i++){
        delete[] grid[i];
    }
    delete[] grid;
}

int **max_coins(int **grid, int n, int m){
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
    clear_grid(grid, n);
    return coins_grid;
}

char *find_way(int **grid, int n, int m){
    char *way = new char[n + m - 2];
    int y = 0, x = 0;
    for (int i = 0; i < n + m - 2; i++){
        if (x + 1 >= n){
            y++;
            way[i] = 'R';
            continue;
        }
        if (y + 1 >= m){
            x++;
            way[i] = 'D';
            continue;
        }
        if (grid[x+1][y] > grid[x][y + 1]){
            x++;
            way[i] = 'D';
        } else {
            y++;
            way[i] = 'R';
        }
    }
    return way;
}

int main(){
    int n, m;
    std::cin >> n >> m;

    int **grid = allocate_grid(n, m);
    char *way;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            std::cin >> grid[i][j];
    }

    grid = max_coins(grid, n, m);

    way = find_way(grid, n, m);

    clear_grid(grid, n);
    for (int i = 0; i < n + m - 2; i++)
        std::cout << way[i] << std::endl;

    delete[] way;

    return 0;
}
