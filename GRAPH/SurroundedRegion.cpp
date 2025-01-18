class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int row, int col){
        if(i<0 || j<0 || i>=row || j>=col || board[i][j] != 'O') return;
        board[i][j] = '#';
        dfs(board, i+1, j, row, col);
        dfs(board, i, j+1, row, col);
        dfs(board, i-1, j, row, col);
        dfs(board, i, j-1, row, col);
    }


    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        // traversing through boundaries

        // traversing vertically
        for(int i=0; i<row; i++){
            if(board[i][0] == 'O') dfs(board, i, 0, row, col);

            if(board[i][col-1]=='O') dfs(board, i, col-1, row, col);
        }

        // traversing horizontally
        for(int j=0; j<col; j++){
            if(board[0][j] == 'O') dfs(board, 0, j, row, col);

            if(board[row-1][j] == 'O') dfs(board, row-1, j, row, col);
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
        
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }



    }
};


// we can do this anyways either BFS or DFS
// Algorithm:-
// first get the indices of  boundary elements mostly 1

// check if there exist a neighbour of 1 which is also a 1

// ignore all of its nbd 

// and remaining elements can be surrounded completely



1020. Number of Enclaves (one such example using bfs);


class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;

        queue<pair<int,int> > q;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    if(i==0 || j==0 || i==row-1 || j==col-1){
                        q.push({i,j});
                        grid[i][j] = 0; //marking them visited
                    }
                } 
            }
        }

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && ny>=0 && nx<row && ny<col && grid[nx][ny] == 1){
                    q.push({nx,ny});

                    // we are upgrading the boundary element because we have to calculate the non boundary elements which we can easily calculate by double iteration as the boundary 1s has become 0 now so only remaining 1s are non boundary 1s
                    grid[nx][ny] = 0;
                }
            }
        }

        // gettin the remaining 1s
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    ans++;
                }
            }
        }


        return ans;
        
    }
}; 