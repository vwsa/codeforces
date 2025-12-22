import subprocess
import sys

def calculate_sum(output):
    try:
        # Assume output is a single line of space-separated integers
        numbers = list(map(int, output.strip().split()))
        return sum(numbers)
    except ValueError:
        print("Error: Output is not a valid list of integers.")
        sys.exit(1)

for n in range(1, 128):
    for k in range(1, 8):
        input_data = f"1\n{n} {k}\n".encode()
        print(f" Testing n = {n}, k = {k}")
        # Run ./a.out
        result_a = subprocess.run(["./a.out"], input=input_data, capture_output=True)
        if result_a.returncode != 0:
            print(f"Error running ./a.out for n={n}, k={k}")
            sys.exit(1)
        output_a = result_a.stdout.decode()
        sum_a = calculate_sum(output_a)
        
        # Run ./b.out
        result_b = subprocess.run(["./b.out"], input=input_data, capture_output=True)
        if result_b.returncode != 0:
            print(f"Error running ./b.out for n={n}, k={k}")
            sys.exit(1)
        output_b = result_b.stdout.decode()
        sum_b = calculate_sum(output_b)
        
        if sum_a != sum_b:
            print(f"n k 分别是 {n} {k}")
            sys.exit(0)

print("All sums match for all n and k.")