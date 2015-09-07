{-
Описать функцию sumfact n: 
sumfact n = 1!+2!+...+n!

Пример вызова:
sumfact 3
Результат должен быть равен 9.

Дополнительное условие: В решении используйте, пожалуйста, хвостовую рекурсию и накапливающие параметры.
-}

sumfact :: Int -> Int
sumfact n = sumfact' n 0 1 1 
 where
  sumfact' 0 s _ _ = s 
  sumfact' n s xp j = sumfact' (n - 1) (s + xp') xp' (j + 1)
   where xp' = xp * j
