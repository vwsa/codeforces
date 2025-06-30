import random
import subprocess

# 随机生成满足 sum(A) = sum(B) 且数字大小在 [1, max_value] 的测试数据
def generate_test_case(max_n=3, max_value=6):
    N = random.randint(2, max_n)  # 随机生成数组长度，范围为 [2, max_n]
    A = [random.randint(1, max_value) for _ in range(N)]  # 随机生成数组 A，范围为 [1, max_value]
    total_sum = sum(A)
    B = A[:]  # 从 A 复制一个初始数组
    
    # 随机调整 B，保持 sum(A) == sum(B)
    for _ in range(random.randint(1, N)):
        i = random.randint(0, N - 1)
        delta = random.randint(-min(B[i] - 1, max_value // 2), min(max_value - B[i], max_value // 2))
        B[i] += delta

    # 修正 B 的总和
    diff = sum(B) - total_sum
    while diff != 0:
        adjust_idx = random.randint(0, N - 1)
        if diff > 0:  # B 的和大于 A，需要减少
            adjust_amount = min(diff, B[adjust_idx] - 1)  # 确保 B[adjust_idx] 不小于 1
            B[adjust_idx] -= adjust_amount
            diff -= adjust_amount
        elif diff < 0:  # B 的和小于 A，需要增加
            adjust_amount = min(-diff, max_value - B[adjust_idx])  # 确保 B[adjust_idx] 不大于 max_value
            B[adjust_idx] += adjust_amount
            diff += adjust_amount

    return N, A, B

# 将测试数据格式化为输入字符串
def format_test_case(N, A, B):
    return f"{N}\n" + " ".join(map(str, A)) + "\n" + " ".join(map(str, B)) + "\n"

# 调用你的程序并获取输出
def run_program(program_path, input_data):
    process = subprocess.Popen(
        program_path,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    stdout, stderr = process.communicate(input=input_data)
    return stdout.strip(), stderr.strip()

# 老老实实模拟程序输出的操作
def simulate_operations(N, A, B, program_output):
    lines = program_output.splitlines()

    # 如果程序输出的第一行不是 "Yes"，验证 A 是否已经等于 B
    if lines[0] != "Yes":
        return A == B

    # 程序输出的操作次数和操作序列
    M = int(lines[1])  # 读取操作次数
    if (M > 31000):
        print(M)
    operations = []
    for line in lines[2:]:
        i, j = map(int, line.split())
        operations.append((i - 1, j - 1))  # 转换为 0-based 索引

    # 模拟操作
    A_sim = A[:]  # 复制初始数组
    for i, j in operations:
        # 检查操作是否合法
        if not (0 <= i < j < N):  # 确保 0 <= i < j < N
            print(f"Illegal operation: i={i + 1}, j={j + 1} out of bounds!")
            return False

        # 模拟操作，注意必须同时更新 i 和 j 的值
        new_A_i = A_sim[j] - 1
        new_A_j = A_sim[i] + 1
        A_sim[i] = new_A_i  # 更新 A[i]
        A_sim[j] = new_A_j  # 更新 A[j]

    # 检查最终结果是否与目标数组 B 相同
    return A_sim == B

# 主程序路径
main_program = "./a.out"  # 你的主程序路径

def main(max_n=10, max_value=10, num_tests=100):
    for test_id in range(num_tests):  # 生成 num_tests 组测试数据
        # 1. 生成测试数据
        N, A, B = generate_test_case(max_n=max_n, max_value=max_value)
        input_data = format_test_case(N, A, B)

        # 2. 运行主程序
        main_output, _ = run_program(main_program, input_data)

        # 3. 老老实实模拟主程序的操作
        is_valid = simulate_operations(N, A, B, main_output)
        if not is_valid:
            print(f"Test case #{test_id + 1} failed!")
            print("Input:")
            print(input_data)
            print("Your program output:")
            print(main_output)
            print("Expected A to be transformed into B.")
            print("Initial A:", A)
            print("Target B:", B)
            break
    else:
        print("All test cases passed!")

if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser(description="Run a tester for the transformation problem.")
    parser.add_argument("--max-n", type=int, default=10, help="Maximum array length (default: 10)")
    parser.add_argument("--max-value", type=int, default=10, help="Maximum value in the array (default: 10)")
    parser.add_argument("--num-tests", type=int, default=100, help="Number of test cases (default: 100)")
    args = parser.parse_args()

    main(max_n=args.max_n, max_value=args.max_value, num_tests=args.num_tests)