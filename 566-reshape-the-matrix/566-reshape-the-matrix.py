class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        rows = len(mat)
        cols = len(mat[0])
        if rows*cols != r*c:
            return mat
        res = [[0 for _ in range(c)] for _ in range(r)]
        for i in range(rows):
            for j in range(cols):
                idx = i * cols + j
                ri = idx//c
                cj = idx%c
                res[ri][cj] = mat[i][j]
        return res