# Lời giải từ bạn kien_the_sun - ngắn gọn

def waitingDays(a):
    a.sort()
    return sum(a[i] -a[i-1] for i in range(1, len(a), 2))
