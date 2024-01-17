def submatrix_max_size(matrix) -> int:
    """Find the max size of square submatrix of 1s in the given square matrix of 0s and 1s."""
    if not matrix or not matrix[0]:
        return 0

    n = len(matrix)
    dp = [[0] * n for _ in range(n)]
    max_size = 0
    # Copy the first row and column
    for i in range(n):
        dp[i][0] = matrix[i][0]
        dp[0][i] = matrix[0][i]
        max_size = max(max_size, dp[i][0], dp[0][i])
    # Dynamic programming to find the largest square matrix of ones
    for i in range(1, n):
        for j in range(1, n):
            if matrix[i][j]:
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                max_size = max(max_size, dp[i][j])

    return max_size


if __name__ == '__main__':
    matrix = [
        [1, 1, 0, 1],
        [1, 1, 1, 1],
        [1, 1, 1, 1],
        [1, 1, 1, 0]
    ]

    print(f"submatrix_max_size: {submatrix_max_size(matrix)}")
