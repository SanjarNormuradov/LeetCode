def digits_sum(n: int) -> int:
    """Compute the sum of digits in the number."""
    return sum(int(d) for d in str(n))


def next_num(n: int) -> int:
    """Find the number in the sequence."""
    return n + digits_sum(n)


def find_joint_point(s1: int, s2: int) -> int:
    """Find the joint point of two sequences starting from s1 and s2."""
    while s1 != s2:
        if s1 < s2:
            s1 = next_num(s1)
        else:
            s2 = next_num(s2)

    return s1


if __name__ == '__main__':
    s1 = 34
    s2 = 40
    print(f"Joint point of {s1} and {s2}: {find_joint_point(s1, s2)}")
