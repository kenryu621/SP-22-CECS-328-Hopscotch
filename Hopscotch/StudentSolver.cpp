#include "StudentSolver.h"

int change_idx(int, int, int);

int recurrsion(std::vector<std::vector<int>>&, int, int, int, std::vector<std::vector<std::vector<int>>>&);

std::vector<int> StudentSolver::solve(std::vector<std::vector<int>> grid) {
	std::vector<int> answer;
	int max_row, max_col, highest_sum;
	std::vector<std::vector<int>> temp_grid;
	std::vector<std::vector<std::vector<int>>> path_grid, highest_path_grid;
	bool first_run = true;
	for (int i = 0; i < grid[0].size(); i++) {
		for (int j = 0; j < 2; j++) {
			// Initialize path grid
			path_grid = std::vector<std::vector<std::vector<int>>>(grid.size(), std::vector<std::vector<int>>(grid[0].size(), std::vector<int>(1, 3)));
			int set_null_col = i, set_null = grid.size() - 2, set_null_row = 1;
			while (set_null > 0) {
				for (int r = set_null_row; r < path_grid.size() - set_null_row; r++)
					path_grid[r][change_idx(set_null_col, -1, path_grid[r].size())][0] = 2;
				set_null_col--;
				set_null -= 2;
				set_null_row++;
			}
			temp_grid = grid;
			int row_idx = j == 0 ? grid.size() - 1 : 0;
			int opponent = recurrsion(temp_grid, row_idx, i, i, path_grid);
			if (first_run || highest_sum < opponent) {
				first_run = false;
				max_row = j;
				max_col = i;
				highest_sum = opponent;
				answer = path_grid[row_idx][max_col];
				highest_path_grid = path_grid;
			}
		}
	}
	answer.insert(answer.begin(), { max_row, max_col });
	return answer;
}

int change_idx(int curr, int direction, int size) {
	int new_idx = curr + direction;
	if (new_idx >= size)
		new_idx %= size;
	else if (new_idx < 0)
		new_idx += size;
	return new_idx;
}

int recurrsion(std::vector<std::vector<int>>& grid, int curr_row, int curr_col, int start_col, std::vector<std::vector<std::vector<int>>>& path_grid) {
	if ((curr_col + 1) % path_grid[curr_row].size() == start_col) {
		path_grid[curr_row][curr_col][0] = 4;
		return grid[curr_row][curr_col];
	}
	else {
		bool first = true;
		int highest_score, highest_row_idx, highest_col_idx, highest_dir;
		for (int i = -1; i <= 1; i++) {
			int temp_row_idx = change_idx(curr_row, i * -1, grid.size()), temp_col_idx = change_idx(curr_col, 1, grid[curr_row].size());
			int check_path_grid = path_grid[temp_row_idx][temp_col_idx][0];
			if (check_path_grid == 3) {
				recurrsion(grid, temp_row_idx, temp_col_idx, start_col, path_grid);
			}
			else if (check_path_grid == 2) {
				continue;
			}
			int score = grid[temp_row_idx][temp_col_idx];
			if (first || score > highest_score) {
				first = false;
				highest_score = score;
				highest_row_idx = temp_row_idx;
				highest_col_idx = temp_col_idx;
				highest_dir = i;
			}
		}
		grid[curr_row][curr_col] += highest_score;
		path_grid[curr_row][curr_col][0] = highest_dir;
		if (path_grid[highest_row_idx][highest_col_idx][0] != 4)
			path_grid[curr_row][curr_col].insert(path_grid[curr_row][curr_col].end(), path_grid[highest_row_idx][highest_col_idx].begin(), path_grid[highest_row_idx][highest_col_idx].end());
		return grid[curr_row][curr_col];
	}
}