
def waiting_time(tickets, p):
    time = 0
    num_tickets = tickets[p]

    for i in range(0,len(tickets)):
        if i < p:
            time += min(tickets[i], num_tickets)
        elif i > p:
            time += min(tickets[i], num_tickets-1)

    return time

ex_list = [5,5,4,3,4,5] 
ex_p    = 3 

print('getting: ', waiting_time(ex_list, ex_p))


