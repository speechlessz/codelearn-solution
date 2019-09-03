# Lời giải từ bạn kien_the_sun - ngắn gọn

def sumOfTheOddNumbers(n):
   #a(n) = a(n+1) + (1 + 3 +5 + ...+ 2*2^(n-1) - 1) = a(n-1) + 4^(n-1) 
   #=a(1) + 4 +...+4^n = (4^n+2)/3
   mod = 10 ** 9 + 7 
   return (pow(4, n , mod) + 2) * 333333336 % mod
