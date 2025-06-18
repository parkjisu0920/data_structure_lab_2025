import sys

def problem2(input_string):
    pieces = input_string.split()
    min_needed_overall = float('inf')

    for piece in pieces:
        if not piece:
            continue

        needed_openings_at_start = 0
        balance = 0

        for char in piece:
            if char == '(':
                balance += 1
            elif char == ')':
                balance -= 1

            if balance < 0:
                needed_openings_at_start += 1
                balance = 0

        needed_closings_at_end = balance
        min_needed_for_this_piece = needed_openings_at_start + needed_closings_at_end
        min_needed_overall = min(min_needed_overall, min_needed_for_this_piece)

    return min_needed_overall

input_line = sys.stdin.readline().strip()
result = problem2(input_line)
print(result)
