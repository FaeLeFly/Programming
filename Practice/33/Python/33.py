_print=print
def sort(ci):
    ne=int()
    for i in range (len(ci)):
        for j in range(len(ci)-1):
            if(ci[j]>ci[j+1]):
                ne=ci[j+1]
                ci[j+1]=ci[i]
                ci[i]=ne
            else:
                continue
    return ci
        
def print(ci):
    for i in range (len(ci)):
        if i!=(len(ci)-1):
            if i==0:_print('[',end='')
            _print(str(ci[i])+',',end='')
        else:
            if i==0: _print ('['+str(ci[i])+']')
            else:_print (str(ci[i])+']')
    return ci
def create(m,first,ranges):
    ci=[]
    for i in range(m):
        ci.append(0)
    count=first
    for i in range(m):
        if (i!=0):count+=ranges
        ci[i]=count
    return ci
    
m,first,ranges=int(input()),int(input()),int(input())
ci=create(m,first,ranges)
ci=sort(ci)
print(ci)
