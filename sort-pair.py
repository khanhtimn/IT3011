"""
Problem: Sắp xếp dãy cặp
Description
Viết chương trình nhập vào 1 số nguyên dương n,
sau đó nhập vào 1 dãy n cặp, trong đó mỗi cặp được cung cấp trên 1 dòng (không quá 110 ký tự):
đầu tiên là 1 chuỗi ký tự và cuối cùng là 1 số nguyên (là mã số). Chuỗi ký tự và mã số được ngăn cách bằng 1 dấu cách.
Sau đó sắp xếp các cặp theo 2 tiêu trí: trước tiên là theo thứ tự chữ cái của chuỗi ký tự, sau đó nếu chuỗi giống nhau thì sắp xếp tăng dần theo mã số.
Cuối cùng xuất ra các cặp theo thứ tự đã sắp xếp, mỗi cặp 1 dòng.
Ví dụ:
Đầu vào:
3
aaa bbb 5
aa 3
aa 8
Đầu ra:
aa 3
aa 8
aaa bbb 5
"""


def sort_pairs(pairs):
    converted_pairs = [(p.rsplit(" ", 1)[0], int(p.rsplit(" ", 1)[1])) for p in pairs]
    return sorted(converted_pairs, key=lambda x: (x[0], x[1]))


def main():
    n = int(input())
    pairs = [input() for _ in range(n)]
    for pair in sort_pairs(pairs):
        print(" ".join(map(str, pair)))


if __name__ == "__main__":
    main()
