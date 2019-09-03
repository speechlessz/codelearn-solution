# lời giải từ bạn kien_the_sun - ngắn gọn :))

def minCostRepairingCar(a, b): 
    if len(a) == len(b) == 1:
       return min(a[0], b[0])
    ans = sum(min(i,j) for i,j in zip(a,b)) 
    if all(i < j for i,j in zip(a,b)):
       ans += min(j-i for i,j in zip(a,b)) 
    elif all(i > j for i,j in zip(a,b)):
       ans += min(i-j for i,j in zip(a,b))
    return ans