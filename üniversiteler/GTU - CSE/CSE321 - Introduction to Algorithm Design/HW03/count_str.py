
def count_str(s: str, start: str, end: str) -> int:
    count = 0
    for i in range(len(s)):
        if s[i] == start:
            for j in range(i, len(s)):
                if s[j] == end:
                    count += 1
    return count

print(count_str("TXZXXJZWX", "X", "Z"))
print(count_str("abcdabcd", "a", "d"))
print(count_str("superpower", "p", "r"))