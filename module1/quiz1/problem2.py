foo = [1,2,3,4,5]

def do_what(a):
    v1 = a[0]
    i = 1
    while(i < len(foo)):
        v1 = v1 + a[i]
        i = i + 1
    v2 = v1 / len(foo) 
    return v2

print(do_what(foo))
