import Data.Char
{-
forte :: String -> Bool
forte a = (length a >= 8) && (maiuscula a) && (minuscula a) && (numero a)

maiuscula :: String -> Bool
maiuscula [] = False
maiuscula (x:xs) = isUpper x || maiuscula xs

minuscula :: String -> Bool
minuscula [] = False
minuscula (x:xs) = isLower x || minuscula xs

numero :: String -> Bool
numero [] = False
numero (x:xs) = isDigit x || numeros xs
-}
{-
forte :: String -> Bool
forte a = (length a >= 8) && (maiuscula a) && (minuscula a) && (numero a)

maiuscula :: String -> Bool
maiuscula l = or [ isUpper x | x <- l]

minuscula :: String -> Bool
minuscula l = or [ isLower x | x <- l]

numero :: String -> Bool
numero l = or [ isDigit x | x <- l]
-}

forte :: String -> Bool
forte a = (length a >= 8) && (maiuscula a) && (minuscula a) && (numero a)

maiuscula :: String -> Bool
maiuscula l = or [ x <= 'Z' && x >= 'A' | x <- l]

minuscula :: String -> Bool
minuscula l = or [ x <= 'z' && x >= 'a' | x <- l]

numero :: String -> Bool
numero l = or [ x >= '0' && x <= '9' | x <- l]
