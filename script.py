opp = lambda x: x[:-1] + 'a' if x[-1] == 'b' else x[:-1] + 'b' 

# returns the count of moves on the left
# i is passed by reference, and keeps updating
def counts_move(i, comm, move):
    move_count = 0
    to_swap = 0
    while (i < len(comm) and comm[i] == move):
        move_count += 1
        i += 1
    return move_count, i

def copies_array(comm, i, offset):
    while (i < len(comm) - 1 - offset):
        comm[i] = comm[i + 1 + offset]
        i += 1
    del comm[len(comm) - 1]

with open("op_test", "r") as file:
    comm = file.read().splitlines()
    i = 0
    print(comm)
    while (i < len(comm)):
        if comm[i] in ['ra', 'rb', 'sa', 'sb', 'rra', 'rrb']:
            start_a = i
            print(f'before counting a: i = {i}')
            racount, i = counts_move(i, comm, comm[i])
            start_b = i
            print(f'after counting a: i = {i}')
            rbcount, i = counts_move(i, comm, opp(comm[start_a]))
            print("racount, rbcount = ", racount, rbcount)
            to_swap = min(racount, rbcount)
            while to_swap > 0:
                comm[start_a] = comm[start_a][:-1] + comm[start_a][0]
                start_a += 1
                to_swap -= 1
            copies_array(comm, start_b, to_swap)
            print(comm)
        i = start_a
