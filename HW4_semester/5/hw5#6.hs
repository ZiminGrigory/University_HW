--Дано выражение, содержащее переменную, константы, арифметические операции. Посчитать производную этого выражения по этой переменной, провести в полученном выражении для производной возможные упрощения (например, 1*x = x). Подходящий тип данных разработать самостоятельно

data Operator = Plus | Minus | Product | Division | Pow

data Polynom = Monom Int Int | Polynom Polynom Operator Polynom | Const Int
        deriving Eq
-- выражения типа x ^ x не решает, ибо вводить логарифм - это уже треш

instance Show Operator where
        show Plus  = " + "
        show Minus = " - "
        show Division = " / "
        show Product = " * "
        show Pow = "^"

instance Eq Operator where (==) Plus Plus = True 
                           (==) Minus Minus = True   
                           (==) Division Division = True  
                           (==) Product Product = True  
                           (==) Pow Pow = True 
                           (==) _ _ = False


instance Show Polynom where
        show (Const a)               = show a
        show (Monom a pow) | a == 0  = ""
        show (Monom a pow) | pow == 0  = show a 
        show (Monom a pow)           = const ++ "x" ++ pow' where 
                                                            const | (a == 1) = "" | otherwise = show a
                                                            pow'  | (pow == 1) = "" | otherwise = "^" ++ show pow 
        show (Polynom a Pow (Const b))       = a' ++ pow ++ b' where 
                                                             pow | b == 0 || b == 1 || a' == "" = "" 
                                                                 | otherwise = show Pow
                                                             a' | b == 0 = show 1 | otherwise = "(" ++ show a ++ ")"
                                                             b' | b == 0 || b == 1 = "" 
                                                                | b < 0 = "(" ++ show b ++ ")" 
                                                                | otherwise = show b
        show (Polynom a op b)        = br1 ++ p1 ++ op' ++ p2 ++ br2
                                                        where
                                                        p1  = show a
                                                        p2  = show b
                                                        op' | ((p1 == "") || (p2 == "")) = "" | otherwise = show op
                                                        br1 | op == Product = "(" | otherwise = ""
                                                        br2 | op == Product = ")" | otherwise = ""

mConst = (Const (-1)) 

diff :: Polynom -> Polynom
diff (Const a) = Const 0
diff (Polynom a Pow (Const b) ) = Polynom (Const b) Product (Polynom (diff a) Pow (Const (b-1) ))
diff (Monom  const pow) = Monom (const * pow) (pow - 1)
diff (Polynom a op b) | (op == Plus || op == Minus) = Polynom (diff a) op (diff b)
                      | op == Product = Polynom (Polynom (diff a) Product b) Plus (Polynom a Product (diff b))
                      | op == Division = Polynom (Polynom (diff a) Product (Polynom b Pow mConst)) 
                                                Plus (Polynom a Product (diff (Polynom b Pow mConst)) )

simplify :: Polynom -> Polynom
simplify p = if (p' == p) then p else (simplify p') 
        where   
                p' = simplify' p 
                simplify' :: Polynom -> Polynom
                simplify' (Const b) = Const b
                simplify' (Monom 0 b) = Monom 0 0
                simplify' (Monom a b) = Monom a b
                simplify' (Polynom (Monom a b) Plus (Monom c d)) | b == d = Monom (a + c) b
                simplify' (Polynom (Monom a b) Minus (Monom c d)) | b == d = Monom (a - c) b
                simplify' (Polynom (Monom a b) Product (Monom c d)) = Monom (a * c) (b + d)
                simplify' (Polynom (Monom a b) Product (Const c)) = Monom (a * c) (b)
                simplify' (Polynom (Const c) Product (Monom a b)) = Monom (a * c) (b)
                simplify' (Polynom a op b) | op /= Pow = Polynom (simplify a) op (simplify b)
                simplify' (Polynom (Monom a b) Pow (Const c))| c > 0 = Monom (a^c) (b^c)
                simplify' (Polynom a Pow (Const b)) = Polynom (simplify a) Pow (Const b)
                


p0 :: Polynom
p0 = Polynom (Monom 1 2) Plus (Polynom (Monom 3 2) Minus (Monom 6 2))
p1 :: Polynom
p1 = Polynom (Monom 1 2) Plus (Polynom (Monom 3 1) Minus (Monom 6 4))
p2 :: Polynom
p2 = Polynom (Polynom (Monom 2 5) Product (Monom 3 4)) Pow (Const 3)
p3 :: Polynom
p3 = Polynom (Monom 2 5) Division (Monom 3 4) -- здесь останется минус, так как он появляется из-за производной, а чтобы его вытащить придется подниматься вверх по структуре, проверяя на что он умножается и какое действие перед произведением.

-- Остальные постые упрощения выполняются, работает на остальных примерах.
p4 :: Polynom
p4 = Polynom (Monom 1 1) Product (Monom 1 1)

