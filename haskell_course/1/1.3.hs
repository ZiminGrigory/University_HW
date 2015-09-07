{-Описать функцию 
sumcos n = cos(1+2+...+n)/(cos 1+cos 2+...+cos n))

Пример вызова:
sumcos 3
Должно получиться cos(1+2+3)/(cos 1+cos 2+cos 3); это равно примерно -1.1 

Дополнительное условие: В решении используйте, пожалуйста, хвостовую рекурсию и накапливающие параметры.

P.S.
Это доп условие все портит...со списками было бы интереснее.
Не помню как обрабатывать деление на 0, так что считаем, что его быть не может.
-}

sumcos :: Int -> Double
sumcos n = cosSum n / sumCos 0.0 n
 where
 cosSum :: Int -> Double
 cosSum n = cos (fromIntegral (sum 0 n))
  where
  sum :: Int -> Int -> Int 
  sum s 0 = s
  sum s n = sum (s + n) (n - 1)
 sumCos :: Double -> Int -> Double
 sumCos s 0 = s
 sumCos s n = sumCos (s + cos (fromIntegral n)) (n-1)
 
         
