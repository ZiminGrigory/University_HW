--Описать тип, позволяющий хранить информацию о многочленах с одной переменной, и реализовать для него сложение, умножение и show
-- Функции mShow, mProduct, mSum.
import Data.List

data MPolynom = Monom Int Int 
        deriving (Eq, Ord)
instance Show MPolynom where
        show (Monom a pow) | a == 0  = ""
        show (Monom a pow) | pow == 0  = show a 
        show (Monom a pow) = const ++ "x" ++ pow' 
                        where 
                                    const | (a == 1) = " + " | a > 0 = " + " ++ show (abs a) 
                                          | (a == -1) = " - " |otherwise = " - " ++ show (abs a)
                                    pow'  | (pow == 1) = "" | pow > 0 = "^" ++ show pow 
                                          | otherwise = "^" ++ "(" ++ show (pow) ++ ")" 

type Polynom = [MPolynom]

mShow' (Monom a pow) | a == 0  = ""
mShow' (Monom a pow) | pow == 0  = show a 
mShow' (Monom a pow) = const ++ "x" ++ pow' 
                where 
                            const | (a == 1) = "" | a > 0 = show (abs a) 
                                  | (a == -1) = " -" |otherwise = "-" ++ show (abs a)
                            pow'  | (pow == 1) = "" | pow > 0 = "^" ++ show pow 
                                  | otherwise = "^" ++ "(" ++ show (pow) ++ ")" 

mShow :: Polynom -> String
mShow [] = ""
mShow (x:xs) = mShow' x ++ mShow'' xs
        where
                mShow'' [] = ""
                mShow'' (x:xs) = show x ++ mShow'' xs
                 
sum' :: Polynom -> Polynom -> Polynom
sum' a b = a ++ b

sum'' :: MPolynom -> MPolynom -> MPolynom
sum'' (Monom a b) (Monom c d) = (Monom (a+c) d)

product' :: MPolynom -> MPolynom -> MPolynom
product' (Monom a b) (Monom c d) = (Monom (a*c) (b+d))

product'' :: Polynom -> Polynom -> Polynom
product'' a (x:xs) = product''' a (x:xs) []
        where   
                product''' a [] acc = acc
                product''' a (x:xs) acc = product''' a xs (map (product' x) a ++ acc)

simplify :: Polynom -> Polynom
simplify xs 
  = map (foldl (sum'') (Monom 0 0))(groupBy (\(Monom a b) (Monom c d)->b == d) (sortBy (\(Monom a b) (Monom c d)-> compare b d) xs))

mSum :: Polynom -> Polynom -> Polynom
mSum a b = simplify (sum' a b)

mProduct :: Polynom -> Polynom -> Polynom
mProduct a b = simplify (product'' a b)

--проверили формулу для разности квадратов
p1 = [Monom 2 2,Monom (-4) 4]
p2 = [Monom 2 2,Monom 4 4]
--проверили формулу для суммы кубов
p3 = [Monom 1 1, Monom 1 2]
p4 = [Monom 1 2, Monom (-1) 3, Monom 1 4]

