
--Реализовать функцию, которая по произвольной строке проверяет корректность скобочной последовательности в этой строке.
is_suitable :: Char -> Char -> Bool
is_suitable x y = (is_suitable' x y) || (is_suitable' y x) where
        is_suitable' '(' ')'   = True
        is_suitable' '[' ']'   = True
        is_suitable' '{' '}'   = True
        is_suitable' '<' '>'   = True
        is_suitable' _  _      = False
	

bracketsChecker :: [Char] -> Bool
bracketsChecker = (== []) . verify . filter (`elem` "()[]{}<>")  where
        verify = foldl (mStack) [] where
                mStack [] x = [x]
		mStack (s : ss) x
			|is_suitable x s = ss
			|otherwise       = (x : s : ss)	

