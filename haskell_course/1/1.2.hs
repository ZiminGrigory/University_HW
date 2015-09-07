{-Описать функцию g n, которая вычисляет 
1+10*(2+10*(3+10*(4+...+10*n)))

Пример вызова:
g 4
Должно получиться 1+10*(2+10*(3+10*4)), то есть 4321
-}

g :: Int -> Int
g 1 = 1
g n = g' (n-1 + (10*n)) (n - 1)
 where 
 g' :: Int -> Int -> Int
 g' e 1 = e
 g' e n = g' (10*e + (n-1)) (n-1) 
  
