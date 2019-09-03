# Lời giải từ bạn kien_the_sun - ngắn gọn

def countTriangles(a,b):
    g = list(zip(a,b))
    from itertools import combinations
    ans = 0
    for (x1,y1), (x2,y2), (x3,y3) in combinations(g, 3):
        ans += (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1) != 0 
    return int(ans)