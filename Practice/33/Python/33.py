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
        
def printf(ci):
    for i in range (len(ci)):
        print(ci[i])
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
printf(ci)
