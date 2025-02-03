def solution(x_position: int, y_position: int) -> int:
    d = abs(x_position - y_position)
    l, r = 0, d

    def cal(x):
        q, r = divmod(x, 2)
        w = q * (q + 1)
        if r:
            w += q + 1
        return w

    while l < r:
        mid = (l + r) >> 1
        if cal(mid) >= d:
            r = mid
        else:
            l = mid + 1
    return l


if __name__ == '__main__':
    print(solution(x_position = 12, y_position = 6) == 4)
    print(solution(x_position = 34, y_position = 45) == 6)
    print(solution(x_position = 50, y_position = 30) == 8)
    print(solution(x_position = 0, y_position = 0) == 0)
