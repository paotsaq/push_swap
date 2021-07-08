opp = lambda x: 'ra' if x == 'rb' else 'rb'

with open("op_test", "r") as file:
    comm = file.read().splitlines()
    print(comm) 
    i = 0
    racount = 0
    while (i < len(comm)):
        if comm[i] == 'ra' or comm[i] == 'rb':
            og = comm[i]
            start = i
            to_swap = 0
            while (comm[i] == og):
                racount += 1
                i += 1
            startover = i
            print(startover)
            if comm[i] == opp(og):
                rb_local = i
                while (comm[i] == opp(og)):
                    if racount:
                        to_swap += 1
                        racount -= 1
                    i += 1
            while to_swap > 0:
                comm[start] = 'rr'
                i = rb_local
                while (i < len(comm) - 1):
                    comm[i] = comm[i + 1]
                    i += 1
                del comm[len(comm) - 1]
                start += 1
                to_swap -= 1
        print(comm) 
        i = startover
