#include <stdio.h>

int r[9][10] = {}, c[9][10] = {}, square[3][3][10] = {}, mat[9][10] = {};

void print_table(int mat[][10], int k){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            printf("%d ", mat[i][j+k]);
        printf("\n");
    }
}

void solve(int n){
    int x = n/9, y = n%9;
    if(n == 81){
        print_table(mat, 0);
        return;
    }
    if(mat[x][y]){
        solve(n+1);
        return;
    }
    for(int i = 1; i < 10; i++)
        if(!r[x][i] && !c[y][i] && !square[x/3][y/3][i]){
            mat[x][y] = i;
            r[x][i] = c[y][i] = square[x/3][y/3][i] = 1;
            solve(n+1);
            r[x][i] = c[y][i] = square[x/3][y/3][i] = 0;
            mat[x][y] = 0;
        }
}

int main(){

    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++){
            scanf("%d", &mat[i][j]);
            r[i][mat[i][j]] = c[j][mat[i][j]] = square[i/3][j/3][mat[i][j]]= 1;
        }
    solve(0);

    return 0;
}
