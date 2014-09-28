--Реализовать функцию, генерирующую бесконечный список, содержащий все целые положительные числа, состоящие только из цифр 1, 7 и 9

nextNumber :: Int -> Int
nextNumber 1 = 7
nextNumber 7 = 9
nextNumber 9 = 11
nextNumber x 
    | modulo == 9       = (nextNumber division) * 10 + 1
    | otherwise         = division * 10 + nextNumber modulo 
  where
    modulo = mod x 10
    division = div x 10

makeList = 1 : map nextNumber makeList
