# 다섯 개의 자연수를 한 줄에 하나씩 입력받음
input_numbers = [int(input()) for _ in range(5)]

def problem1(input):
    # 이곳에 코드를 작성하세요.
    mean = sum(input) // len(input)  # 평균 (정수형)
    median = sorted(input)[len(input) // 2]  # 중앙값

    result = [0, 0]
    result[0] = mean
    result[1] = median
    return result

result = problem1(input_numbers)

# 출력
print(result[0])
print(result[1])
